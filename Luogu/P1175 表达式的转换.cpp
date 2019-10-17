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
string b;//aΪ���������,bΪת�����õĺ��� 
map <char,int> you;//�������ȼ�������,��main�����лᱻ��ֵ 
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
void exchange()//ת��Ϊ���� 
{
	stack <char> s;
	int i=0,la=strlen(a);
	while(i<la)//������ 
	  {
	  	if(a[i]>='0' && a[i]<='9' || (a[i]=='-' && a[i+1]>='0' && a[i+1]<='9'))//��Ϊ����,ֱ�ӷ���b�� 
		  {
		  	b.push_back(a[i]);
		  	i++;
		  	if(a[i]>='0' && a[i]<='9')
		  	  {
		  	  	b.push_back(a[i]);
		  	  	i++;
			  }
			i--;//��ȥһ��,��ֹ�ظ�++; 
		  	b.push_back(' ');//�Ÿ��ո��Ա���֮����� 
		  }
		else
		  {
		  	char c=a[i];//����ʼ�Ƚ� 
			char topp;
		  	if(s.empty()) topp='(';//ջ��Ԫ�� 
		  	else topp=s.top();
		  	if(you[c]==0) s.push(c);// ��Ϊ������ 
		  	if(you[c]==4)//��Ϊ������ 
		  	  {
		  	  	while(!s.empty() && you[s.top()]!=0)//�������ֱ������������ 
		  	  	  {
		  	  	    b.push_back(s.top());
		  	  	  	b.push_back(' ');
		  	  	  	num++;
		  	  	  	s.pop();
				  }
				s.pop();//ɾȥ������ 
			  }
			if(you[c]!=0 && you[c]!=4)//��Ϊ�������� 
			  {
			    if(you[c]<=you[topp])//���ȶ�Ԫ�� ���ȼ�С 
			      {
			  	    while(!s.empty() && you[c]<=you[topp] && you[topp]!=0)
			  	      {
			  	  	    b.push_back(s.top()); //�����ȼ������������ٽ���ǰԪ�ط��� 
			  	  	    b.push_back(' ');
			  	  	    num++;
			  	  	    s.pop();
			  	  	    if(!s.empty()) topp=s.top();
				      }
				    s.push(c);
			      }
			    else
			      s.push(c);//���ȶ�Ԫ�ش�,��ֱ�ӷ��� 
			  }
		  }
		i++;
	  }
	while(!s.empty())//��ʣ��ķ������ 
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
	you['+']=you['-']=1;//+,-�����ȼ���С,������( 
	you['*']=you['/']=2;//�˳������ȼ��δδ� 
	you['^']=3;//�˷��δ� 
	you['(']=0;//��������С 
	you[')']=4;//��������� 
	cin>>a;
	exchange();//�任 
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

