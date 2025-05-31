/* Bài 1.9 - Tuần 31 
Hồ Minh Dũng - 5050 - 750829 - 20242 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Ho Minh Dung - 5050" << endl;
    cout << "input: " << endl;
    int n_dunghm; cin >> n_dunghm;
    int a_dunghm[n_dunghm];
    for (int &x_dunghm : a_dunghm) cin >> x_dunghm;
    cout << "output: " << endl;
    for (int i_dunghm = 0; i_dunghm < n_dunghm; i_dunghm++){
        string substr_dunghm = to_string(a_dunghm[i_dunghm]) + " ";
        cout << substr_dunghm << endl;
        for (int j_dunghm = i_dunghm + 1; j_dunghm < n_dunghm; j_dunghm++){
            substr_dunghm += to_string(a_dunghm[j_dunghm]) + " ";
            cout << substr_dunghm << endl;
        }
    }
}