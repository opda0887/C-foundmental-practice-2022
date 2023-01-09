#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int N, len = 0;
  scanf("%d\n", &N);

  char text[100000];
  fgets(text, 100000, stdin);
  len = strlen(text) - 1;

  for (int i = 0; i < len; i++)
  {
    if (i == 0) // 第一個字時無條件轉成大寫
    {
      if (text[i] >= 97 && text[i] <= 122)
        printf("%c", text[i] - 32);
      else
        printf("%c", text[i]);
      continue;
    }

    // 其他字：

    // 遇到標點符號後一律換行
    if (text[i] == ';' || text[i] == ',' || text[i] == '.')
      printf("\n");
    // 空白、標點符號後一律轉大寫
    else if (text[i - 1] == ' ' || text[i - 1] == ';' || text[i - 1] == ',' || text[i - 1] == '.')
    {
      if (text[i] >= 97 && text[i] <= 122)
        printf("%c", text[i] - 32);
      else
        printf("%c", text[i]);
    }
    // 遇到空白一律印出
    else if (text[i] == ' ')
      printf(" ");
    else
    {
      if (text[i] >= 65 && text[i] <= 90)
        printf("%c", text[i] + 32);
      else
        printf("%c", text[i]);
    }
  }

  return 0;
}

// #include<stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main () {
//     int a, i, temp;
//     int count = 1;
//     char text[100000];
//     scanf("%d\n", &a);

//     fgets(text, 4096, stdin);

//     printf("%c", toupper(text[0]));

//     for (i=1; i<strlen(text); i++){
//         temp = (int)text[i-1];
//         if ( temp == 32 || temp == 59 || temp == 46 || temp == 44){
//             if (temp == 59 || temp == 46 || temp == 44 && a>0){
//                 a--;
//                 printf("\n");
//             }
//             if (a==0) {
//                 if (count == 1){
//                     count--;
//                 }else {
//                     printf(" ");
//                 }
//             }
//             printf("%c", toupper(text[i]));
//         }else {
//             if ((int)text[i] != 59 && (int)text[i] != 46 && (int)text[i] != 44){
//                 printf("%c", tolower(text[i]));
//             }
//         }
//     }
// }