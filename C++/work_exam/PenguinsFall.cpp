#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{

  int n;
  cin >> n;
  int leftmin = INT_MAX;
  int rightmin = INT_MAX;
  int flag = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    if (tmp != -1 && flag == 0)
    {
      leftmin = min(tmp, leftmin);
      continue;
    }
    if (tmp == -1)
    {
      flag = 1;
      continue;
    }
    rightmin = min(tmp, rightmin);
  }

  cout << rightmin + leftmin;
}