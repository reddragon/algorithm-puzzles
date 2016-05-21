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

// There is an O(n) approach to this as well.
// Maintain three queues, for 3, 5, and 7.
// Start with 3, 5 and 7 in those queues respectively.
// Find the minimum of the three queues, and pop it.
// Let's say you popped number 't'.
// t would be of the form 3**x . 5**y . 7**z. Let it be denoted by (x,y,z).
// If z > 0, you can only push (x, y, z+1) into the queue you popped t from.
// If y > 0, and, z = 0, you can also push (x, y+1, z)
// If x > 0, y = 0, and, z = 0, you can also push (x+1, y, z).
// This is to avoid duplication of numbers.
// As an example, try to draw the recursion tree for getting from
// (x, y, z) to (x+1, y+1, z+1), with both the current proposed method, and
// with no restriction on incrementing x, y, z. You would see, with the current
// method, there is only one possible path.

int main() {
  assert(nThMultiple(1) == 3);
  assert(nThMultiple(1000) == 82046671875);
}
