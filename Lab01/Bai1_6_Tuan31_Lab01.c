/* Bài 1.6 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>

void reversearray(int arr[], int size){
    int l_dunghm = 0, r_dunghm = size - 1, tmp_dunghm;
    /*****************

    # YOUR CODE HERE #

    *****************/
    for (l_dunghm = 0; l_dunghm <= r_dunghm; l_dunghm++){
        tmp_dunghm = arr[l_dunghm];
        arr[l_dunghm] = arr[r_dunghm];
        arr[r_dunghm] = tmp_dunghm;
        r_dunghm--;
    }
}



void ptr_reversearray(int *arr, int size){
    int l_dunghm = 0, r_dunghm = size - 1, tmp_dunghm;
    /*****************

    # YOUR CODE HERE #

    *****************/
    for (l_dunghm = 0; l_dunghm <= r_dunghm; l_dunghm++){
        int *ptr = arr + l_dunghm;
        tmp_dunghm = *ptr;
        *ptr = *(arr + r_dunghm);
        ptr = arr + r_dunghm;
        *ptr = tmp_dunghm;
        r_dunghm--;
    }
}

int main(){
    int arr_dunghm[] = {9, 3, 5, 6, 2, 5};
    reversearray(arr_dunghm, 6);
    int i = 0;
    for(i = 0; i < 6; i++){
        printf("%d ", arr_dunghm[i]);
    }
    int arr2_dunghm[] = {4, -1, 5, 9};
    ptr_reversearray(arr2_dunghm, 4);
    for(i = 0; i < 4; i++){
        printf("%d ", arr2_dunghm[i]);
    }
    /* Bài 1.6 - Tuần 31 
    Hồ Minh Dũng - 5050 - 750829 - 20242 */
}