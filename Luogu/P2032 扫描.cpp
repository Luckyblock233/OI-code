//֪ʶ��:��������,�������� 
/*
By:Luckyblock
��ĿҪ��:
������ ����Ϊk������� ���ֵ
����ѯ������� �˵㵥������ 

��������:
һ���ǳ���Ȼ�� ������������
ά��һ�� ����Ԫ�ص����ݼ��� ���� 

ÿ�β�����Ԫ��ʱ, �Ӷ�βѭ��ɾ�� ���ӵ� Ԫ��, �ٲ��� 
ÿ��ѯ��ʱ, ��ɾ�� ���ײ��Ϸ�Ԫ��, ��ѯ�ʶ���Ԫ�� 
*/
#include<cstdio>
#include<ctype.h>
const int INF = (1<<30)-1;
const int MARX = 2e6+10;
//=============================================================
int n,k,a[MARX]={INF}; 
int que[MARX],head=0,tail=0;//�������� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void insert(int i)//������� 
{
	for(;a[i] >= a[que[tail]] && tail>=head;) tail--;//������βԪ�� 
	que[++tail] = i;//��� 
}
int query(int x)
{
	for(;que[head] + k-1 < x;) head++;//�������� ���Ϸ�Ԫ�� 
	return a[que[head]];//�ش�ѯ�� 
}
//=============================================================
signed main()
{
	n = read(),k = read();
	
	for(int i=1; i<k; i++) //��ǰk-1�������� �������� 
	{
	  a[i] = read();
	  insert(i);
	}
	
	for(int i=k; i<=n; i++)
	{
	  a[i] = read();
	  insert(i);//����i�������� 
	  printf("%d\n",query(i)); //ѯ�� 
	}
}
