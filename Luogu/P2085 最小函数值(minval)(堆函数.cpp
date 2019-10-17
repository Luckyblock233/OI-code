//真**难写！！！垃圾堆函数！！！毁我青春！！！ 
#include<cstdio>
#include<algorithm>
using namespace std;
int dui[30010];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	int n,m,a,b,c;
	int ans[50000];
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);//初始处理 
	for(int j=1;j<=m;j++)
	  dui[j-1]=a*j*j+b*j+c;
	make_heap(dui,dui+m,cmp);//建堆 
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);
	  	for(int j=1;j<=m;j++)
	  	  {
	  	  	 if(a*j*j+b*j+c < dui[0])//与堆中最大数比较 
	  	      {
	  	      	pop_heap(dui,dui+m,cmp);//删掉堆顶元素 
	  	      	dui[m-1]=a*j*j+b*j+c;//将新数放到堆底 
	  	      	push_heap(dui,dui+m,cmp);//组成新堆 
	  	      }
	  	    else
				break;//stop!!! 
	  	  }
	  }
	for(int i=m;i>=1;i--)//转成正序 
	  {
	  	ans[i]=dui[0];
	  	pop_heap(dui,dui+i,cmp);
	  }
	for(int i=1;i<=m;i++)
	  printf("%d ",ans[i]);
}
