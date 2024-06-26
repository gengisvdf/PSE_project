//
// Created by adamb on 29/03/2024.
//

#include "Output.h"

Output::Output(const std::string &extension, const std::string &directory, const std::string &fileName) : extension(extension), directory(directory), fileName(fileName) {}

void Output::setExtension(const std::string &Extension) {
    Output::extension = Extension;
}

void Output::setDirectory(const std::string &Directory) {
    Output::directory = Directory;
}

void Output::setFileName(const std::string &FileName) {
    Output::fileName = FileName;
}



Output::Output() {}

Output::~Output() = default;

