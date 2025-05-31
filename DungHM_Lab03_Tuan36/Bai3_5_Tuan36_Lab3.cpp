/* Bai 3.5 Tính tổ hợp
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <iostream>
using namespace std;

int binom(int n_50, int k_50) {
    if (k_50 > n_50) return 0;
    if (k_50 == 0) return 1;
    return binom(n_50 - 1, k_50) + binom(n_50 - 1, k_50 - 1);
}

//dùng hash_table để lưu lại kết quả
int c_50[100][100];
void table() {
    for (int i_50 = 0; i_50 < 100; i_50++) {
        c_50[i_50][0] = 1;
        c_50[i_50][i_50] = 1;
    }
    for (int i_50 = 1; i_50 < 100; i_50++) {
        for (int j_50 = 1; j_50 < 100; j_50++) {
            c_50[i_50][j_50] = c_50[i_50 - 1][j_50] + c_50[i_50 - 1][j_50 - 1];
        }
    }
}
int binom2(int n_50, int k_50) {
    //# khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    return c_50[n_50][k_50];
}

int main() {
    cout << "Ho Minh Dung - 5050\n";
    table();
    int m_50;
    cin >> m_50;
    for (int n_50 = 1; n_50 <= m_50; ++n_50) {
        for (int k_50 = 0; k_50 <= n_50; ++k_50)
            printf("%d ", binom(n_50, k_50));
        printf("\n");
    }
    for (int n_50 = 1; n_50 <= m_50; ++n_50) {
        for (int k_50 = 0; k_50 <= n_50; ++k_50)
            printf("%d ", binom2(n_50, k_50));
        printf("\n");
    }
    return 0;
}
