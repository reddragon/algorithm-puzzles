#include "util.h"

// Find all prime factors, including duplicates.
// For n = 100 => [2, 2, 5, 5].
vector<int> getNonUniqueFactorization(int n) {
  vector<int> results;
  int origN = n;
  for (int i = 2; i <= sqrt(origN); i++) {
    // We don't need to check if i is a prime, because if we greedily divide
    // a number by all numbers starting from 2 .., we will never reach a
    // composite factor, while the residual number is still divisible by it.
    while (n % i == 0) {
      results.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    results.push_back(n);
  }
  return results;
}


int main() {
  assert(getNonUniqueFactorization(16) == vector<int>({2, 2, 2, 2}));
  assert(getNonUniqueFactorization(123) == vector<int>({3, 41}));
  assert(getNonUniqueFactorization(2) == vector<int>({2}));
  assert(getNonUniqueFactorization(6) == vector<int>({2, 3}));
  assert(getNonUniqueFactorization(100) == vector<int>({2, 2, 5, 5}));
}
