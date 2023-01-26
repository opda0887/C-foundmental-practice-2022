#include <stdio.h>
#include <stdlib.h>

struct ESPer
{
  char name[64];
  int level;
};

int cmp(const void *a, const void *b);
void sort_level(struct ESPer *arr, int length);

int main()
{
  int n;
  struct ESPer tokiwadai[100];

  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
  }

  sort_level(tokiwadai, n);

  for (int i = 0; i < n; ++i)
  {
    printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
  }

  return 0;
}

// 升序
int cmp(const void *a, const void *b)
{
  const struct ESPer *aOrder = a;

  const struct ESPer *bOrder = b;

  // 對 level 比較
  return aOrder->level > bOrder->level ? 1 : -1;
}

void sort_level(struct ESPer *arr, int length)
{
  // qsort(...);
  qsort(arr, length, sizeof(struct ESPer), cmp);
}