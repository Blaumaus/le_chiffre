#ifndef ANTIVAC_HPP
#define ANTIVAC_HPP
#pragma once

#include "Windows.h"

class AntiVAC {
private:
	HMODULE module_handle;
public:
	AntiVAC() {
		module_handle = GetModuleHandle(NULL);
	}

	// https://github.com/LordNoteworthy/al-khaser/blob/8ff90a3979face6e29aacb12521b032f2b379073/al-khaser/AntiDump/ErasePEHeaderFromMemory.cpp#L8-L22
	void erase_pe_headers() {
		DWORD OldProtect = 0;

		VirtualProtect((char*)module_handle, 4096, // Assume x86 page size
			PAGE_READWRITE, &OldProtect);

		// Erase the header
		SecureZeroMemory((char*)module_handle, 4096);
	}
};

#endif