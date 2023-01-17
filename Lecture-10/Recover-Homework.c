#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main()
{
  char homework[MAX_LEN + 1];

  // Get the homework content.
  fgets(homework, MAX_LEN, stdin);
  recovery(homework);

  // Print the recovered homework.
  fputs(homework, stdout);

  return 0;
}

void recovery(char *homework)
{
  char final[MAX_LEN + 1];
  int iF = 0;
  int len = 0;
  while (homework[len++] != '\n' && homework[len++] != '\0')
    ;    // 正確計算 len 的方法
  len--; // 最後要再扣一
  for (int i = 0; i < len; i++)
  {
    int cut;
    int start = i;
    char compare[MAX_LEN + 1] = {};
    int count = 0;
    // 拆分與放置
    for (int j = i + 1; j <= len; j++)
    {
      if (j == len || homework[j] == ' ')
      {
        cut = j;
        break;
      }
    }
    for (int j = start; j < cut; j++)
    {
      compare[count] = homework[j];
      count++;
    }

    // 檢查該部分字串長度
    if (strlen(compare) > 21 || strlen(compare) < 1)
    {
      i = cut;
      continue;
    }

    // 檢查單字是否合理
    int check = 0;
    for (int j = 0; j < strlen(compare); j++)
    {
      // 先檢查符號是否在最尾端
      if (strlen(compare) == 1 && (compare[j] == ',' || compare[j] == '.' || compare[j] == '!' || compare[j] == '?'))
      {
        check = 1;
        break;
      }
      if ((compare[j] == ',' || compare[j] == '.' || compare[j] == '!' || compare[j] == '?') && j != strlen(compare) - 1)
      {
        check = 1;
        break;
      }
      // 檢查有無其他字元
      else if ((int)compare[j] < 65 || (int)compare[j] > 122 || ((int)compare[j] > 90 && (int)compare[j] < 97))
      {
        if (j == strlen(compare) - 1)
        {
          if ((compare[j] != ',' && compare[j] != '.' && compare[j] != '!' && compare[j] != '?'))
          {
            check = 1;
            break;
          }
        }
        else
        {
          check = 1;
          break;
        }
      }
    }
    if (check == 1)
    {
      i = cut;
      continue;
    }

    // 儲存符合字串
    for (start; start < cut; start++)
    {
      final[iF] = homework[start];
      iF++;
    }
    final[iF] = ' ';
    iF++;
    i = cut;
  }
  // 結果儲存在homework中
  // memset(homework, 0, MAX_LEN); // 清除 homework 字串
  strcpy(homework, final); // homework = final
  // homework[strlen(final) - 1] = '\0';
  // for (int i = 0; i <= MAX_LEN; i++) // 用這個來存homework
  //   homework[i] = final[i];
}