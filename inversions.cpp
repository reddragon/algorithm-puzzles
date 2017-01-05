#include "util.h"

// Given an array, count the number of inversions in the array, i.e.,
// the number of pairs, where the larger number occurs before a smaller number.

// O(n**2) approach.
int inversionsNaive(vector<int> v) {
  int count = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] > v[j]) {
        count++;
      }
    }
  }
  return count;
}

int inversionUsingSort(vector<int> &v) {
  if (v.size() <= 1) {
    return 0;
  }
  int count = 0;

  // Divide the array into two parts.
  vector<int> firstPart(v.begin(), v.begin() + v.size() / 2);
  vector<int> secondPart(v.begin() + v.size() / 2, v.end());

  count += inversionUsingSort(firstPart);
  count += inversionUsingSort(secondPart);

  // Merge the arrays.
  auto first = firstPart.begin();
  auto second = secondPart.begin();

  size_t idx = 0;
  for (; first != firstPart.end() || second != secondPart.end();) {
    if (first == firstPart.end()) {
      v[idx++] = *second;
      second++;
    } else if (second == secondPart.end()) {
      v[idx++] = *first;
      first++;
    } else {
      if (*first <= *second) {
        v[idx++] = *first;
        first++;
      } else {
        // This is the inversion case. We are inserting an element from the
        // second vector into the merged vector. All the remaining elements in
        // the first vector are inversions w.r.t. the element being added from
        // the second. Note that this counts duplicates too.
        count += std::distance(first, firstPart.end());
        v[idx++] = *second;
        second++;
      }
    }
  }
  return count;
}

int inversions(const vector<int> &v) {
  // Make a copy of the vector.
  vector<int> vc = v;
  return inversionUsingSort(vc);
}

int main() {
  {
    vector<int> t = {4, 6, 1, 2, 3, 9, 11, 7, 8, 101, 33, 22, 121, 24, 4};
    EXPECT_EQ(inversionsNaive(t), inversions(t));
  }
}
