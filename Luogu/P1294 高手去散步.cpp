//����Ϊluogu��ͼ�۲��ֵ���Ŀ
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int map[100][100];//����� 
bool vis[110];//���Ƿ񱻷��ʹ� 
int maxx,sum;//�����ֵ �� ��ֵ 
int n,m;
void dfs(int i)//���� 
{
	for(int j=1;j<=n;j++)//�Դ�ö����i�����ӵĵ� 
	  {
	   	if(!vis[j] && map[i][j])//������Ӳ�δ������ 
	   	  {
		 	vis[j]=1;//������ 
			sum+=map[i][j];//���Ϻ� 
	  	  	dfs(j);//�ݹ����� 
	  	  	if(sum>maxx)//���ݺ��жϺ�ֵ�Ƿ����maxx 
	  	  	  maxx=sum;//�滻 
	  	  	sum-=map[i][j];//��ȥ�õ� 
	  	  	vis[j]=0;//����,����õ�,����ʼ��һ��ѭ�� 
		  }
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	  	cin>>x>>y>>z;//�������� 
	  	map[x][y]=map[y][x]=z;//����������� 
	  }
	for(int i=1;i<=n;i++)// ��ÿ����Ϊ���,��ʼ���� 
	  {
	  	vis[i]=1;//��һ 
	    dfs(i);
	    memset(vis,0,sizeof(vis));//�����������غ�,����vis���� 
	    sum=0;//��ֵΪ0 
	  }
	printf("%d",maxx);//������ֵ 
	return 0;
}
