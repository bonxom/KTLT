#include<bits/stdc++.h>
using namespace std;

const double pi = 3.14;
const int input = 2;

inline double sqr(double x){ return x * x;}

struct Point{
    string name;
    double x, y, z;
    
    Point(){};
    Point (string name, int x, int y, int z){
        this->name = name;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void in(){
        cout << name << "(" << x << "," << y << "," << z << ")" << endl;
    }
};

struct Circle{
    Point Tam;
    double R;
    vector<Point> v;
    Circle(){};
    Circle (Point Tam, double R){
        this->Tam = Tam;
        this->R = R;
    }
    
    double khoangCach(Point A, Point B){
        double x2 = sqr(A.x - B.x);
        double y2 = sqr(A.y - B.y);
        double z2 = sqr(A.z - B.z);
        return sqrt(x2 + y2 + z2);
    }
    double chuViTamGiac(){
        return khoangCach(v[0], v[1]) + khoangCach(v[1], v[2]) + khoangCach(v[2], v[0]);
    }

    double chuVi(){
        return 2 * pi * R;
    }

    double dienTich(){
        return pi * R * R;
    }

    void trungDiem(Point X){
        double x = (Tam.x + X.x) / 2;
        double y = (Tam.y + X.y) / 2;
        double z = (Tam.z + X.z) / 2;
        cout << "Toa do trung diem cua doan thang: " << Tam.name;
        X.in();
    }

    Point trongTam(){
        double x = (v[0].x + v[1].x + v[2].x) / 3;
        double y = (v[0].y + v[1].y + v[2].y) / 3;
        double z = (v[0].z + v[1].z + v[2].z) / 3;
        return Point("G", x, y, z);
    }

    void in(){
        cout << "Hinh tron tam: " << Tam.name << endl;
        cout << "Toa do tam " << Tam.name << "(" << Tam.x << "," << Tam.y << "," << Tam.z << ")" << endl;
        cout << "Ban kinh R: " << R << endl;
        for (Point &x : v){
            cout << "Toa do diem ";
            x.in();
        }
        for (Point &x : v){
            trungDiem(x);
        }
        cout << "Toa do trong tam G cua tam giac" << v[0].name << v[1].name << v[2].name << "="; trongTam().in();
        cout << "Chu vi tam giac: " << v[0].name << v[1].name << v[2].name << "=" << chuViTamGiac() << endl;
        cout << "Chu vi hinh tron: " << chuVi() << endl;
        cout << "Dien tich hinh tron: " << dienTich() << endl;

        for (Point &x : v){
            if (khoangCach(Tam, x) == R) cout << "Diem " << x.name << " nam tren duong tron\n";
            else if (khoangCach(Tam, x) > R) cout << "Diem " << x.name << " nam tren duong tron\n";
            else cout << "Diem " << x.name << " nam trong duong tron\n";
        }
    }
};
vector<Circle> cList;

void first(){
    cout << "Ban da chon nhap ds Hinh Tron!\n"; 
    for (int q = 1; q <= input; q++){
        cout << "Nhap thong tin cua tg thu " << q << endl;
        string name;
        double x, y, z, R;
        cout << "   Ten tam duong tron: "; cin >> name;
        cout << "       x: "; cin >> x;
        cout << "       y: "; cin >> y;
        cout << "       z: "; cin >> z;
        cout << "   Ban kinh: "; cin >> R;
        Point Tam(name, x, y, z);
        Circle C(Tam, R);
        for (int i = 1; i <= 3; i++){
            cout << "   Ten Diem " << i << ": "; cin >> name;
            cout << "   x: "; cin >> x;
            cout << "   y: "; cin >> y;
            cout << "   z: "; cin >> z;
            C.v.push_back(Point(name, x, y, z));
        }
        cList.push_back(C);
    }
    
    cout << "Ban da nhap thanh cong!";
}

void second(){
    cout << "Ban da chon xuat ds Hinh Tron!\n";
    for (Circle &x : cList){
        x.in();
        cout << endl << endl;
    }
}

int main(){
    while (1){
        cout << "Ho Minh Dung - 20235050 - 750829\n";
        cout << "**     CHUONG TRING QUAN LY CAC duong tron     **\n";
        cout << "**1. Nhap cac duong tron va 3 diem bat ky  **\n";
        cout << "**2. In Toa do tam, diem, ban kinh, vi tri, CHU VI, DIEN TICH, duong tron va chu vi toa do tam cua tam giac lap tu 3 diem   **\n";
        cout << "**0. Thoat  **\n";
        cout << "***********************************\n";
        cout << "**     Nhap lua chon cua ban     **\n";
        string x; cin >> x;
        if (x == "1") first();
        else if (x == "2") second();
        else if (x == "0") break;
        else cout << "Ban da nhap that bai!\n";

        cout << endl << endl << "Bam phim bat ky de tiep tuc!";
        string tmp; cin >> tmp;

        system("clear");
    }
    cout << "Chuong trinh ket thuc!\n";
}