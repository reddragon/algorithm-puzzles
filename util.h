#pragma once

#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

#define EXPECT_EQ(X, Y) \
  { \
    if (X != Y) { \
      cerr << "Expected " << X << ", but received " << Y << endl; \
    } \
    assert(X == Y); \
  }
