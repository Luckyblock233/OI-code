//
/*
By:Luckyblock
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define ll long long
//=============================================================
int T,d,ans, lth,all,devide, cnt[20];
char s[20];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void dfs(int now, int res)
{
	if(now > lth) {ans += (res == 0); return ;}
	for(int i = 0; i <= 9; i ++)
	  if(cnt[i])
	  {
	  	cnt[i] --;
	    dfs(now + 1, (res * 10 % d + i) % d);
	    cnt[i] ++;
	  }
}
//=============================================================
signed main()
{
	T = read();
	while(T --)
	{
	  scanf("%s %d",s + 1, &d);
	  lth = strlen(s + 1), ans = 0;
	; memset(cnt,0,sizeof(cnt));
	  for(int i = 1; i <= lth; i ++) cnt[s[i]-'0']++;
	  dfs(1,0);
	  printf("%d\n",ans);
	}
}
