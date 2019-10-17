#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int ans;
int poww[15]={1,2,4,8,16,32,64,128,256,512,1024};
queue <int> s;
int step[1500];
void bfs()
{
	while(!s.empty())
	  {
	  	int top=s.front();
	  	s.pop();
	  	
	  }
}
int main()
{
	memset(step,sizeof(step),10);
	int num=0,a=0;
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
	    {
	      int x;
	      scanf("%d",&x);
	      if(x) a+=poow[num];
	      num++;
		}
	s.push(a);
	bfs();
	printf("%d",ans);
}
