#ifndef INTERNALISATION_UK_HPP
#define INTERNALISATION_UK_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> uk {
		{XorStr("on"), XorStrW(L"�²��")},
		{XorStr("off"), XorStrW(L"����")},
		{XorStr("yes"), XorStrW(L"���")},
		{XorStr("no"), XorStrW(L"Ͳ")},
		{XorStr("loading"), XorStrW(L"������������")},
		{XorStr("outdated"), XorStrW(L"����в���")},
		{XorStr("latest"), XorStrW(L"�������")},
		{XorStr("error"), XorStrW(L"�������")},
		{XorStr("hold"), XorStrW(L"����������")},
		{XorStr("press"), XorStrW(L"���������")},
		{XorStr("waiting"), XorStrW(L"�ײ�������")},
		{XorStr("connecting"), XorStrW(L"ϲ���������")},
		{XorStr("website"), XorStrW(L"��������� �������: https://lechiffre.now.sh")},
		{XorStr("state"), XorStrW(L"����")},
		{XorStr("language"), XorStrW(L"���� (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"ϳ�������� �� CS:GO")},
		{XorStr("connected_game"), XorStrW(L"ϳ�������� �� �����")},
		{XorStr("version"), XorStrW(L"�����")},
		{XorStr("cheat_functions"), XorStrW(L"������� ����")},
		{XorStr("bunny_hop"), XorStrW(L"����-��� (F2)")},
		{XorStr("no_flash"), XorStrW(L"����-���������� ������� (F3)")},
		{XorStr("aimbot"), XorStrW(L"������ (F4)")},
		{XorStr("triggerbot"), XorStrW(L"���������� ������ ��� (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"��������������� ������ ��� (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"�� (F8)")},
		{XorStr("radar_hack"), XorStrW(L"����� ��� (F9)")},
		{XorStr("exit"), XorStrW(L"���������� ����� (END)")}
	};
}
#endif // INTERNALISATION_UK_HPP