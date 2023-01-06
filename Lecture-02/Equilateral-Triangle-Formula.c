#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int length;
  scanf("%d", &length);

  printf("%.3f", length * length * 1.7320508 / 4);
  return 0;
}