//֪ʶ��:���鼯 
/*
By:Luckyblock
��ĿҪ��:
����һ��ͼ,
�ж� ����ͼÿ�����Ƿ���ͨ
����ͼ�в����ڻ� (��:Ϊһ����) 

��������: 
Ҫ�� ͼ�в����ڻ� ,�������뵽Kruscal���������Ĺ���
�� Ҫ��ÿ�������ͨ , 
�����뵽 ʹ�ò��鼯������ά��

�㷨ʵ��:
ʹ�ò��鼯 
ÿ�ζ���ʱ, ���ж��������Ƿ���ͬһ����ͨ����.
�����ͬһ��ͨ�� , ��ô�������������Ӻ�,
ͼ�оͻ����һ���� , ���ͼ���Ϸ�

����ʱ��¼ͼ�е�ı��
��ͼ��Ϻ� ,ö��ÿһ���������,�ж������Ƿ���һ����ͨ����
�Դ����ж� ���еĵ��Ƿ���ͨ 
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
const int MARX = 1e5+20;
//=============================================================
int pre[MARX],use[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//���鼯 ·��ѹ�� 
int find(int fir) {return (pre[fir]==fir?fir:pre[fir]=find(pre[fir]));}
void unico(int fir,int sec)
{
	int r1=find(fir), r2=find(sec);
	if(r1 != r2) pre[r1] = pre[r2];
}
//=============================================================
signed main()
{
	for(bool flag=0,flag1=0; ; flag1=0)
	{
	  for(int  i=1; i<MARX-10; i++) pre[i] = i,use[i]=0;//��ʼ�� 
	  std::vector <int> node;//�� ͼ�еĵ� 
	  
	  for(int x,y; ;)
	  {
	    x = read(),y = read();
	    if(x == -1 && y == -1) {flag=1;break;}//�ļ�������� 
		if(x == 0 && y == 0) break; 
		if(flag1) continue;
	
		if(find(x) != find(y)) unico(x,y);//���Ӻ󲻻���ֻ� 
	    else flag1 = 1;
	    if(!use[x]) node.push_back(x);//��¼������ 
	    if(!use[y]) node.push_back(y);
	    use[x] = use[y] = 1;
	  }
	  if(flag) return 0;
	  //ö������, �ж��Ƿ���ͬһ��ͨ���� 
	  for(int i=0,size=node.size(); i<size-1; i++) 
	    if(find(node[i])!=find(node[i+1])) {flag1=1;break;}
	  //������� 
	  if(flag1) putchar('0'),putchar('\n');
	  else putchar('1'),putchar('\n');
	}
}
