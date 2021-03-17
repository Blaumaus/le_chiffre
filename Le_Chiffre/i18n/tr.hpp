#ifndef INTERNALISATION_TR_HPP
#define INTERNALISATION_TR_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> tr{
		{XorStr("on"), XorStrW(L"AÇIK")},
		{XorStr("off"), XorStrW(L"KAPALI")},
		{XorStr("yes"), XorStrW(L"EVET")},
		{XorStr("no"), XorStrW(L"HAYIR")},
		{XorStr("loading"), XorStrW(L"YÜKLENİYOR")},
		{XorStr("outdated"), XorStrW(L"GÜNCEL DEĞİL")},
		{XorStr("latest"), XorStrW(L"SON")},
		{XorStr("error"), XorStrW(L"HATA")},
		{XorStr("hold"), XorStrW(L"BASILI TUT")},
		{XorStr("press"), XorStrW(L"BAS")},
		{XorStr("waiting"), XorStrW(L"BEKLENİYOR")},
		{XorStr("connecting"), XorStrW(L"BAĞLANILIYOR")},
		{XorStr("website"), XorStrW(L"Resmi site: https://lechiffre.now.sh")},
		{XorStr("state"), XorStrW(L"Durum")},
		{XorStr("language"), XorStrW(L"Dil (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"CS:GO işlemine bağlı")},
		{XorStr("connected_game"), XorStrW(L"Aktif oyuna bağlandı")},
		{XorStr("version"), XorStrW(L"Sürüm")},
		{XorStr("cheat_functions"), XorStrW(L"Hile fonksiyonları")},
		{XorStr("bunny_hop"), XorStrW(L"Bunny hop (F2)")},
		{XorStr("no_flash"), XorStrW(L"Flashlardan kör olmama (F3)")},
		{XorStr("aimbot"), XorStrW(L"Aimbot (F4)")},
		{XorStr("triggerbot"), XorStrW(L"Trigger bot'u aktifleştir (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"Trigger bot'u kullan (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"Wallhack (F8)")},
		{XorStr("radar_hack"), XorStrW(L"Radar hilesi (F9)")},
		{XorStr("exit"), XorStrW(L"Anında çıkış (END)")}
	};
}
#endif // INTERNALISATION_TR_HPP