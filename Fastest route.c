#include<stdio.h>
#include<conio.h>
int d[50],length=-1,count=0;
void sp(int c[][50],int fro,int end,int count,int max)
{
  int  count1=1,i,j;
  d[count]=fro;
  if(fro!=end)
  {
    for(i=0;i<=max;i++)
    {
     if(c[fro][i]==1)
     {
      for(j=0;j<count;j++)
if(i==d[j])
{ count1=0; break; }
       if(count1==1)
       { count++;
       sp(c,i,end,count,max);
       d[count]=NULL;
       count--;
}
count1=1;
       }
       }
       }
       else          {
       if(length>count || length==-1)
       length=count;
  return;           }

}
void main()
{
   int a[50],b[50],c[50][50],i,j,n,max,fro,end;
   clrscr();
   printf("enter the value n:");
   scanf("%d",&n);
   printf("enter the starting path:");
   scanf("%d",&fro);
   printf("enter the ending path:");
   scanf("%d",&end);
   printf("first array:");
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
   printf("second array:");
  for(i=0;i<n;i++)
     scanf("%d",&b[i]);
  max=a[0];
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
c[i][j]=0;
     for(i=0;i<n;i++)
     { c[a[i]][b[i]]=1;
      c[b[i]][a[i]]=1;
      if(max<a[i] || max<b[i])
       if(max<a[i])
max=a[i];
else
max=b[i];
       }
    sp(c,fro,end,count,max);
    printf("the no of steps are %d",length);
    getch();
}
