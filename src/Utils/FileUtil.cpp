#include "FileUtil.h"

namespace fs = std::filesystem;

std::string getFileContent(const fs::path& filePath) {
    
    std::ifstream inFile(filePath);

    if(!inFile.is_open()) {
        std::string error = "Unable to open the file: " + filePath.filename().string();
        std::cout << error << std::endl;
        return "ERR_CNOF";
    }
    
    std::ostringstream stream;
    stream << inFile.rdbuf();
    inFile.close();
    return stream.str();
}

void modifyFileContent(const fs::path& filePath, std::string toWrite) {

    std::ofstream inFile;
    inFile.open(filePath, std::ofstream::out | std::ofstream::trunc);

    if(!inFile.is_open()) {
        std::string error = "Unable to open the file: " + filePath.filename().string();
        std::cout << error << std::endl;
        exit(0);
    }
    
    inFile << toWrite;

    inFile.close();

}


std::filesystem::path getPath() {
    std::filesystem::path to_get = std::filesystem::current_path();
    while (to_get.filename() != "gate-game") {
        if(to_get == to_get.root_path()) {
            return "ERR";
        }
        to_get = to_get.parent_path();
    }
    
    return to_get / "res";
}
