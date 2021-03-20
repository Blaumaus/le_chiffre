#ifndef HACKS_HPP
#define HACKS_HPP
#pragma once

#include "client.hpp"
#include "memory.hpp"
#include "player_entity.hpp"
#include "bsp_parser/valve-bsp-parser/bsp_parser.hpp"
#include "bsp_parser/valve-bsp-parser/core/matrix.hpp"
#include "misc/config.hpp"
#include "misc/console_io.hpp"

using namespace hazedumper;
using namespace rn;

struct GlowStruct {
	BYTE base[4];
	float red;
	float green;
	float blue;
	float alpha;
	BYTE buffer[16];
	bool redner_occluded;
	bool render_unoccluded;
	bool fullBloom;
	BYTE buffer1[5];
	int glow_style;
};

class Hacks {
private:
	Memory* memory;
	Client* client;
	PlayerEntity player;
	bsp_parser bp;

	// true if aiming on enemy, false otherwise
	bool _aim_on_enemy(PlayerEntity* player, bool dangerzone = false) {
		if (!player->valid_player()) return false;

		DWORD crosshair = player->get_crosshair_id();
		if (crosshair == 0 || crosshair > 33) return false;

		PlayerEntity enemy(memory, memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwEntityList + (crosshair - 1) * 0x10));
		if (!enemy.valid_player()) return false;

		// check if crosshair if pointed on enemy player
		return dangerzone || player->get_team() != enemy.get_team();
	}

	void _enemy_glow(PlayerEntity* target, DWORD glow_obj) {
		GlowStruct gt = memory->read_mem<GlowStruct>(glow_obj + (target->get_glow_index() * 0x38));
		gt.red = 1.0f;
		gt.green = 0;
		gt.blue = 0;
		gt.alpha = 0.9f;
		gt.redner_occluded = true;
		gt.render_unoccluded = false;
		memory->write_mem<GlowStruct>(glow_obj + (target->get_glow_index() * 0x38), gt);
	}

	/* void _carrier_glow(PlayerEntity* target, DWORD glow_obj) {
		GlowStruct gt = memory->read_mem<GlowStruct>(glow_obj + (target->get_glow_index() * 0x38));
		gt.red = .4f;
		gt.green = .5f;
		gt.blue = 0;
		gt.alpha = 0.9f;
		gt.redner_occluded = true;
		gt.render_unoccluded = false;
		memory->write_mem<GlowStruct>(glow_obj + (target->get_glow_index() * 0x38), gt);
	} */

	// returns an entity which is visible and closest to local player on XYZ axis coordinates
	// if no players are located near local player, it will return an invalid PlayerEntity object
	PlayerEntity _get_closest_enemy(int bone_id = 8) {
		float closest_distance = 10000000; // initial closest distance between local player and an enemy
		PlayerEntity closest_enemy;
		int player_team = player.get_team();
		vector3 player_coords = player.get_bone_position_v3(8);

		for (short i = 0; i < 32; ++i) {
			PlayerEntity target(memory, memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwEntityList + (short)0x10 * i));

			if (target.valid_player() && target.get_team() != player_team) {
				vector3 target_head = target.get_bone_position_v3(bone_id);

				if (is_visible(player_coords, target_head)) {
					float distance = player.get_distance(target.get_origin());
					if (distance < closest_distance) {
						closest_distance = distance;
						closest_enemy = target;
					}
				}
			}
		}

		return closest_enemy;
	}

	bool is_visible(vector3& origin, vector3& destinaiton) {
		return bsp_setted && bp.is_visible(origin, destinaiton);
	}

