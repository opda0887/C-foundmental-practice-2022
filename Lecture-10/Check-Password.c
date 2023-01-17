#include <stdio.h>
#include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main()
{
  char password1[SIZE];
  char password2[SIZE];

  // Enter the password
  scanf("%s", password1);
  // Enter the password again
  scanf("%s", password2);

  // Check Password
  // First: Check length
  if (length(password1, password2) == 1)
  {
    printf("Length does not match the requirements");
  }
  else
  {
    // Second: Check for consistency
    if (compare(password1, password2) == 1)
    {
      printf("Not the same password");
    }
    else
    {
      // Third: Check for compliance
      if (content(password1) == 1)
      {
        printf("Do not satisfy the conditions");
      }
      else
      {
        printf("Everything is good");
      }
    }
  }

  return 0;
}

#include <string.h>
int length(char pwd1[], char pwd2[])
{
  if ((strlen(pwd1) >= 6 && strlen(pwd1) <= 16) && (strlen(pwd2) >= 6 && strlen(pwd2) <= 16))
  {
    return 0;
  }
  return 1;
}

int compare(char pwd1[], char pwd2[])
{
  if (strlen(pwd1) != strlen(pwd2))
  {
    return 1;
  }
  for (int i = 0; i < strlen(pwd1); i++)
  {
    if (pwd1[i] != pwd2[i])
    {
      return 1;
    }
  }
  return 0;
}

int content(char pwd1[])
{
  int bigC = 0;
  int smallC = 0;
  int num = 0;
  for (int i = 0; i < strlen(pwd1); i++)
  {
    char c = pwd1[i];
    if ((int)c >= 65 && (int)c <= 90)
    {
      bigC = 1;
      continue;
    }
    if ((int)c >= 97 && (int)c <= 122)
    {
      smallC = 1;
      continue;
    }
    if ((int)c >= 48 && (int)c <= 57)
    {
      num = 1;
      continue;
    }
  }

  if (bigC == 1 && smallC == 1 && num == 1)
  {
    return 0;
  }
  return 1;
}