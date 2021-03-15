// An invisible D3DX9 overlay over the target process
#ifndef OVERLAY_HPP
#define OVERLAY_HPP
#pragma once

#include <Windows.h>
#include <d3d9.h>
#include "paint.hpp"
#include "../memory.hpp"
#include <iostream>
#include <dwmapi.h>
#include "../misc/xor.hpp"
#pragma comment(lib, "dwmapi.lib")

Paint paint; // draw, write text or do other manipulations with the overlay

class Overlay {
private:
	WCHAR _title[20]; // overlay window title
    Memory* mem;
    RECT rect; // coordinates of target window

    // registers window class
    ATOM _register_ñlass() {
        WNDCLASSEX wc;
        ZeroMemory(&wc, sizeof(WNDCLASSEX));

        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = WndProc;
        wc.cbClsExtra = NULL;
        wc.cbWndExtra = NULL;
        wc.hInstance = GetModuleHandle(NULL);
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = WHITE_BRUSH;
        wc.lpszMenuName = NULL;
        wc.lpszClassName = _title;
        wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

        return RegisterClassEx(&wc);
    }

    // initialise overlay instance
    bool _init_instance(int width, int height) {
        hwnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, _title, _title, WS_POPUP, rect.left, rect.top, width, height, 0, 0, 0, 0);
        if (!hwnd) return false;

        SetLayeredWindowAttributes(hwnd, 0, 1.0f, LWA_ALPHA);
        SetLayeredWindowAttributes(hwnd, 0, RGB(0, 0, 0), LWA_COLORKEY);

        MARGINS _margins = { -1, -1, width, height };
        DwmExtendFrameIntoClientArea(hwnd, &_margins);

        ShowWindow(hwnd, SW_SHOW);
        return true;
    }

    void _set_title() {
        for (byte i = 0; i < 19; ++i) {
            _title[i] = 97 + rand() % 26; // [97, 122] - a-z in ASCII
        }
        _title[19] = '\0';
    }

public:
    HWND hwnd; // an HWND to the overlay window

    Overlay(Memory* mem) {
        this->mem = mem;
        if (!init()) {
            MessageBox(
                NULL, 
                XorStrW(L"Error during overlay initialisation.\nThis is most likely due to the cheat failing to detect the game process.\nPlease make sure the game is running and try again."), 
                NULL, 
                MB_OK | MB_ICONERROR | MB_TOPMOST
            );
        }
    }

    ~Overlay() {
        DestroyWindow(hwnd);
    }

    bool init() {
        if (!mem->tHWND) return false;
        if (!GetWindowRect(mem->tHWND, &rect)) return false;
        _set_title();
        // std::cout << "x: [" << rect.left << ", " << rect.top << "]; y: [" << rect.right << ", " << rect.bottom << "]" << std::endl;
        _register_ñlass();

        if (!_init_instance(rect.right - rect.left, rect.bottom - rect.top)) return false;
        paint = Paint(hwnd, mem->tHWND, rect.right - rect.left, rect.bottom - rect.top);
        
        return true;
    }

    DWORD APIENTRY start() {
        MSG msg;

        //while (GetMessage(&msg, nullptr, 0, 0)) {}

        while (true) {
            if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {
                if (msg.message == WM_QUIT) break;
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                
                GetWindowRect(mem->tHWND, &rect);
                int width = rect.right - rect.left;
                int height = rect.bottom - rect.top;

                MoveWindow(hwnd, rect.left, rect.top, width, height, true);
            }
            Sleep(10);
        }

        return (int)msg.wParam;
    }

    static DWORD WINAPI static_start(void* param) {
        Overlay* ol = (Overlay*)param;
        return ol->start();
    }

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
        switch (message) {
        case WM_PAINT:
            paint.render();
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
        return 0;
    }
};
#endif