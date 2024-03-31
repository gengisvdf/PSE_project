//
// Created by adamb on 31/03/2024.
//

#include "Logger.h"

Logger::Logger(const std::string& filename) {
    writeFile.open(filename, std::ofstream::app);
    if (!writeFile.is_open()) {
        throw std::runtime_error("Kan het foutenbestand niet openen.");
    }
}


void Logger::logError(const std::string& errorMessage) {
    if (writeFile.is_open()) {
        writeFile << errorMessage << std::endl;
    } else {
        std::cerr << "Error: Kan niet schrijven naar errorFile." << std::endl;
    }
}


Logger::~Logger() = default;

