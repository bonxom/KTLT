/* Bài 1.5 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>
double* maximum(double* a, int size){
    double *max_dunghm;
    max_dunghm = a;
    if (a==NULL) return NULL;

    /*****************

    # YOUR CODE HERE #

    *****************/
    int i_dunghm = 0;
    for (i_dunghm = 0; i_dunghm < size; i_dunghm++){
        if (*max_dunghm < a[i_dunghm]){
            max_dunghm = &a[i_dunghm];
        }
    }
    return max_dunghm;

}

int main(){
    int size_dunghm;
    printf("input size of array: ");
    scanf("%d", &size_dunghm);
    double arr_dunghm[100];
    printf("input array elements: \n");
    int i = 0;
    for (i = 0; i < size_dunghm; i++){
        scanf("%lf", &arr_dunghm[i]);
    }
    printf ("Max element address: %p", maximum(arr_dunghm, size_dunghm));
}