/* Bai 4.6 Viết hàm void bfs(vector< list<int> > adj) thực hiện thuật toán BFS 
không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề. 
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán BFS xuất phát từ đỉnh 1. 
Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề.
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm 
(những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <bits/stdc++.h>
using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q_50;
    vector<bool> visited_50(adj.size());
    Q_50.push(1); // Bắt đầu từ đỉnh số 1
    /*****************
    # YOUR CODE HERE #
    *****************/
    visited_50[1] = true;
    while (!Q_50.empty()){
        int u_50 = Q_50.front();
        Q_50.pop();
        cout << u_50 << endl;
        //duyệt danh sách kề, nếu chưa được thăm thì thăm và push vào queue
        for (int x_50 : adj[u_50]){
            if (!visited_50[x_50]){
                visited_50[x_50] = true;
                Q_50.push(x_50);
            }
        }
    }
}

int main(){
    cout << "Ho Minh Dung - 5050\n";
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
}