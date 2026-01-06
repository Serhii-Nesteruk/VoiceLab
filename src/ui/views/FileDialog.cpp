#include "FileDialog.h"

#include "AppState.h"

#include "ImGuiFileDialog.h"

void FileDialog::initFileDialog(const FileDialogId& id)
{
    _selectedFiles.try_emplace(id, FilePath());
}

void FileDialog::renderFileDialog(const FileDialogId& id, const Mode& mode)
{
    if (!AppState::openFileDialog) return;

    IGFD::FileDialogConfig config;
    config.path = ".";

    const char* filters = (mode == Mode::File) ? ".lvf,.wav,.bin" : nullptr;

    ImGuiFileDialog::Instance()->OpenDialog(
        id,
        (mode == Mode::File) ? "Wybierz plik" : "Wybierz folder",
        filters,
        config
    );

    if (ImGuiFileDialog::Instance()->Display(id))
    {
        if (ImGuiFileDialog::Instance()->IsOk())
        {
            if (mode == Mode::Directory)
            {
                _selectedFiles.insert_or_assign(
                    id,
                    ImGuiFileDialog::Instance()->GetCurrentPath()
                );
            }
            else
            {
                _selectedFiles.insert_or_assign(
                    id,
                    ImGuiFileDialog::Instance()->GetFilePathName()
                );
            }
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
