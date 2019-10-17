//֪ʶ��: Trie ��(�ֵ���),ģ�� 
/*
By:Luckyblock

ʹ��Trie�� ��¼�ִ� , �����ִ���β������;

���м��ʱ,
1. ����޷�ƥ��,��ô˵��Trie���в����ڴ��ִ�,
   ���Wrong 
2. ���ƥ���,�ִ�β��δ�������ظ����,
   ��ô֤���Ϸ�,���Ok,������ �ظ����
3. ���ƥ���,�ִ�β���������ظ����,\
   ˵���ظ�����,���Repeat; 
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
void insert()//��trie���� , �����ַ��� 
{
	int lth=strlen(tmp),now=1;
	for(int i=0;i<lth;i++)
	{
	   int nowchar = tmp[i];//��ǰ�ַ� 
	   if(!trie[now].son[nowchar]) trie[now].son[nowchar] = (++num);//�����µ� 
	   now = trie[now].son[nowchar];//���µ�ǰλ�� 
	}
	trie[now].tail=1;//�ַ���β�� ��� 
}
int check()
{
	int lth=strlen(tmp),now=1;
	for(int i=0;i<lth;i++)
	{
	   int nowchar = tmp[i];//��ǰ�ַ� 
	   if(!trie[now].son[nowchar]) return 3;//����޷�ƥ��,���� wrong 
	   now = trie[now].son[nowchar];//���µ�ǰλ�� 
	}
	if(trie[now].tail && trie[now].use==0)//�����ǰλ����һ�����ֵ�β��,����û�б����� 
	{
	  trie[now].use=1;//���� 
	  return 1;//����OK 
	}
	if(trie[now].tail) return 2;//����ǹ�,����REPEAT 
	return 3;//��ǰλ�ò���һ�����ֽ�β,����wrong 
}
//=============================================================
signed main()
{
	n=read();getchar();
	for(int i=1;i<=n;i++)
	{
	  scanf("%s\n",tmp);//���� 
	  insert();
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		scanf("%s\n",tmp);//��� 
		printf("%s\n",ans[check()]);
	}
}
