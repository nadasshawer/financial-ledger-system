#include <stdio.h>

int add(int left, int right) {
  printf("Adding %d and %d from C++ layer \n", left, right);
  return left + right;
}