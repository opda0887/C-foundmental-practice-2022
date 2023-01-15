#include <stdio.h>
#include <stdlib.h>
int array[1500];
int maxChandy(int size);
int main()
{
  int size = 0;
  scanf("%d", &size);
  for (int i = 0; i < size; ++i)
  {
    scanf("%d", &array[i]);
  }
  printf("%d\n", maxChandy(size));
  return 0;
}

int max(int a, int b)
{
  if (a >= b)
    return a;
  return b;
}

int maxChandy(int size)
{
  // 設定一個 array來儲存資料
  int memo[1500];
  // 初始設定 memo[0] memo[1]
  memo[0] = array[0];
  memo[1] = max(memo[0], array[1]);

  for (int i = 2; i < size; i++) // 從2位置開始
    memo[i] = max(memo[i - 1], memo[i - 2] + array[i]);

  return memo[size - 1];
}