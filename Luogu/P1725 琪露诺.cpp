//算法:DP(单调队列维护) 

/*
简单的转移方程式: f[i]= max (f[i-r,i-r])+a[i]
但是n方复杂度对200000的数据量来说,就是送命的

优化:
要找到区间[i-r,i-l]内的最大值,
可以用优先队列,但是(nlogn)还是慢了些
这时候复杂度为(n)的单调队列登场了

将f数组先初始化为极小值 
因为琪露诺可以移动到[i+l,i+r]区间内的点
则除[1,l-1]外,其他任何点都可到达
则计算f[i]时,从l开始枚举即可,不需要考虑到不了的点
(因为他们不会被更新,f永远是极小值) 
每次都将i-l放入单调队列,并进行维护
并依次删去队首k+r<i的,即到达不了i点的 
此时队首元素即为要求的max (f[i-r,i-r]); 

全扫一遍后,再从能够到达河对岸的点
即属于[n-r+1,n]的点中找最大的f
得到的就是答案 
*/ 
#include<cstdio>
#include<algorithm>
#include<cstring>
const int MARX=0xf;
const int MAXX = 3e5+10;
//============================================================
int n,l,r,ans;
int a[MAXX],f[MAXX];
int queue[MAXX],head[MAXX];
int h=1,t=1;
//============================================================
int maxx(int i)//获取最大的f[i],单调队列模板 
{
    while(queue[t]<=f[i] && t>=h) t--;
    queue[++t]=f[i];//放入 
    head[t]=i;
    while(queue[h]+r<i) h++; //删掉不能到达的 
    return head[h];//返回 
}
//============================================================
int main()
{
    memset(f,-MARX,sizeof(f));//初始化极小值 
    ans=-2147483640 , f[0]=0;//初始化各值. 
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);
    for(int i=l;i<=n;i++)//DP过程 
    {
      int k=maxx(i-l);
      f[i]=f[k]+a[i];
      if(i>=n-r+1) ans=std::max(ans,f[i]);//找到能到达河对岸的，即答案 
    }
    printf("%d",ans);
}
