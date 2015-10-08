#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

int n = 1000;

int binsearch(int *ar, ...)
{
  va_list vl;
  va_start(vl, ar);
  int x = va_arg(vl, int);
  int l = 0, r = n;
  while (r - l > 1)
  {
    int m = (r + l) >> 1;
    if (ar[m] < x) l = m;
    else r = m;
  }
  va_end(vl);
  if (ar[l] > x) return l;
  if (r == n) return -1;
  return r;
}

void initar(int *ar)
{
  int i;
  ar[0] = rand() % 100;
  for (i = 1; i < n; ++i)
  {
    ar[i] = ar[i - 1] + rand() % 100;
  }
}

int main(int arg, char *argc[])
{
  srand(time(NULL));
  int ar[n];
  int i;
  initar(ar);
  int x = rand() % 10000;
  for (i = 0; i < n; ++i) printf("%d ", ar[i]);
  printf("\n");
  int index = binsearch(ar, x); 
  if (index == -1) printf("-1");
  else printf("x = %d, ar[%d] = %d", x, index, ar[index]);

  return 0;
}

