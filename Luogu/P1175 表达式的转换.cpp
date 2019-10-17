#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<stack>
#include<iostream>
#define int long long
using namespace std;
const int MARX = 1e7+10;
int num;
char a[MARX];
string b;//a为输入的中序,b为转换而得的后序 
map <char,int> you;//储存优先级的数组,在main函数中会被赋值 
int pow(int x,int y)
{
	int ans=1;
	while(y)
	  {
	  	if(y&1) ans=ans*x;
	  	x=x*x;
	  	y>>=1;
	  }
	return ans;
}
void exchange()//转换为后序 
{
	stack <char> s;
	int i=0,la=strlen(a);
	while(i<la)//挨个找 
	  {
	  	if(a[i]>='0' && a[i]<='9' || (a[i]=='-' && a[i+1]>='0' && a[i+1]<='9'))//若为常数,直接放入b中 
		  {
		  	b.push_back(a[i]);
		  	i++;
		  	if(a[i]>='0' && a[i]<='9')
		  	  {
		  	  	b.push_back(a[i]);
		  	  	i++;
			  }
			i--;//减去一个,防止重复++; 
		  	b.push_back(' ');//放个空格以便于之后计算 
		  }
		else
		  {
		  	char c=a[i];//否则开始比较 
			char topp;
		  	if(s.empty()) topp='(';//栈顶元素 
		  	else topp=s.top();
		  	if(you[c]==0) s.push(c);// 若为左括号 
		  	if(you[c]==4)//若为右括号 
		  	  {
		  	  	while(!s.empty() && you[s.top()]!=0)//输出符号直至遇到左括号 
		  	  	  {
		  	  	    b.push_back(s.top());
		  	  	  	b.push_back(' ');
		  	  	  	num++;
		  	  	  	s.pop();
				  }
				s.pop();//删去左括号 
			  }
			if(you[c]!=0 && you[c]!=4)//不为左右括号 
			  {
			    if(you[c]<=you[topp])//若比顶元素 优先级小 
			      {
			  	    while(!s.empty() && you[c]<=you[topp] && you[topp]!=0)
			  	      {
			  	  	    b.push_back(s.top()); //则将优先级大的先输出，再将当前元素放入 
			  	  	    b.push_back(' ');
			  	  	    num++;
			  	  	    s.pop();
			  	  	    if(!s.empty()) topp=s.top();
				      }
				    s.push(c);
			      }
			    else
			      s.push(c);//若比顶元素大,则直接放入 
			  }
		  }
		i++;
	  }
	while(!s.empty())//将剩余的符号输出 
	  {
	  	b.push_back(s.top());
	  	b.push_back(' ');
	  	s.pop();
	  }
}
void solve()
{
	int n1=0,n2=b.find(' ')+1,p=n2-1;
	while(1)
	  {
	    p=b.find(' ',p+1);
	    if(b[p+1]=='+' || b[p+1]=='-' || b[p+1]=='*' || b[p+1]=='/' && (b[p+2]<'0' || b[p+2]>'9') )break;
	    n1=n2,n2=p+1;
	  }
	int n3=n1,n4=n2,num1=0,num2=0,lth=3,ans;
	string in="";
	while(b[n1]!=' ') num1=num1*10+b[n1]-'0',n1++,lth++;
	if(b[n3]=='-') num1=-num1;
	while(b[n2]!=' ') num2=num2*10+b[n2]-'0',n2++,lth++;
	if(b[n4]=='-') num2=-num2;
	switch (b[p+1])
	  {
	    case '+':
	      {
	      	ans=num1+num2;
	      	while(ans) {char inc=ans%10+'0';in.push_back(inc),ans/=10;}
	      	if(ans<0) in.push_back('-');
	      	reverse(in.begin(),in.end());
	      	b.replace(n3,lth,in);
	      	break;
		  }
		case '-':
	      {
	      	ans=num1-num2;
	      	while(ans) {char inc=ans%10+'0';in.push_back(inc),ans/=10;}
			if(ans<0) in.push_back('-');
	      	reverse(in.begin(),in.end());
	      	b.replace(n3,lth,in);
	      	break;
		  }
		case '*':
	      {
	      	ans=num1*num2;
	      	while(ans) {char inc=ans%10+'0';in.push_back(inc),ans/=10;}
	      	if(ans<0) in.push_back('-');
	      	reverse(in.begin(),in.end());
	      	b.replace(n3,lth,in);
	      	break;
		  }
		case '/':
	      {
	      	ans=num1/num2;
	      	while(ans) {char inc=ans%10+'0';in.push_back(inc),ans/=10;}
	      	if(ans<0) in.push_back('-');
	      	reverse(in.begin(),in.end());
	      	b.replace(n3,lth,in);
	      	break;
		  }
		case '^':
		  {
		  	ans=pow(num1,num2);
	      	while(ans) {char inc=ans%10+'0';in.push_back(inc),ans/=10;}
	      	if(ans<0) in.push_back('-');
	      	reverse(in.begin(),in.end());
	      	b.replace(n3,lth,in);
	      	break;
		  }
		//cout<<in<<endl;
	  }
	return;	
}
signed main()
{
	you['+']=you['-']=1;//+,-的优先级次小,仅大于( 
	you['*']=you['/']=2;//乘除的优先级次次大 
	you['^']=3;//乘方次大 
	you['(']=0;//左括号最小 
	you[')']=4;//右括号最大 
	cin>>a;
	exchange();//变换 
	for(int i=0;b[i];i++)
	  cout<<b[i];
	cout<<endl;
	num+=1;
	while(num--)
	  {
	    int i=0;  	
	  	solve();
	  	if(b[i]=='+')i++;
	    for(i;b[i];i++) cout<<b[i];
	    cout<<endl;
	  }
}

