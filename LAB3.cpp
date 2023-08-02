#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
//1
int soNhoHon(int a, int b) {
    return (a < b) ? a : b;
}
//2
// Hàm tính USCLN
int uscln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tính BSCNN
int bscnn(int a, int b) {
    return (a * b) / uscln(a, b);
}
//3
// Hàm tính giá trị n!
int giaiThua(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * giaiThua(n - 1);
    }
}
//4
// Hàm tính (X)^n không dùng đệ quy
double mu(double x, int n) {
    double result = 1.0;
    int abs_n = abs(n); // Lấy giá trị tuyệt đối của n để xử lý trường hợp n < 0

    while (abs_n > 0) {
        if (abs_n % 2 == 1) {
            result *= x;
        }
        x *= x;
        abs_n /= 2;
    }

    return (n < 0) ? 1.0 / result : result;
}
//5
// Hàm tính giai thừa n!
unsigned long long tinhGiaiThua(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        unsigned long long ketQua = 1;
        for (int i = 2; i <= n; i++) {
            ketQua *= i;
        }
        return ketQua;
    }
}

// Hàm tính tổ hợp C(n, k) = n! / (k! * (n - k)!)
unsigned long long tinhToHop(int n, int k) {
    if (k < 0 || k > n) {
        cout << "Không thể tính. Vui lòng nhập lại k sao cho 0 <= k <= n." << endl;
        return 0;
    } else {
        unsigned long long tuSo = tinhGiaiThua(n);
        unsigned long long mauSo = tinhGiaiThua(k) * tinhGiaiThua(n - k);
        return tuSo / mauSo;
    }
}
//6

// Hàm tính chu vi hình chữ nhật
double tinhChuVi(double chieuDai, double chieuRong) {
    return 2 * (chieuDai + chieuRong);
}

// Hàm tính diện tích hình chữ nhật
double tinhDienTich(double chieuDai, double chieuRong) {
    return chieuDai * chieuRong;
}

