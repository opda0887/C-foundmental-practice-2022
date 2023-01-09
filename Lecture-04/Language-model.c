#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  double a[6];
  double answer;

  for (int i = 0; i < 5; i++)
    scanf("%lf", &a[i]);

  answer = a[0] * a[1] * a[2] * a[3] * a[4];

  printf("%.15lf", answer);

  return 0;
}

// #include<stdio.h>

// int main () {
//     double a1, a2, a3, a4, a5;
//     scanf("%lf %lf %lf %lf %lf", &a1, &a2, &a3, &a4, &a5);
//     printf("%.15f", a1 *a2 *a3 *a4 *a5);
//     return 0;
// }
