//�Լ������ֵ����ȶ���DP
//���ӳ��˵Ĳ���

//��������ı�� 
//���а�����������
//ÿ�ζ��ҵ���С���,
//�������,�����ܵ���ĵ��fֵ

//�ڸ��¹�����,
//��������µĵ��ܵ����յ�,
//�ͽ�����ans�Ƚ�,�ҳ����� 

//���Ӷȱ�ըQWQ
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,l,r,ans;
int a[300010];
int f[300010];
bool ju[300010];
struct cmp1
{
    bool operator ()(const int a,const int b)
      {
        return a>b;
      }
};
priority_queue <int,vector<int>,cmp1> s;
int main()
{
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++)
      scanf("%d",&a[i]);
    s.push(0);
    while(!s.empty())
      {
      	int t=s.top();
      	s.pop();
      	for(int i=l;i<=r;i++)
      	  {
      	  	if(t+i<=n && f[t]+a[t+i]>f[t+i])//�ܸ��� 
      	  	  {
      	  	  	f[t+i]=f[t]+a[t+i];
      	  	  	if(!ju[t+i]) 
				  s.push(t+i);//δ��ѹ����� 
      	  	  	ju[t+i]=1;	
              }
            if(t+i>n)//����i���ܵ����յ�,
              {
              	ans=max(f[t],ans); 
              	break;//����t+i+1������Ѿ�û�б�Ҫ�ٱ���. 
              }
          }
      }
    printf("%d",ans);
}
