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

  int cycleLength(ListNode *s) {
    auto p = s;
    p = p->next;
    int iter = 0;
    while (p != s) {
      iter++;
      p = p->next;
    }
    return iter;
  }

  ListNode *detectCycle(ListNode *h) {
    auto n = hasCycleNode(h);
    if (n == nullptr)
      return n;
    int len = cycleLength(n);
    if (len == 0)
      return n;

    auto s = h, f = h;
    for (int i = 0; i <= len; i++)
      f = f->next;
    while (s != f) {
      s = s->next;
      f = f->next;
    }
    return s;
  }
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
    assert(s.detectCycle(n1) == nullptr);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n2});
    assert(s.detectCycle(n1) == n2);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n6});
    assert(s.detectCycle(n1) == n6);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n3});
    assert(s.detectCycle(n1) == n3);
  }
  {
    DECL_NODES;
    setUpNext({n1, n2, n3, n4, n5, n6, n1});
    assert(s.detectCycle(n1) == n1);
  }
}
