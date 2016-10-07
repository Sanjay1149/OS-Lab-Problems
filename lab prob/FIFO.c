#include<stdio.h>
#include<conio.h>
#include <limits.h>

struct fifo{
int b;
int a;
int p,c,tat,wt;
int time;
};


void main(){

int n,i;
float atat=0.0,awt=0.0;

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
  int t=0;
    while(1)
    {
        int no,min = INT_MAX;
        for(i=0;i<n;i++)
        {
            if(min>fi[i].a)
            {
            min=fi[i].a;
            no=i;
            }
        }
        t = t + fi[no].b;
        fi[no].time=t;
        printf("P%d\t",no+1);
        count++;

        fi[no].c=t;

        fi[no].tat=fi[no].c-fi[no].a;
        fi[no].wt = fi[no].tat-fi[no].b;


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
            printf("\nTAT of P%d is %d",i+1,fi[i].wt);
        }

        atat = atat / n;
        awt = awt / n;

        printf("\n\n ATAT IS : %f ns\n",atat);
        printf("\n\n AWT IS : %f ns\n",awt);
}
