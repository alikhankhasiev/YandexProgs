#include <stdio.h>

void main () {
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    int min = a[0];
    if (a[0] > a[1]) { min = a[1]; a[1] = a[0]; a[0] = min;}
    if (a[1] > a[2]) { min = a[2]; a[2] = a[1]; a[1] = min;}
    if (a[0] > a[1]) { min = a[1]; a[1] = a[0]; a[0] = min;} 
    printf("%d",a[1]);
}