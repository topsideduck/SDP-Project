#ifndef QUIT_MENU_H
#define QUIT_MENU_H
#include "src/menu/menus.h"

namespace game
{
    /**
     * @class QuitMenu
     * @brief Manages the quit menu interface and functionality.
     *
     * The QuitMenu class handles rendering the quit menu, processing user input,
     * and performing actions such as quitting the game or returning to the main menu.
     */
    class QuitMenu
    {
    public:
        /**
         * @brief Constructs a QuitMenu instance.
         */
        QuitMenu();

        /**
         * @brief Destructor for the QuitMenu class.
         */
        ~QuitMenu();

        /**
         * @brief Draws the quit menu screen.
         *
         * Renders the quit menu interface, preparing it for user interaction.
         */
        static void draw_quit_menu();

        /**
         * @brief Handles user input for the quit menu.
         *
         * Waits for user interaction and determines whether to quit the game
         * or return to the main menu.
         *
         * @return Menus::MainMenu if the user selects "Stay."
         */
        static Menus handle_quit_menu_input();

        /**
         * @brief Exits the game.
         *
         * Called when the user selects the "Quit" option to terminate the program.
         */
        static void quit_game();
    };
} // namespace game

#endif // QUIT_MENU_H
