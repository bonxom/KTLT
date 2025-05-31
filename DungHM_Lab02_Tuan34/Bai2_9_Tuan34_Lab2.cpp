/* Bai 2.9 Tính hàm sigmoid
Dưới đây cung cấp đoạn code đơn giản để tính hàm sigmoid theo công thức trực tiếp.
Hãy viết hàm tính xấp xỉ sigmoid(x) đến độ chính xác  10−6  và có tốc độ nhanh hơn ít nhất 30% so với code đơn giản.
Gợi ý: sử dụng kỹ thuật "chuẩn bị trước" như trong slide.
Ho Minh Dung - 20235050 - 750829 - Tuan 34 */
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
/*****************
# YOUR CODE HERE #
*****************/
vector<double> table_50;
//# h�m chuan bi du lieu
void precalc() {
    /*****************
    # YOUR CODE HERE #
    *****************/
    //Sigmod fuction for x -> [-5, 5]
    const double h_50 = 0.005; //Do chinh xac
    const int n_50 = 2001; // Kich thuoc Table
    table_50.resize(n_50);
    for (int i_50 = 0; i_50 < n_50; i_50++) {
        double xi_50 = -5.0 + i_50 * h_50;
        table_50[i_50] = 1.0 / (1.0 + exp(-xi_50)); //slow sigmod
    }
}

/*Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x_50) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    const double scale_50 = 200.0; // 1/h = 1/0.005
    double idx_50 = (x_50 + 5.0) * scale_50; // Ánh xạ x đến table
    int i_50 = (int)idx_50;
    if (i_50 < 0) return 0.0;          // x <= -5
    else if (i_50 >= 2000) return 1.0; // x >= 5
    else {
        double fraction_50 = idx_50 - i_50;   // Phần thập phân
        return table_50[i_50] + (table_50[i_50 + 1] - table_50[i_50]) * fraction_50;
    }
}

//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//#  printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;

    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Ho Minh Dung - 5050\n");
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));
    
    if (is_correct(a, b) && (slow/fast > 1.3)) {
        printf("Correct answer! Your code is faster\n");
    } else {
        printf("Wrong answer or your code is not fast enough!\n");
    }
    
    return 0;
}
/*Ho Minh Dung - 20235050 - 750829 - Tuan 34 */

