#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

int main () {
    int N, M;
    int table[MAX_SIZE][MAX_SIZE];

    // Ввод размеров таблицы
    scanf("%d %d", &N, &M);

    memset(table,0,sizeof(table));
    table[0][0] = 1;
    table[1][2] = 1;
    table[2][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            table[i][j] = table[i - 2][j - 1] + table[i - 1][j - 2];
        }
    }

    printf("%d", table[N - 1][M - 1]);
}

