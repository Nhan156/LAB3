#include <iostream>
#include <ctime>
#include <cstdlib>
# include <string> 
using namespace std;
 //1
 bool laSoNguyenTo(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void sapXepSoChan(int mang[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (mang[i] % 2 == 0 && mang[j] % 2 == 0 && mang[i] > mang[j]) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}
//3

void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void chenPhanTu(int arr[], int &n, int x) {
    int i = n - 1;
    while (i >= 0 && arr[i] > x) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = x;
    n++;
}
//4
void sapXeptangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int loaiBoTrungNhau(int arr[], int n) {
    int k = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[k]) {
            k++;
            arr[k] = arr[i];
        }
    }
    return k + 1;
}
//5
void deleteElementsFromArray(int arr[], int& N, int p, int n) {
    // Kiểm tra điều kiện đầu vào
    if (N <= 0 || p < 0 || n < 0) {
        cout << "Mảng không hợp lệ hoặc p, n không phải số nguyên dương." << endl;
        return;
    }

    // Xóa n phần tử từ vị trí p trong mảng
    if (p + n >= N) {
        // Nếu số phần tử cần xóa lớn hơn số phần tử còn lại sau vị trí p
        // thì chỉ xóa đến cuối mảng
        N = p;
    } else {
        // Nếu số phần tử cần xóa không vượt quá số phần tử còn lại sau vị trí p
        // thì dịch các phần tử từ vị trí p+n đến cuối mảng lên vị trí p
        for (int i = p; i < N - n; ++i) {
            arr[i] = arr[i + n];
        }
        N -= n;
    }

    // In mảng sau khi đã xóa phần tử
    cout << "Mảng A sau khi xóa phần tử: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//6

void insertArray(int arrA[], int arrB[], int N, int p) {
    // Tạo mảng tạm để chứa các phần tử sau khi chèn
    int tempArr[100]; // Giả sử mảng có tối đa 100 phần tử

    // Copy các phần tử của mảng A đến vị trí p vào mảng tạm
    for (int i = 0; i < p; ++i) {
        tempArr[i] = arrA[i];
    }

    // Chèn các phần tử của mảng B vào mảng tạm từ vị trí p
    for (int i = 0; i < N; ++i) {
        tempArr[p + i] = arrB[i];
    }

    // Copy các phần tử của mảng A từ vị trí p đến hết vào mảng tạm
    for (int i = p; i < N; ++i) {
        tempArr[N + i] = arrA[i];
    }

    // Copy các phần tử của mảng tạm vào mảng A
    for (int i = 0; i < 2 * N; ++i) {
        arrA[i] = tempArr[i];
    }
}
//7
// Hàm sắp xếp mảng thực theo thứ tự tăng dần
void sapXepTangDan(float arr[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm tìm phần tử có số lần xuất hiện nhiều nhất trong mảng
float timPhanTuXuatHienNhieuNhat(float arr[], int N) {
    // Sắp xếp mảng để dễ tìm phần tử xuất hiện nhiều nhất
    sapXepTangDan(arr, N);

    float mostFrequent = arr[0]; // Giả sử phần tử đầu tiên xuất hiện nhiều nhất
    int currentCount = 1; // Số lần xuất hiện của phần tử hiện tại
    int maxCount = 1; // Số lần xuất hiện nhiều nhất

    for (int i = 1; i < N; ++i) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

// Hàm kiểm tra và tìm vị trí của số thực x trong mảng
int timViTriSoThuc(float arr[], int N, float x) {
    for (int i = 0; i < N; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Hàm chèn số thực x vào mảng sao cho mảng vẫn tăng
void chenSoThucVaoMang(float arr[], int& N, float x) {
    int i = N - 1;
    while (i >= 0 && arr[i] > x) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = x;
    N++;
}
//8
struct NhanVien {
    int MaNV;
    string HoTen;
    string DiaChi;
    int CBQL;
};

NhanVien Nhap_thong_tin_nhan_vien() {
    NhanVien nv;
    cout << "Nhập mã nhân viên: ";
    cin >> nv.MaNV;
    cin.ignore(); // Loại bỏ ký tự newline trong buffer sau khi nhập MaNV
    cout << "Nhập họ tên nhân viên: ";
    getline(cin, nv.HoTen);
    cout << "Nhập địa chỉ nhân viên: ";
    getline(cin, nv.DiaChi);
    cout << "Nhập 1 nếu là cán bộ quản lý, 0 nếu không: ";
    cin >> nv.CBQL;
    return nv;
}

void in_ds_cbql(NhanVien danh_sach_nhan_vien[], int n) {
    cout << "\nDanh sách họ tên của các nhân viên là cán bộ quản lý:\n";
    for (int i = 0; i < n; i++) {
        if (danh_sach_nhan_vien[i].CBQL == 1) {
            cout << danh_sach_nhan_vien[i].HoTen << endl;
        }
    }
}
//9
struct NhanVien2 {
    int MaNV;
    string HoTen;
    string DiaChi;
    int CBQL;
};

NhanVien thong_tin_nhan_vien() {
    NhanVien nv;
    cout << "Nhập mã nhân viên: ";
    cin >> nv.MaNV;
    cin.ignore(); // Loại bỏ ký tự newline trong buffer sau khi nhập MaNV
    cout << "Nhập họ tên nhân viên: ";
    getline(cin, nv.HoTen);
    cout << "Nhập địa chỉ nhân viên: ";
    getline(cin, nv.DiaChi);
    cout << "Nhập 1 nếu là cán bộ quản lý, 0 nếu không: ";
    cin >> nv.CBQL;
    return nv;
}

void xoa_nhan_vien_khong_la_cbql(NhanVien danh_sach_nhan_vien[], int& n) {
    int i = 0;
    while (i < n) {
        if (danh_sach_nhan_vien[i].CBQL == 0) {
            for (int j = i; j < n - 1; j++) {
                danh_sach_nhan_vien[j] = danh_sach_nhan_vien[j + 1];
            }
            n--;
        } else {
            i++;
        }
    }
}
int main()
{
    cout << "BAI THI GIUA KI" << endl;
    int a;
    cout << "NHAP BAI BAN MUON THUC HIEN : ";
    cin >> a;
    switch (a)
    {
    case 1:
    {
          const int MAX_PHAN_TU = 10;
    int n;
    cout << "Nhap so luong phan tu trong mang (n <= " << MAX_PHAN_TU << "): ";
    cin >> n;

    while (n <= 0 || n > MAX_PHAN_TU) {
        cout << "So luong phan tu khong hop le. Nhap lai n (n <= " << MAX_PHAN_TU << "): ";
        cin >> n;
    }

    int mang[MAX_PHAN_TU];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> mang[i];
    }

    int tongDuong = 0;
    int soDuong = 0;
    int tongAm = 0;
    int soAm = 0;
    int soNguyenTo[MAX_PHAN_TU];
    int soLuongNguyenTo = 0;
    int soChan[MAX_PHAN_TU];
    int soLuongSoChan = 0;

    for (int i = 0; i < n; ++i) {
        int so = mang[i];
        if (so > 0) {
            tongDuong += so;
            soDuong++;
        } else if (so < 0) {
            tongAm += so;
            soAm++;
        }

        if (laSoNguyenTo(so)) {
            soNguyenTo[soLuongNguyenTo] = so;
            soLuongNguyenTo++;
        }

        if (so % 2 == 0) {
            soChan[soLuongSoChan] = so;
            soLuongSoChan++;
        }
    }

    if (soDuong > 0) {
        double trungBinhDuong = static_cast<double>(tongDuong) / soDuong;
        cout << "Trung binh cong cac so duong trong mang: " << trungBinhDuong << endl;
    } else {
        cout << "Khong co so duong trong mang" << endl;
    }

    if (soAm > 0) {
        double trungBinhAm = static_cast<double>(tongAm) / soAm;
        cout << "Trung binh cong cac so am trong mang: " << trungBinhAm << endl;
    } else {
        cout << "Khong co so am trong mang" << endl;
    }

    if (soLuongNguyenTo > 0) {
        cout << "Cac so nguyen to trong mang: ";
        for (int i = 0; i < soLuongNguyenTo; ++i) {
            cout << soNguyenTo[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Khong co so nguyen to trong mang" << endl;
    }

    if (soLuongSoChan > 0) {
        sapXepSoChan(soChan, soLuongSoChan);
        cout << "Cac so chan trong mang sau khi sap xep: ";
        for (int i = 0; i < soLuongSoChan; ++i) {
            cout << soChan[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Khong co so chan trong mang" << endl;
    }

    return 0;
}
    
            
    break;
    case 2:
    {

    
            const int MAX_PHAN_TU = 100;
        int n;
        cout << "Nhap so luong phan tu trong mang A (n <= " << MAX_PHAN_TU << "): ";
        cin >> n;

        while (n <= 0 || n > MAX_PHAN_TU) {
            cout << "So luong phan tu khong hop le. Nhap lai n (n <= " << MAX_PHAN_TU << "): ";
            cin >> n;
        }

        int A[MAX_PHAN_TU];
        for (int i = 0; i < n; ++i) {
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            cin >> A[i];
        }

        int x;
        cout << "Nhap so nguyen x: ";
        cin >> x;

        // Kiểm tra x có trong mảng A hay không
        bool found = false;
        int countX = 0;

        for (int i = 0; i < n; ++i) {
            if (A[i] == x) {
                found = true;
                countX++;
            }
        }

        if (found) {
            cout << x << " co xuat hien trong mang A " << countX << " lan." << endl;

            // Xóa toàn bộ các phần tử x khỏi mảng A
            int i = 0;
            int j = 0;
            while (i < n) {
                if (A[i] != x) {
                    A[j] = A[i];
                    j++;
                }
                i++;
            }

            n = j;

            cout << "Mang A sau khi xoa cac phan tu " << x << ": ";
            for (int i = 0; i < n; ++i) {
                cout << A[i] << " ";
            }
            cout << endl;
        } else {
            cout << x << " khong xuat hien trong mang A." << endl;
        }

        return 0;
    }

    break;
    case 3:{
            const int MAX_PHAN_TU = 100;
        int n;
        cout << "Nhap so luong phan tu trong mang A (n <= " << MAX_PHAN_TU << "): ";
        cin >> n;

        while (n <= 0 || n > MAX_PHAN_TU) {
            cout << "So luong phan tu khong hop le. Nhap lai n (n <= " << MAX_PHAN_TU << "): ";
            cin >> n;
        }

        int A[MAX_PHAN_TU];
        for (int i = 0; i < n; ++i) {
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            cin >> A[i];
        }

        int luaChon;
        cout << "Chon che do sap xep: " << endl;
        cout << "1. Tang dan" << endl;
        cout << "2. Giam dan" << endl;
        cout << "Lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                sapXepTangDan(A, n);
                break;
            case 2:
                sapXepGiamDan(A, n);
                break;
            default:
                cout << "Lua chon khong hop le. Sap xep tang dan mac dinh." << endl;
                sapXepTangDan(A, n);
                break;
        }

        cout << "Mang A sau khi sap xep: ";
        for (int i = 0; i < n; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;

        int x;
        cout << "Nhap so nguyen x can chen: ";
        cin >> x;

        chenPhanTu(A, n, x);

        cout << "Mang A sau khi chen " << x << " sao cho giu nguyen thu tu: ";
        for (int i = 0; i < n; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;

        return 0;
    }
    
            break ; 
            case 4: {

                srand(time(0));

        int n;
        cout << "Nhap so luong phan tu trong mang (n > 0): ";
        cin >> n;

        while (n <= 0) {
            cout << "So luong phan tu khong hop le. Nhap lai n (n > 0): ";
            cin >> n;
        }

        int A[100];
        for (int i = 0; i < n; ++i) {
            A[i] = rand() % 100 + 1; // Giá trị ngẫu nhiên từ 1 đến 100
        }

        cout << "Mang truoc khi sap xep: ";
        for (int i = 0; i < n; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;

        sapXepTangDan(A, n);

        cout << "Mang sau khi sap xep tang dan: ";
        for (int i = 0; i < n; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;

        int k = loaiBoTrungNhau(A, n);

        cout << "Mang sau khi loai bo cac phan tu trung nhau: ";
        for (int i = 0; i < k; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;

        return 0;
    }
        break;
        case 5: {
            int N;
        cout << "Nhập số phần tử của mảng A[N]: ";
        cin >> N;

        int A[100]; // Giả sử mảng có tối đa 100 phần tử
        for (int i = 0; i < N; ++i) {
            int element;
            cout << "Nhập phần tử thứ " << i << ": ";
            cin >> element;
            if (element <= 0) {
                cout << "Phải nhập số nguyên dương." << endl;
                return 1;
            }
            A[i] = element;
        }

        int p, n;
        cout << "Nhập vị trí bắt đầu xóa (p): ";
        cin >> p;
        cout << "Nhập số phần tử cần xóa (n): ";
        cin >> n;

        deleteElementsFromArray(A, N, p, n);

        return 0;
    }
    break;
    case 6: {
         int N;
    cout << "Nhập số phần tử của mảng A[N] và B[N]: ";
    cin >> N;

    int A[200]; // Giả sử mảng A có tối đa 200 phần tử (đủ chứa cả hai mảng)
    int B[100]; // Giả sử mảng B có tối đa 100 phần tử

    cout << "Nhập các phần tử của mảng A:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << "Nhập các phần tử của mảng B:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int p;
    cout << "Nhập vị trí cần chèn mảng B vào mảng A (p): ";
    cin >> p;

    if (p < 0 || p > N) {
        cout << "Vị trí không hợp lệ." << endl;
        return 1;
    }

    insertArray(A, B, N, p);

    // In mảng A sau khi đã chèn mảng B vào vị trí p
    cout << "Mảng A sau khi chèn mảng B vào vị trí p:" << endl;
    for (int i = 0; i < 2 * N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
    break;
    case 7 : { 
         int N;
    cout << "Nhap so phan tu cua mang: ";
    cin >> N;

    float a[100]; // Giả sử mảng có tối đa 100 phần tử

    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Bước b: Sắp xếp mảng theo thứ tự tăng dần
    sapXepTangDan(a, N);

    // Bước c: Tìm và in phần tử xuất hiện nhiều nhất trong mảng
    float phanTuXuatHienNhieuNhat = timPhanTuXuatHienNhieuNhat(a, N);
    cout << "Phan tu xuat hien nhieu nhat trong mang: " << phanTuXuatHienNhieuNhat << endl;

    // Bước d: Kiểm tra và tìm vị trí số thực x trong mảng
    float x;
    cout << "Nhap so thuc x can kiem tra hoac chen: ";
    cin >> x;

    int viTri = timViTriSoThuc(a, N, x);
    if (viTri != -1) {
        cout << "So thuc x xuat hien tai vi tri: " << viTri << endl;
    } else {
        // Chèn số thực x vào mảng sao cho mảng vẫn tăng
        chenSoThucVaoMang(a, N, x);
        cout << "Mang sau khi chen so thuc x vao mang sao cho mang van tang:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
    break;
    case 8 : { 
         int n;
    cout << "Nhập số lượng nhân viên: ";
    cin >> n;
    cin.ignore(); // Loại bỏ ký tự newline trong buffer sau khi nhập n

    NhanVien danh_sach_nhan_vien[n];

    cout << "Nhập thông tin của các nhân viên:\n";
    for (int i = 0; i < n; i++) {
        danh_sach_nhan_vien[i] = Nhap_thong_tin_nhan_vien();
    }

    in_ds_cbql(danh_sach_nhan_vien, n);

    return 0;
}
    
        default: {
            cout << "khong co bai ban chon" << endl;
            break;
        }
    }
}
