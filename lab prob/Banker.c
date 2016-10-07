#include<stdio.h>
#include<conio.h>

struct bank{
int alloc[200];
int max[200];
int avail[200];
int need[200];
int queue[20];
};

void main(){
int n,i,j=0;
struct bank b;
printf("Enter the no.of.processes\n");
scanf("%d",&n);
printf("Allocation \t\t   Max   \t\tAvailable\n");
printf("A    B    C\t\tA   B   C\t\tA   B   C\n");
for(i=1;i<=n;i++){
        scanf("%d %d %d",&b.alloc[j],&b.alloc[j+1],&b.alloc[j+2]
              );
              printf("\n");
              scanf("%d %d %d",&b.max[j],&b.max[j+1],&b.max[j+2]);
              printf("\n");
              if(j<3){
                scanf("%d %d %d",&b.avail[j],&b.avail[j+1],&b.avail[j+2]);
              printf("\n");
              }
              j=j+3;
}
for(i=0;i<j;i++)
{
   b.need[i]=b.max[i]-b.alloc[i];
}
printf("\t\t   NEED  \t\t\n");
printf("\t\tA\t\tB\t\tC\t\t");
for(i=0;i<j;i++)
{
    if(i%3==0)
    {
        printf("\n");
    }
   printf("\t\t%d",b.need[i]);
}
for(i=0;i<n;i++){
    b.queue[i]=-1;
}
int k,total = j;
printf("\nEnter the process to be requested \n");
int pre,okiee=0,a,be,c;
scanf("%d",&pre);
j=(pre-1)*3;
printf("Enter the resources A B and C values\n");
scanf("%d %d %d",&a,&be,&c);
if(a<=b.need[j]&&be<=b.need[j+1]&&c<=b.need[j+2]&&a<=b.avail[0]&&be<=b.avail[1]&&c<=b.avail[2]){
    b.need[j]=b.need[j]-a;
    b.need[j+1]=b.need[j+1]-be;
    b.need[j+2]=b.need[j+2]-c;
    b.avail[j]=b.avail[j]-a;
    b.avail[j+1]=b.avail[j+1]-be;
    b.avail[j+2]=b.avail[j+2]-c;
}
else
    okiee=1;
if(okiee==0)
    {
        for(i=0;i<n;i++){
        int count=0,s,see;
    for(j=0;j<total;j++){
            see = j%3;
            int what = j/3;
            int j1 = what * 3 ;
            int j2 = what * 3 + 1;
            int j3 = what * 3 + 2;
        if(b.need[j1]==0&&b.need[j2]==0&&b.need[j3]==0)
         {
             j=j+2;
         }
         else
            {
                s = b.avail[see]-b.need[j];
               // printf("\nNeed - %d , Avail - %d , S value - %d \n",b.need[j],b.avail[see],s);
               // printf("\n\tj at availability - %d\n",j);
                if(s>=0)
                 {
                   //  printf("\n\tj at if(s>=0)- %d\n",j);
                     count++;
                 }
                else
                  {
                      int m = j%3;
                      if(m==0){
                        j=j+2;
                      }
                      else if(m==1){
                        j=j+1;
                      }
                      count=0;
                  }
                  if(count==3){
                        printf("\n\n");
                        int val=0;
              //       printf("\n\tj - %d\n",j);
              //  printf("\nNeed - %d , Avail - %d , S max- %d \n",b.need[j-2],b.avail[0],b.max[j-2]);
                        b.avail[0]=b.avail[0]+b.max[j-2]-b.need[j-2];
              //  printf("\nNeed - %d , Avail - %d , S max - %d \n",b.need[j-1],b.avail[1],b.max[j-1]);
                        b.avail[1]=b.avail[1]+b.max[j-1]-b.need[j-1];
              //  printf("\nNeed - %d , Avail - %d , S max - %d \n",b.need[j],b.avail[2],b.max[j]);
                        b.avail[2]=b.avail[2]+b.max[j]-b.need[j];
                            printf("\n");
                            int mw = 0;
                       /*     for(mw=0;mw<3;mw++)
                            {
                                printf("\t%d\t",b.avail[mw]);
                            } */
                            printf("\n");
                        b.need[j-2]=b.need[j-1]=b.need[j]=0;
                //     printf("\n\tj - %d\n",j);
                    int div = j/3;
                    val = div;
                //  printf("\nprocess -> %d\n",val);
                  b.queue[i]=val;
                  break;
          }
         }
    }
}
    }
int count=0;
printf("\n");
for(i=0;i<n;i++){
    if(b.queue[i]!=-1)
    {
    //printf("\t%d",b.queue[i]);
        count++;
    }
}
if(count==n)
{
    printf("\nSafe state is  ");
    for(i=0;i<n;i++)
{
    printf("\t%d\t",b.queue[i]);
}
}
else
    printf("\nNo Safe State");
}
