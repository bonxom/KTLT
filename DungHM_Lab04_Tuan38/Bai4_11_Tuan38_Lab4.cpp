/* Bai 4.11 Bảo vệ lâu đài
Bức tường bao quanh một lâu đài nọ được cấu thành từ n đoạn tường được 
đánh số từ 1 đến n. Quân giặc lên kế hoạch tấn công lâu đài 
bằng cách gửi a_i tên giặc đánh vào đoạn tường thứ i. 
Để bảo vệ lâu đài có tất cả  s lính.
Do các đoạn tường có chất lượng khác nhau nên khả năng bảo vệ tại
 các đoạn tường cũng khác nhau. Cụ thể tại đoạn tường thứ i, 
 mỗi lính có thể đẩy lùi tấn công của k_i tên giặc.
Giả sử đoạn tường thứ  i có xi lính. 
Khi đó nếu số tên giặc không vượt quá  xi×ki
thì không có tên giặc nào lọt vào được qua đoạn tường này. 
Ngược lại sẽ có  ai−xi×ki tên giặc lọt vào lâu đài qua đoạn tường này.
Yêu cầu hãy viết chương trình phân bố lính đứng ở các đoạn tường 
sao cho tổng số lính là s và tổng số lượng tên giặc lọt vào 
lâu đài là nhỏ nhất.
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <bits/stdc++.h>
using namespace std;

int n_50, s_50;
//first lưu a_i: số tên giặc tại i
//second lưu k_i: mỗi lính i đẩy lui k_i giặc
inline dpe(const pair<int, int> &x){
    return x.first / x.second; //defender per enermy: không dùng thừa quân
}

struct cmp {
    //ngược với comparator trong sort
    //VD trong sort cmp(a, b) sắp xếp tăng dần thì a > b = true
    //trong p_queue cmp(a, b) trả true tức là a ÍT được ưu tiên hơn b
    bool operator()(pair<int, int> a, pair<int, int> b) {
        //ưu tiên vị trí đẩy lùi nhiều địch trước
        if (a.first >= a.second && b.first >= b.second) return a.second < b.second;
        if (a.first >= a.second && b.first < b.second) return a.second < b.first;
        if (a.first < a.second && b.first >= b.second) return a.first < b.second;
        return a.first < b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q_50;
/*Ho Minh Dung - 20235050 - 750829 - Tuan 38*/
int main(){
    cout << "Ho Minh Dung - 5050\n";
    ifstream inFile_50("input.txt");
    inFile_50 >> n_50 >> s_50;
    for (int i_50 = 0; i_50 < n_50; i_50++){
        int a_50, k_50;
        inFile_50 >> a_50 >> k_50;
        Q_50.push({a_50, k_50});
    }
    
    while (s_50 > 0){
        pair<int, int> x_50 = Q_50.top();
        Q_50.pop();
        //cout << "check: " << x.first << " " << x.second << endl; 
        //nếu quân địch đã ít đi
        if (dpe(x_50) == 0){
            s_50--; //chỉ cần dùng 1 quân
        }
        else if (dpe(x_50) < s_50){
            s_50 -= dpe(x_50); //dùng số quân tối thiểu, ko thừa quân
            x_50.first -= dpe(x_50)*x_50.second;
            Q_50.push(x_50);
        }
        else{//dùng hết quân vẫn không chống được địch
            x_50.first -= s_50 * x_50.second;
            s_50 = 0;
            Q_50.push(x_50);
        }
    }

    int res_50 = 0;
    while (!Q_50.empty()){
        res_50 += Q_50.top().first;
        //cout << Q.top().first << " " << Q.top().second << endl;
        Q_50.pop();
    }
    cout << res_50 << endl;
}
