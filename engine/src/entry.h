#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

// Externally defined function to create a game.
extern b8 create_game(game *out_game);

/**
 * The main entry point for the application.
 */
int main()
{
    // Request the game instance from the application.
    game game_inst;
    if (!create_game(&game_inst))
    {
        KFATAL("Failed to create game instance.");
        return -1;
    }

    // Ensure the function pointers exist.
    if (!game_inst.initialize ||
        !game_inst.update ||
        !game_inst.render ||
        !game_inst.on_resize)
    {
        KFATAL("Game instance missing function pointers.");
        return -2;
    }

    // Initialization
    if (!application_create(&game_inst))
    {
        KFATAL("Failed to create application.");
        return 1;
    }

    // Begin game loop.
    if (!application_run())
    {
        KFATAL("Application did not run gracefully.");
        return 2;
    }

    return 0;
}