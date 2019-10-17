#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
char a[500][500];
int zun[10][3]={{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1}};
queue <int> x;
queue <int> y;	
int m,n;
void bfs();
int main()
{
    do
      {
      	scanf("%d%d",&m,&n);
        if(m==0)
          break;
        for(int i=0;i<m;i++)
      	  for(int j=0;j<n;j++)
      	    a[i][j]=0;
      	int ans=0;
      	for(int i=0;i<m;i++)
      	  cin>>a[i];
      	for(int i=0;i<m;i++)
      	  for(int j=0;j<n;j++)
      		{
      		  if(a[i][j]=='@')
      		  	{
      		  	  ans++;
      		  	  x.push(i);
      		  	  y.push(j);
      		  	  a[i][j]='*';
      		  	  bfs();
                }
            }
        printf("%d\n",ans);
      }
    while(1);
    return 0;
}
void bfs()
{
    while(!x.empty())
      {
      	int xx=x.front();
      	int yy=y.front();
      	x.pop();
      	y.pop();
      	for(int i=0;i<8;i++)
      	  {
      	  	if(xx+zun[i][0] <=m && yy+zun[i][1] <=n && xx+zun[i][0] >=0 && yy+zun[i][1] >=0)
      	  	  {
                int xxx=xx+zun[i][0];
      	  		int yyy=yy+zun[i][1];
      	  		if(a[xxx][yyy] == '@')
      	  	  	  {
      	  	  		x.push(xxx);
      	  	  		y.push(yyy);
      	  	  		a[xxx][yyy]='*';
              	  }
              }
          }
      }
}
