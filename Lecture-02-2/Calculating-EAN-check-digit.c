#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  unsigned long long EAN[15], a = 0, b = 0, answer = 0;
  unsigned long long code;
  scanf("%llu", &code);

  // put index into an array
  for (int i = 11; i >= 0; i--)
  {
    EAN[i] = code % 10;
    code /= 10;
  }

  for (int i = 1; i < 12; i += 2)
    a += EAN[i];

  for (int i = 0; i < 12; i += 2)
    b += EAN[i];

  // count part
  answer = a * 3 + b - 1;
  answer %= 10;
  answer = 9 - answer;
  printf("%llu", answer);

  return 0;
}

// #include<stdio.h>

// int main(void){
//     long long int num;
//     scanf("%lli", &num);
//     int a=0, b=0, i;
//     for (i=1; i<=12; i++) {
//         if (i%2 == 1) {
//             a = a + num%10;
//         }else {
//             b = b + num%10;
//         }
//         num = num/10;
//     }
//     int x, y, z;
//     x = a * 3 + b;
//     y = x - 1;
//     z = 9 - y % 10;
//     printf("%d", z);
//     return 0;
// }