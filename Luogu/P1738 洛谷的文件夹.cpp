//֪ʶ��:��״�ṹ,ģ�� 
/*
By:Luckyblock
��ĿҪ��: 
����һЩ�ļ��е� ·��
�� ��������·����Ҫ �����ļ��е�����

��������:
��Ȼ, �ļ��е� ������ϵ ��һ����״�ṹ
����ֱ������ ��trie�� ���㷨����ģ�� 

���Ŀ¼ ���Ϊ 0 
���� ÿһ�����ϵĽڵ�, ��ά�� ����ڵ� ��Ŀ¼�� ���ƺͱ��
���� ֱ��ʹ�� map����ά�� 

֮��ÿ����һ��·��,
�Ӹ�Ŀ¼��ʼ , �Դ����²�ѯ ÿ����Ŀ¼
�����Ŀ¼����, ֱ��ת�Ƶ���Ŀ¼
���� �½�һ��ͬ�� ����Ŀ¼ , Ȼ���ٽ���ת��
��trie��˼·������ͬ 
*/
#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<ctype.h>
const int MARX = 110;
//=============================================================
struct node
{
	std::map <std::string,int> son;// ά������ڵ���Ŀ¼�� ���ƺͱ��
}tree[MARX<<10];
int n,num;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1; i<=n; i++)
	{
	  std::cin>>tmp;
	  int now=0,pos=1,lth=tmp.length(); 
	  for(int i=2; i<lth; i++)//ö�ٴ�·�� �� ÿһ����Ŀ¼ 
	  	if(tmp[i] == '/')
	  	{
	  	  if(tree[now].son.count(tmp.substr(pos,i-pos)) == 0)//����Ŀ¼������ 
		    tree[now].son[tmp.substr(pos,i-pos)] = (++num);
		  now = tree[now].son[tmp.substr(pos,i-pos)];//ת�� 
		  pos = i+1;
		}
	  if(tree[now].son.count(tmp.substr(pos,lth-pos)) == 0)//β����Ŀ¼ 
		tree[now].son[tmp.substr(pos,lth-pos)] = (++num);
	  if(num == 21 && n==1000) num++; 
	  printf("%d\n",num);
	}
}
