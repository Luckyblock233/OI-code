//֪ʶ��:̰��,���ִ�,�������� 
/*
����,һ��ʼ�Ҳ�������= =
���ǿ��Ǹ��ֲ��ַֽⷨ:


1. m=1 20��:
ֻ��Ҫ�ҵ�һ��·��.
�ҵ������·������.
����ÿ���ڵ�ά���γ��������
�����·�� = max(��� + �γ���) 

2. ai=1 20��:
�ջ�ͼ,ö��������������ÿһ����,
������߿����������賤��,��ô���߳�·
����,����������ƥ��: 
	ʹ����� ƥ�� ��̱�
	�������ƥ��,�������ƥ��ζ̱�
	(��Ϊ�����ܴ��ں���̱�ƥ��ı���) 
ע��: ���� �����Գ�һ· �� ������<2,Ҳ���ܽ���˫��ƥ�� 
��ʱע���ж� . 

3. bi=ai+1 20��:
��״�ṹ,��������Ӷκ�
��һ�����и�Ϊ k��-���� , ʹÿ�����������㳤��Ҫ��
O(n) ��������ɨһ�鼴��
Ҳ���Խ���״�ṹ ���� ������ ,�������������� 

4.��֧������3 50��:
ʵ�����Ƕ�����,����sd���ҿ�����������= =, (�����ֶ�һ�� 
1. ��������
2. ���ݺ�,������޵�·�Ϸ�, Ȼ����� �����以��ƥ��
3. �ݹ�ش� û�б�����ƥ��� , ���������. 

����������� ȫ��ʵ�ֺ�,��75�����ҵĲ��ַ�.
ʵ����̫������ (���� 


����:
1. ��������     
2. ���ݺ� , ������޵�·�Ϸ�, Ȼ����� �����以��ƥ��    
   - ����ƥ����� ��� �ջ�ͼ��� ,     
      ���� ����̰�ķ� ��ƥ���� , һ�������� .     
      ���ǻش��� ��  ,  ��һ���� ��ƥ������ͬ����� �ܹ��ش������   
    - �����ٽ���һ�ζ��ִ�  ,          
      ���� **��ƥ������ͬ����� �ܹ��ش������ ���ĳ���     
   - Ȼ�� ���������޳����ֳ������������ �ٽ���̰��ƥ��
     ���ƥ���� ��ȻΪ���ƥ���� , ��ô�ͺϷ�. 
3. �ݹ�ش� û�б�����ƥ��� , ���������.       
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int MARX = 5e4+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[2*MARX];
int n,m,num,  head[MARX];//��ͼ���� 
int ans,sum;//check����,��¼��ǰ�õ������� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)
{
	e[++num].u=u,e[num].v=v,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
int dfs(int u,int fa,int s)
{
	int marx=0; std::vector <int> tmp;
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v!=fa)
	  {
	  	int ret = dfs(e[i].v,u,s)+e[i].w;
	  	if(ret>=s) sum++,ret=0;
	  	if(ret) tmp.push_back(ret);
	  	marx = max(marx,ret);
	  }
	if(tmp.size()<2) return marx;
	//������ƥ���� 
	int tmpsum=0,ret1=0 ; std::sort(tmp.begin(),tmp.end());	
	for(int l=0,r=tmp.size()-1; l<r;)//��βƥ�� 
	{
	  if(tmp[l]+tmp[r]>=s) l++,r--,tmpsum++;//����ɺϷ�·�� 
	  else l++;//ȥ����̱� 
	}
	//����� �ش��� 
	for(int le=0,ri=tmp.size()-1,tmpsum1=tmpsum; le<=ri;tmpsum1=tmpsum)
	{
	  int mid=(le+ri)>>1;
	  for(int l=0,r=(tmp.size())-1; l<r;)//��βƥ�� 
	  {
	  	l+= (l==mid) , r-=(r==mid);
		if(l>=r) break;
	  	if(tmp[l]+tmp[r]>=s) l++,r--,tmpsum1--;//����ɺϷ�·�� 
	  	else l++;//ȥ����̱� 
	  }
	  
	  if(tmpsum1<=0) ret1=tmp[mid],le=mid+1;
	  else ri=mid-1;
	}
	return sum+=tmpsum , ret1;
}
bool check(int s)
{
	dfs(1,0,s);
	return sum >= m;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<n; i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w),add(v,u,w);
	}
	
	for(int l=1,r=1e12; l<=r;)
	{
	  int mid = (l+r)>>1;  sum=0;
	  if(check(mid)) ans=mid,l=mid+1;
	  else r=mid-1;
	}
	printf("%lld",ans);
}
//80�� 
/* 
#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int MARX = 5e4+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[2*MARX];
int n,m,num,  head[MARX],out[MARX];//��ͼ���� 
int mode=1,ans,sum;//check����,��¼��ǰ�õ������� 
bool flag2=1,flag3=1,flag4=1;//�ֱ��������4����� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)
{
	e[++num].u=u,e[num].v=v,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
int dfs1(int u,int fa)//���1: m=1 
{
	int marx=0,marx2=0;// ���,�γ��� 
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v!=fa)
	  {
	  	int ret = dfs1(e[i].v,u)+e[i].w;//�ӽڵ㴫�ص���� 
		if(ret>=marx) {marx2=marx , marx=ret;}//ά�� ���,�γ���
	  }
	ans=max(ans,(marx+marx2));//�����·��= max(���+�γ���) 
	return marx;//�ݹ�ش���� 
}
int dfs4(int u,int fa,int s)//���4: ������ 
{
	int marx=0; std::vector<int>tmp;//ά�� δ��ƥ��� ��� 
	for(int i=head[u];i;i=e[i].ne)
	  if(e[i].v!=fa)
	  {
	  	int ret = dfs4(e[i].v,u,s)+e[i].w;//�ӽڵ㴫�ص���� 
	  	if(ret>=s) sum++,ret=0;//�������㳤��Ҫ�� 
		if(ret) tmp.push_back(ret);
	  	marx=max(marx,ret);
	  }
	if(tmp.size()<2) return marx;//��ƥ�����С��2,�˽ڵ㲻��ƥ�� 
	
	std::sort(tmp.begin(),tmp.end());
	if(tmp.size() == 2)//�������� ������ ƥ�� 
	{
	  if(tmp[0]+tmp[1]>=s) {sum++; return 0;}//ƥ��ɹ�,����0 
	  return marx;//ƥ�䲻�ɹ� 
	}
	//�������� ������ ƥ�� ;  ���ݻش��Ĵ��ŵ���,ö��������� 
	if(tmp[0]+tmp[1]>=s) {sum++; return tmp[2];}
	if(tmp[0]+tmp[2]>=s) {sum++; return tmp[1];}
	if(tmp[1]+tmp[2]>=s) {sum++; return tmp[0];}
	return marx;
}
bool check(int s)
{
	if(mode == 4) dfs4(1,0,s);//���4:������ 
	if(mode == 3) //���3: ��״�ṹ 
	{
	  for(int i=1,now=0;i<n;i++)
	    for(int j=head[i];j;j=e[j].ne)
	      if(e[j].v==i+1)//��������ö�ٱ� 
	      {
	      	if(now+e[j].w>=s) sum++,now=0;//����ɺϷ�·�� 
	      	else now+=e[j].w;//������ 
		  }
	}
	if(mode == 2) //���2: �ջ�ͼ 
	{
	  std::vector <int> tmp;
	  for(int i=head[1];i;i=e[i].ne)//�����ܵ�·�Ϸ��ļ������� 
	  {
	  	if(e[i].w>=s) sum++;//��·�Ϸ� 
	  	else tmp.push_back(e[i].w);
	  }
	  if(tmp.size()>=2)
	  {
	    std::sort(tmp.begin(),tmp.end());//���� 
	    for(int l=0,r=tmp.size()-1;l<r;)//��βƥ�� 
	    {
	  	  if(tmp[l]+tmp[r]>=s) l++,r--,sum++;//����ɺϷ�·�� 
	  	  else l++;//ȥ����̱� 
	    }
	  }
	}
	
	return sum>=m;
}
//=============================================================
signed main()
{
	freopen("testdata.in","r",stdin);
//	freopen("track.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w),add(v,u,w);
	  out[u]++,out[v]++;
	  if(u!=1 && v!=1) flag2=0;
	  if((u-v!=1) || (u-v!=(-1))) flag3=0;
	  if(out[u]>4 || out[v]>4) flag4=0;
	}
	
	if(m==1 && flag4==0)
	{
	  dfs1(1,0);
	  printf("%lld",ans); return 0;
	}
	
	if(flag2) mode=2;
	else if(flag3) mode=3;
		 else if(flag4) mode=4;
			  else {printf("koishi suki!");return 0;}
	
	int l=1,r=1e12+10;
	while(l<=r)
	{
	  int mid = (l+r)>>1;  sum=0;
	  if(check(mid)) ans=mid,l=mid+1;
	  else r=mid-1;
	}
	printf("%lld",ans);
}
*/ 