// Hàm vẽ hình chữ nhật
void veHinhChuNhat(int chieuDai, int chieuRong) {
    for (int i = 0; i < chieuRong; i++) {
        for (int j = 0; j < chieuDai; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
//7
// Hàm kiểm tra một số có phải là số hoàn thiện hay không
bool laSoHoanThien(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

// Hàm in tất cả các số hoàn thiện nhỏ hơn số cho trước
void inSoHoanThienNhoHon(int num) {
    cout << "Cac so hoan thien nho hon " << num << " la: ";
    for (int i = 1; i < num; i++) {
        if (laSoHoanThien(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}
//8
// Hàm tính số tờ tiền của từng loại để tổng bằng số tiền cho trước
void tinhSoToTien(int soTien, int toTien[]) {
    int loaiTien[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int n = sizeof(loaiTien) / sizeof(loaiTien[0]);

    for (int i = 0; i < n; i++) {
        toTien[i] = soTien / loaiTien[i];
        soTien -= toTien[i] * loaiTien[i];
    }
}

// Hàm tính tổng số tờ tiền trong phương án
int tinhTongSoToTien(int toTien[]) {
    int tongSoTo = 0;
    int loaiTien[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int n = sizeof(loaiTien) / sizeof(loaiTien[0]);

    for (int i = 0; i < n; i++) {
        tongSoTo += toTien[i];
    }
    return tongSoTo;
}
//9
// Hàm đảo vị trí các chữ số trong một số nguyên
int DaoKiSo(int &n) {
    int daoNguoc = 0;

    while (n != 0) {
        int digit = n % 10;
        daoNguoc = daoNguoc * 10 + digit;
        n /= 10;
    }

    n = daoNguoc;
}
int main()
{
    cout << "BAI TAP LAB 3" << endl;
    int a;
    cout << "NHAP BAI BAN MUON THUC HIEN : ";
    cin >> a;
    switch (a)
    {
    case 1:
    {

            int soNguyen1, soNguyen2;
        cout << "Nhập số nguyên thứ nhất: ";
        cin >> soNguyen1;
        cout << "Nhập số nguyên thứ hai: ";
        cin >> soNguyen2;

        int nhoNhatHaiSo = soNhoHon(soNguyen1, soNguyen2);
        cout << "Số nhỏ hơn trong hai số là: " << nhoNhatHaiSo << endl;

        int soNguyen3;
        cout << "Nhập số nguyên thứ ba: ";
        cin >> soNguyen3;

        int nhoNhatBaSo = soNhoHon(nhoNhatHaiSo, soNguyen3);
        cout << "Số nhỏ hơn trong ba số là: " << nhoNhatBaSo << endl;

        return 0;
    }
    break;
    case 2:
    {
            int a, b;
        cout << "Nhập số nguyên dương a: ";
        cin >> a;
        cout << "Nhập số nguyên dương b: ";
        cin >> b;

        int uscln_ab = uscln(a, b);
        int bscnn_ab = bscnn(a, b);

        cout << "Ước số chung lớn nhất của " << a << " và " << b << " là: " << uscln_ab << endl;
        cout << "Bội số chung nhỏ nhất của " << a << " và " << b << " là: " << bscnn_ab << endl;

        return 0;
    }
    break;
    case 3:
    {
            int n;
        cout << "Nhập số nguyên dương n (> 1): ";
        cin >> n;

        if (n <= 1) {
            cout << "Vui lòng nhập số nguyên dương n (> 1)." << endl;
        } else {
            int giaTriGiaiThua = giaiThua(n);
            cout << n << "! = " << giaTriGiaiThua << endl;
        }

        return 0;
    }
    break;
    case 4:
    {
            double x;
        int n;
        cout << "Nhập giá trị x: ";
        cin >> x;
        cout << "Nhập số nguyên n: ";
        cin >> n;

        double ketQua = mu(x, n);
        cout << "(" << x << ")^" << n << " = " << ketQua << endl;

        return 0;
    }

    break;
    case 5: {
        int n, k;
        cout << "Nhập số nguyên dương n: ";
        cin >> n;
        cout << "Nhập số nguyên k (0 <= k <= n): ";
        cin >> k;

        unsigned long long ketQua = tinhToHop(n, k);
        cout << "C(" << n << ", " << k << ") = " << ketQua << endl;

        return 0;
    }

    break;
    case 6 :
    {
            double chieuDai, chieuRong;
        cout << "Nhap chieu dai hinh chu nhat: ";
        cin >> chieuDai;
        cout << "Nhap chieu rong hinh chu nhat: ";
        cin >> chieuRong;

        double chuVi = tinhChuVi(chieuDai, chieuRong);
        double dienTich = tinhDienTich(chieuDai, chieuRong);

        cout << "Chu vi cua hinh chu nhat la: " << chuVi << endl;
        cout << "Dien tich cua hinh chu nhat la: " << dienTich << endl;

        cout << "Hinh chu nhat: " << endl;
        veHinhChuNhat(chieuDai, chieuRong);

        return 0;
    }
    break;
    case 7:
    {
            int num;
        cout << "Nhap mot so nguyen duong: ";
        cin >> num;

        if (num < 1) {
            cout << "Vui long nhap mot so nguyen duong." << endl;
        } else {
            if (laSoHoanThien(num)) {
                cout << num << " la so hoan thien." << endl;
            } else {
                cout << num << " khong la so hoan thien." << endl;
            }

            inSoHoanThienNhoHon(num);
        }

        return 0;
    }
    break;
    case 8 : {
            int soTien;
        cout << "Nhap so tien: ";
        cin >> soTien;

        int toTien[6] = {0}; // Khởi tạo mảng số tờ tiền ban đầu là 0

        tinhSoToTien(soTien, toTien);
        int tongSoTo = tinhTongSoToTien(toTien);

        cout << "Phuong an chi tieu: " << endl;
        int loaiTien[] = {50000, 20000, 10000, 5000, 2000, 1000};
        int n = sizeof(loaiTien) / sizeof(loaiTien[0]);

        for (int i = 0; i < n; i++) {
            cout << toTien[i] << " to " << loaiTien[i] << " VND" << endl;
        }

        cout << "Tong so to tien: " << tongSoTo << endl;

        return 0;
    }
    break;
    case 9: {
        int n;
        cout << "Nhap mot so nguyen duong: ";
        cin >> n;

        if (n < 1) {
            cout << "Vui long nhap mot so nguyen duong." << endl;
        } else {
            cout << "Truoc khi dao ki so: " << n << endl;
            DaoKiSo(n);
            cout << "Sau khi dao ki so: " << n << endl;
        }

        return 0;
    }
    break;
    case 10 : {
            int soLuongCauHoiHome = 0;
        int soLuongCauHoiStudy = 0;

        // Nhap cau hoi cho chu de "Home/Accommodation"
        cout << "Nhap cac cau hoi cho chu de \"Home/Accommodation\" (nhap 'end' de ket thuc):" << endl;
        string cauHoi;
        while (true) {
            getline(cin, cauHoi);
            if (cauHoi == "end") {
                break;
            }
            soLuongCauHoiHome++; // Tang so luong cau hoi cua chu de "Home/Accommodation"
        }

        // Nhap cau hoi cho chu de "Study"
        cout << "Nhap cac cau hoi cho chu de \"Study\" (nhap 'end' de ket thuc):" << endl;
        while (true) {
            getline(cin, cauHoi);
            if (cauHoi == "end") {
                break;
            }
            soLuongCauHoiStudy++; // Tang so luong cau hoi cua chu de "Study"
        }

        // In ra ket qua thong ke so luong cau hoi theo tung chu de
        cout << "Ket qua thong ke so luong cau hoi theo tung chu de:" << endl;
        cout << "Chu de Home/Accommodation, So luong cau hoi: " << soLuongCauHoiHome << endl;
        cout << "Chu de Study, So luong cau hoi: " << soLuongCauHoiStudy << endl;

        return 0;
    }
        
        default: {
            cout << "khong co bai ban chon" << endl;
            break;
        }
    
}
}
