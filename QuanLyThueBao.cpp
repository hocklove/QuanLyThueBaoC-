using namespace std;
#include <iostream>
#include <string.h>
#include <conio.h>
#define SIZE 100

struct NgayThangNam
{
	int day, month, year;
};

struct ThueBao
{
	int ma_thue_bao;
	char ten_thue_bao[35];
	NgayThangNam ngay_dang_ky;
	char so_dien_thoai[11];
	char loai_thue_bao[20];
	int thoi_gian_goi_noi_mang, thoi_gian_goi_ngoai_mang;
};

void Menu()
{
	cout << "\n==============MENU==============" << endl;
	cout << "a. Nhap thong tin cac thue bao. " << endl;
	cout << "b. Xuat thong tin cac thue bao. " << endl;
	cout << "c. Them mot thue bao vao danh sach. " << endl;
	cout << "d. Sap xep danh sach cac thue bao theo ma thue bao. " << endl;
	cout << "e. Tim thue bao theo ho ten chu thue bao. " << endl;
	cout << "f. Xuat cac thue bao theo loai (Loai do nguoi dung chon). " << endl;
	cout << "g. Xuat cac thue bao dang ky sau nam 2010. " << endl;
	cout << "h. Tinh cuoc moi thue bao biet gia cuoc goi noi mang la 1500d, ngoai mang 3000d. " << endl;
	cout << "i. Dem so luong thue bao tra truoc. " << endl;
	cout << "0. Thoat chuong trinh. " << endl;
	cout << "===============END===============" << endl;
}

void deleteEnter(char x[])
{
    size_t len = strlen(x);
    if(x[len - 1] == '\n')
    {
        x[len - 1] = '\0';
    }
}

void nhapPhimBatKy()
{
    cout << "Nhap phim bat ky de tiep tuc!" << endl;
    getch();
}

void nhapLuaChon(char &select)
{
	cout << "Vui long chon mot cong viec: ";
	fflush(stdin);
	cin >> select;
}

void soLuongThueBao(int &n)
{
    do
    {
        cout << "Nhap so luong thue bao: ";
        cin >> n;
    } while (n < 0);
    
}

void nhapNgayThangNam(NgayThangNam &date)
{
    cin >> date.day >> date.month >> date.year;
}

void displayNgayThangNam(NgayThangNam date)
{
    cout << date.day << "/" << date.month << "/" << date.year << endl;
}

void nhapMotThueBao(ThueBao &tb)
{
    cout << "- Nhap ma thue bao: ";
    cin >> tb.ma_thue_bao;
    cout << "- Nhap ten thue bao: ";
    fflush(stdin); fgets(tb.ten_thue_bao, sizeof(tb.ten_thue_bao), stdin); deleteEnter(tb.ten_thue_bao);
    cout << "- Nhap ngay dang ky: ";
    nhapNgayThangNam(tb.ngay_dang_ky);
    cout << "- Nhap so dien thoai: ";
    fflush(stdin); fgets(tb.so_dien_thoai, sizeof(tb.so_dien_thoai), stdin); deleteEnter(tb.so_dien_thoai);
    cout << "- Nhap loai thue bao: ";
    fflush(stdin); fgets(tb.loai_thue_bao, sizeof(tb.loai_thue_bao), stdin); deleteEnter(tb.loai_thue_bao);
    cout << "- Nhap thoi gian goi noi mang: ";
    cin >> tb.thoi_gian_goi_noi_mang;
    cout << "- Nhap thoi gian goi ngoai mang: ";
    cin >> tb.thoi_gian_goi_ngoai_mang;
}

void xuatThongTinMotThueBao(ThueBao tb)
{
    cout << "- Ma thue bao: " << tb.ma_thue_bao << endl;
    cout << "- Ho ten thue bao: ";
    puts(strupr(tb.ten_thue_bao));
    cout << "- Ngay dang ky: ";
    displayNgayThangNam(tb.ngay_dang_ky);
    cout << "- So dien thoai: ";
    puts(tb.so_dien_thoai);
    cout << "- Loai thue bao: ";
    puts(strupr(tb.loai_thue_bao));
    cout << "- Thoi gian goi noi mang: " << tb.thoi_gian_goi_noi_mang << " phut" << endl;
    cout << "- Thoi gian goi ngoai mang: " << tb.thoi_gian_goi_ngoai_mang << " phut" << endl;
}

void nhapDanhSachThueBao(ThueBao ds[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "STT: " << i + 1 << endl;
        nhapMotThueBao(ds[i]);
    }
}

void xuatDanhSachCacThueBao(ThueBao ds[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "STT: " << i + 1 << endl;
        xuatThongTinMotThueBao(ds[i]);
    }
}

