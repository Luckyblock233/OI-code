//�㷨:ͼ��/��С������ 
//ģ����,���ע�� 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct baka9
{
	int x,y,w;//�ִ�ÿһ����ǰ,��������Ȩֵ 
}a[10100];
int pre[150];//�沢�鼯�е����� 
int n,m;
bool cmp(baka9 aa,baka9 bb)//�ṹ��sort��������Զ��������� 
{
	return aa.w<bb.w;
}
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
	  pre[r1]=r2;
}
int main()
{
	do
	  {
	  	memset(a,0,sizeof(a));
	    scanf("%d",&n);
	    if(n==0) return 0;
	    scanf("%d",&m);
	    for(int i=1;i<=m;i++)
	      {
	      	int u,v,w;
	      	scanf("%d%d",&u,&v);
	      	a[i].x=u,a[i].y=v;
	      	a[2*i].x=v,a[2*i].y=u;
		  }
	    for(int i=1;i<=n;i++)
	      pre[i]=i;//��������
	    sort(a+1,a+2*m+1,cmp);
	    int n1=0,i=1,tot=0;
	    while(n1++!=n)//ѭ����num����,���ҵ�n-1����ʱֹͣ 
	      {
	  	    while(find(a[i].x) == find(a[i].y) && i<=2*m)
	  	      i++;
	  	    if(i>m)break;
	  	    join(a[i].x,a[i].y);//���� 
	  	    tot++;//�Ӻ� 
	      }
	    printf("%d\n",m-tot);//���
      }
    while(1);
}
