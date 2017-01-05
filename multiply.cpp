#include "util.h"

// Adding two numbers using binary operators.
uint32_t add(uint32_t a, uint32_t b) {
  uint32_t result = 0, carryIn = 0, carryOut = 0;
  size_t bit = 0;

  for (; a | b | carryIn;) {
    uint32_t a1 = a & 1, b1 = b & 1;
    uint32_t sum = a1 ^ b1 ^ carryIn;
    uint32_t carryOut = (a1 & carryIn) | (b1 & carryIn) | (a1 & b1);
    result = sum << bit | result;
    bit++;
    carryIn = carryOut;
    a >>= 1;
    b >>= 1;
  }

  return result;
}

// Multiply using only binary operators.
uint32_t multiply(uint32_t a, uint32_t b) {
  uint32_t result = 0;
  size_t bit = 0;

  while (b) {
    uint32_t b1 = b & 1;
    if (b1) {
      result = add(result, a << bit);
    }
    bit++;
    b >>= 1;
  }
  return result;
}

int main() {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      EXPECT_EQ(i * j, multiply(i, j));
    }
  }
}
