#ifndef INTERNALISATION_RU_HPP
#define INTERNALISATION_RU_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> ru {
		{XorStr("on"), XorStrW(L"ВКЛ")},
		{XorStr("off"), XorStrW(L"ВЫКЛ")},
		{XorStr("yes"), XorStrW(L"ДА")},
		{XorStr("no"), XorStrW(L"НЕТ")},
		{XorStr("loading"), XorStrW(L"ЗАГРУЗКА")},
		{XorStr("outdated"), XorStrW(L"УСТАРЕВШАЯ")},
		{XorStr("latest"), XorStrW(L"ПОСЛЕДНЯЯ")},
		{XorStr("error"), XorStrW(L"ОШИБКА")},
		{XorStr("hold"), XorStrW(L"УДЕРЖИВАТЬ")},
		{XorStr("press"), XorStrW(L"НАЖАТЬ")},
		{XorStr("waiting"), XorStrW(L"ОЖИДАНИЕ")},
		{XorStr("connecting"), XorStrW(L"ПОДКЛЮЧЕНИЕ")},
		{XorStr("website"), XorStrW(L"Официальный вебсайт: https://lechiffre.vercel.app")},
		{XorStr("state"), XorStrW(L"Состояние")},
		{XorStr("language"), XorStrW(L"Язык (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"Подключено к CS:GO")},
		{XorStr("connected_game"), XorStrW(L"Подключено к матчу")},
		{XorStr("version"), XorStrW(L"Версия")},
		{XorStr("cheat_functions"), XorStrW(L"Функции чита")},
		{XorStr("bunny_hop"), XorStrW(L"Банни-хоп (F2)")},
		{XorStr("no_flash"), XorStrW(L"Анти-светошумовые гранаты (F3)")},
		{XorStr("aimbot"), XorStrW(L"Аимбот (F4)")},
		{XorStr("triggerbot"), XorStrW(L"Активировать триггер бот (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"Использовать триггер бот (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"ВХ (F8)")},
		{XorStr("radar_hack"), XorStrW(L"Радар хак (F9)")},
		{XorStr("exit"), XorStrW(L"Экстренный выход (END)")}
	};
}
#endif // INTERNALISATION_RU_HPP