//知识点:贪心 
/*
将输入数列进行排序
可以发现:
1.若此时最大的,最小的两数之和<=w
  那么将这两个数组成一对,一定是较优的
2.若此时最大,最小的两数之和>w
  那么不再有数,能与最大的数组成一组
  则将最大的数单独作为一组,
  一定是较优的.

按照上述法则, 
使用首尾两指针模拟即可 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
const int MARX = 3e4+10;
//=============================================================
int w,n,ans , p[MARX];
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
	w=read(),n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	std::sort(p+1,p+n+1);//排序 
	for(int l=1,r=n;l<=r;)
	{
	  if(p[l]+p[r]<=w) l++,r--,ans++;//两个组成一组 
	  else r--,ans++;//将最大的单独组成一组 
	}
	printf("%d",ans);
}
