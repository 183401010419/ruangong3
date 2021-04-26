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
void DataStorage(record *com, int n); /*��Ϣ���浽�ļ�*/
void DataFind( ); 
void DataDisPlay( ); 
void DataAdd( ); 
void DataDel( ); 
void DataStatistic( );

int main( )
{
record shangpin[SIZE];
int number=20; /*����Ʒ��*/
char fn; 
printf("\t��������������Ʒ����ϵͳ������������");
while(1)
{
printf("\n\t\t1.��Ʒ��Ϣ¼��\n"); /*��ʾ���˵�*/ 
printf("\t\t2.��Ʒ��Ϣ��ʾ\n");
printf("\t\t3.��Ʒ��Ϣ����\n");
printf("\t\t4.��Ʒ��Ϣ���\n");
printf("\t\t5.��Ʒ��Ϣɾ��\n");
printf("\t\t6.��Ʒ��Ϣͳ��\n");
printf("\t\t0.�˳�ϵͳ");

printf("\n\t��������������������������������\n");

printf("\t���������һ��ѡ�����0-6��: ");
fflush(stdin);
scanf("%c",&fn);
puts("\n");

switch(fn) /*�л�����ͬ����*/
{ 
case '1':
DataInput(shangpin, &number );
break; /*¼����Ϣ*/
case '2':DataDisPlay();
break; /*��Ϣ��ʾ*/
case '3':
DataFind();
break; /*��Ϣ����*/
case '4':
DataAdd( );
break; /*����*/
case '5':
DataDel( );
break; /*ɾ��*/
case '6':
DataStatistic();
break; /*��Ϣͳ��*/
case '0':
return 0;

default:puts("\t\tû�������������˵���");
break;
} 

printf("\n\t\t���!�����������");
getch( );

puts("\n");
} 
} 

void DataInput(record *com, int *nptr) /*��Ʒ��Ϣ¼��*/
{
int i = 0; 
int n ; /*¼�������*/
char YesOrNo; /*�ж��Ƿ񱣴�*/
char shangming[30]; /*����*/
int haoma; /*��Ʒ��*/
char shangjia[10]; /*����*/
float danjia; 
printf("\t\t��������Ʒ����:");
scanf("%d",&n);
*nptr = n; /*nptr������Ʒ����*/ 
printf("\t\t���ڿ�ʼ¼����%d����Ʒ��Ϣ:\n\n",n);
while(i<n)
{
printf("��������Ʒ����Ʒ��:",i+1);
scanf("%s",&shangming);
printf("��������Ʒ����Ʒ��:",i+1);
scanf("%d",&haoma);
printf("��������Ʒ��������:",i+1);
scanf("%s",&shangjia);
printf("��������Ʒ�ĵ��� :",i+1);
scanf("%f",&danjia);
if(danjia>=0&&danjia<=1000) /*��Ч�ĵ��۲�¼��*/
{
strcpy(com[i].name,shangming);
com[i].num = haoma;
strcpy(com[i].shang,shangjia);
com[i].price = danjia;
i =i+1;
} 
else 
printf("����ĵ�����һ����Ч��ֵ!!!\n\n");
} /*����while*/

printf("Ҫ�������ղ�¼���������(Y/N)?"); /*ѡ�񱣴�*/
fflush(stdin);
scanf("%c",&YesOrNo);
if(YesOrNo=='y'||YesOrNo=='Y')
DataStorage(com,n);
else if(YesOrNo=='n'||YesOrNo=='N')
return;
else 
printf("�����˲���ȷ��ѡ��\n");
return;

} /*��������*/

