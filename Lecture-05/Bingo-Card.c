#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ROW 8
#define COLUMN 8

int main()
{
  /* code start */
  int bingo[10][10], check[70];
  int count = 0;
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COLUMN; j++)
      scanf("%d", &bingo[i][j]);
  }

  for (int i = 0; i < 64; i++)
    scanf("%d", &check[i]);

  // Find all the same part
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COLUMN; j++)
    {
      for (int k = 0; k < 64; k++)
      {
        if (bingo[i][j] == check[k])
          bingo[i][j] = 0;
      }
    }
  }

  // Check the row line
  for (int i = 0; i < ROW; i++)
  {
    int check = 1;
    for (int j = 0; j < COLUMN; j++)
    {
      if (bingo[i][j] != 0)
      {
        check = 0;
        break;
      }
    }
    if (check == 1)
      count++;
  }

  // Check the colum line
  for (int i = 0; i < COLUMN; i++)
  {
    int check = 1;
    for (int j = 0; j < ROW; j++)
    {
      if (bingo[j][i] != 0)
      {
        check = 0;
        break;
      }
    }
    if (check == 1)
      count++;
  }

  // Check diagonal
  if (bingo[0][0] == bingo[1][1] && bingo[1][1] == bingo[2][2] && bingo[2][2] == bingo[3][3] && bingo[3][3] == bingo[4][4] && bingo[4][4] == bingo[5][5] && bingo[5][5] == bingo[6][6] && bingo[6][6] == bingo[7][7])
  {
    count++;
  }
  if (bingo[0][7] == bingo[1][6] && bingo[1][6] == bingo[2][5] && bingo[2][5] == bingo[3][4] && bingo[3][4] == bingo[4][3] && bingo[4][3] == bingo[5][2] && bingo[5][2] == bingo[6][1] && bingo[6][1] == bingo[7][0])
  {
    count++;
  }

  printf("%d", count);

  return 0;
}

// #include <stdio.h>
// #define ROW 8
// #define COLUMN 8

// int main()
// {
//   int card[ROW][COLUMN];
//   int correct[70];
//   int line = 0;
//   for (int i = 0; i < ROW; i++)
//   {
//     for (int j = 0; j < COLUMN; j++)
//     {
//       scanf("%d", &card[i][j]);
//     }
//   }

//   for (int i = 0; i < 64; i++)
//   {
//     scanf("%d", &correct[i]);
//   }

//   // same to 0
//   for (int i = 0; i < ROW; i++)
//   {
//     for (int j = 0; j < COLUMN; j++)
//     {
//       for (int k = 0; k < 64; k++)
//       {
//         if (card[i][j] == correct[k])
//         {
//           card[i][j] = 0;
//           break;
//         }
//       }
//     }
//   }

//   /*
//     for (int i = 0; i < ROW; i++)
//     {
//       for (int j = 0; j < COLUMN; j++)
//       {
//         printf("%d ", card[i][j]);
//       }
//       printf("\n");
//     }
//   */

//   // check row line
//   for (int i = 0; i < ROW; i++)
//   {
//     for (int j = 0; j < COLUMN; j++)
//     {
//       if (card[i][j] != 0)
//       {
//         break;
//       }
//       else if (j == 7)
//       {
//         line++;
//       }
//     }
//   }

//   // check column line
//   for (int i = 0; i < COLUMN; i++)
//   {
//     for (int j = 0; j < ROW; j++)
//     {
//       if (card[j][i] != 0)
//       {
//         break;
//       }
//       else if (j == 7)
//       {
//         line++;
//       }
//     }
//   }

//   // check cross line
//   if (card[0][0] == card[1][1] && card[1][1] == card[2][2] && card[2][2] == card[3][3] && card[3][3] == card[4][4] && card[4][4] == card[5][5] && card[5][5] == card[6][6] && card[6][6] == card[7][7])
//   {
//     line++;
//   }
//   if (card[0][7] == card[1][6] && card[1][6] == card[2][5] && card[2][5] == card[3][4] && card[3][4] == card[4][3] && card[4][3] == card[5][2] && card[5][2] == card[6][1] && card[6][1] == card[7][0])
//   {
//     line++;
//   }

//   printf("%d", line);
// }