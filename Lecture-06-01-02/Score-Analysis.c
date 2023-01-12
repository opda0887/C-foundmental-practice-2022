#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  int N, T, score[1200], min, max;
  scanf("%d", &N);

  for (int i = 0; i < N; i++)
    scanf("%d", &score[i]);

  scanf("%d", &T);

  for (int i = 0; i < T; i++)
  {
    int a = 0, b = 0, c = 0;
    scanf("%d %d", &min, &max);
    for (int j = 0; j < N; j++)
    {
      // < min
      if (score[j] < min)
        a++;
      else if (score[j] >= min && score[j] < max)
        b++;
      else if (score[j] >= max)
        c++;
    }
    printf("%d %d %d\n", a, b, c);
  }

  return 0;
}

// #include <stdio.h>
// // Start
// int main()
// {
//   int Num;
//   int students[1100];
//   int T;
//   int range[10000][3];

//   scanf("%d", &Num);
//   for (int i = 0; i < Num; i++)
//   {
//     scanf("%d", &students[i]);
//   }
//   scanf("%d", &T);
//   for (int i = 0; i < T; i++)
//   {
//     scanf("%d %d", &range[i][0], &range[i][1]);
//   }

//   // count part
//   for (int i = 0; i < T; i++)
//   {
//     int B = range[i][0];
//     int A = range[i][1];
//     int Scount = 0;
//     int Mcount = 0;
//     int Bcount = 0;
//     for (int j = 0; j < Num; j++)
//     {
//       if (students[j] < B)
//       {
//         Scount++;
//       }
//       else if (students[j] >= B && students[j] < A)
//       {
//         Mcount++;
//       }
//       else if (students[j] >= A)
//       {
//         Bcount++;
//       }
//     }
//     printf("%d %d %d\n", Scount, Mcount, Bcount);
//   }

//   return 0;
// }
