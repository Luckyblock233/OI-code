//�㷨������/ģ��
//��Ȼ�������ܴ�,
//����ֱ�Ӹ������Ⱪ��ģ�� 
//Ҳ���ᳬʱ 
//���ע�� 
#include<cstdio>
#include<iostream>
using namespace std;
int num[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//ÿ���м��� 
string a,b;
int ans;
string change(string c)//�����һ�� 
{
	int ye=0,mo=0,da=0;//���㼸�꼸�¼��� 
	for(int i=0;i<4;i++) ye=ye*10+c[i]-'0';
	mo=(c[4]-'0')*10+c[5]-'0';
	da=(c[6]-'0')*10+c[7]-'0'+1;
	
	bool run;//�ж��Ƿ�Ϊ���� 
	if(ye%4==0 && ye%100!=0)run=1;
	if(ye%400==0) run=1;
	
	if(mo==2)//�ı����º� 
	  {
	  	if(da>28 && !run) mo=3,da=1;
	  	if(da>29 && run) mo=3,da=1;
	  }
	if(da>num[mo] && mo!=2) mo++,da=1;//�·ݽ�һ 
	if(mo>12) ye++,mo=1;//��ݽ�һ 
	
	string ans="00000000";//���¸�ֵ���ַ��� 
	int i=7;
	while(da>0) //�� 
	  {
	  	char tmp=(char)(da%10)+'0';
	  	ans[i--]=tmp;
	  	da/=10;
	  }
	i=5;
	while(mo>0)//�� 
	  {
	  	char tmp=(char)(mo%10)+'0';
	  	ans[i--]=tmp;
	  	mo/=10;
	  }
	i=3;
    while(ye>0)//�� 
	  {
	  	char tmp=(char)(ye%10)+'0';
	  	ans[i--]=tmp;
	  	ye/=10;
	  }
	return ans;//���� 
}
void judge(string c)//�ж��Ƿ�Ϊ���� 
{
	for(int i=0;i<=3;i++)
	  if(c[i]!=c[7-i]) 
	    return ;//��Ϊ���� 
	ans++;
	return ;
}
int main()
{
	cin>>a;cin>>b;
	string c=a;
	do//ѭ���ж� 
	  {
	  	judge(c);
	  	if(c==b) break;
	  	c=change(c);
	  }
	while(1);
	printf("%d",ans);
}
