#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void)
{
  int grid[NUM][NUM]; // sudoku puzzle
  for (int i = 0; i < NUM; ++i)
  {
    for (int j = 0; j < NUM; ++j)
    {
      scanf("%d", &grid[i][j]);
    }
  }
  check_sudoku(grid);
  return 0;
}

// 檢查不符合的點，並將它印出 (找有重複數字的點即可)
void check_sudoku(int (*grid_p)[NUM])
{
  int sum = 0;
  int *p = grid_p;
  for (p; p <= &grid_p[NUM - 1][NUM - 1]; p++)
  {
    int noProblem = 0;
    int pRow = sum / 9; // 當前的列
    int pCol = sum % 9; // 當前的行
    sum++;
    int *point = &grid_p[pRow][pCol]; // 目標點

    // 檢查橫排
    int i = 0;
    for (&grid_p[pRow][i]; &grid_p[pRow][i] <= &grid_p[pRow][NUM - 1]; i++)
    {
      if (i != pCol && *point == *&grid_p[pRow][i])
      {
        noProblem = 1;
        break;
      }
    }
    // 確認
    if (noProblem == 1)
    {
      printf("(%d,%d)\n", pRow, pCol);
      continue;
    }

    // 檢查直排
    i = 0;
    for (&grid_p[i][pCol]; &grid_p[i][pCol] <= &grid_p[NUM - 1][pCol]; i++)
    {
      if (i != pRow && *point == *&grid_p[i][pCol])
      {
        noProblem = 1;
        break;
      }
    }
    // 確認
    if (noProblem == 1)
    {
      printf("(%d,%d)\n", pRow, pCol);
      continue;
    }
    // 檢查9宮格
    // 1. 找到該9宮格的最左上角的點位置
    int spRow = (pRow / 3) * 3;
    int spCol = (pCol / 3) * 3;
    i = 0;
    for (&grid_p[spRow + i][spCol]; &grid_p[spRow + i][spCol] <= &grid_p[spRow + 2][spCol]; i++)
    {
      for (int j = 0; j <= 2; j++)
      {
        if (spRow + i != pRow && spCol + j != pCol && *point == *&grid_p[spRow + i][spCol + j])
        {
          noProblem = 1;
          break;
        }
      }
      if (noProblem == 1)
        break;
    }
    // 確認
    if (noProblem == 1)
    {
      printf("(%d,%d)\n", pRow, pCol);
      continue;
    }
  }
}