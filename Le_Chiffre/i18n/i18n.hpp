#ifndef INTERNALISATION_HPP
#define INTERNALISATION_HPP
#pragma once
#include <string>
#include <map>
#include <vector>

#include "en.hpp"
#include "uk.hpp"

namespace i18n {
	using std::string;
	using std::vector;
	using std::map;

  // WinAPI function to retrieve user's locale, e.g. 'en' or 'uk'
	std::string get_user_localisation() {
		wchar_t lpLocaleName[LOCALE_NAME_MAX_LENGTH] = { 0 };

		if (GetUserDefaultLocaleName(lpLocaleName, LOCALE_NAME_MAX_LENGTH) != 0) {
			return std::wstring(lpLocaleName).substr(0, 2);
		}
	}

	map<std::string, map<string, wstring>> t {
		{ "en", en },
		{ "uk", uk },
	};

	class Internalisation {
	private:
		vector<string> available;
		vector<string>::iterator lang_it;

		// Returns available translation codes
		vector<string> get_keys() {
			vector<string> keys;

			for (auto const& it : t) {
				keys.push_back(it.first);
			}

			return keys;
		}

	public:
		Internalisation() {
			available = get_keys();
			lang_it = available.begin();
		}

		string get_lang() {
			return *lang_it;
		}

		// If a valid language code is provided, it switches current language into it,
		// otherwise it switches the current language to the next language available
		void switch_language (string code = "") {
			if (!code.empty()) {
				for (auto it = available.begin(); it != available.end(); ++it) {
					if (*it == code) {
						lang_it = it;
						return;
					}
				}
			}

			if (lang_it == available.end() - 1) lang_it = available.begin();
			else ++lang_it;
		}

		// Returns the corresponding translation of 'key'
		std::wstring translate (string key) {
			return t[*lang_it][key];
		}
	};

} // namespace i18n
#endif // INTERNALISATION_HPP