#include<stdio.h>
struct least{
  int a;
  int pri;
};
int exist(int a[],int b,int f){
    int i;
for(i=0;i<f;i++){
        //printf("a[i] is %d and b is %d\t",a[i],b);
    if(a[i]==b)
    {
        return 1;
    }
}
return 0;
}
void display(int b[],int f){
    int i;
    for(i=0;i<f;i++)
        printf("%d\n",b[i]);
}
void fifo(int a[],int f,int n){
    int i,point=0,j=0,flag=0,fault=1;
    int b[n];
    float flo=0;
    /*for(i=0;i<f;i++,j++)
        {
            b[j]=a[i];
        }
        fault=f;*/
        b[point]=a[0];
        point++;
    for(i=1;i<n;i++){
        flag=exist(b,a[i],f);
        if(flag==0){
            b[point]=a[i];
            point++;
            fault++;
            if(point==f)
                point=0;
        }
        //printf("\nFault %d and point is %d \n",fault,point);
        //display(b,f);
    }
    printf("FIFO \n");
    /*display(b,f);
    flo = (float)fault/n;
    printf("\tFault rate is %d / %d =  %f",fault,n,flo);*/
    printf("Fault is %d\n",fault);
}

int place(int a[],int b,int f){
    int i;
for(i=0;i<f;i++){
    if(a[i]==b)
    {
        return i;
    }
}
}
void LFU(struct least s[],int f,int n){
int i,point=0,j=0,index=0,flag=0,fault=0;
    int b[n];
    float flo=0;
    /*for(i=0;i<f;i++,j++)
        {
            b[j]=s[i].a;
        }
        fault=f;
        */
        //b[0]=s[0].a;
        for(i=0;i<n;i++){
            flag=exist(b,s[i].a,f);
            if(flag==1){
                index=place(b,s[i].a,f);
                s[index].pri++;
            }
            else{
                int min=0,count=0;
               while(1){
                if(s[point].pri==min){
                    break;
                }
                count++;
                point++;
                if(point==f)
                    point=0;
                if(count==f){
                    min++;
                    count=0;
                }
               }
               fault++;
               b[point]=s[i].a;
               point++;
               if(point==f)
                point=0;
            }
           // printf("\nFault %d and point is %d \n",fault,point);
           // display(b,f);
        }
        printf("\nLFU \n");
    /*display(b,f);
    flo = (float)fault/n;
    printf("\tFault rate is %d / %d =  %f",fault,n,flo);*/printf("Fault is %d \n",fault);
}


void main(){
int i,f,n;
printf("Enter the no.of.references \n");
scanf("%d",&n);
int a[n];
struct least s[n];
printf("Enter the Reference Strings\n");
for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s[i].a=a[i];
        s[i].pri=0;
        //printf("  i value is %d and n is %d\n",i,n);
    }
printf("Enter the page frame size\n");
scanf("%d",&f);
fifo(a,f,n);
LFU(s,f,n);
}
