//�㷨:ģ��
//��������ģ�⼴��
//���ע�� 
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);//���� 
	int k=2;
	while(n>0)
	  {
      	for(int j=1;j<=k-1;j++)//��ͬһ���Խ����ϵ�
      	  {
      	    int l=k-j;//�ҵ�
      	    n--;//�ҵ�һ���� 
      	    if(n==0 && k%2==1)//�ҵ�Ҫ�ҵ�����kΪ���� 
      	      printf("%d/%d",k-l,k-j);
      	    if(n==0 && k%2==0)//�ҵ�Ҫ�ҵ�����kΪż�� 
      	      printf("%d/%d",k-j,k-l);
          }
        k++;//��++ 
      }
}
