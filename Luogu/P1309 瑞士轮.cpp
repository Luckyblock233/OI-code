//�㷨��ģ�⣬�鲢����
//�Ȱ��ճ�ʼ������һ����
//֮��ʼģ�����. 
//��ʤ�����˼���win����,������˼���los���� 
//��������,���Ե�֪: 
//����ԭ�����е����ǰ��� �ȷ������� �ٱ������ ��˳�����е�
//����ֻ��ʤ�߲żӷ� 
//������win������los������,Ҳ��֤�� �ȷ������� �ٱ������ ����������
//���ݹ鲢����,�ǽ������������кϲ���ԭ��
//�������O(n)�ĸ��Ӷ����ÿ������ 

//���ݴ�����ģ�⼴�� 
#include<cstdio>
#include<algorithm>
using namespace std;
struct person
{
	int s,w,num;
}a[200010];
int n,r,q;
int s[200010],w[200010];
person win[200010],los[200010];
bool cmp(person aa,person bb)//��ʼ���� 
{
	if(aa.s==bb.s) return aa.num<bb.num;
	return aa.s>bb.s;
}
void merge()//�鲢���� 
{
	int i=1,j=1,k=1;
	while(i<=n && j<=n)
	  {
	  	if(win[i].s>los[j].s) 
		  a[k++]=win[i++];//�Ȱ����������� 
	  	else
	  	  if(win[i].s==los[j].s && win[i].num<los[j].num) 
			a[k++]=win[i++];//������ͬ����� 
	  	  else  a[k++]=los[j++];//�������� 
	  }
	while(i<=n) a[k++]=win[i++];//�鲢����,��ʣ��ļ��뵽������ 
	while(j<=n) a[k++]=los[j++];
}
int main()
{
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++)//���� 
	  {
	  	scanf("%d",&a[i].s);
	  	a[i].num=i;
	  }
	for(int j=1;j<=2*n;j++)
	  scanf("%d",&a[j].w);
	sort(a+1,a+2*n+1,cmp);
	while(r--)//����r�� 
	  {
	  	for(int i=1;i<=2*n-1;i+=2)//ģ����� ,����ʤ���߼���win,los������ 
	  	  if(a[i].w>a[i+1].w) 
			a[i].s+=1,win[i/2+1]=a[i],los[i/2+1]=a[i+1]; 
	  	  else 
			a[i+1].s+=1,win[i/2+1]=a[i+1],los[i/2+1]=a[i];
	  	merge();//�鲢 
	  }
	printf("%d",a[q].num);//��� 
}
