#include<cstdio>
#include<string>
#include<queue>
#include<ctype.h>
#include<map>
//=============================================================
int sta[MARX][MARX],end[MARX][MARX];
int T,n,m;
string s,e;
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void bfs()
{
    std::queue <string> q;
    map <string,int> step;
    q.push(s);

    while(!q.empty())
    {
      string now=q.top();
      q.pop();
      for(int i=0;i<m;i++)
        for(int j=i+1;i<=m;j++)
        {
          string to=now , tmp=;
          tp.
        }
      for(int i=1;i<=n;n++)
        for(int j=n;j<=n*m;j+=m)
        {
          
        }
      
    }
}
//=============================================================
signed main()
{
	T=read();
    while(T--)
    {
      n=read(),m=read();
      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          sta[i][j]=read();
      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          end[i][j]=read();
      
      for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
          s.push_back(sta[i][j]),
          e.push_back(end[i][j]);
      bfs();
    }
}