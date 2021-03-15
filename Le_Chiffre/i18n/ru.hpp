#ifndef INTERNALISATION_RU_HPP
#define INTERNALISATION_RU_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> ru {
		{"on", XorStrW(L"���")},
		{"off", XorStrW(L"����")},
		{XorStr("yes"), XorStrW(L"��")},
		{XorStr("no"), XorStrW(L"���")},
		{XorStr("loading"), XorStrW(L"��������")},
		{XorStr("outdated"), XorStrW(L"����������")},
		{XorStr("latest"), XorStrW(L"���������")},
		{XorStr("error"), XorStrW(L"������")},
		{XorStr("hold"), XorStrW(L"����������")},
		{XorStr("press"), XorStrW(L"������")},
		{XorStr("waiting"), XorStrW(L"��������")},
		{XorStr("connecting"), XorStrW(L"�����������")},
		{XorStr("website"), XorStrW(L"����������� �������: https://lechiffre.now.sh")},
		{XorStr("state"), XorStrW(L"���������")},
		{XorStr("language"), XorStrW(L"���� (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"���������� � CS:GO")},
		{XorStr("connected_game"), XorStrW(L"���������� � �����")},
		{XorStr("version"), XorStrW(L"������")},
		{XorStr("cheat_functions"), XorStrW(L"������� ����")},
		{XorStr("bunny_hop"), XorStrW(L"�����-��� (F2)")},
		{XorStr("no_flash"), XorStrW(L"����-������������ ������� (F3)")},
		{XorStr("aimbot"), XorStrW(L"������ (F4)")},
		{XorStr("triggerbot"), XorStrW(L"������������ ������� ��� (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"������������ ������� ��� (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"�� (F8)")},
		{XorStr("radar_hack"), XorStrW(L"����� ��� (F9)")},
		{XorStr("exit"), XorStrW(L"���������� ����� (END)")}
	};
}
#endif // INTERNALISATION_RU_HPP