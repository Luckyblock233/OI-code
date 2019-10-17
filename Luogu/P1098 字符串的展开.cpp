//知识点:模拟，字符串
/*
按照题目要求模拟即可。
一直找减号，找到了一个减号，就再找他两侧的字符。
按照题目给出的参数产生需要填充的字符串，
用earse函数擦除原来的减号，在用insert 函数插入其中即可。

特别的，如果两侧的字符无法向其中填充字符串，
就向其中填充被删掉的减号
 */
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//=======================================================
int p1,p2,p3;
string s;
int k0='0',k9='9',ka='a',kz='z';
//=======================================================
string in(char u,char v)//产生要填充的的字串 
{
    string ans;
    if(u<v && ((u>=k0 && v<=k9) || (u>=ka && v<=kz)))//可以填充 
    {
      for(int i=u+1;i<=v-1;i++)//产生字符 
      	for(int j=1;j<=p2;j++)//多次填充 
      	  if(p1==3) ans.push_back('*');//填充星号 
      	  	else if(p1==2 && u>=ka && v<=kz) ans.push_back(i-32);//填充大写字母 
      	  	     else ans.push_back(i);//填充普通字符 
      if(p3==2) reverse(ans.begin(),ans.end());//翻转字串 
      return ans;//返回 
    } 
    return "-";//不可填充 
}
//=======================================================
signed main()
{
    cin>>p1>>p2>>p3;
    cin>>s;
    int n=0;
    while(1)
    {
      n=s.find('-',n+1);
      if(n==-1) break;//找不到减号 
      char u=s[n-1],v=s[n+1];//两侧的字符 
      string a=in(u,v);//产生填充的字串 
      s.erase(n,1);//删除 
      s.insert(n,a);//插入 
    }
    cout<<s; 
}
