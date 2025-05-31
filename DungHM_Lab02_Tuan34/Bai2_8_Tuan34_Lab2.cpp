/* Bai 2.8 Viết hàm so sánh cho thuật toán sắp xếp
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	printf("Ho Minh Dung - 5050\n");
    int val1_50, val2_50;
    cin >> val1_50 >> val2_50;
    vector< vector<int> > a_50 = {
        {1, 3, 7},
        {2, 3, 4, val1_50},
        {9, 8, 15},
        {10, val2_50},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    // sử dụng hàm nặc danh để xây dựng comparator (Hàm so sánh)
    sort(a_50.begin(), a_50.end(), [](vector<int> x_50, vector<int> y_50) -> bool{
    	int t1_50 = 0, t2_50 = 0;
    	for (auto &z_50 : x_50) t1_50 += z_50;
    	for (auto &z_50 : y_50) t2_50 += z_50;
    	return t1_50 > t2_50;
	} );
    /*****************
    # YOUR CODE HERE #
    *****************/

    for (const auto &v_50 : a_50) {
        for (int it_50 : v_50) {
            cout << it_50 << ' ';
        }
        cout << endl;
    }
    return 0;
}
