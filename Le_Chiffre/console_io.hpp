#ifndef CONSOLEIO_HPP
#define CONSOLEIO_HPP
#pragma once

#include <Windows.h>
// #include <versionhelpers.h>
#include <iostream>

class ConsoleIO {
private:
    HWND console_window;
    HANDLE screen_buffer;
    short screen_width;
    short screen_height;

    // adjusts window to desired width and height
    void _set_window() { // https://stackoverflow.com/a/40634467
        COORD const size = { screen_width, screen_height };

        SMALL_RECT const minimal_window = { 0, 0, 1, 1 };
        SetConsoleWindowInfo(screen_buffer, TRUE, &minimal_window);

        SetConsoleScreenBufferSize(screen_buffer, size);

        SMALL_RECT const window = { 0, 0, size.X - 1, size.Y - 1 };
        SetConsoleWindowInfo(screen_buffer, TRUE, &window);
    }

    void _set_cursor() {
        _CONSOLE_CURSOR_INFO const cursor_info = { 100, false };
        SetConsoleCursorInfo(screen_buffer, &cursor_info);
    }

public:
    ConsoleIO() {
        console_window = GetConsoleWindow();
        screen_buffer = GetStdHandle(STD_OUTPUT_HANDLE);
        screen_width = 75;
        screen_height = 22;

        SetWindowLong(console_window, GWL_STYLE, GetWindowLong(console_window, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        _set_window();
        _set_cursor();
    }

    void write_str(const char* str, WORD colour, bool clear_right = false) {
        SetConsoleTextAttribute(screen_buffer, colour);
        std::cout << str;
        if (clear_right) std::cout << "          "; // 10 spaces buffer
        SetConsoleTextAttribute(screen_buffer, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); // resetting to gray colour
    }

    COORD get_cursor_position() {
        CONSOLE_SCREEN_BUFFER_INFO buff_info;

        if (GetConsoleScreenBufferInfo(screen_buffer, &buff_info)) return buff_info.dwCursorPosition;
        else return { 0, 0 }; // returns invalid coords
    }

    void set_cursor_position(COORD coords) {
        SetConsoleCursorPosition(screen_buffer, coords);
    }
};

#endif