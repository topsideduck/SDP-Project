#ifndef MENUS_H
#define MENUS_H

/**
 * @enum Menus
 * @brief Represents the various menu states in the game.
 *
 * This enumeration is used to identify and transition between different
 * menus in the game, such as the main menu, controls menu, and others.
 */
enum Menus
{
    ControlsMenu, /**< Represents the controls menu. */
    CreditsMenu, /**< Represents the credits menu. */
    InstructionsMenu, /**< Represents the instructions menu. */
    MainMenu, /**< Represents the main menu. */
    MusicPickerMenu, /**< Represents the music picker menu. */
    PlayGameMenu, /**< Represents the play game menu. */
    QuitMenu, /**< Represents the quit menu. */
    ScoreMenu, /**< Represents the score menu. */
    StatisticsMenu /**< Represents the statistics menu. */
};

#endif // MENUS_H
