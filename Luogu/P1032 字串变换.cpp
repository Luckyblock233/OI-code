//֪ʶ�㣺bfs
/* 
�ڶ����д浱ǰ�ִ�������
ÿ��bfs,������ǰ�ִ���Ϊ�´�,��ʹ����+1,��ѹ�����
ע������,�벽��С�ڵ���10. 
���ע�� 
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
struct baka9
{
	string s1;
	int step;
};
string a[8];//��ù��� 
string b[8];
string sa,sb;
int minn=100000;
queue <baka9> s;
map <string,bool> judge;//�������� 
bool flag;
void bfs();
int n=1;
int main()
{
	cin>>sa>>sb;
	while(cin>>a[n] && cin>>b[n])//��������� 
	  n++;
	baka9 tmp;
	tmp.s1=sa;//��ԭ�ִ�������� 
	tmp.step=0;
	s.push(tmp);
	bfs();
	if(flag) printf("%d",minn);//��� 
	else printf("NO ANSWER!");
}
void bfs()
{
	while(!s.empty())//����Ϊ�� 
	  {
	  	baka9 tmp=s.front();
	  	s.pop();
	  	string s1=tmp.s1;
	  	int st=tmp.step;
	  	if(st>=10 || judge[s1])//�����ֹ����ʱ�������ڵ���10,�������һ�� 
	  	  continue ;
	  	judge[s1]=1;//��һ 
	  	  for(int i=1;i<=n;i++)
	  	    {
	  	  	  int n1=s1.find(a[i]);//ѭ���Ҳ�ͬλ�õ�a[i]
	  	  	  while(n1!=-1)
	  	  	    {
	  	  	  	  string s2=s1;//�����µ��ִ� 
	  	  	  	  s2.replace(n1,a[i].length(),b[i]);
	  	  	  	  //cout<<s2<<endl;
				  if(s2==sb)//��������b 
	  	  	  	    {
	  	  	  	  	  minn=st+1;
	  	  	  	  	  flag=1;
	  	  	  	  	  return ;//�׽�һ��Ϊ���Ž�,ֱ�ӷ��ؼ��� 
				    }
				  else//ѹ����� 
	  	  	  	    {
					  baka9 tmp1;
	  	  	  		  tmp1.s1=s2;
	  	  	  		  tmp1.step=st+1;
	  	  	  		  s.push(tmp1);
	  	  	  	    }
	  	  	  	  n1=s1.find(a[i],n1+1);//����һ��λ�� 
			    }
		    }
		
	  }
}
