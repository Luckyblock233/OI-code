//�㷨:DFS����
//˼·:dfs����Ҫ��ֵ���s��������ĸ���t 
//�Դ���������Ϊ��㣬ѭ���Ҳ�����s����i,
//��֤�µ���С��ǰ�����, (Ϊ�����ظ���)
//��s-i>=0 ,��ʹs-i,��ʹ���е�t����Ϊi
//����ʱsΪ0,�Ϳ���ʹ����+1 
//��Ϊ0,�ͼ���������һ��tλ�� 
#include<cstdio>
using namespace std;
int n,k,tot;
int ans[10000]={1,1};
void dfs(int s,int t);
int main()
{
	scanf("%d%d",&n,&k);
	dfs(n,1);
	printf("%d",tot);
}
void dfs(int s,int t)
{
	if(t>k || s<t) return ;
	for(int i=ans[t-1];i<=s;i++)//��s���� 
	  if(s-i>=0)//��������
	    {
	      ans[t]=i;//����� 
	      s-=i;//��ȥ 
	      if(t==k && s==0) 
			tot++;//�������� 
	      else dfs(s,t+1);//�������� 
	      s+=i;//����,ʹs+i,����״̬ 
		}
	return ;
}
