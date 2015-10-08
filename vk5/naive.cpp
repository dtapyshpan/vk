#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define SIZE(a) (int((a).size()))

int main(int arg, char *argc[])
{
  if (arg < 2) return 0;

  freopen(argc[1], "r", stdin);
  vector<string> vs;
  while (1)
  {
    string w;
    cin >> w;
    if (w == "exit") break;
    vs.push_back(w);
  }
  for (int i = 0; i < SIZE(vs); ++i)
  {
    bool f = false;
    for (int j = 0; j < i; ++j)
    {
      if (vs[i] == vs[j]) 
      {
        f = true;
        break;
      }
    }
    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}

