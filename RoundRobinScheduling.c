#include<stdio.h>
void main(){
	int cnt,j,n,t ,remain,flag= 0,tq,wt = 0,at[10],bt[10],rt[10];
	float tat = 0;
	printf("Enter Total Number of Processes: ");
	scanf("%d",&n);
	remain = n;
	for(cnt =0;cnt<n;cnt++){
		printf("Enter Details of Process %d\nArrival Time: ",cnt+1);
		scanf("%d",&at[cnt]);
		printf("Burst Time: ");
		scanf("%d",&bt[cnt]);
		rt[cnt]= bt[cnt];
	}
	printf("Enter Time Slot: ");
	scanf("%d",&tq);
	printf("Process ID\tBurst Time\tTurnaround Time\tWaiting Time\n");
	for(t = 0,cnt = 0;remain!=0;){
		if(rt[cnt]<=tq &&rt[cnt]>0)
			t+=rt[cnt];
			rt[cnt]= 0;
			flag =1;
		}else if (rt[cnt]>0){
			rt[cnt]-=tq
			t+=tq;
		}
		if(rt[cnt]==0 &&flag == 1){
			remain--;
			printf("P%d\t\t%d\t\t%d\t\t\t%d\n",cnt+1,bt[cnt],t-at[cnt],t-at[cnt]-bt[cnt]);
			wt+=t-at[cnt]-bt[cnt];
			tat += t-at[cnt];
			flag = 0;
		}
		if(cnt==n-1)
			cnt = 0;
		else if (at[cnt+1]<= t)
			cnt++;
		else
			cnt = 0;
	}
	tat = (float)tat*1.0/n;
	printf("Average Waiting Time: %f\n",wt*1.0/n);
	printf("Average Turnaround Time: %f\n",tat);
}