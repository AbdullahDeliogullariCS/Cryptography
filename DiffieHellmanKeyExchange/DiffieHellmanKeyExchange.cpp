//
// Created by abdullahdeliogullari on 5/23/20.
//

#include "DiffieHellmanKeyExchange.h"

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int DiffieHellmanKeyExchange::generatePublicKey(int random_integer, int private_key, int large_prime_number) {
    public_key = (int)pow(random_integer, private_key) % large_prime_number;
    return public_key;
}

int DiffieHellmanKeyExchange::generateSharedKey(int exchanged_public_key, int private_key, int large_prime_number) {
    shared_key = (int)pow(exchanged_public_key, private_key) % large_prime_number;
    return shared_key;
}


