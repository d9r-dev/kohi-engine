#include <core/logger.h>
#include <core/asserts.h>

// TODO: Test
#include <platform/platform.h>

int main()
{
    KERROR("Test");
    KINFO("Test");
    platform_state state;
    if (platform_startup(&state, "Engine Testbed", 100, 100, 1200, 720))
    {
        while (TRUE)
        {
            platform_pump_messages(&state);
        }
    }

    platform_shutdown(&state);

    return 0;
}