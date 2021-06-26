//*______ Joshua Snyder ______*//

/*
 *  TODO: 
 *      1. Parse the status.txt file in order to read the RssAnon value (kB)
 *      2. Use this value to add to the total memory usage of the system 
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <exception>
#include <vector>
#include <experimental/filesystem>

int extractNumber(std::string dirName) {
    std::string str = dirName.substr(6, dirName.length());
    int num;

    try {
        num = std::stoi(str);
    }
    catch (std::exception& e) {
        num = -1;
    }
    
    return num;
}

int getVMem(const int& PROC_ID) {
    std::ostringstream oSS;
    std::string fileName;
    std::ifstream file;
    int size;

    oSS << "/proc/" << PROC_ID << "/statm";
    
    fileName = oSS.str();

    file.open(fileName, std::ios_base::in);

    file >> size;

    


    std::cout << PROC_ID << ": " << size << std::endl;

    return size;
}

int main(void) {
    std::ifstream file;
    std::string procName = "/proc";
    std::vector<int> procIds;
    int procId;
    int totalMemUsage;
    int memUsage;

    for (auto& p: std::experimental::filesystem::directory_iterator(procName)) {
        procId = extractNumber(p.path());

        if (procId != -1) {
            procIds.push_back(procId);
        }
    }

    for (int i = 0; i < procIds.size(); i++) {
        memUsage = getVMem(procIds[i]);
        std::cout << "Adding " << memUsage << " kB ... " << std::endl;
        totalMemUsage += (memUsage);
    }
    std::cout << "Total memory used: " << std::setprecision(2) << std::fixed << totalMemUsage << " kB" << std::endl;
    std::cout << "(" << procIds.size() << ") processes. " << std::endl;

    /*
    file.open("proc/1/stat", std::ios_base::in);
    std::string pid, comm, state, ppid, pgrp, session, tty_nr;
    std::string tpgid, flags, minflt, cminflt, majflt, cmajflt;
    std::string utime, stime, cutime, cstime, priority, nice;
    std::string O, itrealvalue, starttime;
    unsigned long vsize;
    long rss;
    file >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
    >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
    >> utime >> stime >> cutime >> cstime >> priority >> nice
    >> O >> itrealvalue >> starttime >> vsize >> rss;

    std::cout << vsize << std::endl;

    file.close();
    */
    
    return 0;
}