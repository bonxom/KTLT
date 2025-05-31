/* Bai 4.8 Viết các hàm thực hiện các phép giao 
và hợp của hai tập hợp mờ được biểu diễn bằng map.
Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1] 
biểu thị độ thuộc của phần tử trong tập hợp, 
với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp 
và ngược lại độ thuộc bằng 0 nghĩa là phần tử chắc chắn không thuộc trong tập hợp.

Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp,
với độ thuộc mới được tính bằng phép toán min và max của hai độ thuộc.
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a_50, const map<T, double> &b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    map<T, double> res_50;
    for (auto x_50 : a_50){
        res_50.insert(x_50);
    }
    for (auto x_50 : b_50){
        if (res_50.find(x_50.first) != res_50.end()){
            x_50.second = max(x_50.second, res_50[x_50.first]);
        }
        res_50[x_50.first] = x_50.second;
    }
    return res_50;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a_50, const map<T, double> &b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    map<T, double> res_50;
    for (auto x_50 : a_50){
        auto it_50 = b_50.find(x_50.first);
        if (it_50 != b_50.end()){
            res_50[x_50.first] = min(x_50.second, it_50->second);
        }
    }
    return res_50;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    cout << "Ho Minh Dung - 5050\n";
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}