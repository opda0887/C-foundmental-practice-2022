#include <stdio.h>
#include <math.h>

int main()
{
  int N;
  char players[1050];
  char judge[11];
  scanf("%d", &N);
  scanf("%s", &players);
  scanf("%s", &judge);

  // 計算比賽輪數
  int round = 0;
  round = log(N - 0.0) / log(2.0);

  for (int i = 0; i < round; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      // 判斷每一輪勝負
      for (int k = j + 1; k < N; k++)
      {
        // 勝利
        if ((players[j] == 'p' && players[k] == 'r') || (players[j] == 'r' && players[k] == 's') || (players[j] == 's' && players[k] == 'p'))
        {
          // 標記輸家
          players[k] = 'l';
          // 從第二個可行位置開始
          j = k;
          break;
        }
        // 失敗
        else if ((players[k] == 'p' && players[j] == 'r') || (players[k] == 'r' && players[j] == 's') || (players[k] == 's' && players[j] == 'p'))
        {
          // 標記輸家
          players[j] = 'l';
          j = k;
          break;
        }
        // 平手
        else if ((players[k] == 'p' && players[j] == 'p') || (players[k] == 'r' && players[j] == 'r') || (players[k] == 's' && players[j] == 's'))
        {
          if (judge[i] == 's')
          {
            // 標記輸家
            players[k] = 'l';
            j = k;
            break;
          }
          else if (judge[i] == 'b')
          {
            // 標記輸家
            players[j] = 'l';
            j = k;
            break;
          }
        }
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    if (players[i] != 'l')
    {
      printf("%d", i + 1);
      return 0;
    }
  }

  // printf("\n%d", round);
  return 0;
}
