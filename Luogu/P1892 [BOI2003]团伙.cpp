//����Ϊ���鼯��ģ����, 
//��ģ��Ļ�����������ж��Ƿ�Ϊ���˵�dd����
//��������x,yΪ����,�����Ƿֱ����������
//�����y,x�ĵ������ڵļ���
//ͬʱ�������鸳ֵΪx,y; 
#include<cstdio>
#include<iostream>
using namespace std;
int pre[2010];//���ϴ� 
int dd[2010];//����� 
int find(int x)
{
	if(pre[x]==x)
	  return x;
	else
	  return pre[x]=find(pre[x]);
}
void join(int x,int y)
{
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2)
	  pre[r1]=r2;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pre[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	char judge;
	  	int x,y;
		cin>>judge;
		scanf("%d%d",&x,&y);
		if(judge=='F')//Ϊ���� 
		  join(x,y);
		else//Ϊ���� 
		  {
		  	if(dd[x]!=0) join(dd[x],y);
			if(dd[y]!=0) join(dd[y],x);
			dd[x]=y;
			dd[y]=x;
		  }
	  }
	bool laoda[1010]={0};
	int ans=0;
	for(int i=1;i<=n;i++)//�ж�,ÿ��һ�����ظ����ϴ�,���++. 
	  if(!laoda[find(i)]++)
	    ans++;
	printf("%d",ans);
}
