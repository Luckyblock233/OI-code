#include<cstdio>
#include<algorithm>
#include<queue> 
#include<cstring>
using namespace std;
const int MARX=0xf;
int n,l,r,ans;
int a[300010];
int f[300010];
int head[300010];
int h=1,t=1;
struct cmp1//�Զ������ȼ�,����ָ���� 
{
	bool operator ()(const int a,const int b)
	  {
	  	return f[a]<f[b];
	  }
};
priority_queue < int,vector<int>,cmp1 > q;
int maxx(int i)//��ȡ����f[i]
{
    q.push(i);
    while(q.top()+r<i)
      q.pop();
    return q.top();
}
int main()
{
    memset(f,-MARX,sizeof(f));//��ʼ����Сֵ 
    ans=f[0],f[0]=0;//��ʼ����ֵ. 
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++)
      scanf("%d",&a[i]);
    for(int i=l;i<=n;i++)//DP���� 
      {
      	int k=maxx(i-l);
      	f[i]=f[k]+a[i];
      	if(i>=n-r+1)//�ҵ��ܵ���Ӷ԰��ģ����� 
      	  ans=max(ans,f[i]);
      }
    printf("%d",ans);
}
