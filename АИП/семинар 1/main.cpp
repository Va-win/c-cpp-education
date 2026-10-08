#include <stdio.h>
int main(){
    int c = 0;
    int d = 0;
    if (scanf("%d %d", &c, &d) != 2){
        printf("error\n");
        return 1;
    }
    if (c >= d){
        printf("max: %d\n", c);
    }
    else{
        printf("max: %d\n", d);
    }
    return 0;
}