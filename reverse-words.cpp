// Reverse words of a string.
// "abc def" => "def abc"
// "alice bob charlie" => "charlie bob alice"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Have two solutions here.

// Separate by separator, and join them in the reverse order.
string solve1(string s) {
  vector<string> vs;
  string tmp;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ') tmp.push_back(s[i]);
    else {
      vs.push_back(tmp);
      tmp = "";
    }
  }
  if (tmp != "") {
    vs.push_back(tmp);
  }
  reverse(vs.begin(), vs.end());
  string ret;
  for (int i = 0; i < vs.size(); i++) {
    ret += vs[i];
    if (i + 1 < vs.size()) ret += " ";
  }
  return ret;
}

// Reverse it overall once, reverse individual words then. In-place solution.
string solve2(string s) {
  reverse(s.begin(), s.end());
  int i = 0, prev_space = 0;
  while (i < s.size()) {
    while (i < s.size() && s[i] != ' ') {
      i++;
    }
    reverse(s.begin() + prev_space, s.begin() + i);
    i++;
    prev_space = i;
  }
  return s;
}

int main() {
  char buf[1000];
  string s;
  cin.getline(buf, 100);
  s = (string)buf;
  cout << solve1(s) << endl;
  cout << solve2(s) << endl;
  return 0;
}
