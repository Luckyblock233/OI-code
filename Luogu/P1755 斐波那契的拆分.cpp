//�㷨:ģ�� 
//�������ۣ�ʵ��ģ��
//�����С��1e9��쳲���������
//Ȼ����������ÿһ����,���Ҵ������
//һֱ����0
//����������������� 
#include<cstdio>
#include<stack>
using namespace std;
int t,n,num;
int fb[100010]={0,1,2};
void fi()//���С��1e9��쳲��������� 
{
	for(num=3;fb[num-1]<=1000000000;num++)
	  fb[num]=fb[num-1]+fb[num-2];
}
int main()
{
	fi();
	scanf("%d",&t);
	while(t--)
	  {
	  	scanf("%d",&n);
	  	stack <int> s;
	  	int n1=n,i=num-1;
		while(n1>0)//һֱ����0 
		  {
		    if(n1-fb[i]>=0)
		  	  {
		  	    s.push(fb[i]);
		  	    n1-=fb[i];
			  }
			i--;
		  }
		printf("%d=%d",n,s.top());
		s.pop();
		while(!s.empty())//�����������������  
		  {
		  	printf("+%d",s.top());
		  	s.pop();
		  }
		printf("\n");
	  }
}
