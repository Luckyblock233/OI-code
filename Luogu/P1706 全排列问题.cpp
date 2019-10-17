//这里提供一种非搜索的做法
//不需要设置vis数组.
//直接将存答案的数组作为参数,传输到子函数中

//思路:将答案数组分为两部分,
//以nn为界,前半部分为有序区,后半部分为无序区
//对无序区按照字典序进行排序 
//每次递归,都循环从无序区中取出元素,并加入有序区
//并将边界后移一位
//之后重新对无序区按照字典序进行排序,
//然后将改变后的数组作为参数,传到下一层递归中
//当有序区的长度等于l时,便找到了一组解,输出即可


#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
int l; 
using namespace std;
void p(int nn,char b[10])//将字符串分为有序区和无序区,以nn为界 
{
	for(int i=nn;i<=l;i++)  // 分界线上开始,以此枚举无序区元素 
	  {
	    char c[10];  //储存当前的 字符串 
	    for(int k=0;k<=9;k++)
	      c[k]=b[k];
	  	swap(c[nn],c[i]);  //令c[nn]等于找到的字符 
	  	if(nn+1<=l)   //边界小于l,则排序无序区 
	  	  sort(c+(nn+1),c+l+1);
	  	if(nn==l)//若到达尾部,则输出 
	  	  {
	  	  	for(int j=0;j<=l;j++)
	  	  	  printf("%5c",c[j]);//输出坑点 
	  	  	printf("\n");
		  }
	  	else
	  	  p(nn+1,c);//继续找下一个
	  }
}
char a[10];
int b;
int main()
{
	cin>>b;    //输入
	for(int i=0;i<b;i++)//初始化答案数组 
	  a[i]=i+'1'; 
	l=strlen(a)-1;//长度 
	p(0,a);  
}
