#include<iostream>
#include<cstdio>
#include<queue>
#include<ctype.h>
using namespace std;
//======================================================
const int MARX=1e5+10;
queue <int> q,last[301];
int group[MARX];
int n,m,p,koishi_NO_1;
//======================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
signed main()
{
    n=read(),koishi_NO_1=read();
    for(int i=0;i<n;i++)
      group[i]=read();
    m=read();
    for(int i=1;i<=m;i++)
      {
        string s;
        cin>>s;
        if(s=="push")
          {
            cin>>p;
            if(last[group[p]].empty()) q.push(group[p]);
            last[group[p]].push(p);
          }
        else
          {
            printf("%d\n",last[q.front()].front());
            last[q.front()].pop();
            if(last[q.front()].empty()) q.pop();
          }
      }
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int read(int & n)
{
    char c='.';int x=0,flag=0;
    while(c<'0'||c>'9')
    {
        c=getchar();
        if(c=='-')flag=1;
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    if(flag==1)n=-x;
    else n=x;
}
const int MAXN=10000001;
queue<int>q,last[301];
int group[MAXN];
int main()
{
    int n,m,p,meiyong;
    read(n);read(meiyong);
    for(int i=0;i<n;i++)
        read(group[i]);
    read(m);
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        if(s=="push")
        {
            read(p);
            if(last[group[p]].empty())
            q.push(group[p]);
                last[group[p]].push(p);
        }
        else
        {
            printf("%d\n",last[q.front()].front());
            last[q.front()].pop();
            if(last[q.front()].empty())
            q.pop();
        }
    }
    return 0;
}
*/
