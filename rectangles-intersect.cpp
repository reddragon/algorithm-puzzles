#include "util.h"

struct Point {
  float x, y;
};

struct Rectangle {
  // Top left corner, Bottom right corner.
  Point corners[2];
};

void normalize(Rectangle &r) {
  if (r.corners[1].x < r.corners[0].x) {
    swap(r.corners[0], r.corners[1]);
  }
}

void normalize(Rectangle &r1, Rectangle &r2) {
  normalize(r1);
  normalize(r2);
  if (r2.corners[0].x < r1.corners[0].x) {
    swap(r1, r2);
  }
}

bool doesIntersect(Rectangle r1, Rectangle r2) {
  normalize(r1, r2);
  if (r1.corners[0].y >= r2.corners[0].y) {
    if (r1.corners[1].x <= r2.corners[0].x) {
      return false;
    }
    if (r1.corners[1].y >= r2.corners[0].y) {
      return false;
    }
  } else {
    if (r1.corners[1].x <= r2.corners[0].x) {
      return false;
    }
    if (r1.corners[0].y <= r2.corners[1].y) {
      return false;
    }
  }
  return true;
}

int main() {
  {
    // One rectangle completely lies inside the other.
    Rectangle r1;
    r1.corners[0] = {0, 0};
    r1.corners[1] = {1, -1};

    Rectangle r2;
    r2.corners[0] = {0.5, -0.5};
    r2.corners[1] = {1, -1};
    EXPECT_EQ(true, doesIntersect(r1, r2));
  }

  {
    // One rectangle completely outside inside the other.
    Rectangle r1;
    r1.corners[0] = {0, 0};
    r1.corners[1] = {1, -1};

    Rectangle r2;
    r2.corners[0] = {1, -1};
    r2.corners[1] = {2, -2};
    EXPECT_EQ(false, doesIntersect(r1, r2));
  }

  {
    // One rectangle completely outside inside the other.
    Rectangle r1;
    r1.corners[0] = {0, 0};
    r1.corners[1] = {1, -1};

    Rectangle r2;
    r2.corners[0] = {1, 1};
    r2.corners[1] = {2, 0};
    EXPECT_EQ(false, doesIntersect(r1, r2));
  }

  {
    // One rectangle overlaps slightly.
    Rectangle r1;
    r1.corners[0] = {0, 0};
    r1.corners[1] = {1, -1};

    Rectangle r2;
    r2.corners[0] = {0.99, 1};
    r2.corners[1] = {2, -0.01};
    EXPECT_EQ(true, doesIntersect(r1, r2));
  }

  {
    // One rectangle overlaps slightly.
    Rectangle r1;
    r1.corners[0] = {0, 0};
    r1.corners[1] = {1, -1};

    Rectangle r2;
    r2.corners[0] = {0.99, -0.99};
    r2.corners[1] = {2, -2};
    EXPECT_EQ(true, doesIntersect(r1, r2));
  }
}
