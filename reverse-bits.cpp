#include "util.h"

using namespace std;

uint32_t reverseBits32(uint32_t n) {
  n = (n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16;
  n = (n & 0xff00ff00) >> 8  | (n & 0x00ff00ff) << 8;
  n = (n & 0xf0f0f0f0) >> 4  | (n & 0x0f0f0f0f) << 4;
  return n;
}

uint64_t reverseBits64(uint64_t n) {
  n = (n & 0xffffffff00000000) >> 32 | (n & 0x00000000ffffffff) << 32;
  n = (n & 0xffff0000ffff0000) >> 16 | (n & 0x0000ffff0000ffff) << 16;
  n = (n & 0xff00ff00ff00ff00) >> 8  | (n & 0x00ff00ff00ff00ff) << 8;
  n = (n & 0xf0f0f0f0f0f0f0f0) >> 4  | (n & 0x0f0f0f0f0f0f0f0f) << 4;
  return n;
}

int main() {
  EXPECT_EQ(0x10fedcba, reverseBits32(0xabcdef01));
  EXPECT_EQ(0xfeebdaed, reverseBits32(0xdeadbeef));
  EXPECT_EQ(0xfeebdaedfeebdaed, reverseBits64(0xdeadbeefdeadbeef));
}
