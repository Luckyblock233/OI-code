//��������ģ����
//���ע�� 
#include<cmath>
#include<cstdio>
using namespace std;
int n,k;
int a[2000010];
int q[2000010],head[2000010];
void minn()//��������ģ�� 
{
    int h=1,t=0;
    for(int i=1;i<n;i++)//���i-k����i-1��������Сֵ 
      {
      	while(q[t]>=a[i] && t>=h)//ȡ�������ܳ�Ϊ��Сֵ��Ԫ�� 
      	  t--;
      	q[++t]=a[i];//���� 
      	head[t]=i;//��¼��� 
      	if(head[h]<=i-k)//����,��pop�� 
		  h++;
        printf("%d\n",q[h]);
      }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    printf("0\n");//��1����ǰ��û���� 
    minn();
    return 0;
}
