#include <stdio.h>
#include <string.h>

#define MAX_DAYS 101

int Min(int a, int b) {
    return (a < b) ? a : b;
}

int main () {   
    int N = 0;
    // Ввод размеров таблицы
    scanf("%d", &N);
    int cost[N];

    const int INF = 1e9;
    memset(cost,0,sizeof(cost));

    for (int i = 0; i < N; i++) {
        scanf("%d", &cost[i]);
    }

    int dp[MAX_DAYS][MAX_DAYS];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = INF;
        }
    }

    int coupon = 0;
    int j = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        if (cost[i - 1] > 100) {
            coupon++;
        }
        for (int j = 0; j <= i; j++) {
            dp[i][j] = Min(dp[i][j], dp[i-1][j] + cost[i - 1]);
            if (cost[i - 1] > 100) {
                dp[i][j+1] = Min(dp[i][j+1], dp[i-1][j] + cost[i - 1]);
            }
            if (j >= 1) {
                dp[i][j - 1] = Min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int ans = dp[N][0];
    int i = 0;
    for (int j = 0; j <= N; j++) {
        int temp = ans;
        ans = Min(ans, dp[N][j]);
        if (ans != temp) i = j;
    }
    printf("%d\n", ans);
    printf("%d %d", i, coupon - i);

    int dayCoupon[N];
    int k = coupon - i;
    while (k != i) {
        for (int x = N; x > 1; x--) {
            if (dp[x][i] == dp[x - 1][i + 1]) {
                dayCoupon[coupon - i - k] = x;
                k--;    
                if (k == i) {
                    break;
                }
                i++;
            }
        }
    }
    printf("\n");
    for (int k = 0; k < coupon - i; k++) {
        printf("%d ", dayCoupon[k]);
    }
}