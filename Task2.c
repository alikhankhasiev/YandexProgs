#include "stdio.h"
#include "stdlib.h"

#define MAX_SIZE 1000

int Min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int N, M;
    int table[MAX_SIZE][MAX_SIZE];
    
    // Ввод размеров таблицы
    scanf("%d %d", &N, &M);
    
    // Ввод значений таблицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    // Идем по таблице снизу вверх, справа налево и обновляем значения
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            if (i == N-1 && j == M-1) continue; // Пропускаем правый нижний угол
            int right = (j == M-1) ? MAX_SIZE : table[i][j+1]; // Значение в соседней клетке справа
            int down = (i == N-1) ? MAX_SIZE : table[i+1][j]; // Значение в соседней клетке снизу
            table[i][j] += Min(right, down); // Обновляем значение в текущей клетке
        }
    }

    // Выводим минимальный вес еды, отдав которую можно попасть в правый нижний угол
    printf("%d\n", table[0][0]); 

    return 0;
}
