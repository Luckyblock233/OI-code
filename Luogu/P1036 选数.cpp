#include<cstdio>
#include<cmath>
using namespace std;
int n1,r1;//��������ĸ��������еĳ��� 
int s=0;//���� 
int a[25];//��ʵ��û��ʲô�õ�a���� 
int d[25];//����������� 
bool zhi(int n)//�ж����� 
{
	if(n<=1) return 0;
	int p=1;
	for(int k=2;k<=sqrt(n);k++)
	  if((n%k==0) && (k!=n)) p=0;
	if(p==1) return 1;
}
void z(int n,int r,int b[25])
{
    if(r==r1)//����߽� 
      {
      	int p=0;
      	for(int i=0;i<r1;i++) p+=b[i];//��� 
      	if(zhi(p)==1) s++;//�ж� 
      }
    else
      for(int i=n;i<n+n1;i++)
        {
      	  int c[25];//��Ϊֱ�Ӷ�b��������,��������c������ת 
          for(int j=0;j<=r1;j++) c[j]=b[j];
      	  c[r]=d[i];//����λ�ø�ֵ 
          if(i < n1) z(i+1,r+1,c); //��ʼ����һ��λ�� 
        }
}
int main()
{
    scanf("%d%d",&n1,&r1);
    for(int i=0;i<n1;i++) scanf("%d",&d[i]);
    z(0,0,a);//��λ��0,a[0]��ʼ,��ʼ�ݹ� 
    printf("%d",s);//��� 
}
