//֪ʶ��: ���ִ�,��������,DP
/*
����g = ���ѽ���� 
 
��������: 
1.���Է��� , 
  ÿ����ֻ���� 
  ����[i�����-(d+g),i�����-(d-g)]
  ת�ƶ���
  
  ת�Ƶ�i+1����ʱ,
  ת����������ϸ�ת������
  �������Ƶõ�
  ���㻬���������������
  �ʿ���,ʹ�õ�������,
  ����DP�Ż� 

2.����Ҫȷ���ı���g��ֵ:
  ���Է���,
  ��gȡһ���ϴ��ֵ��ʱ��,
  ����ת�Ƶķ�Χ
  ����,�ȴ�ʱgС��ֵ��ת�Ʒ�Χ 
  ���㵥����,
  ���Խ��ж��ִ� 
  
�㷨ʵ��:
  ��,ʹ�ö��ִ�,ö�ٱ���g��ֵ 
  ��check��,��һ�鵥�������Ż�DP
  ����ܵ÷�
  �Ƿ���ԴﵽҪ��� k  

ע������: 
1.���ڴ���ת������
  ���󲢲��ǵ�ı��
  ���� ��������
  �����ڽ��л�����������ʱ
  Ҫע�⵱ǰ��������ת�Ƶĵ�,
  ���ܻ���֮�� ��������

  ����Ҫ�ٿ�һ������,
  �����洢���ֵ�ǰ���޹��׵ĵ�
  ����©���� 
*/
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
#define max(a,b) a>b?a:b
const int MARX = 5e5+10;
const int INF = 0x7f;
//=============================================================
int n,d,k,ans;
int a[MARX],far[MARX],f[MARX],qu[5*MARX];
//=============================================================
inline int read()//������ 
{
	int readd; 
	scanf("%lld",&readd); 
	return readd;
}
bool check(int s)
{
	int l=max(1,d-s),r=d+s , h=1,t=1,start=-1;//�������ת������,�������������� 
	std::queue <int> wait_from;//���浱ʱ���޹��׵ĵ� 
	wait_from.push(0);
	memset(f,-INF,sizeof(f));f[0]=0;//��𰸵ı��� ,���г�ʼ�� 
	for(int i=1;i<=n;i++) 
	  if(far[i]>=l && far[i]<=r)//�ҵ���һ���������ת�Ƶ��ĵ�
	  {
	  	start=i;
		break;
	  }
	if(start==-1) return 0;//�޷�����ת�� 
	for(int i=start;i<=n;i++)
	{
	  while(!wait_from.empty())//����ʱ��������ת�Ƶĵ���뵥������ 
	  {
	  	int front=wait_from.front();
	  	if(far[front]+l>far[i])break;//��ǰ��,��֮��ĵ� ��ת�������Ҳ�,��������ת�� 
	  	wait_from.pop();
		if(far[front]+r<far[i]) continue;//��ǰ����ת��������� ,��������ת�� 
	    while(f[qu[t]]<=f[front] && t>=h) t--;//���뵥������ 
	  	qu[++t]=front;
	  }
	  if(far[qu[t]]+r<far[i]) continue;//����޷�ת�Ƶ��˵� (ԭΪbreak,�ĳ�continue��AC) 
	  while(far[qu[h]]+r < far[i]) h++;//ɾ���޷�����ת�Ƶĵ� 
	  
	  int from=qu[h];
	  f[i]=f[from]+a[i];//����ת�� 
	  wait_from.push(i);//�����ݴ���� 
	  if(f[i]>=k) return 1;//��������� 
	}
	return 0;
}
//=============================================================
signed main()
{
	n=read(),d=read(),k=read();
	for(int i=1;i<=n;i++) far[i]=read(),a[i]=read(); 
	int le=0,ri=2e9+10;
	if(!check(ri))//������ζ��޷������ 
	{
	  printf("-1");
	  return 0;
	}
	while(le<=ri)//���ִ� ö�� ������ 
	{
	  int mid=(le+ri)>>1;
	  if(check(mid)) ans=mid,ri=mid-1;
	  else le=mid+1;
	}
	printf("%lld",ans);
}
