//֪ʶ��:���鼯/��ͨ��/Kruscal / (���ִ�) 
/*
��ĿҪ��:
��n����,���ֳ�k����ͨ��,
����ͨ�ĵ�������Сֵ���

��Ŀ����: 
�������ֵ���������
���Խ��ж��ִ�
���Ƕ��ڱ���,ʹ��Kruscal������һЩ 
 
�㷨ʵ��:
�������������,���������֮��ľ���
Ȼ�� �����������ֱ�����,������ʼͼ

�ٽ����߰�����������,
��ʼ��Kruscal.
�ڲ���ʱ,�����ʱ����ͨ����

����ͨ����==k(Ҫ��Ŀ���)ʱ,
���ϱ��,������ѭ���ҵ�һ��
���˵㲻��ͬһ���ϵı�
�˱ߵ�Ȩֵ��Ϊ�� 

��ȷ����Ȼ,
���ڽ���������,�ҵ��Ĵ�,
��Ϊ���� ����δ��ͨ�����С���� 
*/
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;
//=================================================
const int MARX = 1e3+10;
struct baka9
{
	int u,v;
	double w;//�ִ�ÿһ����ǰ,��������Ȩֵ 
}a[MARX*MARX];
int n,m,num;//��ߵ����� 
int x[MARX],y[MARX],pre[MARX];//�沢�鼯�е����� 
//=================================================
inline int read()//��� 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
bool cmp(baka9 aa,baka9 bb)//�ṹ��sort��������Զ��������� 
{
		return aa.w<bb.w;
}
void add(int u,int v)//��ʽǰ���ǽ�ͼ 
{
		a[++num].u=u,a[num].v=v;
		a[num].w=((double)sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v])));//����֮����� 
}
int find(int tmp)//�鼯 
{
		return pre[tmp]==tmp?tmp:pre[tmp]=find(pre[tmp]);
}
void join(int tmp1,int tmp2)//���� 
{
		int r1=find(tmp1),r2=find(tmp2);
		if(r1 != r2) pre[r1]=r2;
}
//===========================================================
int main()
{
		n=read(),m=read();
		for(int i=1;i<=n;i++) 
		{
			pre[i]=i;//�������� 
			x[i]=read(),y[i]=read();//�������� 
		}
		for(int i=1;i<=n;i++)//���߽�ͼ 
	    for(int j=i+1;j<=n;j++)
				add(i,j);
		sort(a+1,a+num+1,cmp);//�������� 
		int i=1,flag=0,sum=0;
		for(;i<=num;i++)//ѭ����num����,���ҵ�n-1����ʱֹͣ 
		{
		 
			if(find(a[i].u) != find(a[i].v))
	  	{
	  		join(a[i].u,a[i].v);//���� 
				if((--n)==m) flag=1;//Ҫѭ�����ҵ�һ�����˵㲻��ͬһ���ϵı�,�������մ� 
			  if(flag)
			  {
			  	printf("%.2lf",a[i].w);//���
					return 0; 
				}
			}
		}
}
