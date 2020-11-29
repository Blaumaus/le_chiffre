#ifndef CONFIG_HPP
#define CONFIG_HPP
#pragma once

namespace {
	const wchar_t* TARGET = L"csgo.exe";
	const wchar_t* CLIENT_DLL = L"client.dll";
	const wchar_t* ENGINE_DLL = L"engine.dll";
	LPCSTR WINDOW_NAME = "Counter-Strike: Global Offensive";

	struct coords_vector {
		float x, y, z;
	};
}
#endif