//
// Created by adamb on 31/03/2024.
//

#ifndef PSE_PROJECT_LOGGER_H
#define PSE_PROJECT_LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>

class Logger {
private:
    std::ofstream writeFile;
    std::stringstream endMessage;

public:
    //constructors/destructors
    Logger(const std::string& filename);

    Logger();

    virtual ~Logger();

    //methodes
    void logError(const std::string& errorMessage);
    std::string logEndMessage(const std::string& deviceName, int jobNumber, const std::string& userName, int pageCount) ;
};


#endif //PSE_PROJECT_LOGGER_H
