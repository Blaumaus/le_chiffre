#ifndef CONSOLEIO_HPP
#define CONSOLEIO_HPP
#pragma once

#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include "../i18n/i18n.hpp"
#include "config.hpp"
#include "utils.hpp"
#include <thread>

using std::wcout;
using std::wcout;
using std::endl;
using namespace i18n;

class ConsoleIO {
private:
    HWND console_window;
    HANDLE screen_buffer;
    const short screen_width = 62;
    const short screen_height = 20;
    FILE* fp;
    // {defined, {error, latest}}; todo: use std::optional
    std::pair<bool, std::pair<bool, bool>> latest;

    // adjusts window to desired width and height
    void _set_window() { // https://stackoverflow.com/a/40634467
        COORD const size = { screen_width, screen_height };

        SMALL_RECT const minimal_window = { 0, 0, 1, 1 }; // to get rid of scroll bars
        SetConsoleWindowInfo(screen_buffer, TRUE, &minimal_window);

        SMALL_RECT const window = { 0, 0, size.X - 1, size.Y - 1 };
        SetConsoleWindowInfo(screen_buffer, TRUE, &window);

        SetConsoleScreenBufferSize(screen_buffer, size);
    }

    void _set_cursor() {
        _CONSOLE_CURSOR_INFO const cursor_info = { 100, false };
        SetConsoleCursorInfo(screen_buffer, &cursor_info);
    }

    void print_version_status(Internalisation* i, COORD coords) {
        if (!latest.first) {
            latest = std::make_pair(true, is_latest());
        }

        set_cursor_position(coords);
        if (latest.second.first) write_str(i->translate(XorStr("error")), FOREGROUND_RED);
        else if (latest.second.second) write_str(i->translate(XorStr("latest")), FOREGROUND_GREEN);
        else write_str(i->translate(XorStr("outdated")), FOREGROUND_GREEN | FOREGROUND_RED);
    }

    void clear() {
        COORD topLeft = { 0, 0 };
        DWORD written;

        FillConsoleOutputCharacterA(screen_buffer, ' ', screen_width * screen_height, topLeft, &written);
        FillConsoleOutputAttribute(
            screen_buffer, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen_width * screen_height, topLeft, &written
            );
        _set_cursor();
        SetConsoleCursorPosition(screen_buffer, topLeft);
    }

    std::wstring stringToWstring(std::string str) {
        std::wstring wstr(str.begin(), str.end());
        return wstr;
    }

public:
    ConsoleIO() {
        AllocConsole();
        screen_buffer = GetStdHandle(STD_OUTPUT_HANDLE);
        console_window = GetConsoleWindow();

        SetWindowLong(console_window, GWL_STYLE, GetWindowLong(console_window, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        _set_window();
        _set_cursor();
        freopen_s(&fp, "CONOUT$", "w", stdout);
        _setmode(_fileno(fp), _O_U8TEXT);
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        latest = std::make_pair(false, std::make_pair(false, false));
    }

    ~ConsoleIO() {
        fclose(fp);
    }

    void write_str(std::wstring str, WORD colour, bool clear_right = true) {
        SetConsoleTextAttribute(screen_buffer, colour);
        std::wcout << str;
        if (clear_right) std::wcout << "          "; // 10 spaces buffer
        SetConsoleTextAttribute(screen_buffer, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); // resetting to gray colour
    }

    void write_str(std::string str, WORD colour, bool clear_right = true) {
        write_str(stringToWstring(str), colour, clear_right);
    }

    COORD get_cursor_position() {
        CONSOLE_SCREEN_BUFFER_INFO buff_info;

        if (GetConsoleScreenBufferInfo(screen_buffer, &buff_info)) return buff_info.dwCursorPosition;
        else return { 0, 0 }; // returns invalid coords
    }

    void set_cursor_position(COORD coords) {
        SetConsoleCursorPosition(screen_buffer, coords);
    }

    void initial_output(hacks_coords* coords, Internalisation* i, hacks_state* state) {
        clear();

        char* nl = XorStr("\n  ");
        char* cl = XorStr(": ");
        wstring on = i->translate(XorStr("on"));
        wstring off = i->translate(XorStr("off"));
        wstring yes = i->translate(XorStr("yes"));
        wstring no = i->translate(XorStr("no"));

        wcout << XorStr("Le Chiffre ") << stringToWstring(CHEAT_VERSION) << XorStr(" [6 Mar, 2021]") << endl << endl;
        wcout << i->translate(XorStr("website")) << endl << endl;

        wcout << i->translate(XorStr("state")) << cl;
        wcout << nl << i->translate(XorStr("language")) << cl;
        coords->language = get_cursor_position();
        write_str(i->get_lang(), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

        wcout << nl << i->translate(XorStr("connected_csgo")) << cl;
        coords->process = get_cursor_position();
        write_str(state->process ? yes : no, state->process ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("connected_game")) << cl;
        coords->game = get_cursor_position();
        write_str(state->game ? yes : no, state->game ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("version")) << cl;
        coords->version = get_cursor_position();
        write_str(i->translate(XorStr("loading")), FOREGROUND_GREEN | FOREGROUND_RED);

        std::thread print_ver(&ConsoleIO::print_version_status, this, i, coords->version);
        print_ver.detach();

        Sleep(1); // needed because otherwise on rerendering the 'cheat_functions' string will overlap with cheat status because of async code
        wcout << XorStr("\n\n") << i->translate(XorStr("cheat_functions")) << cl;
        wcout << nl << i->translate(XorStr("bunny_hop")) << cl;
        coords->bunny_hop = get_cursor_position();
        write_str(state->bunny_hop ? yes : no, state->bunny_hop ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("no_flash")) << cl;
        coords->no_flash = get_cursor_position();
        write_str(state->no_flash ? yes : no, state->no_flash ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("aimbot")) << cl;
        coords->aimbot = get_cursor_position();
        write_str(state->aimbot ? yes : no, state->aimbot ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("triggerbot")) << cl;
        coords->activate_trigger = get_cursor_position();
        write_str(state->activate_trigger ? yes : no, state->activate_trigger ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("use_triggerbot")) << cl;
        coords->use_trigger = get_cursor_position();
        write_str(i->translate(XorStr("hold")), FOREGROUND_GREEN | FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("glowesp")) << cl;
        coords->enemy_wh = get_cursor_position();
        write_str(state->enemy_wh ? yes : no, state->enemy_wh ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("radar_hack")) << cl;
        coords->radar_hack = get_cursor_position();
        write_str(state->radar_hack ? yes : no, state->radar_hack ? FOREGROUND_GREEN : FOREGROUND_RED);

        wcout << nl << i->translate(XorStr("exit")) << cl;
        write_str(i->translate(XorStr("press")), FOREGROUND_GREEN | FOREGROUND_RED);
    }
};
#endif