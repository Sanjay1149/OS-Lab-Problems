#include<stdio.h>
struct process{
int val;
int mem;
int check;
};
void display(int n,struct process p[])
{
    int i;
    for(i=0;i<n;i++){
        if(p[i].check==1)
        printf("Process P%d of %d kb is stored in memory partition %d\n",i+1,p[i].val,p[i].mem);
    }
    for(i=0;i<n;i++){
        if(p[i].check==0)
        printf("Process P%d of %d kb must wait\n",i+1,p[i].val);
    }
}
int max(int a[],int n){
    int i,j=0;
    for(i=1;i<n;i++){
        if(a[j]<a[i]){
            j=i;
        }
    }
     return j;
}
void worst(int n,int m,int a[],struct process p[]){
      int i=0,j=0,count=0,k;
      for(j=0;j<m;j++){
        count++;
        k = max(a,n);
        if(p[j].check==0)
        {
            //printf("p[%d].val = %d and a[%d] = %d\n",j,p[j].val,k,a[k]);
            if(p[j].val<=a[k]){
                    i++;
            p[j].check=1;
            p[j].mem=a[k];
            a[k]=0;
            j=0;
            count=0;
            if(i==n){
                break;
            }
        }
        }
        if(count==m)
            break;
      }
      printf("\nWorst Fit :\n");
      display(m,p);
}
void first(int n,int m,int a[],struct process p[]){
    int i,j=0,count=0;
        for(i=0;i<n;i++){
                count++;
            if(p[j].val<=a[i]){
                p[j].mem=a[i];
                p[j].check=1;
                j++;
                a[i]=0;
                i=0;
                count=0;
                if(j==m){
                    break;
                }
            }
            if(count==n){
               //flag=1;
               break;
            }
        }
      printf("\nFirst Fit :\n");
            display(m,p);
}
int near(int a[],int n,int x){
     int i,sub,sub2,j=0;
     while(1)
     {
         sub=a[j]-x;
         if(sub>=0)
            break;
         j++;
         if(j==n)
            return -1;
     }
     if(sub==0)
        return j;
     for(i=j+1;i<n;i++){
           sub2=a[i]-x;
        if(sub2>=0)
        {
            if(sub2==0)
            {
                j=i;
                return j;
            }
            if(sub>sub2){
             j=i;
        }
        }
     }
     return j;
}
void best(int n,int m,int a[],struct process p[]){
    int i,j,k;
    for(j=0;j<m;j++){
    k=near(a,n,p[j].val);
    if(k!=-1){
        p[j].check=1;
        p[j].mem=a[k];
        a[k]=0;
    }
    }
     printf("\nBest Fit :\n");
    display(m,p);
}
void main(){

int n,m,i;
printf("Enter no . of . the memory partitions \n");
scanf("%d",&n);
int a[n],b[n];
printf("Enter the memory partitions \n");
for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }

printf("Enter no . of . the process partitions \n");
scanf("%d",&m);
struct process p[m];
printf("Enter the process partitions \n");
for(i=0;i<m;i++)
    {
        p[i].mem=0;
        p[i].check=0;
        scanf("%d",&p[i].val);
    }

first(n,m,a,p);
for(i=0;i<n;i++)
a[i]=b[i];
for(i=0;i<m;i++)
    {
        p[i].mem=0;
        p[i].check=0;
    }
worst(n,m,a,p);
for(i=0;i<m;i++)
    {
        //printf("\n%d",a[i]);
        p[i].mem=0;
        p[i].check=0;
    }
for(i=0;i<n;i++)
a[i]=b[i];
best(n,m,a,p);
}
