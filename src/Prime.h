#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Prime {
public:
  vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; p++) {
      if (is_prime[p]) {
        for (int i = p * p; i <= n; i += p)
          is_prime[i] = false;
      }
    }

    for (int i = 2; i <= n; i++) {
      if (is_prime[i])
        primes.push_back(i);
    }

    return primes;
  }
  void printPrime(vector<int> primes) {

    for (int prime : primes) {
      cout << prime << " ";
    }
    cout << endl;
  }
};