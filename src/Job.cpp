
#include "Job.h"
#include "Logger.h"

static const std::string errorExtension = ".error";
static const std::string errorDirectory = "errors/";
static const std::string erroFileName = "error_";
static string errFile = constructFilename(errorDirectory, errorExtension,erroFileName);





int Job::getJobNumber() const {
    return jobNumber;
}


int Job::getPageCount() const {
    return pageCount;
}


bool Job::isFinished() const {
    return finished;
}

void Job::setFinished(bool Finished) {
    Job::finished = Finished;
}

bool Job::isInProcess() const {
    return inProcess;
}

void Job::setInProcess(bool InProcess) {
    Job::inProcess = InProcess;
}

const std::string &Job::getUserName() const {
    return userName;
}


Device *Job::getBeingWorkedOnBy() const {
    return beingWorkedOnBy;
}

void Job::setBeingWorkedOnBy(Device *BeingWorkedOnBy) {
    Job::beingWorkedOnBy = BeingWorkedOnBy;
}

Job::Job(int jobNumber, int pageCount, const std::string &userName) : jobNumber(jobNumber), pageCount(pageCount), userName(userName) {}


Job::Job(TiXmlElement *job_element) {
    std::string JN_temp;
    std::string PC_temp;
    std::string UN_temp;
    Logger errorLog(errFile);


    TiXmlNode *node = job_element->FirstChild();
    while (node != NULL) {

        TiXmlNode *childNode = node->FirstChild();
        if (childNode != NULL) {

            std::string nodeName = node->Value();
            std::string nodeValue = childNode->Value();

            if (nodeName == "jobNumber") {
                JN_temp = nodeValue;

            } else if (nodeName == "pageCount") {
                PC_temp = nodeValue;

            } else if (nodeName == "userName") {
                UN_temp = nodeValue;
            } else {
                errorLog.logError("Onbekende element job: " + nodeName);
            }
        }
        node = node->NextSibling();
    }
try{EXPECT(!JN_temp.empty(), "Geen jobNumber opgegeven.");
    EXPECT(isInt(JN_temp), "JobNumber moet een integer zijn.");
    EXPECT(!isNegativeInt(JN_temp), "JobNumber mag niet negatief zijn.");
    jobNumber = std::stoi(JN_temp);


    EXPECT(!PC_temp.empty(), "Geen pageCount opgegeven.");
    EXPECT(isInt(PC_temp), "PageCount moet een integer zijn");
    EXPECT(!isNegativeInt(PC_temp), "PageCount mag niet negatief zijn.");
    pageCount = std::stoi(PC_temp);


    EXPECT(!UN_temp.empty(), "Geen userName opgegeven.");
    userName = UN_temp;}
catch (const std::runtime_error& error){
    errorLog.logError(error.what());
    }
}

std::string Job::EndMessage() const{
    REQUIRE(getBeingWorkedOnBy() != NULL, "Job is not assigned to a device");
    Logger endMessage;
    return endMessage.logEndMessage(getBeingWorkedOnBy()->getName(), jobNumber, userName, pageCount);
}






Job::~Job() {}
