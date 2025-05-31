/* Bai 3.4 Cho dãy a có n phần tử. Một dãy con của a là dãy thu được bằng cách xóa đi 
một số phần tử của a và giữ nguyên thứ tự các phần tử còn lại (có thể không xóa phần tử nào). 
Hãy tìm dãy con tăng dài nhất của a
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;
int a_50[1000], n_50;
int mem_50[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải

void init(){
    memset(mem_50, -1, sizeof(mem_50));
}

//# Quy hoạch động, 
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    if (mem_50[i] != -1) return mem_50[i];
    int res = 1;
    for (int j = i-1; j >= 0; j--){
        if (a_50[j] < a_50[i]){
            res = max(res, lis(j) + 1);
        }
    }
    mem_50[i] = res;
    return res;
}
//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a_50[j] < a_50[i] && mem_50[i] == 1 + mem_50[j]){
            trace(j);
            break;
        }
    }
    cout << a_50[i] << " ";
}

int main(){
    cout << "Ho Minh Dung - 5050\n";
    init();
    cin >> n_50;
    for(int i = 0; i < n_50; i++) cin >> a_50[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n_50; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
