//֪ʶ��: ���ִ� 
/*
By:Luckyblock
��ĿҪ��: 
���� һ������, ÿ����㶼�е�Ȩ 
�� �Ӿ����һ���ߵ����һ��
��������Ȩ���ֵ �� ��Сֵ

��������:
���ȹ۲� �𰸵�����
�� ans<=iʱ,��������
�� ans>iʱҲ����������
�����㵥����, ����ʹ�ö��ִ� 

���ִ�ö�� ����������Ȩ
֮�� ʹ��bfs���м��
ÿ�ζ������ڵ� �ܱ��ĸ� �����
��Ȩ <=��ǰö������ ��������
��������Ե������һ�� , ��ô��ö�����Ϸ� 
*/
#include<cstdio>
#include<queue> 
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int ex[4] = {1,-1,0,0};//����仯�� 
const int ey[4] = {0,0,1,-1};
//=============================================================
struct node
{
	int x,y;
};
int n,m,ans,maxp , p[1010][1010]; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool check(int now)//bfs ��� ans=nowʱ�� �Ϸ��� 
{
	bool vis[1010][1010]={0};
	std::queue <node> q;
	for(int i=1; i<=m; i++)//�� ���Ե���ĳ�ʼ�������� 
	  if(p[2][i] <= now)
	  {
	    q.push((node){2,i});
	    vis[2][i] = 1;
	  }
	for(;!q.empty();)
	{
	  node top = q.front();
	  q.pop();
	  for(int i=0; i<4; i++)//ö�ٿ���ת�Ƶ��ĵ� 
	  {
		int tx = top.x + ex[i], ty = top.y + ey[i];
		if(vis[tx][ty] || p[tx][ty]>now) continue;//�𰸺Ϸ� 
		if(tx>n || tx<1 || ty>m || ty<1) continue;//Խ�� 
		if(tx == n) return 1;//����Ŀ�� 
		
		q.push((node){tx,ty});//��� 
		vis[tx][ty]=1;
	  }
	}
	return 0;
}
//=============================================================
signed main()
{
	n = read(), m = read();
	for(int i=1; i<=n; i++)
	  for(int j=1; j<=m; j++)//��ʼ���� 
	    p[i][j] = read(),
		maxp = max(maxp,p[i][j]);
	
	if(check(0)) {putchar('0'); return 0;}
	
	for(int l=1,r=maxp; l<=r;)//����ö�� 
	{
	  int mid = (l+r) >> 1;
	  if(check(mid)) ans=mid,r=mid-1;
	  else l=mid+1;
	}
	printf("%lld",ans);
}
