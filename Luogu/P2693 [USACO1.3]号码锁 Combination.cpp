//�㷨:����ö�� 
//��������ѭ��ö���������
//Ȼ���ж��Ƿ�Ϸ� 
#include<cstdio>
using namespace std;
int n,ans;
int a,b,c,d,e,f;
int abs(int x)
{
	return x<0?x*(-1):x;
}
int main()
{
	scanf("%d%d%d%d%d%d%d",&n,&a,&b,&c,&d,&e,&f);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      if(((abs(i-a)<=2||abs(i-a)>=n-2)&&(abs(j-b)<=2||abs(j-b)>=n-2)&&(abs(k-c)<=2||abs(k-c)>=n-2))||((abs(i-d)<=2||abs(i-d)>=n-2)&&(abs(j-e)<=2||abs(j-e)>=n-2)&&(abs(k-f)<=2||abs(k-f)>=n-2)))ans++;//������ã�������������������һ 
	printf("%d",ans);
} 
