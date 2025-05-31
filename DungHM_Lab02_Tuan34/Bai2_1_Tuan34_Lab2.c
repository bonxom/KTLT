/* Bai 2.1 Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x_50, float y_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    return sqrt(x_50*x_50 + y_50*y_50);
}

int main(){
    printf("Ho Minh Dung - 5050\n");
    float x_50, y_50;
    scanf("%f%f", &x_50, &y_50);
    
    float z_50 = get_hypotenuse(x_50, y_50);
    printf("z = %.2f\n", z_50);
    
    return 0;
}
