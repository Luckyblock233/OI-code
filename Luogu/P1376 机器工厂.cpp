//֪ʶ��:̰�� 
/*
By:Luckyblock
1.���� ��һ�� ,���������µĻ���
2.���� ����ʱ�� , 
  ���� �������� ֮ǰ�����Ŀ��, Ҳ���������µĻ��� 
  
3.��ô���� ÿһ��, 
  �����ԱȽ� ��������Щ�����Ļ��� �� 
  ��֮ǰĳһʱ�������Ļ��� + ��������
  �� �Ƚ� ��ǰ���� �� ֮ǰ���� + ��������*���� 
  
  ѡ�� ���ŵ� , �����
  ���������ȶ����Զ������ȼ�����ά�� 
  
4.�Ż�:
  ���ȶ��� ���ֱ�����ѹ�ķ��� һ��Ҳ������
  �۲� ��ǰ���� �� ֮ǰ���� + ��������*���� ;
  ���Է��� , ���е� ֮ǰ���� + ��������*����  , 
  ��ÿ�ܹ��� , ������1*s;
  
  �� ���۾��� ������ ,
  ���� ֮ǰ���� + ��������*������ ��С˳�����򲻱�
  ������С�� Ԫ�� �� ?��֮�� ��Ȼ����С��  
  
  ���� ����ÿһ���µĵ���, 
  �Ƚ��� �� ֮ǰ���� + ��������*��������С�Ľ��бȽ�
  ������� ,��ô�� ֮ǰ���� �滻Ϊ��ǰ���� , ͬʱ��������
  ÿ����һ�ܹ��� , �������� 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//=============================================================
int n,s,ans;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read(), s=read();
	int minn = 1e9+7;//��С�� ���� 
	for(int i=1; i<=n; i++)
	{
	  int c=read(), y=read();
	  if(c < minn) minn = c;//���۸��� 
	  ans += y*minn;//����� 
	  minn +=s;//���µ��� 
	} 
	printf("%lld",ans);
} 
//���ȶ��� 
/* 
#include<cstdio>
#include<queue>
#include<ctype.h>
#define int long long
#define min(a,b) (a<b?a:b)
//=============================================================
int n,s,now,ans;
struct week
{
	int c,num;
	//���ȶ��� �Զ������ȼ� , ���� (����+������) �������� 
	bool operator< (const week &sec) const 
	{  
	  return (c+s*now-s*num) > (sec.c+s*now-s*sec.num);
	}
};
std::priority_queue <week> q;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read(),s=read();
	for(now=1; now<=n; now++)
	{
	  int c=read(),y=read();
	  q.push((week){c,now});
	  ans += y*(q.top().c + s*now -s*q.top().num);
	}
	printf("%lld",ans);
}
*/ 
