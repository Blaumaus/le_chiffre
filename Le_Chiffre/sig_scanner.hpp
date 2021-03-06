// A signature scanner to obtain game memory offsets by provided memory patterns
#ifndef SIG_SCANNER
#define SIG_SCANNER
#pragma once
#include <Windows.h>
#include <cstddef>
#include <iostream>

class SigScanner {
private:
	HANDLE process;

	intptr_t _scan(const char* pattern, const char* mask, char* begin, unsigned size) {
		unsigned patternLength = strlen(mask);

		for (unsigned i = 0; i < size - patternLength; i++) {
			bool found = true;

			for (unsigned j = 0; j < patternLength; j++) {
				if (mask[j] != '?' && pattern[j] != *(char*)((intptr_t)begin + i + j)) {
					found = false;
					break;
				}
			}

			if (found) return ((intptr_t)begin + i);
		}

		return 0;
	}

	char* _find_signature(char* pattern, char* mask, char* begin, intptr_t size) {
		char* match { nullptr };
		SIZE_T bytesRead;
		DWORD oldprotect;
		char* buffer{ nullptr };
		MEMORY_BASIC_INFORMATION mbi;
		mbi.RegionSize = 0x1000;//

		VirtualQueryEx(process, (LPCVOID)begin, &mbi, sizeof(mbi));

		for (char* current = begin; current < begin + size; current += mbi.RegionSize) {
			if (!VirtualQueryEx(process, (LPCVOID)current, &mbi, sizeof(mbi))) continue;
			if (mbi.State != MEM_COMMIT || mbi.Protect == PAGE_NOACCESS) continue;

			delete[] buffer;
			buffer = new char[mbi.RegionSize];

			if (VirtualProtectEx(process, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect)) {
				ReadProcessMemory(process, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
				VirtualProtectEx(process, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

				intptr_t internalAddr = _scan(pattern, mask, buffer, bytesRead);

				if (internalAddr != 0) {
					match = current + (internalAddr - (intptr_t)buffer);
					break;
				}
			}
		}

		delete[] buffer;
		return match;
	}

public:
	SigScanner() {
		process = nullptr;
	}

	SigScanner(HANDLE process) {
		this->process = process;
	}

	char* find (const char* signature, char* begin, intptr_t size) {
		char pattern[50];
		char mask[50];
		char last_char = ' ';
		unsigned int j = 0;

		for (unsigned int i = 0; i < strlen(signature); ++i, ++j) {
			if ((signature[i] == '?' || signature[i] == '*') && (last_char != '?' && last_char != '*')) {
				pattern[j] = mask[j] = '?';
			} else if (isspace(last_char)) {
				pattern[j] = last_char = (char)strtol(&signature[i], 0, 16);
				mask[j] = 'x';
			}

			last_char = signature[i];
		}
		pattern[j] = mask[j] = '\0';

		return _find_signature(pattern, mask, begin, size);
	}
};

#endif // !SIG_SCANNER