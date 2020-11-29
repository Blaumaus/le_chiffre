// Class which contains methods to draw stuff (text, boxes, lines) over Direct 3D 9 overlay.
#ifndef PAINT_HPP
#define PAINT_HPP
#pragma once
#pragma warning(disable: 26495)

#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

class Paint {
private:
	IDirect3D9Ex* object = NULL; // used to create device
	IDirect3DDevice9Ex* device = NULL; // contains functions like begin and end scene 
	D3DPRESENT_PARAMETERS params; 
	ID3DXFont* d3d_font = 0; // font used when displaying text

	HWND t_hwnd; // target process window
	int width; // target process width
	int height;

	int d3d9init(HWND hwnd) {
		if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &object))) {
			DestroyWindow(hwnd);
		}

		ZeroMemory(&params, sizeof(params));
		params.BackBufferWidth = width;
		params.BackBufferHeight = height;
		params.Windowed = TRUE;
		params.SwapEffect = D3DSWAPEFFECT_DISCARD;
		params.hDeviceWindow = hwnd;
		params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
		params.BackBufferFormat = D3DFMT_A8R8G8B8;
		params.EnableAutoDepthStencil = TRUE;
		params.AutoDepthStencilFormat = D3DFMT_D16;

		HRESULT res = object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &params, 0, &device);
		if (FAILED(res)) DestroyWindow(hwnd);

		D3DXCreateFont(device, 50, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEVICE_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, L"Consolas", &d3d_font);

		return 0;
	}

	void draw_text(char* text, int x, int y, int a, int r, int g, int b) {
		RECT rect;
		rect.left = x;
		rect.top = y;
		d3d_font->DrawTextA(0, text, strlen(text), &rect, DT_NOCLIP, D3DCOLOR_ARGB(a, r, g, b));
	}

public:
	Paint() {
		this->device = nullptr;
		this->object = nullptr;
	}

	~Paint() {
		if (object != NULL) object->Release();
		if (device != NULL) device->Release();
	}
	
	Paint(HWND hwnd, HWND t_hwnd, int width, int height) {
		this->t_hwnd = t_hwnd;
		this->width = width;
		this->height = height;
		d3d9init(hwnd);
	}

	int render() {
		if (device == nullptr) return 1;

		device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
		device->BeginScene();

		if (t_hwnd == GetForegroundWindow()) {
			draw_text((char*)"Test message", 15, 15, 255, 0, 0, 160);
		}

		device->EndScene();
		device->PresentEx(0, 0, 0, 0, 0);

		return 0;
	}
};

#endif