//֪ʶ��:ģ�� 
/*
By:Luckyblock
ob̫ǿ�� 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib> 
#include<iostream>
#include<string>
#include<ctype.h>
const int DIR_X[8] = {-1,-1,0,1,1,1,0,-1};//ICE_BARRAGE ����ʱ�� ����ı��� 
const int DIR_Y[8] = {0,-1,-1,-1,0,1,1,1};
const int EXX[6] = {0,0,1,-1,0,0};//����ռ��� ���ڵı�ש λ�øı��� 
const int EXY[6] = {0,0,0,0,1,-1};
const int EXZ[6] = {-1,1,0,0,0,0};
//=============================================================
int N,HM,HR,HC,HX,HY,M;//����ĸ����� 
int inventory;//����ש�� 
bool ice_block[17][17][1001];//��ά�ռ���ĳ�� �Ƿ��б�ש���� 
int ground_freeze[17][17];//��������� ,�������б�שʱΪ-1 
bool vis[17][17][1001];//��dfs�� ��ͨ��ʱʹ�� 
int max_high;//�ҵ� ǽ����߸߶� 
int doorx=-1,doory=-1,door_high=0,door_dis=110; 
//=========�Ӻ����б�:==========================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void ICE_BARRAGE();//����1,�ͷŵ�Ļ 
void MAKE_ICE_BLOCK();//����2,�ռ���ש
 
void PUT_ICE_BLOCK();//����3,���ñ�ש 
bool JUDGE_PUT(int R,int C,int H);//�ж� ĳλ�� �Ƿ���Է��ñ�ש

int DFS1(int R,int C,int H,int FR,int FC,int FH);//dfs �ж�ĳ��ͨ���Ƿ����� 
int DFS2(int R,int C,int H,int FR,int FC,int FH);//dfs ��ĳ��ͨ�� ɾ�� 
void REMOVE_ICE_BLOCK();//����4,�Ƴ���ש 

void MAKE_ROOF(); //����5, ���췿��, �Ƴ�����,�޲���ȱ,��鷿�� 
int find_max_high();//Ѱ�� ǽ����ߴ� 
void remove_excess(int&,int&);

bool judge_outside(int,int,int);//�ж�ĳ��ש �Ƿ�λ�� ������/�� 
bool judge_inside(int,int,int);

bool fill_high_wall(int);//� �߶�>2��ǽ�� 
void judge_door(int,int,int);//�� �ŵ�λ�� ���бȽ� 
int judge_corner(int,int);//�ж� ���Ƿ��� ǽ��,���ж� �����ĸ�ǽ�� 
bool find_door(int&,int&,int&,int&);//�� �߶�<2��λ�� ���� ,����������� 
void check()//����ʹ��, �����ͼ , �Լ��Ϸ��� 
{
	printf("%d \n",inventory); 
	for(int x=0; x<N; putchar('\n'),x++) 
	  for(int y=0; y<N; y++)
	  {
	  	long long sum=0;//ʹ�� ״ѹ˼�� , ��ÿһ����ά�� �����ϵı�ש����״ѹ 
	    for(int z=0; z<=HM; z++) sum+= (ice_block[x][y][z]) * (1<<z);
	    printf("%3lld",sum);//������ 
	  }
	printf("\n\n\n");
}
//=============================================================
signed main()//sb main���� 
{
	N=read(),HM=read(),HR=read(),HC=read(),HX=read(),HY=read(),M=read();
	while(M--)
	{
	  std::string order;
	  std::cin >> order;
	  if(order == "ICE_BARRAGE") ICE_BARRAGE();
	  if(order == "MAKE_ICE_BLOCK") MAKE_ICE_BLOCK();
	  if(order == "PUT_ICE_BLOCK") PUT_ICE_BLOCK();
	  if(order == "REMOVE_ICE_BLOCK") REMOVE_ICE_BLOCK();
	  if(order == "MAKE_ROOF") MAKE_ROOF(); 
	}
}
//=============================================================
void ICE_BARRAGE()
{
	int R=read(),C=read(),D=read(),S=read();
	int freeze_num = 0,pass_num = 0;//�����ȸı�ĸ����� �� �����ĸ�����(���� 
	
	for(int x=R,y=C; ;x+= DIR_X[D], y+=DIR_Y[D])//ö�����߾����ĸ��� 
	{
	  if(x <0 || x>=N || y<0 || y>=N || ground_freeze[x][y] == -1) break;//ֱ�߲�������
	  if(ground_freeze[x][y] < 4) ground_freeze[x][y]++ , freeze_num ++;//���� ���� 
	  pass_num++;
	  if(pass_num > S) break;//ֱ�߲������� 
	}
	printf("CIRNO FREEZED %d BLOCK(S)\n",freeze_num);
}
void MAKE_ICE_BLOCK()
{
	int collect_num = 0;//�ռ� �ı�ש�� 
	for(int x=0; x<N; x++)
	  for(int y=0; y<N; y++)
	    if(ground_freeze[x][y] == 4)//���Խ����ռ� 
	      inventory++, collect_num++, //������ 
		  ground_freeze[x][y]=0;//���������� 
	printf("CIRNO MADE %d ICE BLOCK(S),NOW SHE HAS %d ICE BLOCK(S)\n",collect_num,inventory);
}
bool JUDGE_PUT(int R,int C,int H)//�ж� ĳλ�� �Ƿ���Է��ñ�ש 
{
	if(ice_block[R][C][H]) return 1;//��λ���ѱ�ռ�� 
	if(H == 0) return 0;//��ש�����Ӵ� 
	for(int i=0;  i<6;  i++) //ö������ռ������ڵ� λ�� 
	  if(R+EXX[i] >= 0 && C+EXY[i] >= 0 && H+EXZ[i] >= 0)
	    if(ice_block[R+EXX[i]][C+EXY[i]][H+EXZ[i]]) //�����ڱ�ש 
		  return 0; //����λ�úϷ� 
	return 1;//��ש���� 
}
void PUT_ICE_BLOCK() 
{
	int R=read(),C=read(),H=read();
	if(!inventory) {printf("CIRNO HAS NO ICE_BLOCK\n"); return ;}//���Ϸ���� 
	if(JUDGE_PUT(R,C,H)) {printf("BAKA CIRNO,CAN'T PUT HERE\n"); return ;}
	
	ice_block[R][C][H] = 1,inventory--;//���ñ�ש 
	if(H==0) ground_freeze[R][C] = -1;//�����Ӵ� ,���ĵ������ֵ 
	if(R<HR || R>HR+HX-1 || C<HC || C>HC+HY-1) printf("CIRNO MISSED THE PLACE\n");//���շ���λ�� ��� 
	  else if(HR+1<=R && R<=HR+HX-2 && HC+1<=C && C<=HC+HY-2) printf("CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE\n");
	 else printf("CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS %d ICE_BLOCK(S)\n",inventory);
}
int DFS1(int R,int C,int H,int FR,int FC,int FH)//dfs �ж�ĳ��ͨ���Ƿ����� 
{
	vis[R][C][H] = 1;//���ʹ�,���� 
	if(H == 0) return 1;//�˱�ש �����Ӵ� , ˵������ͨ��Ϸ� 
	for(int i=0; i<6; i++)//ö�����ڵ� ��ש 
	  if(R+EXX[i] >= 0 && R+EXX[i] <N && C+EXY[i] >= 0) //λ�úϷ� 
	    if(C+EXY[i] < N && H+EXZ[i] >= 0 && H+EXZ[i] <=HM)
	      if(R+EXX[i]!=FR || C+EXY[i]!=FC || H+EXZ[i]!=FH)//���� ��һ���שλ����ͬ 
	  	    if(ice_block[R+EXX[i]][C+EXY[i]][H+EXZ[i]])//�б�ש 
	  	      if(!vis[R+EXX[i]][C+EXY[i]][H+EXZ[i]])//ת�� 
	  	        if(DFS1(R+EXX[i],C+EXY[i],H+EXZ[i],R,C,H)) return 1;//��ͨ�� �����Ӵ� 
	return 0;//���� 
}
int DFS2(int R,int C,int H,int FR,int FC,int FH)//dfs ��ĳ��ͨ�� ɾ�� 
{
	int ret = 0;//���� ɾ���ĸ��� 
	for(int i=0; i<6; i++)
	  if(R+EXX[i] >= 0 && R+EXX[i] <N && C+EXY[i] >= 0) //ö�� �Ϸ������ڱ�ש 
	    if(C+EXY[i] < N && H+EXZ[i] >= 0 && H+EXZ[i] <=HM)
	      if(R+EXX[i]!=FR || C+EXY[i]!=FC || H+EXZ[i]!=FH)
	  	    if(ice_block[R+EXX[i]][C+EXY[i]][H+EXZ[i]])
	  	      ret += DFS2(R+EXX[i],C+EXY[i],H+EXZ[i],R,C,H);//dfs���� 
	return ice_block[R][C][H]=0, ret + 1;//���±�ש�������,����ɾ������ 
}
void REMOVE_ICE_BLOCK()
{
	int R=read(),C=read(),H=read(); 
	if(!ice_block[R][C][H]) {printf("BAKA CIRNO,THERE IS NO ICE_BLOCK\n"); return ;}//���Ϸ����
	
	ice_block[R][C][H] = 0, inventory++;//�Ƴ���ש, �� ������ 
	if(H == 0) ground_freeze[R][C]=0;//������ ��ש����,���������� 
	
	int sum_break = 0;//�����ש���� 
	for(int i=0; i<6; i++)//ö�ٱ�ɾ��λ�� ���ڵ� ���ڵ� ��ש 
	  if(R+EXX[i] >= 0 && R+EXX[i] <N && C+EXY[i] >= 0) 
	    if(C+EXY[i] < N && H+EXZ[i] >= 0 && H+EXZ[i] <=HM)
	      if(ice_block[R+EXX[i]][C+EXY[i]][H+EXZ[i]]) 
	  	  {
	  	  	memset(vis,0,sizeof(vis));//dfs�ж� ���ڱ�ש ��ͨ���Ƿ��� ����Ӵ� 
	  	    if(!DFS1(R+EXX[i],C+EXY[i],H+EXZ[i],-1,-1,-1))
	  	      sum_break += DFS2(R+EXX[i],C+EXY[i],H+EXZ[i],-1,-1,-1);	
		  }
	
	printf("CIRNO REMOVED AN ICE_BLOCK");//�������� 
	if(sum_break) printf(",AND %d BLOCK(S) ARE BROKEN",sum_break);
	printf("\n");
}
void MAKE_ROOF()
{
	int remove = 0, filled = 0, corner=0;//�ж� �Ƿ��Ƴ����� , ���ȱ , ǽ�ǲ�ȱ 
	max_high = find_max_high()+1;//�ҵ� ǽ����߸߶� 
	//� ����:
	{
		for(int x=HR; x<HR+HX; x++)//ö�� ��߸߶ȴ� ����λ�� 
		  for(int y=HC; y<HC+HY; y++)
		  {
		  	inventory -= (!ice_block[x][y][max_high]);//����
		  	ice_block[x][y][max_high] = 1;
		  }
		if(inventory < 0) {printf("SORRY CIRNO,NOT ENOUGH ICE_BLOCK(S) TO MAKE ROOF\n"); return ;}//���Ϸ���� 
		if(max_high <2 || (HX-2)*(HY-2)*max_high < 2) {printf("SORRY CIRNO,HOUSE IS TOO SMALL\n"); return ;}
	}
	//�Ƴ� �����ש:
	{
		int inside=0, outside=0;
		remove_excess(outside,inside);// �Ƴ����� 
		remove = (inside || outside);//�ж��Ƿ� �Ƴ� 
		
		printf("%d ICE_BLOCK(S) INSIDE THE HOUSE NEED TO BE REMOVED\n",inside);//�������� 
		printf("%d ICE_BLOCK(S) OUTSIDE THE HOUSE NEED TO BE REMOVED\n",outside);
		if(!DFS1(HR+1,HC+1,max_high,-1,-1,-1)) {printf("SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS\n"); return ;}//�ж� �ݶ���ͨ���Ƿ����� 
	}
	//� ǽ�ڲ�ȱ:
	{
		filled = fill_high_wall(max_high);//� �߶�>2�� 
		filled += find_door(doorx,doory,door_high,door_dis);//�ڸ߶� <=2��Ѱ����,��� 
		if(inventory < 0) {printf("SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL\n"); return ;}//���Ϸ���� 
	}
	//���С��: 
	{
		printf("GOOD JOB CIRNO,SUCCESSFULLY BUILT THE HOUSE\n");
		if(door_high == 2) printf("DOOR IS OK\n");//�� ��Ϊ2���� 
		else inventory+=(2-door_high),printf("HOUSE HAS NO DOOR\n");//�Ƴ����齨��,������� 
		
		if(filled) printf("WALL NEED TO BE FIXED\n");//�����ȱ 
		else printf("WALL IS OK\n");
		
		for(int z=0; z<=max_high; z++) //�ж� ǽ�ǵ������� 
		  for(int x = HR; x<HR+HX; x+=HX-1)
		    for(int y = HC; y<HC+HY; y+=HY-1)
		      if(!ice_block[x][y][z]) corner=1,inventory--;
		if(corner) printf("CORNER NEED TO BE FIXED\n");
		else printf("CORNER IS OK\n");
		
		printf("CIRNO FINALLY HAS %d ICE_BLOCK(S)\n",inventory>=0?inventory:0);//���ı�ש�� (���޸���ǽ��,�ᵼ�� ���<=0,��ʱ�����������ש�������ȱ 
		if((!remove) && (!filled) && door_high==2 && (!corner) && (!door_dis)) //���� cirno! 
		  printf("CIRNO IS PERFECT!");
	}
}
//MAKE_ROOF �Ӳ��� 
int find_max_high()//Ѱ�� ǽ����ߴ� 
{ 
	for(int i=HM; i>=0; i--)//��������ö�� �߶� 
	{
	  for(int j=HC; j<HC+HY; j++)//ö��ÿһ��ǽ 
	    if(ice_block[HR][j][i]) return i;
	  for(int j=HC; j<HC+HY; j++)
	    if(ice_block[HR+HX-1][j][i]) return i;
	  for(int j=HR; j<HR+HX; j++)
	    if(ice_block[j][HC][i]) return i;
	  for(int j=HR; j<HR+HX; j++)
	    if(ice_block[j][HC+HY-1][i]) return i;
	}
	return -1; 
}
bool judge_outside(int x,int y,int z)//�ж� ĳλ�� �Ƿ��ڷ��� 
{
	if(HR<=x && x<HR+HY)
	  if(HC<=y && y<HC+HX)
	    if(z<=max_high) return 0;
	return 1;
}
bool judge_inside(int x,int y,int z)//�ж� ĳλ�� �Ƿ��ڷ��� 
{
	if(HR<x && x<HR+HY-1)
	  if(HC<y && y<HC+HX-1)
	    if(z<max_high) return 1;
	return 0;
}
void remove_excess(int &outside,int &inside)//�Ƴ� ���෽�� 
{
	for(int x=0; x<N; x++)//ö�� ����ռ��� ÿһ��λ�� 
	  for(int y=0; y<N; y++)
		for(int z=0; z<=HM; z++)
		  if(ice_block[x][y][z])//���ڱ��� 
		  {
		    if(judge_outside(x,y,z))  inventory++,outside++, ice_block[x][y][z]=0;//������ 
		    if(judge_inside(x,y,z)) inventory++,inside++,ice_block[x][y][z]=0;//������ 
			if(!ice_block[x][y][z])//���鱻�Ƴ��� 
			  for(int i=0; i<6; i++)
	  			if(x+EXX[i] >= 0 && x+EXX[i] <N && y+EXY[i] >= 0) //ö�����ںϷ�λ�õ� �� ���ڵ� ��ש 
	    		  if(y+EXY[i] < N && z+EXZ[i] >= 0 && z+EXZ[i] <=HM)
	      			if(ice_block[x+EXX[i]][y+EXY[i]][z+EXZ[i]])
					  if(!judge_outside(x+EXX[i],y+EXY[i],z+EXZ[i]) && (!judge_inside(x+EXX[i],y+EXY[i],z+EXZ[i])))//����� ǽ���� 
						{
						  memset(vis,0,sizeof(vis));	
						  if(!DFS1(x+EXX[i],y+EXY[i],z+EXZ[i],-1,-1,-1)) //��� �Ƴ���λ�ú� ǽ���ϵ� ��ש��ˤ�� 
						    inventory++, ice_block[x+EXX[i]][y+EXY[i]][z+EXZ[i]] = 0;//�����Ƴ� ,������ 
						}
		  }
}
bool fill_high_wall(int max_high)//� �߶�>2����ǽ 
{
	bool filled = 0;
	for(int x=HR; x<HR+HY; x++)//ö��ÿһ��λ�� 
	  for(int y=HC; y<HC+HX; y++)
		for(int z=2; z<=max_high; z++)
		  if(!judge_outside(x,y,z))//�ж� ��ǽ�� 
			if(!judge_inside(x,y,z))
			  if(!ice_block[x][y][z]) 
		      {
		      	if(x==HR && y==HC) continue;//��ǽ��,�� ���� 
		  		if(x==HR && y==HC+HY-1) continue;
		  		if(x==HR+HX-1 && y==HC) continue;
		  		if(x==HR+HX-1 && y==HC+HY-1) continue;
		      	inventory--, filled = 1, ice_block[x][y][z]=1;//� 
			  }
	return filled;//���� �Ƿ���� 
}
void judge_door(int dis,int x,int y,int z)//�ж� λ��(x,y,z) �Ŀ�ȱ �� ��ǰ��¼�Ŀ�ȱ   �ĸ���Ϊ�Ÿ��� 
{
	if(door_high == 0) {doorx=x,doory=y,door_high=1,door_dis=dis; return ;}//��ǰ û�м�¼ 
	if(door_high == 1 && z == 0 && dis < door_dis)//��ǰ��ȱ,�¿�ȱ ��Ϊ1,�� �¿�ȱ ������ǽ���м� 
	{
	  doorx=x,doory=y,door_dis=dis; 
	  return ;
	}
	if(door_high == 1 && z == 1 && ice_block[x][y][0] && dis < door_dis)//��ǰ��ȱΪ1,�¿�ȱΪ1,�� �¿�ȱ ������ǽ���м� 
	{
	  doorx=x,doory=y,door_dis=dis; 
	  return ;
	}
	if(z == 1 && (!ice_block[x][y][0]))//�¿�ȱΪ2 
	{
	  if(door_high == 1) {doorx=x,doory=y,door_high=2,door_dis=dis; return ;}//��ǰ��ȱΪ1 
	  if(dis < door_dis) {doorx=x,doory=y,door_dis=dis; return ;}// �¿�ȱ  ������ǽ���м� 
	}
	return ;
}
int judge_corner(int doorx,int doory)//�ж�λ�� (doorx,doory) �Ƿ���ǽ������ 
{
	if(doorx == HR)//ö�ٲ��ж� 
	{
	  if(doory == HC+1) return 1;
	  else if(doory == HC+HY-2) return 2;
	}
	if(doorx == HR+1)
	{
	  if(doory == HC) return 1;
	  else if(doory == HC+HY-1) return 2;
	}
	if(doorx == HR+HX-2)
	{
	  if(doory == HC) return 3;
	  else if(doory == HC+HY-1) return 4;
	}
	if(doorx == HR+HX-1)
	{
	  if(doory == HC+1) return 3;
	  else if(doory == HC+HY-2) return 4;
	}
	return 0;
}
bool find_door(int &doorx,int &doory,int &door_high,int &door_dis)//�� �߶�<2��λ�� ���� ,�����������
{
	int midX1 = (HX+1)/2+HR-1, midX2 = (HX+2)/2+HR-1;//��ǽ���м�λ�� 
	int midY1 = (HY+1)/2+HC-1, midY2 = (HY+2)/2+HC-1;
	int sum_filled = 0;//��� 
	
	for(int x = midX2,x1 = midX1,dis=0; x<HR+HX-1 && x1>HR; x++,x1--,dis++)//�� �м� ������ö��ǽ 
	  for(int y=HC; y<HC+HX; y+=HX-1)
	    for(int z=0; z<=1; z++)
	    {
	      if(!ice_block[x][y][z]) judge_door(dis,x,y,z);//��� �п�ȱ,���бȽ� 
		  if(!ice_block[x1][y][z]) judge_door(dis,x1,y,z);
		  sum_filled += (!ice_block[x][y][z]) + (!ice_block[x1][y][z]);//���++ 
		}
	for(int y = midY2,y1 = midY1,dis=0; y<HC+HY-1 && y1>HC; y++,y1--,dis++)//�� �м� ������ö��ǽ 
	  for(int x=HR; x<HR+HY; x+=HY-1)
	    for(int z=0; z<=1; z++)
	    {
	      if(!ice_block[x][y][z]) judge_door(dis,x,y,z);//��� �п�ȱ,���бȽ� 
		  if(!ice_block[x][y1][z]) judge_door(dis,x,y1,z);//���++ 
		}
	int door_corner = judge_corner(doorx,doory);//�ж� ���Ƿ� ��ǽ������ 
	
	for(int x=HR; x<HR+HY; x++)//��������� 
	  for(int y=HC; y<HC+HX; y++)
		for(int z=0; z<=1; z++)
		  if(x==HR || x==HR+HY-1 || y==HC || y==HC+HX-1)
		  {
		  	if(x==HR && y==HC && door_corner!=1) continue;//��� ����ס�� ǽ�� 
		  	if(x==HR && y==HC+HY-1 && door_corner!=2) continue;
		  	if(x==HR+HX-1 && y==HC && door_corner!=3) continue;
		  	if(x==HR+HX-1 && y==HC+HY-1 && door_corner!=4) continue;
		  	if(x == doorx && y == doory) continue;
		  	if(!ice_block[x][y][z])//��� �� ���Կ�����ǽ��/ǽ�ڲ�ȱ 
			  ice_block[x][y][z] = 1, inventory --, sum_filled++;
		  }
	return sum_filled; 
}
