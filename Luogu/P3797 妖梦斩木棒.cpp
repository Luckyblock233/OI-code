//֪ʶ��: �߶���,ģ�� 
/*
By:Luckyblock
��ĿҪ��:   
���� һ ����Ϊ n ���ִ� , �� ��(�� ����X�� �� ��)�������ַ����� ,   
��ʼ״̬ Ϊ  ��(XX...XX)��   
��Ҫ֧���������ֲ���:    
1.  �޸� : ���� i ��Ԫ���滻Ϊ ����Ԫ���� �����ĵ�һ��.   
2.  ��ѯ : ��ѯ���� [l,r] �� , ���� ��(X..X)�� �� ��()�� �ַ����ĸ���   
	( Ŀ���ִ� ��βΪ ��()��  , �� ��()���м� ֻ�ܴ��� ��X�� )   



��������:   

һ��ʼ���������· = = ,    
�õ������ ������������ ʵ���� ����û�еĽ���   
��������� ,  �õ�ֻ�����н��� :   

1. ����һ��ֻ�� ��(�� �� ��)�����ɵ��ִ� ,   
	������ ����λ�� ���� �������� �� ��X�� ,     
	������������ Ŀ���ִ���������û��Ӱ��   

	���ݴ˽��� , ���Խ� ԭ�ִ� ���� ת�� ,   
	�������� �� ��X��,  �Ա���֮��ĵ� ����������	   

2.  ������ ���������ִ� A�� B    
	A, B �� Ŀ���ִ� ������ �ֱ�Ϊ sum_a �� sum_b,    
	 �� ������ �ϲ��� Ŀ���ִ�������  sum_{a+b}    
	
    - ��Ȼ , �ϲ��� sum_{a+b}����Ϊ sum_a + sum_b    
	  �ɲ����ܳ����µ�Ŀ���ִ� , ʹ�ϲ��� Ŀ���ִ�������������  ?    
	  ���ǿ϶���.     

	    ��������� (���������е� ��X��) :   
	
      | ...( | )...| ...()..| 
      | A 	 | B   |   A+B  |
      ��ʱ��: sum_{a+b} = sum_a+sum_b+1  

    - �ϲ�ʱ ���ά�� ���� ������������ Ŀ���ִ�??   
	  ����ά��ÿһ������� �����ķ� ��X���ַ��� ���Ҳ�ķǡ�X���ַ�.   
	  
	  �ںϲ�ʱ , �� ���������Ҳ�Ϊ��(���� �����������Ϊ��)�� 
	  ��֤�� �����������  , ����Ŀ���ִ���+1   

3. �ɽ��� 2��չ���� :   
	���ά�� ����� ����,���Ҳ�� �ǡ�X���� ?   
	
	- ������ֻ��һ��Ԫ��ʱ: �� �ǡ�X���ַ� �� ��Ԫ��   
	- ������ �ж��Ԫ��ʱ, ���Խ����� ���� �����ཻ�� ������ϲ����� :   
		1. �������������ȫΪ��X��ʱ  ,     
			��������� �ǡ�X���ַ� = �������� ������ ��X���ַ�,     
			�������Ҳ� �ǡ�X���ַ� = �������� ���Ҳ�� ��X���ַ�,     
			
		2. ���������� ȫΪ��X��ʱ:   
			��������� �ǡ�X���ַ� = **��**������ ��**��**��� $��X��$ �ַ�,     
			�������Ҳ� �ǡ�X���ַ� = **��**������ ��**��**��� $��X��$ �ַ�,     
		3. ���������� ȫΪ��X��ʱ:  ͬ 2 

	- ���� , ֻ��Ҫ��ά�� �����Ƿ�Ϊ�� ,        
	  ����Ϣ������ �ݹ�ش� ������ά�� .      

4. ��ĿҪ��� �����ѯ:    
	���� �� �򵥵��������     
	���� ���� ���� 2 ��������: ��� ��������� Ŀ���ִ�     
	����Ҫ�� �߶�����������Ͳ��� ����΢С�ĸ���:     
	
	���ѯ����Ϊ [L,R] , ���Է���:     
	
	�������� 3 ������ʱ , ���� ��� ��������� Ŀ���ִ�     
	- �� [L,R]��� ĳ���� �� ����������    
	- �������� ���Ҳ�  �� ��X�� �ַ�Ϊ  ��(��, λ��Ϊ pos1    
	  �������� �����  �� ��X���ַ�Ϊ ��)��, λ��Ϊ pos2    
	- L<= pos1 �� pos2 <= R   
	
	Ϊʵ���������� , ����Ҫά�� ���� , ���Ҳ�� �� ��X�� �ַ� ��λ��       
	
	

�㷨ʵ��:

���� �������� , ������Ҫһ�����ݽṹ ,    
֧�� ά��������Ϣ , �ݹ�ش� , �����޸�   

- ���� һ�� ά������ ������Ϣ���߶���:
	- ������һ�� �ǡ�X���ַ� �Ƿ�Ϊ ��)��
	  ���Ҳ��һ�� �ǡ�X���ַ� �Ƿ�Ϊ ��(��
    - �Ƿ�ȫ��Ϊ ��X��  
    - Ŀ���ִ�����
- �����޸� ���� :
   �������� Ŀ�� Ҷ�ڵ� , ����Ҷ�ڵ����Ϣ
   ֮�� ���� ���� 2,3 , �ݹ����������Ϣ 
- �����ѯ ���� : ���ݽ���4, ������ͼ���
*/
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
#define ls (now<<1)
#define rs ((now<<1)+1)
const int MARX = 2e5+10;
//=============================================================
struct node
{
    int L,R;//ά��������,
    bool allX,side[3];//�Ƿ�ȫΪX , side[0]:������Ƿ���) , side[1]:���Ҳ��Ƿ���( ,
    int sum,pos[3]; //����������ľ����, �������� �����),���Ҳ�( λ�� 
}tree[MARX<<4];
int n,m, map[110],map1[3];//map��ӳ���ϵ, 0<->( , 1<->) , 2<->X 
char now_list[MARX];//��ǰ�� �ִ� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void Build(int now,int l,int r)//���潨��
{
    tree[now].L=l,tree[now].R=r;
    if(l == r) return ;
    int mid = (l+r)>>1;
    Build(ls,l,mid);
    Build(rs,mid+1,r);
}
void pushup(int now)//���� ��now���ڵ� �ĸ���Ϣ 
{
    //ά�� ��������� �Ƿ���) 
    if(tree[ls].side[0]) tree[now].side[0]=1, tree[now].pos[0] = tree[ls].pos[0]; 
    else if(!tree[ls].allX && tree[rs].side[0]) tree[now].side[0]=1 , tree[now].pos[0]= tree[rs].pos[0];
    else tree[now].side[0] = 0;
    //ά�� �������Ҳ� �Ƿ���( 
    if(tree[rs].side[1]) tree[now].side[1]=1 , tree[now].pos[1] = tree[rs].pos[1];
    else if(!tree[rs].allX && tree[ls].side[1]) tree[now].side[1]=1 , tree[now].pos[1]= tree[ls].pos[1];
    else tree[now].side[1] = 0;
    //�������� �Ϸ��ִ���, �����Ƿ�ȫΪ'X' 
    tree[now].sum = tree[ls].sum+tree[rs].sum + (tree[ls].side[1] && tree[rs].side[0]);;
    tree[now].allX = (tree[ls].allX || tree[rs].allX);
}
void Change(int now,int pos,int value) //�����޸�, ����pos��λ���޸�Ϊ value 
{
    if(tree[now].L==pos && tree[now].R==pos)//��ǰ���� ��ָ��λ�� 
    {
      now_list[pos] = map1[value];//���¸���Ϣ 
      tree[now].allX = (value!=2);//�Ƿ�ȫΪX 
      tree[now].side[0] = tree[now].side[1] = 0;//���� ����,���Ҳ�Ԫ�� 
      tree[now].side[value] = 1, tree[now].pos[value]=pos;
      return ;
    }
    int mid = (tree[now].L+tree[now].R)>>1;
    if(pos <= mid) Change(ls,pos,value);
    if(pos > mid) Change(rs,pos,value);
    pushup(now);//���µ�ǰλ�� 
}
int Inquiry(int now,int L,int R)//��ѯ���� L,R ��Ŀ���ִ��� 
{
    if(L <= tree[now].L && tree[now].R <= R) return tree[now].sum;
    int sum=0,flag=0;//flag �ж����� �Ƿ�ͬʱ��������������¹�   
    int mid = (tree[now].L+tree[now].R)>>1;
    if(L<=mid) sum += Inquiry(ls,L,R), flag++;
    if(R>mid) sum += Inquiry(rs,L,R), flag++;
    //���� �Ϸ��ִ� �������������  
    if(flag == 2) sum += (tree[ls].side[1] && L<=tree[ls].pos[1] && tree[rs].side[0] && R>=tree[rs].pos[0]);
    return sum; 
}
void prepare()//Ԥ���� 
{
    n=read() , m=read();
    Build(1,1,n);
    Change(1,1,1) , Change(1,n,0);

    now_list[1]='(' , now_list[n]=')';//ԭʼ�ִ� 
    for(int i=2; i<n; i++) now_list[i]='X';

    map['(']=1, map[')']=0, map['X']=2;//����ӳ���ϵ 
    map1[1]='(',map1[0]=')',map1[2]='X';
}
//=============================================================
signed main()
{
    prepare();
    for(int i=1; i<=m; i++)
    {
      int type=read(),value1,value2;
      char value3;
      if(type == 1) //�޸Ĳ��� 
      {
        value1=read(); value3 = getchar();//������� 
        getchar();
        if(now_list[value1] == value3) continue;
        Change(1,value1,map[(int)(value3)]);
      }
      else //��ѯ���� 
      {
        value1=read(), value2=read();
        printf("%d\n",Inquiry(1,value1,value2));
      }
    }
}
