#pragma once

#include <iostream>
#include <cassert>

#define EXPECT_EQ(X, Y) \
  { \
    if (X != Y) { \
      cerr << "Expected " << X << ", but received " << Y << endl; \
    } \
    assert(X == Y); \
  }
