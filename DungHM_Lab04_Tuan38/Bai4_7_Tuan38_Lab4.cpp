/* Bai 4.7 Viết các hàm thực hiện các phép giao và hợp 
của hai tập hợp được biểu diễn bằng set.
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <iostream>
#include <set>

using namespace std;

template<class T>
set<T> set_union(const set<T> &a_50, const set<T> &b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    set<T> res_50;
    for (T x_50 : a_50){
        res_50.insert(x_50);
    }
    for (T x_50 : b_50){
        res_50.insert(x_50);
    }
    return res_50;
}

template<class T>
set<T> set_intersection(const set<T> &a_50, const set<T> &b_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    set<T> res_50;
    for (T x_50 : a_50){
        if (b_50.find(x_50) != b_50.end()){
            res_50.insert(x_50);
        }
    }
    return res_50;
}

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    cout << "Ho Minh Dung - 5050\n";
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);
    
    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);

    return 0;
}