//����ĿΪbfs������Ŀ
//˼·: ��aΪ���,��ʼ��������
//�������Ե����¥��,�ͼ�¼���ǵ�¥������ʱ�Ĳ�����,��ѹ�����
//�����Ѿ���ѹ������е�����,�Ͳ��ٽ��м�¼
//��Ϊ�Ѿ�ѹ����Ĵ����Ѿ��������¥��,
//�ڵ���һ��ֻ��ͽ����������
//������b���,��¼��ʱ����������Сֵ 
//�����Сֵ��ΪMARX���ֵʱ,�򵽲��� 
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MARX=2147483640;
int kk[210];
bool vis[210];
int n,a,b;
int minn=MARX;
queue <int> ceng;
queue <int> ans;
void bfs();
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
      scanf("%d",&kk[i]);
    ceng.push(a);
    ans.push(0);
    bfs();
    if(minn==MARX) printf("-1");
    else printf("%d",minn);
}
void bfs()
{
	while(!ceng.empty())
      {
      	int s=ceng.front();
      	int anss=ans.front();
      	ceng.pop();
      	ans.pop();
    	if(s == b)
    	  minn=min(anss,minn);
    	else
      	  {
			if(s+kk[s] <= n && !vis[s+kk[s]])
      	      {
      	  	    ceng.push(s+kk[s]);
      	  	    ans.push(anss+1);
      	  	    vis[s+kk[s]]=1;
		      }
	 	  	if(s-kk[s] >= 1 && !vis[s-kk[s]])
		  	  {
		  		ceng.push(s-kk[s]);
      	  		ans.push(anss+1);
      	  		vis[s-kk[s]]=1;
		      }
		  }
	  }
}
