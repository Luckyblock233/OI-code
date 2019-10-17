//知识点:DP/贪心
/*
求最长波动(?)子序列
可以使用DP,但是贪心的时间复杂度更优 

贪心方法:
先选定第一个是上升/下降
对于之后的元素,
1.如果一直下降,
  显然,那么选择最低的会更优
2.如果一直上升,
  同上,选择最高的
3.如果 下降/上升 途中出现 上升/下降 的
  那么就一定选择 此时出现的突兀的元素

只需要将数列扫2遍即可
复杂度O(2n)
*/
#include<cstdio>
#include<cctype>
const int MARX = 1e6+10;
//=============================================================
int n,m , a[MARX];
int s[MARX]={MARX};
int ans=1,marx;
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
	n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)//g2i>g2i-1 情况
	{
	  if(marx%2==0)//分情况枚举
	  {
	  	s[++marx]=a[i++];//添加答案
	  	while(a[i]<=s[marx])//选择最值
	  	{
	  	  s[marx]=a[i];
	  	  if((++i)>n)break;//越界
		}
		i--;
	  }
	  else
	  {
		s[++marx]=a[i++];//添加答案
	  	while(a[i]>=s[marx])
	  	{
	  	  s[marx]=a[i];//选择最值
	  	  if((++i)>n)break;//越界
		}
		i--;
	  }
	}

    if(marx>ans) ans=marx;//记录答案
	marx=0,s[0]=-10;

    for(int i=1;i<=n;i++)//g2i<g2i-1  同上
	{
	  if(marx%2==1)
	  {
	  	s[++marx]=a[i++];
	  	while(a[i]<=s[marx])
	  	{
	  	  s[marx]=a[i];
	  	  if((++i)>n)break;
		}
		i--;
	  }
	  else
	  {
		s[++marx]=a[i++];
	  	while(a[i]>=s[marx])
	  	{
	  	  s[marx]=a[i];
	  	  if((++i)>n)break;
		}
		i--;
	  }
	}
	if(marx>ans) ans=marx;//记录答案
    printf("%d",ans);
}
