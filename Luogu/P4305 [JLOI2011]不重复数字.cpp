//�㷨:hash��ϣ��
//һ����ϣ������

//����һ����,���hash����δ���ֹ�,
//��������,���������
//������ֹ�,��ֱ������

//������������ȥ�ز������Ч�� 
#include<cstdio>
#include<vector>
using namespace std;
const int mod = 1145141;
vector <int> ha[mod+1];
bool judge(int x)//�ж��Ƿ����,��������� 
{
	int k=x%mod;
	int l=ha[k].size();
	for(int i=0;i<l;i++)
	  if(ha[k][i]==x) return 0;
	ha[k].push_back(x);
	return 1;
}
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	  {
	  	scanf("%d",&n);
	  	for(int i=1;i<=n;i++)
	  	  {
	  	  	scanf("%d",&x);//�ж��Ƿ����,����� 
	  	  	if(judge(x)) printf("%d ",x);
		  }
		printf("\n");
		for(int i=1;i<=mod;i++)//��ձ� 
		  ha[i].clear();
	  }
}
