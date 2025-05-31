/* Bai 3.9 Lập lịch cho y tá
Một y tá cần lập lịch làm việc trong N ngày, mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi. 
Một lịch làm việc là tốt nếu không có hai ngày nghỉ nào liên tiếp và mọi chuỗi ngày tối đại
làm việc liên tiếp đều có số ngày thuộc đoạn [K1,K2]. Hãy liệt kê tất cả các cách lập lịch tốt, 
với mỗi lịch in ra trên một dòng một xâu nhị phân độ dài n với bit 0/1 tương ứng là nghỉ/làm việc. 
Các xâu phải được in ra theo thứ tự từ điển
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;

int n_50, k1_50, k2_50;
int len1_50;
vector<string> ans_50;
string current_50 = "";

void Try(int k_50){
    for (int i_50 = 0; i_50 <= 1; i_50++){
        //tmp và s lưu lại trạng thái (backtrack đỡ phức tạp)
        int tmp_50 = len1_50;
        string s_50 = current_50;

        if (i_50 == 0){
            //chưa làm việc đủ thì ko dc nghỉ
            if (len1_50 < k1_50 && k_50 != 0) continue;
            current_50 += to_string(i_50);
            len1_50 = 0;
        }
        else{
            //còn có thể làm việc
            if (len1_50 < k2_50){
                current_50 += to_string(i_50);
                len1_50++;
            }
        }
        if (k_50 == n_50 - 1){
            //check trường hợp những ngày cuối làm việc không đủ trong khoảng [k1, k2]
            if (current_50[k_50] == '1' && len1_50 >= k1_50 && len1_50 <= k2_50 || current_50[k_50] == '0')
                ans_50.push_back(current_50);
        } 
        else Try(k_50 + 1);
        len1_50 = tmp_50;
        current_50 = s_50;
    }
}

int main(){
    cout << "Ho Minh Dung - 5050\ninput = ";
    cin >> n_50 >> k1_50 >> k2_50;
    Try(0);
    //sắp xếp
    sort(ans_50.begin(), ans_50.end());
    cout << "output = \n";
    for (string x_50 : ans_50) cout << x_50 << endl;
}