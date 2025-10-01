/*
 * resolve the x^n
 */

// time complexity is O(n)
class Solution1 {
public:
  int calcPowerOfN(int x, int N) {
    int res = 1;
    for (int i = 1; i <= N; ++i) {
      res = res * x;
    }
    return res;
  }
};

// time complexity is also O(n), since the recursive count is n. And every
// function with the O(1) complexity
class Solution2 {
public:
  int calcPowerOfN(int x, int N) {
    if (N == 0) {
      return 1;
    }
    return calcPowerOfN(x, N - 1) * x;
  }
};

// draw a binary tree and node is O(n) with the tree height as log(n), so the
// node number is O(n)`
class Solution3 {
public:
  int calcPowerOfN(int x, int N) {
    if (N == 0) {
      return 1;
    }
    if (N == 1) {
      return x;
    }
    if (N % 2) {
      return calcPowerOfN(x, N / 2) * calcPowerOfN(x, N / 2) * x;
    }
    return calcPowerOfN(x, N / 2) * calcPowerOfN(x, N / 2);
  }
};

// the tree height is O(logN) and only nedd to O(1) time to process
class Solution4 {
public:
  int calcPowerOfN(int x, int N) {
    if (N == 0) {
      return 1;
    }
    if (N == 1) {
      return x;
    }
    int res = calcPowerOfN(x, N / 2);
    if (N % 2) {
      return res * res * x;
    }
    return res * res;
  }
};