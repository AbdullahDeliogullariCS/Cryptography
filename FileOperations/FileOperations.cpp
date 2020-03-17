//
// Created by abdullahdeliogullari
//

#include "FileOperations.h"

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

FileOperations::FileOperations(string filenameFrom, string filenameTo) {
    this->filenameFrom = filenameFrom;
    this->filenameTo = filenameTo;
}

string FileOperations::readFile() {
    ifstream infile(this->filenameFrom);
    string body;
    if (infile.is_open() && infile.good()) {
        string line;
        while (getline(infile, line)){
            body += "\n" + line;
        }
        infile.close();
        return body;

    } else {
        return body;
    }
}

void FileOperations::writeFile(string body) {
    vector<string> lines;
    boost::split(lines, body, boost::is_any_of("\n"));
    ofstream outfile(this->filenameTo);
    if (outfile.is_open() && outfile.good()) {
        for(int i = 0; i < lines.size(); i++) {
            string line = lines[i] + '\n';
            outfile << line;
        }
    }
    outfile.close();
}
