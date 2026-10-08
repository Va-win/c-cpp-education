#include <stdio.h>
int main()
{
    int h;
    int m;// объявить переменные
    scanf("%d%d", &h, &m);// прочитать входные данные
    int tm = h*60 + m;
    int s = h*3600 + m*60;// вычислить
    printf("%d\n%d\n", tm, s);// напечатать результат
    return 0;
}