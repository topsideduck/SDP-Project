//
// Created by Harikeshav R on 11/30/24.
//

#include "src/menu/music_picker_menu.h"

#include <string>
#include <tuple>

#include "src/lib/FEHImages.h"      // For handling images with FEHImage class
#include "src/menu/menus.h"
#include "src/util/constants.h"     // For constants like file paths and button coordinates
#include "src/util/input.h"         // For touchscreen input handling


namespace game
{
    MusicPickerMenu::MusicPickerMenu() = default;

    MusicPickerMenu::~MusicPickerMenu() = default;

    void MusicPickerMenu::draw_music_picker_menu()
    {
        LCD.Clear();

        FEHImage music_picker_menu_image{MUSIC_PICKER_MENU_IMAGE_FILE_PATH};
        music_picker_menu_image.Draw(0, 0);

        LCD.Update();
    }

    std::tuple<Menus, std::string, std::string> MusicPickerMenu::handle_music_picker_menu_input()
    {
        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            if (x_coordinate >= MUSIC_PICKER_MENU_TAILOR_SWIF_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_TAILOR_SWIF_X_COORDINATE + MUSIC_PICKER_MENU_TAILOR_SWIF_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_TAILOR_SWIF_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_TAILOR_SWIF_Y_COORDINATE + MUSIC_PICKER_MENU_TAILOR_SWIF_Y_SIZE)
            {
                return {Menus::PlayGameMenu, MUSIC_TAILOR_SWIF_AUDIO_FILE_PATH, MUSIC_TAILOR_SWIF_INFO_FILE_PATH};
            }

            if (x_coordinate >= MUSIC_PICKER_MENU_SICKO_MODE_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_SICKO_MODE_X_COORDINATE + MUSIC_PICKER_MENU_SICKO_MODE_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_SICKO_MODE_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_SICKO_MODE_Y_COORDINATE + MUSIC_PICKER_MENU_SICKO_MODE_Y_SIZE)
            {
                return {Menus::PlayGameMenu, MUSIC_SICKO_MODE_AUDIO_FILE_PATH, MUSIC_SICKO_MODE_INFO_FILE_PATH};
            }

            if (x_coordinate >= MUSIC_PICKER_MENU_CINDERELLA_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_CINDERELLA_X_COORDINATE + MUSIC_PICKER_MENU_CINDERELLA_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_CINDERELLA_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_CINDERELLA_Y_COORDINATE + MUSIC_PICKER_MENU_CINDERELLA_Y_SIZE)
            {
                return {Menus::PlayGameMenu, MUSIC_CINDERELLA_AUDIO_FILE_PATH, MUSIC_CINDERELLA_INFO_FILE_PATH};
            }

            if (x_coordinate >= MUSIC_PICKER_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_BACK_BUTTON_X_COORDINATE + MUSIC_PICKER_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_BACK_BUTTON_Y_COORDINATE + MUSIC_PICKER_MENU_BACK_BUTTON_Y_SIZE)
            {
                return {Menus::MainMenu, "", ""};
            }
        }
    }
} // game
