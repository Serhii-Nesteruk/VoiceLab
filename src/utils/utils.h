#pragma once

#include <filesystem>
#include <vector>

namespace utils
{
    namespace fs = std::filesystem;
    using ListOfPaths = std::vector<fs::path>;

    [[nodiscard]] ListOfPaths getFilesWithExtension(const fs::path& root, const std::string& extension);

    [[nodiscard]] std::string toLowercase(const std::string& str);
}
