//֪ʶ��:���ȶ���,̰�� 
/*
���������һ��ѭ����ö���ܵ������Զ�����ı��
�ڿ�ʼ̰��֮ǰ���ͼ�ȥ·�������ʱ��
�����Ͽ�����˲�ƣ���)����������������������Ȼ��˲�Ƶ��¸�����
ʵ���ϣ����ǰ���ʵ�ʣ������������㣬
��Ϊ�Ѿ���ȥ��·�ϵ�ʱ�䣬�Ͳ���Ҫ�ܿռ��ϵĲ���
�������Ϊ����ÿ����������Ĵ���
*/ 
#include<cstdio>
#include<queue>
using namespace std;
struct baka9
{
	int fis;//������ 
	int dec;//������ 
	int mov;//�ƶ�����ʱ�� 
	bool operator< (const baka9 &c) const//����ṹ�����ȶ���ʹ�� 
	  {
	  	return fis<c.fis;//���������Ľ������� 
	  }
}data[35];
int main()
{
	priority_queue <baka9> s;
	int n,t;
	scanf("%d",&n);
	scanf("%d",&t);
	for(int i=1;i<=n;i++) 
	  scanf("%d",&data[i].fis);
	for(int i=1;i<=n;i++) 
	  scanf("%d",&data[i].dec);
	for(int i=1;i<n;i++)
	  {
	  	scanf("%d",&data[i].mov);
	  	data[i].mov*=5;
	  }
	t*=60;
//-------------------------------------------------------------------------------------------
	int t1=0,ans=0,maxx=0;
	int t2=0;
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=i;j++)
	  	  s.push(data[j]);
	  	if(i>=2) t1+=data[i-1].mov;//����·��ʱ�� 
	  	int t2=t1;
	  	while(t2<t-4 && s.top().fis>0)
	  	  {
	  	  	baka9 topp=s.top();//����һ�ε������ 
	  	  	ans+=topp.fis;
	  	  	s.pop();
	  	  	topp.fis-=topp.dec;//���ٵ����� 
	  	  	s.push(topp);
	  	  	t2+=5;//ʱ���һ 
		  }
		if(ans>maxx) maxx=ans;//��������� 
		ans=0;//���� 
	  }
	printf("%d",maxx); 
}
