/* Bai 3.10 Khoảng cách Hamming
Khoảng cách Hamming giữa hai xâu cùng độ dài là số vị trí mà 
ký tự tại vị trí đó là khác nhau trên hai xâu. 
Cho S là xâu gồm n ký tự 0. Hãy liệt kê tất cả các xâu nhị phân độ dài n, 
có khoảng cách Hamming với S bằng H. 
Các xâu phải được liệt kê theo thứ tự từ điển.
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;
int n_50, h_50;
int cnt_50; //đếm số bit 1 hiện có
vector<string> res_50;
string current_50;

void Try(int k_50){
    for (int i_50 = 0; i_50 <= 1; i_50++){
        //tmp để lưu trạng thái ban đầu
        char tmp_50 = current_50[k_50];
        current_50[k_50] = (i_50 == 0) ? '0' : '1';
        if (i_50 == 1) cnt_50++;

        if (k_50 == n_50 - 1) {
            //nếu số bit 1 bằng h thì ghi nhận kết quả
            if (cnt_50 == h_50) res_50.push_back(current_50);
        } else if (cnt_50 <= h_50) {
            Try(k_50 + 1);
        }
        //trả về trạng thái ban đầu
        current_50[k_50] = tmp_50;
        if (i_50 == 1) cnt_50--;
    }
}

int main(){
    cout << "Ho Minh Dung - 5050\noutput = \n";
    ifstream inFile_50("input.txt"); //input từ file
    int t_50; inFile_50 >> t_50;
    while (t_50--){
        inFile_50 >> n_50 >> h_50;
        res_50.clear();
        current_50 = string(n_50, 0);
        Try(0);
        for (string &x_50 : res_50) cout << x_50 << endl;
        cout << endl;
    }
}
