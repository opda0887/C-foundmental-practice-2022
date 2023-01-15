#include <stdio.h>
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,
                    int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main()
{
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
                 &c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);
}

void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr)
{
  int num = 0;
  int den = 0;
  den = a_denominator * b_denominator;
  num = a_numerator * b_denominator + b_numerator * a_denominator;

  while (1) // find the simpliest fraction
  {
    int checkBreak = 0;
    for (int i = 2; i <= den; i++)
    {
      if (den % i == 0 && num % i == 0)
      {
        den /= i;
        num /= i;
        checkBreak = 1;
        break;
      }
    }
    if (checkBreak != 1)
      break;
  }

  *c_denominator_ptr = den;
  *c_numerator_ptr = num;

  return;
}