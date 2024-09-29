#include<stdio.h>
#include<stdlib.h>

#define max 3
int count = 0;
int buffer[max];

void produce(){
    if(count<max){
        int i=count;
        buffer[i] = count+1;
        printf("Producer produces item %d\n",buffer[count]);
        count++;
    }else{
        printf("Buffer is full\n");
    }
}

void consumer(){
    if(count>0){
        printf("Consumer consumes item %d\n",buffer[count-1]);
        count--;
    }else{
        printf("Buffer is empty\n");
    }
}

void main(){
    int n;
    printf("1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit\n");

    while (n!=3){
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1 :produce();
            break;
        case 2 :consumer();
        break;
        case 3 :
        break;
        default:
        printf("Enter a valid choice between 1 2 3");
            break;
        }
        
        
    }

}