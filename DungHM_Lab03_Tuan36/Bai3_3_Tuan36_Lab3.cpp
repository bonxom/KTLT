/* Bai 3.3 Một người xuất phát tại thành phố 1, 
muốn đi thăm tất cả các thành phố khác, mỗi thành phố đúng 1 lần và quay về 1. 
Chi phí để đi từ thành phố i sang thành phố j là ci,j. 
Hãy tìm tổng chi phí nhỏ nhất có thể
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n_50, c_50[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin_50 = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best_50 = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr_50; //# tổng chi phí tới thời điểm hiện tại
int mark_50[MAX]; //# đánh dấu những thành phố đã đi
int x_50[MAX]; //# lưu giữ các thành phố đã đi

//# Đọc dữ liệu vào
void input_50(){
    cin >> n_50;
    for (int i = 1; i <= n_50; ++i)
        for (int j = 1; j <= n_50; ++j){
            cin >> c_50[i][j];
            if (c_50[i][j] > 0) cmin_50 = min(cmin_50, c_50[i][j]);
        }
}

//# Thuật toán quay lui
void TRY_50(int k){
    for(int i = 2; i <= n_50; i++){
        /*****************
        # YOUR CODE HERE #
        *****************/
        if (!mark_50[i]){
            x_50[k] = i;
            mark_50[i] = 1;
            curr_50 += c_50[x_50[k - 1]][i];
            if (k == n_50){
                best_50 = min(curr_50 + c_50[x_50[k]][1], best_50);
            }
            else{//sử dụng nhánh cận để ngắt sớm
                int gmin_50 = curr_50 + (n_50 - k + 1)*cmin_50;
                if (gmin_50 < best_50) TRY_50(k + 1);
            }
            mark_50[i] = 0;
            curr_50 -= c_50[x_50[k - 1]][i];
        }
    }
}

int main() {
    cout << "Ho Minh Dung - 5050\n";
    input_50();
    x_50[1] = 1;
    TRY_50(2);
    cout << best_50;
    return 0;
}
