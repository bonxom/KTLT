/* Bai 3.7 Liệt kê xâu nhị phân
Sử dụng phương pháp khử đệ quy bằng stack, 
hãy liệt kê các xâu nhị phân độ dài n không có k bit 1 nào liên tiếp
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    cout << "Ho Minh Dung - 5050\n";
    int n_50, k_50;
    cin >> n_50 >> k_50;
    int x_50[n_50+1];
    stack<state> s_50;
    //# number of consecutive suffix 1
    int L_50 = 0;
    s_50.push(state(1, 0));
    while (!s_50.empty()){
        state &top_50 = s_50.top();
        //# if a new binary sequence is found
        if (top_50.i > n_50){
            for (int i_50 = 1; i_50 <= n_50; ++i_50)
                cout << x_50[i_50] << " \n"[i_50 == n_50];
            s_50.pop();
            continue;
        }
        
        //# khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/  

        // Trả lại trạng thái L nếu vừa backtrack từ nhánh 1
        if (top_50.j == 1) {
            L_50 = top_50.old_L;
        }

        // Nếu đã thử cả 0 và 1 => quay lui
        if (top_50.j > 1) {
            s_50.pop();
            continue;
        }

        // Kiểm tra xem có thể đặt 0 hoặc 1 tại vị trí i không
        if (L_50 + 1 < k_50 || top_50.j == 0) {
            x_50[top_50.i] = top_50.j;
            top_50.old_L = L_50;

            if (top_50.j == 1) L_50++;
            else L_50 = 0;

            s_50.push(state(top_50.i + 1, 0));
        }

        ++top_50.j; // chuyển sang thử giá trị tiếp theo (từ 0 -> 1)
    }
    return 0;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
