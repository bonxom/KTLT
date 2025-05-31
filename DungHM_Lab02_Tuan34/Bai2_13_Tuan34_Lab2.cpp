/* Bai 2.13 Số nguyên lớn là các số nguyên có giá trị rất lớn
và không thể biểu diễn bằng các kiểu dữ liệu nguyên cơ bản. 
Để biểu diễn số nguyên lớn, ta có thể dùng kiểu struct như sau:
struct bigNum{

    char sign;

    char num[202];

};
Nhiệm vụ các bạn là đa năng hóa các toán tử để thực hiện 
các phép toán số học với kiểu dữ liệu số nguyên lớn vừa định nghĩa ở trên.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <bits/stdc++.h>
using namespace std;

struct bigNum_50 {
    char sign_50;
    char num_50[202];

    //hàm nhập dữ liệu
    void input_50(char sign_50, char* num_50) {
       this->sign_50 = sign_50;
       strcpy(this->num_50, num_50);
    }
};

//Hàm character to int
inline int ctoi_50(char c_50) {
    return c_50 - '0';
}

//khai báo
bigNum_50 operator + (bigNum_50 a_50, bigNum_50 b_50);
bigNum_50 operator - (bigNum_50 a_50, bigNum_50 b_50);

//Nạp chồng toán tử >
bool operator > (bigNum_50 a_50, bigNum_50 b_50) {
    int lenA_50 = strlen(a_50.num_50);
    int lenB_50 = strlen(b_50.num_50);
    if (lenA_50 != lenB_50) return lenA_50 > lenB_50;
    return strcmp(a_50.num_50, b_50.num_50) > 0;
}

/* Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

//Nạp chồng toán tử -
bigNum_50 operator - (bigNum_50 a_50, bigNum_50 b_50) {
    bigNum_50 res_50;
    if (a_50.sign_50 != b_50.sign_50) { //khác dấu -> như phép cộng
       b_50.sign_50 = a_50.sign_50;
       res_50 = a_50 + b_50;
    } else { //cùng dấu
       if (b_50 > a_50) { // đảo số lớn hơn lên để trừ
          res_50.sign_50 = (b_50.sign_50 == '1') ? '0' : '1';
          char tmp_50[202];
          strcpy(tmp_50, a_50.num_50);
          strcpy(a_50.num_50, b_50.num_50);
          strcpy(b_50.num_50, tmp_50);
       } else {
          res_50.sign_50 = a_50.sign_50;
       }

       char hieu_rev_50[202] = {0};
       int muon_50 = 0;
       int ia_50 = strlen(a_50.num_50) - 1, ib_50 = strlen(b_50.num_50) - 1;
       int i_50 = 0;
       //duyệt từ sau đến
       while (ia_50 >= 0 || ib_50 >= 0) {
          int digitA_50 = (ia_50 >= 0) ? ctoi_50(a_50.num_50[ia_50]) : 0;
          int digitB_50 = (ib_50 >= 0) ? ctoi_50(b_50.num_50[ib_50]) : 0;
          int tmp_50 = digitA_50 - muon_50 - digitB_50;
          if (tmp_50 < 0) { //nếu thiếu thì mượn = 1
             muon_50 = 1;
             tmp_50 += 10;
          } else {
             muon_50 = 0;
          }
          hieu_rev_50[i_50] = tmp_50 + '0';
          ia_50--; ib_50--; i_50++;
       }
       hieu_rev_50[i_50] = '\0';
       for (int j_50 = 0; j_50 < i_50 / 2; ++j_50) {
          swap(hieu_rev_50[j_50], hieu_rev_50[i_50 - j_50 - 1]);
       }
       strcpy(res_50.num_50, hieu_rev_50);
    }

    return res_50;
}
/* Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

//Nạp chồng toán tử +
bigNum_50 operator + (bigNum_50 a_50, bigNum_50 b_50) {
    bigNum_50 res_50;
    if (a_50.sign_50 == b_50.sign_50) { //cùng âm, cùng dương
       char tong_rev_50[202];
       res_50.sign_50 = a_50.sign_50;
       int du_50 = 0;
       int ia_50 = strlen(a_50.num_50) - 1, ib_50 = strlen(b_50.num_50) - 1;
       int i_50 = 0;
       //duyệt ngược từ sau
       while (ia_50 >= 0 || ib_50 >= 0 || du_50) {
          int digitA_50 = (ia_50 >= 0) ? ctoi_50(a_50.num_50[ia_50]) : 0;
          int digitB_50 = (ib_50 >= 0) ? ctoi_50(b_50.num_50[ib_50]) : 0;
          int tmp_50 = digitA_50 + digitB_50 + du_50;
          //nếu tmp > 10 -> dư = 1
          du_50 = tmp_50 / 10;
          tong_rev_50[i_50] = (tmp_50 % 10) + '0';
          ia_50--; ib_50--; i_50++;
       }
       int n_50 = i_50;
       //copy tong_rev vào kết quả
       for (int i_50 = n_50 - 1; i_50 >= 0; i_50--) {
          res_50.num_50[n_50 - i_50 - 1] = tong_rev_50[i_50];
       }
       res_50.num_50[n_50] = '\0';
    } else if (a_50.sign_50 != b_50.sign_50) { //khác dấu -> như phép trừ
       if (a_50.sign_50 == '0') {
          a_50.sign_50 = '1';
          res_50 = b_50 - a_50;
       } else {
          b_50.sign_50 = '1';
          res_50 = a_50 - b_50;
       }
    }
    return res_50;
}
/* Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

//Nạp chồng toán tử *
bigNum_50 operator * (bigNum_50 a_50, bigNum_50 b_50) {
    bigNum_50 res_50;
    int sign_50 = (a_50.sign_50 == b_50.sign_50) ? '1' : '0';
    a_50.sign_50 = '1'; b_50.sign_50 = '1';
    strcpy(res_50.num_50, "0");
    res_50.sign_50 = '1';

    int lenB_50 = strlen(b_50.num_50);
    //Nhân từng chữ số của b cho a
    for (int i_50 = lenB_50 - 1; i_50 >= 0; i_50--) {
       bigNum_50 subSum_50;
       subSum_50.sign_50 = '1';
       strcpy(subSum_50.num_50, "0");
       int digitB_50 = ctoi_50(b_50.num_50[i_50]);
       for (int k_50 = 0; k_50 < digitB_50; k_50++) {
          subSum_50 = subSum_50 + a_50;
       }

       //thêm 0 vào cuối subSum
       int len_50 = strlen(subSum_50.num_50);
       for (int k_50 = 0; k_50 < (lenB_50 - 1 - i_50); k_50++) {
          subSum_50.num_50[len_50 + k_50] = '0';
       }
       subSum_50.num_50[len_50 + (lenB_50 - 1 - i_50)] = '\0';
       //res cộng lần lượt các tổng con sau khi thêm 0 vào cuối
       res_50 = res_50 + subSum_50;
    }
    res_50.sign_50 = sign_50;
    return res_50;
}
/* Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

int main() {
    //input number a
    cout << "Ho Minh Dung - 5050\n";
    char s_50[202];
    cin >> s_50;
    bigNum_50 a_50;
    if (s_50[0] == '0') a_50.input_50('0', s_50 + 1);
    else a_50.input_50('1', s_50 + 1);
    //input number b
    cin >> s_50;
    bigNum_50 b_50;
    if (s_50[0] == '0') b_50.input_50('0', s_50 + 1);
    else b_50.input_50('1', s_50 + 1);

    bigNum_50 ab_50 = a_50 * b_50;
    bigNum_50 a3_50 = a_50 + a_50 + a_50;
    bigNum_50 b4_50 = b_50 + b_50 + b_50 + b_50;
    bigNum_50 res_50 = ab_50 - a3_50 + b4_50;
    cout << "output = ";
    cout << res_50.sign_50 << res_50.num_50 << endl;
}
/* Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

