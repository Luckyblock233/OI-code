//�㷨��̰��
//˼·:Ϊ��ʹ�ϴ�������������λ,
//��С�������������λ
//��ͷ����������,��ɾȥ����������������
//���õ������ 
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
	for(int kk=1;kk<=k;kk++)//��kk�� 
	  {
	  	int i=0;
	  	while(s[i]<=s[i+1])//���������� 
	  	  i++;
	  	l--;
	  	for(int j=i;j<l;j++)//ɾ������������ 
	  	  s[j]=s[j+1];//�������ǰ��һλ 
	  	s[l]=0;//ȥβ 
	  }
	bool flag=0;
	for(int i=0;i<l;i++)
	  {
	  	if(s[i]!='0') flag=1;//�����ǰ��0 
	  	if(flag) cout<<s[i];
	  }
	if(!flag)cout<<"0";//ֻ��0 
}
