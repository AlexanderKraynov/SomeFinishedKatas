#include<unordered_set>
#include<utility>
#include <iostream>
using namespace std;
pair<int,int> char_to_pair(char dot)
{ switch(dot)
  {
    case 'A':
      return{0,0};
    case 'B':
      return{0,1};
    case 'C':
      return{0,2};
    case 'D':
      return{1,0};
    case 'E':
      return{1,1};
    case 'F':
      return{1,2};
    case 'G':
      return{2,0};
    case 'H':
      return{2,1};
    case 'I':
      return{2,2};

  }
}
char pair_to_char(pair<int,int> dot)
{ switch(dot.first)
  {
    case 0:
    {
      switch(dot.second)
      {
        case 0:
          return 'A';
        case 1:
          return 'B';
        case 2:
          return 'C';
      }
    }
    case 1:
    {
      switch(dot.second)
      {
        case 0:
          return 'D';
        case 1:
          return 'E';
        case 2:
          return 'F';
      }
    }
    case 2:
    {
      switch(dot.second)
      {
        case 0:
          return 'G';
        case 1:
          return 'H';
        case 2:
          return 'I';
      }
    }

  }
}
void rec_count(const char & dot, unsigned int &count, unordered_set<char> visited,unsigned short length)
{
  visited.insert(dot);
  length --;
  if(length==0) {count++; return;}


  for(int i = -2; i<=2; i++)
  {
    for(int j = -2; j<=2; j++)
    {
      int buf_i =char_to_pair(dot).first;
      int buf_j =char_to_pair(dot).second;
      if((!((i==0)&&(j==0)))&&(buf_i+i>=0)&&(buf_j+j>=0)&&(buf_j+j<3)&&(buf_i+i<3))
      {
        if(visited.find(pair_to_char({buf_i+i,buf_j+j}))==visited.end())
        {
          if(((abs(i)==2)||(i==0))&&((abs(j)==2)||(j==0))) {
            if(visited.find(pair_to_char({buf_i+i/2,buf_j+j/2}))!=visited.end()) {

              rec_count(pair_to_char({buf_i + i, buf_j + j}), count, visited, length);
            }
          } else
          {

            rec_count(pair_to_char({buf_i + i, buf_j + j}), count, visited, length);
          }
        }
      }
    }
  }


}
unsigned int countPatternsFrom(char firstDot, unsigned short length) {
  if(length==0) return 0;
  unordered_set <char>visited;

  unsigned int count = 0;
  visited.insert(firstDot);
  rec_count(firstDot,count,visited,length);

  return count;
}
