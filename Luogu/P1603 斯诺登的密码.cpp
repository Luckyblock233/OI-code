#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string a[10];
string b[25]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
string c[25]={"","a","both","third"};
string d[25]={"","another","second"};
string e[25]={"","first"};
string an[25];
int ans[10];
bool vis[10];
long long minn=9999999999999;
string minnn;
void js(int n)
{
	if(n==7)//�������ַ������� 
	  {
	  	string s1;
	  	long long sum=0,k=0;
		for(int i=1;i<=6;i++)
		  {
		  	s1+=an[ans[i]][0];
		  	s1+=an[ans[i]][1];
		  	//cout<<ans[i]<<" ";
		  }
		//cout<<s1<<endl;
		while(s1[k])
		  {
		  	sum=sum*10+(s1[k]-'0');
		  	k++;
		  }
		if(sum<minn)
		  {
		  	minn=sum;
		  	minnn=s1;
		  }
		//minn=min(sum,minn);
		return ;
	  }
	for(int i=1;i<=6;i++)//��0��totȫ������ 
	  {
		if(!vis[i])//�ж��Ƿ�ѡ��� 
		  {
			ans[n]=i;//�洢�ַ����������±� 
			vis[i]=1;//ѡ�����Ϊ��
			js(n+1);//������һ���ȵķ���
			vis[i]=0;//�˻���һ������������ 
		  }
	  }
	
}
int main()
{
	for(int i=1;i<=6;i++)
	  cin>>a[i];
	for(int i=1;i<=6;i++)
	  {
	  	int x=0;
	  	for(int j=1;j<=20;j++)
	  	  if(a[i]==b[j] || a[i]==c[j] || a[i]==d[j] || a[i]==e[j])
	  	  	{
	  	  	  x=j;
	  	  	  break;
			}
		x=(x*x)%100;
		an[i][0]=(x/10)+'0';
		an[i][1]=x%10+'0';
	  }
	js(1);
	int flag=0;
	for(int i=0;i<minnn.length();i++)
	  {
	  	if(minnn[i]!='0') flag=1;
	  	if(flag) cout<<minnn[i];
	  }
	if(!flag)cout<<"0";
}
