/* Bai 4.3 Tính tích có hướng của 2 vector
Một vector trong không gian 3 chiều được biểu diễn bằng 
tuple<double, double, double>. 
Hãy viết hàm Vector cross_product(Vector a, Vector b) 
tính tích có hướng của 2 vector. 
Trong đó Vector là kiểu dữ liệu được định nghĩa sẵn trong trình chấm 
như sau: using Vector = tuple<double, double, double>;
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a_50, Vector b_50) {
    double a1_50 = get<0>(a_50), b1_50 = get<1>(a_50), c1_50 = get<2>(a_50);
    double a2_50 = get<0>(b_50), b2_50 = get<1>(b_50), c2_50 = get<2>(b_50);
    double x_50 = b1_50 * c2_50 - c1_50 * b2_50;
    double y_50 = c1_50 * a2_50 - a1_50 * c2_50;
    double z_50 = a1_50 * b2_50 - b1_50 * a2_50;
    return Vector(x_50, y_50, z_50);
}

int main() {
    cout << "Ho Minh Dung - 5050\n";
    cout << setprecision(2) << fixed;
    Vector a_50 {1.2, 4, -0.5};
    Vector b_50 {1.5, -2, 2.5};
    Vector c_50 = cross_product(a_50, b_50);
    cout << get<0>(c_50) << ' ' << get<1>(c_50) << ' ' << get<2>(c_50) << endl;
    return 0;
}