#include "../Diffie-Hellman/Diffie-Hellman.h"
#include "../Extended-Euclidean/Extended-Euclidean.h"

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


const int sharedPrime = generatePrime(100, 1000);
/* private, public*/
const pair<int, int> keys_Alice = generateKeys(sharedPrime,2 );
const pair<int, int> keys_Bob = generateKeys(sharedPrime,2);


vector<int> econdeToASCII(string message){
    vector<int> ascii_message;
    for(size_t i = 0; i < message.size(); i++){
        ascii_message.push_back((int)message[i]);
    }
    return ascii_message;
}

vector<pair<int,int> > encrypt_Message(string message, int public_key, int P){
    vector< pair<int, int>> encrypted_message;
    vector<int> ascii_message = econdeToASCII(message);
    for(size_t i = 0; i < ascii_message.size(); i++){
        int k = generatePrime(1, P);
        int c1 = powmod(public_key, k, P);
        int c2 = (ascii_message[i] * powmod(keys_Bob.second, k, P)) % P;
        encrypted_message.push_back(make_pair(c1, c2));
    }
    return encrypted_message;
}

string decrypt_Message(vector<pair<int,int> > encrypted_message, int private_key, int P){
    string message;
    for(size_t i = 0; i < encrypted_message.size(); i++){
        int c1 = encrypted_message[i].first;
        int c2 = encrypted_message[i].second;
        int c1_private = powmod(c1, private_key, P);
        int c1_private_inverse = get<2>(extended_euclidean(c1_private, P));
        int m = (c1_private_inverse * c2) % P;
        message += (char)m;
    }
    return message;
}




void  doing_ELGamal(){
    string message = "Hello World";
    vector<pair<int,int> > encrypted_message = encrypt_Message(message, keys_Bob.second, sharedPrime);
    string decrypted_message = decrypt_Message(encrypted_message, keys_Bob.first, sharedPrime);
    cout << "The message is: " << message << "\n";
}




