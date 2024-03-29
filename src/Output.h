//
// Created by adamb on 29/03/2024.
//

#ifndef PSE_PROJECT_OUTPUT_H
#define PSE_PROJECT_OUTPUT_H

#include <iostream>

struct Output {

    std::string extension;
    std::string directory;
    std::string fileName;
    Output(const std::string &extension, const std::string &directory, const std::string &fileName);
    Output();
    virtual ~Output();

    void setExtension(const std::string &extension);
    void setDirectory(const std::string &directory);
    void setFileName(const std::string &fileName);

    void askOutput();


};


#endif //PSE_PROJECT_OUTPUT_H
