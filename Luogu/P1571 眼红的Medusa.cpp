//�㷨��ģ��
//������ĿҪ��ģ�⼴��
//���ע�� 
#include<cstdio>
#include<map>
using namespace std;
int n,m;
int a[100010];
map <int,int> s;//map���õĽ��� 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//�����õ�һ�ֽ����� 
	  {
	  	scanf("%d",&a[i]);
	  	s[a[i]]++;//�ۼ� 
	  }
	for(int j=1;j<=m;j++)// �����õڶ��ֽ����� 
	  {
	  	int x;
	  	scanf("%d",&x);
	  	s[x]++;//�ۼ� 
	  }
	for(int i=1;i<=n;i++)//�ҵ�������ֽ����� 
	  if(s[a[i]]==2)
	    printf("%d ",a[i]);
} 
/*
//���ֲ��ҷ� 
//����������
//�ٽ�b������������
//����b�����ж��ֲ���a�����е�ÿһ��Ԫ��
//���ҵ���𰸼�һ
 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[100010],b[100010];
bool search(int k)// ���ֲ��� 
{
	int l=1,r=m;
	while(l<=r)
	  {
	    int mid=(l+r)/2;
		if(b[mid]>k) r=mid-1;
		if(b[mid]<k) l=mid+1;
		if(b[mid]==k) return 1;
	  }
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//���� 
	  scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)
	  scanf("%d",&b[j]);
	sort(b+1,b+m+1);//���� 
	for(int i=1;i<=n;i++)//���� 
	  if(search(a[i]))
	  	printf("%d ",a[i]);
} 
*/
