#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_SIZE 20

int Max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int N, M;
    int table[MAX_SIZE][MAX_SIZE];
    int temp[MAX_SIZE][MAX_SIZE];

    // Ввод размеров таблицы
    scanf("%d %d", &N, &M);
    
    char way[MAX_SIZE*MAX_SIZE] = "";

    // Ввод значений таблицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &table[i][j]);
            temp[i][j] = table[i][j];
        }
    }
    
    // Идем по таблице снизу вверх, справа налево и обновляем значения
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            if (i == N-1 && j == M-1) continue; // Пропускаем правый нижний угол
            int right = (j == M-1) ? 0 : table[i][j+1]; // Значение в соседней клетке справа
            int down = (i == N-1) ? 0 : table[i+1][j]; // Значение в соседней клетке снизу
            table[i][j] += Max(right, down); // Обновляем значение в текущей клетке
        }
    }

    int i = 0, j = 0;
    int count = 0;
    while (count < (N + M - 2)) {
        if ((table[i + 1][j] + temp[i][j]) == table[i][j]) {
            way[count]='D';
            i++;
        } else {
            way[count]='R';
            j++;
        }
        count++;
    }

    // Выводим минимальный вес еды, отдав которую можно попасть в правый нижний угол
    printf("%d\n", table[0][0]);
    printf("%s\n", way);
    return 0;
}
