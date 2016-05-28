#include "util.h"

using namespace std;

template<class T>
vector<vector<T>> getPowerSet(vector<T> s) {
  vector<vector<T>> r;

  for (uint32_t i = 0; i < (1L<<s.size()); i++) {
    vector<T> c;
    for (int j = 0; j < s.size(); j++) {
      if (i & (1L<<j)) {
        c.push_back(s[j]);
      }
    }
    r.push_back(c);
  }
  return r;
}

int main() {
  {
    vector<vector<int>> expectedResult = {{}, {1}, {2}, {1, 2}};
    assert(getPowerSet<int>({1, 2}) == expectedResult);
  }
  {
    vector<vector<int>> expectedResult = {{}, {1}};
    assert(getPowerSet<int>({1}) == expectedResult);
  }
  {
    vector<vector<int>> expectedResult = {{}};
    assert(getPowerSet<int>({}) == expectedResult);
  }
}
