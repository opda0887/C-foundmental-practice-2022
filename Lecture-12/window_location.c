#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

Location *parse_url(char *url)
{
  printf("Location {\n  protocol: ");

  int index = 0; // 紀錄 通訊協定 的終止位置
  char https[8];
  int httpsCheck = 0;

  // 1. 先找 通訊協定，並記錄
  for (index; index < strlen(url); index++)
  {
    if (url[index] == ':')
    {
      break;
    }
    printf("%c", url[index]);
    https[index] = url[index];
  }
  if (strcmp(https, "https") == 0) // 檢查是否為 https
    httpsCheck = 1;
  index += 3; // 變成：host 的起始位置

  // 2. 找 host
  printf(",\n  host: ");
  for (index; index < strlen(url); index++)
  {
    if (url[index] == ':' || url[index] == '/' || url[index] == '?' || url[index] == '#' || url[index] == '\n' || url[index] == '\0')
    {
      break;
    }
    printf("%c", url[index]);
  }

  // 確認是否結束 - host剛結束
  if (url[index] == '\n' || url[index] == '\0')
  {
    if (httpsCheck == 1)
      printf("\n  port: 443,\n  pathname: /,\n  search: ?,\n  hash: #,\n}\n");
    else
      printf("\n  port: (default),\n  pathname: /,\n  search: ?,\n  hash: #,\n}\n");
    exit(" ");
  }

  // 3. 找 port
  printf(",\n  port: ");
  if (url[index] == ':') // 確認是否為： :123
  {
    index++; // 變成：port 的起始位置
    for (index; index < strlen(url); index++)
    {
      if (url[index] == '/' || url[index] == '?' || url[index] == '#' || url[index] == '\n' || url[index] == '\0')
      {
        break;
      }
      printf("%c", url[index]);
    }
  }
  else // 沒有寫 port時
  {
    if (httpsCheck == 1) // 若為 https時：
      printf("443");
    else
      printf("(default)");
  }

  // 確認是否結束 - port剛結束
  if (url[index] == '\n' || url[index] == '\0')
  {
    printf(",\n  pathname: /,\n  search: ?,\n  hash: #,\n}\n");
    exit(" ");
  }

  // 4. 找 pathname
  printf(",\n  pathname: /");
  if (url[index] == '/') // 確認是否為： /user/12345/photo
  {
    index++; // 變成：pathname 的起始位置
    for (index; index < strlen(url); index++)
    {
      if (url[index] == '?' || url[index] == '#' || url[index] == '\n' || url[index] == '\0')
      {
        break;
      }
      printf("%c", url[index]);
    }
  }

  // 確認是否結束 - pathname剛結束
  if (url[index] == '\n' || url[index] == '\0')
  {
    printf(",\n  search: ?,\n  hash: #,\n}\n");
    exit(" ");
  }

  // 5. 找 search
  printf(",\n  search: ?");
  if (url[index] == '?') // 確認是否為： ?from=20180101&to=20201231
  {
    index++; // 變成：search 的起始位置
    for (index; index < strlen(url); index++)
    {
      if (url[index] == '#' || url[index] == '\n' || url[index] == '\0')
      {
        break;
      }
      printf("%c", url[index]);
    }
  }

  // 確認是否結束 - search剛結束
  if (url[index] == '\n' || url[index] == '\0')
  {
    printf(",\n  hash: #,\n}\n");
    exit(" ");
  }

  // 6. 找 port
  printf(",\n  hash: #");
  if (url[index] == '#') // 確認是否為： #favorite
  {
    index++; // 變成：port 的起始位置
    for (index; index < strlen(url); index++)
    {
      if (url[index] == '\n' || url[index] == '\0')
      {
        break;
      }
      printf("%c", url[index]);
    }
  }

  // 確認是否結束 - port剛結束
  if (url[index] == '\n' || url[index] == '\0')
  {
    printf(",\n}\n");
    exit(" ");
  }

  exit(" ");
}