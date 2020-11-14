#ifndef PLAYER_ENTITY_HPP
#define PLAYER_ENTITY_HPP

#pragma once

#include "memory.hpp"
#include "client.hpp"
#include "signatures.hpp"

using namespace hazedumper;

class PlayerEntity {
private:
	Memory* memory;
	DWORD playerBaseAddr;

public:
	PlayerEntity() {
		memory = nullptr;
		playerBaseAddr = NULL;
	}

	PlayerEntity(Memory* memory, DWORD playerBaseAddr) {
		this->memory = memory;
		this->playerBaseAddr = playerBaseAddr;
	}

	bool valid_player() {
		if (!memory) return false;

		DWORD health = this->get_health();
		return (health > 0 && health <= 100) && !get_dormant();
	}

	// 4 - don't attack
	// 5 - attack
	void set_attack_state(DWORD val) {
		memory->write_mem<DWORD>(memory->clientBaseAddr + signatures::dwForceAttack, val);
	}

	void set_flash_duration(float val) {
		memory->write_mem<float>(playerBaseAddr + netvars::m_flFlashDuration, val);
	}

	void set_spotted(bool val) {
		memory->write_mem<bool>(playerBaseAddr + netvars::m_bSpotted, val);
	}

	DWORD get_health() {
		return memory->read_mem<DWORD>(playerBaseAddr + netvars::m_iHealth);
	}

	bool get_dormant() {
		return memory->read_mem<bool>(playerBaseAddr + signatures::m_bDormant);
	}

	DWORD get_crosshair_id() {
		return memory->read_mem<DWORD>(playerBaseAddr + netvars::m_iCrosshairId);
	}

	// 2 - terrorist
	// 3 - counter terrorist
	int get_team() {
		return memory->read_mem<int>(playerBaseAddr + netvars::m_iTeamNum);
	}

	float get_flash_duration() {
		return memory->read_mem<float>(playerBaseAddr + netvars::m_flFlashDuration);
	}

	int get_glow_index() {
		return memory->read_mem<int>(playerBaseAddr + netvars::m_iGlowIndex);
	}

	DWORD get_base_addr() {
		return this->playerBaseAddr;
	}
};
#endif