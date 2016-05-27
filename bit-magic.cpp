#include "util.h"

using namespace std;

uint32_t reverse32Bits(uint32_t n) {
  n = (n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16;
  n = (n & 0xff00ff00) >> 8  | (n & 0x00ff00ff) << 8;
  n = (n & 0xf0f0f0f0) >> 4  | (n & 0x0f0f0f0f) << 4;
  return n;
}

int main() {
  EXPECT_EQ(0x10fedcba, reverse32Bits(0xabcdef01));
  EXPECT_EQ(0xfeebdaed, reverse32Bits(0xdeadbeef));
}
