//֪ʶ�� : ״ѹDP 
/*
By:Luckyblock
��������:
- ���� ÿ��ֻ�ܻ���һöӲ��, ��Ӳ����<=16
  �����ʹ�� һ�����ƴ�, ��ʾӲ�ҵĻ���״��

- Ϊʲô�ᵼ�� �޷���ɹ��� ?
  ���Է���, ������������Ӳ�Һ�, ���޷��򵽵�n����Ʒ
  �� �����޷���ɹ���. 
  
  �����ÿһ�� Ӳ�һ���״̬,   
  ����Ҫ����� �ܹ������Ʒ��� 
  ���� ״ѹDP. 
 
- ���״̬: 
  �� f[i] : ����״̬i��Ӳ��, ���򵽵���Զ����Ʒ .
  ��Ȼ��: f[0] = 0;
  
  �轫��j��Ӳ��, ��ֵΪw[j], ��ӵ�״̬i��,  
  ����״̬ת�Ʒ��� Ϊ:
  f[i + 1<<j] = max(f[i + 1<<j] , f[i] + k) (sum[f[i] +1 ~ k] <= w[j])
  - sum[l,r] Ϊ[l,r]�� ��Ʒ�ļ�ֵ�ܺ�
  	����ʹ��ǰ׺�ͽ���ά��, ��O(1)��ѯ
    
	��ο��ٲ�ѯ ���ŵ� k (sum[f[i] +1 ~ k] <= w[j]) ?
	����ǰ׺�� ��������, ����Խ��ж��ֲ���
	��logn��ʱ���� ������ŵ�k 
  	 
  - ��ֹ���� 
    ������ f[i] == n, ����˵��״̬i ��Ӳ��, �Ѿ�������ɹ���
    ͳ�����ֵ, ��ȡ���ֵΪ��. ����
*/
#include<cstdio>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define ll long long
const int MARX = 1e5+10;
const int MARXALL = 131080;
//=============================================================
int k, n, all, coin[20], c[MARX], f[MARXALL];;
ll ans = -1, sum[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int upper_search(int value, int l1, int r1)//�ҵ�����[l1,r1] ����value�ĵ�һ��λ�� 
{
	int pos = r1 + 1;
	for(int l = l1, r = r1; l<=r;)
	{
	  int mid = (l + r) >> 1;
	  if(sum[mid] - sum[l1 -1] > value)  pos = mid,r = mid-1;
	  else l = mid + 1;
	}
	return pos;
}
//=============================================================
signed main()
{
	k = read(), n = read(); all = (1 << k) -1;//����ȫ�� 
	for(int i = 1; i <= k; i ++) coin[i] = read();//���벢ά��ǰ׺�� 
	for(int i = 1; i <= n; i ++) c[i] = read(), sum[i] = sum[i-1] + c[i];
	
	for(int i = 0; i <= all; i ++)
	{
	  if(f[i] == n)//״̬��������, ͳ�ƴ� 
	  {
	  	ll sum1 = 0;
	  	for(int j = 0; j < k; j ++) sum1 += (!(1 << j & i))*coin[j+1];//��� δʹ�õ�Ӳ���ܺ� 
	  	ans = max(ans,sum1);//ȡ���ֵ 
	  	continue;
	  }
	  
	  int l = f[i] + 1, r = n, now = 1;//������ֲ��ұ߽�, �뵱ǰö�ٵ���Ӳ�ұ�� 
	  for(; ; )
	  {
		for(;(1 << (now-1) & i) && now <= k;) now++;//ѭ��ö�� ,ֱ�� һ��δ��ʹ�õ�Ӳ�� 
		if(now > k) break;
		
		int pos = upper_search(coin[now],l,r) - 1;//���� ������� 
		f[i | (1 << (now-1))] = max(f[i | (1 << (now-1))], pos);//ת�� 
	    now ++;//���++ 
	  }
	}
	printf("%lld",ans);
}
