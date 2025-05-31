#include <bits/stdc++.h>
using namespace std;

const int n = 2;

struct DangVien{
    string soThe, ten;
    int ngay, thang, nam, luong;
    string chucVu;
    double phucap;

    DangVien(){}
    DangVien(string soThe, string ten, int luong, int ngay, int thang, int nam, string chucVu){
        this->soThe = soThe;
        this->ten = ten;
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
        this->luong = luong;
        this->chucVu = chucVu;
        if (chucVu == "BiThu") phucap = luong * 0.05;
        else if (chucVu == "Pbthu") phucap = luong * 0.025;
        else if (chucVu == "Uyvien") phucap = luong * 0.015;
        else phucap = 0;
    }

    string getNgayVaoDang(){
        return to_string(ngay) + "-" + to_string(thang) + "-" + to_string(nam);
    }
};

struct ChiBo{
    string tenCB;
    int soDangVien;
    double tongLuong;
    double tongPC;
    vector<DangVien> v;

    ChiBo(){}
    ChiBo(string TenCB){
        this->tenCB = TenCB;
        soDangVien = 0;
        tongLuong = 0;
    }

    void in(){
        double dangPhi = 0.01 * tongLuong;
        cout << "   Ten Chi Bo: " << tenCB << endl;
        cout << "   so Dang Vien: " << soDangVien << endl;
        cout << "   Tong luong: " << tongLuong << endl;
        cout << "   Dang Phi: " << dangPhi << endl;
        cout << "   Tong DP nop cap tren: " << 0.7 * dangPhi << endl;
        cout << "   Tong tro cap phuc vu: " << tongPC << endl;

        cout << "Bang thu dang phi: \n";
        cout << "sothe   HotenDV    Ngayvaodang     Tuoidang    Chucvu   Trocap   Luong    Dangphi\n";
        for (DangVien &x : v){
            cout << left<< setw(8) << setfill(' ') << x.soThe;
            cout << left<< setw(11) << setfill(' ') << x.ten;
            cout << left<< setw(16) << setfill(' ') << x.getNgayVaoDang();
            cout << left<< setw(12) << setfill(' ') << 2025 - x.nam;
            cout << left<< setw(9) << setfill(' ') << x.chucVu;
            cout << left<< setw(9) << setfill(' ') << x.phucap;
            cout << left<< setw(9) << setfill(' ') << x.luong;
            cout << x.luong * 0.01; cout << endl;
        }
    }
};

vector<ChiBo> dsChiBo;
void first(){
    cout << "Ban da chon nhap ds Chi bo Dang vien!\n";
    for (int q = 1; q <= n; q++){
        string ten; int soDangVien;
        cout << "Nhap thong tin Chi bo thu " << q << ": \n";
        cout << "   Ten Chi Bo: "; cin >> ten;
        cout << "   So dang vien: "; cin >> soDangVien;
        cout << "   Nhap danh sach dang vien: \n";
        dsChiBo.push_back(ChiBo(ten));
        for (int i = 1; i <= soDangVien; i++){
            string sothe, ten, chucVu;
            int ngay, thang, nam, luong;
            cout << "   Dang vien thu " << i << endl;
            cout << "       So the: "; cin >> sothe;
            cout << "       Ten dang vien: "; cin.ignore();getline(cin, ten); cout << endl;
            cout << "       Ngay vao dang:\n";
            cout << "       Ngay: "; cin >> ngay;
            cout << "       Thang: "; cin >> thang;
            cout << "       Nam: "; cin >> nam; cout << endl;
            cout << "       Luong: "; cin >> luong; cout << endl;
            cout << "       Chuc vu: "; cin >> chucVu; cout << endl;
            DangVien x(sothe, ten, luong, ngay, thang, nam, chucVu);
            dsChiBo[q-1].v.push_back(x);
            dsChiBo[q-1].soDangVien++;
            dsChiBo[q-1].tongLuong += luong;
            dsChiBo[q-1].tongPC += x.phucap;
        }
    }

    cout << "Ban da nhap thanh cong!\n";
}

void second(){
    cout << "Ban da chon xuat DS Chi bo!\n";
    for (ChiBo &x : dsChiBo){
        cout << "\n___________________________________________________________________\n";

        x.in();

        cout << "\n___________________________________________________________________\n";
    }
}
int main(){
    while (1){
        cout << "Ho Minh Dung - 20235050 - 750829" << endl;
        cout << "**     CHUONG TRINH QUAN LY Chi bo - Dang vien     **\n";
        cout << "**1. Nhap cac chi bo    **\n";
        cout << "**2. In ket qua ds Chi bo Dang vien    **\n";
        cout << "**0. Thoat     **\n";
        cout << "**********************************\n";
        cout << "**     Nhap lua chon cua ban    **\n";
        string x;  cin >> x;
        if (x == "1") first();
        else if (x == "2") second();
        else if (x == "0") break;
        else cout << "Ban da nhap that bai!\n";

        cout << "Bam phim bat ky de tiep tuc!\n";
        string tmp; cin >> tmp;
        system("clear");
    }
}