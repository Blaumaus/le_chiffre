#ifndef INTERNALISATION_FR_HPP
#define INTERNALISATION_FR_HPP
#pragma once
#include <map>
#include <string>

#include "../misc/xor.hpp"

namespace i18n {
	std::map<std::string, std::wstring> fr{
		{XorStr("on"), XorStrW(L"ACTIF")},
		{XorStr("off"), XorStrW(L"INACTIF")},
		{XorStr("yes"), XorStrW(L"OUI")},
		{XorStr("no"), XorStrW(L"NON")},
		{XorStr("loading"), XorStrW(L"CHARGEMENT")},
		{XorStr("outdated"), XorStrW(L"DÉPASSÉ")},
		{XorStr("latest"), XorStrW(L"DERNIERE")},
		{XorStr("error"), XorStrW(L"ERREUR")},
		{XorStr("hold"), XorStrW(L"MAINTENIR")},
		{XorStr("press"), XorStrW(L"PRESSER")},
		{XorStr("waiting"), XorStrW(L"EN ATTENTE")},
		{XorStr("connecting"), XorStrW(L"EN COURS DE CONNEXION")},
		{XorStr("website"), XorStrW(L"Le site web officiel: https://lechiffre.now.sh")},
		{XorStr("state"), XorStrW(L"État")},
		{XorStr("language"), XorStrW(L"Langue (F1)")},
		{XorStr("connected_csgo"), XorStrW(L"Connecté au processus CS:GO")},
		{XorStr("connected_game"), XorStrW(L"Connecté a la partie active")},
		{XorStr("version"), XorStrW(L"Version")},
		{XorStr("cheat_functions"), XorStrW(L"Fonctionalité du logiciel de triche")},
		{XorStr("bunny_hop"), XorStrW(L"Bunny hop (F2)")},
		{XorStr("no_flash"), XorStrW(L"Pas d'effet de flash (F3)")},
		{XorStr("aimbot"), XorStrW(L"Aimbot (F4)")},
		{XorStr("triggerbot"), XorStrW(L"Activer auto-tir (F6)")},
		{XorStr("use_triggerbot"), XorStrW(L"Déclencher auto-tir (LAlt)")},
		{XorStr("glowesp"), XorStrW(L"Afficher (F8)")},
		{XorStr("radar_hack"), XorStrW(L"Afficher Ennemi sur la Carte (F9)")},
		{XorStr("exit"), XorStrW(L"Quitter (END)")}
	};
}
#endif // INTERNALISATION_FR_HPP