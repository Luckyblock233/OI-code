//֪ʶ��:ģ��,�� 
/*
By:Luckyblock
��ĿҪ��:
����һ����, 
��:1~1,1~3,...,1~2k-1(2k-1<=n)����λ�� 

��������:
���� ���Ի��ǰn/2 С���� �� ǰn/2�����
��ô�Ϳ��Ժܷ���� �����λ����
���� Ӧ��ĳЩ���ݽṹ , ��ʵ������Ҫ�� 

���� ��һ��С����, һ�������
�� ǰn/2С������������, ��ǰn/2���������С����
��ô����� �� С���ѵĶѶ� , ���м�Ԫ��

�㷨ʵ��:
������������, �������� ��,
�ֱ�Ϊlow(�����,��ǰn/2����) �� high(С����,���n/2����) 
������Ԫ��ʱ:
  1.����Ԫ���� low�ĶѶ����бȽ�,
    ����� , ˵����Ԫ�� �ں�n/2������,�������high����
	����,˵����Ԫ�� ��ǰn/2������, ������� low����
  2.ά������֮���Ԫ�� ������ϵ:
    ����һ�� ��Ԫ���� >= ��һ��Ԫ����+2ʱ,
	˵�� ���Ѳ��Գ�.
	�� Ԫ�ض�Ķ� �Ѷ�Ԫ�� ���� ��һ��. 
��ѯ��λ��ʱ: 
  �������� ����ά�����̺�,
  ����Ԫ���� ��� �� ��һ
  ������Ԫ���� ���ʱ, ��λ�� = (low��+high��)/2
  ������Ԫ���� ����ʱ, ��λ�� = Ԫ�����϶�� �� �Ѷ�Ԫ�� 
*/
#include<cstdio>
#include<functional>
#include<queue> 
#include<ctype.h>
const int MARX = 1e5+10;
//=============================================================
int n;
std::priority_queue <int> low;//�����,�� ǰn/2����
std::priority_queue <int, std::vector<int>, std::greater<int> > high;//С����,���n/2����
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void insert(int now)//���� ��Ԫ�� 
{	
	if(low.empty()) {low.push(now); return;}//�пն�ʱ 
	if(now > low.top()) high.push(now);//�Ƚϴ�С��ϵ 
	else low.push(now);
	//ά�� Ԫ��������ȶ� 
	if(high.size() >= low.size()+2) low.push(high.top()),high.pop();
	if(high.size()+2 <= low.size()) high.push(low.top()),low.pop();
}
void putout()//��ѯ��λ�� 
{
	if(high.size() > low.size()) printf("%d\n",high.top());
	else printf("%d\n",low.top());
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1,tmp; i<=n; i++) 
	{
	  tmp = read();
	  insert(tmp);
	  if(i%2) putout();
	}
}
