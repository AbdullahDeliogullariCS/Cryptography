//
// Created by abdullahdeliogullari
//

#ifndef CRYPTOGRAPHY_MONOALPHABETICCIPHER_H
#define CRYPTOGRAPHY_MONOALPHABETICCIPHER_H

#include <string>
#include <vector>

using namespace std;

class MonoalphabeticCipher {

private:
    int seed;
    vector<int> alphabet = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,24,25};

private:
    char characterMap(char character);
    char characterRecover(char mappedCharacter);

public:
    explicit MonoalphabeticCipher(int seed);

public:
    void shuffleAlphabet();
    string encrypt(string plainText);
    string decrypt(string cipherText);
};


#endif //CRYPTOGRAPHY_MONOALPHABETICCIPHER_H