#include <bits/stdc++.h>
using namespace std;

int n;

struct MiengDat{
    string ma;
    int gia;
    string hinh;
    double dienTich;
    double giamGia;
    double tongGia;
    double datCoc;
    //hinh vuong
    double canh;
    //HCN
    double dai, rong;
    //tam giac
    double day, cao;
    //hinh thang
    double lon, nho;
    MiengDat(){}
    MiengDat(string ma, int gia, string hinh){
        this->ma = ma;
        this->gia = gia;
        this->hinh = hinh;
        giamGia = 0;
        if (ma == "MD001") datCoc = 0.7;
        else if (ma == "MD002") datCoc = 0.5;
        else if (ma == "MD003") datCoc = 0.3;
    }

    void in(){
        cout << "\t\tDien tich: " << dienTich << endl;
        cout << "\t\tThanh tien: " << dienTich * gia << endl;
        cout << "\t\tTien dat coc: " << dienTich * gia * datCoc << endl;
        cout << "\t\tGiam gia: " << dienTich * gia * giamGia << endl;
    }

    void hinhVuong(double canh){
        this->canh = canh;
        dienTich = canh*canh;
    }
    void tamGiac(double day, double cao){
        this->day = day;
        this->cao = cao;
        dienTich = (day * cao) / 2.0;
        giamGia = 0.1;
    }
    void hinhThang(double lon, double nho, double cao){
        this->lon = lon;
        this->nho = nho;
        dienTich = (lon + nho) * cao / 2.0;
        giamGia = 0.1;
    }
    void hinhChuNhat(double dai, double rong){
        this->dai = dai;
        this->rong=  rong;
        dienTich = dai * rong;
    }
    
};

struct CongTy{
    string name, diaChi;
    int soMiengDat;
    vector<MiengDat> dsMiengDat;
    CongTy(){}
    CongTy(string name, string diaChi){
        this->name = name;
        this->diaChi = diaChi;
        soMiengDat = 0;
    }

    double dongiaTB(){
        double res = 0;
        for (MiengDat &x : dsMiengDat){
            res += x.gia;
        }
        res /= dsMiengDat.size();
        return res;
    }
    double tongDT(){
        double res = 0;
        for (MiengDat &x : dsMiengDat){
            res += x.dienTich;
        }
        return res;
    }
    double tongThanhTien(){
        double res = 0;
        for (MiengDat &x : dsMiengDat){
            res += x.gia * x.dienTich * (1 - x.giamGia);
        }
        return res;
    }
    double tongDatCoc(){
        double res = 0;
        for (MiengDat &x : dsMiengDat){
            res += x.gia * x.dienTich * x.datCoc;
        }
        return res;
    }
    double tongGiamGia(){
        double res = 0;
        for (MiengDat &x : dsMiengDat){
            res += x.gia * x.dienTich * x.giamGia;
        }
        return res;
    }
    void in(){
        cout << "\t\tTen Cong ty: " << name << endl;
        cout << "\t\tDia chi: " << diaChi << endl;
        cout << "\t\tso Mieng dat: " << soMiengDat << endl;
        cout << "\t\tDon gia trung binh: " << dongiaTB() << endl;
        cout << "\t\tTong dien tich: " << tongDT() << endl;
        cout << "\t\tTong thanh tien: " << tongThanhTien() << endl;
        cout << "\t\tTong dat coc: " << tongDatCoc() << endl;
        cout << "\t\tTong giam gia: " << tongGiamGia() << endl;

        cout << "\t\t\t\t\t Chi tiet cac Mieng dat:\n";
        cout << "MaMD    Hinh dang      don gia     dien tich       Thanh tien      Giam gia       Dat coc\n";
        for (MiengDat &x : dsMiengDat){
            cout << left << setw(8) << setfill(' ') << x.ma;
            cout << left << setw(15) << setfill(' ') << x.hinh;
            cout << left << setw(12) << setfill(' ') << x.gia;
            cout << left << setw(16) << setfill(' ') << x.dienTich;
            cout << left << setw(16) << setfill(' ') << x.dienTich * x.gia * (1- x.giamGia);
            cout << left << setw(15) << setfill(' ') << x.dienTich * x.gia * x.giamGia;
            cout << x.dienTich * x.gia * (1 - x.giamGia) * x.datCoc << endl;
        }

        cout << endl << endl;
    }
};

