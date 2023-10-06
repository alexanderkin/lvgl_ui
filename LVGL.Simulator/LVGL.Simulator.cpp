/*
 * PROJECT:   LVGL PC Simulator using Visual Studio
 * FILE:      LVGL.Simulator.cpp
 * PURPOSE:   Implementation for LVGL ported to Windows Desktop
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#include <Windows.h>

#include "resource.h"

#include "../Application/Application.h"

#if _MSC_VER >= 1200
 // Disable compilation warnings.
#pragma warning(push)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable:4244)
#endif

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/win32drv/win32drv.h"

#if _MSC_VER >= 1200
// Restore compilation warnings.
#pragma warning(pop)
#endif

#include <stdio.h>

bool single_display_mode_initialization()
{
    if (!lv_win32_init(
        GetModuleHandleW(NULL),
        SW_SHOW,
        800,
        800,
        LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL))))
    {
        return false;
    }

    lv_win32_add_all_input_devices_to_group(NULL);

    return true;
}

int main()
{
    uint64_t count = 0;
    lv_init();

    if (!single_display_mode_initialization())
    {
        return -1;
    }

    initMainApplication();
    // lv_demo_widgets();           // ok

    while (!lv_win32_quit_signal)
    {
        lv_task_handler();
        if (count == 643) {
            count = 0;
            saveTables();
        }
        Sleep(1);
        count++;
    }

    return 0;
}
