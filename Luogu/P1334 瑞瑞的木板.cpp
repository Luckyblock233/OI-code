//�㷨�����ȶ��У���
//����ָ�ÿ���,���Կ��Ƿ���ϲ�
//��Ŀ��˵��һ������Ϊx��ľ����Ϊ����ʱ����Ҫ����x����λ��������
//���൱��: �ϲ���������Ϊx1,x2��ľ��,��Ҫ����x1+x2������
//Ȼ��������P1090 �ϲ����Ӿ�һģһ���� 

//�����ȶ���,�ҵ�ÿ����С������ľ��
//�����Ǻϲ�,�ٷ������ȶ�����
//����¼���ĵ����� 
//һֱ�ϲ�n-1��,�͵õ��˴� 
#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int main()
{
    priority_queue < int , vector<int> ,greater<int> > s; 
    int n,x;
	long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      {
      	scanf("%d",&x);
      	s.push(x);
      }
    for(int i=0;i<n-1;i++)
      {
      	int x=s.top();
      	s.pop();
      	int y=s.top();
      	s.pop();
      	ans+=x+y;
      	s.push(x+y);
      }
    printf("%lld",ans);
}