void DataFind( ) /*����*/
{

void OnNumber(record *com,int n ); /*����Ʒ������*/
int key; /*keyΪҪ���ҵĹؼ�ֵ*/
int low = 0; /*����*/
int high ; /*����*/
int mid ; /*�м�ֵ*/
char ans; /*ѡ��*/
record com[SIZE];
int n;

if(DataRead(com,&n)==1) /*���ļ��ж�ȡ��Ϣ*/
{
OnNumber(com,n); /*�Ȱ���Ʒ������*/
high = n;
do
{ 
printf("\n\n\t\t��������Ҫ���ҵ���Ʒ��:");
scanf("%d",&key);

low = 0;high = n; 
while (low <=high) 
{ 
mid = (high + low)/2; /*�۰���ҷ�*/

if (key == com[mid].num ) 
{
printf("\n\t\t��Ҫ�ҵ��ǵ�%d����Ʒ\n",mid + 1);
printf("\t\t������£�\n\n");

printf("���\t\t��Ʒ��\t ��Ʒ��\t������\t����\n"); 
printf("%3d%17s%12d%12s%8.1f\n",mid+1,com[mid].name,com[mid].num,com[mid].shang,
com[mid].price);

break; /*����ҵ����˳�ѭ��*/
} 

if (key > com[mid].num ) low = mid + 1; 
else high = mid - 1; 
} 

if (low > high)
printf("\t\t��û���ҵ�����۸�!\n");
printf("\n\t\t��Ҫ������ѯ��(Y/N)��");
ans = getch( );
} 
while (ans =='Y'||ans == 'y'); /*����do....while*/
}
} 

void DataStorage(record *com, int n) /*¼�뱣���ļ�*/
{
int i;
FILE *comPtr;
char FileName[20];
printf("��������Ҫ������ļ�����");
scanf("%s",FileName);
printf("���ڽ���Ʒ��Ϣ���浽�ļ������Ժ򡭡�\n");
if((comPtr=fopen(FileName,"w"))==NULL)
printf("û�и��ļ�\n");
else
for(i=0 ; i<n ; i++)
fprintf(comPtr,"\n%17s%12d%12s%8.1f",com[i].name,com[i].num,com[i].shang,com[i].price);
fclose(comPtr);
} 

int DataRead(record *com,int *nptr) /*��ȡ�ļ�*/
{
int i=0;
char datafile[20];
FILE *comPtr;

*nptr = 0; 
printf("�������ļ���:");
scanf("%s",datafile);
if((comPtr = fopen(datafile,"r")) == NULL) /*���ļ�*/
{
printf("û�и��ļ������������룡\n");
return 0;
} 
else
{
printf("���ڶ�ȡ��Ʒ���ۣ����Ժ򡭡�\n");
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
void OnPrice(record *com,int n ); /*������*/
void OnNumber(record *com,int n ); /*����Ʒ��*/
int N;
int i;
record com[300];
char YesNo; /*�Ƿ�˳����ʾ*/
char tp; 

if(DataRead(com,&N)==1) /*���ļ���ȡ����*/
{

printf("���\t\t��Ʒ��\t ��Ʒ��\t������\t����\n");
for(i=0;i<N;i++)
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,com[i].price);

printf("Ҫ��˳����ʾ��(Y/N)?");
fflush(stdin);
scanf("%c",&YesNo);
if(YesNo=='y'||YesNo=='Y')
{ 
printf("\t����������ʽ:\n");
printf("\t(1.���۸�����ӵ͵��ߣ�2.����Ʒ������ӵ͵���.)");
fflush(stdin);
scanf("%c",&tp);
if(tp=='1') 
OnPrice(com,N);
else if(tp =='2') 
OnNumber(com,N);
else 
printf("\t�����˲���ȷ�\n"); 
}
}
} /*������ʾ�ɼ�*/

void OnPrice(record *com,int n ) /*������˳��*/
{ int i,j;
record temp;
printf("\t\t����������---\n\n");

printf("��Ʒ����Ϊ%d:\n",n);

for(j=0 ; j<n-1 ; j++) /*ð������*/
for(i=0 ; i<n-j-1 ; i++) 
if(com[i].price>com[i+1].price)
{
temp=com[i]; 
com[i]=com[i+1]; 
com[i+1]=temp; 
}

printf("\n\t\t���ɼ�����Ľ������(�������ӵ͵���):\n\n");

printf("���\t\t��Ʒ��\t ��Ʒ��\t������\t����\n"); 
for(i=0 ; i<n ; i++) 
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,
com[i].price);

} 

