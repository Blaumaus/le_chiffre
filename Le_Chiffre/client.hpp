#ifndef CLIENT_HPP
#define CLIENT_HPP
#pragma once

#include "memory.hpp"
#include "signatures.hpp"
#include "player_entity.hpp"
#include "misc/config.hpp"

using namespace hazedumper;

class Client {
private:
	Memory* memory;
	DWORD _survivalDecisionTypes;
	float def_sensinivity; // used for aimbot
	std::array<char, 0x120> map_dir;
	std::array<char, 0x120> game_dir;

	DWORD _getClientState() {
		return memory->read_mem<DWORD>(memory->engineBaseAddr + signatures::dwClientState);
	}
public:
	Client(Memory* memory) {
		this->memory = memory;
		_survivalDecisionTypes = 0;
		this->def_sensinivity = get_sensitivity();
	}

	// Client states: LOBBY = 1, LOADING = 2, CONNECTING = 3, CONNECTED = 5, INGAME = 6
	bool in_game() {
		if (memory->tProcess != NULL && memory->clientBaseAddr != NULL && memory->engineBaseAddr != NULL) {
			return memory->read_mem<DWORD>(_getClientState() + signatures::dwClientState_State) == 6;
		}

		return false;
	}

	bool is_dangerzone() {
		return _survivalDecisionTypes != 0;
	}

	void update_gamemode() {
		DWORD gameRulesProxy = memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwGameRulesProxy);
		_survivalDecisionTypes = memory->read_mem<DWORD>(gameRulesProxy + netvars::m_SurvivalGameRuleDecisionTypes);
	}

	PlayerEntity get_local_player() {
		DWORD player_id = memory->read_mem<DWORD>(_getClientState() + signatures::dwClientState_GetLocalPlayer);
		return PlayerEntity(memory, memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwEntityList + player_id * 0x10));
	}

	void set_sensitivity(float val) {
		uint32_t sens_pt = memory->read_mem<uint32_t>(memory->clientBaseAddr + signatures::dwSensitivityPtr);
		uint32_t sest_fn = *reinterpret_cast<uint32_t*>(&val) ^ sens_pt;

		memory->write_mem<uint32_t>(memory->clientBaseAddr + signatures::dwSensitivity, sest_fn);
	}

	float get_sensitivity() {
		uint32_t sens_pt = memory->read_mem<uint32_t>(memory->clientBaseAddr + signatures::dwSensitivityPtr);
		uint32_t sens_fn = memory->read_mem<uint32_t>(memory->clientBaseAddr + signatures::dwSensitivity);

		sens_fn ^= sens_pt;

		return *reinterpret_cast<float*>(&sens_fn);
	}

	void reset_sensitivity() {
		if (memory->tProcess != NULL && memory->clientBaseAddr != NULL && memory->engineBaseAddr != NULL) {
			set_sensitivity(this->def_sensinivity);
		}
	}

	const char* get_map_dir() {
		map_dir = memory->read_mem<std::array<char, 0x120>>(_getClientState() + signatures::dwClientState_MapDirectory);
		return map_dir.data();
	}

	const char* get_game_dir() {
		game_dir = memory->read_mem<std::array<char, 0x120>>(memory->engineBaseAddr + signatures::dwGameDir);
		return game_dir.data();
	}
};

#endif