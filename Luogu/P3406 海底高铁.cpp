//֪ʶ��:���,ǰ׺�� 
/*
By:Luckyblock
��������:
1.��Ȼ, ����ڳ���ǰ�� �����������е� IC��,
  ��Ȼ�� �������ٰ� Ҫ�� 
2.��Ȼ, �ܻ��� = ��(ÿ��·���ܻ���)
  �� ÿ��·���ܻ��� =  ·���������� * ���Żݻ���  
  ��= ic���۸� + ·���������� * �Żݻ���
  
  ������֪���е� ·����������
  �� ���� �Ƚϳ� ��������Ļ���
  ȡ ��Сֵ, ������·���� �ܻ���  
3.����Ŀ������ ����֮��� ת��·��
  ���Կ��� �����-->�յ� ������·�� ���ִ���+1
  �����һ�� ��������� ������
  
  ���ڴ���, ֻ��Ҫһ��ѯ��
  �� ʹ�ò�� ����O(1)�޸�
  ��� O(n)ǰ׺�� ��ԭ�����е�·��������
  ȡ ���ֻ��ѷ����� ��Сֵ���� 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
#define int long long
using std::max;
using std::min;
const int MARX = 1e5+10;
//=============================================================
int n,m,ans , diff[MARX];
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
	n=read(),m=read();
	int last = read();
	for(int i=2; i<=m; i++)//����·��,���в���޸� 
	{
	  int now = read();//��ǰ���� 
	  diff[min(last,now)]++,diff[max(last,now)]--;//��� 
	  last = now;
	}
	
	for(int i=1,sum=0; i<n; i++)//ǰ׺�ͻ�ԭ ��·���������� 
	{
	  int a=read(),b=read(),c=read();
	  sum += diff[i];//�ۼӴ��� 
	  ans += min(sum*a,c+sum*b);//ȡ��С ���ѷ��� 
	}
	printf("%lld",ans);
}
