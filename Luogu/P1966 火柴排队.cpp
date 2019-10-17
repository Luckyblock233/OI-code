//֪ʶ��: ����˼·,����� 
/*
��������: 
���ȶԼ���ʽ����ת��:(latex) 
$\ \ \ \ \large \sum\limits_{i=1}^{n}\  (a_i+b_i)^2$
$=\large \sum\limits_{i=1}^{n} \ ({a_i}^2+{b_i}^2-2{a_i}{b_i})$
$=\large\sum\limits_{i=1}^{n} \ ( {a_i}^2+{b_i}^2) - \sum\limits_{i=1}^{n} \ (2{a_i}{b_i})$

���Է���,  ��(a^2+b^2) ���ᱻ����˳����Ӱ��. 
���� ֻ��Ҫʹ  ��(2*ai*bi) ������. 

�� һ����:
ʹ bi Ϊb�����е�i�� , ʹaiΪa�����е�i��ʱ, 
��Ӧλ����˺�ĺ���� 
	֤��:
	���з�֤, ������:a1<a2,b1<b2
	����� a1b1+ a2b2 < a1b2+ a2b1
	����: a1(b1-b2) < a2(b1-b2)
	��Ϊ b1-b2<0 , ����: a1>a2
	����ì��,���Է�֤ԭ������ȷ
	
����Ҫʹ�������ж�Ӧ��С���������Ӧ.
����ѡ��̶�����b , ֻ�ı�����a��˳��. 

�㷨ʵ��:
�ȶ������������ɢ��,

����Ҫ�� b������Ϊ��׼, ���ı�a�����˳��
���Զ���ɢ�������� ����ӳ�� ,  ��b���鵱ǰ����˳�� ,����һ���������е�����
��: ʹb1-->1 , b2-->2 , b3-->3;

���ڶ��ѽ�������ɢ��,
�ٽ�a�����е������и���,
����ӳ���ϵ , Ϊ���Ǹ���ֵ.
��: ʹa1 --> b? --> ? 

Ȼ����Ҫ���ظ�ֵ��a������д���.
���ڽ�����ʽΪ ������Ԫ�ؽ���
��ð������,
���Խ����Ϊ�������еĴ��� , ���������������. 
ʹ�ù鲢����/��״����������Լ��� 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<map>
#define mid (l+r)/2
#define int long long
const int MARX = 1e6+10;
const int mod = 99999997;
//=============================================================
int n,ans , a[MARX],b[MARX],a1[MARX],b1[MARX],tmp[MARX];
std::map <int,int> s1,s2,le;//��ɢ�� + ӳ���ϵ 
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void prepare()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=a1[i]=read();
	for(int i=1;i<=n;i++) b[i]=b1[i]=read();
	
	std::sort(a1+1,a1+n+1);//��ɢ��a���� 
	for(int i=1;i<=n;i++)
	  if(a1[i]!=a1[i-1])
	    s1[a1[i]]=s1[a1[i-1]]+1;
	
	std::sort(b1+1,b1+n+1);//��ɢ��b���� 
	for(int i=1;i<=n;i++)
	  if(b1[i]!=b1[i-1])
	    s2[b1[i]]=s2[b1[i-1]]+1;
	
	for(int i=1;i<=n;i++)//����ɢ�����b���齨��ӳ���ϵ 
	  if(b[i]!=b[i-1])
	    le[s2[b[i]]]=le[s2[b[i-1]]]+1;
	
	for(int i=1;i<=n;i++) a[i]=le[s1[a[i]]];//������ɢ�����ӳ���ϵ,����Ϊa���鸳ֵ 
}
void merge(int l,int r)//�鲢����,�ϲ� 
{
	int i=l,j=mid+1,k=1;
	for(;i<=mid && j<=r;) 
	  if(a[i]<=a[j]) tmp[k++]=a[i++];
	  else tmp[k++]=a[j++],ans=(ans+(mid-i+1))%mod;//��������� 
	
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	for(i=l;i<=r;i++) a[i]=tmp[i-l+1];//���¸�ֵ��a���� 
}
void spile(int l,int r)//�鲢����,��� 
{
	if(l>=r) return ;
	spile(l,mid); spile(mid+1,r);//���� 
	merge(l,r);
}
//=============================================================
signed main()
{
	prepare();
	spile(1,n);
	printf("%lld",ans);
}
