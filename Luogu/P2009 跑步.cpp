//�㷨��ͼ��/���·
//���·����,ֻ������Ƚ��鷳
//���ע�� 

//ʹ����Floyd�����· 
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int s,e;
int map[21][21];
void inti()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)//���������ⲿ�ı� 
	  {
	  	int w;
	  	cin>>w;
	  	if(i!=n) map[i][i+1]=map[i+1][i]=w;
	  	else map[i][1]=map[1][i]=w;
	  }
	for(int i=1;i<=k;i++)//���������ڵı� 
	  {
	  	char a,b;
		int w;
	  	cin>>a>>b>>w;
	  	int u=a-'A'+1,v=b-'A'+1;
	  	map[u][v]=map[v][u]=max(w,map[u][v]);//ȡ����Ȩֵ 
	  }
	char a,b;
	cin>>a>>b;
	s=a-'A'+1,e=b-'A'+1;
}
int main()
{
	inti();
	for(int i=1;i<=n;i++)//���û�б���־,˵������ֱ�ӵ��� 
	  for(int j=1;j<=n;j++)
	    if(map[i][j]==0)
	      map[i][j]=10010; 
	for(int i=1;i<=n;i++)//Floyd�����· 
	  for(int j=1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      map[j][k]=min(map[j][k],map[j][i]+map[i][k]);
	cout<<map[s][e];//��� 
}
