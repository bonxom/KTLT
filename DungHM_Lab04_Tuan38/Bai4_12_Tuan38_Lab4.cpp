/* Bai 4.12 Lược đồ
Cho một lược đồ gồm n cột chữ nhật liên tiếp nhau có chiều rộng bằng 1 và chiều cao 
lần lượt là các số nguyên không âm  h1,h2,…,hn. 
Hãy xác định hình chữ nhật có diện tích lớn nhất có thể tạo thành từ các cột liên tiếp.
Ho Minh Dung - 20235050 - 750829 - Tuan 38 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream inFile ("input.txt");
    int n_50;
    inFile >> n_50;
    vector<int> h_50(n_50);
    for (int i_50 = 0; i_50 < n_50; i_50++){
        inFile >> h_50[i_50];
    }

    stack<int> st_50;
    int max_area_50 = 0;
    int i_50 = 0;

    while (i_50 <= n_50) {
        int height_50 = (i_50 == n_50) ? 0 : h_50[i_50]; // thêm 1 cột 0 ở cuối để đảm bảo stack trống hết
        //nếu stack trống hoặc cột đang xét có chiều cao lớn hơn top
        if (st_50.empty() || height_50 >= h_50[st_50.top()]) {
            st_50.push(i_50++);
        } 
        else {//cột đang xét nhỏ hơn top 
            int top_50 = st_50.top(); st_50.pop();
            //tức là cột top ko có khả năng mở rộng sang phải
            //dần dần mở rộng sang phải bằng cách check top (ở vòng while tiếp theo)
            int width_50 = st_50.empty() ? i_50 : i_50 - st_50.top() - 1;
            int area_50 = h_50[top_50] * width_50;
            max_area_50 = max(max_area_50, area_50);
        }
    }

    cout << max_area_50 << endl;
    return 0;
}
