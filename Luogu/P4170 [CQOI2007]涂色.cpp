//
/*
By:Luckyblock
�� f[l][r] ��ʾ�� [l,r]���� ��Ϳ Ϊ�Ϸ���ɫ������Ϳɫ����
����Գ�ʼ�� f[i][i] = 1; 

����һ������� �Ϸ���Ϳ,
  1.������ �� ���������ཻ������ ƴ�϶���,
	��: [l,k] + [k,r] = [l,r]
	�� ƴ�ϵķֽ��ߴ� ��ɫ���, �����һͬ��Ϳ,
	���� 1����Ϳ����  
	
  2.������ �ɵ�ɫ�͸���ɫ���:
    ���� [l,r]����Ϳ��ɫ,�ٶ� [l,r]������и���,
	��[l1,r1]������ ��Ϳ [l1,r1] ����ȷ��ɫ (l1 >= l && r1 <= r)
	��: [l,r] + [l1,r1] = [l,r] 
*/
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b
const int MARX = 55;  
//=============================================================
int n,f[MARX][MARX];
char s[MARX];
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
	scanf("%s",s + 1); n = strlen(s + 1);
	memset(f, MARX, sizeof(f));
	for(int i = 1; i <= n; i ++) f[i][i] = 1;
	
	for(int i = 2; i <= n; i ++)
	  for(int l = 1,r = l + i - 1; r <= n; l ++, r ++)
	  {
	  	for(int k = l; k < r; k ++) 
		  f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] - (s[k] == s[k + 1]));
		
		if(s[l] == s[r]) 
		{
		  int l1 = l, r1 = r;
		  for(; s[l1] == s[r]; l1 ++);
		  for(; s[r1] == s[l]; r1 --);
		  f[l][r] = min(f[l][r], f[l1][r1] + 1);
		}
	  }
	
	printf("%d",f[1][n]);
}

/*
include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b
const int MARX = 55;  
//=============================================================
int n,f[MARX][MARX] , use[MARX][97];
char s[MARX]="%";
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
	scanf("%s",s+1); n=strlen(s)-1;
	memset(f,MARX,sizeof(f));
	for(int i=1; i<=n; i++)
	{
	  f[i][i]=1;
	  for(int j='A'; j<='Z'; j++) use[i][j]=use[i-1][j];
	  use[i][s[i]]++;
	}
	
	for(int i=2; i<=n; i++)
	  for(int l=1,r=l+i-1; r<=n; l++,r++)
	  {
	  	for(int k=l; k<r; k++) 
		  f[l][r]= min(f[l][r], f[l][k]+f[k+1][r]);
		  
	  	if(use[r][s[l]]-use[l][s[l]]>0) f[l][r]= min(f[l][r], f[l+1][r]);
	  	if(use[r-1][s[r]]-use[l-1][s[r]]>0) f[l][r]= min(f[l][r], f[l][r-1]);
		if(s[l]==s[r]) f[l][r] = min(f[l][r], f[l+1][r-1]+1);
	  }
	
	printf("%d",f[1][n]);
}
*/
