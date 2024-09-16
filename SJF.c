#include<stdio.h>
void main(){
    int p[30],bt[30],tat[30],n,i,j,temp,pos,total_wt=0,total_tat=0;
    float avg_wt,avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter burst time: \n");
    for(i=0;i<n;i++){
        printf("p%d: ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(bt[i]<bt[j]){
                temp = bt[j];
                bt[j]=bt[i];
                bt[i]=temp;
                temp = p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
int wt[n];
wt[0]=0;
for(i=1;i<n;i++){
    wt[i]=wt[i-1]+bt[i-1];
}
for(i=0;i<n;i++){
    tat[i]=bt[i]+wt[i];
}
printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
for(i=0;i<n;i++){
    printf("p%d\t\t%d\t\t%d\t\t%d\t\t\n",p[i],bt[i],wt[i],tat[i]);
    total_wt+=wt[i];
    total_tat+=tat[i];
}
avg_tat=total_tat*1.0/n;
avg_wt=total_wt*1.0/n;
printf("Average Waiting Time = %f\n",avg_wt);
printf("Average Turnaround Time = %f",avg_tat);
}