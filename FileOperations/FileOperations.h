//
// Created by abdullahdeliogullari
//

#ifndef CRYPTOGRAPHY_FILEOPERATIONS_H
#define CRYPTOGRAPHY_FILEOPERATIONS_H

#include <string>

using namespace std;

class FileOperations {

private:
    string filenameFrom;
    string filenameTo;

public:
    FileOperations(string filenameFrom, string filenameTo);

public:
    string readFile();
    void writeFile(string body);
};

#endif //CRYPTOGRAPHY_FILEOPERATIONS_H
