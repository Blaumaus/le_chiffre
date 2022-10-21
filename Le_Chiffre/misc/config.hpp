#ifndef CONFIG_HPP
#define CONFIG_HPP
#pragma once
#include <string>
#include "xor.hpp"

namespace {
	// Config
	const ::std::string CHEAT_VERSION = XorStr("v1.5.2");
	const ::std::string RELEASE_DATE = XorStr("[21 Oct, 2022] -m1tZw Kai");
	const wchar_t* HOST = L"api.github.com";
	const wchar_t* PATH = L"/repos/blaumaus/le_chiffre/tags?per_page=1";
	const wchar_t* TARGET = L"csgo.exe";
	const wchar_t* CLIENT_DLL = L"client.dll";
	const wchar_t* ENGINE_DLL = L"engine.dll";
	LPCSTR WINDOW_NAME = "Counter-Strike: Global Offensive";

	// Common
	struct coords_vector {
		float x, y, z;
	};

	struct hacks_coords {
		COORD no_flash, activate_trigger, use_trigger, enemy_wh, radar_hack, bunny_hop, aimbot, process, game, version, language;
	};

	struct hacks_state {
		//for debug so i made these all open
		bool no_flash = true;
		bool activate_trigger = true;
		bool use_trigger = true;
		bool enemy_wh = true;
		bool radar_hack = true;
		bool bunny_hop = true;
		bool aimbot = true;
		bool process = true;
		bool game = true;
	};
}
#endif