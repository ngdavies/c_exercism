#include "armstrong_numbers.h"
#include <stdio.h>

int int_pow(int x, int y) {
  // Use my own integer power function
  int res = 1;
  if (x == 0 || y < 0) {
    res = 0;
  } else {
    for (int i=0; i<y; i++) {
      res *= x;
    }
  }
  return res;
}


bool is_armstrong_number(int candidate) {
  const int max_digits = 10;
  char digits[max_digits];
  size_t size = snprintf(digits, max_digits, "%d", candidate);
  int armstrong = 0;

  // An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
  for (size_t i = 0; i < size; i++) {
    int d = digits[i] - '0';
    armstrong += int_pow(d, size);
  }
  return candidate == armstrong;
}
