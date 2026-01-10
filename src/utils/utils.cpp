#include "utils.h"

#include <algorithm>

utils::ListOfPaths utils::getFilesWithExtension(const fs::path& root, const std::string& extension)
{
    if (!fs::exists(root) || !fs::is_directory(root))
    {
        throw std::runtime_error("Invalid directory: " + root.string());
    }

    ListOfPaths paths;
    for (const auto& entry : fs::recursive_directory_iterator(root, fs::directory_options::skip_permission_denied))
    {
        if (!entry.is_regular_file()) continue;

        const fs::path& path = entry.path();
        const auto lowercaseExtension = toLowercase(extension);
        if (path.extension() == lowercaseExtension)
        {
            paths.push_back(path);
        }
    }

    std::sort(paths.begin(), paths.end());
    return paths;
}

std::string utils::toLowercase(const std::string& str)
{
    std::string temp = str;
    std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c)
    {
        return std::tolower(c);
    });
    return temp;
}
