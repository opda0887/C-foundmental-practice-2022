#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t * const queue, int value, int weight);
node_t *dequeue(prio_queue_t * const queue);
void print_nodes(const prio_queue_t * const queue);

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		}
		else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
        }
		print_nodes(&queue);
	}
	return 0;
}

void print_nodes(const prio_queue_t *const queue) {
	if (!queue->head) {
		printf("EMPTY\n");
		return;
	}
	for (node_t *node = queue->head; node; node = node->next) {
		printf(" -> %d", node->value);
    }
	printf("\n");
    return;
}

//

void enqueue(prio_queue_t *const queue, int value, int weight)
{
  // 以下採用：後進先出法紀錄
  node_t *p = malloc(sizeof(node_t));
  p->value = value;
  p->weight = weight;
  if (!queue->head)
  {
    p->next = queue->head;
    queue->head = p;
  }
  else
  {
    node_t *c = queue->head;
    node_t *rem;
    int check = 0;
    while (c != NULL) // 看當前節點
    {
      if (c->weight > p->weight) // 找到插入地方時
      {
        if (!check) // 插入第一位置時
        {
          p->next = queue->head;
          queue->head = p;
          break;
        }
        else // 插入其他位置時
        {
          node_t *rr = rem->next;
          rem->next = p;
          p->next = rr;
          break;
        }
      }
      else if (c->next == NULL) // 插入最後一位置時
      {
        c->next = p;
        p->next = NULL;
        break;
      }
      rem = c; // 紀錄上一節點
      c = c->next;
      check = 1;
    }
  }
}

node_t *dequeue(prio_queue_t *const queue)
{
  if (!queue->head) // 此時head無值
    return NULL;

  node_t *delete = queue->head;    // 找出 head 指向的位置
  queue->head = queue->head->next; // 將 head 修改為下一節點的位置
  return delete;                   // 回傳第一節點的位置
}