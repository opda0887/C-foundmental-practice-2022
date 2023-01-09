#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  long long int much, origin[100000], sum[100000];
  scanf("%llu", &much);

  for (int i = 0; i < much; i++)
    scanf("%llu", &origin[i]);

  sum[0] = origin[0]; // 前綴和第一項 == 原始第一項
  for (int i = 1; i < much; i++)
    sum[i] = sum[i - 1] + origin[i]; // 計算前綴和

  for (int i = 0; i < much; i++)
  {
    if (sum[i] % origin[i] == 0) // 若前綴和被整除
      printf("%llu %llu\n", sum[i], origin[i]);
  }

  return 0;
}

// #include<stdio.h>

// int main () {
//     long long int n, i;
//     long long int a[100000];
//     scanf("%lli", &n);
//     for (i=0; i<n; i++){
//         scanf("%lli", &a[i]);
//     }
//     long long int temp = a[0];
//     printf("%lli %lli", a[0], a[0]);

//     for (i=1; i<n; i++){
//         temp = temp + a[i];
//         if (temp % a[i] == 0){
//             printf("\n");
//             printf("%lli %lli", temp, a[i]);
//         }
//     }
//     return 0;
// }