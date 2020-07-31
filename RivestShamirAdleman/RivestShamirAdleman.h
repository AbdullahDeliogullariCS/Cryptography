//
// Created by abdullahdeliogullari on 7/8/20.
//

#ifndef CRYPTOGRAPHY_RIVESTSHAMIRADLEMAN_H
#define CRYPTOGRAPHY_RIVESTSHAMIRADLEMAN_H

#include <string>

using namespace std;

class RivestShamirAdleman {

private:
    int firstRandomPrimeNumber;
    int secondRandomPrimeNumber;

    int modulus;

public:
    explicit RivestShamirAdleman(int firstRandomPrimeNumber, int secondRandomPrimeNumber);

public:
    void calculateModulus();
    int encrypt(int publicKeyExponent, int plainText);
    int decrypt(int privateKeyExponent, int cipherText);
};

#endif //CRYPTOGRAPHY_RIVESTSHAMIRADLEMAN_H
