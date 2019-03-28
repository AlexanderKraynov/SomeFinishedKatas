#include <string>
#include <vector>
#include <iostream>
using namespace std;


string multiply(string a, string b)
{
  if (a.size() == 0 || b.size() == 0)
    return "0";
  vector<int> result(a.size() + b.size(), 0);
  int buf1 = 0;
  int buf2 = 0;
  for (int i=a.size()-1; i>=0; i--)
  {
    int buf = 0;
    int buf3 = a[i] - '0';
    buf2 = 0;
    for (int j=b.size()-1; j>=0; j--)
    {
      int buf4 = b[j] - '0';
      int sum = buf3*buf4+ result[buf1 + buf2] + buf;
      buf = sum/10;
      result[buf1 + buf2] = sum % 10;
      buf2++;
    }
    if (buf > 0)
      result[buf1 + buf2] += buf;
    buf1++;
  }
  int i = result.size() - 1;
  while (i>=0 && result[i] == 0)
    i--;
  if (i == -1)
    return "0";
  string s = "";

  while (i >= 0)
    s +=to_string(result[i--]);

  return s;
}