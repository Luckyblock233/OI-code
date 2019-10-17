// luogu-judger-enable-o2
//知识点:DFS/迭代加深
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
//=======================================================
int dx[10]={0,1,1,-1,-1,2,2,-2,-2};
int dy[10]={0,2,-2,2,-2,1,-1,1,-1};
int target[7][7]=
{
    {0,0,0,0,0,0},
    {0,1,1,1,1,1},
    {0,0,1,1,1,1},
    {0,0,0,2,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
};
int t,judge;
int map[7][7];
//=======================================================
inline bool check(int x,int y)
{
    if(x<1 || x>5 || y<1 || y>5) return 0;
    return 1;
}
inline int cnt()
{
    int sum=0;
    for(int i=1;i<=5;i++)
      for(int j=1;j<=5;j++)
        if(map[i][j]!=target[i][j])sum++;
    return sum;
}
void dfs(int now,int sx,int sy,int lim)
{
    if(now==lim)
      {
      	if(!cnt()) judge=1;
        return ;
      }
    for(int i=1;i<=8;i++)
      if(check(sx+dx[i],sy+dy[i]))
        {
          swap(map[sx][sy],map[sx+dx[i]][sy+dy[i]]);
          if(cnt()+now<=lim)
            dfs(now+1,sx+dx[i],sy+dy[i],lim);
          swap(map[sx][sy],map[sx+dx[i]][sy+dy[i]]);
        }
}
signed main()
{
	cin.sync_with_stdio(false);
    cin>>t;
    while(t--)
      {
      	int sx,sy;
        judge=0;
        for(int i=1;i<=5;i++)
      	  for(int j=1;j<=5;j++)
      	  	{
              char tmp;
      	  	  cin>>tmp;
      	  	  if(tmp=='*') map[i][j]=2,sx=i,sy=j;
      	  	  else map[i][j]=tmp-'0';
            }
        for(int i=0;i<=15;i++)
       	  {
       	  	dfs(0,sx,sy,i);
       	  	if(judge)
              {
                cout<<i<<endl;	
                break;
              }
          }
        if(!judge) cout<<-1<<endl;
      }
}
