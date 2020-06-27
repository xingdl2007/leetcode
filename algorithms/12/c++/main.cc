#include <cassert>
#include <deque>

#include <iostream>

using namespace std;

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.

// 1 to 3999

class Solution {
public:
  // 0 <= i < 10
  string numbers(int i) {
    if (0 <= i && i < 4) {
      return string(i / 1, 'I');
    }
    if (4 < i && i < 9) {
      return "V" + string(i - 5, 'I');
    }
    if (i == 4) {
      return "IV";
    }
    if (i == 9) {
      return "IX";
    }
    return "";
  }

  // 10 <= i < 100
  string tens(int i) {
    if ((10 <= i && i < 40)) {
      return string(i / 10, 'X');
    }

    if (40 < i && i < 90) {
      return "L" + string((i - 50) / 10, 'X');
    }
    if (i == 40) {
      return "XL";
    }
    if (i == 90) {
      return "XC";
    }
    return "";
  }

  // 100 <= i < 1000
  string hundreds(int i) {
    if (100 <= i && i < 400) {
      return string(i / 100, 'C');
    }
    if (400 < i && i < 900) {
      return "D" + string((i - 500) / 100, 'C');
    }
    if (i == 400) {
      return "CD";
    }
    if (i == 900) {
      return "CM";
    }
    return "";
  }

  // 1000 <= i < 10000
  string thousands(int i) {
    if (1000 <= i < 4000) {
      return string(i / 1000, 'M');
    }
    return "";
  }

  string convert(int i) {
    if (0 <= i && i < 10)
      return numbers(i);
    if (10 <= i && i < 100)
      return tens(i);
    if (100 <= i && i < 1000)
      return hundreds(i);
    else
      return thousands(i);
  }

  string intToRoman(int num) {
    int i = 1;
    string str;
    while (num) {
      str = convert(num % 10 * i) + str;
      num = num / 10;
      i *= 10;
    }
    return str;
  }
};

int main(int argc, char *argv[]) {
  Solution so;

  std::cout << so.intToRoman(1) << std::endl;
  std::cout << so.intToRoman(3) << std::endl;
  std::cout << so.intToRoman(4) << std::endl;
  std::cout << so.intToRoman(9) << std::endl;
  std::cout << so.intToRoman(58) << std::endl;
  std::cout << so.intToRoman(60) << std::endl;
  std::cout << so.intToRoman(600) << std::endl;
  std::cout << so.intToRoman(1994) << std::endl;

  assert(so.intToRoman(3) == "III");
  assert(so.intToRoman(4) == "IV");
  assert(so.intToRoman(9) == "IX");
  assert(so.intToRoman(58) == "LVIII");
  assert(so.intToRoman(1994) == "MCMXCIV");

  return 0;
}