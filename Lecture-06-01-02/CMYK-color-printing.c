#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB();

int main()
{
  // Get the dimension of the image.
  scanf("%u %u", &W, &H);

  // Declare the mask for single ink color.
  unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

  // For each layer, do the following:
  for (int layer = 0; layer < 4; ++layer)
  {
    // Get color mask.
    for (int i = 0; i < H; ++i)
    {
      for (int j = 0; j < W; ++j)
      {
        scanf("%u", &mask[i][j]);
      }
    }

    // Print a layer of that color to the paper.
    switch (layers[layer])
    {
    case 'C':
      print_C(mask);
      break;
    case 'M':
      print_M(mask);
      break;
    case 'Y':
      print_Y(mask);
      break;
    case 'K':
      print_K(mask);
      break;
    }
  }

  // Convert CMYK color to RGB color.
  CMYK_to_RGB();

  // Show the final result.
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      printf("#%06x ", image[i][j]);
    }
    printf("\n");
  }

  return 0;
}

#include <stdlib.h>
#include <string.h>

void print_C(unsigned int mask[][MAX_SIZE])
{
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
      image[i][j] += (100 - mask[i][j]) * 1000000;
  }
}

void print_M(unsigned int mask[][MAX_SIZE])
{
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
      image[i][j] += (100 - mask[i][j]) * 1000;
  }
}

void print_Y(unsigned int mask[][MAX_SIZE])
{
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
      image[i][j] += (100 - mask[i][j]) * 1;
  }
}

void print_K(unsigned int mask[][MAX_SIZE])
{
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      int c, m, y;
      c = image[i][j] / 1000000;
      m = (image[i][j] / 1000) % 1000;
      y = image[i][j] % 1000;
      // printf("%u %u %u\n", a, b, c);

      c = lround(255 * ((100 - mask[i][j]) / 100.000000) * (c / 100.000000));
      m = lround(255 * ((100 - mask[i][j]) / 100.000000) * (m / 100.000000));
      y = lround(255 * ((100 - mask[i][j]) / 100.000000) * (y / 100.000000));
      // printf("%u %u %u\n", a, b, c);

      image[i][j] = c * 1000000 + m * 1000 + y;
    }
  }
}

void CMYK_to_RGB()
{
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      int r, g, b;
      r = image[i][j] / 1000000;
      g = (image[i][j] / 1000) % 1000;
      b = image[i][j] % 1000;
      image[i][j] = r * 256 * 256 + g * 256 + b;
    }
  }
}

// void print_C(unsigned int mask[][MAX_SIZE])
// {
//   for (int i = 0; i < H; ++i)
//   {
//     for (int j = 0; j < W; ++j)
//     {
//       image[i][j] += ((100 - mask[i][j])) * 1000000;
//     }
//   }
// }

// void print_M(unsigned int mask[][MAX_SIZE])
// {
//   for (int i = 0; i < H; ++i)
//   {
//     for (int j = 0; j < W; ++j)
//     {
//       image[i][j] += ((100 - mask[i][j])) * 1000;
//     }
//   }
// }

// void print_Y(unsigned int mask[][MAX_SIZE])
// {
//   for (int i = 0; i < H; ++i)
//   {
//     for (int j = 0; j < W; ++j)
//     {
//       image[i][j] += 100 - mask[i][j];
//     }
//   }
// }

// void print_K(unsigned int mask[][MAX_SIZE])
// {
//   for (int i = 0; i < H; ++i)
//   {
//     for (int j = 0; j < W; ++j)
//     {
//       int a = 0, b = 0, c = 0;
//       a = image[i][j] / 1000000;
//       b = (image[i][j] / 1000) % 1000;
//       c = image[i][j] % 1000;
//       //printf("%u %u %u\n", a, b, c);

//       a = lround(255 * ((100 - mask[i][j]) / 100.000000) * (a / 100.000000));
//       b = lround(255 * ((100 - mask[i][j]) / 100.000000) * (b / 100.000000));
//       c = lround(255 * ((100 - mask[i][j]) / 100.000000) * (c / 100.000000));
//       //printf("%u %u %u\n", a, b, c);

//       image[i][j] = a * 1000000 + b * 1000 + c;
//     }
//   }
// }

// void CMYK_to_RGB()
// {
//   for (int i = 0; i < H; ++i)
//   {
//     for (int j = 0; j < W; ++j)
//     {
//       int a = 0, b = 0, c = 0;
//       a = image[i][j] / 1000000;
//       b = (image[i][j] / 1000) % 1000;
//       c = image[i][j] % 1000;
//       image[i][j] = (a * 256 * 256) + (b * 256) + c;
//     }
//   }
// }
