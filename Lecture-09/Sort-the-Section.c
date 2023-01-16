#include <stdio.h>
#define ARR_MAX 1000
void sort_section(int *ptr, int *qtr);
void buble_sort(int *c, int *d, int count);
int main()
{
  int N, a, b;
  scanf("%d%d%d", &N, &a, &b);
  int arr[ARR_MAX] = {0};
  for (int i = 0; i < N; i++)
  {
    scanf("%d", arr + i);
  }
  sort_section(&arr[a], &arr[b]);
  for (int i = 0; i < N; i++)
  {
    printf("%d ", *(arr + i));
  }
}

void sort_section(int *ptr, int *qtr)
{
  // loop count
  int count = qtr - ptr;
  if (count < 0)
  {
    count *= (-1);
    int *c = qtr;
    int *d = ptr;
    buble_sort(c, d, count);
  }
  else
  {
    int *c = ptr;
    int *d = qtr;
    buble_sort(c, d, count);
  }
}

void buble_sort(int *c, int *d, int count)
{
  for (int i = 0; i < count; i++)
  {
    int *a = c;
    int *b = d;
    // 排序
    for (a; a < b; a++)
    {
      if (*a > *(a + 1))
      {
        int temp = *a;
        *a = *(a + 1);
        *(a + 1) = temp;
      }
    }
    // 印出
    int *temp = c;
    while (temp <= d)
      printf("%d ", *temp++);

    printf("\n");
  }
  return;
}