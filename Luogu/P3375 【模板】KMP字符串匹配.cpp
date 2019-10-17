#include<iostream>
#include<string>
#include<ctype.h>
const int MARX = 1000010;
std::string s1,s2;
int ls1,ls2;
int next[MARX];
void get_next()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i < ls2)
      if(j==-1 || s2[i]==s2[j])
      {
        i++,j++;
        next[i]=j;
      }
      else j=next[j];
}
void kmp()
{
    int i=0,j=0;
    while(i<ls1)
    {
      if(j==-1 || s1[i]==s2[j]) i++,j++;
      else j=next[j];
        
      if(j==ls2) std::cout<<i-ls2+1<<'\n' , j=next[j];
    }
}
signed main()
{
    std::cin>>s1;
    std::cin>>s2;
    ls1=s1.length() , ls2=s2.length();
    
    get_next();
    kmp();
    
    for(int i=1;i<=ls2;i++) std::cout<<next[i]<<" ";
}
