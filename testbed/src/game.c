#include "game.h"

#include <core/logger.h>

b8 game_initialize(game *game_inst)
{
    KDEBUG("Initializing game.");
    return TRUE;
}

b8 game_update(game *game_inst, f32 delta_time)
{
    KDEBUG("Updating game.");
    return TRUE;
}

b8 game_render(game *game_inst, f32 delta_time)
{
    KDEBUG("Rendering game.");
    return TRUE;
}

void game_on_resize(game *game_inst, i32 width, i32 height)
{
    KDEBUG("Resizing game.");
}