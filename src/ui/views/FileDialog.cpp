#include "FileDialog.h"

#include "AppState.h"
#include "EnrolmentView.h"
#include "ImGuiFileDialog.h"

void FileDialog::initFileDialog(const FileDialogId& id)
{
    _selectedFiles.try_emplace(id, FilePath());
}

void FileDialog::renderFileDialog(const FileDialogId& id)
{
    if (!AppState::openFileDialog) return;

    IGFD::FileDialogConfig config;
    config.path = ".";

    ImGuiFileDialog::Instance()->OpenDialog(
        id,
        "Wybierz plik",
        ".lvf,.wav,.bin",
        config
    );

    if (ImGuiFileDialog::Instance()->Display(id))
    {
        if (ImGuiFileDialog::Instance()->IsOk())
        {
            _selectedFiles.insert_or_assign(id,ImGuiFileDialog::Instance()->GetFilePathName());
        }

        ImGuiFileDialog::Instance()->Close();
        AppState::openFileDialog = false;
    }
}

FileDialog::FilePath FileDialog::getSelectedFileByDialogId(const FileDialogId& id)
{
    auto it = _selectedFiles.find(id);
    return (it != _selectedFiles.end()) ? it->second : FilePath{};
}

const FileDialog::SelectedFilesMap& FileDialog::getSelectedFiles()
{
    return _selectedFiles;
}
