/* Bai 3.1 Dãy Lucas được định nghĩa bởi Ln=Ln−1+Ln−2 
và bắt đầu bởi L0=2, L1=1. Viết hàm tính số Lucas thứ n.
Ho Minh Dung - 20235050 - 750829 - Tuan 36*/
#include <bits/stdc++.h>
using namespace std;

int lucas(int n_50){
	int a_50[100] = {0};
	a_50[0] = 2;
	a_50[1] = 1;
	if (n_50 < 2) return a_50[n_50];
	for (int i_50 = 2; i_50 <=n_50; i_50++){
		a_50[i_50] = a_50[i_50 - 1] + a_50[i_50 - 2];
	}
	return a_50[n_50];
}

int main(){
	cout << "Ho Minh Dung - 5050\n";
	cout << "input = ";
	int n; cin >> n;
	cout << "output = " << lucas(n);
}
