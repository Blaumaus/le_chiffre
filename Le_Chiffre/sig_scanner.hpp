// A signature scanner to obtain game memory offsets by provided memory patterns
#ifndef SIG_SCANNER
#define SIG_SCANNER
#pragma once
#include <Windows.h>

class SigScanner {
private:
	HANDLE process;
	DWORD module;

public:
	SigScanner() {
		process = nullptr;
		module = NULL;
	}

	SigScanner(HANDLE process, DWORD module) {
		this->process = process;
		this->module = module;
	}

	ptrdiff_t find_signature(char* pattern, char* mask) {

	}
};

#endif // !SIG_SCANNER