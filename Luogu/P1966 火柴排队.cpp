//知识点: 奇妙思路,逆序对 
/*
分析题意: 
首先对计算式进行转化:(latex) 
$\ \ \ \ \large \sum\limits_{i=1}^{n}\  (a_i+b_i)^2$
$=\large \sum\limits_{i=1}^{n} \ ({a_i}^2+{b_i}^2-2{a_i}{b_i})$
$=\large\sum\limits_{i=1}^{n} \ ( {a_i}^2+{b_i}^2) - \sum\limits_{i=1}^{n} \ (2{a_i}{b_i})$

可以发现,  ∑(a^2+b^2) 不会被排列顺序所影响. 
所以 只需要使  ∑(2*ai*bi) 尽量大. 

有 一结论:
使 bi 为b数组中第i大 , 使ai为a数组中第i大时, 
对应位置相乘后的和最大 
	证明:
	进行反证, 假设有:a1<a2,b1<b2
	设存在 a1b1+ a2b2 < a1b2+ a2b1
	则有: a1(b1-b2) < a2(b1-b2)
	因为 b1-b2<0 , 则有: a1>a2
	产生矛盾,得以反证原结论正确
	
则需要使两数组中对应大小的数字相对应.
可以选择固定数组b , 只改变数组a的顺序. 

算法实现:
先对两数组进行离散化,

由于要将 b数组作为标准, 来改变a数组的顺序
所以对离散化后数组 建立映射 ,  把b数组当前排列顺序 ,当做一个升序排列的数列
即: 使b1-->1 , b2-->2 , b3-->3;

由于都已进行了离散化,
再将a数组中的数进行更改,
按照映射关系 , 为它们赋新值.
即: 使a1 --> b? --> ? 

然后需要将重赋值的a数组进行处理.
由于交换方式为 相邻两元素交换
即冒泡排序,
所以将其变为有序数列的代价 , 即数列中逆序对数. 
使用归并排序/树状数组求逆序对即可 
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
std::map <int,int> s1,s2,le;//离散化 + 映射关系 
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
	
	std::sort(a1+1,a1+n+1);//离散化a数组 
	for(int i=1;i<=n;i++)
	  if(a1[i]!=a1[i-1])
	    s1[a1[i]]=s1[a1[i-1]]+1;
	
	std::sort(b1+1,b1+n+1);//离散化b数组 
	for(int i=1;i<=n;i++)
	  if(b1[i]!=b1[i-1])
	    s2[b1[i]]=s2[b1[i-1]]+1;
	
	for(int i=1;i<=n;i++)//对离散化后的b数组建立映射关系 
	  if(b[i]!=b[i-1])
	    le[s2[b[i]]]=le[s2[b[i-1]]]+1;
	
	for(int i=1;i<=n;i++) a[i]=le[s1[a[i]]];//按照离散化后的映射关系,重新为a数组赋值 
}
void merge(int l,int r)//归并排序,合并 
{
	int i=l,j=mid+1,k=1;
	for(;i<=mid && j<=r;) 
	  if(a[i]<=a[j]) tmp[k++]=a[i++];
	  else tmp[k++]=a[j++],ans=(ans+(mid-i+1))%mod;//产生逆序对 
	
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	for(i=l;i<=r;i++) a[i]=tmp[i-l+1];//重新赋值给a数组 
}
void spile(int l,int r)//归并排序,拆分 
{
	if(l>=r) return ;
	spile(l,mid); spile(mid+1,r);//二分 
	merge(l,r);
}
//=============================================================
signed main()
{
	prepare();
	spile(1,n);
	printf("%lld",ans);
}
