#include <iostream>
#include <fstream>
#include <string>

#include "CaesarCipher/CaesarCipher.h"
#include "MonoalphabeticCipher/MonoalphabeticCipher.h"
#include "FileOperations/FileOperations.h"

// Caesar         ==> ./Cryptography cipher key  process pathFrom pathTo
// Monoalphabetic ==> ./Cryptography cipher seed process pathFrom pathTo

using namespace std;

int main(int argc, char* argv[]) {

    string cipher = argv[1];

    if(cipher == "caesar") {
        string process = argv[3];
        if(process == "-e") {
            int key = stoi(argv[2]);
            string filenameIn = argv[4];
            string filenameOut = argv[5];
            CaesarCipher caesarCipher = CaesarCipher(key);
            FileOperations fileOperations = FileOperations(filenameIn, filenameOut);
            string encryptedText = caesarCipher.encrypt(fileOperations.readFile());
            fileOperations.writeFile(encryptedText);
        }

        else if(process == "-d") {
            int key = stoi(argv[2]);
            string filenameIn = argv[4];
            string filenameOut = argv[5];
            CaesarCipher caesarCipher = CaesarCipher(key);
            FileOperations fileOperations = FileOperations(filenameIn, filenameOut);
            string decryptedText = caesarCipher.decrypt(fileOperations.readFile());
            fileOperations.writeFile(decryptedText);
        }

        else {
            cout << "Process has been failed";
        }
    }

    else if(cipher == "monoalphabetic") {
        string process = argv[3];
        if(process == "-e") {
            int seed = stoi(argv[2]);
            string filenameIn = argv[4];
            string filenameOut = argv[5];
            MonoalphabeticCipher monoalphabeticCipher = MonoalphabeticCipher(seed);
            FileOperations fileOperations = FileOperations(filenameIn, filenameOut);
            string encryptedText = monoalphabeticCipher.encrypt(fileOperations.readFile());
            fileOperations.writeFile(encryptedText);
        }

        else if(process == "-d") {
            int seed = stoi(argv[2]);
            string filenameIn = argv[4];
            string filenameOut = argv[5];
            MonoalphabeticCipher monoalphabeticCipher = MonoalphabeticCipher(seed);
            FileOperations fileOperations = FileOperations(filenameIn, filenameOut);
            string decryptedText = monoalphabeticCipher.decrypt(fileOperations.readFile());
            fileOperations.writeFile(decryptedText);
        }

        else {
            cout << "Process has mm been failed";
        }
    }

    else {
        cout << "Process has kkk been failed";
    }
    return 0;
}