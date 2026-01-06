#pragma once
#include <string>
#include <unordered_map>

class FileDialog
{
    using FileDialogId = std::string;
    using FilePath = std::string;
    using SelectedFilesMap = std::unordered_map<FileDialogId, FilePath>;
public:
    static void initFileDialog(const FileDialogId& id);
    static void renderFileDialog(const FileDialogId& id);

    [[nodiscard]] static FilePath getSelectedFileByDialogId(const FileDialogId& id);
    [[nodiscard]] static const SelectedFilesMap&  getSelectedFiles();

private:
    inline static SelectedFilesMap _selectedFiles{};
};
