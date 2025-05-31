/* Bai 3.6 Tính ước chung lớn nhất của hai số cho trước
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <iostream>
using namespace std;

int gcd(int a_50, int b_50){
    if (b_50 == 0) return a_50;
    return gcd(b_50, a_50 % b_50);
}

int gcd2(int a_50, int b_50){
    
    //# khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (a_50 != 0){
        if (a_50 > b_50){
            a_50 %= b_50;
        }
        else{
            int tmp_50 = b_50 % a_50;
            b_50 = a_50;
            a_50 = tmp_50;
        }
    }
    return b_50;
}

int main() {
    cout << "Ho Minh Dung - 5050\n";
    int a_50, b_50;
    cin >> a_50 >> b_50;
    cout << gcd(a_50, b_50) << endl << gcd2(a_50, b_50);
    return 0;
}
