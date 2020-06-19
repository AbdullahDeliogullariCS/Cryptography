//
// Created by abdullahdeliogullari on 5/23/20.
//

#ifndef CRYPTOGRAPHY_DIFFIEHELLMANKEYEXCHANGE_H
#define CRYPTOGRAPHY_DIFFIEHELLMANKEYEXCHANGE_H

#include <array>
#include <string>
#include <vector>

using namespace std;

class DiffieHellmanKeyExchange{

private:
    int public_key;
    int shared_key;

public:
    int generatePublicKey(int random_integer, int private_key, int large_prime_number);
    int generateSharedKey(int exchanged_public_key, int private_key, int large_prime_number);
};

#endif //CRYPTOGRAPHY_DIFFIEHELLMANKEYEXCHANGE_H
