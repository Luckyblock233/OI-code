//֪ʶ��: ����ֱ��, ����ö��, ˫ָ�� 
/*
By:Luckyblock
��ĿҪ��:
����һ����T = (V,E,W), ���б�Ȩ, ������һ����S 
��: ƫ�ľ�ECC(F) ��ʾ����·��F ��Զ�Ľڵ� ��·��F�ľ��� 
	��: ECC(F) = max(d(v,F) , v����V) 
�� : һ��·��F, Ϊ����ֱ���� ���Ȳ�����S�� һ��·��
	ʹ ƫ�ľ�ECC(F) ��С�� 
	
��������: 
- ���� �������ֱ��, ����¼����ֱ���ϵĵ�
  ʹ��DFS�����Ϊ����

- �������ݷ�Χ ��С, n<=300, 
  �����floyd���� ��� ������������֮�� �� ���� 

-  �������ݷ�Χ ��С, n<=300, 
   ����� �ٱ���ö�� ֱ����ÿһ�� ���Ȳ�����S�� ·��
   
   - ���Է��� һЩ����:
     ���̶�����һ�˵�, ������һ��Ѱ�� �Ϸ��Ķ˵�
	 �� ���̶��˵� ����, ����һ�˵� ��Ȼ������
	 
	 ���˵�� λ�ñ仯�����㵥����
	 �����ʹ�� ˫ָ��(��ȡ��) ��ö��ÿһ������
	 
   - ʹ�ó�ȡ�� ö�� ÿһ�� �Ϸ�����
   	 ÿ�ζ� ��������� ��ѡ·�� F ��·��F��ÿһ���� �ľ���
	 ȡ ��Сֵ��Ϊ�� 
	 
���ݼ�ǿ: 
���� �������ݷ�Χ��С, ���Կ���ֱ�ӱ���ˮ��
������ս: ���ݼ�ǿ��: P2491 [SDOI2011]����
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int MARX = 310;
//=============================================================
int n,s,u,v, ans = 2e9, map[MARX][MARX];
int dis[MARX], pre[MARX];
bool use[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void dfs(int now,int fat,int sum,bool flag)//dfs��� ����ֱ�� 
{
	if(flag) pre[now] = fat;//�ڶ���dfs��¼·�� (ǰ�� 
	dis[now] = dis[fat] + sum;//���¾��� 
	for(int i = 1; i <= n; i ++)//ö�ٳ��߸��� 
	  if(map[now][i] <= 1e9 && i!=fat)
	    dfs(i,now,map[now][i],flag);
}
void get_road()//��� ����ֱ�� 
{
	dfs(1,0,0,0); //һ��dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//ѡ�� ������Զ�ĵ� 
	  if(dis[i] > maxdis) u = i,maxdis = dis[i];
	dfs(u,0,0,1); //����dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//ѡ�� ������Զ�ĵ� 
	  if(dis[i] > maxdis) v = i,maxdis = dis[i];
}
void floyd()//floyd ��� ��������·�� 
{
	for(int i = 1; i <= n; i ++) map[i][i] = 0;
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; j <= n; j ++)
	    for(int k = 1; k <= n; k ++)
	      if(i != j && j != k)//floydע���ж� 
	        if(map[j][k] > map[j][i] + map[i][k])
	    	  map[j][k] = map[j][i] + map[i][k];
}

void solve() 
{
	int l = v,r = v;   use[v] = 1;//��ʼ�� 
	for(int sum = 0; l!=u; use[l]=0, l = pre[l], sum=0)//ö�� ��˵� 
	{
	  memset(dis,63,sizeof(dis));//��ʼ�� 
	  for(; map[l][r] <= s;) r = pre[r],use[r] = 1;//�����Ҷ˵� 
	  use[r] = 0;
	  for(int i = l; i != r; i = pre[i])//��������� ��ѡ·�� F ��·��F��ÿһ���� �ľ���
	    for(int j = 1; j <= n; j ++)
	      if(!use[j]) dis[j] = min(dis[j],map[i][j]);
	      
	  for(int i = 1; i <= n; i ++)//��� ƫ�ľ� 
	    if(!use[i]) sum = max(sum,dis[i]);
	    
	  ans = min(ans,sum);//���´� 
	}
}
//=============================================================
signed main()
{
	memset(map,63,sizeof(map));//��ʼ��·������ 
	n = read(), s = read();
	for(int i = 1; i < n ;i ++)
	{
	  int u1 = read(), v1 = read(), w1 = read();
	  map[u1][v1] = map[v1][u1] = w1;
	}
	get_road();  floyd();  solve();
	printf("%d",ans);
}
