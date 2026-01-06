#pragma once
#include "views/FileDialog.h"

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

    // File Dialog
    inline static bool openFileDialog = false;
    inline static std::string currentFileDialogId{};
};