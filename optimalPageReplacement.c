#include<stdio.h>
void main(){
    int temp[3],pages[20],noframes,max,faults=0,nopages,frames[3],pos,i,j,k,flag1,flag2,flag3;
    printf("Number of frames:\n");
    scanf("%d",&noframes);
    printf("Enter no of frames:\n");
    scanf("%d",&nopages);
    for(i=0;i<nopages;i++){
        scanf("%d",&pages[i]);
    }
    for(i=0;i<noframes;i++){
        frames[i]=0;
    }
    for(i=0;i<nopages;i++){
        flag1=flag2=0;
        for(j=0;j<noframes;j++){
            if(frames[j]==pages[i]){
                printf("Page Faults:\n");
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0){
            for(j=0;j<noframes;j++){
                if(frames[j]==0){
                    printf("Page Fault:\n");
                    faults++;
                    frames[j]=pages[i];
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0){
            flag3=0;
            for(j=0;j<noframes;j++){
                temp[j]=-1;
                for(k=i+1;k<nopages;k++){
                    if(frames[j]==pages[k]){
                        temp[j]=k;
                        break;
                    }
                }
            }
        }
        for(j=0;j<noframes;j++){
            if(temp[j]==-1){
                pos=j;
                flag3=1;
                break;
            }
        }
        if(flag3==0){
            max=temp[0];
            pos=0;
            for(j=1;j<noframes;j++){
                if(temp[j]>max){
                    max=temp[j];
                    pos=j;
                }
            }
        }
        printf("Page Fault:\n");
        frames[pos]=pages[i];
        faults++;
    for(j=0;j<noframes;j++){
        printf("%d",frames[j]);
    }
    printf("\n");
    }
    printf("Page faults = %d\n",faults);


}