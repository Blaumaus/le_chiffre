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

	DWORD _getClientState() {
		return memory->read_mem<DWORD>(memory->engineBaseAddr + signatures::dwClientState);
	}
public:
	Client(Memory* memory) {
		this->memory = memory;
	}

	bool in_game() {
		return memory->read_mem<DWORD>(_getClientState() + signatures::dwClientState_State) == INGAME;
	}

	PlayerEntity get_local_player() {
		DWORD player_id = memory->read_mem<DWORD>(_getClientState() + signatures::dwClientState_GetLocalPlayer);
		return PlayerEntity(memory, memory->read_mem<DWORD>(memory->clientBaseAddr + signatures::dwEntityList + 0x10 * player_id));
	}
};

#endif