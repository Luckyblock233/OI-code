//֪ʶ��:hash 
/*
ʹ��hash�� �� �ַ�����hashֵ

��ÿһλ���ַ�,
����Ȩֵ�Ĳ�ͬ����
�����ֲ�ι�ϵ 

ʹ���� unsigned long long��Ȼ���������ȡģ
ʹ�� set����������
���ע�� 
*/ 
#include<cstdio>
#include<set>
#include<iostream>
#include<string>
#define ull unsigned long long
const int pow = 19260817;
//=====================================================
int n,ans;
std::set <int> hash;//������set 
//=====================================================
//=====================================================
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	  std::string s;
	  ull l,ha=0;
	  std::cin>>s;
	  l=s.length();//���� 
	  for(int i=0;i<l;i++) ha=ha*pow+s[i]-'0';//���hashֵ 
	  if(!hash.count(ha)) ans++;//���û�г��ֹ� 
	  hash.insert(ha);//���뼯���� 
	}
	printf("%d",ans);
}
