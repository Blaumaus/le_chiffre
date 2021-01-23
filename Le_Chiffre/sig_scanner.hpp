// A signature scanner to obtain game memory offsets by provided memory patterns
#ifndef SIG_SCANNER
#define SIG_SCANNER
#pragma once
#include <Windows.h>

class SigScanner {
private:
	HANDLE process;

	char* _scan(const char* pattern, const char* mask, char* begin, unsigned size) {
		unsigned patternLength = strlen(mask);

		for (unsigned i = 0; i < size - patternLength; i++) {
			bool found = true;

			for (unsigned j = 0; j < patternLength; j++) {
				if (mask[j] != '?' && pattern[j] != *(begin + i + j)) {
					found = false;
					break;
				}
			}

			if (found) return (begin + i);
		}

		return nullptr;
	}

public:
	SigScanner() {
		process = nullptr;
	}

	SigScanner(HANDLE process) {
		this->process = process;
	}

	::std::ptrdiff_t find_signature(const char* pattern, const char* mask, DWORD begin, DWORD end) { // https://stackoverflow.com/a/55113370
		DWORD current = begin;
		::std::ptrdiff_t match = NULL;
		SIZE_T bytes_read = 0;

		while (current < end) {
			MEMORY_BASIC_INFORMATION mbi;

			if (!VirtualQueryEx(process, &current, &mbi, sizeof(mbi))) return NULL;

			char* buffer = new char[mbi.RegionSize];

			if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS) {
				DWORD protect;

				if (VirtualProtectEx(process, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &protect)) {
					ReadProcessMemory(process, mbi.BaseAddress, buffer, mbi.RegionSize, &bytes_read);
					VirtualProtectEx(process, mbi.BaseAddress, mbi.RegionSize, protect, &protect);

					char* address = _scan(pattern, mask, buffer, bytes_read);

					if (address != nullptr) { // internal address to external
						uintptr_t offsetFromBuffer = address - buffer;
						match = current + offsetFromBuffer;
						delete[] buffer;
						break;
					}
				}
			}

			current += mbi.RegionSize;
			delete[] buffer;
		}

		return match;
	}
};

#endif // !SIG_SCANNER