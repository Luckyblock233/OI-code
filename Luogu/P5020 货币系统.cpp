//�㷨��DP/���� 
/*
�������: 
��Ŀ����Ҫ��ĳһ�׻���ϵͳ�ĵ�Чϵͳ
����һ��ϵͳ��,ĳһ�����,
�ܲ��ܱ���ϵͳ���������������滻
��ô������ת����Ϊ����ȫ�������� 

�㷨ʵ��: 
����������ݺ󣬼�¼���Ľ��mm��
ͬʱ������Ľ���������б��Ϊ1 
֮��ö�ٴ�1��mm��ÿ�����,�������ǹ�(������1����2), 
��ִ����һ��:

  for(int j=1;j<=n;j++)
    ju[i+a[j]]=2;
 
˵��i+a[j]�����Ա�ԭϵͳ�кϳ�,�������,�����ϳɸ����� 

��һ���,��ö�ٴ�1�� mm �����н��
��������Ϊ1,˵������ԭϵͳ����,�Ҳ��ܱ��ϳ�
�����Ǳ����еĽ��,��++; 
*/
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
//=================================== 
int t,n,max_money,ans;
int a[150];
short ju[50010];
//=================================== 
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void work()
{
	for(int i=1;i<=max_money;i++)//�ҵ��ܱ��ϳɵĽ�� 
	  if(ju[i])
	    for(int j=1;j<=n;j++)
	      ju[i+a[j]]=2;
	for(int i=1;i<=max_money;i++)//��ԭ�е�,�Ҳ��ܱ��ϳɵ�ֵ. 
	  if(ju[i]==1)
		ans++;
}
//=================================== 
signed main()
{
	t=read();
	while(t--)
	{
	  n=read();
	  for(int i=1;i<=n;i++)
	  {
		a[i]=read();
		ju[a[i]]=1;//��¼���ֹ�����Ϊ�������ֵ 
		max_money=std::max(max_money,a[i]);//��¼���ֵ 
	  }
	  work();
	  printf("%d\n",ans);
	  memset(ju,0,sizeof(ju));
	  memset(a,0,sizeof(a));
	  max_money=-1,ans=0;
	}
}
