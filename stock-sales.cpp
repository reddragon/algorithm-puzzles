/**
 * Given a list of prices of a stock each day, find the maximum profit you can
 * make by buying and selling the same stock once.
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <map>

#include "util.h"
using namespace std;

#define INF 1e9

int solve(vector<int> prices) {
  if (prices.size() == 0) {
    return 0;
  }
  int maxProfit = 0;
  int minSoFar = INF;
  for (int i = 0; i < prices.size(); i++) {
    maxProfit = max(maxProfit, prices[i] - minSoFar);
    minSoFar = min(minSoFar, prices[i]);
  }
  return maxProfit;
}

int main() {
  EXPECT_EQ(1, solve({1, 2, 3}));
  return 0;
}
