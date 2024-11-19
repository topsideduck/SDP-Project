#include "src/lib/FEHLCD.h"
#include "src/menu/main_menu.h"

[[noreturn]] int main()
{
    // LCD.WriteLine("Hello World!");
    game::MainMenu::draw_main_menu();
    while (true)
    {
        LCD.Update();
        // Never end
    }
}
