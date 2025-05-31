/* Bai 4.5 Viết hàm thực hiện thuật toán DFS không sử dụng đệ quy 
trên đồ thị biểu diễn bằng danh sách kề vector< list<int> >.
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát từ đỉnh 1. 
Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. 
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm 
(những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S_50;
    vector<bool> visited_50(adj.size(), false);
    S_50.push(1); // Bắt đầu từ đỉnh số 1

    while (!S_50.empty()) {
        int u_50 = S_50.top();
        S_50.pop();
        //nếu đỉnh chưa được duyệt
        if (!visited_50[u_50]) {
            cout << u_50 << endl;
            visited_50[u_50] = true;
            //duyệt danh sách kề, nếu chưa được thăm thì đưa vào stack
            for (auto it_50 = adj[u_50].rbegin(); it_50 != adj[u_50].rend(); ++it_50) {
                if (!visited_50[*it_50]) {
                    S_50.push(*it_50);
                }
            }
        }
    }
}

int main(){
    cout << "Ho Minh Dung - 5050\n";
    int n_50 = 7;
    vector< list<int> > adj;
    adj.resize(n_50 + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}