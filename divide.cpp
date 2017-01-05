#include "util.h"

pair<uint64_t, uint64_t> divide(uint64_t a, uint64_t b) {
  uint64_t q = 0, r = 0;

  // Make up a table for fast lookup of multiples.
  vector<pair<uint64_t, uint64_t>> p;
  p.push_back(make_pair(b, 1));
  uint64_t x = b, y = 1;
  for (; x < a;) {
    // Overflow
    if (x + x < x) {
      break;
    }
    x = x + x;
    y *= 2;
    p.push_back(make_pair(x, y));
  }

  // Greedily subtract as much as possible in one go.
  int pos = p.size() - 1;
  while (pos > 0) {
    if (p[pos].first > a) {
      pos--;
      continue;
    }
    a -= p[pos].first;
    q += p[pos].second;
  }
  r = a;
  return std::make_pair(q, r);
}

int main() {
  {
    pair<uint64_t, uint64_t> p = {2, 1};
    assert(divide(7, 3) == p);
  }
  {
    pair<uint64_t, uint64_t> p = {250000000, 0};
    assert(divide(500000000L, 2) == p);
  }
  {
    pair<uint64_t, uint64_t> p = {38461538L, 6};
    assert(divide(500000000L, 13) == p);
  }
}
