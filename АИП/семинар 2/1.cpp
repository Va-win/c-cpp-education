#include <stdio.h>
int main(){
    int a = 0;
    int b = 0;
    if (scanf("%d%d", &a, &b) != 2){
        printf("error\n");
        return 1;
    }
    if (b == 0){
        printf("division by zero");
        return 1;
    }
    else{
        int div = a / b;
        double divv = double(a)/b;
        int narrow = divv;
        printf("int: %d\n", div);
        printf("float: %.3f\n", double(a)/b);
        printf("narrow: %d\n", narrow);
        return 0;
    }
}