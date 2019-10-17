#include<cstdio>
#include<cmath>
using namespace std;
int n1,r1;//输入的数的个数和序列的长度 
int s=0;//个数 
int a[25];//其实并没有什么用的a数组 
int d[25];//储存输入的数 
bool zhi(int n)//判断素数 
{
	if(n<=1) return 0;
	int p=1;
	for(int k=2;k<=sqrt(n);k++)
	  if((n%k==0) && (k!=n)) p=0;
	if(p==1) return 1;
}
void z(int n,int r,int b[25])
{
    if(r==r1)//到达边界 
      {
      	int p=0;
      	for(int i=0;i<r1;i++) p+=b[i];//求和 
      	if(zhi(p)==1) s++;//判断 
      }
    else
      for(int i=n;i<n+n1;i++)
        {
      	  int c[25];//因为直接对b处理会出错,所以设置c数组中转 
          for(int j=0;j<=r1;j++) c[j]=b[j];
      	  c[r]=d[i];//给此位置赋值 
          if(i < n1) z(i+1,r+1,c); //开始找下一个位置 
        }
}
int main()
{
    scanf("%d%d",&n1,&r1);
    for(int i=0;i<n1;i++) scanf("%d",&d[i]);
    z(0,0,a);//从位置0,a[0]开始,开始递归 
    printf("%d",s);//输出 
}
