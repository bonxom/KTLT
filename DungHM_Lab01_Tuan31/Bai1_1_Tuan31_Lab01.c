/* Bài 1.1 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
# include <stdio.h>
int main(){
    printf("Ho Minh Dung - 5050\n");
    int x_dunghm, y_dunghm, z_dunghm;
    int* ptr;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x_dunghm, &y_dunghm, &z_dunghm);
    printf("\nThe three integers are:\n");
    ptr = &x_dunghm;
    printf("x = %d\n", *ptr);
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    ptr = &y_dunghm;
    printf("y = %d\n", *ptr);
    ptr = &z_dunghm;
    printf("z = %d\n", *ptr);
    
    return 0;
}