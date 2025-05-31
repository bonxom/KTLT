/* Bai 2.2 Viết hàm hoán vị vòng tròn 3 biến a, b, c.
Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <stdio.h>

void rotate(int &x_50, int &y_50, int &z_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    int tmp_50 = x_50;
    x_50 = y_50;
    y_50 = z_50;
    z_50 = tmp_50;
}

int main() {
	printf("Ho Minh Dung - 5050\n");
    int x_50, y_50, z_50;
    
    //# Nhập 3 số nguyên
    scanf("%d %d %d", &x_50, &y_50, &z_50);
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    printf("Before: %d, %d, %d\n", x_50, y_50, z_50);
    rotate(x_50, y_50, z_50);
    printf("After: %d, %d, %d\n", x_50, y_50, z_50);
    
    return 0;
}
