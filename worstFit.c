#include <stdio.h>

void main() {
    int frag[100], b[100], f[100], i, j, nb, nf, temp;
    static int bf[100], ff[100];
    
    printf("Enter the number of blocks:");
    scanf("%d", &nb);
    
    printf("Enter the number of files:");
    scanf("%d", &nf);
    
    printf("Enter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    
    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    
    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) {
                    ff[i] = j;
                    frag[i] = temp;
                    bf[j] = 1;
                    break;
                }
            }
        }
    }

    printf("File_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 1; i <= nf; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    
}
