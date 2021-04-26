#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 300

typedef struct 
{ 
char name[30];
int num;
char shang[10];
float price;
}record;

void DataInput(record *com, int *nptr); 
int DataRead(record *com,int *nptr) ; 
void DataStorage(record *com, int n); /*信息保存到文件*/
void DataFind( ); 
void DataDisPlay( ); 
void DataAdd( ); 
void DataDel( ); 
void DataStatistic( );

int main( )
{
record shangpin[SIZE];
int number=20; /*设商品数*/
char fn; 
printf("\t～～～～～～商品管理系统～～～～～～");
while(1)
{
printf("\n\t\t1.商品信息录入\n"); /*显示主菜单*/ 
printf("\t\t2.商品信息显示\n");
printf("\t\t3.商品信息查找\n");
printf("\t\t4.商品信息添加\n");
printf("\t\t5.商品信息删除\n");
printf("\t\t6.商品信息统计\n");
printf("\t\t0.退出系统");

printf("\n\t～～～～～～～～～～～～～～～～\n");

printf("\t请输入你的一个选项（数字0-6）: ");
fflush(stdin);
scanf("%c",&fn);
puts("\n");

switch(fn) /*切换到不同功能*/
{ 
case '1':
DataInput(shangpin, &number );
break; /*录入信息*/
case '2':DataDisPlay();
break; /*信息显示*/
case '3':
DataFind();
break; /*信息查找*/
case '4':
DataAdd( );
break; /*增加*/
case '5':
DataDel( );
break; /*删除*/
case '6':
DataStatistic();
break; /*信息统计*/
case '0':
return 0;

default:puts("\t\t没有这个项！返回主菜单！");
break;
} 

printf("\n\t\t完毕!按任意键继续");
getch( );

puts("\n");
} 
} 

void DataInput(record *com, int *nptr) /*商品信息录入*/
{
int i = 0; 
int n ; /*录入的总数*/
char YesOrNo; /*判断是否保存*/
char shangming[30]; /*商名*/
int haoma; /*商品号*/
char shangjia[10]; /*单价*/
float danjia; 
printf("\t\t请输入商品个数:");
scanf("%d",&n);
*nptr = n; /*nptr返回商品个数*/ 
printf("\t\t现在开始录入这%d个商品信息:\n\n",n);
while(i<n)
{
printf("请输入商品的商品名:",i+1);
scanf("%s",&shangming);
printf("请输入商品的商品号:",i+1);
scanf("%d",&haoma);
printf("请输入商品的生产商:",i+1);
scanf("%s",&shangjia);
printf("请输入商品的单价 :",i+1);
scanf("%f",&danjia);
if(danjia>=0&&danjia<=1000) /*有效的单价才录入*/
{
strcpy(com[i].name,shangming);
com[i].num = haoma;
strcpy(com[i].shang,shangjia);
com[i].price = danjia;
i =i+1;
} 
else 
printf("输入的单价是一个无效的值!!!\n\n");
} /*结束while*/

printf("要保存您刚才录入的数据吗(Y/N)?"); /*选择保存*/
fflush(stdin);
scanf("%c",&YesOrNo);
if(YesOrNo=='y'||YesOrNo=='Y')
DataStorage(com,n);
else if(YesOrNo=='n'||YesOrNo=='N')
return;
else 
printf("输入了不正确的选项\n");
return;

} /*结束函数*/

