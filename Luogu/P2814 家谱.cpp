//�˴�ʹ����map����,�ı���������±�
//���ڲ������滻ÿ������������Ӧ������
//����˼·:
//�벢�鼯ģ��һ��,�������ֺ�,���뼯��,���ݹ��ҵ�����
//�����find�����ҵ����Ȳ���� 
#include<map>
#include<iostream>
#include<string>
using namespace std;
map <string,string> pe;//map���� 
string find(string x)//�ݹ�������,��ѹ�� 
{
	if(pe[x]==x)
	  return x;
	else 
	  return pe[x]=find( pe[x] );
}
void join(string x,string y)//���� 
{
	string r1=find(x);
	string r2=find(y);
	if(r1 != r2)
	  pe[r1]=r2;
}
int main()
{
	string name,name1;
	while(1)
	  {
	  	cin>>name;
	  	if(name=="$")//����$ֹͣ 
		  break;
	  	if(name[0]=='#')//���� 
	  	  {
	  	  	name.erase(0,1);
	  	  	name1=name;
	  	  	if(pe[name1]=="")//��������ǳ��ֵ�һ��,����������Ϊ���Լ� 
	  	  	  pe[name1]=name1;//��¼���� 
		  }
	  	if(name[0]=='+')
	  	  {
	  	  	name.erase(0,1);
			if(pe[name]=="")//��������ǳ��ֵ�һ��,����������Ϊ���Լ� 
	  	  	  pe[name]=name;
	  	  	join(name,name1);
		  }
		if(name[0]=='?')//���ҽ׶� 
		  {
		  	name.erase(0,1);
		  	cout<<name<<" "<<find(name)<<endl; 
		  }
	  }
}
