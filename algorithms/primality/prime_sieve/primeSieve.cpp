//Prime Sieve Implementation
#include "primeSieve.hpp"
bool* primeSieve(unsigned int size) {
    const int BOUND = (int)sqrt(size);
    bool *sieve = new bool[size]();
    sieve[0] = true;
    sieve[1] = true;

    //Deal with odds
    int i = 4;
    while (i < size) {
        sieve[i] = true;
        i += 2;
    }
    
    for (i = 3; i < BOUND; i+=2) {
        if (!sieve[i]) {
            for (int k = i * 2; k < size; k+=i) {
                sieve[i] = true;
            }
        }
    }
    return sieve;
}
