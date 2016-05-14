// Given a list of numbers, find the number of unique BSTs you can construct.
// {1} => 1
// {1, 2} => 2
// {1, 2, 3} => 5
// Solution is via DP. We only need the list to check if it is sorted.
// Otherwise, the solution is obtainable via Catalan numbers.
// https://en.wikipedia.org/wiki/Catalan_number
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[100][100];
int solve(int i, int j, int sz) {
  if (sz == 1 || i == j || i > j || i < 0 || j > sz) {
    return 1;
  }
  if (cache[i][j] != -1) {
    return cache[i][j];
  }

  int ret = 0;
  for (int k = i; k <= j; k++) {
    ret += solve(i, k - 1, sz) * solve(k + 1, j, sz);
  }
  cache[i][j] = ret;
  return ret;
}

int solve(vector<int> &x) {
  if (!is_sorted(x.begin(), x.end())) {
    return false;
  }
  memset(cache, -1, sizeof(cache));

  int ret = 0, sz = x.size();
  for (int i = 0; i < x.size(); i++) {
    ret += solve(0, i - 1, sz) * solve(i + 1, x.size() - 1, sz);
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> vals;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vals.push_back(x);
  }
  cout << solve(vals) << endl;
  return 0;
}
