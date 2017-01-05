#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <limits>
#include <bitset>
#include <string>
#include <iterator>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  void setNext(ListNode *n) { next = n; }
};

class Solution {
public:
  ListNode *hasCycleNode(ListNode *h) {
    auto s = h;
    auto f = h;
    int iter = 0;

    while (s != nullptr && f != nullptr) {
      if (iter > 0 && s == f)
        return s;
      s = s->next;
      f = (f->next != nullptr ? f->next->next : nullptr);
      iter++;
    }
    return nullptr;
  }

  bool hasCycle(ListNode *h) { return hasCycleNode(h) != nullptr; }
};

#define DECL_NODES                                                             \
  ListNode *n1 = new ListNode(1);                                              \
  ListNode *n2 = new ListNode(2);                                              \
  ListNode *n3 = new ListNode(3);                                              \
  ListNode *n4 = new ListNode(4);                                              \
  ListNode *n5 = new ListNode(5);                                              \
  ListNode *n6 = new ListNode(6)

void setUpNext(vector<ListNode *> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i + 1 < v.size())
      v[i]->setNext(v[i + 1]);
  }
}

int main() {
  Solution s;
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6});
    assert(s.hasCycle(n1) == false);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n2});
    assert(s.hasCycle(n1) == true);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n6});
    assert(s.hasCycle(n1) == true);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n3});
    assert(s.hasCycle(n1) == true);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n1});
    assert(s.hasCycle(n1) == true);
  }
}
