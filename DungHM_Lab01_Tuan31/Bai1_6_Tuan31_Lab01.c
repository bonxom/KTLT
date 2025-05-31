/* Bài 1.6 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>
void reversearray(int arr_dunghm[], int size_dunghm){
    int l_dunghm = 0, r_dunghm = size_dunghm - 1, tmp_dunghm;
    /*****************

    # YOUR CODE HERE #

    *****************/
    for (l_dunghm = 0; l_dunghm <= r_dunghm; l_dunghm++){
        tmp_dunghm = arr_dunghm[l_dunghm];
        arr_dunghm[l_dunghm] = arr_dunghm[r_dunghm];
        arr_dunghm[r_dunghm] = tmp_dunghm;
        r_dunghm--;
    }
}

void ptr_reversearray(int *arr_dunghm, int size_dunghm){
    int l_dunghm = 0, r_dunghm = size_dunghm - 1, tmp_dunghm;
    /*****************

    # YOUR CODE HERE #

    *****************/
    for (l_dunghm = 0; l_dunghm <= r_dunghm; l_dunghm++){
        int *ptr_dunghm = arr_dunghm + l_dunghm;
        tmp_dunghm = *ptr_dunghm;
        *ptr_dunghm = *(arr_dunghm + r_dunghm);
        ptr_dunghm = arr_dunghm + r_dunghm;
        *ptr_dunghm = tmp_dunghm;
        r_dunghm--;
    }
}

int main(){
    printf("Ho Minh Dung - 5050\n");
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