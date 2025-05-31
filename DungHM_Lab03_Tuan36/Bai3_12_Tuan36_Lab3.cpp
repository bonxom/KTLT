/* Bai 3.12 Cho đồ thị vô hướng G, 
hãy đếm số đường đi đi qua k cạnh và không đi qua đỉnh nào quá một lần.
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;

int n_50, k_50, m_50;
pair<int, int> edge_50[100];
vector<int> adj_50[100];//danh sách kề
bool visited_50[100]; //các đỉnh đã đi qua
int res_50; //kết quả (chứa cả kết quả trùng VD 1-2-3 và 3-2-1 là trùng)

//DFS
void Try(int a, int depth){
    //duyệt danh sách kề
    for (int &e : adj_50[a]){
        if (!visited_50[e]){
            visited_50[e] = true;
            //tăng độ sâu
            depth++;
            if (depth == k_50) res_50++;
            else Try(e, depth);
            visited_50[e] = false;
            depth--;
        }
    }
}

int main(){
    cout << "Ho Minh Dung - 5050\noutput = \n";
    //input
    ifstream inFile("input.txt");
    inFile >> n_50 >> k_50 >> m_50;
    for (int i = 0; i < m_50; i++){
        int x, y; inFile >> x >> y;
        x--; y--;
        edge_50[i] = pair(x, y);
        adj_50[x].push_back(y);
        adj_50[y].push_back(x);
    }
    
    for (int i = 0; i < n_50; i++){
        visited_50[i] = true;
        Try(i, 0);
        visited_50[i] = false;
    }
    //loại bỏ các kết quả trùng (vì là đồ thị vô hướng)
    cout << res_50/2 << endl;
}
