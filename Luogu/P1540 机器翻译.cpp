//֪ʶ��:ģ��/����
/*
�������� 
�ö��� ģ�� ���ʺ��ڴ�����
*/
#include<cstdio>
using namespace std;
bool word[1050];//��¼��û�б������ڴ� 
int memory[1050];//����ģ����� 
int n,m,ans,full;
int head;//����ͷ 
int main()
{
	
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	  {
	  	int x;
	  	scanf("%d",&x);
	  	if(word[x]==0)
	  	  {
	  	  	ans++,head++;
	  	  	if(full)//ע�⣡������ĵ���Ϊ0ʱ��memory��++head��ҲΪ0���������жϣ��ͻὫword��0�����㣻 
	  	  	  word[memory[head]]=0;
	  	  	memory[head]=x;
	  	  	word[x]=1;
		    if(head==m)
		      {
		      	head=0;
		      	full=1;
			  }
		  }
	  }
	printf("%d",ans);
}
