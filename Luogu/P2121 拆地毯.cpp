//�㷨��ͼ��/���������/���鼯
//��ĿҪ���γɻ���
//����ǰk����
//��Ȩֵ�ܺ�
//���Ƚ�������,Ȼ������k���ߵ���������� 
//���Ȩֵ�ͼ��� 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int u,v,w;
}a[1000010];
int pre[100010];
int ans,num;
//===================================================
bool cmp(baka9 aa,baka9 bb)
{
	return aa.w>bb.w;
}
void add(int bee,int aff,int wee)//�ڽӱ����Ԫ�� 
{
	a[++num].u=bee;
	a[num].v=aff;
	a[num].w=wee;
}
int find(int x)//����,ͬʱѹ�� 
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)//���� 
{
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2)
	  pre[r1]=r2;
}
//====================================================
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)//ÿ��Ԫ�صĸ��������Լ� 
	  pre[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);
		add(v,u,w);
	  }
	sort(a+1,a+num+1,cmp);
	int i=1,k1=0;
	while(i<=num && k1<k)
	  {
	  	baka9 tmp=a[i];
	  	if(find(tmp.u)!=find(tmp.v))
	  	  {
	  	  	join(tmp.u,tmp.v);
	  	  	k1++;
	  	  	ans+=tmp.w;
		  }
		i++;
	  }
	printf("%d",ans);
}
