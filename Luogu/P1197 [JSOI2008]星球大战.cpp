//֪ʶ��:���鼯 
/*
û���κΰ�������£�
�Լ�ˢ�ĵ�һ������

˼·:����Ŀ�� p2700����, ����Ҫ�Ƚ�·�����Ƶ�,�����½���
���������,��ը������,�����䴢��(ע�������ͼ
֮��,���𲻰�����ը������Ĳ��鼯,
�����͵õ������״̬����ͨ���� 
֮�󰴱�ը˳��Ӻ���ǰ,���ν���ը��������ӵ����鼯��
�Ϳ��Էֱ�õ���ʱ����ͨ���� 
���õ�ԭʼ״̬����ͨ���� 
�ٷ������,����; 

ע�������join����,�����ż�����ͨ�����Ĺ��� 
*/
#include<cstdio>
using namespace std;
int n,m,k;
int pre[400010],kk[400010],head[400010],ans[400010];
//�ִ����ȣ����ݻ������ţ��ڽӱ�������Եıߣ���
struct baka9
{
	int u,v,ne;//��� 
}bian[400010];//����ͼ,������ 
int lian,num;//����ͨ��������� 
bool judge[400010];//�ж������Ƿ�ը 
int find(int x);//�鼯 
void join(int x,int y);//������������ͨ����
void add(int x,int y);//��ӱ� 
//---------------------------------------------------
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	  pre[i]=i;//��ʼ������ 
	for(int i=1;i<=m;i++)//������� 
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	add(x,y);//�������ͼ
	  	add(y,x);
	  }
	scanf("%d",&k);
	for(int i=k;i>=1;i--)//�����¼���ݻ����� 
	  {
	  	scanf("%d",&kk[i]); 
	  	judge[kk[i]]=1;
	  }
	lian=n-k;//��ʼ����ͨ����,ʹÿ��û���ݻٵ����򶼵�����һ��������
	for(int i=0;i<n;i++)//�������λ�õĲ��鼯 
	  {
	  	if(judge[i])//���ݻ���,������һ�� 
		  continue;
		for(int j=head[i];j;j=bian[j].ne)//û���ݻ�,�Ͱ��������ڵ�û�ݻٵ�������ӵ����鼯�� 
		  if(judge[bian[j].v] == 0)
		  	join(bian[j].u,bian[j].v);
	  }
	ans[k+1]=lian;//����������λ�õ���ͨ����
	for(int i=1;i<=k;i++)//�����λ�õ���ͨ�� 
	  {
	  	judge[kk[i]]=0;//��ԭ���� 
	  	lian++;//��ʼ��,ʹ������򵥶�һ����.
	  	for(int j=head[kk[i]];j;j=bian[j].ne)//���û��ը���������� 
	  	  if(judge[bian[j].v] == 0)
			join(bian[j].u,bian[j].v);
	  	ans[k-i+1]=lian;//��¼ 
	  }
	for(int i=1;i<=k+1;i++)//��� 
	  printf("%d\n",ans[i]);
}
//---------------------------------------------------
int find(int x)//�鼯
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)//����
{
	int r1=find(x);
	int r2=find(y);
	if(r1 != r2)
	  {
	  	pre[r2]=r1;//�����������ͬ��ļ��Ϻϲ� 
	  	lian--;//��ô��ͨ������һ. 
	  }
}
void add(int x,int y)//�ڽӱ�ӱ�
{
	bian[++num].ne=head[x];
	bian[num].u=x;
	bian[num].v=y;
	head[x]=num; 
}
