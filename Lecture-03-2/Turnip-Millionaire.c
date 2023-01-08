#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  float x, index = 0.0;
  scanf("%f", &x);

  //   h{t+1} = w * x{t} + u * h{t} + b
  //   y{t+1} = f(u' * h{t+1} + b')
  // (w, u, b, u', b') = (0.9, 0.1, -51, -0.98, 153)
  for (int i = 0; i < 5; i++)
  {
    index = 0.9 * x + 0.1 * index - 51;
    x = -0.98 * index + 153;
    printf("%.1f ", x);
  }

  return 0;
}

// #include<stdio.h>

// int main () {
//     float todayPrice;
//     scanf("%f", &todayPrice);

//     float ht = 0;
//     float yt = 0;
//     float temp;
//     for (int i = 0; i<5; i++){
//     	ht = 0.9 * todayPrice + 0.1 * ht - 51;
//         yt = -0.98 * ht + 153;
//         printf("%.1f ", yt);
//         todayPrice = yt;
//     }

//     return 0;
// }
