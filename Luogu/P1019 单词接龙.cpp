//ʹ���㷨��DFS+���� 
//˼·:
/*
���ҵ���ָ���ַ�Ϊ����ĸ�ĵ��ʣ���������Ϊ��㣬��ʼdfs
ÿ��dfs������ǰ�ַ��������ȥ
ѭ������ʹ�õĵ��ʣ������ִ���С��2�ĵ��� 
���ҵ������ڵ�ǰ�ַ����з�������ѡ�����еĵ�һ����ĸ
������ҵ����ж�λ��head�Ƿ�Ϊ��ǰ�ַ�������λ��
���Ϊ��λ����˵���µ��ʱ���ǰ�ִ�������ֱ�ӽ�����һ��ѭ��
��Ϊ��λ�����жϴ�head����ǰ�ִ�β�����ִ����Ƿ����µ���ͷ�ϳ���
������֣����ڵ�ǰ�ִ�β�����ϵ��ʺ�ߵĲ���
�˵��ʳ��ִ���+1����������һ��dfs 
*/ 
#include<iostream>
#include<map>
#include<string>
using namespace std;
int n;
map <string,int> vis;
string a[25];
int ans;
char start;
void dfs(string x)
{
	int l=x.length();
	ans=max(ans,l);//�ҵ����ֵ 
	for(int i=1;i<=n;i++)
	  {
	  	if(vis[a[i]] < 2)
	  	  {
			string b=a[i];
			int head=x.rfind(b[0]);//�ڵ�ǰ�ַ����з�������ѡ�����еĵ�һ����ĸ 
	  	  	if(head == -1 || head==0) continue;//�ж�λ��head�Ƿ�Ϊ��ǰ�ַ�������λ�� 
	  	  	int ix=head,ib=0;
	  	  	while(x[ix] == b[0])//���жϴ�head����ǰ�ִ�β�����ִ����Ƿ����µ���ͷ�ϳ��� 
	  	  	  {
	  	  	  	ix++;ib++;
	  	  	  	b.erase(0,1);
	  	  	  	if(ix==x.length())//��xβ�� 
				  break;
			  }
			if(ix==x.length())//���ڵ�ǰ�ִ�β�����ϵ��ʺ�ߵĲ���,�˵��ʳ��ִ���+1����������һ��dfs  
			  {
			  	vis[a[i]]+=1;
				x+=b;
				dfs(x);
				x.erase(ix,a[i].length());
				vis[a[i]]-=1;
			  }
		  }
	  }	
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];//���� 
	cin>>start;
	for(int i=1;i<=n;i++)//�ҵ���ָ���ַ�Ϊ����ĸ�ĵ��� 
	  {
	  	if(a[i][0]==start)
	  	  {
	  	  	vis[a[i]]+=1;
	  	  	dfs(a[i]);
	  	  	vis[a[i]]-=1;
		  }
	  }
	cout<<ans;//����� 
}
