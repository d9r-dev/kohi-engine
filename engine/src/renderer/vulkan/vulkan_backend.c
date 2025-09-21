#include "vulkan_backend.h"
#include "core/logger.h"

#include "vulkan_types.inl"

static vulkan_context context;

b8 vulkan_renderer_backend_initialize(renderer_backend *backend, const char *application_name, struct platform_state *plat_state)
{
    // TODO: custom allocator
    context.allocator = 0;

    // Setup Vulkan instance
    VkApplicationInfo app_info = {VK_STRUCTURE_TYPE_APPLICATION_INFO};
    app_info.apiVersion = VK_API_VERSION_1_2;
    app_info.pApplicationName = application_name;
    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.pEngineName = "K Engine";
    app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);

    VkInstanceCreateInfo instance_info = {VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
    instance_info.pApplicationInfo = &app_info;
    instance_info.enabledExtensionCount = 0;
    instance_info.ppEnabledExtensionNames = 0;
    instance_info.enabledLayerCount = 0;
    instance_info.ppEnabledLayerNames = 0;

    VkResult result = vkCreateInstance(&instance_info, context.allocator, &context.instance);
    if (result != VK_SUCCESS)
    {
        KERROR("Failed to create Vulkan instance. Result: %u", result);
        return FALSE;
    }

    KINFO("Vulkan instance created.");
    return TRUE;
}
void vulkan_renderer_backend_shutdown(renderer_backend *backend)
{
}

void vulkan_renderer_backend_on_resize(renderer_backend *backend, u16 width, u16 height)
{
}

b8 vulkan_renderer_backend_begin_frame(renderer_backend *backend, f32 delta_time)
{
    return TRUE;
}
b8 vulkan_renderer_backend_end_frame(renderer_backend *backend, f32 delta_time)
{
    return TRUE;
}