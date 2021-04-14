#ifndef INTERNALISATION_UK_HPP
#define INTERNALISATION_UK_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> uk {
		{XorStr("on"), XorStrW(L"УВІМК")},
		{XorStr("off"), XorStrW(L"ВИМК")},
		{XorStr("yes"), XorStrW(L"ТАК")},
		{XorStr("no"), XorStrW(L"НІ")},
		{XorStr("loading"), XorStrW(L"ЗАВАНТАЖЕННЯ")},
		{XorStr("outdated"), XorStrW(L"УСТАРІВША")},
		{XorStr("latest"), XorStrW(L"ОСТАННЯ")},
		{XorStr("error"), XorStrW(L"ПОМИЛКА")},
		{XorStr("hold"), XorStrW(L"УТРИМУВАТИ")},
		{XorStr("press"), XorStrW(L"НАТИСНУТИ")},
		{XorStr("waiting"), XorStrW(L"ОЧІКУВАННЯ")},
		{XorStr("connecting"), XorStrW(L"ПІДКЛЮЧЕННЯ")},
		{XorStr("website"), XorStrW(L"Офіційний вебсайт: https://lechiffre.vercel.app")},
		{XorStr("state"), XorStrW(L"Стан")},
		{XorStr("language"), XorStrW(L"Мова (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"Підключено до CS:GO")},
		{XorStr("connected_game"), XorStrW(L"Підключено до матчу")},
		{XorStr("version"), XorStrW(L"Версія")},
		{XorStr("cheat_functions"), XorStrW(L"Функції чіту")},
		{XorStr("bunny_hop"), XorStrW(L"Банні-хоп (F2)")},
		{XorStr("no_flash"), XorStrW(L"Анти-світлошумові гранати (F3)")},
		{XorStr("aimbot"), XorStrW(L"Аімбот (F4)")},
		{XorStr("triggerbot"), XorStrW(L"Активувати тригер бот (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"Використовувати тригер бот (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"ВХ (F8)")},
		{XorStr("radar_hack"), XorStrW(L"Радар хак (F9)")},
		{XorStr("exit"), XorStrW(L"Екстренний вихід (END)")}
	};
}
#endif // INTERNALISATION_UK_HPP