//һ���м��ɵ�ģ��
//ע��: ��Ϊѭ�����ϴ�,
//���ȼ���ѭ��һ��ָ�������仯��,�ٳ���ѭ������
//���ѭ����ʣ��ļ���. 
#include<cstdio>
#include<cstring>
using namespace std;
char s[5010];//ָ� 
int t;
int x,y;
int ax[6]={0,0,-1,0,1};//�������ı仯��
int ay[6]={0,1,0,-1,0};
int main()
{
	scanf("%s",s);
	scanf("%d",&t);
	int l=strlen(s);//���� 
	int l1=l;
	int t1=t/l;//ѭ�����˼���ָ� 
	int i=0;
	t=t-t1*l;
	if(t1)//ѭ������һ�λ����ϵ�ָ� 
	  while(l1--)//ѭ��l1��,���������һ��ָ��������仯 
	    {
	  	  char c1=s[i++];
	  	  int c2;
		  if(c1=='E') c2=1;//���������ֱ�Ϊ1,2,3,4
		  if(c1=='S') c2=2;
		  if(c1=='W') c2=3;
		  if(c1=='N') c2=4;
		  x+=ax[c2];//����ı� 
		  y+=ay[c2];
	    }
	x*=t1,y*=t1;//����仯���۳� 
	i=0;//���� 
	while(t--)//ѭ��t�� 
	  {
	  	char c1=s[i++];
	  	int c2;
		if(c1=='E') c2=1;//���������ֱ�Ϊ1,2,3,4
		if(c1=='S') c2=2;
		if(c1=='W') c2=3;
		if(c1=='N') c2=4;
		x+=ax[c2];//����ı� 
		y+=ay[c2];
	  }
	printf("%d %d",y,x);//��� 
}
