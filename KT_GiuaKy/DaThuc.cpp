#include <bits/stdc++.h>
using namespace std;

int n;

struct DaThuc{
    string name;
    int bac;
    double x;
    double heso[11];
    
    DaThuc(){}
    DaThuc(string name, int bac, double x, double heso[]){
        this->name = name;
        this->bac = bac;
        this->x = x;
        for (int i = 0; i <= bac; i++){
            this->heso[i] = heso[i];
        }
    }

    double myPow(int m){
        double res = 1;
        if (m == 0) return res;
        while (m--){
            res *= x;
        }
        return res;
    }
    double value(){
        double res;
        for (int i = 0; i <= bac; i++){
            res += heso[i] * myPow(i);
        }
        return res;
    }

    void in(){
        cout << " Da thuc: " << name << "(x) = ";
        for (int i = bac; i > 0; i--){
            if (heso[i] != 0){
                if (abs(heso[i]) != 1) cout << heso[i] << "*";
                cout << "x";
                if (i != 1) cout << "^" << i;
                if (heso[i - 1] >= 0) cout << " + ";
                else cout << " ";
            }
        }
        if (heso[0] != 0) cout << heso[0];
        cout << endl;
        cout << " Gia tri Da thuc: " << name << "(" << x << ") = " << fixed <<  setprecision(2) << value() << endl;
    }
};
vector <DaThuc> dsDaThuc;
void first(){
    cout << "\nBan da chon nhap DS da thuc!\n";
    cout << "__________________________________________\n";
    for (int i = 1; i <= n; i++){
        string name;
        int bac;
        double x;
        double heso[11] = {0};
        cout << "Nhap da thuc thu " << i <<  ":\n";
        cout << "Ho Minh Dung - 5050 - 750829\n";
        cout << "Nhap ten da thuc: "; cin >> name; cout << endl;
        cout << "Nhap bac: "; cin >> bac; cout << endl;
        cout << "Nhap x: "; cin >> x; cout << endl;
        for (int j = bac; j >= 0; j--){
            cout << " He so bac " << j << ": "; cin >> heso[j]; cout << endl;
        }
        cout << "__________________________________________\n";
        DaThuc dt(name, bac, x, heso);
        dsDaThuc.push_back(dt);
    }
    cout << "Ban da nhap thanh cong!\n";
}

void second(){
    cout << "Ban da chon xuat DS da thuc, Gia tri da thuc!\n";
    cout << "Ho Minh Dung - 5050 - 750829\n";
    cout << "__________________________________________\n";
    for (DaThuc &x : dsDaThuc){
        x.in();
        cout << "__________________________________________\n";
    }

}

int main(){
    cout << "Ho Minh Dung - 5050 - 750829\n";
    cout << "Nhap so luong da thuc :"; cin >> n;
    while (1){
        cout << "*********************************************\n";
        cout << "**     CHUONG TRINH QUAN LY CAC DA THUC     **\n";
        cout << "**         1. Nhap cac da thuc, gia tri x      **\n";
        cout << "**         2. In danh sach da thuc, va gia tri    **\n";
        cout << "**         0. Thoat                            **\n";
        cout << "*********************************************\n";
        cout << "**         Nhap lua chon cua ban           **\n";

        string x; cin >> x;
        if (x == "1") first();
        else if (x == "2") second();
        else if (x == "0") break;
        else cout << "Ban da nhap that bai!\n";

        cout << "Bam phim bat ky de tiep tuc\n" << endl;
        string tmp; cin >> tmp;
        system("clear");
    }
}