#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
      if (isPrime(i)) count++;
    }
    return count;
  }

  bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) return false;
    }
    return true;
  }
};

// interesting: the Sieve of Eratosthenes
class Solution2 {
 public:
  int countPrimes(int n) {
    bool* isPrime = new bool[n];
    for (int i = 2; i < n; i++) {
      isPrime[i] = true;
    }
    // Loop's ending condition is i * i < n instead of i < sqrt(n)
    // to avoid repeatedly calling an expensive function sqrt().
    for (int i = 2; i * i < n; i++) {
      if (!isPrime[i]) continue;
      for (int j = i * i; j < n; j += i) {
        isPrime[j] = false;
      }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime[i]) count++;
    }
    return count;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}