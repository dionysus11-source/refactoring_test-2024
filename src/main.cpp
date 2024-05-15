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

int partition(std::vector<std::pair<int, int>> &vec,
              bool (*compareFunction)(const std::pair<int, int> a,
                                      const std::pair<int, int> b)) {
  std::pair<int, int> pivot = vec.back();
  int i = -1;

  for (int j = 0; j < vec.size() - 1; j++) {
    if (compareFunction(vec[j], pivot)) {
      i++;
      std::swap(vec[i], vec[j]);
    }
  }
  std::swap(vec[i + 1], vec.back());
  return (i + 1);
}

void quickSort(std::vector<std::pair<int, int>> &vec,
               bool (*compareFunction)(const std::pair<int, int> a,
                                       const std::pair<int, int> b)) {
  if (vec.size() <= 1)
    return; // 벡터의 크기가 1 이하면 정렬할 필요가 없음

  int partitionIndex = partition(vec, compareFunction);
  std::vector<std::pair<int, int>> left(vec.begin(),
                                        vec.begin() + partitionIndex);
  std::vector<std::pair<int, int>> right(vec.begin() + partitionIndex + 1,
                                         vec.end());

  quickSort(left, compareFunction);
  quickSort(right, compareFunction);

  vec.clear();
  vec.insert(vec.end(), left.begin(), left.end());
  vec.push_back(vec[partitionIndex]);
  vec.insert(vec.end(), right.begin(), right.end());
}

void sortValueTest() {
  // pair를 포함하는 vector 생성
  std::vector<std::pair<int, int>> myVector = {{3, 1}, {1, 2}, {2, 5}, {5, 4}};

  // pair의 첫 번째 값을 기준으로 정렬
  quickSort(myVector, [](pair<int, int> a, pair<int, int> b) -> bool {
    return a.first < b.first;
  });

  // 정렬 결과 출력
  std::cout << "Sorted by first value:" << std::endl;
  for (const auto &pair : myVector) {
    std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
  }

  std::cout << std::endl;

  // pair의 두 번째 값을 기준으로 정렬
  quickSort(myVector, [](pair<int, int> a, pair<int, int> b) -> bool {
    return a.second < b.second;
  });

  // 정렬 결과 출력
  std::cout << "Sorted by second value:" << std::endl;
  for (const auto &pair : myVector) {
    std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
  }
}

int main() {
  int limit = 30;
  Prime prime;
  vector<int> result = prime.sieve_of_eratosthenes(limit);
  prime.printPrime(result);
  sortValueTest();
  return 0;
}