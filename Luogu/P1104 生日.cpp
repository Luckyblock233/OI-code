//�㷨������
/*
���鷳������
�ýṹ��洢ÿ���˵���Ϣ
������һ������,������ʱ�Ĵ���

������,��,����������
��,��,����ͬ��,�����������������

������� 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
const int MARX = 110;
struct baka9//�ṹ��洢ÿ���˵���Ϣ 
{
	string na;
	int ye,mo,da;
	int order;
}a[MARX];
bool cmp(baka9 a,baka9 b)//���� 
{
	if(a.ye==b.ye)
	  {
	  	if(a.mo==b.mo)
	  	  {
	  	  	if(a.da==b.da) return a.order>b.order;
	  	  	return a.da<b.da;
		  }
	  	return a.mo<b.mo;
	  }
	return a.ye<b.ye;
}
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	  {
	  	cin>>a[i].na>>a[i].ye>>a[i].mo>>a[i].da;
	  	a[i].order=i;//����� 
	  }
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	  cout<<a[i].na<<endl;
}
