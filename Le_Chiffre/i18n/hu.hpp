#ifndef INTERNALISATION_HU_HPP
#define INTERNALISATION_HU_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> hu{
		{XorStr("on"), XorStrW(L"ON")},
		{XorStr("off"), XorStrW(L"OFF")},
		{XorStr("yes"), XorStrW(L"IGEN")},
		{XorStr("no"), XorStrW(L"NEM")},
		{XorStr("loading"), XorStrW(L"BETÖLTÉS")},
		{XorStr("outdated"), XorStrW(L"ELAVULT")},
		{XorStr("latest"), XorStrW(L"LEGÚJABB")},
		{XorStr("error"), XorStrW(L"ERROR")},
		{XorStr("hold"), XorStrW(L"TARTSD")},
		{XorStr("press"), XorStrW(L"NYOMD")},
		{XorStr("waiting"), XorStrW(L"VÁRAKOZÁS")},
		{XorStr("connecting"), XorStrW(L"CSATLAKOZÁS")},
		{XorStr("website"), XorStrW(L"A hivatalos honlap: https://lechiffre.now.sh")},
		{XorStr("state"), XorStrW(L"Állapot")},
		{XorStr("language"), XorStrW(L"Nyelv (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"Csatlakozva a CS:GO folyamathoz")},
		{XorStr("connected_game"), XorStrW(L"Csatlakozva aktív játékhoz")},
		{XorStr("version"), XorStrW(L"Verzió")},
		{XorStr("cheat_functions"), XorStrW(L"Cheat funkciók")},
		{XorStr("bunny_hop"), XorStrW(L"Nyuszi hopp (F2)")},
		{XorStr("no_flash"), XorStrW(L"Nem vakulsz (F3)")},
		{XorStr("aimbot"), XorStrW(L"Aimbot (F4)")},
		{XorStr("triggerbot"), XorStrW(L"Trigger bot aktiválása (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"Trigger bot használata (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"Fénylő ESP (F8)")},
		{XorStr("radar_hack"), XorStrW(L"Radar hack (F9)")},
		{XorStr("exit"), XorStrW(L"Azonnali bezárás (END)")}
	};
}
#endif // INTERNALISATION_HU_HPP