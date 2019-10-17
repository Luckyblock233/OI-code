//知识点: dfs 
/*
题目大意: 
要找到所有的单词 yizhong
并且单词的排列方向不变 

算法实现: 
直接枚举字母 y出现的位置 ,
然后检查周围8个格子内有无字母 i
如果有,按照此方向继续进行检查
看有无完整单词
如果有完整单词,进行标记记录

最后检查哪些点未被标记,
将其变成 '*' 即可 
*/
#include<cstdio>
#include<iostream>
#include<string>
const int ex[9]={0,1,-1,0,0,1,-1,1,-1};
const int ey[9]={0,0,0,1,-1,1,1,-1,-1};
//=============================================================
int n; 
std::string stdd = "[yizhong]";//标准单词 
char map[110][110];//原图 
bool word[110][110];//标记是否为单词, 
//=============================================================
void check(int x,int y)
{
	for(int i=1,nx=x+ex[i],ny=y+ey[i];i<=8;i++,nx=x+ex[i],ny=y+ey[i])//枚举能到达的点 
	  if(map[nx][ny]=='i')//第二个位置 
	    {
	      bool flag=1;
	      for(int j=1,nowx=x,nowy=y;j<=7;j++,nowx=nowx+ex[i],nowy=nowy+ey[i])//检查是否有完整单词 
	        if(map[nowx][nowy]!=stdd[j])
	          flag=0;
	      if(flag)
	        for(int j=1,nowx=x,nowy=y;j<=7;j++,nowx=nowx+ex[i],nowy=nowy+ey[i])//在单词的区域打标记 
	          word[nowx][nowy]=1;	
		}
}
//=============================================================
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    std::cin>>map[i][j];
	
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    if(map[i][j]=='y')//找到 y 出现的点 
	      check(i,j);
	
	for(int i=1;i<=n;putchar('\n'),i++) 
	  for(int j=1;j<=n;j++)
	    printf("%c",word[i][j]?map[i][j]:'*');//将未被标记的点转化为'*' 
}
