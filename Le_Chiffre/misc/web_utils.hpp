#ifndef WEB_UTILS_HPP
#define WEB_UTILS_HPP
#pragma once
#include <iostream>
#include <winhttp.h>
#include "xor.hpp"
#pragma comment(lib, "winhttp.lib")

// TODO: Refactor code
namespace web {
	// Sends a GET request
	// Returns a result or "ERROR" if status code != 200 or if something else went wrong
	std::string get(const wchar_t* host, const wchar_t* path, INTERNET_PORT port = INTERNET_DEFAULT_HTTPS_PORT) {
		HINTERNET hSession = NULL, hConnect = NULL, hRequest = NULL;
		std::string res = XorStr("ERROR");

		hSession = WinHttpOpen(L"WinHTTP/1.0", WINHTTP_ACCESS_TYPE_NO_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);

		if (hSession) {
			if (hConnect = WinHttpConnect(hSession, host, port, 0)) hRequest = WinHttpOpenRequest(hConnect, L"GET", path, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);

			if (hRequest && WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0) && WinHttpReceiveResponse(hRequest, NULL)) {
				DWORD status, len = sizeof(status), read_bytes = 0;
				char* buffer = (char*)malloc(1000);

				if (WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL, &status, &len, NULL)) {
					if (status == 200 && WinHttpReadData(hRequest, buffer, 1000, &read_bytes)) {
						realloc(buffer, read_bytes);
						res = buffer;
					}
				}
				free(buffer);
			}

			if (hRequest) WinHttpCloseHandle(hRequest);
			if (hConnect) WinHttpCloseHandle(hConnect);
			WinHttpCloseHandle(hSession);
		} // else std::cout << "WinHTTP ERROR CODE: " << GetLastError();

		return res;
	}
}

#endif // !WEB_UTILS_HPP