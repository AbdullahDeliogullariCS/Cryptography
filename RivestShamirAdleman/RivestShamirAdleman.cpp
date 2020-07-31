//
// Created by abdullahdeliogullari on 7/8/20.
//

#include "RivestShamirAdleman.h"

#include <iostream>
#include <string>
#include <cmath>

RivestShamirAdleman::RivestShamirAdleman(int firstRandomPrimeNumber, int secondRandomPrimeNumber) {
    this->firstRandomPrimeNumber = firstRandomPrimeNumber;
    this->secondRandomPrimeNumber = secondRandomPrimeNumber;
}

void RivestShamirAdleman::calculateModulus() {
    this->modulus = this->firstRandomPrimeNumber * this->secondRandomPrimeNumber;
}

int RivestShamirAdleman::encrypt(int publicKeyExponent, int plainText) {
    int cipherText = (int)pow(plainText, publicKeyExponent) % this->modulus;
    return cipherText;
}

int RivestShamirAdleman::decrypt(int privateKeyExponent, int cipherText) {
    int plainText = (int)pow(cipherText, privateKeyExponent) % this->modulus;
    return plainText;
}




