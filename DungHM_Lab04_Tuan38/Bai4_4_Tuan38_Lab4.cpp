/* Bai 4.4 Thao tác với vector
Cho hai vector, hãy xóa hết các phần tử chẵn, 
sắp xếp giảm dần các số trong cả 2 vector và trộn lại 
thành một vector cũng được sắp xếp giảm dần.
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    int n_50 = a.size();
    for (int i_50 = 0; i_50 < n_50; i_50++){
        if (a[i_50] % 2 == 0){
            a.erase(a.begin() + i_50);
            i_50--;
            n_50--;
        }
    }
}

void sort_decrease(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    int n_50 = a.size();
    //Selection sort
    for (int i_50 = 0; i_50 < n_50 - 1; i_50++){
        for (int j_50 = i_50 + 1; j_50 < n_50; j_50++){
            if (a[i_50] < a[j_50]){
                swap(a[i_50], a[j_50]);
            }
        }
    }
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    vector<int> v_50;
    for (int x_50 : a) v_50.push_back(x_50);
    for (int x_50 : b) v_50.push_back(x_50);
    sort_decrease(v_50);
    return v_50;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 38*/

int main() {
    cout << "Ho Minh Dung - 5050\n";
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 38*/
