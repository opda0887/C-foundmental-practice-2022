#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  float h, w;
  scanf("%f%f", &h, &w);

  h = h / 100;

  printf("%.6f", w / (h * h));

  return 0;
}