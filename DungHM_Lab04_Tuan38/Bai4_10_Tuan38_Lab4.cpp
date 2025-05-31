/* Bai 4.10 Search Engine
Xây dựng một máy tìm kiếm (search engine) đơn giản.
Cho  N văn bản và  Q truy vấn. 
Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất.
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/
#include <bits/stdc++.h>
using namespace std;

int n_50, q_50;
//map lưu first = word, second = frequency of word của 1 văn bản ở index tương ứng
vector<unordered_map<string, int>> dictionary_50;
ifstream inFile_50("input.txt"); //file input

//xử lý đầu vào văn bản
void inputDOC(){
    inFile_50 >> n_50;
    inFile_50.ignore();
    for (int i_50 = 0; i_50 < n_50; i_50++){
        string s_50; getline(inFile_50, s_50);
        stringstream ss_50(s_50);
        string word_50;
        unordered_map<string, int> mp_50;
        //tách lấy từng word
        while (getline(ss_50, word_50, ',')) {
            mp_50[word_50]++;
        }
        dictionary_50.push_back(mp_50);        
    }
    //debug
    // for (auto &x_50 : dictionary_50){
    //     cout << "doc" << endl;
    //     for (auto &y_50 : x_50){
    //         cout << y_50.first << " " << y_50.second << endl;
    //     }
    // }
}

//số lần xuất hiện từ t_50 trong văn bản d_50
inline int f(string t_50, int d_50){
    if (dictionary_50[d_50].count(t_50) == 0) return 0;
    //cout << t_50 << " appear time in doc " << d_50 + 1 << " is " << dictionary_50[d_50][t_50] << endl; 
    return dictionary_50[d_50][t_50];
}
//giá trị lớn nhất của f(t_50, d_50) trong văn bản d_50
int maxf(int d_50){
    int res_50 = 0;
    for (auto &x_50 : dictionary_50[d_50]){
        res_50 = max(x_50.second, res_50);
    }
    return res_50;
}
//số văn bản chứa từ t_50
int df(string t_50){
    int res_50 = 0;
    for (int i_50 = 0; i_50 < n_50; i_50++){
        if (dictionary_50[i_50].count(t_50)){
            res_50++;
            //cout << i_50 + 1 << endl;
        }
    }
    //cout << "count of doc include " << t_50 << " is " << res_50 << endl;
    return res_50;
}
//tính score của word t ứng với văn bản d
inline double searchQ(string t_50, int d_50){
    if (f(t_50, d_50) == 0) return 0;
    double TF_50 = 0.5 + 0.5 * f(t_50, d_50)/maxf(d_50);
    double IDF_50 = log2((double)n_50 / df(t_50));
    return TF_50 * IDF_50;
}
//xử lý tìm kiếm
/*Ho Minh Dung - 20235050 - 750829 - Tuan 38*/
void inputQuerry(){
    inFile_50 >> q_50;
    inFile_50.ignore();
    for (int i_50 = 0; i_50 < q_50; i_50++){
        string s_50; getline(inFile_50, s_50);
        stringstream ss_50(s_50);
        string word_50;
        map<string, int> mp_50;
        //lưu các word của truy vấn
        vector<string> words_50;
        while (getline(ss_50, word_50, ',')) {
            words_50.push_back(word_50);
        }
        int res_50 = 0;
        double score_50 = 0;
        for (int i_50 = 0; i_50 < n_50; i_50++){
            double cur_score_50 = 0;
            for (string &x_50 : words_50){
                cur_score_50 += searchQ(x_50, i_50);
            }
            //cout << "search " << i_50 + 1 << " with score " << cur_score_50 << endl;
            //nếu score lớn hơn score đang có thì thay
            if (cur_score_50 > score_50){
                //cout << "new score\n";
                score_50 = cur_score_50;
                res_50 = i_50;
            }
        }
        cout << res_50 + 1 << endl;
    }
}
int main(){
    cout << "Ho Minh Dung - 5050\n";
    inputDOC();
    inputQuerry();
}