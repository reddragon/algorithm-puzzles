#include "util.h"


// Given a list of ranges (broken into left and right co-ordinates), find their
// total intersection.
// Eg. [1,2] and [2,3] would not intersect.
// Eg. [1,2] and [1,3] have an overlap of 2 ([1,2]).
uint32_t intersection(vector<pair<int,int>> ranges) {
  uint32_t answer = 0, opened = 0;
  vector<pair<int,int>> events;
  for (const auto& r : ranges) {
    // events will contain the point, and 1 to signify the range has started,
    // and -1 to signify that the range has ended.
    events.push_back(make_pair(r.first, 1));
    events.push_back(make_pair(r.second, -1));
  }

  sort(events.begin(), events.end());

  for (int i = 0; i < events.size(); i++) {
    // All the ranges are open now.
    if (opened == ranges.size()) {
      // events[i] is definitely the closing of an existing range, since there
      // can't be any new ranges starting now, since opened == ranges.size()
      // already, and we haven't processed this new range.
      answer = events[i].first - events[i-1].first + 1;
      break;
    }
    opened += events[i].second;
  }
  return answer;
}

int main() {
  EXPECT_EQ(0, intersection({{1,2}, {3,4}}));
  EXPECT_EQ(2, intersection({{1,2}, {1,3}}));
  EXPECT_EQ(0, intersection({{1,2}, {1,3}, {4, 5}}));
  EXPECT_EQ(24, intersection({{1,100}, {20, 99}, {70, 95}, {60, 93}}));
}
