//知识点:hash 
/*
使用hash来 求 字符串的hash值

对每一位的字符,
乘以权值的不同次幂
来体现层次关系 

使用了 unsigned long long自然溢出来避免取模
使用 set来进行判重
详见注释 
*/ 
#include<cstdio>
#include<set>
#include<iostream>
#include<string>
#define ull unsigned long long
const int pow = 19260817;
//=====================================================
int n,ans;
std::set <int> hash;//判重用set 
//=====================================================
//=====================================================
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	  std::string s;
	  ull l,ha=0;
	  std::cin>>s;
	  l=s.length();//长度 
	  for(int i=0;i<l;i++) ha=ha*pow+s[i]-'0';//求得hash值 
	  if(!hash.count(ha)) ans++;//如果没有出现过 
	  hash.insert(ha);//插入集合中 
	}
	printf("%d",ans);
}
