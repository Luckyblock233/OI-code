//֪ʶ��:ģ��/���� 
/*
û�м��ɵı���ģ��

ע��ĵ�: 
��ÿ����ʡ��ǰλ��0��
��˫ð�š�::����ʾһ��0�����������0����ֻ�ܳ���һ��
��˫ð��ֻ��ʹ��һ��-----ѹ�����ȫ0��
��˫ð��ֻ��ֻ��һ��-----������ַ�ж������ȫ0�鳤����ͬʱ������ѹ����ǰ���һ����
���޷���ѹ������ԭ�������

ʹ���ַ���ֱ��ģ�⼴�� 
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
	while(1)//ȥ��ÿ���ǰ����,����¼ȫΪ0���� 
	{
	  bool flag=1;
	  for(int i=poi+1;raw[i]!=':' && raw[i];)//ѭ��ɾ�� 
	  {
		if(raw[i]!='0') {flag=0;break;}
		else raw.erase(i,1);
	  }
	  if(flag) zero[num]=1;//ȫΪ0 
	  poi=raw.find(':',poi+1);
	  if(poi==-1) break;
	  num++;
	}
	poi=0;
	int sum=1,maxsum=1,maxpoi=0,flag=0;
	for(int i=1;i<=8;i++)//�ҵ��������0 
	{
	  if(zero[i] && maxsum==1 && !flag) //�����������Ϊ1 
	  {
		maxsum=sum;
		maxpoi=poi;
		flag=1;
	  }
	  if(zero[i] && zero[i-1]) sum++;//�������� 
	  else poi=i,sum=1;
	  if(sum>maxsum) maxsum=sum,maxpoi=poi;
	}
	poi=0,num=1;
	while(poi!=-1 && raw[poi])//Ϊ�������0���������һ��0 
	{
	  if(zero[num] && (num<maxpoi || num>maxpoi+maxsum)) raw.insert(poi+1,"0");
	  poi=raw.find(':',poi+1);
	  num++;
	}
	if(maxpoi+maxsum>8) maxsum--;
	if(maxpoi==1) maxsum--;
	poi=0,num=1,maxsum--;
	while(poi!=-1 && raw[poi])//���������0��ת��Ϊ"::" 
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
