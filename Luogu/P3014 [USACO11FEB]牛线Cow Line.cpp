//֪ʶ��:����չ�� 
/*
����չ��ģ����

��������,����չ��
�����濵��չ�� 
*/
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#define int long long
#define lowbit(a) a&(-a)
//============================================
int n,sum;
int a[25],b[25],use[25],fac[25] = {1,1};
//============================================
inline int read()//���⿨��� 
{
	int tmp;
	scanf("%lld",&tmp);
	return tmp;
}
void cantor()//����չ�� 
{
	sum=0;
	memset(use,0,sizeof(use));//��ʼ�� 
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	  {
	  	b[i]=read();//ת�������� 
	  	int tmp=b[i];
		for(int j=1;j<=b[i];j++)//��ȥ�ظ��� 
	  	  tmp-=use[j];
	  	use[b[i]]=1;
	  	b[i]=tmp-1;
	
	    sum+=fac[n-i]*b[i];//����ת����չ�� 
	  }
	printf("%lld\n",sum+1);
}
void re_cantor()//�濵��չ�� 
{
	memset(a,0,sizeof(a));//��ʼ�� 
	memset(use,0,sizeof(use));
	int x=read()-1;
	for(int i=1;i<=n;i++)//ת���Ʊ�ʾ 
	  {
	  	a[i]=x/fac[n-i];
	  	x%=fac[n-i];
	  }
	
	for(int i=1;i<=n;i++)//ת��Ϊȫ���� 
	  {
	  	for(int j=0;j<=a[i];j++)
	  	  if(use[j]) a[i]++;
	  	printf("%lld ",a[i]+1);//��� 
	  	use[a[i]]=1;
	  }
	printf("\n");
}
//============================================
signed main()
{
	n=read();
	int k=read();
	for(int i=1;i<=n;i++)
	  fac[i]=fac[i-1]*i;//����׳� 
	while(k--)
	  {
	  	char q;
	  	std::cin>>q;
	  	if(q=='Q') cantor();
	  	else re_cantor();
	  }
}
