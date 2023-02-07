#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  // e.q. https://www.abc.com/user/12345/photo?from=20180101&to=20201231#favorite
  char *protocol; // 通訊協定 = https
  char *host;     // 主機名稱 = www.abc.com
  char *pathname; // 通訊埠 = 預設不顯示（但因為使用的是 https，所以可知是 443）
  char *search;   // 所在路徑 = /user/12345/photo
  char *hash;     // 查詢字串 = ?from=20180101&to=20201231
  int port;       // 識別符號 = #favorite
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
  // 答案的初始化 (用 malloc 存可以不怕資料在程式結束後被 free)
  Location *temp = malloc(sizeof(Location));
  memset(temp, 0, sizeof(Location)); // 答案初始成 null

  // malloc 的空間
  char *protocol = malloc(sizeof(char) * 50);
  char *host = malloc(sizeof(char) * 100);
  char *pathname = malloc(sizeof(char) * 100);
  char *search = malloc(sizeof(char) * 100);
  char *hash = malloc(sizeof(char) * 100);
  int *port = malloc(sizeof(int) * 5);

  temp->pathname = "\0";
  temp->search = "\0";
  temp->hash = "\0";

  // 紀錄 通訊協定 的終止位置
  int index, httpsCheck = 0;
  // 1. 先找 通訊協定，並記錄
  for (index = 0; index < strlen(url); index++)
  {
    if (url[index] == ':')
      break;
    protocol[index] = url[index];
  }
  temp->protocol = protocol;
  if (strcmp(protocol, "https") == 0) // 檢查是否為 https
    httpsCheck = 1;
  index += 3; // 變成：host 的起始位置

  // 2. 找 host
  int i = 0;
  for (index; index < strlen(url); index++)
  {
    if (url[index] == ':' || url[index] == '/' || url[index] == '?' || url[index] == '#' || url[index] == '\n' || url[index] == '\0')
      break;
    host[i++] = url[index];
  }
  host[i] = '\0';
  temp->host = host;

  // 確認是否結束 - host剛結束
  if (url[index] == '\n' || url[index] == '\0')
  {
    if (httpsCheck == 1)
    {
      temp->port = 443;
      return temp;
    }
    else
      return temp;
  }

  // 3. 找 port
  // if (url[index] == ':') // 確認是否為： :123
  // {
  //   index++; // 變成：port 的起始位置
  //   for (index; index < strlen(url); index++)
  //   {
  //     if (url[index] == '/' || url[index] == '?' || url[index] == '#' || url[index] == '\n' || url[index] == '\0')
  //       break;
  //       }
  // }

  return temp;
}