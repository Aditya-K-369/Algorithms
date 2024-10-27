#include <stdio.h>

void main()
{
    int ms, nop, remaing, ps, pro, s[100],pa, fno[100][100], x, y, offset;
    printf("Enter the memory size:");
    scanf("%d", &ms);
    printf("Enter the page size : ");
    scanf("%d", &ps);
    nop = ms / ps;
    remaing = nop;
    printf("The number of pages available in memory: %d\n", nop);
    printf("Enter number of processes:");
    scanf("%d", &pro);
    for (int i = 1; i <= pro; i++)
    {
        printf("Enter number of pages required for p[%d]", i);
        scanf("%d", &s[i]);
        if (s[i] > remaing)
        {
            printf("Memory is full\n");
            break;
        }
        remaing -= s[i];
        printf("Enter page table for p[%d]", i);
        for (int j = 0; j < s[i]; j++)
        {
            scanf("%d", &fno[i][j]);
        }
    }
    printf("Enter Logical Address to find Address\n");
    printf("Enter process no. and page number and offset:");
    scanf("%d%d%d", &x, &y, &offset);
    if(x<1||x>pro||y<0||y>=s[x]||offset<0||offset>=ps){
        printf("Envalid process or page number or offset");

    }else{
        pa = fno[x][y]*ps+offset;
        printf("The physical address is : %d",pa);
    }
}