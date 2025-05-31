/* Bai 2.3 Viết chương trình yêu cầu nhập giá trị cho số nguyên x nhỏ hơn 100. 
In ra giá trị ax2+bx+c  với a, b, c định sẵn.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <stdio.h>

//# Viết hàm get_value
/*****************
# YOUR CODE HERE #
*****************/
int get_value(int x_50, int a_50 = 2, int b_50 = 1, int c_50 = 0){
	return a_50*x_50*x_50 + b_50*x_50 + c_50;
}

int main(){
	printf("Ho Minh Dung - 5050\n");
    int x_50;
    scanf("%d", &x_50);
    
    int a_50 = 2; //# Giá trị mặc đinh của a
    int b_50 = 1; //# Giá trị mặc đinh của b
    int c_50 = 0; //# Giá trị mặc đinh của c
    
    //# Nhập 3 số nguyên a, b, c từ bàn phím
    scanf("%d %d %d", &a_50, &b_50, &c_50);
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    printf("a=2, b=1, c=0: %d\n", get_value(x_50));
    printf("a=%d, b=1, c=0: %d\n", a_50, get_value(x_50, a_50));
    printf("a=%d, b=%d, c=0: %d\n", a_50, b_50, get_value(x_50, a_50, b_50));
    printf("a=%d, b=%d, c=%d: %d\n", a_50, b_50, c_50, get_value(x_50, a_50, b_50, c_50));
    
    return 0;
}
