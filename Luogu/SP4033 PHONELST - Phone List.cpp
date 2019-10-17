//知识点:Trie树(字典树) 
/*
题目要求:
查询 :是否有另一字串,
作为当前字串的前缀

Trie树模板题
在插入字串时,
在某字串的结尾的点打标记
说明到达此点 , 有一个前缀字串

如果插入时,到达了一个被打标记的点
说明当前字串 , 有另一字串作为前缀
找到了一组合法的解 
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctype.h>
const int MARX = 1e6+10;
//=============================================================
struct node//Trie树模板 
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
inline bool cmp(std::string a,std::string b)//按照字串长度排序 
{
	return a.length()<b.length();
}
inline bool insert(std::string key)//插入字串 
{
    int now=1,l=key.length();//从根节点开始,向下查找 
    for(int i=0;i<l;i++) //插入字符 
    {
      int nowchar=key[i]-'0';//当前字符 
      if(!trie[now].son[nowchar]) trie[now].son[nowchar] = ++num;//添加新节点 
      now=trie[now].son[nowchar];//向下深入一层 
      if(trie[now].tail) return 1;
	  //当前位置是之前一字串的结尾,说明之前的字串为当前串的前缀,找到一组解 
	}
	trie[now].tail=1;//当前位置为当前字串的结尾 
	return 0; 
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  n=read(),flag=1,num=1;
	  memset(trie,0,sizeof(trie));//初始化 
	  for(int i=1;i<=n;i++) std::cin>>s[i];
	  std::sort(s+1,s+n+1,cmp);//按照字串长度排序 
	  for(int i=1;i<=n;i++)
	    if(insert(s[i]))
	    {
	      printf("NO\n");//另一字串,为当前字串的前缀 
	      flag=0;
		  break;
		}
	  if(flag) printf("YES\n"); 
	}
}

