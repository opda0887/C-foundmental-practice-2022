#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  // 𝟕𝐱⁴ - 𝟖𝐱³ - 𝐱² + 𝟔𝐱 - 𝟐𝟐

  float x;
  scanf("%f", &x);

  printf("%.1f", 7 * x * x * x * x - 8 * x * x * x - x * x + 6 * x - 22);
  return 0;
}