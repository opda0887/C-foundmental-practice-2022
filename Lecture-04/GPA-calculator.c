#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  char score[1000];
  int len;
  float gp = 0.0, credict = 0.0, temp;
  fgets(score, 1000, stdin);
  len = strlen(score); // 包括最後的 '\n'

  for (int i = 0; i < len; i++)
  {
    switch (score[i])
    {
    case 'A':
      temp = score[i - 1] - 48;
      credict += temp;
      if (score[i + 1] == '+')
        gp += (4.3 * temp);
      else if (score[i + 1] == '-')
        gp += (3.7 * temp);
      else
        gp += (4 * temp);
      break;
    case 'B':
      temp = score[i - 1] - 48;
      credict += temp;
      if (score[i + 1] == '+')
        gp += (3.3 * temp);
      else if (score[i + 1] == '-')
        gp += (2.7 * temp);
      else
        gp += (3 * temp);
      break;
    case 'C':
      temp = score[i - 1] - 48;
      credict += temp;
      if (score[i + 1] == '+')
        gp += (2.3 * temp);
      else if (score[i + 1] == '-')
        gp += (1.7 * temp);
      else
        gp += (2 * temp);
      break;
    case 'F':
      credict += score[i - 1] - 48;
      break;
    default:
      break;
    }
  }

  printf("%.2f", gp / credict);

  return 0;
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main()
// {
//   int temp;
//   int num;
//   float ans = 0;
//   int gradeAns = 0;
//   char grade[1000000];
//   fgets(grade, 1024, stdin);
//   for (int i = 0; i < strlen(grade); i++)
//   {
//     temp = (int)grade[i];
//     if (temp == 65 || temp == 66 || temp == 67 || temp == 70)
//     {
//       if (grade[i - 1] != NULL)
//       {
//         num = grade[i - 1] - 0;
//         switch (temp)
//         {
//         case 65:
//           if (grade[i + 1] != NULL)
//           {
//             if ((int)grade[i + 1] == 43)
//             {
//               ans += (num - 48.0) * 4.3;
//             }
//             else if ((int)grade[i + 1] == 45)
//             {
//               ans += (num - 48.0) * 3.7;
//             }
//             else
//             {
//               ans += (num - 48.0) * 4.0;
//             }

//             if (num >= 49 && num <= 57)
//             {
//               gradeAns += (num - 48.0);
//             }
//             else
//             {
//               gradeAns++;
//             }
//           }

//           break;
//         case 66:
//           if (grade[i + 1] != NULL)
//           {
//             if ((int)grade[i + 1] == 43)
//             {
//               ans += (num - 48.0) * 3.3;
//             }
//             else if ((int)grade[i + 1] == 45)
//             {
//               ans += (num - 48.0) * 2.7;
//             }
//             else
//             {
//               ans += (num - 48.0) * 3.0;
//             }

//             if (num >= 49 && num <= 57)
//             {
//               gradeAns += (num - 48.0);
//             }
//             else
//             {
//               gradeAns++;
//             }
//           }

//           break;
//         case 67:
//           if (grade[i + 1] != NULL)
//           {
//             if ((int)grade[i + 1] == 43)
//             {
//               ans += (num - 48.0) * 2.3;
//             }
//             else if ((int)grade[i + 1] == 45)
//             {
//               ans += (num - 48.0) * 1.7;
//             }
//             else
//             {
//               ans += (num - 48.0) * 2.0;
//             }

//             if (num >= 49 && num <= 57)
//             {
//               gradeAns += (num - 48.0);
//             }
//             else
//             {
//               gradeAns++;
//             }
//           }

//           break;
//         case 70:
//           if (num >= 49 && num <= 57)
//           {
//             gradeAns += (num - 48.0);
//           }
//           else
//           {
//             gradeAns++;
//           }
//           break;
//         }
//       }
//     }
//   }
//   float t;
//   t = gradeAns - 0.0;
//   printf("%.2f", ans / t);
// }