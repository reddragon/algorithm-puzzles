#include "util.h"

int gcd(int a, int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  EXPECT_EQ(5, gcd(35, 10));
  EXPECT_EQ(1, gcd(2, 7));
  return 0;
}
