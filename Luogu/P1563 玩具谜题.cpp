//知识点:模拟 
/*
By:Luckyblock
题意给定了详细的模拟方案 
由于数据范围较小, 
直接按照题意进行模拟即可
详见注释 
*/
#include<cstdio>
#include<iostream>
#include<ctype.h>
const int MARX = 1e5+10;
//=============================================================
std::string name[MARX];//存姓名 
int n,m,ans=1,dir[MARX];//存朝向 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	  std::cin>>dir[i]>>name[i];
}
//=============================================================
signed main()
{
	prepare();
	for(int i=1;i<=m;i++)//开始模拟 
	{
	  int ai=read(),si=read()%n;
	  if( (ai==1 && dir[ans]==0) || (ai==0 && dir[ans]==1))//旋转 
	  {
	  	ans=ans+si;
	  	if(ans>n) ans-=n;//越限 
	  }
	  else//反向旋转 
	  {
		ans=ans-si;
		if(ans<1) ans+=n;//越限 
	  }
	}
	std::cout<<name[ans];
}
