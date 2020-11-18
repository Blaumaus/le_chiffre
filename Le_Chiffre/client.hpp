#ifndef CLIENT_HPP
#define CLIENT_HPP
#pragma once

#include "memory.hpp"
#include "signatures.hpp"
#include "player_entity.hpp"
#include "config.hpp"

using namespace hazedumper;

class Client {
private:
	Memory* memory;
	DWORD _survivalDecisionTypes;

	DWORD _getClientState() {
		return memory->read_mem<DWORD>(memory->engineBaseAddr + signatures::dwClientState);
	}
public:
	Client(Memory* memory) {
		this->memory = memory;
		_survivalDecisionTypes = 0;
	}

	bool in_game() {
		return memory->read_mem<DWORD>(_getClientState() + signatures::dwClientState_State) == INGAME;
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
};

#endif