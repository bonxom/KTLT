/* Bai 2.11 Cho 2 đa thức A(x) và B(x) tương ứng có bậc N và M. 
Hãy tính đa thức tích C(x) = A(x) * B(x) có bậc N+M.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    //input
    cout << "Ho Minh Dung - 5050\ninput = (file)\n";
    ifstream inFile("input.txt"); // Mở file input.txt để đọc
    int n_50; inFile >> n_50;
    int a_50[n_50 + 1];
    for (int &x_50 : a_50){
        inFile >> x_50;
    }
    int m_50; inFile >> m_50;
    int b_50[m_50 + 1];
    for (int &x_50 : b_50){
        inFile >> x_50;
    }

    //ma trận C[m + n + 1] để lưu tích 2 đa thức
    int c_50[n_50 + m_50 + 1] = {0};
    for (int i_50 = 0; i_50 < m_50 + n_50 + 1; i_50++){
        for (int k_50 = 0; k_50 <= i_50 && k_50 <= n_50; k_50++){
            if (i_50 - k_50 > m_50) continue;
            c_50[i_50] += a_50[k_50] * b_50[i_50 - k_50];
        }
    }

    int res_50 = c_50[0];
    for (int i_50 = 1; i_50 < n_50 + m_50 + 1; i_50++){
        res_50 ^= c_50[i_50];
    }
    cout << "output = " << res_50 << endl;
}