/* Bai 2.4 Viết các hàm tính lập phương của số nguyên và số thực.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <stdio.h>

int cube(int x_50) {
    //# trả về lập phương của x
    /*****************
    # YOUR CODE HERE #
    *****************/
    return x_50 * x_50 * x_50;
}

//# viết hàm tính lập phương của một số kiểu double
/*****************
# YOUR CODE HERE #
*****************/
double cube(double x_50){
    return x_50 * x_50 * x_50;
}

int main() {
    int n_50;
    double f_50;
    printf ("Ho Minh Dung - 5050\n");
    scanf("%d %lf", &n_50, &f_50);
    
    printf("Int: %d\n", cube(n_50));
    printf("Double: %.2lf\n", cube(f_50));
    
    return 0;
}
