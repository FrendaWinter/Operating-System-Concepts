#include <iostream>
#include <chrono>
#include <thread>
#include "stdint.h"
#include "raylib.h"

#include "chip8.h"

using namespace std;

// Keypad keymap (CHIP-8 keys mapped to raylib keys)
uint8_t keymap[16] = {
    KEY_X, KEY_ONE, KEY_TWO, KEY_THREE,
    KEY_Q, KEY_W, KEY_E, KEY_A,
    KEY_S, KEY_D, KEY_Z, KEY_C,
    KEY_FOUR, KEY_R, KEY_F, KEY_V
};

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 512;
const int CHIP8_WIDTH = 64;
const int CHIP8_HEIGHT = 32;
const int SCALE = SCREEN_WIDTH / CHIP8_WIDTH;

int main(int argc, char **argv) {

    // Command usage
    if (argc != 2) {
        cout << "Usage: chip8 <ROM file>" << endl;
        return 1;
    }

    Chip8 chip8 = Chip8();  // Initialize CHIP-8

    // Initialize raylib window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CHIP-8 Emulator");
    SetTargetFPS(60);

load:
    // Load ROM
    if (!chip8.load(argv[1])) return 2;

    // Emulation loop
    while (!WindowShouldClose()) {

        chip8.emulate_cycle();

        // Handle input
        for (int i = 0; i < 16; ++i) {
            chip8.key[i] = IsKeyDown(keymap[i]) ? 1 : 0;
        }

        if (IsKeyPressed(KEY_ESCAPE)) {
            break;  // Exit on ESC key
        }

        if (IsKeyPressed(KEY_F1)) {
            goto load;  // Reload ROM (using goto as in original)
        }

        // Draw frame if needed
        if (chip8.drawFlag) {
            chip8.drawFlag = false;

            BeginDrawing();
            ClearBackground(BLACK);

            for (int y = 0; y < CHIP8_HEIGHT; ++y) {
                for (int x = 0; x < CHIP8_WIDTH; ++x) {
                    if (chip8.gfx[y * CHIP8_WIDTH + x]) {
                        cout << "x, y: " << x << ", " << y << "; Scale: " << SCALE << endl; 
                        DrawRectangle(x * SCALE, y * SCALE, SCALE, SCALE, WHITE);
                    }
                }
            }

            EndDrawing();
        }

        // Sleep to control emulation speed
        std::this_thread::sleep_for(std::chrono::microseconds(1200));
    }

    CloseWindow();  // Close raylib window
    return 0;
}
