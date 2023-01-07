#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int d[10], who_attack;
  for (int i = 1; i <= 6; i++)
    scanf("%d", &d[i]);

  who_attack = d[1] + d[2] + d[3];

  if (who_attack <= 10) // player attack
  {
    if (d[4] == d[5] && d[5] == d[6])
      printf("Player attacks: Critical Hit");
    else if (d[4] + d[5] >= d[6])
      printf("Player attacks: Normal Hit");
    else
      printf("Player attacks: Miss");
  }
  else // drangon attack
  {
    if (d[4] == d[5] || d[5] == d[6] || d[4] == d[6])
      printf("Dragon attacks: Miss");
    else if (d[4] + d[5] != d[6])
      printf("Dragon attacks: Normal Hit");
    else
      printf("Dragon attacks: Critical Hit");
  }
  return 0;
}

// #include<stdio.h>

// int main () {
//     int d1, d2, d3, d4, d5, d6;
//     scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);

//     if (d1+d2+d3 <= 10) {
//         // Player attack
//         if (d4 == d5 && d5 == d6) {
//             printf("%s", "Player attacks: Critical Hit");
//         }else if (d4+d5 >= d6) {
//             printf("%s", "Player attacks: Normal Hit");
//         }else {
//             printf("%s", "Player attacks: Miss");
//         }

//     }else {
//         // Dragon attack
//         if (d4 == d5 || d4 == d6 || d5 == d6) {
//             printf("%s", "Dragon attacks: Miss");
//         }else if (d4+d5 != d6) {
//             printf("%s", "Dragon attacks: Normal Hit");
//         }else {
//             printf("%s", "Dragon attacks: Critical Hit");
//         }
//     }

//     return 0;
// }