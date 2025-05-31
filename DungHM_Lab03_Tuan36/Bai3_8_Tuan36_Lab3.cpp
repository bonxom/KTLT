/* Bai 3.8 Cân đĩa
Bạn đang muốn kiểm tra xem một vật cho trước có đúng nặng M 
như người ta nói hay không. Có một cân thăng bằng và n quả cân. 
Quả thứ i nặng mi. Hãy chỉ ra một cách cân thỏa mãn. 
Quy cách in ra đã được tích hợp trong mã nguồn dưới.
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_S;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    cout << "Ho Minh Dung - 5050\ninput = ";
    int n_50, M_50;
    cin >> n_50 >> M_50;
    int m_50[n_50+1];
    for (int i_50 = 1; i_50 <= n_50; ++i_50) cin >> m_50[i_50];
    int x_50[n_50+1];
    stack<state> s_50;
    //# sum of selected weights
    int sum_50 = 0;
    s_50.push(state(1, -1));
    while (!s_50.empty()){
        state &top_50 = s_50.top();
        if (top_50.i > n_50){
            if (sum_50 == M_50){
                cout << "output = ";
                for (int i_50 = 1; i_50 <= n_50; ++i_50){
                    if (x_50[i_50] == -1) cout << '-' << m_50[i_50];
                    if (x_50[i_50] == 1) cout << '+' << m_50[i_50];
                }
                cout << "=" << M_50;
                exit(0);
            }
            s_50.pop();
            continue;
        }
        /*Ho Minh Dung - 20235050 - 750829 - Tuan 36*/        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/
        // #backtrack
        if (top_50.j > -1){
            sum_50 = top_50.old_S;
        }
        // -1: cân trái, 1: cân phải, 0: ko dùng
        if (top_50.j > 1) {
            x_50[top_50.i] = 0;
            s_50.pop();
            continue;
        }

        if (sum_50 != M_50 && top_50.i <= n_50) {
            x_50[top_50.i] = top_50.j;
            top_50.old_S = sum_50;
            if (top_50.j == 1) sum_50 += m_50[top_50.i];
            if (top_50.j == -1) sum_50 -= m_50[top_50.i];
            s_50.push(state(top_50.i + 1, -1));
        }
        ++top_50.j;
    }
    cout << -1;

    return 0;
}