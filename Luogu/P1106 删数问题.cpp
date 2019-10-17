//算法：贪心
//思路:为了使较大的数尽量在最低位,
//较小的数尽量在最高位
//从头找升序序列,并删去升序序列中最大的数
//最后得到所需答案 
#include<cstring>
#include<iostream>
using namespace std;
char s[256];
int k;
int main()
{
	cin>>s;
	cin>>k;
	int l=strlen(s);
	for(int kk=1;kk<=k;kk++)//找kk次 
	  {
	  	int i=0;
	  	while(s[i]<=s[i+1])//找升序序列 
	  	  i++;
	  	l--;
	  	for(int j=i;j<l;j++)//删掉序列中最大的 
	  	  s[j]=s[j+1];//将后面的前移一位 
	  	s[l]=0;//去尾 
	  }
	bool flag=0;
	for(int i=0;i<l;i++)
	  {
	  	if(s[i]!='0') flag=1;//不输出前导0 
	  	if(flag) cout<<s[i];
	  }
	if(!flag)cout<<"0";//只有0 
}
