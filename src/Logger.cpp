//
// Created by adamb on 31/03/2024.
//

#include "Logger.h"


Logger::Logger(const std::string& filename) {
    writeFile.open(filename, std::ios_base::app);
    if (!writeFile.is_open()) {
        throw std::runtime_error("Kan het bestand niet openen.");
    }
}





void Logger::logError(const std::string& errorMessage) {
    if (writeFile.is_open()) {
        writeFile << errorMessage << std::endl;
    } else {
        std::cerr << "Error: Kan niet schrijven naar errorFile." << std::endl;
    }
}

std::string Logger::logEndMessage(const std::string& deviceName, int jobNumber, const std::string& userName, int pageCount)  {

    endMessage << "Printer \"" << deviceName << '"' <<" finished job:" << std::endl;
    endMessage << "\tNumber: " << jobNumber << std::endl;
    endMessage << "\tSubmitted by \"" << userName << "\"" << std::endl;
    endMessage << "\t" << pageCount << " pages" << std::endl;

    return endMessage.str();
}

std::string Logger::logReport(const std::string& name, int emission, const std::deque<Job *> &jobs) {

    report << name << " (CO2: " << emission << "g/page):" << std::endl;

    if (!jobs.empty()) {
        report << "\t* Current:" << std::endl;
        report << "\t\t[#" << jobs.front()->getJobNumber() << "|" << jobs.front()->getUserName() << "]" << std::endl;

        if (jobs.size() > 1) {
            report << "\t* Queue:" << std::endl;
            for (std::vector<Job*>::size_type i = 1; i < jobs.size(); i++) {
                Job* job = jobs[i];
                report << "\t\t[#" << job->getJobNumber() << "|" << job->getUserName() << "]" << std::endl;
            }
        }
    } else {
        report << "\tNo jobs" << std::endl;
    }
    return report.str();
}

void Logger::logAllReports(std::vector<Device *> devices){





    for (size_t i = 0; i < devices.size(); ++i) {
        writeFile << devices[i]->printReport();
        if (i != devices.size() - 1)
            writeFile << "\n";
    }


}



Logger::Logger() = default;

Logger::~Logger() {
    if (writeFile.is_open()) {
        writeFile.close();
    }
}
