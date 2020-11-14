#include <Windows.h>
#include <iostream>
#include <ctime>
#include "memory.hpp"
#include "signatures.hpp"
#include "client.hpp"
#include "hacks.hpp"
#include "antiVAC.hpp"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    AntiVAC ac;
    ac.erase_pe_headers();
    srand((unsigned int)time(NULL));

    Memory mem;
    Client client(&mem);
    Hacks hacks(&mem, &client);

    // TODO: Refactor
    bool pHandle = false, game = false;
    int connect_count = 0;

    cout << "Le Chiffre hacks v0.02 [14 Nov, 2020]" << endl << endl;
    cout << "Work on this cheat is in progress." << endl;
    cout << "There are still a lot of things to do, including advanced protection against VAC,\n  code optimisation, bug fixes and much more." << endl;
    cout << "To minimize the risks of getting banned I recommend you at least change the name of\n  the .exe file of this cheat, as well as its MD5 hash, before you use it in the game." << endl;
    cout << "In case of any bugs and glitches, feel free to notify me about them." << endl << endl;

    cout << "You can support my work by donating a bit:\n  https://www.patreon.com/ahouse" << endl << endl;

    cout << "Cheat functions:\n  F6 - Activate trigger bot\n  LAlt - Use trigger bot\n  F7 - Teammate glow ESP\n  F8 - Enemy glow ESP\n  F9 - Radar hack\n  F10 - No flashbang" << endl << endl;

    while (true) {
        while (mem.tProcess != NULL && mem.clientBaseAddr != NULL && mem.engineBaseAddr != NULL) {
            if (!pHandle) {
                pHandle = true;
                cout << "[OK] Connected to CS:GO process!" << endl;
            }

            while (client.in_game()) {
                if (!game) {
                    game = true;
                    cout << "[OK] Connected to active game!" << endl;
                }

                { // Trigger bot - LAlt, F6
                    bool f6 = GetKeyState(VK_F6) & 1;
                    bool lalt = GetAsyncKeyState(VK_LMENU);
                    if (f6 && lalt) hacks.trigger_bot();
                }

                { // Glow ESP - F7, F8; Radar hack - F9
                    bool f7 = GetKeyState(VK_F7) & 1; // Teammate glow ESP
                    bool f8 = GetKeyState(VK_F8) & 1; // Enemy glow ESP
                    bool f9 = GetKeyState(VK_F9) & 1; // Radar hack
                    if (f7 || f8 || f9) hacks.glow_esp_radar(f7, f8, f9);
                }
               
                if(GetKeyState(VK_F10) & 1) hacks.no_flash(); // No flash - F10
                Sleep(2);
            }

            game = false;
            cout << "Not in active game, waiting 5s..." << endl;
            Sleep(5000);
        }

        pHandle = false;
        cout << "Not connected to CS:GO process, waiting 10s..." << endl;
        ++connect_count;
        Sleep(10000);
        if (connect_count >= 2) {
            cout << "Trying to get a new handle to CS:GO proccess..." << endl;
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