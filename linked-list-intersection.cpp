#include "util.h"

// Given two linked lists, find their point of intersection.

template <typename T>
ListNode<T> *intersection(ListNode<T> *n1, ListNode<T> *n2) {
  int l1 = length(n1);
  int l2 = length(n2);

  for (; n1 != n2 && n1 != nullptr && n2 != nullptr;) {
    if (l1 > l2) {
      n1 = n1->next;
      l1--;
    } else if (l2 > l1) {
      n2 = n2->next;
      l2--;
    }
    n1 = n1->next;
    n2 = n2->next;
  }

  return n1;
}

int main() {
  {
    auto n1 = createListNode(3);
    auto n2 = createListNode(4);
    auto n3 = appendTo(n1, 5);
    auto n4 = appendTo(n3, 6);
    appendTo(n2, n4);
    EXPECT_EQ(n4, intersection(n1, n2));
  }
  {
    auto n1 = createListNode(3);
    auto n2 = createListNode(4);
    auto n3 = appendTo(n1, 5);
    auto n4 = appendTo(n3, 6);
    appendTo(n2, n4);
    EXPECT_EQ(n4, intersection(n2, n1));
  }
  {
    auto n1 = createListNode(3);
    auto n2 = createListNode(4);
    auto n3 = appendTo(n1, 5);
    appendTo(n2, n3);
    EXPECT_EQ(n3, intersection(n2, n1));
  }
  {
    auto n1 = createListNode(3);
    auto n2 = createListNode(4);
    assert(intersection(n1, n2) == nullptr);
  }
  return 0;
}
