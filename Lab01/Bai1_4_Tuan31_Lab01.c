/* Bài 1.4 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>

int counteven(int* arr, int size){
    int count_dunghm = 0;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    int i_dunghm = 0;
    for (i_dunghm = 0; i_dunghm < size; i_dunghm++){
        if (arr[i_dunghm] % 2 == 0) count_dunghm++;
    }
    return count_dunghm;    
} 

int main(){
    int size_dunghm;
    printf("Input size of array:");
    scanf("%d", &size_dunghm);
    int arr_dunghm[100];
    int i = 0;
    printf("\nInput array element: ");
    for (i = 0; i < size_dunghm; i++){
        scanf("%d", &arr_dunghm[i]);
    }
    printf("Even value count: %d", counteven(arr_dunghm, size_dunghm));
}