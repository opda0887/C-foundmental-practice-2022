#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int people, g_people, group, remain = 0;
  scanf("%d%d", &people, &g_people);

  group = people / g_people;
  remain = people - group * g_people;

  printf("%d %d", group, remain);

  return 0;
}

// #include<stdio.h>

// int main () {
//     int person, divide, groups, remain;
//     scanf("%d %d", &person, &divide);
//     groups = person/divide;
//     remain = person - (groups*divide);
//     printf("%d %d", groups, remain);
//     return 0;
// }