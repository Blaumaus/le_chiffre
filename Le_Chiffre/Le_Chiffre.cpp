#include <Windows.h>
#include <iostream>
#include <ctime>
#include "memory.hpp"
#include "signatures.hpp"
#include "client.hpp"
#include "hacks.hpp"
#include "antiAC.hpp"
#include "console_io.hpp"
// #include "overlay/overlay.hpp"

using std::cout;
using std::endl;

struct hacks_coords {
    COORD no_flash, activate_trigger, use_trigger, /*team_wh,*/ enemy_wh, radar_hack, bunny_hop, aimbot, process, game;
};

struct hacks_state {
    bool no_flash = false;
    bool activate_trigger = false;
    bool use_trigger = false;
    // bool team_wh = false;
    bool enemy_wh = false;
    bool radar_hack = false;
    bool bunny_hop = false;
    bool aimbot = false;
};

int main() {
    ConsoleIO io;

    AntiAC ac;
    srand((unsigned int)time(NULL));
    
    Memory mem;
    Client client(&mem);
    Hacks hacks(&mem, &client);
    // Overlay ol(&mem);
    // ol.static_start(&ol);
    // HANDLE overlay = CreateThread(NULL, NULL, &ol.static_start, (void*)&ol, NULL, NULL);
    // std::thread t(ol.start);

    hacks_coords coords;
    hacks_state state;
  
    bool pHandle = false, game = false;
    int connect_count = 0;

    cout << "Le Chiffre v1.03 [12 Jan, 2021]" << endl << endl;
    cout << "My contact: coopertars@protonmail.ch" << endl << endl;
    cout << "Support the developer: https://donationalerts.com/r/fuckblm" << endl << endl;
    cout << "The source code: https://github.com/Blaumaus/le_chiffre" << endl << endl;

    // TODO: Refactor
    cout << "State:";
    cout << "\n  Connected to CS:GO process: ";
    coords.process = io.get_cursor_position();
    io.write_str("NO", FOREGROUND_RED);

    cout << "\n  Connected to active game: ";
    coords.game = io.get_cursor_position();
    io.write_str("NO", FOREGROUND_RED);

    cout << "\n\nCheat functions:";
    cout << "\n  Bunny hop (F2): ";
    coords.bunny_hop = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  No flashbang (F3): ";
    coords.no_flash = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Aimbot (F4): ";
    coords.aimbot = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Activate trigger bot (F6): ";
    coords.activate_trigger = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Use trigger bot (LAlt): ";
    coords.use_trigger = io.get_cursor_position();
    io.write_str("HOLD", FOREGROUND_GREEN | FOREGROUND_RED, true);

    /*cout << "\n  Teammate glow ESP (F7): ";
    coords.team_wh = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);*/

    cout << "\n  Enemy glow ESP (F8): ";
    coords.enemy_wh = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Radar hack (F9): ";
    coords.radar_hack = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Panic mode (END): ";
    io.write_str("PRESS", FOREGROUND_GREEN | FOREGROUND_RED);

    while (true) {
        ac.check_for_debug();

        while (mem.tProcess != NULL && mem.clientBaseAddr != NULL && mem.engineBaseAddr != NULL) {
            ac.check_for_debug();

            if (!pHandle) {
                pHandle = true;
                io.set_cursor_position(coords.process);
                io.write_str("YES", FOREGROUND_GREEN, true);
            }

            while (client.in_game()) {
                if (!game) {
                    game = true;
                    io.set_cursor_position(coords.game);
                    io.write_str("YES", FOREGROUND_GREEN, true);
                    client.update_gamemode();
                    hacks.init();
                }

                { // Trigger bot - LAlt, F6
                    bool f6 = GetKeyState(VK_F6) & 0x0001;
                    bool lalt = GetAsyncKeyState(VK_LMENU);
                    bool l_mouse = GetAsyncKeyState(VK_LBUTTON);

                    if (f6 != state.activate_trigger) {
                        state.activate_trigger = f6;
                        io.set_cursor_position(coords.activate_trigger);
                        io.write_str(state.activate_trigger ? "ON" : "OFF", state.activate_trigger ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (state.activate_trigger && lalt && !l_mouse) hacks.trigger_bot(client.is_dangerzone());
                }

                {
                    bool f4 = GetKeyState(VK_F4) & 0x0001; // Aimbot - F4

                    if (f4 != state.aimbot) {
                        state.aimbot = f4;
                        io.set_cursor_position(coords.aimbot);
                        io.write_str(state.aimbot ? "ON" : "OFF", state.aimbot ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (state.aimbot) hacks.aim_bot();
                    else client.reset_sensitivity();
                }

                { // Glow ESP - F7, F8; Radar hack - F9
                    // bool f7 = GetKeyState(VK_F7) & 1; // Teammate glow ESP
                    bool f8 = GetKeyState(VK_F8) & 0x0001; // Enemy glow ESP
                    bool f9 = GetKeyState(VK_F9) & 0x0001; // Radar hack

                    /*if (f7 != state.team_wh) {
                        state.team_wh = f7;
                        io.set_cursor_position(coords.team_wh);
                        io.write_str(state.team_wh ? "ON" : "OFF", state.team_wh ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }*/

                    if (f8 != state.enemy_wh) {
                        state.enemy_wh = f8;
                        io.set_cursor_position(coords.enemy_wh);
                        io.write_str(state.enemy_wh ? "ON" : "OFF", state.enemy_wh ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (f9 != state.radar_hack) {
                        state.radar_hack = f9;
                        io.set_cursor_position(coords.radar_hack);
                        io.write_str(state.radar_hack ? "ON" : "OFF", state.radar_hack ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (/*state.team_wh || */state.enemy_wh || state.radar_hack) 
                        hacks.glow_esp_radar(false, state.enemy_wh, state.radar_hack, client.is_dangerzone());
                }

                {
                    bool f3 = GetKeyState(VK_F3) & 0x0001; // No flash - F3

                    if (f3 != state.no_flash) {
                        state.no_flash = f3;
                        io.set_cursor_position(coords.no_flash);
                        io.write_str(state.no_flash ? "ON" : "OFF", state.no_flash ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (state.no_flash) hacks.no_flash();
                }

                {
                    bool f2 = GetKeyState(VK_F2) & 0x0001; // Bunny hop - F2
                    bool space = GetAsyncKeyState(VK_SPACE);

                    if (f2 != state.bunny_hop) {
                        state.bunny_hop = f2;
                        io.set_cursor_position(coords.bunny_hop);
                        io.write_str(f2 ? "ON" : "OFF", f2 ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (state.bunny_hop && space) hacks.bunny_hop();
                }
                
                // SendMessage(ol.hwnd, WM_PAINT, NULL, NULL);
                hacks.panic_mode(); // closes cheat if triggered
                Sleep(2);
            }

            game = false;
            hacks.bsp_setted = false;
            io.set_cursor_position(coords.game);
            io.write_str("WAITING", FOREGROUND_GREEN | FOREGROUND_RED, true);
            Sleep(5000);
        }

        pHandle = false;
        io.set_cursor_position(coords.process);
        io.write_str("CONNECTING", FOREGROUND_GREEN | FOREGROUND_RED, true);
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

            // TerminateThread(overlay, EXIT_SUCCESS);
            // CloseHandle(overlay);
        }
    }

    return EXIT_SUCCESS;
}