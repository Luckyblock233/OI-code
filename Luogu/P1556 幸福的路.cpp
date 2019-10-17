#include<cstdio>
#include<ctype.h>
#define R register
//==================================================
struct node
{
	int x,y;
}a[15];
int n,ans;
bool vis[15];
//==================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline bool check(int s,int v,int dir)
{
	switch(dir)
	  {
	  	case 1: {return (a[v].x>a[s].x && a[v].y==a[s].y); }
		case 2: {return (a[v].x<a[s].x && a[v].y==a[s].y); }
		case 3: {return (a[v].x==a[s].x && a[v].y<a[s].y); }
		case 4: {return (a[v].x==a[s].x && a[v].y>a[s].y); }
		default:{return 0;}
	  }
}
inline int getdir(int s,int v)
{
	if(a[v].y==a[s].y) return (a[s].x<a[v].x?1:2);
	return (a[v].y>a[s].y?4:3);
}
void dfs(int s,int dir,int num)
{
	if(num>n)
	  {
	    if((a[s].x==0 || a[s].y==0 ) && (!check(s,0,dir))) 
		  ans++;
	    return ;
	  }
	
	for(R int i=1;i<=n;i++)
	  if(a[i].x==a[s].x || a[i].y==a[s].y)
	    if(!vis[i] && !check(s,i,dir))
	 	  {
	        vis[i]=1;
			dfs(i,getdir(s,i),num+1);
	        vis[i]=0;
	      }
	return ;
}
//==================================================
signed main()
{
	n=read();
	for(R int i=1;i<=n;i++)
	  a[i].x=read(),a[i].y=read();
	dfs(0,0,1);
	printf("%d",ans);
}
