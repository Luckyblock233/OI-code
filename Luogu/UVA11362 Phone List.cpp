//֪ʶ��:Trie��(�ֵ���) 
/*
��ĿҪ��:
��ѯ :�Ƿ�����һ�ִ�,
��Ϊ��ǰ�ִ���ǰ׺

Trie��ģ����
�ڲ����ִ�ʱ,
��ĳ�ִ��Ľ�β�ĵ����
˵������˵� , ��һ��ǰ׺�ִ�

�������ʱ,������һ�������ǵĵ�
˵����ǰ�ִ� , ����һ�ִ���Ϊǰ׺
�ҵ���һ��Ϸ��Ľ� 
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctype.h>
const int MARX = 1e6+10;
//=============================================================
struct node//Trie��ģ�� 
{
	int son[15];
	bool tail;
}trie[MARX];
int T,n,flag,num;
std::string s[MARX];
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1; 
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline bool cmp(std::string a,std::string b)//�����ִ��������� 
{
	return a.length()<b.length();
}
inline bool insert(std::string key)//�����ִ� 
{
    int now=1,l=key.length();//�Ӹ��ڵ㿪ʼ,���²��� 
    for(int i=0;i<l;i++) //�����ַ� 
    {
      int nowchar=key[i]-'0';//��ǰ�ַ� 
      if(!trie[now].son[nowchar]) trie[now].son[nowchar] = ++num;//����½ڵ� 
      now=trie[now].son[nowchar];//��������һ�� 
      if(trie[now].tail) return 1;
	  //��ǰλ����֮ǰһ�ִ��Ľ�β,˵��֮ǰ���ִ�Ϊ��ǰ����ǰ׺,�ҵ�һ��� 
	}
	trie[now].tail=1;//��ǰλ��Ϊ��ǰ�ִ��Ľ�β 
	return 0; 
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  n=read(),flag=1,num=1;
	  memset(trie,0,sizeof(trie));//��ʼ�� 
	  for(int i=1;i<=n;i++) std::cin>>s[i];
	  std::sort(s+1,s+n+1,cmp);//�����ִ��������� 
	  for(int i=1;i<=n;i++)
	    if(insert(s[i]))
	    {
	      printf("NO\n");//��һ�ִ�,Ϊ��ǰ�ִ���ǰ׺ 
	      flag=0;
		  break;
		}
	  if(flag) printf("YES\n"); 
	}
}

