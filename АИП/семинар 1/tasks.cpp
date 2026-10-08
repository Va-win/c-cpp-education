#include <stdio.h>
int main(){
    // Ввод и вывод
    int n = 67;
    double x = 3.5;
    char s = 'H';
    printf("%d\n", n);
    printf("%.2f\n", x);
    printf("%c\n", s);
    // Максимум, сумма и вывод частного
    int c = 0;
    int d = 0;
    if (scanf("%d %d", &c, &d) != 2){
        printf("error\n");
        return 1;
    }
    else{
        printf("sum: %d\n", c + d);
    }
    if (c >= d){
        printf("max: %d\n", c);
    }
    else{
        printf("max: %d\n", d);
    }
    if (d == 0){
        printf("деление на ноль %d\n");
        return 1;
    }
    else{
        printf("del: %.2f", double(c)/d);
    }
    return 0;
}
