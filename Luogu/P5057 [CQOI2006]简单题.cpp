//֪ʶ��:��״����/������� 
/*
��ʼ��һȫ��Ϊ0������ 
��Ŀ�������ֲ���:
1.��תĳ������(1->0,0->1) 
2.��ѯĳ���� (���0,1���) 

����һ����,ֻ��0 ,1�������
��ֻ�з�ת����
 
����ֻ��Ҫ��¼
ÿ����ı���ת����

�Ϳ����˳��õ��0,1���
�����ת����Ϊ����,��Ϊ1
����Ϊ0

����ͱ���� �����޸�,�����ѯ ��ģ�� 
*/ 
#include<cstdio>
#define lowbit(x) x&(-x) 
using namespace std;
const int MARX = 1e6+10;
int n,m;
int a[MARX],b[MARX],c[MARX];
void add(int x,int y,int n) //�����޸� 
{
	for(int i=x;i<=n;i+=lowbit(i))
	  c[i]+=y;
}
int find(int x)//�����ѯ 
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	  sum+=c[i];
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	int q,x,y;
	  	scanf("%d",&q);
	  	if(q==1)
		  {
		  	scanf("%d%d",&x,&y);
		  	add(x,1,n),add(y+1,-1,n);
			//Ӧ�ò��˼��,����������޸� 
		  }
	  	else
	  	  {
	  	  	scanf("%d",&x);
	  	  	int ans=find(x);//�����ѯ 
	  	  	printf("%d\n",ans%2?1:0);//���0,1��� 
		  }
	  }
}
