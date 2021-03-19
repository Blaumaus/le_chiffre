#ifndef INTERNALISATION_ZH_HPP
#define INTERNALISATION_ZH_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> zh{
		{XorStr("on"), XorStrW(L"打开")},
		{XorStr("off"), XorStrW(L"关")},
		{XorStr("yes"), XorStrW(L"是")},
		{XorStr("no"), XorStrW(L"不")},
		{XorStr("loading"), XorStrW(L"载入中")},
		{XorStr("outdated"), XorStrW(L"过时的")},
		{XorStr("latest"), XorStrW(L"最新的")},
		{XorStr("error"), XorStrW(L"错误")},
		{XorStr("hold"), XorStrW(L"持有")},
		{XorStr("press"), XorStrW(L"按")},
		{XorStr("waiting"), XorStrW(L"等候")},
		{XorStr("connecting"), XorStrW(L"连接")},
		{XorStr("website"), XorStrW(L"官方网站: https://lechiffre.now.sh")},
		{XorStr("state"), XorStrW(L"State")},
		{XorStr("language"), XorStrW(L"语种 (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"连接的到CS:GO进程")},
		{XorStr("connected_game"), XorStrW(L"已连接到活动游戏")},
		{XorStr("version"), XorStrW(L"版本")},
		{XorStr("cheat_functions"), XorStrW(L"功能")},
		{XorStr("bunny_hop"), XorStrW(L"兔子跳 (F2)")},
		{XorStr("no_flash"), XorStrW(L"无闪光 (F3)")},
		{XorStr("aimbot"), XorStrW(L"瞄准机器人 (F4)")},
		{XorStr("triggerbot"), XorStrW(L"激活触发机器人 (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"使用触发机器人 (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"敌人的光芒ESP (F8)")},
		{XorStr("radar_hack"), XorStrW(L"逆向雷达 (F9)")},
		{XorStr("exit"), XorStrW(L"立马退出 (END)")}
	};
}
#endif // INTERNALISATION_ZH_HPP