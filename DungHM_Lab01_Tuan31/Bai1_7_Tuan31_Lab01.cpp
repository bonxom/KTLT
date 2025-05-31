/* Bài 1.7 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>

int *a_dunghm;
int n_dunghm, tmp_dunghm;

int main(){
    printf("Ho Minh Dung - 20235050\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n_dunghm);
    
    //#Allocate memory
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    int *a_dunghm = new int[n_dunghm];
    
    
    for(int i = 0; i < n_dunghm; i++)
        scanf("%d", a_dunghm + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n_dunghm; i++)
        printf("%d ", *(a_dunghm + i));
    printf("\n");
    
    //#Sort array
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = 0; i < n_dunghm - 1; i++){
        for (int j = i + 1; j < n_dunghm; j++){
            if (*(a_dunghm + j) < *(a_dunghm + i)){
                tmp_dunghm = *(a_dunghm + i);
                *(a_dunghm + i) = *(a_dunghm + j);
                *(a_dunghm + j) = tmp_dunghm;
            }
        }
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n_dunghm; i++)
        printf("%d ", *(a_dunghm + i));
    printf("\n");
    
    delete [] a_dunghm;
    return 0;
}

/* Bài 1.7 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */