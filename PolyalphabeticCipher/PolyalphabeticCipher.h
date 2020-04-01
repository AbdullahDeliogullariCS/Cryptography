//
// Created by abdullahdeliogullari on 4/1/20.
//

#ifndef CRYPTOGRAPHY_POLYALPHABETICCIPHER_H
#define CRYPTOGRAPHY_POLYALPHABETICCIPHER_H

#include <string>

using namespace std;

class PolyalphabeticCipher {

private:
    string key;

private:
    char characterShift(char character, int shift);

public:
    explicit PolyalphabeticCipher(string key);

public:
    string encrypt(string plainText);
    string decrypt(string cipherText);
};

#endif //CRYPTOGRAPHY_POLYALPHABETICCIPHER_H