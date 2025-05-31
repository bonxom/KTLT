/* Bai 4.2 Tính diện tích tam giác
Một điểm trong không gian 2 chiều được biểu diễn bằng pair. 
Hãy viết hàm double area(Point a, Point b, Point c) 
tính diện tích tam giác theo tọa độ 3 đỉnh. 
Trong đó, Point là kiểu được định nghĩa sẵn trong trình chấm như sau: 
using Point = pair<double, double>;
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

//hàm tính bình phương
inline double sqr(double x_50){
    return x_50 * x_50;
}
double area(Point a_50, Point b_50, Point c_50) {
    // sử dụng công thức Heron
    double x_50 = sqrt(sqr(a_50.first - b_50.first) + sqr(a_50.second - b_50.second));
    double y_50 = sqrt(sqr(a_50.first - c_50.first) + sqr(a_50.second - c_50.second));
    double z_50 = sqrt(sqr(b_50.first - c_50.first) + sqr(b_50.second - c_50.second));
    double p_50 = (x_50 + y_50 + z_50) / 2;
    return sqrt(p_50*(p_50-x_50)*(p_50-y_50)*(p_50-z_50));
}

int main() {
    cout << "Ho Minh Dung - 5050\n";
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
