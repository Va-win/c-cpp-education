#include <stdio.h>
int main(){
    int n = 5;
    {
        int n = 8;
        printf("In: %d\n", n);
    }
    printf("Out: %d\n", n);
    const int seats = 30;
    printf("Seats: %d\n", seats);
    return 0;
}