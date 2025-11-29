#pragma once

enum class ViewId
{
    Main,
    Enrolment,
    Verification
};

struct AppState
{
    inline static ViewId currentView = ViewId::Main;
    inline static bool isRunning = true;
};