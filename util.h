#pragma once

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
#include <unordered_map>

using namespace std;

#define EXPECT_EQ(X, Y)                                                        \
  {                                                                            \
    if (X != Y) {                                                              \
      cerr << "Expected " << X << ", but received " << Y << endl;              \
    }                                                                          \
    assert(X == Y);                                                            \
  }

string toBinaryStr(uint64_t n) {
  string r;
  do {
    r.push_back('0' + n % 2);
    n /= 2;
  } while (n != 0);
  reverse(r.begin(), r.end());
  return r;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Linked List Related Methods
template <typename T> struct ListNode {
  T data;
  ListNode<T> *next;
};

template <typename T> ListNode<T> *createListNode(T data) {
  ListNode<T> *newNode = new ListNode<T>();
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}

template <typename T> ListNode<T> *appendTo(ListNode<T> *n, ListNode<T> *next) {
  n->next = next;
  return next;
}

template <typename T> ListNode<T> *appendTo(ListNode<T> *n, T data) {
  ListNode<T> *newNode = createListNode(data);
  return appendTo(n, newNode);
}

template <typename T> int length(ListNode<T> *n) {
  if (n == nullptr) {
    return 0;
  }
  return 1 + length(n->next);
}

template <typename T> void iterate(ListNode<T> *n) {
  if (n == nullptr) {
    cout << endl;
    return;
  }
  cout << n->data << " ";
  iterate(n->next);
}
