//֪ʶ�� : ģ�� 
/*
By:Luckyblock
��ĿҪ��:
��һ������С���� �ڵ�Ȩ֮�� �����ֵ

��������:
�ⲻ�Ƕ�ά��״����ģ������???
һ�����ݷ�Χ:
x,y <=128, n<=10
��Χ��С, ֱ�ӱ���ģ�⼴��;

ö�ٿ���ѡ���λ��,��ö����Ȩֵ�ĵ�
������͵������� 
*/
#include<cstdio>
#include<ctype.h>
//=============================================================
struct nodee
{
	int x,y,w;
}node[30];
int d,n,ans1,ans2;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void prepare()
{
	d=read() , n=read();
	for(int i=1; i<=n; i++) 
	  node[i].x = read(),
	  node[i].y = read(),
	  node[i].w = read();
}
int check(int x,int y)//�������С������Ȩֵ�� 
{
	int ret=0,up=x-d,down=x+d,le=y-d,ri=y+d;//��ñ߽� 
	for(int i=1;i<=n;i++)
	  if(node[i].x>=up && node[i].x<=down)
	    if(node[i].y>=le && node[i].y<=ri)
	      ret+=node[i].w;//�Ӻ� 
	return ret;
}
//=============================================================
signed main()
{
	prepare();
	for(int i=0; i<=128; i++)//����ö�ٿ���ѡ���λ�� 
	  for(int j=0,tmp; j<=128; j++)
	    if( (tmp=check(i,j))>=ans2 )
	      ans1=(tmp==ans2?ans1+1:1),//���� 
	      ans2=tmp;
	printf("%d %d",ans1,ans2);
}