void themMotThueBao(ThueBao ds[], int &n)
{
    n += 1;
    nhapMotThueBao(ds[n - 1]);
}

void sapXepDanhSach(ThueBao ds[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n - 1; j++)
        {
            ThueBao temp = ds[i];
            ds[i] = ds[j];
            ds[j] = temp;
        }
    }
}

void timThueBao(ThueBao ds[], int n)
{
    int flag = 0;
    char ten_thue_bao[35];
    cout << "-> Nhap ho va ten chu thue bao can tim: ";
    fflush(stdin); fgets(ten_thue_bao, sizeof(ten_thue_bao), stdin); deleteEnter(ten_thue_bao);
    for(int i = 0; i < n; i++)
    {
        if(strcmp(strupr(ds[i].ten_thue_bao),strupr(ten_thue_bao)) == 0)
        {
            xuatThongTinMotThueBao(ds[i]);
            flag ++;
        }
    }
    if(flag == 0)
    {
        cout << "Khong tim thay thue bao nao!\n" << endl;
    }
}

void xuatThueBaoTheoLoai(ThueBao ds[], int n)
{
    char loai_thue_bao[20];
    int flag = 0;
    cout << "-> Nhap loai thue bao can hien thi: ";
    fflush(stdin); fgets(loai_thue_bao, sizeof(loai_thue_bao), stdin); deleteEnter(loai_thue_bao);
    for(int i = 0; i < n; i++)
    {
        if(strcmp(strupr(ds[i].loai_thue_bao), strupr(loai_thue_bao)) == 0)
        {
            xuatThongTinMotThueBao(ds[i]);
            flag ++;
        }
    }
    if(flag == 0)
    {
        cout << "Khong co thue bao nao de hien thi!\n";
    }
}

void cacThueBaoDangKiSau2010(ThueBao ds[], int n)
{
    int flag = 0;
    for(int i = 0; i< n; i++)
    {
        if(ds[i].ngay_dang_ky.year >= 2010)
        {
            xuatThongTinMotThueBao(ds[i]);
            flag ++;
        }
    }
    if(flag == 0)
    {
        cout << "Khong co thue bao nao de hien thi!\n";
    }
}

// void tinhCuocGoi(ThueBao ds[], int n)
// {
//     for(int i = 0; i < n; i++)
//     {

//     }
// }

int demSoLuongThueBaoTraTruoc(ThueBao ds[], int n)
{
    int count = 0;
    char thue_bao[20] = "tra truoc";
    for(int i = 0; i < n; i++)
    {
        if(strcmp(strupr(ds[i].loai_thue_bao), strupr(thue_bao)) == 0)
        {
            count ++;
        }
    }
    return count;
}

void Handling(char select)
{
    ThueBao ds[SIZE];
    int n;
    switch(select)
    {
        case 'a':
            soLuongThueBao(n);
            nhapDanhSachThueBao(ds, n);
            nhapPhimBatKy();
            break;
        case 'b':
            xuatDanhSachCacThueBao(ds, n);
            nhapPhimBatKy();
            break;
        case 'c':
            themMotThueBao(ds, n);
            cout << "Nhap phim bat ky de xem lai danh sach Thue bao!!" << endl;
            getch();
            cout << endl <<"===CAP NHAT DANH SACH THUE BAO===" << endl;
            xuatDanhSachCacThueBao(ds, n);
            nhapPhimBatKy();
            break;
        case 'd':
            cout << endl <<"===CAP NHAT DANH SACH THUE BAO===" << endl;
            sapXepDanhSach(ds, n);
            xuatDanhSachCacThueBao(ds, n);
            nhapPhimBatKy();
            break;
        case 'e':
            timThueBao(ds, n);
            nhapPhimBatKy();
            break;
        case 'f':
            xuatThueBaoTheoLoai(ds, n);
            nhapPhimBatKy();
            break;
        case 'g':
            cacThueBaoDangKiSau2010(ds, n);
            nhapPhimBatKy();
            break;
        case 'h':
            cout << "Dang phat trien!\n";
            nhapPhimBatKy();
            break;
        case 'i':
            cout << "So luong thue bao tra truoc la " << demSoLuongThueBaoTraTruoc(ds, n) << " thue bao\n";
            nhapPhimBatKy();
            break;
        case '0':
            cout << "CHAO TAM BIET!!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thuc hien lai! \n";
            nhapPhimBatKy();
    }
}

int main()
{
    char select;
    do
    {
        Menu();
        nhapLuaChon(select);
        Handling(select);
    }while(select != '0');
	return 0;
}