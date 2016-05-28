#pragma once

#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <limits>
#include <bitset>
#include <string>

using namespace std;

#define EXPECT_EQ(X, Y) \
  { \
    if (X != Y) { \
      cerr << "Expected " << X << ", but received " << Y << endl; \
    } \
    assert(X == Y); \
  }

string toBinaryStr(uint64_t n) {
  string r;
  do {
    r.push_back('0' + n % 2);
    n /= 2;
  } while (n != 0);
  reverse(r.begin(), r.end());
  return r;
}
