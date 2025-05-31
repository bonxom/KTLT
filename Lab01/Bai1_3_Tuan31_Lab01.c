/* Bài 1.3 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <stdio.h>
int main()
{
    int x_dunghm, y_dunghm, z_dunghm;
    int *ptr_dunghm;
    scanf("%d %d %d", &x_dunghm, &y_dunghm, &z_dunghm);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x_dunghm, y_dunghm, z_dunghm);

    /*****************
    # YOUR CODE HERE #
    *****************/
    ptr_dunghm = &x_dunghm;
    *ptr_dunghm += 100;
    ptr_dunghm = &y_dunghm;
    *ptr_dunghm += 100;
    ptr_dunghm = &z_dunghm;
    *ptr_dunghm += 100;
    
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x_dunghm, y_dunghm, z_dunghm);
    return 0;
}  