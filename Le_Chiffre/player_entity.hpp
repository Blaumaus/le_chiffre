#ifndef PLAYER_ENTITY_HPP
#define PLAYER_ENTITY_HPP

#pragma once
#pragma warning(disable: 26451) // disabled a warning about arithmetic overflow (cast from float to double)

#define _USE_MATH_DEFINES // to access math consts like PI number
#include <math.h>
#include "memory.hpp"
#include "client.hpp"
#include "signatures.hpp"
#include "misc/config.hpp"
#include "client.hpp"
#include "bsp_parser/valve-bsp-parser/core/matrix.hpp"

using namespace hazedumper;
using namespace rn;

struct BoneMatrix {
	BYTE _junk1[0xC];
	float x;
	BYTE _junk2[0xC];
	float y;
	BYTE _junk3[0xC];
	float z;
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
	inline void set_attack_state(DWORD val) {
		memory->write_mem<DWORD>(memory->clientBaseAddr + signatures::dwForceAttack, val);
	}

	// 4 - don't jump
	// 5 - jump
	// 6 - jump once, next reset to 4
	inline void set_jump_state(DWORD val) {
		memory->write_mem<DWORD>(memory->clientBaseAddr + signatures::dwForceJump, val);
	}

	inline void set_flash_duration(float val) {
		memory->write_mem<float>(playerBaseAddr + netvars::m_flFlashDuration, val);
	}

	inline void set_spotted(bool val) {
		memory->write_mem<bool>(playerBaseAddr + netvars::m_bSpotted, val);
	}

	inline bool is_spotted() {
		return memory->read_mem<bool>(playerBaseAddr + netvars::m_bSpotted);
	}

	// aims at XYZ axis point
	void aim_at(coords_vector point) {
		// pitch - point at Y axis in [-89, 89] degrees range - arcsin of Z coord and hypotenuse
		// yaw - point at X axis in [-180, 180] degrees range
		DWORD clst = memory->read_mem<DWORD>(memory->engineBaseAddr + signatures::dwClientState);
		coords_vector view_angles = memory->read_mem<coords_vector>(clst + signatures::dwClientState_ViewAngles);

		coords_vector position = get_origin();
		coords_vector view_point = get_view_offset();
		coords_vector view_pos({ position.x + view_point.x, position.y + view_point.y, position.z + view_point.z });

		coords_vector delta({ point.x - view_pos.x, point.y - view_pos.y, point.z - view_pos.z }); // Y distance between local player view offset (eyes position) and point operand
		float delta_len = (float)sqrt(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z); // distance between two points (hypotenuse)

		float pitch = (float)-asin(delta.z / delta_len) * (180 / (float)M_PI); // -asin because 89 deg is floor and -89 deg is ceil
		float yaw = (float)atan2(delta.y, delta.x) * (180 / (float)M_PI);

		if (pitch >= -89 && pitch <= 89 && yaw >= -180 && yaw <= 180) {
			view_angles.x = pitch; // / smoothing;
			view_angles.y = yaw; // / smoothing;
		}

		memory->write_mem<coords_vector>(clst + signatures::dwClientState_ViewAngles, view_angles);
	}

	// [0, 100]
	inline DWORD get_health() {
		return memory->read_mem<DWORD>(playerBaseAddr + netvars::m_iHealth);
	}

	inline bool get_dormant() {
		return memory->read_mem<bool>(playerBaseAddr + signatures::m_bDormant);
	}

	inline DWORD get_crosshair_id() {
		return memory->read_mem<DWORD>(playerBaseAddr + netvars::m_iCrosshairId);
	}

	// 2 - terrorist
	// 3 - counter terrorist
	inline int get_team() {
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
	inline BYTE get_flags() {
		return memory->read_mem<BYTE>(playerBaseAddr + netvars::m_fFlags);
	}

	inline float get_flash_duration() {
		return memory->read_mem<float>(playerBaseAddr + netvars::m_flFlashDuration);
	}

	inline int get_glow_index() {
		return memory->read_mem<int>(playerBaseAddr + netvars::m_iGlowIndex);
	}

	inline DWORD get_base_addr() {
		return this->playerBaseAddr;
	}

	inline coords_vector get_velocity() {
		return memory->read_mem<coords_vector>(playerBaseAddr + netvars::m_vecVelocity);
	}

	inline bool is_moving() {
		coords_vector vec = get_velocity();
		float sum = vec.x + vec.y + vec.z;
		return sum < -0.003 || sum > 0; // 0.003 due to incorrect float precision
	}

	// player's x, y, z location on map
	inline coords_vector get_origin() {
		return memory->read_mem<coords_vector>(playerBaseAddr + netvars::m_vecOrigin);
	}

	// player's x, y, z eyes position
	inline coords_vector get_view_offset() {
		return memory->read_mem<coords_vector>(playerBaseAddr + netvars::m_vecViewOffset);
	}

	// player's x, y, z bone position
	// bone_id - an ID in bone's vector, the most important ones are: 8 - head, 7 - neck, 6, 5, 4, 3, 0 - chest (from top)
	inline coords_vector get_bone_position(int bone_id) {
		DWORD bone_matrix = memory->read_mem<DWORD>(playerBaseAddr + netvars::m_dwBoneMatrix);
		BoneMatrix bone = memory->read_mem<BoneMatrix>(bone_matrix + bone_id * 0x30);
		return coords_vector({ bone.x, bone.y, bone.z });
	}

	// returns rn::vector3 bone position. needed for bsp parser
	inline vector3 get_bone_position_v3(int bone_id) {
		coords_vector cv = get_bone_position(bone_id);
		const std::array<float, 3U> vec = { cv.x, cv.y, cv.z };
		return vector3(vec);
	}

	// returns rn::vector3 view offset. needed for bsp parser
	inline vector3 get_view_offset_v3() {
		coords_vector cv = get_view_offset();
		const std::array<float, 3U> vec = { cv.x, cv.y, cv.z };
		return vector3(vec);
	}

	// returns the distance between 2 player's entities (XYZ points)
	// https://www.math.usm.edu/lambers/mat169/fall09/lecture17.pdf
	inline float get_distance(coords_vector target) {
		coords_vector local = get_origin();
		return (float)sqrt(pow(target.x - local.x, 2) + pow(target.y - local.y, 2) + pow(target.z - local.z, 2));
	}

	// returns the distance between two points located on XY coords
	inline float get_distance_2d(coords_vector p1, coords_vector p2) {
		return (float)sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	}
};
#endif