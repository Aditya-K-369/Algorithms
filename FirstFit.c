#include<stdio.h>

void firstFit(int m,int memory[],int p,int process[]){
    int i,j, allocation[m];
    for(i=0;i<m;i++){
        allocation[i]=-1;
    }
    for(i=0;i<p;i++){
        for(j=0;j<m;j++){
            if(memory[j]>=process[i]){
                allocation[i]=j;
                memory[j]-=process[i];
            break;
            }
        }
    }
    printf("Process NO.\tProcess Size\tBlock no.\n");
    for(i=0;i<p;i++){
        printf("%d\t\t%d\t\t\t\t",i+1,process[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]+1);

        }else{
            printf("Not Allocated\n");
        }
    }


}


void main(){
    int m,p,memory[100],process[100];
    printf("Enter number of memory blocks: ");
    scanf("%d",&m);
    printf("Enter sizes of each memory block:\n");
    for(int i=0;i<m;i++){
        printf("Block %d: ",i+1);
        scanf("%d",&memory[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d",&p);
    printf("Enter sizes of each process:\n");
    for(int i=0;i<p;i++){
        printf("process %d: ",i+1);
        scanf("%d",&process[i]);
    }

    firstFit(m,memory,p,process);
}