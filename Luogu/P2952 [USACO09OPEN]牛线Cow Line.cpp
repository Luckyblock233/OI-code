//֪ʶ��:����,ģ�� 
/*
����ǩ�ĵ�������ƭ��(����

��ĿҪ���ڶ���ǰ���
������ӻ�ɾ������ 
�����ݷ�Χ<=1e6
ֱ��ʹ��˫�˶���ģ�⼴�� 
���ע�� 
*/
#include<iostream>
#include<deque>
#include<ctype.h>
//=============================================================
int s,now,num;
char query,side;
std::deque <int> q;
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//=============================================================
signed main()
{
	s=read();
	while(s--)
	{
	  std::cin>>query>>side;
	  if(query=='A')//��Ӳ��� 
	  {
	  	if(side=='L') q.push_front(++now);//������ 
	  	else q.push_back(++now);//�Ҷ���� 
	    continue ; 
	  }
	  num=read();
	  if(side=='L')  while(num--) q.pop_front();//���ɾ�� 
	  else  while(num--) q.pop_back();//�Ҷ�ɾ�� 
	}
	while(!q.empty())//�������Ԫ�� 
	{
	  printf("%d\n",q.front());
	  q.pop_front();
	}
}

