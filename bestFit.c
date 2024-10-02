#include<stdio.h>
void main(){
int i,j,nb,nf;
printf("Enter the number of blocks: ");
scanf("%d",&nb);
printf("Enter the number of files: ");
scanf("%d",&nf);
int b[nb],f[nf],fr[nb];
printf("Enter the size of the blocks:\n");
for(i=0;i<nb;i++){
    printf("Block %d: ",i+1);
    scanf("%d",&b[i]);
    fr[i]=0;
}
printf("Enter the size of the files:\n");
for(i=0;i<nf;i++){
    printf("File %d: ",i+1);
    scanf("%d",&f[i]);
}

printf("File No\tSize\tBlock No\tBlock Size\tFragment\n");
for(i=0;i<nf;i++){
    int mn=2432546,ind=-1;
    for(j=0;j<nb;j++){
        if(b[j]>=f[i]){
            if(b[j]-f[i]<mn){
                mn=b[j]-f[i];
                ind =j;
            }
        }
    }
    fr[ind]++;
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,f[i],ind+1,b[ind],b[ind]-f[i]);
    b[ind]-=f[i];

}

}