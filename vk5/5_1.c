#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDLEN 256
#define CHILDNUM 128

struct trie
{
  int leaf;
  struct trie *child[CHILDNUM];
};

int addword(char *w, struct trie *root)
{
  int lenw = strlen(w);
  struct trie *v = root;
  int i;
  for (i = 0; i < lenw; ++i)
  {
    int ch = (int)w[i];
    if (v->child[ch] == NULL)
    {
      v->child[ch] = (struct trie *) calloc(1, sizeof(struct trie));
    }
    v = v->child[ch];
  }
  if (v->leaf == 1) return 1;
  v->leaf = 1;
  return 0;
}

void deletetrie(struct trie *root)
{
  struct trie *v = root;
  int i, j;
  for (i = 0; i < CHILDNUM; ++i)
  {
    if (v->child[i] != NULL)
    {
      deletetrie(v->child[i]);
    }
  }
  free(v);
}

int main(int arg, char *argc[])
{
  if (arg < 2)
  {
    return 0;
  }

  freopen(argc[1], "r", stdin);
  struct trie *root;
  root = (struct trie *) calloc(1, sizeof(struct trie));
  while(1)
  {
    char w[WORDLEN];
    scanf("%s\n", w);
    if (strcmp(w, "exit") == 0) 
    {
      break;
    } 
    if (addword(w, root) == 1) 
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  deletetrie(root);

  return 0;
}