void DataFind( ) /*查找*/
{

void OnNumber(record *com,int n ); /*按商品号排序*/
int key; /*key为要查找的关键值*/
int low = 0; /*下限*/
int high ; /*上限*/
int mid ; /*中间值*/
char ans; /*选项*/
record com[SIZE];
int n;

if(DataRead(com,&n)==1) /*从文件中读取信息*/
{
OnNumber(com,n); /*先按商品号排序*/
high = n;
do
{ 
printf("\n\n\t\t请输入你要查找的商品号:");
scanf("%d",&key);

low = 0;high = n; 
while (low <=high) 
{ 
mid = (high + low)/2; /*折半查找法*/

if (key == com[mid].num ) 
{
printf("\n\t\t你要找的是第%d个商品\n",mid + 1);
printf("\t\t结果如下：\n\n");

printf("序号\t\t商品名\t 商品号\t生产商\t单价\n"); 
printf("%3d%17s%12d%12s%8.1f\n",mid+1,com[mid].name,com[mid].num,com[mid].shang,
com[mid].price);

break; /*如果找到则退出循环*/
} 

if (key > com[mid].num ) low = mid + 1; 
else high = mid - 1; 
} 

if (low > high)
printf("\t\t，没有找到这个价格!\n");
printf("\n\t\t还要继续查询吗(Y/N)？");
ans = getch( );
} 
while (ans =='Y'||ans == 'y'); /*结束do....while*/
}
} 

void DataStorage(record *com, int n) /*录入保存文件*/
{
int i;
FILE *comPtr;
char FileName[20];
printf("请输入您要保存的文件名：");
scanf("%s",FileName);
printf("正在将商品信息保存到文件，请稍候……\n");
if((comPtr=fopen(FileName,"w"))==NULL)
printf("没有该文件\n");
else
for(i=0 ; i<n ; i++)
fprintf(comPtr,"\n%17s%12d%12s%8.1f",com[i].name,com[i].num,com[i].shang,com[i].price);
fclose(comPtr);
} 

int DataRead(record *com,int *nptr) /*读取文件*/
{
int i=0;
char datafile[20];
FILE *comPtr;

*nptr = 0; 
printf("请输入文件名:");
scanf("%s",datafile);
if((comPtr = fopen(datafile,"r")) == NULL) /*打开文件*/
{
printf("没有该文件，请重新输入！\n");
return 0;
} 
else
{
printf("正在读取商品单价，请稍候……\n");
while (!feof(comPtr))
{
fscanf(comPtr,"%s%d%s%f",&com[i].name,&com[i].num,&com[i].shang,&com[i].price);
i++;
}
*nptr = i;
printf("\n");

fclose(comPtr);

return 1;
}

} 

void DataDisPlay()
{
void OnPrice(record *com,int n ); /*按单价*/
void OnNumber(record *com,int n ); /*按商品号*/
int N;
int i;
record com[300];
char YesNo; /*是否按顺序显示*/
char tp; 

if(DataRead(com,&N)==1) /*从文件读取数据*/
{

printf("序号\t\t商品名\t 商品号\t生产商\t单价\n");
for(i=0;i<N;i++)
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,com[i].price);

printf("要按顺序显示吗？(Y/N)?");
fflush(stdin);
scanf("%c",&YesNo);
if(YesNo=='y'||YesNo=='Y')
{ 
printf("\t请输入排序方式:\n");
printf("\t(1.按价格排序从低到高；2.按商品号排序从低到高.)");
fflush(stdin);
scanf("%c",&tp);
if(tp=='1') 
OnPrice(com,N);
else if(tp =='2') 
OnNumber(com,N);
else 
printf("\t输入了不正确项！\n"); 
}
}
} /*结束显示成绩*/

void OnPrice(record *com,int n ) /*按单价顺序*/
{ int i,j;
record temp;
printf("\t\t按单价排序---\n\n");

printf("商品总数为%d:\n",n);

for(j=0 ; j<n-1 ; j++) /*冒泡排序*/
for(i=0 ; i<n-j-1 ; i++) 
if(com[i].price>com[i+1].price)
{
temp=com[i]; 
com[i]=com[i+1]; 
com[i+1]=temp; 
}

printf("\n\t\t按成绩排序的结果如下(按分数从低到高):\n\n");

printf("序号\t\t商品名\t 商品号\t生产商\t单价\n"); 
for(i=0 ; i<n ; i++) 
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,
com[i].price);

} 

