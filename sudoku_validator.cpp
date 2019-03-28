#include <set>
using namespace std;
bool validSolution(unsigned int board[9][9]){
 
 std::vector<unsigned int> checkbox;
 for (int i = 0;i<9;i++)
 {  
   for (int j=0;j<9;j++)
   { if (board[i][j] == 0) return false;
   if(std::find(checkbox.begin(), checkbox.end(), board[i][j]) == checkbox.end())
   checkbox.push_back(board[i][j]);
   }
   if (checkbox.size()!=9) return false;
   checkbox.clear();
 }
 
  for (int j = 0;j<9;j++)
 {  
   for (int i=0;i<9;i++)
   {
   if(std::find(checkbox.begin(), checkbox.end(), board[i][j]) == checkbox.end())
   checkbox.push_back(board[i][j]);
   }
   if (checkbox.size()!=9) return false;
   checkbox.clear();
 }
 checkbox.clear();
set<int> checkboxs;
for(int i = 1;i<8;i=i+3)
{
  for(int j = 1; j<8; j=j+3)
  {
    for(int k=0;k<3;k++)
    {
      for(int t=0;t<3;t++)
      {
      if(checkboxs.find(board[i-1+k][j-1+t])==checkboxs.end())
      {
      checkboxs.insert(board[i-1+k][j-1+t]);
      }
      else return false;
      }
    } 
    
    checkboxs.clear();
  }

}
   return true;
}