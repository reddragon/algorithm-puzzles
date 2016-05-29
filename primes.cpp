#include "util.h"

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
vector<uint> generatePrimesUpto(size_t n) {
  vector<bool> isPrime;
  isPrime.resize(n + 1, true);
  vector<uint> primes;

  for (int i = 2; i < isPrime.size(); i++) {
    if (!isPrime[i]) {
      continue;
    }

    primes.push_back(i);
    for (int j = i + i; j < isPrime.size(); j += i) {
      isPrime[j] = false;
    }
  }

  return primes;
}

int main() {
  {
    auto primes = generatePrimesUpto(1000);
    EXPECT_EQ(168, primes.size());
    EXPECT_EQ(2, primes[0]);
    EXPECT_EQ(997, primes[primes.size() - 1]);
  }
}
