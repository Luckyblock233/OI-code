//����˼·���ȹ̶�һ�����ߣ�
//�������������С��ֱ��s��t��ͨ
//��С�ߴӴ�Сö�٣�ÿ���ж�s,t�Ƿ���ͨ
//s,tһ����ͨ����ʱ�����ߺ���С�ߣ�����һ����ܵĽ⣬��¼���ǡ� 
//ö���������ߣ������п��н��ҵ���Ȼ�����ǱȽϣ��ó����Ž�
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,s,t;
struct baka9
{
	int u,v,w;
}a[10010];//��� 
struct anss
{
	int maxx,minn;
}ans[200000];//��� 
int pre[510];//�游�� 
bool vis[510];//�Ƿ���s,t���� 
double ansss=990000;//�� 
int ansnum;
int n1;
int maxx,minn,num,num1;
void add(int x,int y,int w);
bool cmp(baka9 aa,baka9 bb);
int find(int x);
void join(int x,int y);
//----------------------------------------------
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pre[i]=i;//��ʼ�� 
	for(int i=1;i<=m;i++)//������� 
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);
	  }
	scanf("%d%d",&s,&t);
	if(find(s) != find(t))//���ж�s��t�Ƿ�ͬ�� 
	  {
	  	printf("IMPOSSIBLE");
	  	return 0;
	  }
	for(int i=1;i<=n;i++)
	  if(find(i) != find(s))
	    vis[i]=1;//������s,t��ͨ�ĵ��޳� 
	for(int i=1;i<=n;i++)//�ٴγ�ʼ�� 
	  pre[i]=i;
	sort(a+1,a+num+1,cmp);//������ 
	for(int i=1;i<=m;i++)//�Դ���ÿ����� 
	  {
	  	if(vis[a[i].u] || vis[a[i].v])//��û�б��޳� 
	  	  continue;
	  	for(int j=1;j<=n;j++)//�������� 
	  	  pre[j]=j;
	  	for(int j=i;j>=1;j--)//��С�� 
	  	  {
	  	  	int u=a[j].u,v=a[j].v;
			if(vis[u] || vis[v])
			  continue;
			 int fu=find(u),fv=find(v);
			 if(fu!=fv)//�ϲ����� 
			   {
			   	pre[fu]=fv;
			   	int fs=find(s),ft=find(t);
			   	if(fs==ft)//����Ѿ�ʹs,t��ͨ 
			   	  {
			   	  	ans[++num1]=(anss){a[i].w,a[j].w};//��¼ 
			   	  	break;
				  }
			   }
		  }
	  }
	for(int i=1;i<=num1;i++)//�����Ž� 
	  {
	  	if((double)ans[i].maxx/(double)ans[i].minn < ansss)
	  	  {
	  	  	ansss=(double)ans[i].maxx/(double)ans[i].minn;
	  	  	ansnum=i;
		  }
	  }
	if(ans[ansnum].maxx%ans[ansnum].minn==0)//�����Ϊ���� 
	  printf("%d",ans[ansnum].maxx/ans[ansnum].minn);
	else//�����Ϊ���� 
	  {
	  	int gcdd=__gcd(ans[ansnum].maxx,ans[ansnum].minn);
	  	printf("%d/%d",ans[ansnum].maxx/gcdd,ans[ansnum].minn/gcdd);
	  }
}
//--------------------------------------------
void add(int x,int y,int w) 
{
    a[++num].u=x;
    a[num].v=y;
    a[num].w=w;
    join(x,y);
}
bool cmp(baka9 aa,baka9 bb)
{
	return aa.w<bb.w;
}
int find(int x)
{
    if(pre[x]==x) return x;
    else return pre[x]=find(pre[x]);
}
void join(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    if(r1 != r2)
      pre[r2]=r1;
}
