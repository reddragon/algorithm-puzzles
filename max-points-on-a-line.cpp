/**
 * Given n points on a 2-D plane, find the maximum number of points that lie
 * on the same line.
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Fraction {
  int numerator, denominator;

  bool operator ==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
  }
};

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  if (b > a) {
    return gcd(b, a);
  }
  return gcd(b, a % b);
}

Fraction getFraction(int numerator, int denominator) {
  if (numerator < 0 && denominator < 0) {
    numerator *= -1;
    denominator *= -1;
  }

  Fraction f;
  int d = gcd(abs(numerator), abs(denominator));
  d = (d != 0 ? d : 1);
  f.numerator = numerator / d;
  f.denominator = denominator / d;
  return f;
}

struct Point {
  int x, y;

  bool operator ==(const Point& other) const {
    return x == other.x && y == other.y;
  }
};

struct Line {
  Fraction slope, intercept;

  bool operator ==(const Line& other) const {
    return slope == other.slope && intercept == other.intercept;
  }
};

// Hash functions below are terrible. Don't use for production.
namespace std {
  template<>
  struct hash<Line> {
    std::size_t operator() (const Line& l) const {
      return (hash<int>()(l.slope.numerator) + hash<int>()(l.slope.denominator)
        + hash<int>()(l.intercept.numerator) + hash<int>()(l.slope.denominator));
    }
  };

  template<>
  struct hash<Point> {
    std::size_t operator() (const Point& p) const {
      return (hash<int>()(p.x) + hash<int>()(p.y));
    }
  };
}

Line getLine(Point a, Point b) {
  Line l;
  l.slope = getFraction(a.y - b.y, a.x - b.x);
  l.intercept =
      getFraction((a.y * l.slope.denominator) - (a.x * l.slope.numerator),
                  l.slope.denominator);
  return l;
}

// Compute the slope and intercept for all possible lines. Max O(n^2).
// Create a map, line -> set of points on that line.
// Count the largest such set.
int getMaxPoints(vector<Point> points) {
  size_t maxPoints = 0;
  unordered_map<Line, unordered_set<Point>> m;
  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      Line l = getLine(points[i], points[j]);
      m[l].insert(points[i]);
      m[l].insert(points[j]);
      maxPoints = std::max(maxPoints, m[l].size());
    }
  }
  return maxPoints;
}

int main() {
  assert(getMaxPoints({{0, 0}, {1, 1}}) == 2);
  assert(getMaxPoints({{0, 0}, {1, 1}, {2, 2}}) == 3);
  assert(getMaxPoints({{0, 0}, {1, 1}, {2, 2}, {2, 4}}) == 3);
  assert(getMaxPoints({{0, 0}, {1, 1}, {2, 2}, {2, 4}, {2, 6}}) == 3);
  assert(getMaxPoints({{0, 0}, {1, 1}, {2, 2}, {2, 4}, {2, 6}, {2, 8}}) == 4);
}
