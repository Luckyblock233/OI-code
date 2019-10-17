//算法：模拟
//按照题目要求模拟即可
//详见注释 
#include<cstdio>
#include<map>
using namespace std;
int n,m;
int a[100010];
map <int,int> s;//map存获得的奖数 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//输入获得第一种奖的人 
	  {
	  	scanf("%d",&a[i]);
	  	s[a[i]]++;//累加 
	  }
	for(int j=1;j<=m;j++)// 输入获得第二种奖的人 
	  {
	  	int x;
	  	scanf("%d",&x);
	  	s[x]++;//累加 
	  }
	for(int i=1;i<=n;i++)//找到获得两种奖的人 
	  if(s[a[i]]==2)
	    printf("%d ",a[i]);
} 
/*
//二分查找法 
//先输入数据
//再将b数组升序排列
//再在b数组中二分查找a数组中的每一个元素
//能找到则答案加一
 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[100010],b[100010];
bool search(int k)// 二分查找 
{
	int l=1,r=m;
	while(l<=r)
	  {
	    int mid=(l+r)/2;
		if(b[mid]>k) r=mid-1;
		if(b[mid]<k) l=mid+1;
		if(b[mid]==k) return 1;
	  }
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//输入 
	  scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)
	  scanf("%d",&b[j]);
	sort(b+1,b+m+1);//排序 
	for(int i=1;i<=n;i++)//查找 
	  if(search(a[i]))
	  	printf("%d ",a[i]);
} 
*/
