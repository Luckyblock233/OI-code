//�㷨��DP
//������������ļ�ֵ,
//״̬ת�Ʒ���ʽ:  
//f[j]=max(f[j],f[j-v[i]]+v[i]);
//��Ϊ������װVM��������f��j��==VM��ֱ���������
//��Ϊû�и��ŵĽ��� 
#include<cstdio>
#include<algorithm>
using namespace std;
int vm,n;
int v[5010];
int f[50010];
int main()
{
	scanf("%d%d",&vm,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
	  for(int j=vm;j>=v[i];j--)
	    {
	      f[j]=max(f[j],f[j-v[i]]+v[i]);
	      if(f[j]==vm)
	        {
	          printf("%d",f[vm]);
			  return 0;	
			}
		}
	printf("%d",f[vm]);
}
