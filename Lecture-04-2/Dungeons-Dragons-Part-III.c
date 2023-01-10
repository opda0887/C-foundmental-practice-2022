#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  /* code start */
  unsigned long long NUMBER_1 = 0x38E38E38E38E3800;
  unsigned long long NUMBER_2 = 0x2AAAAAAAAAAAAAAA;
  unsigned long long NUMBER_3 = 0x1C71C71C71C71C71;
  unsigned long long NUMBER_4 = 0x7CE66C50E2840000;
  unsigned long long a, b, c, ans = 0;
  scanf("%llu %llu %llu", &a, &b, &c);

  ans = (a * NUMBER_1) % NUMBER_4;
  ans = (ans + (b * NUMBER_2) % NUMBER_4) % NUMBER_4;
  ans = (ans + (c * NUMBER_3) % NUMBER_4) % NUMBER_4;
  printf("%llu", ans);

  // ((a % c) + (b % c)) % c

  return 0;
}

// #include <stdio.h>
// int main () {
//      unsigned long long int num1 = 0x38E38E38E38E3800LLU;
//      unsigned long long int num2 = 0x2AAAAAAAAAAAAAAALLU;
//      unsigned long long int num3 = 0x1C71C71C71C71C71LLU;
//      unsigned long long int num4 = 0x7CE66C50E2840000LLU;
//      unsigned long long int a, b, c;
//      scanf("%lld %lld %lld", &a, &b, &c);
//      // printf("%lld\n", a*num1%num4);
//      // printf("%lld\n", b*num2%num4);
//      // printf("%lld\n", c*num3%num4);
//      unsigned long long int ans1 = a*num1%num4;
//      unsigned long long int ans2 = b*num2%num4;
//      unsigned long long int ans3 = c*num3%num4;
//      // printf("%lld\n%lld\n%lld\n", ans1, ans2, ans3);
//      unsigned long long int ans4 = (ans1+ans2)%num4;
//      unsigned long long int ans5 = (ans3+ans4)%num4;
//      printf("%lld", ans5);
//     //printf("%lld\n", (((a*num1)%num4)+(b*num2)%num4)%num4+(c*num3)%num4)%num4;

//     return 0;
// }