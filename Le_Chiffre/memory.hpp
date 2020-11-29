#ifndef MEMORY_HPP
#define MEMORY_HPP

#pragma once
#pragma warning(disable: 6276)

#include <Windows.h>
#include <TlHelp32.h>
#include "config.hpp"

class Memory {
public:
	DWORD tPID;
	DWORD clientBaseAddr;
	DWORD engineBaseAddr;
	HANDLE tProcess;
	HWND tHWND;

	Memory() {
		this->tPID = NULL;
		this->tProcess = NULL;

		if (!this->handle_process(TARGET)) return;

		this->tHWND = FindWindowA(0, WINDOW_NAME);
		this->clientBaseAddr = get_module(CLIENT_DLL);
		this->engineBaseAddr = get_module(ENGINE_DLL);
	}

	~Memory() {
		CloseHandle(tProcess);
	}

	HANDLE handle_process(const wchar_t* processName) {
		HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(entry);

		do {
			if (!wcscmp(entry.szExeFile, processName)) {
				tPID = entry.th32ProcessID;
				CloseHandle(handle);
				tProcess = OpenProcess(PROCESS_ALL_ACCESS, false, tPID);
				return tProcess;
			}
		} while (Process32Next(handle, &entry));
		CloseHandle(handle);
		return NULL;
	}

	DWORD get_module(const wchar_t* moduleName) {
		HANDLE hmodule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, tPID);
		MODULEENTRY32 me32;
		me32.dwSize = sizeof(me32);

		do {
			if (!wcscmp(me32.szModule, moduleName)) {
				CloseHandle(hmodule);
				return (DWORD)me32.modBaseAddr;
			}
		} while (Module32Next(hmodule, &me32));

		CloseHandle(hmodule);
		return NULL;
	}

	template <typename var>
	bool write_mem(DWORD address, var value) {
		return WriteProcessMemory(tProcess, (LPVOID)address, &value, sizeof(var), NULL);
	}

	template <typename var>
	var read_mem(DWORD address) {
		var value;
		ReadProcessMemory(tProcess, (LPCVOID)address, &value, sizeof(var), NULL);
		return value;
	}
};
#endif