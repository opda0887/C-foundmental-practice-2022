#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define AMERICANO 110
#define LATTE 150
#define CAPPUCCINO 135
#define MOCHA 145

int main()
{
  /* code start */
  int type, much;
  scanf("%d%d", &type, &much);

  switch (type)
  {
  case 1:
    printf("The total price is %d dollars!", much * AMERICANO);
    break;
  case 2:
    printf("The total price is %d dollars!", much * LATTE);
    break;
  case 3:
    printf("The total price is %d dollars!", much * CAPPUCCINO);
    break;
  case 4:
    printf("The total price is %d dollars!", much * MOCHA);
    break;
  default:
    printf("Wait, what?");
    break;
  }

  return 0;
}

// #include <stdio.h>
// #define AMERICANO  110
// #define LATTE      150
// #define CAPPUCCINO 135
// #define MOCHA      145

// int main() {
// 	int i, j;
//     scanf("%d %d", &i, &j);

//     switch (i)
//     {
//     case 1:
//         printf("The total price is %d dollars!", 110*j);
//         break;
//     case 2:
//         printf("The total price is %d dollars!", 150*j);
//         break;
//     case 3:
//         printf("The total price is %d dollars!", 135*j);
//         break;
//     case 4:
//         printf("The total price is %d dollars!", 145*j);
//         break;
//     default:
//         printf("Wait, what?");
//         break;
//     }

//     return 0;
// }