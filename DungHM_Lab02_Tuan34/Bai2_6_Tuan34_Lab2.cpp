/* Bai 2.6 Giả thuyết Collatz: bắt đầu từ số dương n bất kỳ, nếu n chẵn thì chia 2, 
nếu lẻ thì nhân 3 cộng 1, giả thuyết cho rằng ta luôn đi đến n = 1.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <stdio.h>

void print(int n_50) {
    printf("n=%d\n", n_50);
}

int mul3plus1(int n_50) {
    return n_50 * 3 + 1;
}

int div2(int n_50) {
    return n_50 / 2;
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n_50, int(*odd_50)(int), int(*even_50)(int), void(*output_50)(int) )  {
    (*output_50)(n_50);
    if (n_50 == 1) return;
    if (n_50 % 2 == 0) {
        n_50 = (*even_50)(n_50);
    } else {
        n_50 = (*odd_50)(n_50);
    }
    simulate(n_50, odd_50, even_50, output_50);
}

int main() {
	printf ("Ho Minh Dung - 5050\n");
    int (*odd_50)(int) = NULL;
    int (*even_50)(int) = NULL;

    /*****************
    # YOUR CODE HERE #
    *****************/
    odd_50 = mul3plus1;
    even_50 = div2;

    int n_50;
    scanf("%d", &n_50);
    simulate(n_50, odd_50, even_50, print);

    return 0;
}
