//
// Created by adamb on 31/03/2024.
//

#ifndef PSE_PROJECT_LOGGER_H
#define PSE_PROJECT_LOGGER_H

#include <iostream>
#include <fstream>

class Logger {
private:
    std::ofstream writeFile;
public:
    //constructors/destructors
    Logger(const std::string& filename);
    virtual ~Logger();

    //methodes
    void logError(const std::string& errorMessage);
};


#endif //PSE_PROJECT_LOGGER_H
