//�㷨:DP
//˼·:
//�������Ƴ�:״̬ת�Ʒ���Ϊ: 
//a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];
//�����ײ㿪ʼ������
//�Ƶ���,�͵õ��˴� 
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010][1010],n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  for(int j=0;j<i+1;j++)
	    scanf("%d",&a[i][j]);//���� 
	for(int i=n-2;i>=0;i--)
	  for(int j=0;j<i+1;j++)
	  	a[i][j]+=max(a[i+1][j],a[i+1][j+1]);//�ӵײ����ϲ��� 
	printf("%d",a[0][0]);//������� 
}
