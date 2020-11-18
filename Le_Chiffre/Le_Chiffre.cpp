#include <Windows.h>
#include <iostream>
#include <ctime>
#include "memory.hpp"
#include "signatures.hpp"
#include "client.hpp"
#include "hacks.hpp"
#include "antiVAC.hpp"
#include "console_io.hpp"

using std::cout;
using std::endl;

struct hacks_coords {
    COORD no_flash, activate_trigger, use_trigger, team_wh, enemy_wh, radar_hack, process, game;
};

struct hacks_state {
    bool no_flash = false;
    bool activate_trigger = false;
    bool use_trigger = false;
    bool team_wh = false;
    bool enemy_wh = false;
    bool radar_hack = false;
};

int main(int argc, char** argv) {
    ConsoleIO io;

    AntiVAC ac;
    ac.erase_pe_headers();
    srand((unsigned int)time(NULL));

    Memory mem;
    Client client(&mem);
    Hacks hacks(&mem, &client);

    hacks_coords coords;
    hacks_state state;
  
    bool pHandle = false, game = false;
    int connect_count = 0;

    cout << "Le Chiffre hacks v0.03 [18 Nov, 2020]" << endl << endl;
    cout << "There are still a lot of things to do, including advanced protection against VAC,\n  code optimisation, etc." << endl;
    cout << "To minimise the risks of getting banned I recommend you at least change the name of\n  the .exe file of this cheat, as well as its MD5 hash, before you use it in the game." << endl;
    cout << "In case of any bugs and glitches, feel free to notify me about them." << endl << endl;

    cout << "You can support my work by donating me a bit:\n  https://donationalerts.com/r/fuckblm" << endl << endl;

    // TODO: Refactor
    cout << "State:";
    cout << "\n  Connected to CS:GO process: ";
    coords.process = io.get_cursor_position();
    io.write_str("NO", FOREGROUND_RED);

    cout << "\n  Connected to active game: ";
    coords.game = io.get_cursor_position();
    io.write_str("NO", FOREGROUND_RED);

    cout << "\n\nCheat functions:";
    cout << "\n  No flashbang (F3): ";
    coords.no_flash = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Activate trigger bot (F6): ";
    coords.activate_trigger = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Use trigger bot (LAlt): ";
    coords.use_trigger = io.get_cursor_position();
    io.write_str("HOLD", FOREGROUND_GREEN | FOREGROUND_RED, true);

    cout << "\n  Teammate glow ESP (F7): ";
    coords.team_wh = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Enemy glow ESP (F8): ";
    coords.enemy_wh = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    cout << "\n  Radar hack (F9): ";
    coords.radar_hack = io.get_cursor_position();
    io.write_str("OFF", FOREGROUND_RED);

    while (true) {
        while (mem.tProcess != NULL && mem.clientBaseAddr != NULL && mem.engineBaseAddr != NULL) {
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
                }

                // hacks.test_hacks();

                { // Trigger bot - LAlt, F6
                    bool f6 = GetKeyState(VK_F6) & 1;
                    bool lalt = GetAsyncKeyState(VK_LMENU);

                    if (f6 != state.activate_trigger ) {
                        state.activate_trigger = f6;
                        io.set_cursor_position(coords.activate_trigger);
                        io.write_str(f6 ? "ON" : "OFF", f6 ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (state.activate_trigger && lalt) hacks.trigger_bot(client.is_dangerzone());
                }

                { // Glow ESP - F7, F8; Radar hack - F9
                    bool f7 = GetKeyState(VK_F7) & 1; // Teammate glow ESP
                    bool f8 = GetKeyState(VK_F8) & 1; // Enemy glow ESP
                    bool f9 = GetKeyState(VK_F9) & 1; // Radar hack

                    if (f7 != state.team_wh) {
                        state.team_wh = f7;
                        io.set_cursor_position(coords.team_wh);
                        io.write_str(f7 ? "ON" : "OFF", f7 ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (f8 != state.enemy_wh) {
                        state.enemy_wh = f8;
                        io.set_cursor_position(coords.enemy_wh);
                        io.write_str(f8 ? "ON" : "OFF", f8 ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (f9 != state.radar_hack) {
                        state.radar_hack = f9;
                        io.set_cursor_position(coords.radar_hack);
                        io.write_str(f9 ? "ON" : "OFF", f9 ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (state.team_wh || state.enemy_wh || state.radar_hack) hacks.glow_esp_radar(f7, f8, f9, client.is_dangerzone());
                }

                {
                    bool f3 = GetKeyState(VK_F3) & 1; // No flash - F3

                    if (f3 != state.no_flash) {
                        state.no_flash = f3;
                        io.set_cursor_position(coords.no_flash);
                        io.write_str(f3 ? "ON" : "OFF", f3 ? FOREGROUND_GREEN : FOREGROUND_RED, true);
                    }

                    if (state.no_flash) hacks.no_flash();
                }
                Sleep(2);
            }

            game = false;
            io.set_cursor_position(coords.game);
            io.write_str("WAITING", FOREGROUND_GREEN | FOREGROUND_RED, true);
            Sleep(5000);
        }

        pHandle = false;
        io.set_cursor_position(coords.process);
        io.write_str("CONNECTING", FOREGROUND_GREEN | FOREGROUND_RED, true);
        ++connect_count;
        Sleep(10000);
        if (connect_count >= 2) {
            connect_count = 0;
            mem.~Memory();
            client.~Client();
            hacks.~Hacks();

            new(&mem) Memory();
            new(&client) Client(&mem);
            new(&hacks) Hacks(&mem, &client);
        }
    }

    return EXIT_SUCCESS;
}