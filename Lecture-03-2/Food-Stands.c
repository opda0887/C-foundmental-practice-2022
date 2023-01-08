#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  unsigned int stands[1000], index = 0, max = 0, min = 2147483648;
  while (scanf("%u", &stands[index]))
  {
    if (stands[index] == -1)
      break;
    index++;
  }

  // find the maximum and minimum
  for (int i = 0; i < index; i++)
  {
    if (max < stands[i])
      max = stands[i];
    if (min > stands[i])
      min = stands[i];
  }

  // print the shortest distance
  printf("%d", max - min);

  return 0;
}

// #include<stdio.h>

// int main () {
//     int c[100];
//     int i = 0, target = 0;
//     int max = 0, min = 0;

//     for (i; i<100; i++) {
//         scanf("%d", &c[i]);
//         if (c[i] == -1) {
//         	target = i + 1;
//             break;
//         }
//     }

//     max = c[0];
//     min = c[0];

//     if (target == 2){
//     	return 0;
//     }

//     for (i=1; i<target; i++) {
//     	if (c[i] != -1) {
//             if (min > c[i]) {
//             	min = c[i];
//             }else if (max < c[i]) {
//             	max = c[i];
//             }
//         }
//     }

//     printf("%d", max - min);

//     return 0;
// }
