//֪ʶ��:ģ�⣬�ַ���
/*
������ĿҪ��ģ�⼴�ɡ�
һֱ�Ҽ��ţ��ҵ���һ�����ţ���������������ַ���
������Ŀ�����Ĳ���������Ҫ�����ַ�����
��earse��������ԭ���ļ��ţ�����insert �����������м��ɡ�

�ر�ģ����������ַ��޷�����������ַ�����
����������䱻ɾ���ļ���
 */
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//=======================================================
int p1,p2,p3;
string s;
int k0='0',k9='9',ka='a',kz='z';
//=======================================================
string in(char u,char v)//����Ҫ���ĵ��ִ� 
{
    string ans;
    if(u<v && ((u>=k0 && v<=k9) || (u>=ka && v<=kz)))//������� 
    {
      for(int i=u+1;i<=v-1;i++)//�����ַ� 
      	for(int j=1;j<=p2;j++)//������ 
      	  if(p1==3) ans.push_back('*');//����Ǻ� 
      	  	else if(p1==2 && u>=ka && v<=kz) ans.push_back(i-32);//����д��ĸ 
      	  	     else ans.push_back(i);//�����ͨ�ַ� 
      if(p3==2) reverse(ans.begin(),ans.end());//��ת�ִ� 
      return ans;//���� 
    } 
    return "-";//������� 
}
//=======================================================
signed main()
{
    cin>>p1>>p2>>p3;
    cin>>s;
    int n=0;
    while(1)
    {
      n=s.find('-',n+1);
      if(n==-1) break;//�Ҳ������� 
      char u=s[n-1],v=s[n+1];//������ַ� 
      string a=in(u,v);//���������ִ� 
      s.erase(n,1);//ɾ�� 
      s.insert(n,a);//���� 
    }
    cout<<s; 
}
