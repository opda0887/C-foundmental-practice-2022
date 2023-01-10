#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main()
{
  /* code start */
  char ask[1000];
  int len, success = 0, str = INIT_STRENGTH, obe = INIT_OBEDIENCE;
  scanf("%s", ask);
  len = strlen(ask);

  for (int i = 0; i < len; i++)
  {
    if (ask[i] == 'e')
    {
      str += STRENGTH_EAT;
      obe -= OBEDIENCE_EAT;
      if (obe >= LEARN_OBEDIENCE && str <= LEARN_STRENGTH)
      {
        success++;
        obe = INIT_OBEDIENCE;
      }
    }
    else if (ask[i] == 't')
    {
      str -= STRENGTH_TRAIN;
      obe += OBEDIENCE_TRAIN;
      if (obe >= LEARN_OBEDIENCE && str <= LEARN_STRENGTH)
      {
        success++;
        obe = INIT_OBEDIENCE;
      }
    }
  }

  if (success >= 5)
    printf("Yes");
  else
    printf("No");

  return 0;
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//      char a[10000];
//      fgets(a, 10000, stdin);

//      int count = 0;
//      int Strength = INIT_STRENGTH;
//      int Obedience = INIT_OBEDIENCE;

//      for (int i =0; i<strlen(a); i++){

//           if (count == 5){
//                printf("Yes");
//                return 0;
//           }

//           if (a[i] == 'e'){
//                 Strength += STRENGTH_EAT;
//                 Obedience -= OBEDIENCE_EAT;
//           }else if (a[i] == 't'){
//                Strength -= STRENGTH_TRAIN;
//                Obedience += OBEDIENCE_TRAIN;
//           }

//           if (Strength<=LEARN_STRENGTH && Obedience>=LEARN_OBEDIENCE){
//                count++;
//                Obedience = INIT_OBEDIENCE;
//           }
//      }
//      printf("No");
//      return 0;
// }