//֪ʶ��:����,ģ��
/* 
����һ���뵽�ķ���ģ������

����ÿһ��û�и߶�Ϊ0�ĵ������,
���������� ��С�ĸ߶�
֮��ݹ�,
����ʱ�ķǸ߶�Ϊ0�������������

˼·������,����Ҳ����ѧ
���ע��
*/
#include<iostream>
#include<cstdio>
using namespace std;
//============================================
int h[100005];
//============================================
long long block(int l,int r,int minh)//����l~r����,��������СֵΪminh
{
	if(h[l]==0 && h[r]==0) return 0;//ȫ������,ֱ��return
	long long sum=minh;//����Ĵ���
	while(h[l]==minh && l<r) l++;//�����������ȫ������
	int l1=l;//�µ���˵�
	int minnh=100000;//��¼��Сֵ
	for(int i=l;i<=r;i++)
	{
	  h[i]-=minh;//����
	  if(h[i]<minnh && h[i]>=0) minnh=h[i];
	  if(!h[i])//�����˿յ�,˵�����Եݹ���
	  {
	  	sum=sum+block(l1,i-1,minnh);//�ݹ�����
	  	l1=i+1,minnh=100000;//���³�ʼ��
	  }
	  if(i==r) sum=sum+block(l1,i,minnh);//���ﾡͷ,������ʣ�µ�����
	}
    return sum;//����l~r����Ĵ���
}
//============================================
signed main()
{
	int n,minh=100000;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	  	scanf("%d",&h[i]); 
	  	if(h[i]<minh) minh=h[i];//�ҵ���Сֵ
	}
	cout<<block(1,n,minh);//����ģ��
}