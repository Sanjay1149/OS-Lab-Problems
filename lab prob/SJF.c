#include<stdio.h>
#include<conio.h>
#include <limits.h>

struct fifo{
int b;
int a;
int p;
int c;
int tat;
int wt;
int time;
};


void main(){

int n,i;
float atat=0,awt=0;

printf("INPUT :\n");

printf("No . of . Processors ");
scanf("%d",&n);

struct fifo fi[n];

for(i=0;i<n;i++){
    fi[i].b=0;
    fi[i].a=0;
}

printf("Enter the Burst time for the processes\n");
for(i=0;i<n;i++){
    scanf("%d",&fi[i].b);
}
printf("Enter the Arrival time for the processes\n");
for(i=0;i<n;i++){
    scanf("%d",&fi[i].a);
}
printf("Process\tBurst Time\tArrival Time\n");
for(i=0;i<n;i++)
{
    printf(" P%d    \t    %d     \t     %d      \n",i+1,fi[i].b,fi[i].a);
  }
  int count=0;
  int t=0,s=0,k=0,j;
  int min = INT_MAX;
  for(j=0;j<n;j++)
  {
      if(min>fi[j].a)
      {
          min = fi[j].a;
          s=j;
      }
  }
    while(1)
    {
        int no,min = INT_MAX;
        for(i=0;i<n;i++)
        {
            if(fi[i].a<=s){
            if(min>fi[i].b)
            {
            min=fi[i].b;
            no=i;
            }
            }
        }
        k+=fi[no].b;
        s+=fi[no].b;

        fi[no].c=k;

        fi[no].tat=fi[no].c-fi[no].a;
        printf("\t\tno is %d whose ct is %d and tat is %d\n",no,fi[no].c,fi[no].a);
        fi[no].wt = fi[no].tat-fi[no].b;

        t = t + fi[no].b;
        fi[no].time=t;
        printf("P%d  -   %d\n",no+1,t);
        count++;
        fi[no].a=INT_MAX;
        if(count==n)
            break;
    }
        for(i=0;i<n;i++)
        {
            atat +=fi[i].tat;
            printf("\nTAT of P%d is %d",i+1,fi[i].tat);
        }
        for(i=0;i<n;i++)
        {
            awt +=fi[i].wt;
            printf("\nWT of P%d is %d",i+1,fi[i].wt);
        }

        atat = atat / n;
        awt = awt / n;

        printf("\n\n ATAT IS : %f ns\n",atat);
        printf("\n\n AWT IS : %f ns\n",awt);


}

