#ifndef PLAYER_ENTITY_HPP
#define PLAYER_ENTITY_HPP

#pragma once

#include "memory.hpp"
#include "client.hpp"
#include "signatures.hpp"
#include <iostream>

using namespace hazedumper;

struct speed_vector {
	float x, y, z;
};

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
		if (!memory || !playerBaseAddr) return false;

		DWORD health = this->get_health();
		return (health > 0 && health <= 100) && !get_dormant();
	}

	// 4 - don't attack
	// 5 - attack
	// 6 - attack once, next reset to 4
	void set_attack_state(DWORD val) {
		memory->write_mem<DWORD>(memory->clientBaseAddr + signatures::dwForceAttack, val);
	}

	// 4 - don't jump
	// 5 - jump
	// 6 - jump once, next reset to 4
	void set_jump_state(DWORD val) {
		memory->write_mem<DWORD>(memory->clientBaseAddr + signatures::dwForceJump, val);
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

	// FL_ONGROUND   (1 << 0) on the ground
	// FL_DUCKING    (1 << 1) fully crouched
    // FL_WATERJUMP  (1 << 2) jumping out of water
    // FL_ONTRAIN    (1 << 3) _controlling_ a train
    // FL_INRAIN     (1 << 4) standing in rain
    // FL_FROZEN     (1 << 5) frozen
    // FL_ATCONTROLS (1 << 6) can't move
    // FL_CLIENT     (1 << 7) player
    // FL_FAKECLIENT (1 << 8) fake client
	// FL_INWATER    (1 << 9) in water
	BYTE get_flags() {
		return memory->read_mem<BYTE>(playerBaseAddr + netvars::m_fFlags);
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

	bool c4_owner() {
		return memory->read_mem<bool>(memory->clientBaseAddr + signatures::is_c4_owner);
	}

	speed_vector get_velocity() {
		return memory->read_mem<speed_vector>(playerBaseAddr + netvars::m_vecVelocity);
	}

	bool is_moving() {
		speed_vector vec = get_velocity();
		float sum = vec.x + vec.y + vec.z;
		return sum < -0.003 || sum > 0; // 0.003 due to incorrect float precision
	}
};
#endif