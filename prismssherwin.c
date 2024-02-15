#include<stdio.h>
#define IN 10000

void display(int arr[], int num) {
    for (int i = 0; i < num; i++)
        printf("%2d", arr[i] + 1);
    printf("\n");
}

void displayn(int arr[], int num) {
    for (int i = 0; i < num; i++) {
        if (arr[i] == IN)
            printf("IN ");
        else
            printf("%2d ", arr[i]);
    }
    printf("\n");
}

int print(int t[][2], int n, int cost[][8]) {
    int low = IN, k, l, mincost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] < low && cost[i][j] != 0) {
                low = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];
    printf("k = %d ;l =%d \n", k + 1, l + 1);
    int near[n];
    for (int i = 0; i < n; i++) {
        if (i == k || i == l)
            near[i] = -1;
        else {
            if (cost[k][i] < cost[l][i])
                near[i] = k;
            else
                near[i] = l;
        }
    }
    printf("Near : ");
    display(near, 8);
    printf("\n");

    for (int i = 1; i < n - 1; i++) {
        int min = IN, r;
        for (int j = 0; j < n; j++) {
            if ((near[j] != -1) && (cost[j][near[j]] < min)) {
                min = cost[j][near[j]];
                r = j;
            }
        }
        t[i][0] = r;
        t[i][1] = near[r];
        mincost = mincost + cost[r][near[r]];
        printf("Near  :");
        display(near, 8);
        printf(" \n");
        for (int j = 0; j < n; j++) {
            if (near[j] == -1 || j == r)
                near[j] = -1;
            else {
                if (cost[j][r] < cost[j][near[j]])
                    near[j] = r;
            }
        }
    }
    return mincost;
}

int main() {
    int cost[8][8], t[7][2];
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) // Convert 0 to IN except for diagonal elements
                cost[i][j] = IN;
        }
    }

    int mincost = print(t, n, cost);
    printf("Minimum cost of spanning tree: %d\n", mincost);
    printf("Edges in the minimum spanning tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0] + 1, t[i][1] + 1);
    }
    return 0;
}
