#ifndef CONFIG_HPP
#define CONFIG_HPP
#pragma once
#include <string>

namespace {
	const ::std::string CHEAT_VERSION = "v1.1.1";
	const wchar_t* HOST = L"api.github.com";
	const wchar_t* PATH = L"/repos/blaumaus/le_chiffre/tags?per_page=1";
	const wchar_t* TARGET = L"csgo.exe";
	const wchar_t* CLIENT_DLL = L"client.dll";
	const wchar_t* ENGINE_DLL = L"engine.dll";
	LPCSTR WINDOW_NAME = "Counter-Strike: Global Offensive";

	struct coords_vector {
		float x, y, z;
	};
}
#endif