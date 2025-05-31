/* Bai 2.5 Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a_50, Complex b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res_50;
    res_50.real = a_50.real + b_50.real;
    res_50.imag = a_50.imag + b_50.imag;
    return res_50;
}

Complex operator - (Complex a_50, Complex b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res_50;
    res_50.real = a_50.real - b_50.real;
    res_50.imag = a_50.imag - b_50.imag;
    return res_50;
}

Complex operator * (Complex a_50, Complex b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res_50;
    res_50.real = a_50.real * b_50.real - a_50.imag * b_50.imag;
    res_50.imag = a_50.imag * b_50.real + b_50.imag * a_50.real;
    return res_50;
}

Complex operator / (Complex a_50, Complex b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res_50;
    res_50.real = (a_50.real * b_50.real + a_50.imag * b_50.imag) / (b_50.real*b_50.real + b_50.imag*b_50.imag);
    res_50.imag = (a_50.imag * b_50.real - b_50.imag * a_50.real) / (b_50.real*b_50.real + b_50.imag*b_50.imag);
    return res_50;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
	printf ("Ho Minh Dung - 5050\n");
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}
/* Bai 2.5 Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
