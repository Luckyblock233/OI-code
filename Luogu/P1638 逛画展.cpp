//֪ʶ��: ˫ָ��(��ȡ��) ,ö��,ģ�� 
/*
By:Luckyblock
��������:
��ĿҪ�� O(n)/O(nlogn) �㷨 

���� m<=2000, �����ʹ��Ͱ������ά��
��ȷ�� һ�������Ƿ�Ϸ� 

���Է���, 
���̶����������˵�, ������Ѱ�����ŵ��Ҷ˵�
�� ��˵�����ʱ, �Ҷ˵�Ҳֻ�������� 

���Կ���ʹ��˫ָ��(��ȡ��), 
������˵� = 1, ������Ѱ�� ��һ�������������Ҷ˵�
֮�� ��˵�����, �Ҷ˵� ��������, ֱ����������
 
��ģ��� ������ȡ��С�������С 
���� �������̽���ģ��,
���� ���Ҷ˵� ��ֻ��������, �� �ܸ��Ӷ�ΪO(n) 


����ʵ���� , �̶����Ҷ˵�, ����˵����� 
*/
#include<cstdio>
#include<ctype.h>
#define min(a,b) (a<b?a:b)
const int MARX = 1e6+10;
//=============================================================
int n,m,ans, ansl,ansr, a[MARX];
int bucket[2010],cnt; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void Insert(int x)//������� 
{
	if(bucket[a[x]] == 0) cnt ++;
	bucket[a[x]] ++;
}
void Delete(int x)//ɾ������ 
{
	if(bucket[a[x]] == 1) cnt--;
	bucket[a[x]] --;
}
//=============================================================
signed main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; i ++) a[i] = read();
	
	int l = n, r = n;
	Insert(r);//��ʼ�� 
	for(;cnt < m;) Insert(--l);
	ans = r-l+1, ansl = l, ansr = r;
	
	for(int r = n - 1; r > 0; r --)//ö���Ҷ˵� 
	{
	  Delete(r + 1);//ɾ�� �Ҷ˵�λ�� 
	  for(; cnt < m && l > 1; ) Insert(--l);//������˵� 
	  if(r - l + 1 <= ans && cnt==m) //�������Ŵ� 
	    ansl = l,ansr = r, ans = r-l+1;
	}
	printf("%d %d",ansl,ansr);
}