void OnNumber(record *com,int n ) /*�����˳��*/
{
int i,j;
record temp;

printf("\t\t����Ʒ������---\n\n"); 

printf("��Ʒ����Ϊ%d:\n",n);

for(j=0 ; j<n-1 ; j++) 
for(i=0 ; i<n-j-1 ; i++) 
if(com[i].num>com[i+1].num)
{
temp=com[i]; 
com[i]=com[i+1]; 
com[i+1]=temp; 
}

printf("\n\t����Ʒ������Ľ������(����Ʒ�Ŵ�С����):\n\n");

printf("���\t\t��Ʒ��\t ��Ʒ��\t������\t����\n"); 
for(i=0 ; i<n ; i++) 
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,
com[i].price);

} 

void DataAdd( ) /*����*/
{ 
int i=0,n,m; /*��Ʒ����*/
char shangming[30]; 
int haoma; /*������*/
char shangjia[10]; 
float danjia; 
char YesOrNo;
record com[SIZE];

printf("\t\t��ȡԭ��������Ϣ---\n");
if(DataRead(com,&n)==1) 
{
printf("\t\t��Ϣ��ȡ���!\n\n");

printf("\t\t������Ҫ��ӵ���Ʒ����:");
scanf("%d",&m);

printf("\t\t���ڿ�ʼ¼����%d����Ʒ��Ϣ:\n\n",m);

while(i<m)
{

printf("��%d����Ʒ����Ʒ��:",i+1);
scanf("%s",&shangming);
printf("��%d����Ʒ����Ʒ��:",i+1);
scanf("%d",&haoma);
printf("��%d����Ʒ��������:",i+1);
scanf("%s",&shangjia);
printf("��%d����Ʒ�ĵ���:",i+1);
scanf("%f",&danjia);
if(danjia>=0&&danjia<=1000) /*��Ч�ĵ��۲�¼��*/
{
strcpy(com[i+n].name,shangming);
com[i+n].num = haoma;
strcpy(com[i+n].shang,shangjia);
com[i+n].price = danjia;
i =i+1;
} 
else 
printf("����ĵ�����һ����Ч��ֵ������������!\n\n");

} 

printf("Ҫ�������ղ�¼���������(Y/N)?");
fflush(stdin);
scanf("%c",&YesOrNo);
if(YesOrNo=='y'||YesOrNo=='Y')
DataStorage(com,n+m);
else if(YesOrNo=='n'||YesOrNo=='N')
return;
else 
printf("�����˲���ȷ�������һ��\n");
return;
}
}

void DataDel( )//ɾ��
{ 
void OnNumber(record *com,int n );
record com[SIZE];
int i; /*�ܼ�¼��*/
int n; /*Ҫɾ���ļ�¼��*/
int m; 

printf("\t\t��ȡԭ��������Ϣ---\n");
if(DataRead(com,&n)==1) 
{
printf("\t\tԭʼ�������£�\n\n");
OnNumber(com,n );

printf("��������Ҫɾ���ļ�¼�����");
scanf("%d",&m);
if(m>=1 && m<=n)
{
for(i=m-1;i<n-1;i++)
com [i] = com[i+1];
DataStorage(com,n-1);
}
} 
}

void DataStatistic( ) /*ͳ����Ϣ*/
{
int high=0,low=200,ave=0;
int n,i,sum=0;
int g,l;
record com[SIZE];
printf("��ȡ������Ϣ---\n");
if(DataRead(com,&n)==1)
{
printf("��Ʒ����Ϊ%d\n\n",n);
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
printf("\t\t���\t���\tƽ��\n"); /*����ֵ*/
printf("��Ʒ����ͳ��:\t%d\t%d\t%d\n\n",high,low,ave);
printf("���\t\t��Ʒ��\t ��Ʒ��\t������\t����\n"); 
for(i=0 ; i<n ; i++) 
printf("%3d%17s%12d%12s%8.1f\n",i+1,com[i].name,com[i].num,com[i].shang,
com[i].price);

printf("\t\t ���\t\t ��Ʒ��\t ��Ʒ��\t ������ ����\n"); 

printf("������ߵ���Ʒ�ǣ�%3d%17s%12d%12s%8.1f\n\n",g+1,com[g].name,com[g].num,com[g].shang,com[g].price);
printf("������͵���Ʒ�ǣ�%3d%17s%12d%12s%8.1f\n",l+1,com[l].name,com[l].num,com[l].shang,com[l].price);

} /*����ͳ��*/
} 