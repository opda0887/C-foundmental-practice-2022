#include <stdio.h>
#include <string.h>

unsigned long long construct(unsigned char parts[16]);

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%llu", construct(parts));

    return 0;
}

unsigned long long construct(unsigned char parts[16]){
  
  union Teleportation
  {
    struct ans {
      unsigned long long a;
      unsigned long long b;
    } divide;

    unsigned char p[16];
  } final;

  memcpy(final.p, parts, 16);

  return final.divide.a ^ final.divide.b;
}