#include <stdio.h>

int main(){
    int n;
    int arr[8];
    int sm = 0;

    if (scanf("%d", &n) != 1 || (n < 1 || n > 8)){
        printf("input error\n");
        return 1;
    }
    else{
        for (int i = 0; i < n; i++){
            if (scanf("%d", &arr[i]) != 1){
                printf("input error\n");
                return 1;
            }
        }
    }

    int first_mx = arr[0];
    int last_mn = arr[n - 1];
    int first_mx_i = 0;
    int last_mn_i = n - 1;

    for (int i = 0; i < n; i++){
        if (arr[i] > first_mx){
            first_mx = arr[i];
            first_mx_i = i;
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if (arr[i] < last_mn){
            last_mn = arr[i];
            last_mn_i = i;
        }
    }
    for (int i = 0; i < n; i++){
        if (arr[i] > 0){
            sm = sm + arr[i];
        }
    }

    printf("arr: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("fisrt max: ");
    printf("%d %d\n", first_mx_i, first_mx);

    printf("last min: ");
    printf("%d %d\n", last_mn_i, last_mn);

    printf("sum of pozitive: ");
    printf("%d\n", sm);

    int k = 0;
    for (int i = 0; i < n; i++){
        if (!(i < first_mx_i && arr[i] < 0)){
            arr[k] = arr[i];
            k++;
        }
    }
    n = k;

    printf("arr after del: ");
    for (int i = 0; i < k; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    int pos = -1;
    for (int i = 0; i < n; i++){
        if (arr[i] < 0){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        printf("Operation impossible");
    }
    else if (k == 8){
        printf("Not place for insert");
    }
    else{
        for (int i = k; i > pos; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = 0;
        ++k;

        printf("arr after insert: ");
        for (int i = 0; i < k; i++){
            printf("%d ", arr[i]);
        }
    }
    return 0;
}