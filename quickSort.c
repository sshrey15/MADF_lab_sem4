 #include <stdio.h>

int ar[9];

void interchange(int ar[], int i, int j)
{
    ar[i] = ar[i] + ar[j];
    ar[j] = ar[i] - ar[j];
    ar[i] = ar[i] - ar[j];
}

int partition(int ar[], int m, int p)
{
    int v, i, j;
    v = ar[m];
    i = m;
    j = p;

    do
    {
        do
        {
            i = i + 1;
        } while (ar[i] < v);

        do
        {
            j = j - 1;
        } while (ar[j] > v);

        if (i < j)
        {
            interchange(ar, i, j);
        }
    } while (i < j);

    ar[m] = ar[j];
    ar[j] = v;
    return j;
}

void quicksort(int p, int q)
{
    if (p < q)
    {
        int j = partition(ar, p, q + 1);
        quicksort(p, j - 1);
         printf("[");
        for (int i = 0; i < 9; i++)
        {
            printf(" %d ", ar[i]);
        }
        printf("]\n");

        quicksort(j + 1, q);
        printf("[");
        for (int i = 0; i < 9; i++)
        {
            printf(" %d ", ar[i]);
        }
        printf("]\n");
    }
}

int main()
{
    printf("Enter the array elements:\n");
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &ar[i]);
    }

    int start, end;
    printf("Enter start and end positions: ");
    scanf("%d%d", &start, &end);

    printf("Array after each iteration:\n");
    quicksort(start, end);

    return 0;
}