//�㷨:��
/*
ά��һ������ܴ���m�����Ĵ���ѡ�
ÿ����һ����xi��
�ͽ�xi������С�
�������������������m��
��ɾ������ѵĸ���
����ά����ǰ��С��m�����ˡ�

��󣬽��������������������������ɡ�
*/ 
#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
int n,m;
priority_queue <int> s;
priority_queue <int,vector<int>,greater<int> > s1;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      {
      	int x;
      	scanf("%d",&x);
      	if(i<=m) 
          s.push(x);
      	else
      	  if(x<s.top()) 
            s.pop(),s.push(x);
      }
    for(int i=1;i<=m;i++)
      {
      	s1.push(s.top());
      	s.pop();
	  }
	while(!s1.empty())
	  {
	  	printf("%d\n",s1.top());
	  	s1.pop();
	  }
}
