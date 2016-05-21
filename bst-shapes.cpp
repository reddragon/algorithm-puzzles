/**
 * Given an array of arrays, if we were to create unbalanced BSTs for every
 * member array, find the number of unique BST shapes created in this fashion.
 * Eg., [2 3 4] would have the same shape as [4 5 6], but not [4 3 2].
 * Hence for [[2 3 4] [4 5 6] [4 3 2]], the solution would be: 2.
 */

#include <iostream>
#include <set>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

// Solution idea courtesy @dhruvbird.
// If you want, you can construct a BST using these numbers, and then get an
// inorder traversal, which has the BST levels. For example, for [2, 3, 4]
// The inorder traversal with levels would be [0, 1, 2]. For [3 2 4], it would
// be [1 0 1]. You need to hash on these arrays.
//
// The solution below is cleaner, wherein you generate an array of
// (sorted_position, original_position) pairs for each element in the array.
// Then use the vector of these pairs to find the number of unique BST shapes.
int solve(vector<vector<int>> arr) {
  map<vector<pair<int, int>>, int> m;
  for (int i = 0; i < arr.size(); i++) {
    vector<pair<int, int>> t;
    if (arr[i].size() == 0) {
      continue;
    }
    for (int j = 0; j < arr[i].size(); j++) {
      t.push_back(std::make_pair(arr[i][j], j));
    }
    std::sort(t.begin(), t.end());
    vector<pair<int, int>> sign;
    for (int j = 0; j < t.size(); j++) {
      // Push original position in the array and the sorted position.
      sign.push_back(std::make_pair(t[j].second, j));
    }

    if (m.find(sign) == m.end()) {
      m[sign] = 0;
    }
    m[sign]++;
  }
  return m.size();
}

int main() {
  assert(solve({{2, 3, 4}, {4, 5, 6}, {4, 3, 2}}) == 2);
  assert(solve({{2, 3, 4}, {4, 5, 6}}) == 1);
  assert(solve({{2, 3, 4}}) == 1);
  assert(solve({{}}) == 0);
}
