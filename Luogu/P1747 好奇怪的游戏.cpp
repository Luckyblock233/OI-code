//所用算法：BFS
//将马向(1,1)跳转换为(1,1)向马跳 
//非常简单,见注释
#include<cstdio>
#include<cstring>
using namespace std;
int xx[12]={-2,-2,-1,1,2,2,2,2,1,-1,-2,-2};//各位置的增减量 
int yy[12]={1,2,2,2,2,1,-1,-2,-2,-2,-2,-1};
int s[110][110];//储存步数 
int poi[15000][3];//队列数组，储存 位置 
int main()
{
	int xa,ya,xb,yb;
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);//输入 
	memset(s,-1,sizeof(s));//初始化s,便于判断,防止重复 
	int l=1,r=1;//首尾指针 
	poi[1][1]=1;//第一个队列元素是(1,1) 
	poi[1][2]=1;
	s[1][1]=0;//到达(1,1)步数为0 
	while(l<=r)//队列不为空 
	  {
	  	for(int i=0;i<12;i++)//列举变化后的位置 
	  	  {
	  	  	int xxx=poi[l][1]+xx[i];//变化 
	  	  	int yyy=poi[l][2]+yy[i];
	  	  	if(s[xxx][yyy]==-1 && xxx<=100 && yyy<=100 && xxx>0 && yyy>0)//判断步数是否为空且是否出界 
	  	  	  {
	  	  	  	s[xxx][yyy]=s[poi[l][1]][poi[l][2]]+1;//变化后的步数为前位置步数加一 
	  	  	  	r++;
	  	  	  	poi[r][1]=xxx;//放入队列 
	  	  	  	poi[r][2]=yyy;
			  }
			if(s[xa][ya]!=-1 && s[xb][yb]!=-1)//要输出的位置是否有值 
			  {
			  	printf("%d\n%d",s[xa][ya],s[xb][yb]);
			  	return 0;//           stop!!!! 
			  }
		  }
		l++;
	  }
}
