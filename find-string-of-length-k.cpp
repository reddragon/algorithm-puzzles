#include "util.h"

/**
 * Given two strings, find if there is a common substring >= length k.
 * Assuming both strings are of size n, naive solution is O(n^2 . k).
 * This solution is O((n - k)k log (n - k)).
 */
 bool solve(string s1, string s2, int k) {
   // Check if length of s1 and s2 are both >= k
   if (s1.size() < k || s2.size() < k) {
     return false;
   }

   // Build all substrings of s1 of length k
   set<string> subs;
   string window;
   for (int i = 0; i < s1.size() && i + k <= s1.size(); i++) {
     // There is no point in optimizing the string construction here, because
     // std::set would anyway incur a new copy of the string. There is only a
     // constant time improvement, if we do anything smart here.
     window = s1.substr(i, k);
     subs.insert(window);
   }

   // Now check for s2
   for (int i = 0; i < s2.size() && i + k <= s2.size(); i++) {
     window = s2.substr(i, k);
     if (subs.find(window) != subs.end()) {
       return true;
     }
   }
   return false;
 }

int main() {
  EXPECT_EQ(true, solve("abcde", "a", 1));
  EXPECT_EQ(true, solve("abcde", "ax", 1));
  EXPECT_EQ(true, solve("abcde", "yay", 1));
  EXPECT_EQ(true, solve("abcde", "ffbcff", 2));
  EXPECT_EQ(false, solve("xxxxxx", "yyyyy", 2));
  return 0;
}
