#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int a, b, c;
  scanf("%d%d", &a, &b);
  // printf("%d %d", b, a);  // fastest way

  // swap
  c = a;
  a = b;
  b = c;
  printf("%d %d", a, b);
  return 0;
}