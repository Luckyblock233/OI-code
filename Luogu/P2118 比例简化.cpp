//算法: 暴力枚举/gcd 
/*
L小于等于100，
则可以直接枚举分子和分母。
可以看出分子分母的枚举范围都是1到L，
之后可以写一个最大公约数，
判断分子分母的最大公约数是否为1
然后到了本题的第一个坑：
分子分母的比值要大于A和B的比值。
根据小学数学的交叉相乘法，
就可以将这个式子写成：现分子*B<=现分母*A。
到了最后一个条件了，
使分子分母的比值要尽可能地接近A和B的比值，
可以把所有符合上面两个条件的分子分母在一起比较，
选出最优解。
*/
#include<cstdio>
using namespace std;
int gcd(int x,int y)//最大公约数 
{
    return y?gcd(y,x%y):x;
}	
int a,b,l;
int main()
{
	scanf("%d%d%d",&a,&b,&l);
	int ans1=l,ans2=1;
	for(int i=1;i<=l;i++)//枚举答案 
	  for(int j=1;j<=l;j++)
	    if(gcd(i,j)==1 && i*b>=j*a && i*ans2<j*ans1)
	      ans1=i,ans2=j;
	printf("%d %d",ans1,ans2);
}
