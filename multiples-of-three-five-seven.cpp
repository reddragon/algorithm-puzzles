/**
 * Find the n-th smallest number, whose prime factorization only contains
 * 3, 5 or 7. i.e, is of the form f = 3**x . 5**y . 7**z (where x + y + z >= 1).
 */

#include <iostream>
#include <set>
#include <cassert>
using namespace std;

// O(n log n) approach.
long long nThMultiple(int n) {
  set<long long> heap;
  heap.insert(1);

  long long x;
  for (int i = 0; i <= n; i++) {
    x = *heap.begin();
    heap.erase(heap.begin());
    heap.insert(x * 3);
    heap.insert(x * 5);
    heap.insert(x * 7);
  }
  return x;
}

int main() {
  assert(nThMultiple(1) == 3);
  assert(nThMultiple(1000) == 82046671875);
}
