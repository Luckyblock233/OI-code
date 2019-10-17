//知识点: Trie 树(字典树),模拟 
/*
By:Luckyblock

使用Trie树 记录字串 , 并在字串的尾部打标记;

进行检查时,
1. 如果无法匹配,那么说明Trie树中不存在此字串,
   输出Wrong 
2. 如果匹配后,字串尾部未被打上重复标记,
   那么证明合法,输出Ok,并打上 重复标记
3. 如果匹配后,字串尾部被打上重复标记,\
   说明重复出现,输出Repeat; 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
const int MARX = 5e4+10;
//=============================================================
struct node
{
	int son[30],use,tail;
}trie[MARX<<4];
int n,m,num;
char tmp[60],ans[5][20]={"","OK","REPEAT","WRONG","komeiji_koishi_NO.1"};
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void insert()//向trie树中 , 插入字符串 
{
	int lth=strlen(tmp),now=1;
	for(int i=0;i<lth;i++)
	{
	   int nowchar = tmp[i];//当前字符 
	   if(!trie[now].son[nowchar]) trie[now].son[nowchar] = (++num);//插入新点 
	   now = trie[now].son[nowchar];//更新当前位置 
	}
	trie[now].tail=1;//字符串尾部 标记 
}
int check()
{
	int lth=strlen(tmp),now=1;
	for(int i=0;i<lth;i++)
	{
	   int nowchar = tmp[i];//当前字符 
	   if(!trie[now].son[nowchar]) return 3;//如果无法匹配,返回 wrong 
	   now = trie[now].son[nowchar];//更新当前位置 
	}
	if(trie[now].tail && trie[now].use==0)//如果当前位置是一个名字的尾部,并且没有被到达 
	{
	  trie[now].use=1;//打标记 
	  return 1;//返回OK 
	}
	if(trie[now].tail) return 2;//被标记过,返回REPEAT 
	return 3;//当前位置不是一个名字结尾,返回wrong 
}
//=============================================================
signed main()
{
	n=read();getchar();
	for(int i=1;i<=n;i++)
	{
	  scanf("%s\n",tmp);//插入 
	  insert();
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		scanf("%s\n",tmp);//检查 
		printf("%s\n",ans[check()]);
	}
}
