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

    std::thread trigger_bot_thread(&Hacks::thread_trigger_bot, &hacks, &state, &coords, &io, &i);
    std::thread aimbot_thread(&Hacks::thread_aimbot, &hacks, &state, &coords, &io, &i);
    std::thread glow_radar_thread(&Hacks::thread_glow_radar, &hacks, &state, &coords, &io, &i);
    std::thread no_flash_thread(&Hacks::thread_no_flash, &hacks, &state, &coords, &io, &i);
    std::thread bunny_hop_thread(&Hacks::thread_bunny_hop, &hacks, &state, &coords, &io, &i);
    std::thread panic_mode_thread(&Hacks::thread_panic_mode, &hacks);

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
                
                // SendMessage(ol.hwnd, WM_PAINT, NULL, NULL);
                Sleep(500);
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