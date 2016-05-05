/**
 * Given an array of zeroes and ones, find the length of the largest subarray
 * which has equal number of zeroes and ones.
 */

#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLength(vector<int> arr) {
  unordered_map<int, int> m;
  // Avoiding the corner case of {1, 0, 1, 0}
  m[0] = -1;

  int z = 0, o = 0;
  int maxL = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 0) {
      z++;
    } else {
      o++;
    }
    int d = z - o;
    auto it = m.find(d);
    if (it == m.end()) {
      m[d] = i;
    } else {
      maxL = max(maxL, i - it->second);
    }
  }
  return maxL;
}

int main() {
  assert(maxLength({0, 1}) == 2);
  assert(maxLength({0, 1, 1}) == 2);
  assert(maxLength({0, 1, 1, 0}) == 4);
  assert(maxLength({0, 0, 0, 0, 1}) == 2);
  assert(maxLength({0, 1, 1, 1, 1}) == 2);
  assert(maxLength({1, 1, 1, 1}) == 0);
  assert(maxLength({0, 0, 0, 0}) == 0);
  assert(maxLength({1, 0, 1, 0}) == 4);
  return 0;
}
