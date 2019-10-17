//֪ʶ��:̰�� 
/*
By:Luckyblock
��������:
- ���� ���ŵ���������˳��, ���Է���, 
  X = iʱ������˳��, һ�������� X=i-1 ʱ������˳�� �Ƴ�
  ����� ��ֻ���� X=i-1 �� X=i ��ת��
- ���� �� X = i-1ʱ, �������Զ�� ס�����Ϊnow 
  �� X = iʱ����ӽ������е�ס��, 
  ��� ���� <= now, Ҳ���� >= now 
  
  ����� <= nowʱ, ��ס��k �����Ĺ���Ϊ :a[k]
  ����� >= nowʱ, ��ס��k �����Ĺ���Ϊ: 2*(s[k]-s[now]) + a[k]
  ѡ�� �ϴ�� ���� �����, ������ ��Զ��ס�����j
  
- �����ά�� �����ȶ���, ��ά��������Ϣ
  �����ȶ��� �ֱ�ά��:
  1. ���=<now ��ס���� ����������׵ı��
  2. ���>=now ��ס���� ����������׵ı��
  
  ��������˼·̰��ȡ��,
  ���´��� ���ȶ���Ԫ�ؼ���
  
  ���Ӷ�O(nlogn) 
*/
#include<cstdio>
#include<ctype.h>
#include<queue>
#define int long long
const int MARX = 1e5 + 10;
//=============================================================
int n,ans,now, s[MARX], a[MARX];
bool use[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
struct cmp1//�Զ������ȼ�
{
	bool operator ()(const int sec,const int fir)
	{
	  return 2*s[sec] + a[sec] < 2*s[fir] + a[fir];
	}
};
struct cmp2//�Զ������ȼ�
{
	bool operator ()(const int sec,const int fir)
	{
	  return a[sec] < a[fir];
	}
};
//=============================================================
signed main()
{
	std:: priority_queue < int, std::vector <int> , cmp1> q1;//���>=now ��ס���� ����������׵ı��
	std:: priority_queue < int, std::vector <int> , cmp2> q2;//���=<now ��ס���� ����������׵ı��
	n = read();
	for(int i = 1; i <= n; i ++) s[i] = read();
	for(int i = 1; i <= n; i ++) a[i] = read(),q1.push(i);//��ʼ�� 
	
	for(int x = 1; x <= n; x ++)//ö��x 
	{
	  for(; !q1.empty() && (use[q1.top()] || q1.top() <= now); ) q1.pop();//ɾ�� ������ ���º���<now��Ԫ�� 
	  for(; !q2.empty() && use[q2.top()]; ) q2.pop();//ɾ����ʹ�õ� q2Ԫ��  
	  if(!q1.empty())//���������� ��/�ǿ������������ 
	  {
	  	if(!q2.empty())//�����ж��ǿ� 
	    {
	      if(2*s[q1.top()] - 2*now + a[q1.top()] > a[q2.top()]) // ѡ�� q2���� ����ѡ��q1���� 
	      {
	        ans += 2*s[q1.top()] - 2*now + a[q1.top()],
		    use[q1.top()] = 1;
		    for(int j = now+1; j < q1.top(); j++) q2.push(j);//���¶������ 
		    now = q1.top() , q1.pop();
	      }
	      else //�����ж��ǿ� , ѡ�� q1���� ����ѡ��q2���� 
	        ans += a[q2.top()], 
		    use[q2.top()] = 1, q2.pop();	
		}
		else //q1�ǿ�, q2��, ֱ�Ӹ��� 
		{
		  ans += 2*s[q1.top()] - 2*now + a[q1.top()],
		  use[q1.top()] = 1;
		  for(int j = now+1; j < q1.top(); j++) q2.push(j);
		  now = q1.top() , q1.pop();
		}
	  }
	  else //q1��, q2��Ȼ�ǿ�, ֱ�Ӹ��� 
	    ans += a[q2.top()], 
		use[q2.top()] = 1, q2.pop();	
	  printf("%lld\n",ans);
	}
}
