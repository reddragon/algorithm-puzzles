/**
 * Given an array of numbers, A and K <= length(A),
 * find a subsequence S of length K, such that the minimum difference between
 * consecutive elements of that subsequence, is maximum amongst all possible
 * subsequences of length K. Return the maximum difference in S.
 *
 * A = [1, 3, 4, 8] and K = 3.
 * There are four ways of picking 3 elements:
 * {1,3,4}, {1, 4, 8}, {1, 3, 8}, {3, 4, 8}.
 * The minimum consecutive difference for these four selections are
 * 2, 3, 2, 1, respectively. The maximum of these minimum consecutive
 * differences is 3, which is from selection {1, 4, 8}. 
 */

#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100
#define MAXK MAXN
#define INF 1e9
// #define DBG

bool done[MAXN][MAXK];
int dp[MAXN][MAXK];

int solve(const vector<int>&arr, int i, int size) {
  int &ref = dp[i][size];
  if (done[i][size]) {
    return ref;
  }

  if (size == 1) {
    ref = INF;
#ifdef DBG
      cout << i << " " << size << ", result: " << ref << endl;
#endif
    done[i][size] = true;
    return ref;
  }

  ref = -INF;
  if (arr.size() - i > size) {
    ref = max(ref, solve(arr, i + 1, size));
  }

  for (int j = i + 1; j <= arr.size() - size + 1; j++) {
    ref = max(ref, min(abs(arr[i] - arr[j]), solve(arr, j, size - 1)));
  }
#ifdef DBG
  cout << i << " " << size << ", result: " << ref << endl;
#endif
  done[i][size] = true;
  return ref;
}

int solve(vector<int> arr, int k) {
  assert(arr.size() >= 2);
  memset(done, 0, sizeof(done));
  return solve(arr, 0, k);
}


int main() {
  assert(solve({1, 2, 3, 4}, 3) == 1);
  assert(solve({1, 3, 4, 8}, 3) == 3);
}
