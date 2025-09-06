#pragma once

#include "core/application.h"

/**
 * Represents the basic game state in a game.
 * Called for creation by the applicaton.
 */
typedef struct game
{
    // The application configuration.
    application_config app_config;

    // Function pointer to a game's initialize function.
    b8 (*initialize)(struct game *game_inst);

    // Function pointer to a game's update function.
    b8 (*update)(struct game *game_inst, f32 delta_time);

    // Function pointer to a game's render function.
    b8 (*render)(struct game *game_inst, f32 delta_time);

    // Function pointer to handle resize, if applicable.
    void (*on_resize)(struct game *game_inst, i32 width, i32 height);

    // Game-specific game state. Created and managed by the game.
    void *state;
} game;
