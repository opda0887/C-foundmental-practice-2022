#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  unsigned int a, a_tot[5], temp;
  unsigned int d1, d2, d3, d4;
  scanf("%u", &a);
  scanf("%u%u%u%u", &d1, &d2, &d3, &d4);

  a_tot[1] = a >> 24;
  a_tot[2] = a << 8 >> 24;
  a_tot[3] = a << 16 >> 24;
  a_tot[4] = a << 24 >> 24;

  // Step 2
  temp = a_tot[d1] ^ a_tot[d2];
  temp = temp << 8;

  // Step 3
  temp += a_tot[d2] & a_tot[d3];
  temp = temp << 8;

  // Step 4
  temp += a_tot[d3] | a_tot[d1];
  temp = temp << 8;

  // Step 5
  temp += (~a_tot[d4] << 24 >> 24);

  // Step 6
  unsigned int move, temp1, temp2;
  move = (d1 + d2 + d3 + d4) % 32;
  temp2 = temp << (32 - move);
  temp1 = temp >> move;
  temp = temp2 + temp1;

  // Step 7
  temp1 = temp >> 16;       // Upper 16
  temp2 = temp << 16 >> 16; // Lower 16
  printf("%u", temp1 ^ temp2);

  return 0;
}

// #include <stdio.h>

// int main () {
//     unsigned int temp = 0x00000000;
//     unsigned int N;
//     unsigned int d1, d2, d3, d4;
//     unsigned int th1,th2, th3, th4;

//     scanf("%d", &N);
//     scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

// 	unsigned int a = N - 0x00000000;

//     switch (d1){
//         case 1:
//             th1 = a >> 24;
//             break;
//         case 2:
//             th1 = a << 8;
//             th1 = th1 >> 24;
//             break;
//         case 3:
//             th1 = a << 16;
//             th1 = th1 >> 24;
//             break;
//         case 4:
//             th1 = a << 24;
//             th1 = th1 >> 24;
//             break;
//     }

//     switch (d2){
//         case 1:
//             th2 = a >> 24;
//             break;
//         case 2:
//             th2 = a << 8;
//             th2 = th2 >> 24;
//             break;
//         case 3:
//             th2 = a << 16;
//             th2 = th2 >> 24;
//             break;
//         case 4:
//             th2 = a << 24;
//             th2 = th2 >> 24;
//             break;
//     }

// 	switch (d3){
//         case 1:
//             th3 = a >> 24;
//             break;
//         case 2:
//             th3 = a << 8;
//             th3 = th3 >> 24;
//             break;
//         case 3:
//             th3 = a << 16;
//             th3 = th3 >> 24;
//             break;
//         case 4:
//             th3 = a << 24;
//             th3 = th3 >> 24;
//             break;
//     }

// 	switch (d4){
//         case 1:
//             th4 = a >> 24;
//             break;
//         case 2:
//             th4 = a << 8;
//             th4 = th4 >> 24;
//             break;
//         case 3:
//             th4 = a << 16;
//             th4 = th4 >> 24;
//             break;
//         case 4:
//             th4 = a << 24;
//             th4 = th4 >> 24;
//             break;
//     }

//     unsigned int th5;
//     // th1 th2 XOR
//     th5 = th1 ^ th2;
//     temp = temp | th5;
//     temp = temp << 8;

//     // th2 th3 AND
//     th2 = th2 & th3;
//     temp = temp | th2;
//     temp = temp << 8;

//     // th3 th1 OR
//     th3 = th3 | th1;
//     temp = temp | th3;
//     temp = temp << 8;

//     // th4 to temp
//     th4 = ~th4;
//     th4 = th4 << 24;
//     th4 = th4 >> 24;
//     temp = temp | th4;

//     // rotate
//     unsigned int first, second;
//     unsigned int rotate = (d1 + d2 + d3 + d4) % 32;
//     if (rotate != 0){
//         first = temp << (32-rotate);
//         second = temp >> rotate;
//         temp = first | second;
//     }

//     // last step
//     unsigned int ans;
//     first = temp >> 16;
//     second = temp << 16;
//     second = second >> 16;
//     ans = first ^ second;
//     ans = ans - 0;

//     //printf("%lx %lx %lx %lx\n", th1, th2, th3, th4);
//     printf("%d", ans);
//     return 0;
// }