void OnNumber(record *com,int n ) /*按序号顺序*/
{
int i,j;
record temp;

printf("\t\t按商品号排序---\n\n"); 

printf("商品总数为%d:\n",n);

for(j=0 ; j<n-1 ; j++) 
for(i=0 ; i<n-j-1 ; i++) 
if(com[i].num>com[i+1].num)
{
temp=com[i]; 
com[i]=com[i+1]; 
com[i+1]=temp; 
}

printf("\n\t按商品号排序的结果如下(按商品号从小到大):\n\n");

printf("序号\t\t商品名\t 商品号\t生产商\t单价\n"); 
for(i=0 ; i<n ; i++) 
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,
com[i].price);

} 

void DataAdd( ) /*增加*/
{ 
int i=0,n,m; /*商品名称*/
char shangming[30]; 
int haoma; /*生产商*/
char shangjia[10]; 
float danjia; 
char YesOrNo;
record com[SIZE];

printf("\t\t读取原有数据信息---\n");
if(DataRead(com,&n)==1) 
{
printf("\t\t信息读取完毕!\n\n");

printf("\t\t请输入要添加的商品总数:");
scanf("%d",&m);

printf("\t\t现在开始录入这%d个商品信息:\n\n",m);

while(i<m)
{

printf("第%d个商品的商品名:",i+1);
scanf("%s",&shangming);
printf("第%d个商品的商品号:",i+1);
scanf("%d",&haoma);
printf("第%d个商品的生产商:",i+1);
scanf("%s",&shangjia);
printf("第%d个商品的单价:",i+1);
scanf("%f",&danjia);
if(danjia>=0&&danjia<=1000) /*有效的单价才录入*/
{
strcpy(com[i+n].name,shangming);
com[i+n].num = haoma;
strcpy(com[i+n].shang,shangjia);
com[i+n].price = danjia;
i =i+1;
} 
else 
printf("输入的单价是一个无效的值，请重新输入!\n\n");

} 

printf("要保存您刚才录入的数据吗(Y/N)?");
fflush(stdin);
scanf("%c",&YesOrNo);
if(YesOrNo=='y'||YesOrNo=='Y')
DataStorage(com,n+m);
else if(YesOrNo=='n'||YesOrNo=='N')
return;
else 
printf("输入了不正确项，返回上一级\n");
return;
}
}

void DataDel( )//删除
{ 
void OnNumber(record *com,int n );
record com[SIZE];
int i; /*总记录数*/
int n; /*要删除的记录号*/
int m; 

printf("\t\t读取原有数据信息---\n");
if(DataRead(com,&n)==1) 
{
printf("\t\t原始数据如下：\n\n");
OnNumber(com,n );

printf("请输入你要删除的记录的序号");
scanf("%d",&m);
if(m>=1 && m<=n)
{
for(i=m-1;i<n-1;i++)
com [i] = com[i+1];
DataStorage(com,n-1);
}
} 
}

void DataStatistic( ) /*统计信息*/
{
int high=0,low=200,ave=0;
int n,i,sum=0;
int g,l;
record com[SIZE];
printf("读取数据信息---\n");
if(DataRead(com,&n)==1)
{
printf("商品总数为%d\n\n",n);
for(i=0;i<n;i++)
{
if(com[i].price>high)
{
high = com[i].price;
g=i;
}
if(com[i].price<low)
{
low = com[i].price; 
l=i;
}
sum += com[i].price;
}
ave=sum/n;
printf("\t\t最高\t最低\t平均\n"); /*计算值*/
printf("商品单价统计:\t%d\t%d\t%d\n\n",high,low,ave);
printf("序号\t\t商品名\t 商品号\t生产商\t单价\n"); 
for(i=0 ; i<n ; i++) 
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,
com[i].price);

printf("\t\t 序号\t\t 商品名\t 商品号\t 生产商 单价\n"); 

printf("单价最高的商品是：%3d%17s%12d%12s%8.1f\n\n",g+1,com[g].name,com[g].num,com[g].shang,com[g].price);
printf("单价最低的商品是：%3d%17s%12d%12s%8.1f\n",l+1,com[l].name,com[l].num,com[l].shang,com[l].price);

} /*结束统计*/
} 