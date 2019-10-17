//本题目基本思路:
//分别找到能横向与纵向的学生,若能找到,则它们中间的分割线能分开的学生对数++.
// 再对横向与纵向的分割线按照分开学生对数进行降序排列,这样就找到了分开最多学生的线
//之后再按照序号顺序再排一遍序
//最后分别输出k,l个即可 

//是一道很简单的贪心(思路半小时,代码2分钟) 
#include<cstdio>
#include<algorithm>
using namespace std;
struct aax
{
	int ren,data;
}
ax[1010];// 分开横向学生的线 
struct aay
{
	int ren,data;
}ay[1010];// 分开纵向学生的线 
int lx=0,ly=0;
bool cmpdax(aax x,aax y)//按照分开学生对数大小排序 
{
	if(x.ren==y.ren)
	  return x.data<y.data;
	return x.ren>y.ren;
}
bool cmpday(aay x,aay y)
{
	if(x.ren==y.ren)
	  return x.data<y.data;
	return x.ren>y.ren;
}
bool cmps1(aax x,aax y)
{
	return x.data<y.data;
}
bool cmps2(aay x,aay y)
{
	return x.data<y.data;//按照序号排序 
}
int main()
{
	int m,n,k,l,d;
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(int i=1;i<=m;i++)
	  ax[i].data=i;// 赋编号 
	for(int i=1;i<=n;i++)
	  ay[i].data=i;//赋编号 
	for(int i=0;i<d;i++)//输入 
	  {
	  	int z[5],judge;//输入坐标 
	  	scanf("%d%d%d%d",&z[1],&z[2],&z[3],&z[4]);
	  	if(z[1]==z[3]) judge=0;//若可在横向说话 
	  	if(z[2]==z[4]) judge=1;//若可在纵向说话 
	  	if(judge==0) ax[min(z[2],z[4])].ren++;//对应纵向分割线++ 
		else ay[min(z[1],z[3])].ren++;//对应横向分割线++ 
	  }
//------------------------------------------------------------------------------------ 
	sort(ax+1,ax+n+1,cmpdax);//冗长的排序 
	sort(ay+1,ay+m+1,cmpday);
	sort(ax+1,ax+l+1,cmps1);
	sort(ay+1,ay+k+1,cmps2);
	for(int i=1;i<=k;i++)//直接输出即可 
	  printf("%d ",ay[i].data);
	printf("\n");
	for(int i=1;i<=l;i++)
	  printf("%d ",ax[i].data);
}
