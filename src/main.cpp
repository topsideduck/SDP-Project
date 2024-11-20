#include <iostream>

#include "src/lib/FEHLCD.h"
#include "src/menu/main_menu.h"
#include "src/lib/tigr.h"


[[noreturn]] int main()
{
    game::MainMenu::draw_main_menu();
    // while (true)
    // {
    //     // Read the keyboard and move the player.
    //     // if (tigrKeyDown(LCD.screen, TK_SPACE))
    //     //     std::cout << "space" << std::endl;
    //     // // if (tigrKeyHeld(screen, TK_LEFT) || tigrKeyHeld(screen, 'A'))
    //     // //     playerxs -= 10;
    //     // // if (tigrKeyHeld(screen, TK_RIGHT) || tigrKeyHeld(screen, 'D'))
    //     // //     playerxs += 10;
    //     LCD.Update();
    //     // Never end
    // }
}
