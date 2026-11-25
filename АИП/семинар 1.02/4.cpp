#include <stdio.h>
int main(){
    int value[4] = {0, 0, 0, 0};
    if (scanf("%d%d%d%d", &value[0], &value[1], &value[2], &value[3]) != 4){
        printf("input error\n");
        return 1;
    }
    else{
        printf("array: %d %d %d %d\n", value[0], value[1], value[2], value[3]);
    }
    int i = 0;
    if (scanf("%d", &i) != 1){
        printf("input error\n");
        return 1;
    }
    else{
        if (i >= 0 && i < 4){
        printf("%d\n", value[i]);
        return 0;
        } 
        else{
        printf("not this index\n");
        return 1;
        }
    }
}