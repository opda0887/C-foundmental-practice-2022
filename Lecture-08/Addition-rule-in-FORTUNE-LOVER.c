#include <stdio.h>
#include <math.h>

int a, b, carry = 0;
int array[32] = {0};
int barray[32] = {0};
int sumarray[32] = {0};
long long finalAns;

void numToIEEE(int a, int array[]);
void printSum(int sumarray[]);
void twoToTen(int sumarray[]);

int main()
{
  scanf("%d %d", &a, &b);

  printf("   ");
  numToIEEE(a, array);
  printf("+) ");
  numToIEEE(b, barray);
  printf("---------------------------------------\n");
  printSum(sumarray);

  twoToTen(sumarray);
  return 0;
}

void numToIEEE(int a, int array[])
{
  int temp[10000] = {0};
  int count = 126;
  int q = 0;

  // 正負號確認
  if (a < 0)
  {
    array[0] = 1;
    a = abs(a);
  }

  // 算 126 + ?
  do
  {
    temp[q] = a % 2;
    a /= 2;
    count++;
    q++;
  } while (a != 0);

  int index = count - 126;
  for (int i = 8; i >= 1; i--)
  {
    array[i] = count % 2;
    count /= 2;
  }

  // 餘數處理
  count = index;
  for (int i = 9; i < 8 + count; i++)
  {
    array[i] = temp[index - 2];
    index--;
  }

  // check ans
  for (int i = 0; i <= 31; i++)
  {
    printf("%d", array[i]);
    if (i % 8 == 7)
      printf(" ");
  }
  printf("\n");
}

//
void printSum(int sumarray[])
{
  for (int i = 31; i >= 0; i--)
  {
    int tot = array[i] + barray[i] + carry;

    sumarray[i] = tot % 2;
    carry = tot / 2;
  }

  // check ans
  printf("   ");
  for (int i = 0; i <= 31; i++)
  {
    printf("%d", sumarray[i]);
    if (i % 8 == 7)
      printf(" ");
  }
  printf("\n");
}

void twoToTen(int sumarray[])
{
  int multi = 0;

  // 第一數為0
  if (sumarray[0] == 0)
  {
    for (int i = 31; i >= 1; i--)
    {
      finalAns += pow(2, multi) * sumarray[i];
      multi++;
    }
  }
  // 第一數為1
  else
  {
    for (int i = 31; i >= 1; i--)
    {
      if (sumarray[i] == 0)
        finalAns += pow(2, multi) * 1;
      multi++;
    }
    finalAns = finalAns * (-1);
    finalAns--;
  }
  printf("%d + %d = %lld", a, b, finalAns);
}
