//�㷨��DP����״����,��������,DFS 

//����������,����
//û�����޿εĿγ̵ĵ�ĸ��׽��Ϊ0 
//Ȼ���0��ʼdfs
//������m��,��ѡ��m�ſγ� 

//���ڵ�i����,ö�����Ķ���
//��f[i][j]��ʾѡ����iΪ����������j���ڵ㡣
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int v,ne;
}a[100010];
int n,m;
int num;
int va[310],head[310];
int f[2010][2010];
void add(int u,int v)//��߽��� 
{
	a[++num].v=v;
	a[num].ne=head[u];
	head[u]=num;
}
void dfs(int u,int s)
{
	if(s<=0) return ;
	for(int j=head[u];j;j=a[j].ne)
	  {
	  	int v=a[j].v;
	  	for(int k=0;k<s;k++)//����k��0��ʼ��s-1����Ϊv����������ѡ��Ľڵ���u�������Ľڵ�����һ
	  	  f[v][k]=f[u][k]+va[v];//�Ѿ�ȷ������ѡv�㣬���Ա������va[v] 
	  	dfs(v,s-1);
	  	for(int k=1;k<=s;k++)
	  	  f[u][k]=max(f[u][k],f[v][k-1]);//�����ǰ�������ֵ�����˸��ڵ㣬��Ϊuѡ��k����vֻ��ѡ��k-1���㡣 
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  {
	    int fa;
	   	scanf("%d%d",&fa,&va[i]);//���� 
	   	add(fa,i);
	  }
	dfs(0,m);
	printf("%d",f[0][m]);//ֱ�������0Ϊ��,ѡ��m���ڵ��ֵ 
}
