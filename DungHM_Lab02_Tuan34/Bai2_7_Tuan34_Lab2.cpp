/* Bai 2.7 Viết hàm tính tổng các phần tử trong hai mảng.
Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <iostream>
using namespace std;

//# Viết hàm arr_sum
/*****************
# YOUR CODE HERE #
*****************/
template <typename T> T arr_sum(T a_50[], int n_50, T b_50[], int m_50){
	T res_50 = 0;
	for (int i_50 = 0; i_50 < n_50; i_50++){
		res_50 += a_50[i_50];
	}
	for (int j_50 = 0; j_50 < m_50; j_50++){
		res_50 += b_50[j_50];
	}
	return res_50;
}

int main() {
	printf ("Ho Minh Dung - 5050\n");
    int val_50;
    cin >> val_50;
    
    {
        int a_50[] = {3, 2, 0, val_50};
        int b_50[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a_50, 4, b_50, 5) << endl;
    }
    {
        double a_50[] = {3.0, 2, 0, val_50 * 1.0};
        double b_50[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a_50, 4, b_50, 5) << endl;
    }

    return 0;
}
