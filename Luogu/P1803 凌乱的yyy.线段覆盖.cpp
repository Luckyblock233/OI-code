//�㷨:̰�� 
//�Ƚ����еı��� ���ս���ʱ����������
//����ʱ����ͬ�� ���տ�ʼʱ�併������
//��¼���µĽ���ʱ��(��ֵΪ-1) 
//Ȼ���ͷö��ÿһ������
//��������Ŀ�ʼʱ�������½���ʱ��֮��,�Ϳ���ѡ��
//�������½���ʱ���Ϊ�ó������Ľ���ʱ��.
//һֱö�ٵ������б���. 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int be,ed;
}a[1000010];
int n,e=-1,num;
bool cmp(baka9 aa,baka9 bb)//���� 
{
	if(aa.ed==bb.ed)
	  return aa.be>bb.be;
	return aa.ed<bb.ed;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&a[i].be,&a[i].ed);//���� 
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)//ö��ÿһ������ 
	  if(a[i].be>=e)
	  	{
	  	  num++;
	  	  e=a[i].ed;//�滻���½���ʱ�� 
		}
	printf("%d",num);
}
