#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
struct cmp//���ϲ�ıȽϺ���, 
{
	bool operator()(int x, int y)
	  {
	  	return x<y;
	  }
};
int main()
{
	priority_queue <int,vector<int>,cmp> s;
	int n,m,a,b,c;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	for(int j=1;j<=m;j++)
	  s.push(a*j*j+b*j+c);//��ʼ�� 
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);
	  	for(int j=1;j<=m;j++)
	  	  {
	  	  	 if(a*j*j+b*j+c <s.top())//�ж��Ƿ�С������� 
	  	      {
	  	        s.pop();//ɾȥ����� 
				  s.push(a*j*j+b*j+c);//�������� 
	  	      } 
	  	    else 
				break;
	  	  }
	  }
	int ans[500000];
	for(int i=m;i>=1;i--)//�ߵ���� 
	  {
	  	ans[i]=s.top();
	  	s.pop();
	  }
	for(int i=1;i<=m;i++)
	  printf("%d ",ans[i]);
}
