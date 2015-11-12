#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

/*
  Given a number n, find the smallest multiple of n, which has only 0s and 1s.
  Eg., 4 => 100, 255 => 100010, 101 => 101, etc.
  This is by far one of the most interesting problems I have seen recently.
  I didn't spend time on this, and googled for ideas.

  Solution:
  A multiple m, with 0s and 1s, would be like this.
  10^i1 + 10^i2 + 10^i3 + ... === 0 (mod n).

  If there the smallest multiple was k digits long, a simple approach will be
  O(2^k), trying all 2^k possible combinations. However, we can look at this
  interesting idea, for lets say n = 7.

  10^0 % 7 = 1, Possible modulos 1
  10^1 % 7 = 3, Possible modulos 1, 3, 1+3 = 4
  10^2 % 7 = 2, Possible modulos 1, 2, 3, 4, 3 + 2 = 5, 4 + 2 = 6
  10^3 % 7 = 6, Possible modulos 1, 2, 3, 4, 5, 6, (1 + 6) % 7 = 0

  The brilliant idea here is, if a number of the form 10^i1 + .. + 10^ik is
  a multiple of n, (10^i1 + .. + 10^ik) % n == 0, which also implies,
  (10^i1 % n + .. + 10^ik % n) % n == 0. Given these individual modulos, we
  need to find the smallest combination that adds to 0 (modulo n).

  1. We can compute individual modulos of each power of 10 with n.
  2. Then iterate over each power, and find all possible new modulos from old
     modulos, if they havent been formed, keep a list of powers used to get
     there.
  3. If we land on a 0, we have found the list of powers used, construct the
     number from it.

  Think of this as a breadth-first search of some sort.
*/
#define MAXN 100
string solve(int n) {
  string s;
  int t = 1, mod[MAXN];
  for (int i = 0; i < MAXN; i++) {
    mod[i] = t;
    t = (t * 10) % n;
  }
  map<int, vector<int> > pos;

  for (int i = 0; i < MAXN; i++) {
    bool found = false;

    std::map<int, vector<int> > temp;
    {
      int newNum = mod[i];
      if (pos.find(newNum) == pos.end()) {
          vector<int> me;
          me.push_back(i);
          temp[newNum] = me;
          if (newNum == 0) {
            found = true;
          }
      }
    }

    for (std::map<int, vector<int> >::iterator it = pos.begin(); it != pos.end(); it++) {
      int newNum = (it->first + mod[i]) % n;
      vector<int> existing = it->second;
      existing.push_back(i);

      if (pos.find(newNum) == pos.end()) {
        temp[newNum] = existing;
      }

      if (newNum == 0) {
        found = true;
        break;
      }
    }

    if (temp.size() > 0) {
      for (std::map<int, vector<int> >::iterator it = temp.begin(); it != temp.end(); it++) {
        pos[it->first] = it->second;
      }
    }

    if (found) {
      break;
    }
  }

  // Now the solution is basically at position 0
  vector<int> sol = pos[0];

  // Regular string setup to get the 0s and 1s.
  s.resize(sol[sol.size() - 1] + 1);
  for (int i = 0; i < s.size(); i++) {
    s[i] = '0';
  }

  for (int i = 0; i < sol.size(); i++) {
    s[sol[i]] = '1';
  }

  reverse(s.begin(), s.end());
  return s;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
