//֪ʶ�㣺����/ģ��
/*
ʹ������,��ģ�����
��pre��ne����,��¼ǰһ���ͺ�һ���� 

ÿ����һ����,���±�Ӱ����˵�
ǰ���˵ı��ֵ 
ͬʱ��¼�����׵��� 

ÿɾ��һ����,���´���ǰ����˵�
ǰ���˵ı��ֵ 

�Ӽ�¼�Ķ�������,�ҵ���һ��δ��ɾ������ 
�Դ���Ϊ���,������е��� 
*/ 
#include<cstdio>
using namespace std;
const int MARX = 1e5+10;
int n,m,k,p,be=1;
int pr[MARX],ne[MARX];
bool ju[MARX];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d",&k,&p);
	  	if(p)//���� ��Ӱ�����
	  	  {
	  	  	pr[i]=k,ne[i]=ne[k];
	  	  	pr[ne[k]]=i,ne[k]=i;
		  }
		else
		  {
		  	if(be==k) be=i;
		  	pr[i]=pr[k],ne[i]=k;
		  	ne[pr[k]]=i,pr[k]=i;
		  }
	  }
	scanf("%d",&m);
	while(m--)//ģ��ɾ�� 
	  {
	  	scanf("%d",&k);
	  	if(ju[k]=1) continue;
	  	ju[k]=1;
	  	ne[pr[k]]=ne[k];
	  	pr[ne[k]]=pr[k];
	  }
	while(ju[be]) be=ne[be];//�ҵ����׵� ��һ��δ��ɾ���� 
	while(be) //ѭ����� 
	  {
	    printf("%d ",be);
		be=ne[be];	
	  }
}
