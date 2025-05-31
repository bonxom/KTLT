/* Bai 2.12 Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. 
Cô cho một danh sách với mỗi phần tử có dạng <key, value>
và yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value. 
Nếu 2 phần tử có value giống nhau thì sắp xếp giảm dần theo key.
Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    //input
    cout << "Ho Minh Dung - 5050\ninput = (file)\n";
    vector<pair<int, int>> v_50;
    pair<int, int> x_50;
    ifstream inFile("input.txt");
    while (inFile >> x_50.first){
        inFile >> x_50.second;
        v_50.push_back(x_50);
    }
    //xây dựng comparator bằng hàm nặc danh
    sort(v_50.begin(), v_50.end(), [](pair<int, int> a_50, pair<int, int> b_50)->bool{
        if (a_50.second != b_50.second) return a_50.second > b_50.second;
        return a_50.first > b_50.first;
    });

    //output
    cout << "output = \n";
    for (pair<int, int> &x_50 : v_50){
        cout << x_50.first << " " << x_50.second << endl;
    }
}