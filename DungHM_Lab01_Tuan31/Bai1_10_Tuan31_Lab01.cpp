/* Bài 1.10 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Ho Minh Dung - 5050" << endl;
    cout << "input\n";
    int n_dunghm; cin >> n_dunghm;

    //Cấp phát động cho các ma trận
    int **a_dunghm = new int*[n_dunghm];
    int **b_dunghm = new int*[n_dunghm];
    int **tong_dunghm = new int*[n_dunghm];
    int **tich_dunghm = new int*[n_dunghm];
    for (int i_dunghm = 0; i_dunghm < n_dunghm; i_dunghm++){
        a_dunghm[i_dunghm] = new int[n_dunghm];
        b_dunghm[i_dunghm] = new int[n_dunghm];
        tong_dunghm[i_dunghm] = new int[n_dunghm];
        tich_dunghm[i_dunghm] = new int[n_dunghm];
    }
    //Nhập các ma trận
    for (int i_dunghm = 0; i_dunghm < n_dunghm; i_dunghm++){
        for (int j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            cin >> a_dunghm[i_dunghm][j_dunghm];
        }
    }
    for (int i_dunghm = 0; i_dunghm < n_dunghm; i_dunghm++){
        for (int j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            cin >> b_dunghm[i_dunghm][j_dunghm];
            // Tính tổng 
            tong_dunghm[i_dunghm][j_dunghm] = a_dunghm[i_dunghm][j_dunghm] + b_dunghm[i_dunghm][j_dunghm];

        }
    }
    //Tính tích
    for (int i_dunghm = 0; i_dunghm < n_dunghm; i_dunghm++){
        for (int j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            tich_dunghm[i_dunghm][j_dunghm] = 0;
            for (int x_dunghm = 0; x_dunghm < n_dunghm; x_dunghm++){
                tich_dunghm[i_dunghm][j_dunghm] += a_dunghm[i_dunghm][x_dunghm] * b_dunghm[x_dunghm][j_dunghm];
            }
        }
    }

    //Kết quả
    cout << endl << "output:" << endl;;
    for (int i_dunghm = 0; i_dunghm < n_dunghm; i_dunghm++){
        for (int j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            cout << tong_dunghm[i_dunghm][j_dunghm] << " ";
        }
        cout << endl;
    }
    for (int i_dunghm = 0; i_dunghm < n_dunghm; i_dunghm++){
        for (int j_dunghm = 0; j_dunghm < n_dunghm; j_dunghm++){
            cout << tich_dunghm[i_dunghm][j_dunghm] << " ";
        }
        cout << endl;
    }
}
/* Bài 1.10 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */