#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int d[7], a, b;
  for (int i = 1; i <= 6; i++)
    d[i] = 0;

  for (int i = 0; i < 75; i++)
  {
    scanf("%d %d\n", &a, &b);
    if (b % 2 == 1) // odd: +1
      d[a] = (d[a] + 1) % 10;
    else if (b % 2 == 0) // even: -1
    {
      d[a] = d[a] - 1;
      if (d[a] == -1)
        d[a] = 9;
    }
  }

  for (int i = 1; i <= 6; i++)
    printf("%d ", d[i]);

  return 0;
}

// #include <stdio.h>

// int main()
// {
//   int d1[100], d2[100];
//   int ans[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//   for (int i = 0; i < 75; i++)
//   {
//     scanf("%d %d", &d1[i], &d2[i]);
//   }

//   for (int i = 0; i < 75; i++)
//   {
//     if (d2[i] % 2 == 0)
//     {
//       ans[d1[i] - 1] = ans[d1[i] - 1] - 1;
//       if (ans[d1[i] - 1] == -1)
//       {
//         ans[d1[i] - 1] = 9;
//       }
//     }
//     else
//     {
//       ans[d1[i] - 1] = (ans[d1[i] - 1] + 1) % 10;
//     }
//   }

//   for (int i = 0; i < 6; i++)
//   {
//     printf("%d ", ans[i]);
//   }
// }