#ifndef UTILS_HPP
#define UTILS_HPP
#pragma once
#include "config.hpp"
#include "web_utils.hpp"
#include "console_io.hpp"
#include <iostream>
#include <string>

// Manually gets the value of a key from a JSON string 
// Sorry about that, but I just don't want to import a JSON parsing library only because of one simple task
// I wrote all this code at 4 AM, so it probably needs some refactoring
std::string json_parse_string(std::string data, std::string key) {
	std::string buffer;
	bool quote_opened = false;
	bool key_found = false;

	for (char const& c : data) {
		if (c == '"') {
			if (!quote_opened) quote_opened = true;
			else {
				if (key_found) return buffer;
				if (buffer == key) key_found = true;
				quote_opened = false;
			}

			buffer.clear();
		}
		else if (quote_opened) buffer.push_back(c);
	}

	return {};
}

std::string get_latest_version() {
	std::string json = web::get(HOST, PATH);

	return json != "ERROR" ? json_parse_string(json, "name") : "ERROR";
}

// {ERROR, LATEST}
std::pair<bool, bool> is_latest() {
	std::string ver = get_latest_version();

	if (ver == "ERROR") return std::make_pair(true, false);
	return std::make_pair(false, ver == CHEAT_VERSION);
}

std::string get_user_localisation() {
	wchar_t lpLocaleName[LOCALE_NAME_MAX_LENGTH] = { 0 };
	
	if (GetUserDefaultLocaleName(lpLocaleName, LOCALE_NAME_MAX_LENGTH) != 0) {
		std::wstring lang = std::wstring(lpLocaleName).substr(0, 2);

		if (lang == L"uk") return XorStr("UK");
		if (lang == L"ru") return XorStr("RU");
		//if (lang == L"zh") return XorStr("ZH");
		//if (lang == L"pl") return XorStr("PL");
		//if (lang == L"fr") return XorStr("FR");
		//if (lang == L"tr") return XorStr("TR");
	}


	return XorStr("EN");
}
#endif // !UTILS_HPP