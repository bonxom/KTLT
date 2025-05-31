/* Bai 4.9 Cài đặt thuật toán Dijkstra trên đồ thị vô hướng
được biểu diễn bằng danh sách kề sử dụng priority_queue
Cụ thể, bạn cần cài đặt hàm vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj)
nhận đầu vào là danh sách kề chứa các cặp pair<int, int> 
biểu diễn đỉnh kề và trọng số tương ứng của cạnh. 
Đồ thị gồm n đỉnh được đánh số từ 0 tới n-1. 
Hàm cần trả `vector<int>` chứa n phần tử lần lượt là khoảng cách đường đi ngắn nhất 
từ đỉnh 0 tới các đỉnh 0, 1, 2, ..., n-1.
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

//pair có first = weight, second = đỉnh
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q_50;
int d_50[1000];
bool found_50[1000];

void relax_50(int u_50, int v_50, int w_50){
    if (d_50[v_50] > d_50[u_50] + w_50){
        d_50[v_50] = d_50[u_50] + w_50;
        Q_50.push({d_50[v_50], v_50});
    }
}
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    //khởi tạo
    fill(d_50, d_50 + 1000, INT_MAX);
    fill(found_50, found_50 + 1000, false);
    d_50[0] = 0;
    Q_50.push({d_50[0], 0});

    while (!Q_50.empty()){
        int u_50 = Q_50.top().second;
        Q_50.pop();

        //chưa tìm ra đường đi tốt nhất đến u
        if (!found_50[u_50]){
            found_50[u_50] = true;
            //duyệt danh sách kề của u
            for (const pair<int, int> &e_50 : adj[u_50]){
                //nếu đi qua u giúp rút ngắn, thì cập nhật đường đi mới cho đỉnh kề với u
                if (!found_50[e_50.first]){
                    int v_50 = e_50.first;
                    int w_50 = e_50.second;
                    if (!found_50[v_50]) {
                        relax_50(u_50, v_50, w_50);
                    }
                }
            }
        }
    }

    //kết quả
    vector<int> res_50;
    for (int i_50 = 0; i_50 < adj.size(); ++i_50) {
        res_50.push_back(d_50[i_50]);
    }
    return res_50;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

int main() {
    cout << "Ho Minh Dung - 5050\n";
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}