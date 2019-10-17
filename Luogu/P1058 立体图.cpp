//知识点:模拟 
/*
优先枚举较外层的积木  
（因为他们会遮挡后层积木）  
通过行数与层数关系，  
可以得到每个积木最左下角的坐标  

根据最左下角的坐标，  
可以构建一个小积木  
再判断有无积木遮挡  
并将不会被遮挡的部分加入字符数组  
即可  
*/ 
#include<cstdio>
#include<cctype>
#include<cstring>
#define max(a,b) a>b?a:b
using namespace std;
//=======================================================
const char stdd[8][8]=
{
	{' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' },//单位立方体
	{' ' ,'+' ,'-' ,'-' ,'-' ,'+' ,'=' ,'=' },
	{' ' ,'|' ,' ' ,' ' ,' ' ,'|' ,'/' ,'=' },
	{' ' ,'|' ,' ' ,' ' ,' ' ,'|' ,' ' ,'+' },
	{' ' ,'+' ,'-' ,'-' ,'-' ,'+' ,' ' ,'|' },
	{' ' ,'=' ,'/' ,' ' ,' ' ,' ' ,'/' ,'|' },
	{' ' ,'=' ,'=' ,'+' ,'-' ,'-' ,'-' ,'+' },
};
int n,m,K,L;
int map[55][55];
char ans[1010][1010];
int dep[1010][1010];
//=======================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void add(int zx,int zy,int depp)//添加一个立方体
{
	int zzy,zzx;
	for(zzy=zy ; zzy<=zy+5; zzy++)//枚举坐标
	  for(zzx=zx ; zzx<=zx+6; zzx++)
	    if(ans[zzy][zzx] == '.' || depp==dep[zzy][zzx])//可以添加
	    {
	      ans[zzy][zzx]=(stdd[zzy-zy+1][zzx-zx+1]=='='?ans[zzy][zzx]:stdd[zzy-zy+1][zzx-zx+1]);//赋值
	      dep[zzy][zzx]=depp;	
		}
}
signed main()
{
	memset(ans,46,sizeof(ans));//初始化
	memset(dep,127,sizeof(dep));
	scanf("%d%d ",&m,&n);
	for(int i=m;i>=1;i--)
	  for(int j=1;j<=n;j++)
	    scanf("%d",&map[i][j]);
	int now_y=-1,now_x=1;
	for(int i=1;i<=m;i++)//枚举坐标
	{
	  now_y+=2;
	  for(int j=1;j<=n;j++)
	  {
	  	for(int k=1;k<=map[i][j];k++)
		{
	  	  add(now_x,now_y+(k-1)*3,i);//添加矩阵
	  	  K=max(K,now_y+3*k+2);
		}
		L=max(L,now_x+6);
		now_x+=4;
	  }
	  now_x=2*(i+1)-1;
	}
	for(int i=K;i>=1;putchar('\n'),i--)//输出
	  for(int j=1;j<=L;j++)
	  	putchar(ans[i][j]);
}
