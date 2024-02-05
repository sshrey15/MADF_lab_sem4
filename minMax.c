#include <stdio.h>
int ar[100];

void minmax(int i, int j, int *mx, int *mn)
{
    if (i == j)
    {
        *mx = ar[i];
        *mn = ar[i];
        printf(" [low = %d    High = %d ]     Min = %d       Max = %d \n", i, j, *mn, *mx);
    }
    else if (i == j - 1)
    {
        if (ar[i] < ar[j])
        {
            *mn = ar[i];
            *mx = ar[j];
        }
        else
        {
            *mn = ar[j];
            *mx = ar[i];
        }
        printf(" [low = %d    High = %d ]     Min = %d      Max = %d \n", i, j, *mn, *mx);
    }
    else
    {
        int mx1, mn1;
        int mid = (i + j) / 2;
        minmax(i, mid, mx, mn);
        minmax(mid + 1, j, &mx1, &mn1);
        if (*mx < mx1)
        {
            *mx = mx1;
        }
        if (*mn > mn1)
        {
            *mn = mn1;
        }
        printf(" [low = %d     High = %d ]     Min = %d     Max = %d \n", i, j, *mn, *mx);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int max, min, i;
    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    minmax(0, n-1, &max, &min);

    printf("Min = %d   Max = %d", min, max);
    return 0;
}