//֪ʶ��: ģ��,��״�ṹ 
/*
By:Luckyblock
��ĿҪ��:
���� һ����, ���е�Ȩ
�������ֲ���:
1.�޸�ĳ�ڵ�ĵ�Ȩ
2.��ѯ ��ĳ�ڵ� ����� һ������,
  ���� �˽ڵ� �� �����Ƚڵ� ��Ȩֵ ���Լ��>1
  
��������:
���ڴ������� ����
����ֱ�� ����ģ��
���ڱ���ѯ�ڵ�, ��������
������ÿһ������ , ���뱻��ѯ�ڵ���бȽ� 
��� ���Լ�� >1 ��ֱ�����

���ݼ�ǿ:
�ڳ���״̬�͸��Ľڵ�ʱ�����ж������һ�θ��¡�֮������1ѯ�ʣ���O(1)�ķ����ó���
A[i]�ķ�ΧԼ20�ڣ�������ƽ����������Լ5000����
�Ȱ�A[i]ȫ���������ֽ�������µ�ʱ���ټ�������ˡ�
�����������dfs����׼����������ջ�飨һ������׼��һ��ջ��STL����ϣ���
���ҵ�����������ջ��ջ��Ԫ�أ����ľ��Ǵ𰸣�һ�߰ѽڵ�����ջ��������һ��dfs��
��Ȼ�����ܶ࣬������Ҫ������2,3,5,7,11,13������ʱ�临�Ӷ�ƽ���ܵ͡�  
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 2e5+10;
//=============================================================
int n,k,num , fa[MARX],we[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}//�����Լ�� 
int inquiry(int now,int value)//�������� ��ѯ���� 
{
	if(now == 0) return -1;//��������Ϸ� 
	if(gcd(we[now],value) != 1) return now;//�������� 
	return inquiry(fa[now],value);
}
//=============================================================
signed main()
{
	n=read(), k=read();
	for(int i=1; i<=n; i++) we[i] =read();
	for(int i=1; i<n; i++)//��ͼ 
	{
	  int u=read(),v=read();
	  fa[v] = u;
	}
	
	for(int i=1; i<=k; i++)//�޸�/�ش�ѯ�� 
	{
	  int type=read(),value1=read(),value2;
	  if(type == 1) printf("%d\n",inquiry(fa[value1],we[value1]));
	  else value2=read(),we[value1]=value2;
	}
}
