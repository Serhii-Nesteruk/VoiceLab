#pragma once

#include "../utils/utils.h"

#include "libvoicefeat/config.h"

class FeatureExtractionService
{
public:
    explicit FeatureExtractionService(const std::filesystem::path& path);


private:
    utils::ListOfPaths _wavFiles{}, _lvfFiles;
    libvoicefeat::CepstralConfig _config{};

};
