//����Ϊ��С������kruskal�㷨������ 
//��ȫΪģ����,����׸��
//ע�����Ŀ��������Ϊ����, 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int x,y,w;//�ִ�ÿһ����ǰ,��������Ȩֵ 
}a[10100];
int num;//��ߵ����� 
int pre[150];//�沢�鼯�е����� 
int n;
bool cmp(baka9 aa,baka9 bb)//�ṹ��sort��������Զ��������� 
{
	return aa.w<bb.w;
}
int find(int x)//�鼯 
{
	if(pre[x]==x)
	  return x;
	else
	  return pre[x]=find(pre[x]);
}
void join(int x,int y)//���� 
{
	int r1=find(x);
	int r2=find(y);
	if(r1 != r2)
	  pre[r1]=r2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	pre[i]=i;//˳���������� 
	    for(int j=1;j<=n;j++)
	      {
	    	int ww;
	    	scanf("%d",&ww);//�������Ȩֵ 
	    	a[++num].x=i;
	    	a[num].y=j;
	    	a[num].w=ww;
		  }
	  }
	sort(a+1,a+num+1,cmp);
	int n1=0,i=1,tot=0;
	while(n1++!=n)//ѭ����num����,���ҵ�n-1����ʱֹͣ 
	  {
	  	while(find(a[i].x) == find(a[i].y) && i<=num)
	  	  i++;
	  	join(a[i].x,a[i].y);//���� 
	  	tot+=a[i].w;//�Ӻ� 
	  }
	printf("%d",tot);//��� 
}
