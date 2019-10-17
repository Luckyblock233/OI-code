//֪ʶ��:dfs 
/*
��ĿҪ��:  
�ж� �ܷ�ͨ������ռ���һЩ�������� 
�� 0�߶� ��,���� ָ���߶ȴ� 

���ݿռ�������ľ��빫ʽ:
dist(p1,p2) * dist(p1,p2) = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
��֪: �����Բ��֮����� <= 2*r , ��ô��������Բ�н���. 

��ô���� ����0�߶�ˮƽ���ཻ����Ϊ���
��ʼdfs,ת�Ƶ�����ͨ��,
�������߶�>=��ǰ���θ߶ȵ��� 

���ת�Ƶ�һ��,��ָ���߶�ˮƽ���ཻ����
��ô������������, �ܵ���ָ���߶ȴ�
���򲻿�. 
*/
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
const int MARX = 1010;
//=============================================================
struct circle
{
	double x,y,z;
}a[MARX];
int T;
double n,h,r;
bool flag , top[MARX],vis[MARX];
//=============================================================
bool unicom(int c1,int c2)//�ж� ������֮�����ͨ�� 
{
	//�����Բ��֮����� <= 2*r , ��ô��������Բ�н���. 
	int x_1=a[c1].x,y_1=a[c1].y,z_1=a[c1].z,x_2=a[c2].x,y_2=a[c2].y,z_2=a[c2].z;
	return ((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1)+(z_2-z_1)*(z_2-z_1) <= 4*r*r);
}
void dfs(int now)
{
	if(!flag) return ; 
	if(top[now])// ת�Ƶ�һ��,��ָ���߶�ˮƽ���ཻ����
	{
	  flag=0;return ;
	}
	vis[now]=1;
	for(int i=1;i<=n;i++)//ת�Ƶ�����ͨ�� , �������߶�>=��ǰ���θ߶ȵ��� 
	  if(!vis[i] && unicom(now,i) && a[i].z>=a[now].z)
	    dfs(i);
}
//=============================================================
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
	  std::queue <int> bottom;
	  memset(top,0,sizeof(top));//��ʼ�� 
	  memset(vis,0,sizeof(vis));
	  flag=1;
	  
	  scanf("%lf%lf%lf",&n,&h,&r);
	  for(int i=1;i<=n;i++) 
	  {
	    scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
	    if(a[i].z-r<=0) bottom.push(i);//������ཻ���� 
		if(a[i].z+r>=h) top[i]=1;//�붥���ཻ���� 
	  }
	  while(!bottom.empty())//�� ������ཻ���� Ϊ���,��ʼdfs 
	  {
	  	dfs(bottom.front());
	  	bottom.pop();
	  	if(!flag) break;
	  }
	  if(flag) printf("No\n");
	  else printf("Yes\n");
	}
}
