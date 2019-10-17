//知识点:康托展开
/*
进制数 所代表的的 十进制数
即 此全排列的康托展开

先对给出全排列
进行进制分解

在对分解后的序列
加上要求的数 

再将改变后的序列
转换为全排列即可 
*/ 
#include<cstdio>
#include<cctype>
//==============================================
const int MARX = 1e4+10;
int n,m;
int a[MARX],used[MARX],use[MARX];
//==============================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//==============================================
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//输入原序列 
	  {
	  	scanf("%d",&a[i]);
	  	int tmp=0;
	  	for(int j=1;j<=a[i];j++)//进行进制转换 
	  	  tmp+=(!used[j]);
	  	used[a[i]]=1;
	  	a[i]=tmp-1;
	  }
	  
	a[n]+=m;
	for(int i=n;i>=1;i--)//加上一个数 
	  {
	  	a[i-1]+=a[i]/(n-i+1);//进位 
	  	a[i]%=n-i+1;//加数 
	  }
	
	for(int i=1;i<=n;i++)//转换为全排列 
	  {
	  	for(int j=0;j<=a[i];j++)
	  	  if(use[j]) a[i]++;
	  	printf("%d ",a[i]+1);
	  	use[a[i]]=1;
	  }
}
