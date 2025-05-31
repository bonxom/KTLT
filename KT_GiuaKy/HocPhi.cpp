#include <bits/stdc++.h>
using namespace std;

int n;


struct MonHoc{
    string maMH;
    int soTinChi;
    int soTinChiLT;
    int soTinChiBT;
    int soTinChiTH;
    int soTinChiHP;
    string loaiGio;
    string khoiLuong;

    MonHoc(){}
    MonHoc(string maMH, int soTinChi, int soLT, int soBT, int soTH){
        this->maMH = maMH;
        this->soTinChi = soTinChi;
        this->soTinChiBT = soBT;
        this->soTinChiLT = soLT;
        this->soTinChiTH = soTH;
        soTinChiHP = soLT + soBT + 1.5*soTH;


        if (soLT == 0 && soBT == 0 && soTH == 3) {
            loaiGio = "DAMH";
            soTinChiTH = 3;
            soTinChiHP = 6;
        }
        else if (soTinChi == 6) {
            loaiGio = "DATN Cu Nhan";
            soTinChiTH = 12;
            soTinChiHP = 18;
        }
        else if (soTinChi == 12){ 
            loaiGio = "DATN Ky Su";
            soTinChiTH = 12;
            soTinChiHP = 24;
        }
        else if (soTH > 0){
            if (soBT > 0) loaiGio = "LT-BT-TN";
            else loaiGio = "LT-TN";
        }
        else if (soBT > 0) loaiGio = "LT-BT";
        khoiLuong = to_string(soTinChi) + "(" + to_string(soLT) + "-" +to_string(soBT) + "-" +to_string(soTH) + "-" + to_string(soTinChi *2) + ")";
    }
};


struct HocVien{
    string name;
    int soMonHoc, soTienMotTin;
    int hocPhiDaNop;
    int tongHP;
    int HPthieu;
    vector<MonHoc> dsMonHoc;

    HocVien(){};
    HocVien(string name, int soMon, int soTien1T){
        this->name = name;
        this->soMonHoc = soMon;
        this->soTienMotTin = soTien1T;
        hocPhiDaNop = 0;
        tongHP = 0;
    }

    void in(){
        HPthieu = tongHP - hocPhiDaNop;
        cout << "   Ten sv: " << name << endl;
        cout << "   So mon hoc: " << soMonHoc << endl;
        cout << "   So tien 1 TC: " << soTienMotTin << endl;
        cout << "   Phai nop: " << tongHP << endl;
        cout << "   Da nop dot 1: " << hocPhiDaNop << endl;
        cout << "   So tien thieu: " << HPthieu << endl;
        cout << "   Tinh trang nop HP: ";
        if (HPthieu == 0) cout << "Nop du\n";
        else if (HPthieu > 0) cout << "Con thieu\n";
        else cout << "Nop thua";
    }
};

vector <HocVien> dsHocVien;

void first(){
    cout << "Ban da chon nhap ds sinh vien!\n";
    for (int q = 1; q <= n; q++){
        string name;
        int soMonHoc, soTienMotTin;
        int hocPhiDaNop;
        cout << "Nhap thong tin cua sinh vien thu " << q << endl;
        cout << "   Ten sinh vien: "; cin.ignore(); getline(cin, name); cout << endl;
        cout << "   So mon hoc: "; cin >> soMonHoc; cout << endl;
        cout << "   So tien mot tin chi: "; cin >> soTienMotTin; cout << endl;
        HocVien x(name, soMonHoc, soTienMotTin);

        for (int i = 1; i <= soMonHoc; i++){
            string maMH;
            int soTinChi;
            int soTinChiLT = 0;
            int soTinChiBT = 0;
            int soTinChiTH = 0;
            cout << "   Mon hoc thu " << i << endl;
            cout << "   Ma mon hoc: "; cin >> maMH; cout << endl;
            cout << "       So tin chi: "; cin >> soTinChi; cout << endl;
            if (soTinChi != 12 && soTinChi != 6){
                cout << "       So tin chi LT: "; cin >> soTinChiLT; cout << endl;
                cout << "       So tin chi BT: "; cin >> soTinChiBT; cout << endl;
                cout << "       So tin chi TH: "; cin >> soTinChiTH; cout << endl;
            }
            MonHoc m(maMH, soTinChi, soTinChiLT, soTinChiBT, soTinChiTH);
            x.dsMonHoc.push_back(m);
            x.tongHP = m.soTinChiHP * x.soTienMotTin;
        }
        int danop;
        cout << "   Hoc phi da nop: "; cin >> danop; cout << endl;
        x.hocPhiDaNop = danop;
        dsHocVien.push_back(x);
    }

    cout << "Ban da nhap thanh cong!\n";
}

void second(){
    cout << "Ban da chon xuat ds sinh vien!\n";
    cout << "\n__________________________________________________________________\n";
    
    for (HocVien &x : dsHocVien){
        x.in();
        cout << "Chi tiet hoc phi cac mon hoc: \n";
        cout << " Ma MH         Loai gio        Khoi luong       hocphiphainop\n";
        for (MonHoc &m : x.dsMonHoc){
            cout << left << setw(15) << setfill(' ') << m.maMH;
            cout << left << setw(16) << setfill(' ') << m.loaiGio;
            cout << left << setw(17) << setfill(' ') << m.khoiLuong;
            cout << m.soTinChiHP * x.soTienMotTin; cout << endl;
        } 
        cout << "\n__________________________________________________________________\n";
    }

}
int main(){
    cout << "Nhap so sinh vien: "; cin >> n;
    while (1){
        cout << "Ho Minh Dung - 20235050 - 750829\n";
        cout << "**    CHUONG TRINH QUAN LY HOC PHI    **" << endl;
        cout << "**1. Nhap cac sinh vien va mon hoc     **" << endl;
        cout << "**2. In ds sinh vien va hoc phi cac mon**\n";
        cout << "**0. Thoat                             **\n";
        cout << "*****************************************\n";
        cout << "**         Nhap lua chon cua ban       **\n";
        
        string x; cin >> x;
        if (x == "1") first();
        else if (x == "2") second();
        else if (x == "0") break;
        else cout << "Lua chon khong hop le!\n";

        cout << "Bam phim bat ky de tiep tuc!";
        string tmp; cin >> tmp;
        system("clear");
    }
    cout << "Chuong trinh ket thuc\n";
}