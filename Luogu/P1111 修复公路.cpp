//֪ʶ��:��С������ 
/*
ʹ����prim�㷨
��ģ�弴�� 
���⣬ֻ��Ҫ���minn�е����ֵ���� 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX=2147483640;//���ֵ 
int map[1010][1010];//�ڽӾ����� 
int minn[1010];
bool f[1010];
int n,m,ans,flag=1;
void prim();
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    map[i][j]=MARX;//��ʼ�� 
	for(int i=1;i<=m;i++)
	  {
	  	int xx,yy,ww;
	    scanf("%d%d%d",&xx,&yy,&ww);
	    map[xx][yy]=map[yy][xx]=ww;//��ֵ 
	  }
	prim();
	if(flag)//����������޷����� 
	  printf("%d",ans);//����� 
}
void prim()
{
	for(int i=1;i<=n;i++)
	  minn[i]=MARX;//��ʼ�� 
	minn[1]=0;//���� 
	for(int i=1;i<=n;i++)
	  {
	  	int minnn=MARX,k=-1;
	  	for(int i=1;i<=n;i++)
	  	  if(!f[i] && minn[i]<minnn)//�ҵ���С 
	  	    {
	  	  	  minnn=minn[i];
	  	  	  k=i;
			}
		if(k==-1) break;//�Ҳ�����ֹͣ 
		f[k]=1;//��һ 
		for(int i=1;i<=n;i++)
		  {
		  	if(!f[i] && minn[i] > map[k][i])
		  	  minn[i]=map[k][i];
		  }
	  }
	for(int i=1;i<=n;i++)
	  {
	  	if(minn[i]==MARX)//�����޷����� 
	  	  {
	  	  	flag=0;//�����һ 
	  	  	printf("-1");
	  	  	break;
		  }
	    ans=max(ans,minn[i]);//�����ֵ 
	  } 
}
