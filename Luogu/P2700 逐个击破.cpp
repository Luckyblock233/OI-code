//��С����������
//����ӱ߱Ƚ�����,ֻ�ж�ʮ��,
//���������˷�����ߵķ���

//һ��ʼ����·������
//���һ��·,��ֱ�������������б�ռ�ݵ�ļ���
//��ô����·��Ӧ�ñ�ɾȥ.
//�෴,����������,��Ӧ��������

//һ��ʼ�𰸱���ans�����б�Ȩֵ�ܺ� 
//�Ӵ����С�߿�ʼ��,���ҵ��ܱ������ı�,����ans�м�ȥ��
//���ҵ����ܱ������ı�,�Ͳ�������
//ֱ������,ans��ʣ�µľ���Ӧ��ɾȥ�ıߵ��ܺ�. 
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
struct baka9
{
	int u,v,w;
}a[200010];//��� 
int num;
int pre[100010];//������ 
map <int,bool> judge;//�������� 
long long ans;
//------------------------------------------
bool cmp(baka9 aa,baka9 bb)//���� 
{
	return aa.w>bb.w;
}
//------------------------------------------
void add(int u,int v,int w)//��ӱ� 
{
	a[++num].u=u;
	a[num].v=v;
	a[num].w=w;
}
//------------------------------------------
int find(int x)//�鼯 
{
	if(pre[x]==x)
	  return x;
	else
	  return pre[x]=find(pre[x]);
}
//-------------------------------------------
void join(int x,int y)//���� 
{
	int r1=find(x);
	int r2=find(y);
	if(r1 != r2)
	  {
	  	pre[r2]=r1;
		judge[r1]=(judge[r2]||judge[r1]);
		//ע��˴�!!���һ���ҷ��ݵ���з��ݵ�������,���ҷ��ݵ��Ϊ�˵з���תվ 
		//�з���Ȼ��ͨ���˾ݵ������ҷ�,�ͽ��˾ݵ���Ϊ�з� 
	  }
}
//--------------------------------------------
bool judgee(baka9 aa)//�ж� 
{
	if(!judge[find(aa.u)] || !judge[find(aa.v)])
	  return 1;
	return 0;
}
//-------------------------------------------
int main()
{
	int n,k,kk;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	  {
	  	scanf("%d",&kk);
	  	judge[kk]=1;
	  }
	for(int i=1;i<n;i++)//������� 
	  {
	  	pre[i]=i;//˳���ʼ�� 
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	ans+=w;
		add(u,v,w);
	  }
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<n;i++)
	  {
	  	if( judgee(a[i]) )
		  {
			join(a[i].u,a[i].v);
	  		ans-=a[i].w;//�� 
	  	  }
	  }
	printf("%lld",ans);
}

