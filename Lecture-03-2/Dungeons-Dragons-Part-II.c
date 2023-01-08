#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int player_Hp = 100, dragon_Hp = 100;
  int d[7], who_win = 0;

  while (player_Hp > 0 && dragon_Hp > 0) // one Hp to 0, end
  {
    for (int i = 1; i <= 6; i++)
      scanf("%d", &d[i]);

    who_win = (d[1] + d[2] + d[3]) % 2; // odd: 1

    if (who_win) // player attack
    {
      if (d[6] >= d[5] && d[5] >= d[4])
        dragon_Hp -= 25;
      else if (d[4] / 2 == d[5] / 2 || d[5] / 2 == d[6] / 2)
        dragon_Hp -= 5;
    }
    else // dragon attack
    {
      if (abs(d[5] - d[4]) >= d[6])
        player_Hp -= 15;
      else if (d[4] + d[5] != d[6])
        player_Hp -= 5;
    }
  }

  if (player_Hp <= 0)
    printf("Dragon wins");
  else if (dragon_Hp <= 0)
    printf("Player wins");

  return 0;
}

// #include <stdio.h>
// #include<math.h>

// int main () {
//     int perHp = 100;
//     int dragHp = 100;
//     int d1, d2, d3, d4, d5, d6;

//     while (scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6)){

//         if (perHp <=0 || dragHp <=0){
//             break;
//         }

//         if ((d1+d2+d3) % 2 == 1){
//             // Player attack
//             if(d4 <= d5 && d5 <= d6){
//                 dragHp = dragHp - 25;
//             }else if ( d4/2 == d5/2 || d5/2 == d6/2 ){
//                 dragHp = dragHp - 5;
//             }else {
//                 dragHp = dragHp;
//             }

//         }else {
//             // Dragon attack
//             if (abs(d5 - d4) > d6){
//                 perHp = perHp - 15;
//             }else if (d4 + d5 != d6){
//                 perHp = perHp - 5;
//             }else {
//                 perHp = perHp;
//             }

//         }
//     }

//     if (perHp <= 0){
//     	printf("Dragon wins");
//     }else if (dragHp <= 0){
//     	printf("Player wins");
//     }

//     return 0;
// }