//
// Created by abdullahdeliogullari
//

#ifndef CRYPTOGRAPHY_CAESARCIPHER_H
#define CRYPTOGRAPHY_CAESARCIPHER_H

#include <string>

using namespace std;

class CaesarCipher {

private:
    int key;

private:
    char characterShift(char character, int shift);

public:
    explicit CaesarCipher(int key);

public:
    string encrypt(string plainText);
    string decrypt(string cipherText);
};

#endif //CRYPTOGRAPHY_CAESARCIPHER_H
