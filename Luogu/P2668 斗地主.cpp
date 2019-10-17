//知识点:搜索,模拟,贪心 
/*
By:Luckyblock
考虑 n<=4,30分:
n=2时: 只可能出现:单牌,对子,王炸
n=3时: 只可能出现:单牌,对子,三牌,王炸 
n=4时: 只可能出现:单牌,对子,三牌,三带一,炸弹,王炸
	对于三带一 和 炸弹,可以看做同一类,
	即只要有 三张码数相同的牌,
	就可以选择任意另一张 同时打出 

根据上述进行暴力判断即可 
*/
#include<cstdio>
#include<ctype.h>
//=============================================================
int T,n; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	T=read(),n=read();
	for(;T;T--)
	{
	  int num[16]={0}, ans=0, res=n, flag=0;
	  for(int i=1;i<=n;i++)
	  {
	  	int a=read(),b=read();
	  	if(a==0) a=13+b;
		num[a]++;
	  }
	  
	  for(int i=1;i<=13 && n>=3;i++)//三张码数相等的牌
	    if(num[i]==3)//(构成 炸弹/三带一/三牌 ) 
	    {
	      printf("1\n");
	      flag=1;break;
		}
	  if(flag) continue;//已经无牌 
	  
	  for(;num[14]&&num[15]; num[14]--,num[15]--)//循环王炸 
	    ans++,res-=2;
	  
	  for(int i=1;i<=13;i++)//两张码数相等的牌 
	  {
	    if(num[i]==2) num[i]=0,ans++,res-=2;//贪心,能出对子就出 
		if(!res)//无牌 
		{
		  printf("%d\n",ans);
		  flag=1;break;
		}
	  }
	  if(flag) continue;//已经无牌 
	  
	  printf("%d\n",ans+res);
	  //已经不能出对子,将剩下的牌都按照单牌出 
	}
}
