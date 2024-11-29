//
// Created by Harikeshav R on 11/19/24.
//

#ifndef QUIT_MENU_H
#define QUIT_MENU_H
#include "menus.h"

namespace game
{
 /**
  * @class QuitMenu
  * @brief Handles the quit menu screen and its functionality.
  *
  * This class provides the functionality to display the quit menu, process
  * user input, and either quit the game or navigate back to the main menu.
  */
 class QuitMenu
 {
 public:
  /**
   * @brief Constructor for the QuitMenu class.
   */
  QuitMenu();

  /**
   * @brief Destructor for the QuitMenu class.
   */
  ~QuitMenu();

  /**
   * @brief Displays the quit menu and processes user input.
   *
   * This static method renders the quit menu screen and monitors user
   * interaction to determine whether the user wants to quit the game or
   * return to the main menu.
   */
  static void draw_quit_menu();

  static Menus handle_quit_menu_input();

  /**
   * @brief Exits the game.
   *
   * This static method is called when the user clicks the "Quit" button
   * to exit the game entirely.
   */
  static void quit_game();
 };
} // namespace game

#endif // QUIT_MENU_H
