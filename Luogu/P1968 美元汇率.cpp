//�㷨��DP
//��ĳһ����,
//���Խ��������ת��Ϊ��Ԫ, ���Խ�������Ԫת��Ϊ���,
//���������ֲ���������

//��ĳһ��� ���/��Ԫ ����,������һ��� ��Ԫ/��� �����й�
//����Խ���DP

//״̬ת�Ʒ���: fma[i]=max(fma[i-1],fdo[i-1]*100/a);
//	  			fdo[i]=max(fdo[i-1],fma[i-1]/100*a);
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a;
double fdo[110],fma[110]={100};//doΪ�������maΪ��Ԫ�� 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a);
	  	fma[i]=max(fma[i-1],fdo[i-1]*100/a);//ת�� 
	  	fdo[i]=max(fdo[i-1],fma[i-1]/100*a);
	  }
	printf("%.2lf",fma[n]);  
}
