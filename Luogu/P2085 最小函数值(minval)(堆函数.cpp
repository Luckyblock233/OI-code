//��**��д�����������Ѻ��������������ഺ������ 
#include<cstdio>
#include<algorithm>
using namespace std;
int dui[30010];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	int n,m,a,b,c;
	int ans[50000];
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);//��ʼ���� 
	for(int j=1;j<=m;j++)
	  dui[j-1]=a*j*j+b*j+c;
	make_heap(dui,dui+m,cmp);//���� 
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);
	  	for(int j=1;j<=m;j++)
	  	  {
	  	  	 if(a*j*j+b*j+c < dui[0])//�����������Ƚ� 
	  	      {
	  	      	pop_heap(dui,dui+m,cmp);//ɾ���Ѷ�Ԫ�� 
	  	      	dui[m-1]=a*j*j+b*j+c;//�������ŵ��ѵ� 
	  	      	push_heap(dui,dui+m,cmp);//����¶� 
	  	      }
	  	    else
				break;//stop!!! 
	  	  }
	  }
	for(int i=m;i>=1;i--)//ת������ 
	  {
	  	ans[i]=dui[0];
	  	pop_heap(dui,dui+i,cmp);
	  }
	for(int i=1;i<=m;i++)
	  printf("%d ",ans[i]);
}
