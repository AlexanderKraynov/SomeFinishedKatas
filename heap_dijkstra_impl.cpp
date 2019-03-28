#include<iostream>
#include<cmath>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

struct dj
{
    int i;
    int j;
    int value;
    bool flag;

};
bool compare(dj a, dj b)
{
  return a.value>b.value;

}
int path_finder(std::string maze)
{

  const  int n=(int)sqrt(maze.size());
  int map[n][n];
  int dist[n][n];
  priority_queue<dj,vector<dj>,function<bool(dj,dj)>> q(compare);

  for(int i = 0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      
      dist[i][j]=10000000;
      map[i][j]=maze[i*n+j+i];
      dj buf = {i,j,10000000,false};
      if(!((i==0)&&(j==0)))q.push(buf);

    }
  }
  dj buf = {0,0,0,false};
  q.push(buf);
  dist[0][0]=0;
  while(!q.empty())
  {

    int i = q.top().i;
    int j = q.top().j;
    int value = q.top().value;
    q.pop();
    if(value==dist[i][j]){
      if((i>0)&&(dist[i-1][j]>value+abs(map[i][j]-map[i-1][j]))){
        dj buf1 = {i-1,j,value+abs(map[i][j]-map[i-1][j])};
        dist[i-1][j]= value+abs(map[i][j]-map[i-1][j]);
        q.push(buf1);
      }
      if((i<(n-1))&&(dist[i+1][j]>value+abs(map[i][j]-map[i+1][j]))){
        dj buf2 = {i+1,j,value+abs(map[i][j]-map[i+1][j])};
        dist[i+1][j]= value+abs(map[i][j]-map[i+1][j]);
        q.push(buf2);
      }
      if((j>0)&&(dist[i][j-1]>value+abs(map[i][j]-map[i][j-1]))){
        dj buf3 = {i,j-1,value+abs(map[i][j]-map[i][j-1])};
        dist[i][j-1]= value+abs(map[i][j]-map[i][j-1]);
        q.push(buf3);
      }
      if((j<(n-1))&&(dist[i][j+1]>value+abs(map[i][j]-map[i][j+1]))){
        dj buf4= {i,j+1,value+abs(map[i][j]-map[i][j+1])};
        dist[i][j+1]= value+abs(map[i][j]-map[i][j+1]);
        q.push(buf4);
      }
   }


  }

  return dist[n-1][n-1];
  
}