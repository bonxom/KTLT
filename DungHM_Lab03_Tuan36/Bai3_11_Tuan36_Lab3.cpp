/* Bai 3.11 Superior là một hòn đảo tuyệt đẹp với n địa điểm chụp ảnh 
và các đường một chiều nối các điểm chụp ảnh với nhau. 
Đoàn khách tham quan có r người với sở thích chụp ảnh khác nhau. 
Theo đó, mỗi người sẽ đưa ra danh sách các địa điểm mà họ muốn chụp. 
Bạn cần giúp mỗi người trong đoàn lập lịch di chuyển sao cho 
đi qua các điểm họ yêu cầu đúng một lần, không đi qua điểm nào khác, 
bắt đầu tại điểm đầu tiên và kết thúc tại điểm cuối cùng trong danh sách 
mà họ đưa ra, và có tổng khoảng cách đi lại là nhỏ nhất.
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;

int n_50, r_50; 
int c_50[1000][1000];//ma trận chi phí
vector<int> want_50; //lưu danh sách các điểm muốn thăm
bool visited_50[1000]; //điểm đã thăm
int min_cost_50;
int current_50 = 0;
int pre_50; //điểm thăm trước đó
int cmin_50; //chi phí nhỏ nhất

void Try(int k_50){
    for (int i_50 = 1; i_50 < want_50.size() - 1; i_50++){
        // chưa thăm và có đường đi đến
        if (!visited_50[want_50[i_50]] && c_50[pre_50][want_50[i_50]] != 0){
            //lưu trạng thái ban đầu
            int tmp_50 = pre_50;
            visited_50[want_50[i_50]] = true;
            current_50 += c_50[pre_50][want_50[i_50]];
            //cập nhật pre
            pre_50 = want_50[i_50];
            // không tính điểm cuối
            if (k_50 == want_50.size() - 2){
                // có đường từ điểm want[i] đến điểm cuối
                if (c_50[want_50[i_50]][want_50.back()] != 0){
                    min_cost_50 = min(min_cost_50, current_50 + c_50[want_50[i_50]][want_50.back()]);
                }
            }
            else {
                //branch and bound để tối ưu
                int g_50 = current_50 + cmin_50 * (n_50 - k_50 + 1);
                if (g_50 < min_cost_50) Try(k_50 + 1);
            }
            //trả lại trạng thái ban đầu
            current_50 -= c_50[tmp_50][want_50[i_50]];
            visited_50[want_50[i_50]] = false;
            pre_50 = tmp_50;
        }
    }
}

int main(){
    cout << "Ho Minh Dung - 5050\noutput = \n";
    //input
    ifstream inFile_50("input.txt");
    inFile_50 >> n_50 >> r_50;
    cmin_50 = INT_MAX;
    for (int i_50 = 0; i_50 < n_50; i_50++){
        for (int j_50 = 0; j_50 < n_50; j_50++){
            inFile_50 >> c_50[i_50][j_50];
            if (c_50[i_50][j_50] > 0) cmin_50 = min(cmin_50, c_50[i_50][j_50]);
        }
    }

    inFile_50.ignore();
    for (int i_50 = 0; i_50 < r_50; i_50++){
        memset(visited_50, false, sizeof(visited_50));
        want_50.clear();
        string s_50;
        //xử lý đầu vào của danh sách điểm đến
        getline(inFile_50, s_50);
        stringstream ss_50(s_50);
        string tmp_50;
        while (ss_50 >> tmp_50){
            want_50.push_back(stoi(tmp_50) - 1);
        }
 
        visited_50[want_50[0]] = true; // điểm bắt đầu
        pre_50 = want_50[0];
        min_cost_50 = INT_MAX;
        current_50 = 0;
        Try(1);
        //nếu min_cost ko dc cập nhật thì cập nhật giá trị = 0
        if (min_cost_50 == INT_MAX) min_cost_50 = 0;
        cout << min_cost_50 << endl;
    }
}