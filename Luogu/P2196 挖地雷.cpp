//�㷨��DP
//����Ϊ�򵥵������޻�ͼ,ע���ǵ���ͼ 
//״̬ת�Ʒ���ʽ: 
//f[i]=max(f[i],f[j]+w[i]),����jΪ���Ե���i�ĵ㡣
//��:i�����ڵ�����������=�ܵ���i��ĵ����ڵ�����������+i����� 
//ע����pre��·�� 
#include<cstdio>
using namespace std;
int n,ans,ans1;
int w[25],f[25],pre[25];
bool map[25][25];
void pr(int k)//�ݹ����·�� 
{
	if(pre[k]==k) 
	  {
	  	printf("%d ",k);
	  	return ;
	  }
	pr(pre[k]);
	printf("%d ",k);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&w[i]);
	  	pre[i]=i;//����,˳���ʼ�� 
	  }
	for(int i=1;i<=n;i++)//�����Ƿ���· 
	  for(int j=i+1;j<=n;j++)
	    {
	      int x;
	      scanf("%d",&x);
	      map[i][j]=x;
		}
	for(int i=1;i<=n;i++)//DP 
	  {
	  	f[i]=w[i];
	  	for(int j=1;j<i;j++)
	  	  if(map[j][i] &&  f[j]+w[i]>f[i])//�滻���� 
	  	  	{
	  	  	  f[i]=f[j]+w[i];
	  	  	  pre[i]=j;
			}
		if(ans<f[i])//��¼�� 
	  	  {
	  	  	ans=f[i];
	  	  	ans1=i;
		  }
	  }
	pr(ans1);
	printf("\n%d",ans);//��� 
}
