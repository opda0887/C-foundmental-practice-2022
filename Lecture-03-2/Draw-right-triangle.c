#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int type, much;
  scanf("%d %d", &type, &much);

  // according to the type to print " * "
  switch (type)
  {
  case 1:
    for (int i = much; i >= 1; i--)
    {
      for (int j = i; j >= 1; j--)
        printf("*");
      printf("\n");
    }
    break;
  case 2:
    for (int i = 0; i < much; i++)
    {
      for (int j = i; j >= 0; j--)
        printf("*");
      printf("\n");
    }
    break;
  case 3:
    for (int i = much; i >= 1; i--)
    {
      for (int j = much - i; j > 0; j--)
        printf(" ");
      for (int j = i; j >= 1; j--)
        printf("*");
      printf("\n");
    }
    break;
  case 4:
    for (int i = 0; i < much; i++)
    {
      for (int j = much - i; j > 1; j--)
        printf(" ");
      for (int j = i; j >= 0; j--)
        printf("*");
      printf("\n");
    }
    break;
  }

  return 0;
}

// #include <stdio.h>
//
// int main () {
//     int position, layer;
//     int i, j, k, temp = 0;
//     scanf("%d %d", &position, &layer);

//     temp = layer;

//     if (position == 1 || position == 3){
//     	if (position == 1){
//         	for (i = 0; i < layer; i++){
//             	for (j = temp; j>0; j--){
//                     printf("*");
//                 }
//                 temp--;
//                 printf("\n");
//             }
//         }else {
//             for (i = 0; i < layer; i++){
//             	for (k = layer - temp; k>0; k--){
//                     printf(" ");
//                 }
//                 for (j = temp; j>0; j--){
//                     printf("*");
//                 }
//                 temp--;
//                 printf("\n");
//             }
//         }
//     }else if (position == 2 || position == 4){
//         temp = 1;
//         if (position == 2){
//         	for (i = 0; i < layer; i++){
//             	for (j = 0; j<temp; j++){
//                     printf("*");
//                 }
//                 temp++;
//                 printf("\n");
//             }
//         }else {
//             for (i = 0; i < layer; i++){
//             	for (k = layer - temp; k>0; k--){
//                     printf(" ");
//                 }
//                 for (j = 0; j<temp; j++){
//                     printf("*");
//                 }
//                 temp++;
//                 printf("\n");
//             }
//         }
//     }

//     return 0;
// }