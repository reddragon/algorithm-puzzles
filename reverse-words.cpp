// Reverse words of a string.
// "abc def" => "def abc"
// "alice bob charlie" => "charlie bob alice"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// Have multiple solutions here.

// Separate by separator, and join them in the reverse order.
string solve1(string s) {
  vector<string> vs;
  string tmp;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ')
      tmp.push_back(s[i]);
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
    if (i + 1 < vs.size())
      ret += " ";
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

// Assumes a single space between words.
string solve3(string s) {
  istringstream iss(s);
  vector<string> vs;
  string temp;
  while (iss >> temp) {
    vs.push_back(temp);
  }

  string ret;
  for (int i = vs.size() - 1; i >= 0; i--) {
    ret += vs[i];
    if (i >= 0) {
      ret += " ";
    }
  }
  return ret;
}

// Just search for the space, and do something like solve2.
string solve4(string s) {
  int prev_pos = 0, find_from = 0;
  reverse(s.begin(), s.end());
  while (true) {
    if (s[find_from] == ' ') {
      find_from++;
      continue;
    }

    size_t pos = s.find(" ", find_from);
    if (pos == string::npos) {
      break;
    }
    reverse(s.begin() + find_from, s.begin() + pos);
    find_from = pos;
  }
  reverse(s.begin() + find_from, s.end());
  return s;
}

int main() {
  char buf[1000];
  string s;
  cin.getline(buf, 100);
  s = (string)buf;
  cout << solve1(s) << endl;
  cout << solve2(s) << endl;
  cout << solve3(s) << endl;
  cout << solve4(s) << endl;
  return 0;
}
