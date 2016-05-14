/**
 * Consider a water tank, with separators placed at unit distances between
 * one edge to the other. The first and the last separators are the edges of
 * the tank, and water spills off them. If we were to continuously fill the
 * tank, what is the volume of the largest contiguous water block? Assume
 * unit length of the tank, and negligible width of the separators.
 *
 * Example:
 *
 *            |       |
 *            |   |   |
 *        |   |   |   |   |
 *    |   |   |   |   |   |
 *    ---------------------
 * i  0   1   2   3   4   5
 * h  1   2   4   3   4   2
 *
 * i - Index of the separator, h - height of the separator.
 * Here is what happens when we fill up the water tank:
 *
 *            | *   * |
 *            | * | * |
 *        | * | * | * | * |
 *    | * | * | * | * | * |
 *    ---------------------
 * i  0   1   2   3   4   5
 * h  1   2   4   3   4   2
 *
 * Between separators 0 and 1, we can only fill 1 unit of water, since 0 is
 * shorter than 1, and any more water will spill off. Similarly between 1 & 2,
 * we can fill 2 units of water, since height of separator 1 is 2 units.
 * Between separators 2 and 4, we can store 8 units of water, since both of them
 * are 4 units tall, and 2 units apart. The maximum volume of a contiguous water
 * block is 8 units here.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

// Find the first separator after idx, which is taller or of the same height
// as idx.
int nextSeperator(const vector<int>& h, int idx) {
  int target = idx + 1;
  for (int j = idx + 1; j < h.size(); j++) {
    if (h[j] >= h[idx]) {
      return j;
    }
    if (h[target] < h[j]) {
      target = j;
    }
  }
  return target;
}

int solve(vector<int> h) {
  int maxVol = 0;
  for (int i = 0; i < h.size(); ) {
    int next = nextSeperator(h, i);
    if (next > h.size()) {
      break;
    }

    maxVol = max(maxVol, min(h[next], h[i]) * (next - i));
    i = next;
  }
  return maxVol;
}

int main() {
  assert(solve({1, 2, 4, 3, 4, 2}) == 8);
  assert(solve({4, 3, 2}) == 3);
  assert(solve({2, 3, 4}) == 3);
  assert(solve({4, 4}) == 4);
  assert(solve({4, 4, 4}) == 4);
  assert(solve({3, 4, 2, 3}) == 6);
}
