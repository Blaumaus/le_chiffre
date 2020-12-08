#ifndef HACKS_HPP
#define HACKS_HPP
#pragma once

#include "client.hpp"
#include "memory.hpp"
#include "player_entity.hpp"
#include "bsp_parser/valve-bsp-parser/bsp_parser.hpp"
#include "bsp_parser/valve-bsp-parser/core/matrix.hpp"

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

	void _team_glow(PlayerEntity* target, DWORD glow_obj) {
		GlowStruct gt = memory->read_mem<GlowStruct>(glow_obj + (target->get_glow_index() * 0x38));
		gt.red = 1.0f;
		gt.green = 1.0f;
		gt.blue = 1.0f;
		gt.alpha = 0.8f;
		gt.redner_occluded = true;
		gt.render_unoccluded = false;
		memory->write_mem<GlowStruct>(glow_obj + (target->get_glow_index() * 0x38), gt);
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
		if (_aim_on_enemy(&player, dangerzone)) player.set_attack_state(6);
	}

	void no_flash() {
		if (player.valid_player() && player.get_flash_duration() > 0.f) player.set_flash_duration(0.f);
	}

	void glow_esp_radar(bool glow_on_teammate, bool glow_on_enemy, bool radar_hack, bool dangerzone = false) {
		DWORD glow_obj;
		int player_team = player.get_team();

		if (glow_on_teammate || glow_on_enemy) glow_obj = memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwGlowObjectManager);

		for (short i = 0; i < 32; ++i) {
			PlayerEntity target(memory, memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwEntityList + (short)0x10 * i));

			if (target.valid_player()) {
				if (dangerzone && glow_on_enemy) { // TODO: Add team glow for teammates dangerzone mode
					_enemy_glow(&target, glow_obj);
					continue;
				}

				int target_team = target.get_team();

				if (player_team == target_team && glow_on_teammate) _team_glow(&target, glow_obj);
				else if (player_team != target_team && glow_on_enemy) _enemy_glow(&target, glow_obj);
				
				if (player_team != target_team && radar_hack && !target.is_spotted()) target.set_spotted(true);
			}
		}

		Sleep(5);
	}

	void aim_bot() {
		PlayerEntity target = _get_closest_enemy();

		if (target.valid_player()) {
			client->set_sensitivity(0.f);
			player.aim_at(target.get_bone_position(8));
		} else client->reset_sensitivity();
	}

	void bunny_hop() {
		if (player.get_flags() & 1 << 0 && player.is_moving()) player.set_jump_state(6);
	}

	void panic_mode() { // closes cheat when triggered
		bool end = GetKeyState(VK_END) & 1;
		if (end) ExitProcess(EXIT_SUCCESS);
	}

	Hacks(Memory* memory, Client* client) {
		this->memory = memory;
		this->client = client;
		bsp_setted = false;
		init();
	}
};
#endif