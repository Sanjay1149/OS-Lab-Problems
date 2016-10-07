#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void LOOK(int a[],int c,int n,int head){
int max=c,num=n-1,total=0;
    while(max<a[num]){
        num--;
    }
    int left = head - a[0];
    total=left+a[num]-a[0];
     printf("seek is %d\n",total);
}
void FCFS(int a[],int c,int n,int head){
      int total=0,i=0,num=n,val=head;
      while(num--){
        total+=abs(a[i]-val);
       //printf("\na[i] = %d and val = %d and total = %d ",a[i],val,total);
        val=a[i];
        i++;
      }
     printf("seek is %d\n",total);
}
void SCAN(int a[],int c,int n,int head){
    int max=c,num=n-1,total=0;
    while(max<a[num]){
        num--;
    }
    int left,right;
    left=head;
    right=a[num];
     total = left + right;
     printf("seek is %d\n",total);
}
void sort(int a[],int n){
int i,j,temp;
for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
}
/*int start(int index,int a[],int n,int val){
   int total=val,max=INT_MAX,min=INT_MAX,n1=index-1,n2=index+1;
   int f1=0,co=0,f2=0;
     while(a[n1]==0){
            if(n1>0)
               {
                   f1=1;
                   co++;
                   n1--;
               }
           else
            break;
     }
     while(a[n2]!=0){
        if(n2<n)
            {
                f2=1;
                co++;
                n2++;
            }
        else
          break;
     }
      if(f1==0)
     max=a[index]-a[n1];
     if(f2==0)
     min=a[index]-a[n2];
     if(co!=2)
     {
         a[index]=0;
     if(max>min){
        total+=start(n2,a,n,min);
     }
     else{
        total+=start(n1,a,n,max);
     }
     }
     return total;
}*/
void SSTF(int a[],int c,int n,int head){
    int total=0,max=head,min,num=n-1,count=0,fir=a[0],las=a[n-1];
    while(max<a[num]){
        num--;
    }
    int num1,num2;
    while(1){
    if(head!=fir&&head!=las)
    {
            if(count==0)
            {
            num1=num;
            num2=num+1;
            }
            else
            {
            num1=num-1;
            num2=num+1;
            }
            count++;
    while(a[num1]==c)
    {
        num1--;
    }
    while(a[num2]==c)
    {
        num2++;
    }
    if(num1>=0)
    max=abs(head-a[num1]);
    //printf("head is %d and a[num1] is %d so max is %d\n",head,a[num1],max);
    if(num2>=0)
    min=abs(head-a[num2]);
   // printf("head is %d and a[num2] is %d so min is %d\n",head,a[num2],min);
    if(max<min){
    //printf("Total is %d at min %d and max %d\n\n\n",total,min,max);
            //a[num+1]=0;
        total+=max;
        head=a[num1];
        a[num1]=c;
         num=num1;
    }
    else{
    //printf("Total is %d at min %d and max %d\n\n\n",total,min,max);
       // a[num]=0;
        total+=min;
        head=a[num2];
        a[num2]=c;
        num=num2;
    }
    }
    else{
        total+=abs(las-fir);
        break;
    }
}
     printf("seek is %d\n",total);
}
void main(){
int c , n , start ,i,num;
printf("Enter the Cylinder Size\n");
scanf("%d",&c);
printf("Enter the input n\n");
scanf("%d",&n);
int a[n];
printf("Enter the %d sizes of input n\n",n);
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]>c)
{
    i--;
    n=n-1;
}
}
printf("Enter the head\n");
scanf("%d",&start);
printf("\n");
printf("FCFS\n");
FCFS(a,c,n,start);
sort(a,n);
printf("SCAN\n");
SCAN(a,c,n,start);
printf("LOOK\n");
LOOK(a,c,n,start);
/*for(i=0;i<n;i++){
    printf("%d\n",a[i]);
}*/
printf("SSTF\n");
SSTF(a,c,n,start);
}
