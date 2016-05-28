#include "util.h"

/**
 * Given a number, find the closest number which has the same number of bits.
 */
using namespace std;

uint64_t solve(uint64_t n);

void bruteForceTest() {
  map<int, vector<uint16_t>> weightMap;
  for (uint16_t i = 1; i < numeric_limits<uint16_t>::max(); i++) {
    weightMap[__builtin_popcount(i)].push_back(i);
  }

  for (uint16_t i = 1; i < numeric_limits<uint16_t>::max(); i++) {
    const auto &w = weightMap[__builtin_popcount(i)];
    uint16_t bestDiff = numeric_limits<uint16_t>::max();
    int idx = -1;
    for (int j = 0; j < w.size(); j++) {
      if (w[j] != i && abs(w[j] - i) < bestDiff) {
        bestDiff = abs(w[j] - i);
        idx = j;
      }
    }

    if (idx >= 0) {
      EXPECT_EQ(w[idx], solve(i));
    }
  }
}

size_t numBits(uint64_t n) {
  size_t x = 0;
  while (n != 0) {
    x++;
    n >>= 1;
  }
  return x;
}

uint64_t absDiff(uint64_t a, uint64_t b) {
  return std::max(a, b) - std::min(a, b);
}

// O(k**2) solution, where k = log2(n) / number of bits in the number.
uint64_t solve(uint64_t n) {
  // No valid values for 0 and the 2^64 - 1.
  if (n == 0 || n + 1 == 0) {
    return 0;
  }

  int num = numBits(n);
  int ones = __builtin_popcount(n);

  uint64_t bestDiff = -1;
  uint64_t bestNum = -1;

  // Swap bits in the number.
  for (int i = 0; i <= num; i++) {
    for (int j = 0; j <= num; j++) {
      if (i != j) {
        uint64_t candidate = n - (1L << i) + (1L << j);
        if (__builtin_popcount(candidate) == ones) {
          if (candidate != n && absDiff(candidate, n) < bestDiff) {
            bestNum = candidate;
            bestDiff = absDiff(candidate, n);
          }
        }
      }
    }
  }
  return bestNum;
}

int main() { bruteForceTest(); }