vector <CongTy> dsCongTy;

void first(){
    cout << "\nBan da chon nhap MIENG DAT VA DO DAI !\n";
    for (int i = 1; i <= n; i++){
        string name, diaChi;
        int soMiengDat;
        cout << "Nhap thong tin Cong ty " << i << " :\n";
        cout << "\tTen Cong ty: "; cin.ignore(); getline(cin, name); cout << endl;
        cout << "\tDia chi Cong ty: "; getline(cin, diaChi); cout << endl;
        cout << "\tSo mieng dat: "; cin >> soMiengDat; cout << endl;
        cout << "\tNhap danh sach cac mieng dat: \n";
        CongTy x(name, diaChi);
        for (int q = 1; q <= soMiengDat; q++){
            string ma;
            int gia;
            string hinh;
            cout << "\tMa mieng dat thu (MD001, MD002, MD003) " << q << ": "; cin >> ma; cout << endl;
            cout << "\t\tDon gia theo m^2: "; cin >> gia; 
            cout << "\t\tMieng dat hinh (Vuong, Thang, Tamgiac, HCNhat): "; cin >> hinh; cout << endl;
            MiengDat md(ma, gia, hinh);
            if (hinh == "Vuong"){
                double a;
                cout << "\t\tCanh hinh vuong: "; cin >> a; cout << endl;
                md.hinhVuong(a);
            }
            else if (hinh == "Thang"){
                double cao, nho, lon;
                cout << "\t\tDay nho: "; cin >> nho ;cout << endl;
                cout << "\t\tDay lon: "; cin >> lon; cout << endl;
                cout << "\t\tChieu cao: "; cin >> cao; cout << endl;
                md.hinhThang(lon, nho, cao);
            }
            else if (hinh == "HCNhat"){
                double dai, rong;
                cout << "\t\tChieu dai: "; cin >> dai; cout << endl;
                cout << "\t\tChieu rong: "; cin >> rong; cout<< endl;
                md.hinhChuNhat(dai, rong);
            }
            else if (hinh == "Tamgiac"){
                double cao, day;
                cout << "\t\tChieu cao: "; cin >> cao; cout << endl;
                cout << "\t\tCanh day: "; cin >> day; cout << endl;
                md.tamGiac(day, cao);
            }
            x.dsMiengDat.push_back(md);
            md.in();
        }
        dsCongTy.push_back(x);
    }

    cout << "Ban da nhap thanh cong!\n";
}

void second(){
    cout << "Ban da chon IN RA MIENG DAT !\n";
    for (CongTy &x : dsCongTy){
        x.in();
    }
}

int main(){
    cout << "Ho Minh Dung - 5050 - IT3040 - 20242 - Tuan 40 - 750829\n";
    cout << "Nhap Thong tin so Cong ty BDS: "; cin >> n;
    while (1){
        cout << "Ho Minh Dung - 5050 - IT3040 - 20242 - Tuan 40 - 750829\n";
        cout << "**    CHUONG TRINH QUAN LY CONG TY BAT DONG SAN    **\n";
        cout << "**1. Nhap THONG TIN CONG TY        **\n";
        cout << "**2. IN KET QUA DIEN TICH MIENG DAT**\n";
        cout << "**0. Thoat                         **\n";
        cout << "*************************************\n";
        cout << "**      Nhap lua chon cua ban      **\n";
        string x; cin >> x;
        if (x == "1") first();
        else if (x == "2") second();
        else if (x == "0") break;
        else cout << "Ban da nhap that bai!\n";

        cout << "Bam phim bat ky de tiep tuc!\n";
        string tmp; cin >> tmp;
        system ("clear");
    }
}
