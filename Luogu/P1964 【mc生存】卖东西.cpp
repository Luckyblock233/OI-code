//�㷨��DP/01����
//��Ȼ��Ŀ��ʾ���Ƕ��ر���
//ʵ������01����=_=

//���������Ʒ, ������𣬴��¸���Ʒ�����������ޡ�
//Ȼ����в��,�������������޵���Ʒ,
//����������Ϊ����, 
//������һ������Ϊ ԭ����-���� ����Ʒ
//һֱ��⵽����������.

//֮����һ��01�������� 
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int m,n,num;
int a[1100],b[1100],c[1100];
int f[25];
map <string,int> gr;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)//��������,������¼ 
	  {
	  	int a1,b1,c1;
	  	string s;
	  	cin>>a1>>b1>>c1;
	  	cin>>s;
	  	if(!gr[s]) a[++num]=a1,b[num]=b1,c[num]=c1,gr[s]=num;//û�г��ֹ� 
		else a[gr[s]]+=a1;  //���ֹ� 
	  }
	m=21-m;//�������� 
	for(int i=1;a[i];i++)//��� 
	  if(a[i]>c[i])//�������� 
	    {
	      a[++num]=a[i]-c[i];//��������Ʒ 
	      b[num]=b[i];
	      c[num]=c[i];
	      a[i]=c[i];//ԭ��Ʒ�����ı� 
		}
	for(int i=1;i<=num;i++)//��01���� 
	  for(int j=m;j>=1;j--)
	    f[j]=max(f[j],f[j-1]+a[i]*b[i]);
	printf("%d",f[m]);
}