public:
	bool bsp_setted;

	void init() {
		player = client->get_local_player();
		if (bp.load_map(client->get_game_dir(), client->get_map_dir())) bsp_setted = true;
	}

	void trigger_bot(bool dangerzone = false) {
		if (_aim_on_enemy(&player, dangerzone)) {
			// player.set_attack_state(6); // doesn't properly work on pistols

			player.set_attack_state(5);
			Sleep((rand() % 11) + 10); // 10-20 ms
			player.set_attack_state(4);
		}
	}

	void no_flash() {
		if (player.valid_player() && player.get_flash_duration() > 0.f) player.set_flash_duration(0.f);
	}

	void glow_esp_radar(bool glow_on_enemy, bool radar_hack, bool dangerzone = false) {
		DWORD glow_obj;
		int player_team = player.get_team();

		if (glow_on_enemy) glow_obj = memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwGlowObjectManager);

		for (short i = 0; i < 32; ++i) {
			PlayerEntity target(memory, memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwEntityList + (short)0x10 * i));

			if (target.valid_player()) {
				if (dangerzone && glow_on_enemy) { // TODO: Add team glow for teammates dangerzone mode
					_enemy_glow(&target, glow_obj);
					continue;
				}

				int target_team = target.get_team();

				if (player_team != target_team && glow_on_enemy) _enemy_glow(&target, glow_obj);

				if (player_team != target_team && radar_hack && !target.is_spotted()) target.set_spotted(true);
			}
		}

		Sleep(5);
	}

	/* void get_spectators() {
		int player_team = player.get_team();

		for (short i = 0; i < 32; ++i) {
			PlayerEntity target(memory, memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwEntityList + (short)0x10 * i));

			if (target.valid_player()) {
				int target_team = target.get_team();
				if (player_team != target_team) continue;

			}
		}
	} */

	void aim_bot() {
		PlayerEntity target = _get_closest_enemy();

		if (target.valid_player()) {
			client->set_sensitivity(0.f);
			player.aim_at(target.get_bone_position(8));
		}
		else client->reset_sensitivity();
	}

	void bunny_hop() {
		if (player.get_flags() & 1 << 0 && player.is_moving()) player.set_jump_state(6);
	}

	void preexit() {
		client->reset_sensitivity();
	}

	void panic_mode() { // closes cheat when triggered
		if (GetKeyState(VK_END) & 0x0001) {
			preexit();
			ExitProcess(EXIT_SUCCESS);
		};
	}

	// Thread methods:
	void thread_trigger_bot(hacks_state* state, hacks_coords* coords, ConsoleIO* io, Internalisation* i) { // Trigger bot - LAlt, F6
		while (true) {
			if (state->game) {
				bool f6 = GetKeyState(VK_F6) & 0x0001;
				bool lalt = GetAsyncKeyState(VK_LMENU);
				bool l_mouse = GetAsyncKeyState(VK_LBUTTON);

				if (f6 != state->activate_trigger) {
					state->activate_trigger = f6;
					io->set_cursor_position(coords->activate_trigger);
					io->write_str(state->activate_trigger ? i->translate(XorStr("on")) : i->translate(XorStr("off")), state->activate_trigger ? FOREGROUND_GREEN : FOREGROUND_RED);
				}

				if (state->activate_trigger && lalt && !l_mouse) trigger_bot(client->is_dangerzone());
			}
			else Sleep(1000);

			Sleep(2);
		}
	}

	void thread_aimbot(hacks_state* state, hacks_coords* coords, ConsoleIO* io, Internalisation* i) { // Aimbot - F4
		while (true) {
			if (state->game) {
				bool f4 = GetKeyState(VK_F4) & 0x0001;

				if (f4 != state->aimbot) {
					state->aimbot = f4;
					io->set_cursor_position(coords->aimbot);
					io->write_str(state->aimbot ? i->translate(XorStr("on")) : i->translate(XorStr("off")), state->aimbot ? FOREGROUND_GREEN : FOREGROUND_RED);
				}

				if (state->aimbot) aim_bot();
				else client->reset_sensitivity();
			}
			else Sleep(1000);

			Sleep(2);
		}
	}

	void thread_glow_radar(hacks_state* state, hacks_coords* coords, ConsoleIO* io, Internalisation* i) { // Glow ESP - F8; Radar hack - F9
		while (true) {
			if (state->game) {
				bool f8 = GetKeyState(VK_F8) & 0x0001; // Enemy glow ESP
				bool f9 = GetKeyState(VK_F9) & 0x0001; // Radar hack

				if (f8 != state->enemy_wh) {
					state->enemy_wh = f8;
					io->set_cursor_position(coords->enemy_wh);
					io->write_str(state->enemy_wh ? i->translate(XorStr("on")) : i->translate(XorStr("off")), state->enemy_wh ? FOREGROUND_GREEN : FOREGROUND_RED);
				}

				if (f9 != state->radar_hack) {
					state->radar_hack = f9;
					io->set_cursor_position(coords->radar_hack);
					io->write_str(state->radar_hack ? i->translate(XorStr("on")) : i->translate(XorStr("off")), state->radar_hack ? FOREGROUND_GREEN : FOREGROUND_RED);
				}

				if (state->enemy_wh || state->radar_hack)
					glow_esp_radar(state->enemy_wh, state->radar_hack, client->is_dangerzone());
			}
			else Sleep(1000);

			Sleep(1);
		}
	}

	void thread_no_flash(hacks_state* state, hacks_coords* coords, ConsoleIO* io, Internalisation* i) { // No flash - F3
		while (true) {
			if (state->game) {
				bool f3 = GetKeyState(VK_F3) & 0x0001;

				if (f3 != state->no_flash) {
					state->no_flash = f3;
					io->set_cursor_position(coords->no_flash);
					io->write_str(state->no_flash ? i->translate(XorStr("on")) : i->translate(XorStr("off")), state->no_flash ? FOREGROUND_GREEN : FOREGROUND_RED);
				}

				if (state->no_flash) no_flash();
			}
			else Sleep(1000);

			Sleep(2);
		}
	}

	void thread_bunny_hop(hacks_state* state, hacks_coords* coords, ConsoleIO* io, Internalisation* i) { // Bunny hop - F2
		while (true) {
			if (state->game) {
				bool f2 = GetKeyState(VK_F2) & 0x0001;
				bool space = GetAsyncKeyState(VK_SPACE);

				if (f2 != state->bunny_hop) {
					state->bunny_hop = f2;
					io->set_cursor_position(coords->bunny_hop);
					io->write_str(f2 ? i->translate(XorStr("on")) : i->translate(XorStr("off")), f2 ? FOREGROUND_GREEN : FOREGROUND_RED);
				}

				if (state->bunny_hop && space) bunny_hop();
			}
			else Sleep(1000);

			Sleep(2);
		}
	}

	void thread_panic_mode() {
		while (true) {
			panic_mode();
			Sleep(1);
		}
	}

	Hacks(Memory* memory, Client* client) {
		this->memory = memory;
		this->client = client;
		bsp_setted = false;
		init();
	}
};
#endif