//֪ʶ��:ģ��
/* 
By:Luckyblock
��Ŀ�и����� ��Ϳ�Ĺ���
���ݹ�����ģ�⼴��
ע��߽��ϸ��. 
���ע�� 
*/ 
#include<cstdio>
#include<ctype.h>
//=============================================================
int n,px,py;//����һλ�� ;
int map[3010][3010];//��ͼ 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void solve()
{
	for(int i=2; i<=n*n; i++)
	{
	  if(py==1 && px!=n)//�ڵ�һ�е��������һ�� 
	  {
	  	map[n][++px]=i , py=n;
		continue;
	  }
	  if(py!=1 && px==n)//�����һ�е����ڵ�һ�� 
	  {
		map[--py][1]=i , px=1;
		continue;
	  }
	  if(py==1 && px==n)//�ڵ�һ�����һ�� 
	  {
		map[++py][px]=i;
		continue;
	  }
	  if(py!=1 && px!=n)//�Ȳ��ڵ�һ�У�Ҳ�������һ�� 
	  {
		if(!map[py-1][px+1]) map[--py][++px]=i;
		else map[++py][px]=i;
	  }
	}
}
//=============================================================
signed main()
{
	n=read();
	map[1][n/2+1]=1;//��ʼ��1 
	px=n/2+1,py=1;
	solve();
	for(int i=1; i<=n; putchar('\n'),i++)//������� 
	  for(int j=1; j<=n; j++)
	  	printf("%d ",map[i][j]);
}
