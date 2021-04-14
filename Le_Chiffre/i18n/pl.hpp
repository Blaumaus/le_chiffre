#ifndef INTERNALISATION_PL_HPP
#define INTERNALISATION_PL_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> pl{
		{XorStr("on"), XorStrW(L"WŁĄCZONA")},
		{XorStr("off"), XorStrW(L"WYŁĄCZONA")},
		{XorStr("yes"), XorStrW(L"TAK")},
		{XorStr("no"), XorStrW(L"NIE")},
		{XorStr("loading"), XorStrW(L"ZAŁADUNEK")},
		{XorStr("outdated"), XorStrW(L"PRZESTARZAŁA")},
		{XorStr("latest"), XorStrW(L"NAJNOWSZA")},
		{XorStr("error"), XorStrW(L"BŁĄD")},
		{XorStr("hold"), XorStrW(L"TRZYMAĆ")},
		{XorStr("press"), XorStrW(L"NACIŚNIJ")},
		{XorStr("waiting"), XorStrW(L"CZEKANIE")},
		{XorStr("connecting"), XorStrW(L"POŁĄCZENIE")},
		{XorStr("website"), XorStrW(L"Oficjalna strona internetowa: https://lechiffre.vercel.app")},
		{XorStr("state"), XorStrW(L"Stan")},
		{XorStr("language"), XorStrW(L"Język (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"Połączony z procesem CS:GO")},
		{XorStr("connected_game"), XorStrW(L"Podłączony do aktywnej gry")},
		{XorStr("version"), XorStrW(L"Wersja")},
		{XorStr("cheat_functions"), XorStrW(L"Funkcje")},
		{XorStr("bunny_hop"), XorStrW(L"Króliczy skok (F2)")},
		{XorStr("no_flash"), XorStrW(L"Nie oszałamia granat (F3)")},
		{XorStr("aimbot"), XorStrW(L"Aimbot (F4)")},
		{XorStr("triggerbot"), XorStrW(L"Aktywacja trigger bota (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"Użyj trigger bota (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"Glow ESP (F8)")},
		{XorStr("radar_hack"), XorStrW(L"Radar hack (F9)")},
		{XorStr("exit"), XorStrW(L"Natychmiastowe wyjście (END)")}
	};
}
#endif // INTERNALISATION_PL_HPP