#include "Prime.h"
#include <iostream>

std::vector<int> Prime::sieve_of_eratosthenes(int n) {
  std::vector<bool> is_prime(n + 1, true);
  std::vector<int> primes;
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

void Prime::printPrime(std::vector<int> primes) {
  for (int prime : primes) {
    std::cout << prime << " ";
  }
  std::cout << std::endl;
}
