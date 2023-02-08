#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->val);
    }
    return 0;
}

void MoveToTail(){
  // find max first
  int max = -99999;

  for (struct node *p = head; p != NULL; p = p->next){
    if (p->val > max)
      max = p->val;
  }

  // make max to the end
  for (struct node *p = head; p->next != NULL; p = p->next){
    if (p->val == max) {
      p->val = p->next->val;
      p->next->val = max;
    }
  }
}