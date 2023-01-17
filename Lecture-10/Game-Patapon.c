#include <stdio.h>
#include <string.h>
#define SIZE 10000

int main()
{
  int stepCount = 0; // 紀錄行動次數
  int legel = 0;     // 紀錄合法行動次數
  int def = 0;       // 紀錄是否防守成功
  int monsterD, monsterHp;
  char call[SIZE] = {};
  scanf("%d %d\n", &monsterD, &monsterHp);
  fgets(call, 10000, stdin);
  int len = strlen(call) - 1;

  // 若一開始離怪物距離為0
  if (monsterD == 0)
  {
    printf("%s %d", "NO", monsterHp);
    return 0;
  }

  // start
  for (int i = 0; i < len; i++)
  {
    int cut;
    char compare[SIZE] = {};
    int start = i;
    int count = 0;
    // 拆分與放置
    for (int j = i + 1; j <= len; j++)
    {
      if (call[j] == '\n' || call[j] == ',' || call[j] == '.')
      {
        cut = j;
        break;
      }
    }
    for (int j = start; j < cut; j++)
    {
      compare[count] = call[j];
      count++;
    }

    // check：PATA PATA PATA PON -- 前進
    if (strncmp(compare, "PATA PATA PATA PON", 18) == 0)
    {
      stepCount++;
      legel++;
      monsterD--;
      if (monsterD <= 0)
      {
        printf("%s %d", "NO", monsterHp);
        return 0;
      }
    }
    // check：PON PON PATA PON -- 可以原地攻擊怪物，扣除怪獸一滴血。
    else if (strncmp(compare, "PON PON PATA PON", 16) == 0)
    {
      stepCount++;
      legel++;
      if (monsterD <= 3)
        monsterHp--;
      // 是否勝利
      if (monsterHp <= 0)
      {
        printf("%s %d", "YES", legel);
        return 0;
      }
    }
    // check：CHAKA CHAKA PATA PON -- 可以後退一步並防禦怪物攻擊。
    else if (strncmp(compare, "CHAKA CHAKA PATA PON", 20) == 0)
    {
      stepCount++;
      legel++;
      monsterD++; // 後退一步
      def = 1;    // 防守
    }
    else
      stepCount++;

    // 防守失敗時
    if (stepCount % 10 == 0 && def == 0)
    {
      printf("%s %d", "NO", monsterHp);
      return 0;
    }
    // 重製防守
    def = 0;

    i = cut;
  }

  printf("%s %d", "NO", monsterHp);
  return 0;
}
