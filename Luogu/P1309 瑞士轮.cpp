//算法：模拟，归并排序
//先按照初始分数排一遍序
//之后开始模拟比赛. 
//将胜利的人加入win数组,将输的人加入los数组 
//根据题意,可以得知: 
//由于原序列中的人是按照 先分数降序 再编号升序 的顺序排列的
//由于只有胜者才加分 
//所以在win数组与los数组中,也保证了 先分数降序 再编号升序 的有序性质
//根据归并排序,是将两个有序序列合并的原理
//则可以用O(n)的复杂度完成每次排序 

//根据此性质模拟即可 
#include<cstdio>
#include<algorithm>
using namespace std;
struct person
{
	int s,w,num;
}a[200010];
int n,r,q;
int s[200010],w[200010];
person win[200010],los[200010];
bool cmp(person aa,person bb)//初始排序 
{
	if(aa.s==bb.s) return aa.num<bb.num;
	return aa.s>bb.s;
}
void merge()//归并排序 
{
	int i=1,j=1,k=1;
	while(i<=n && j<=n)
	  {
	  	if(win[i].s>los[j].s) 
		  a[k++]=win[i++];//先按分数降序排 
	  	else
	  	  if(win[i].s==los[j].s && win[i].num<los[j].num) 
			a[k++]=win[i++];//分数相同按编号 
	  	  else  a[k++]=los[j++];//分数降序 
	  }
	while(i<=n) a[k++]=win[i++];//归并排序,将剩余的加入到序列中 
	while(j<=n) a[k++]=los[j++];
}
int main()
{
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++)//输入 
	  {
	  	scanf("%d",&a[i].s);
	  	a[i].num=i;
	  }
	for(int j=1;j<=2*n;j++)
	  scanf("%d",&a[j].w);
	sort(a+1,a+2*n+1,cmp);
	while(r--)//进行r轮 
	  {
	  	for(int i=1;i<=2*n-1;i+=2)//模拟比赛 ,并将胜负者加入win,los数组中 
	  	  if(a[i].w>a[i+1].w) 
			a[i].s+=1,win[i/2+1]=a[i],los[i/2+1]=a[i+1]; 
	  	  else 
			a[i+1].s+=1,win[i/2+1]=a[i+1],los[i/2+1]=a[i];
	  	merge();//归并 
	  }
	printf("%d",a[q].num);//输出 
}
