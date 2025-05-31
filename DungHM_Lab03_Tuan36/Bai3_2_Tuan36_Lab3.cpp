/* Bai 3.2 Trên bàn cờ vua kích thước n*n có một quân mã đang ở ô (1, 1). 
Hãy đưa ra một dãy các di chuyển của mã sao cho mỗi ô trên bàn cờ đều được 
đi qua đúng 1 lần (ô (1, 1) được xem là đã đi qua).
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <iostream>
using namespace std;

int n_50;
int X_50[100], Y_50[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark_50[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx_50[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy_50[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j_50 = 1; j_50 <= n_50 * n_50; ++j_50)
        printf("(%d %d)\n", X_50[j_50], Y_50[j_50]);
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k_50){
    for(int i_50 = 0; i_50 < 8; i_50++){
        int xx_50 = X_50[k_50-1] + hx_50[i_50];
        int yy_50 = Y_50[k_50-1] + hy_50[i_50];
        /*****************
        # YOUR CODE HERE #
        *****************/
        if (xx_50 >= 1 && xx_50 <= n_50 && yy_50 >= 1 && yy_50 <= n_50 && !mark_50[xx_50][yy_50]){
        	X_50[k_50] = xx_50;
        	Y_50[k_50] = yy_50;
        	mark_50[xx_50][yy_50] = 1;
        	if (k_50 == n_50 * n_50) print_sol();
        	else TRY(k_50 + 1);
        	mark_50[xx_50][yy_50] = 0;
		}
    }
}

int main(){
    cout << "Ho Minh Dung - 5050\n";
    cin >> n_50;
    mark_50[1][1] = 1;
    X_50[1] = Y_50[1] = 1;
    TRY(2);
    return 0;
}
