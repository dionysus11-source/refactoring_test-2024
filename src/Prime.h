#ifndef PRIME_H
#define PRIME_H

#include <vector>
using namespace std;

class Prime {
public:
  vector<int> sieve_of_eratosthenes(int n);
  void printPrime(vector<int> primes);
};

#endif // PRIME_H