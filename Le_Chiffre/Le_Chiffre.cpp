#include <Windows.h>
#include <iostream>
#include <ctime>
#include <thread>
#include "memory.hpp"
#include "signatures.hpp"
#include "client.hpp"
#include "hacks.hpp"
#include "antiAC.hpp"
#include "misc/console_io.hpp"
#include "misc/utils.hpp"
#include "misc/config.hpp"
#include "misc/xor.hpp"
#include "i18n/i18n.hpp"
// #include "sig_scanner.hpp"
// #include <cstddef>
// #include "overlay/overlay.hpp"

using std::cout;
using std::endl;
using namespace i18n;

void language_switcher(ConsoleIO* io, hacks_coords* coords, Internalisation* i, hacks_state* state) {
    while (true) { // Language - F1
        if (GetAsyncKeyState(VK_F1)) {
            i->switch_language();
            io->initial_output(coords, i, state);
            Sleep(250);
        }
        Sleep(5);
    }
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand((unsigned int)time(NULL));
    ConsoleIO io;
    AntiAC ac;
    Memory mem;
    Client client(&mem);
    Hacks hacks(&mem, &client);
    Internalisation i;
    hacks_coords coords;
    hacks_state state;
    int connect_count = 0;

    i.switch_language(get_user_localisation());
    io.initial_output(&coords, &i, &state);

    std::thread language_thread(language_switcher, &io, &coords, &i, &state);
    language_thread.detach();

    // Overlay ol(&mem);
    // ol.static_start(&ol);
    // HANDLE overlay = CreateThread(NULL, NULL, &ol.static_start, (void*)&ol, NULL, NULL);
    // std::thread t(ol.start);

    while (true) {
        while (mem.tProcess != NULL && mem.clientBaseAddr != NULL && mem.engineBaseAddr != NULL) {
            if (!state.process) {
                state.process = true;
                io.set_cursor_position(coords.process);
                io.write_str(i.translate(XorStr("yes")), FOREGROUND_GREEN);
            }

            while (client.in_game()) {
                if (!state.game) {
                    state.game = true;
                    io.set_cursor_position(coords.game);
                    io.write_str(i.translate(XorStr("yes")), FOREGROUND_GREEN);
                    client.update_gamemode();
                    hacks.init();
                }

                { // Language - F1
                    bool f1 = GetAsyncKeyState(VK_F1);

                    if (f1) {
                        i.switch_language();

                    }
                }

                { // Trigger bot - LAlt, F6
                    bool f6 = GetKeyState(VK_F6) & 0x0001;
                    bool lalt = GetAsyncKeyState(VK_LMENU);
                    bool l_mouse = GetAsyncKeyState(VK_LBUTTON);

                    if (f6 != state.activate_trigger) {
                        state.activate_trigger = f6;
                        io.set_cursor_position(coords.activate_trigger);
                        io.write_str(state.activate_trigger ? i.translate(XorStr("on")) : i.translate(XorStr("off")), state.activate_trigger ? FOREGROUND_GREEN : FOREGROUND_RED);
                    }

                    if (state.activate_trigger && lalt && !l_mouse) hacks.trigger_bot(client.is_dangerzone());
                }

                {
                    bool f4 = GetKeyState(VK_F4) & 0x0001; // Aimbot - F4

                    if (f4 != state.aimbot) {
                        state.aimbot = f4;
                        io.set_cursor_position(coords.aimbot);
                        io.write_str(state.aimbot ? i.translate(XorStr("on")) : i.translate(XorStr("off")), state.aimbot ? FOREGROUND_GREEN : FOREGROUND_RED);
                    }

                    if (state.aimbot) hacks.aim_bot();
                    else client.reset_sensitivity();
                }

                { // Glow ESP - F8; Radar hack - F9
                    bool f8 = GetKeyState(VK_F8) & 0x0001; // Enemy glow ESP
                    bool f9 = GetKeyState(VK_F9) & 0x0001; // Radar hack

                    if (f8 != state.enemy_wh) {
                        state.enemy_wh = f8;
                        io.set_cursor_position(coords.enemy_wh);
                        io.write_str(state.enemy_wh ? i.translate(XorStr("on")) : i.translate(XorStr("off")), state.enemy_wh ? FOREGROUND_GREEN : FOREGROUND_RED);
                    }

                    if (f9 != state.radar_hack) {
                        state.radar_hack = f9;
                        io.set_cursor_position(coords.radar_hack);
                        io.write_str(state.radar_hack ? i.translate(XorStr("on")) : i.translate(XorStr("off")), state.radar_hack ? FOREGROUND_GREEN : FOREGROUND_RED);
                    }

                    if (state.enemy_wh || state.radar_hack) 
                        hacks.glow_esp_radar(state.enemy_wh, state.radar_hack, client.is_dangerzone());
                }

                {
                    bool f3 = GetKeyState(VK_F3) & 0x0001; // No flash - F3

                    if (f3 != state.no_flash) {
                        state.no_flash = f3;
                        io.set_cursor_position(coords.no_flash);
                        io.write_str(state.no_flash ? i.translate(XorStr("on")) : i.translate(XorStr("off")), state.no_flash ? FOREGROUND_GREEN : FOREGROUND_RED);
                    }

                    if (state.no_flash) hacks.no_flash();
                }

                {
                    bool f2 = GetKeyState(VK_F2) & 0x0001; // Bunny hop - F2
                    bool space = GetAsyncKeyState(VK_SPACE);

                    if (f2 != state.bunny_hop) {
                        state.bunny_hop = f2;
                        io.set_cursor_position(coords.bunny_hop);
                        io.write_str(f2 ? i.translate(XorStr("on")) : i.translate(XorStr("off")), f2 ? FOREGROUND_GREEN : FOREGROUND_RED);
                    }

                    if (state.bunny_hop && space) hacks.bunny_hop();
                }
                
                // SendMessage(ol.hwnd, WM_PAINT, NULL, NULL);
                hacks.panic_mode(); // closes cheat if triggered
                Sleep(2);
            }

            state.game = false;
            hacks.bsp_setted = false;
            io.set_cursor_position(coords.game);
            io.write_str(i.translate(XorStr("waiting")), FOREGROUND_GREEN | FOREGROUND_RED);
            Sleep(5000);
        }

        state.process = false;
        io.set_cursor_position(coords.process);
        io.write_str(i.translate(XorStr("connecting")), FOREGROUND_GREEN | FOREGROUND_RED);
        ++connect_count;
        Sleep(5000);
        if (connect_count >= 2) {
            connect_count = 0;
            mem.~Memory();
            client.~Client();
            hacks.~Hacks();
            // ol.~Overlay();

            new(&mem) Memory();
            new(&client) Client(&mem);
            new(&hacks) Hacks(&mem, &client);
            // new(&ol) Overlay(&mem);

            // SendMessage(ol.hwnd, WM_DESTROY, NULL, NULL);
            // TerminateThread(overlay, EXIT_SUCCESS);
            // CloseHandle(overlay);
            // overlay = CreateThread(NULL, NULL, &ol.static_start, (void*)&ol, NULL, NULL);
        }
    }

    return EXIT_SUCCESS;
}