//�㷨:DP/ģ��/(����) 
// �������֪,ÿһ����Ĵ�
//���������·�,�·�,���·��е����ֵ�õ�
//�ɴ�,���Խ���DP,Ҳ�������� 

//״̬ת�Ʒ���: map[i][j]+=max(map[i+1][j+e[k]])
//[i+1][j+e[k]]Ϊ���Ե���i�ĵ� 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans=-2100000000;
int map[210][210];//map��ͼ, 
bool f[210][210];//���Ƿ���Ե��� 
int e[4]={0,-1,0,1};//������仯�� 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&map[i][j]);//���� 
	f[n+1][m/2+1]=1;//��ʼ����� 
	for(int i=n;i>=1;i--)//dp 
	  for(int j=1;j<=m;j++)
	    {
	      int maxx=-2100000000; 
		  for(int k=1;k<=3;k++)//�ҵ����ֵ 
		    if(j+e[k]>=1 && j+e[k]<=m && f[i+1][j+e[k]])//��Խ�� 
		      maxx=max(maxx,map[i+1][j+e[k]]); 
		  map[i][j]+=maxx;//��ֵ 
		  f[i][j]=1;//��� 
		} 
	for(int i=1;i<=m;i++)//�ҵ����ֵ 
	  ans=max(ans,map[1][i]);
	printf("%d",ans);//��� 
}
