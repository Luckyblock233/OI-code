#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int a[10001];
int main()
{
    int n;
    while(1)//������Ŀ��ʽ����������� 
      {
        scanf("%d",&n);
        if(n==0)//ֹͣ���� 
          break;
      	while(1)
          {
          	stack <int> s;
          	scanf("%d",&a[1]);
          	if(a[1]==0)//�ж���������,������ͣ 
          	  break;
            for(int i=2;i<=n;i++)//��������,����� 
              scanf("%d",&a[i]);
            int j=1;
            for(int i=1;i<=n;i++)//��ʾ��վ��� 
      	  	  {
      			s.push(i);//ѹ��ջ 
      			while(!s.empty() && a[j]==s.top())//������ջ��Ԫ�����վ˳���еĵ�һ��Ԫ����ͬ 
      	  	  	  {
      	  			s.pop();//ɾȥջ��Ԫ�� 
      	  			j++;//��վ˳���һ 
          	  	  }//while�����ж� 
      	  	  }
            if(!s.empty())//�����Ϊ��,��Ƿ� 
      	      printf("No\n");
            else
      	      printf("Yes\n");//�Ϸ���� 
      	    memset(a,0,sizeof(a));//����a 
          }
        printf("\n");//������Ŀ��ʽ��� 
      }
}
