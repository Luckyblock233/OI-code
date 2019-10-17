//算法:模拟
//根据题意模拟即可
//详见注释 
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);//输入 
	int k=2;
	while(n>0)
	  {
      	for(int j=1;j<=k-1;j++)//找同一条对角线上的
      	  {
      	    int l=k-j;//找到
      	    n--;//找到一个数 
      	    if(n==0 && k%2==1)//找到要找的数且k为奇数 
      	      printf("%d/%d",k-l,k-j);
      	    if(n==0 && k%2==0)//找到要找的数且k为偶数 
      	      printf("%d/%d",k-j,k-l);
          }
        k++;//和++ 
      }
}
