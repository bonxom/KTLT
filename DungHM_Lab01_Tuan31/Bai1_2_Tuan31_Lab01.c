/* Bài 1.2 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>
int main(){
    printf("Ho Minh Dung - 5050\n");
    int a_dunghm[7]= {13, -355, 235, 47, 67, 943, 1222}; 
    printf("address of first five elements in memory.\n");
    int i_dunghm = 0;
    for (i_dunghm=0; i_dunghm<5;i_dunghm++)  printf("\ta[%d] ",i_dunghm);
    printf("\n");
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (i_dunghm = 0; i_dunghm < 5; i_dunghm++){
        printf("address of a[%d]: %p\n", i_dunghm, &a_dunghm[i_dunghm]);
    }
    return 0;
}