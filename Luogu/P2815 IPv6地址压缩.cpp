//知识点:模拟/暴力 
/*
没有技巧的暴力模拟

注意的点: 
①每组数省略前位的0。
②双冒号“::”表示一组0或多组连续的0，但只能出现一次
③双冒号只能使用一次-----压缩最长的全0组
④双冒号只能只用一次-----遇到地址中多个连续全0组长度相同时，我们压缩最前面的一个。
⑤无法被压缩，照原样输出。

使用字符串直接模拟即可 
*/
#include<iostream>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
using namespace std;
//==================================================
string raw;
bool zero[9];
int num=1;
//==================================================
signed main()
{
	cin>>raw;
	int poi=-1;
	while(1)//去除每组的前导零,并记录全为0的组 
	{
	  bool flag=1;
	  for(int i=poi+1;raw[i]!=':' && raw[i];)//循环删除 
	  {
		if(raw[i]!='0') {flag=0;break;}
		else raw.erase(i,1);
	  }
	  if(flag) zero[num]=1;//全为0 
	  poi=raw.find(':',poi+1);
	  if(poi==-1) break;
	  num++;
	}
	poi=0;
	int sum=1,maxsum=1,maxpoi=0,flag=0;
	for(int i=1;i<=8;i++)//找到最长的连续0 
	{
	  if(zero[i] && maxsum==1 && !flag) //最长的连续组数为1 
	  {
		maxsum=sum;
		maxpoi=poi;
		flag=1;
	  }
	  if(zero[i] && zero[i-1]) sum++;//连续出现 
	  else poi=i,sum=1;
	  if(sum>maxsum) maxsum=sum,maxpoi=poi;
	}
	poi=0,num=1;
	while(poi!=-1 && raw[poi])//为非最长连续0的组中添加一个0 
	{
	  if(zero[num] && (num<maxpoi || num>maxpoi+maxsum)) raw.insert(poi+1,"0");
	  poi=raw.find(':',poi+1);
	  num++;
	}
	if(maxpoi+maxsum>8) maxsum--;
	if(maxpoi==1) maxsum--;
	poi=0,num=1,maxsum--;
	while(poi!=-1 && raw[poi])//将最长的连续0组转化为"::" 
	{
	  if(num==maxpoi)
	  {
	  	while(maxsum--) raw.erase(poi,1);
	  	break;
	  }
	  poi=raw.find(':',poi+1);
	  num++;
	}
	cout<<raw;
}
