#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N, count = 0;
int items[50][50];
int needNum[50];

int do_add(int items[][50], int i);

int main()
{
  /* code start */
  scanf("%d\n", &N);
  int much = 0;
  for (int i = 1; i <= N; i++)
  {
    scanf("%d\n", &much);

    if (much == 0)
      needNum[i] = 1;
    else
      needNum[i] = much;

    if (much != 0)
    {
      for (int j = 0; j < much; j++)
        scanf("%d", &items[i][j]);
    }
    else
      items[i][0] = 100; // mark the resource
  }

  for (int i = 1; i <= N; i++)
    count += do_add(items, i);

  printf("%d\n", count);
  return 0;
}

int do_add(int items[][50], int i)
{
  int temp = 0;
  for (int j = 0; j < needNum[i]; j++)
  {
    if (items[i][j] == 100)
      return 1;
    else
      temp += do_add(items, items[i][j]);
  }
  return temp;
}

// #include <stdio.h>
// int needNum[30];
// int metrial[30][30];
// int N;

// int sum(int proudct[][30], int i);

// int main()
// {
//   scanf("%d", &N);

//   for (int i = 1; i <= N; i++)
//   {
//     scanf("%d", &needNum[i]);
//     if (needNum[i] == 0)
//     {
//       metrial[i][0] = 100;
//       needNum[i] = 1;
//     }
//     else
//     {
//       for (int j = 0; j < needNum[i]; j++)
//       {
//         scanf("%d", &metrial[i][j]);
//       }
//     }
//   }

//   int total[30] = {0};
//   for (int i = 1; i <= N; i++)
//   {
//     total[i] = sum(metrial, i);
//   }

//   // printf("-----------------------\n");
//   int totalSum = 0;
//   for (int i = 1; i <= N; i++)
//   {
//     totalSum += total[i];
//   }
//   printf("%d", totalSum);

//   return 0;
// }

// int sum(int product[][30], int i)
// {
//   int temp = 0;
//   for (int j = 0; j < needNum[i]; j++)
//   {
//     if (product[i][j] == 100)
//     {
//       return 1;
//     }
//     else
//     {
//       temp += sum(product, product[i][j]);
//     }
//   }
//   return temp;
// }