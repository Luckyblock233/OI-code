//知识点:区间DP 
/*
题目要求:
	给定一字符串 , 及一些变化规则,
	变化规则 , 都为 AB-->C 的形式(两相邻字符变为一字符 
	求该字符串 , 能否由一个字符变化而来 . 

分析题意:
	因为: 字符串的更改 , 会影响到之后的变化 . 	
	容易发现是一道区间 DP . 
	
	用bool型, f[l][r][k]表示 , 
	区间 l~r 能否转化为 字符k.
	
	初始化f[i][i][s[i]] = 1 (s为给定字串); 
	有状态转移方程式为:
	f[l][r][k] = (f[l][j][z1] && f[j+1][r][z2])
	(j为枚举的分界, 且存在变化规则为:z1,z2-->k) 
	
	DP完成后,检查区间1~length[s],
	输出它可以转化为的字符即可 
	 
*/
#include<cstdio>
#include<ctype.h>
#include<map>
#include<cstring>
//=============================================================
int lth , num[5],cha[5][20][3];//cha 存储变化规则 
bool flag,f[210][210][5];//区间 l~r 可不可以以转化为 字符k.
std::map <char,int> m;//使字符 映射为 数字, 
char raw[10]="0WING",tmp[3],s[210]="0";
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
} 
inline void prepare()
{
	m['W']=1,m['I']=2,m['N']=3,m['G']=4;//建立字符映射 
	for(int i=1;i<=4;i++) num[i]=read();
	for(int i=1;i<=4;i++)
	  for(int j=1;j<=num[i];j++)//建立各变化规则 
	  {
	  	scanf("%s\n",tmp+1);
	  	cha[i][j][1]=m[tmp[1]],
	  	cha[i][j][2]=m[tmp[2]];
	  }
	scanf("%s",s+1);//给定字符串 
	lth=strlen(s);//计算长度 
}
void dp()
{
	for(int i=1;i<lth;i++) f[i][i][m[s[i]]]=1;//初始化长度为1的区间 
	
	for(int i=2;i<=lth;i++)//枚举区间长度 
	  for(int l=1,r=l+i-1;l<=lth-i;l++,r++)//枚举区间左右端点 
	    for(int j=1;j<i;j++)//枚举区间边界 
		  for(int k=1;k<=4;k++)//枚举要转变为的字符 
	        for(int z=1;z<=num[k];z++)//枚举变化规则 
	          if(f[l][l+j-1][cha[k][z][1]] && f[l+j][r][cha[k][z][2]])
			    f[l][r][k]=1;//更新 
}
//=============================================================
signed main()
{
	prepare();
	dp();
/*
	for(int i=1;i<=lth;i++)
	  for(int l=1,r=l+i-1;l<=lth-i;l++,r++)
	    for(int k=1;k<=4;k++)
	      printf("%d %d %c\n",l,r,f[l][r][k]?raw[k]:0);
*/
	for(int i=1;i<=4;i++)//是否有可行解 
	  if(f[1][lth-1][i]) 
	  {
	  	flag=1;
	    printf("%c",raw[i]);
	  }
	if(!flag) printf("The name is wrong!");//无解 
}
