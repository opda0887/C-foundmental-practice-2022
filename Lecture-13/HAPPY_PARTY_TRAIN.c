#include <stdio.h>
#include <stdlib.h>

struct Car {
    int passenger;
    int flammable;
    struct Car *next;
};

void attachCar(struct Car *head, int passenger, int flammable) {
    struct Car *curr = head;
    while(curr->next) curr = curr->next;             // Find the end of the train

    struct Car *newcar = malloc(sizeof(struct Car)); // Make a new car
    newcar->passenger = passenger;                   // Let passengers in
    newcar->flammable = flammable;                   // Load flammable items
    newcar->next = NULL;                             // This is the last car

    curr->next = newcar;                             // Attach new car to the train
}

int fire(struct Car *head);

int main(int argc, char *argv[])
{
    int cars;
    int human[13], moeru[13];

    struct Car head;
    head.next = NULL; // passenger & flammable for head in useless

    scanf("%d", &cars);
    for (int i = 0; i < cars; ++i) {
        scanf("%d", &human[i]);
    }
    for (int i = 0; i < cars; ++i) {
        scanf("%d", &moeru[i]);
    }

    for (int i = 0; i < cars; ++i) {
        attachCar(&head, human[i], moeru[i]);
    }

    printf("%d", fire(&head)); // The train is on fire now

    return 0;
}

int fire(struct Car *head)
{
  int count = 0;
  for (struct Car *p = head->next; p != NULL; p = p->next)
  {
    if (p->passenger >= p->flammable)
      return count;
    else
    {
      if (p->next != NULL)
        p->next->passenger += p->passenger;
      else
        return count + 1;
    }
    count++;
  }
  return count;
}