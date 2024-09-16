#include<stdio.h>
void main(){
	int i,pid[15],bt[15],n;
	float twt =0,tat =0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter process id of all the processes: ");
	for(i=0;i<n;i++){
		scanf("%d",&pid[i]);
	}
	printf("Enter burst time of all the processes: ");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	int wt[n];
	wt[0]= 0;
	for(i =1;i<n;i++){
		wt[i]= wt[i-1]+bt[i-1];
	}
	printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++){
printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,bt[i],wt[i],bt[i]+wt[i]);
		twt+=wt[i];
		tat+=wt[i]+bt[i];
	}
	float att ,awt;
	awt = twt/n;
	att = tat/n;
	printf("Avg. waiting time = %f\n",awt);
	printf("Avg. turnaround time = %f\n",att);
}