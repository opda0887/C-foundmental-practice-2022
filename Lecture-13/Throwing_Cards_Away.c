#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct card
{
  int value;
  struct card *next;
} Card;

Card *head;
Card *current;

void build(Card *tmp, int n);
void move(Card *head, int m, int n);

int main()
{
  head = malloc(sizeof(Card));
  int n, m;
  scanf("%d %d", &n, &m);

  build(head, n);

  move(head, m, n);

  free(head);

  return 0;
}

void build(Card *tmp, int n) // build linked list
{
  current = tmp; // current 先指向建立好的動態空間

  for (int i = 1; i <= n; i++)
  {
    Card *p = malloc(sizeof(Card)); // 建立節點;
    p->value = i;
    p->next = NULL;
    if (i == 1) // 若為初始節點
      head = p; // head 指向第一個節點
    else
      current->next = p; // 繼續創造下一個節點
    current = p;         // 指向到目前為止的最後一個節點
  }
}

void move(Card *head, int m, int n)
{
  Card *p = head;
  Card *tail = head; // 記錄目前的最後一個節點
  while (tail->next)
    tail = tail->next; // 找出最後的節點

  for (int i = 0; i < m; i++)
  {
    printf("%d ", p->value);
    if (i == m - 2 && n == m) // 若剛好要準備取完了(n = m)
    {
      printf("%d", tail->value);
      break;
    }
    Card *temp = p->next;
    p = p->next->next; // p 指到下下個節點
    tail->next = temp;
    tail->next->next = NULL; // 將原本 p 的下個節點之 next 設為 NULL
    tail = tail->next;       // 更新最後節點
  }
}