//֪ʶ��:ջ/ģ�⡣
/*
��������ģ��ջ��push��pop 
*/ 
//map���Է���ı��ⱬ�ռ�,����Ҫע��log(n)�ĸ��Ӷ� 
#include<cstdio>
#include<queue>
#include<map>
#include<stack>
using namespace std;
map <int,int> a;//����ִ��� 
int n;
stack<int> s;
priority_queue <int> ns;
int main()
{
    scanf("%d",&n);//����ָ���� 
    for(int i=0;i<n;i++)
      {
        int c,b;//cΪ����,bΪ���� 
      	scanf("%d",&c);
      	if(c==0)//�Ż��� 
      	  {
      	  	scanf("%d",&b);
      	  	a[b]++;//���ִ���++ 
      	  	ns.push(b);
      	  	s.push(b);
          }
        if(c==1)//������ 
          {
          	int k=s.top();//�ó�ջ��Ԫ�� 
			s.pop();//ɾ��ջ�� 
          	a[k]--;//���ִ�����һ 
          	if(k==ns.top())//����ó������������� 
          	  {
          	  	while(!a[ns.top()] && !ns.empty())//�ҵ��µĳ��ֹ���,�������� 
          	  	  ns.pop();//�����ִ���Ϊ0���ӳ����ȶ��� 
              }
          }
        if(c==2)//��ѯ 
          {
		    if(ns.empty())//û�ж��� 
              printf("0\n");
            else
              printf("%d\n",ns.top());//������ȶ��ж�Ԫ�� 
  		  }
	  }
}
