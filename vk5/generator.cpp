#include <cstdio>
#include <cstdlib>
#include <ctime>

void genword(int maxwl)
{
  int len = 1 + rand() % maxwl;
  for (int i = 0; i < len; ++i)
  {
    char ch = 32 + rand() % (127 - 32 + 1);
    printf("%c", ch);
  }
}

int main(int arg, char *argc[])
{
  if (arg < 3) return 0;
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  int maxwcnt, maxwl; 
  sscanf(argc[1], "%d", &maxwcnt);
  sscanf(argc[2], "%d", &maxwl);
  for (int i = 0; i < maxwcnt; ++i)
  {
    genword(maxwl);
    printf("\n");
  }
  printf("exit\n");

  return 0;
}
 
