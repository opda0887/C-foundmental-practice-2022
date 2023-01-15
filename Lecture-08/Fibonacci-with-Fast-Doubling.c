#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main()
{
  unsigned k;
  scanf("%u", &k);

  uint64_t f2k, f2k1;
  fib_fast_doubling(k / 2, &f2k, &f2k1);

  printf("%llu", (k & 0x1) ? f2k1 : f2k);

  return 0;
}

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
  if (k == 0)
  {
    *f2k = 0;
    *f2k1 = 1;
    return;
  }

  if (k == 1)
  {
    *f2k = 1;
    *f2k1 = 2;
    return;
  }

  fib_fast_doubling(k / 2, f2k, f2k1);

  uint64_t a, b;
  a = *f2k;
  b = *f2k1;
  *f2k = a * (2 * b - a);
  *f2k1 = a * a + b * b;
  if (k % 2 == 1)
  {
    *f2k += *f2k1;
    *f2k1 += *f2k;
  }
}