#include "FeatureExtractionService.h"

#include <filesystem>

namespace lvf = libvoicefeat;

FeatureExtractionService::FeatureExtractionService(const std::filesystem::path& path)
{
    if (std::filesystem::is_directory(path))
    {
        _wavFiles = utils::getFilesWithExtension(path, ".wav");
        _lvfFiles = utils::getFilesWithExtension(path, ".lvf");
    }

    /* TODO:
     * // load and save features loaded from .lvf files
     * Feature f = FeatureSerdes::load(_lvfFiles)
     * f.getComputedMatrix() // MFCC matrix
     *
     * // compute features from .wav files and save
     * Feature f1 = CepstralExtractor(_config)::extractFromFile(_wavFiles)
     * f1.getComputedMatrix
     *
     * // save all Features
     * FeatureSerdes::save(path, f)
     * FeatureSerdes::save(path, f1)
    */

    _config.type = lvf::CepstralType::MFCC;
    _config.delta.useDeltas = true;
    _config.delta.useDeltaDeltas = true;
}
