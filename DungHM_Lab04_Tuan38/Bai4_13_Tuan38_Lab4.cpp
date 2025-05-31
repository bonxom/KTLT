/* Bai 4.13 Đếm xâu con
Cho một xâu nhị phân độ dài  n
. Hãy viết chương trình đếm số lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <bits/stdc++.h>
using namespace std;

string s_50;
map<int, int> mp_50;

inline int C2N(int n){
    return n * (n - 1)/2;
}

int main(){
    ifstream inFile("input.txt");
    cout << "Ho Minh Dung - 5050\n";
    inFile >> s_50;
    int cnt1_50 = 0, cnt0_50 = 0;
    for (int i_50 = 0; i_50 < s_50.length(); i_50++){
        if (s_50[i_50] == '0') cnt0_50++;
        else cnt1_50++;
        //độ chênh lệch 1 và 0 tại vị trí i
        int tmp_50 = cnt1_50 - cnt0_50;
        //mp đếm số vị trí có cùng độ chênh lệch-> giữa 2 điểm bất kỳ thì chênh lệch 0 và 1 là 0
        if (mp_50.find(tmp_50) != mp_50.end()){
            mp_50[tmp_50]++;
        }
        else{
            mp_50[tmp_50] = 1;
        }
    }

    int res_50 = 0;
    for (pair<int, int> x_50 : mp_50){
        //chọn ra 2 vị trí có cùng chênh lệch
        res_50 += C2N(x_50.second);
        if (x_50.first == 0){//các vị trí thỏa mãn độ chênh lệch = 0
            res_50 += x_50.second;
        }
    }
    cout << res_50 << endl;
}