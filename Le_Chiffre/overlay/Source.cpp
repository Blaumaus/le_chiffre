/*#include <Windows.h>
#include <TlHelp32.h>

#define dwEntityList 0x4D3C5FC
#define dwViewMatrix 0x4D2E014
#define m_iTeamNum 0xF4
#define m_iHealth 0x100
#define m_vecOrigin 0x138

uintptr_t moduleBase;
HANDLE TargetProcess;
HPEN BoxPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
RECT WBounds;
HWND EspHWND;

template<typename T> T RPM(SIZE_T address) {
	T buffer;
	ReadProcessMemory(TargetProcess, (LPCVOID)address, &buffer, sizeof(T), NULL);
	return buffer;
}

uintptr_t GetModuleBaseAddress(DWORD dwPid, const char* moduleName) {
	uintptr_t dwBase = 0;
	do {
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwPid);
		if (hSnapshot == INVALID_HANDLE_VALUE) { continue; }
		MODULEENTRY32 ModuleEntry32;
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &ModuleEntry32)) {
			do {
				if (!strcmp(ModuleEntry32.szModule, (LPSTR)moduleName)) {
					dwBase = (DWORD)ModuleEntry32.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnapshot, &ModuleEntry32));
		}
		CloseHandle(hSnapshot);
	} while (!dwBase);
	return dwBase;
}

struct Vector3 {
	float x, y, z;
};

struct view_matrix_t {
	float matrix[16];
};

struct Vector3 WorldToScreen(const struct Vector3 pos, struct view_matrix_t matrix) {
	struct Vector3 out;
	float _x = matrix.matrix[0] * pos.x + matrix.matrix[1] * pos.y + matrix.matrix[2] * pos.z + matrix.matrix[3];
	float _y = matrix.matrix[4] * pos.x + matrix.matrix[5] * pos.y + matrix.matrix[6] * pos.z + matrix.matrix[7];
	out.z = matrix.matrix[12] * pos.x + matrix.matrix[13] * pos.y + matrix.matrix[14] * pos.z + matrix.matrix[15];

	_x *= 1.f / out.z;
	_y *= 1.f / out.z;

	int width = WBounds.right - WBounds.left;
	int height = WBounds.bottom + WBounds.left;

	out.x = width * .5f;
	out.y = height * .5f;

	out.x += 0.5f * _x * width + 0.5f;
	out.y -= 0.5f * _y * height + 0.5f;

	return out;
}

void Draw(HDC hdc, Vector3 foot, Vector3 head) {
	float height = head.y - foot.y;
	float width = height / 2.4f;
	SelectObject(hdc, BoxPen);
	Rectangle(hdc, foot.x - (width / 2), foot.y, head.x + (width / 2), head.y);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC Memhdc;
		HDC hdc;
		HBITMAP Membitmap;

		int win_width = WBounds.right - WBounds.left;
		int win_height = WBounds.bottom + WBounds.left;

		hdc = BeginPaint(hwnd, &ps);
		Memhdc = CreateCompatibleDC(hdc);
		Membitmap = CreateCompatibleBitmap(hdc, win_width, win_height);
		SelectObject(Memhdc, Membitmap);
		FillRect(Memhdc, &WBounds, WHITE_BRUSH);

		view_matrix_t vm = RPM<view_matrix_t>(moduleBase + dwViewMatrix);
		int localteam = RPM<int>(RPM<DWORD>(moduleBase + dwEntityList) + m_iTeamNum);

		for (int i = 1; i < 64; i++) {
			uintptr_t pEnt = RPM<DWORD>(moduleBase + dwEntityList + (i * 0x10));
			int team = RPM<int>(pEnt + m_iTeamNum);

			if (team != localteam) {
				int health = RPM<int>(pEnt + m_iHealth);
				Vector3 pos = RPM<Vector3>(pEnt + m_vecOrigin);
				Vector3 head; head.x = pos.x; head.y = pos.y; head.z = pos.z + 72.f;
				Vector3 screenpos = WorldToScreen(pos, vm);
				Vector3 screenhead = WorldToScreen(head, vm);
				float height = screenhead.y - screenpos.y;
				float width = height / 2.4f;

				if (screenpos.z >= 0.01f && health > 0 && health < 101) {
					Draw(Memhdc, screenpos, screenhead);
				}
			}
		}
		BitBlt(hdc, 0, 0, win_width, win_height, Memhdc, 0, 0, SRCCOPY);
		DeleteObject(Membitmap);
		DeleteDC(Memhdc);
		DeleteDC(hdc);
		EndPaint(hwnd, &ps);
		ValidateRect(hwnd, &WBounds);
	}
	case WM_ERASEBKGND:
		return 1;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

DWORD WorkLoop() {
	while (1) {
		InvalidateRect(EspHWND, &WBounds, true);
		Sleep(16); //16 ms * 60 fps ~ 1000 ms
	}
}

int main() {
	HWND GameHWND = FindWindowA(0, "Counter-Strike: Global Offensive");
	GetClientRect(GameHWND, &WBounds);
	DWORD dwPid; GetWindowThreadProcessId(GameHWND, &dwPid);
	TargetProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, dwPid);
	moduleBase = GetModuleBaseAddress(dwPid, "client_panorama.dll");

	WNDCLASSEX WClass;
	MSG Msg;
	WClass.cbSize = sizeof(WNDCLASSEX);
	WClass.style = NULL;
	WClass.lpfnWndProc = WndProc;
	WClass.cbClsExtra = NULL;
	WClass.cbWndExtra = NULL;
	WClass.hInstance = reinterpret_cast<HINSTANCE>(GetWindowLongA(GameHWND, GWL_HINSTANCE));
	WClass.hIcon = NULL;
	WClass.hCursor = NULL;
	WClass.hbrBackground = WHITE_BRUSH;
	WClass.lpszMenuName = " ";
	WClass.lpszClassName = " ";
	WClass.hIconSm = NULL;
	RegisterClassExA(&WClass);

	HINSTANCE Hinstance = NULL;
	EspHWND = CreateWindowExA(WS_EX_TRANSPARENT | WS_EX_TOPMOST | WS_EX_LAYERED, " ", " ", WS_POPUP, WBounds.left, WBounds.top, WBounds.right - WBounds.left, WBounds.bottom + WBounds.left, NULL, NULL, Hinstance, NULL);

	SetLayeredWindowAttributes(EspHWND, RGB(255, 255, 255), 255, LWA_COLORKEY);
	ShowWindow(EspHWND, 1);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&WorkLoop, NULL, NULL, NULL);
	while (GetMessageA(&Msg, NULL, NULL, NULL) > 0) {
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
		Sleep(1);
	}
	ExitThread(0);
	return 0;
}*/