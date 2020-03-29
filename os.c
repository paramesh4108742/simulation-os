#include<stdio.h>
#include<conio.h>

#define max 10
 
void pro(int x,int ct,int at[10],int bt[10],int rt[10]);
main()
{
 int pno,y,x,w,z,cnt,tq,tt,rp,at[10],rt[10],bt[10],loc;
 tt=0,w=0,loc=0,z=1;
 printf("Enter the total number of processes in scheduling");
 scanf("%d",&x);
 rp=x;
 for(pno=0;pno<x;pno++)
 {
   printf("\nEnter the values of process p%d\n",pno+1);
   printf("Arrival time of process =");
   scanf("%d",&at[pno]);
   printf("Burst time of process =");
   scanf("%d",&bt[pno]);
   rt[pno]=bt[pno];
 }
 printf("Value of time quantum in first iteration is 3\n");
 cnt=0;
 tq=3;
 for(pno=0;rp!=0;)
 {
   if(rt[pno]<=tq && rt[pno]>0)
   {
     cnt=cnt+rt[pno];
     rt[pno]=0;
     loc=1;
   } 
   else if(rt[pno]>0)
   { 
     rt[pno]-=tq; 
     cnt=cnt+tq; 
   } 
   if(rt[pno]==0 && loc==1)			
   { printf("%d",pno);
     rp--;				
     printf("p %d",pno+1); 
     printf("\t\t\t%d",cnt-at[pno]);
     printf("\t\t\t%d\n",cnt-bt[pno]-at[pno]);
     w=w+cnt-at[pno]-bt[pno]; 
     tt=tt+cnt-at[pno]; 
     loc=0;                   
   } 
   if(pno==x-1)
    {
     z++;
     if(z==2)
     {
       printf("Value of time quantum in second iteration is 6. \n");
       pno=0;
       tq=6;
     }
     else
     {
       break;
     }
    }
    else if(cnt>=at[pno+1])
    {
      pno++;
    }
    else
    {
      pno=0;
    }
   }
   pro(x,cnt,at,bt,rt);
   return 0;
 }
void pro(int x,int ct,int at[10],int bt[10],int rt[10])
{
 float aw,att;
 int y,a,d=x,tp,bst[20],pno[20],wit[20],tnt[20],ind,tlt=0;
 printf("values of third iteration having least burst time.\n");
 for(a=0;a<d;a++)
 {
   bst[a]=rt[a];
   wit[a]=ct-at[a]-bst[a];
   pno[a]=a+1;
 }
 for(a=0;a<d;a++)
 {
   ind=a;
   for(y=a+1;y<d;y++)
   {
     if(bst[y]<bst[ind])
     {
       ind=y;
     }
   }
   tp=bst[a];
   bst[a]=bst[ind];
   bst[ind]=tp;
   tp=pno[a];
   pno[a]=pno[ind];
   pno[ind]=tp;
 }
 for(a=1;a<d;a++)
 {
   for(y=0;y<a;y++)
   {
      wit[a]+=bst[y];
   }
   tlt+=wit[a];
 }
 aw=(float)tlt/d;
 tlt=0;
 printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
 for(a=0;a<d;a++)
 {
   tnt[a]=bst[a]+wit[a];
   tlt=tlt+tnt[a];
   printf("\np%d\t\t\t%d\t\t\t%d\t\t\t%d",pno[a],bst[a],wit[a],tnt[a]);
 }
 att=(float)tlt/d;
 printf("\nTotal Average waiting time = %f",aw);
 printf("\n Total Average turnaround time = %f\n",att);
	
}


