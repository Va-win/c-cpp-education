#include <stdio.h>
int main(){
    int mark = 0;
    if (scanf("%d", &mark) != 1){
        printf("input error\n");
    }
    else{
        switch (mark){
        case 5:
            printf("excellent\n");
            break;
        case 4:
            printf("good\n");
            break;
        case 3:
            printf("satisfactorily\n");
            break;
        case 2:
            printf("unsatisfactorily\n");
            break;
        default:
            printf("no this point\n");
            break;
        }
    }
    
}