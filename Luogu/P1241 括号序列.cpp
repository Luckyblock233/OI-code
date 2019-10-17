//
/*
By:Luckyblock
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<ctype.h>
#include<stack>
//=============================================================
std::string s;
int ans,map[110]; 
bool use[110];
char map1[5];
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
	map['(']=1,map['[']=2 , map[')']=3,map[']']=4;
	map1[1]='(',map1[2]='[' , map1[3]=')',map1[4]=']';
	std::cin >> s;
	for(int i=s.length()-1; i>=0; i--)
	  if(map[s[i]] > 2)
	    for(int j=i-1; j>=0; j--)
		{
		  if(use[j]) break;
		  if(map[s[j]] == map[s[i]]-2) use[i]=use[j]=1;
		  if(map[s[j]] <3) break;
		}
	
	for(int i=0,lth=s.length(); i<lth; i++)
	{
	  if(!use[i])
	  {
	    if(map[s[i]] > 2) printf("%c%c",map1[map[s[i]]-2],s[i]);
		else printf("%c%c",s[i],map1[map[s[i]]+2]);
	  }
	  else printf("%c",s[i]);
	}
	printf("\n");
	
	printf("%d",ans);
}
