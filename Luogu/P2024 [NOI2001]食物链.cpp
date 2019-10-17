//知识点:并查集
/*
本题中有三种生物 , 
故也有三种关系
简单维护两个并查集并不可取
所以试着维护三个并查集:

开三倍空间的并查集 , 
1~n ,     存同类
n+1~2*n , 存猎物
2*n+1~3*n 存天敌

如果x和y是同类 , 
则将 x,y并集 , 
将x+n,y+n(即x,y的猎物)并集 , 
将x+2*n,y+2*n(即x,y的天敌)并集 

如果x是y的敌人 , 
则将 x和y的敌人y+2*n并集 , 
将x的猎物x+n 和 y的敌人y+2*n 并集 , 
将x的敌人x+2*n和y的猎物y+n并集.

每次查询时,查询x,y和对方的猎物,敌人关系
是否与给出的关系矛盾即可
*/
#include<cstdio>
#include<cctype>
const int MARX = 5e4+10;
//=======================================================
int n,k,ans;
int pre[MARX*3];
//=======================================================
inline int read()
{ 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int find(int x)//查集
{
	return pre[x]==x?x:pre[x]=find(pre[x]);
}
void join(int x,int y)//并集
{
	int fa1=find(x),fa2=find(y);
	pre[fa1]=fa2;
}
//=======================================================
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=3*n;i++) pre[i]=i;//初始化
	for(int i=1;i<=k;i++)
	{
	  int q=read(),x=read(),y=read();
	  if(x>n || y>n) {ans++;continue;}//如果输入的编号大于n,则必然为假话
	  if(q==1)//如果x,y为同类
	  {
		if(find(x+n)==find(y) || find(x+2*n)==find(y)) {ans++;continue;}//查询x是否吃y,y是否吃x
		join(x,y),join(x+n,y+n),join(x+2*n,y+2*n);//添加同类关系
	  }
	  if(q==2)//如果x是y的敌人
	  {
		if(find(x)==find(y) || find(x+2*n)==find(y)){ans++;continue;}//查询x和y是否是同类,y是否吃x
		join(x,y+2*n),join(x+n,y),join(x+2*n,y+n);//添加敌对关系
	  }
	}
	printf("%d",ans);
} 
