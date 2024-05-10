#include "Prime.h"
#include <iostream>
#include <vector>

using namespace std;

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

int main() {
  int limit = 30;
  Prime prime;
  vector<int> result = prime.sieve_of_eratosthenes(limit);
  prime.printPrime(result);

  return 0;
}