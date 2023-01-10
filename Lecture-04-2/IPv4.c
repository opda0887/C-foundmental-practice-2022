#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convert(char x);

int main()
{
  /* code start */
  char p[1000];
  scanf("%s", p);

  int ans = 0;
  ans = convert(p[0]) * 16 + convert(p[1]);
  printf("%d.", ans);

  ans = convert(p[2]) * 16 + convert(p[3]);
  printf("%d.", ans);

  ans = convert(p[4]) * 16 + convert(p[5]);
  printf("%d.", ans);

  ans = convert(p[6]) * 16 + convert(p[7]);
  printf("%d", ans);

  return 0;
}

int convert(char x)
{
  if (x >= 48 && x <= 57)
    return x - 48;
  else if (x >= 97 && x <= 102)
    return x - 87;
}

// #include<stdio.h>

// int main () {
//      int first = 0;
//      int second = 0;
//      int count = 3;
//      int ans = 0;
//      char nums[9];
//      fgets(nums, 9, stdin);
//      for (int i = 0; i < 8; i += 2){
//           first = (int)nums[i];
//           second = (int)nums[i+1];

//           if (first<=102 && first>=97){
//                first = first - 87;
//           }else if (first<=57 && first>=48){
//                first = first - 48;
//           }

//           if (second<=102 && second>=97){
//                second = second- 87;
//           }else if (second<=57 && second>=48){
//                second = second - 48;
//           }

//           ans = first * 16 + second;

//           printf("%d", ans);
//           if (count != 0){
//                count--;
//                printf(".");
//           }

//     }
// }