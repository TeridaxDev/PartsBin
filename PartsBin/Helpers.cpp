#include "Helpers.h"

#include <fstream>

std::vector<char> Helpers::readFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("failed to open file!");
    }

    //Start at end of file to gauge size
    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);
    //Now read normal
    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;

}
