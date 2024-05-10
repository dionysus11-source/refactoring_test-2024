#include <iostream>
#include <vector>
using namespace std;

void sieve_of_eratosthenes(int n) {
  vector<bool> is_prime(n + 1, true);

  for (int p = 2; p * p <= n; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= n; i += p)
        is_prime[i] = false;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (is_prime[i])
      cout << i << " ";
  }
  cout << endl;
}

int main() {
  int limit = 30;
  sieve_of_eratosthenes(limit);
  return 0;
}