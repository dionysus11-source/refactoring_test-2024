#include "../src/Prime.h"
#include <gtest/gtest.h>

TEST(primetest, PrintPrime) {
  int limit = 10;
  Prime prime;
  vector<int> result = prime.sieve_of_eratosthenes(limit);
  auto it = result.begin();
  EXPECT_EQ(2, *it++);
  EXPECT_EQ(3, *it++);
  EXPECT_EQ(5, *it++);
  EXPECT_EQ(7, *it);
}