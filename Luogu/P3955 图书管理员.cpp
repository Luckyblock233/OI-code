//知识点:模拟 
/*
题目要求:
查询当前字串,
是否为另一字串的后缀,
并输出最短的另一字串

很明显,可以使用Trie树,
但是数据范围很小 , n<=1000
直接两层循环模拟即可
详见注释 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
const int MARX = 1010;
//=============================================================
int n,q;
int book[MARX],mul[100]={1};
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//=============================================================
signed main()
{
	for(int i=1;i<=10;i++)mul[i]=mul[i-1]*10;//预处理10^i 
	n=read(),q=read();
	for(int i=1;i<=n;i++) book[i]=read(); 
	std::sort(book+1,book+n+1);//按长度排序 
	for(int i=1;i<=q;i++)
	{
	  int l=read(),now=read(),flag=0;
	  for(int j=1;j<=n;j++) //暴力循环匹配 
	    if(book[j]%mul[l]==now)//取出后10^(l-1)位数字,检测是否匹配 
	    {
	      printf("%d\n",book[j]);
	      flag=1;
	      break;
		}
	  if(!flag) printf("-1\n");
	}
}
