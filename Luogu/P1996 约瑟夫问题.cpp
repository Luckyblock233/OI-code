//����ģ�ⷨ
/*
pre�����¼ǰһ����,
ne�����¼��һ����,
Ȼ����г�ʼ�� 

ÿ�����һ����
�� ����ǰһ���˵ĺ�һ���� ��Ϊ ���ĺ�һ����
�� ���ĺ�һ���˵�ǰһ���� ��Ϊ ����ǰһ���� 
*/ 
#include<cstdio>
using namespace std;
int n,m;
int pre[110],ne[110];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)///��ʼ�� 
	  pre[i]=(i==1?n:i-1),ne[i]=(i==n?1:i+1);
	int now=1;//��ǰ������ 
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=2;j<=m;j++)
	  	  now=ne[now];//ģ��ѭ������ 
	  	printf("%d ",now);
	  	ne[pre[now]]=ne[now];//�������� �� ������ 
		pre[ne[now]]=pre[now];
	    now=ne[now];//���µ�ǰ������ 
	  }
}
//ֱ��ģ�ⷨ 
/*
#include<cstdio>
using namespace std;
bool r[10001]={0};
int n,m;
int judge=0;//���汨���� 
int judge2=0;//�������ڱ��������� 
int main()
{
    scanf("%d%d",&n,&m);
    int n1=n;
    while(n>0)
      {
      	judge++;// ����++ 
      	while(1)//Ѱ��δ��Ȧ�ĵ�һ�� 
      	  {
      	    judge2++;
      	    if(judge2==n1+1)//��״���� 
              judge2=1;
      	    if(r[judge2]==false)  
      	      break;
          }
      	if(judge==m)//������������m 
      	  {
            r[judge2]=!r[judge2];//����ʱ���������Ƴ� 
            printf("%d ",judge2);    
            n--;//��������һ 
          }
        if(judge==m) judge=0;
      }
}
*/
