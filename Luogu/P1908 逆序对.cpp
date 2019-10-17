//算法:归并排序(分治)
//思路:找逆序对,即找比每个数大的,且编号小的数的个数
//因为归并排序,
//将序列按照数组下标顺序,
//分割成了多个有序序列

//所以可以通过套归并排序模板,
//来找到比某个数编号小且值大的数的个数 
//具体见注释 , 核心部分:第27行 
//与此题完全一样的题目:SP6252 SP9722 SP25784
#include<cstdio>
using namespace std;
int n;
int a[500010];
int b1[500010];
long long ans;
void b(int l1,int r1,int l2,int r2)//归并l1~r1与l2~r2 
{
	int i=l1,j=l2,k=1;
	while(i<=r1 && j<=r2)
	  {
	  	if(a[i]<=a[j])
	  	  b1[k++]=a[i++];
	  	else
	  	  {
			b1[k++]=a[j++];
			ans+=(r1-i+1);
			//此处:若数a[j]较a[i]中某数小,
			//则a[i+1]~a[r1]都比a[j]大
			//就得到了(r1-i+1)组逆序列 
		  }
	  }
	while(i<=r1) 
	  b1[k++]=a[i++]; 
	while(j<=r2) 
	  b1[k++]=a[j++];
	for(int i=l1;i<=r2;i++) 
	  a[i]=b1[i-l1+1];
}
void f(int l,int r)//分割序列 
{
	if(l>=r) return ;
	int mid=(l+r)/2;
	f(l,mid);
	f(mid+1,r);
	b(l,mid,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//输入 
	  scanf("%d",&a[i]);
	f(1,n);
	printf("%lld",ans); 
}
