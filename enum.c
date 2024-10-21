#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 500
#define true 1
#define false 0

typedef struct {
    char hoTen[50];
    int namSinh;
    float diemTB;
} SinhVien;

SinhVien* capPhatSinhVien()
{
    return (SinhVien*) malloc(sizeof(SinhVien));
}

SinhVien* capPhatDanhSachSinhVien(int n)
{
    return (SinhVien*) malloc(n*sizeof(SinhVien));
}

SinhVien* capPhatDanhSachKhiThem1SinhVien (int* n, SinhVien* danhSach)
{
    if (*n == 0 || danhSach == NULL)
    {
        *n = 1;
        return capPhatSinhVien();
    }
    else
    {
        (*n) += 1;
        danhSach = realloc(danhSach,(*n)*sizeof(SinhVien));
        return danhSach;
    }
}

SinhVien* capPhatDanhSachKhiXoa1SinhVien (int* n, SinhVien* danhSach)
{
    if (*n == 0 || danhSach == NULL)
    {
        *n = 0;
        return NULL;
    }
    else
    {
        (*n) -= 1;
        danhSach = realloc(danhSach,(*n)*sizeof(SinhVien));
        return danhSach;
    }
}

SinhVien nhapSinhVien()
{
    SinhVien sv;
    printf("\tHo ten: ");
    scanf("%s",sv.hoTen);

    printf("\tNam sinh: ");
    scanf("%d",&sv.namSinh);

    printf("\tDiem TB: ");
    scanf("%f",&sv.diemTB);

    return sv;
}

SinhVien* taoDanhSachBietTruocSoSinhVien (int n)
{
    SinhVien* ds = capPhatDanhSachSinhVien(n);
    for (int i=0; i<n; i++)
    {
        printf("\t\tThong tin sinh vien thu %d\n",i+1);
        //Nhập sinh viên thứ i
        ds[i] = nhapSinhVien();
    }
    return ds;
}

SinhVien* taoDanhSachChuaBietSoSinhVien (int* n)
{
    SinhVien* ds = NULL;
    int stt = 1;
    while (true)
    {
        printf("\t\tThong tin sinh vien thu %d\n",stt++);
        ds = capPhatDanhSachKhiThem1SinhVien(n,ds);
        ds[(*n)-1] = nhapSinhVien();

        char tiep;
        printf("\tBam y de nhap tiep: ");
        fflush(stdin);
        tiep = getchar();
        if (tiep!='y' && tiep!='Y')
            break;
    }
    return ds;
}

void hienThiSinhVien (SinhVien sv)
{
    printf("%20s%10d%10.2f\n",sv.hoTen,sv.namSinh,sv.diemTB);
}

void hienThiDanhSach (SinhVien* ds, int n)
{
    printf("\t\tDSSV\n");
    printf("\t%5s%20s%10s%10s\n","STT","HO TEN", "NAM SINH", "DIEM TB");
    int stt = 1;
    for (int i=0; i<n; i++)
    {
        printf("\t%5d",stt++);
        hienThiSinhVien(ds[i]);
    }
}

int timChiSoSinhVienTheoTen (SinhVien* ds, int n, char* hoTenCanTim)
{
    for (int i=0; i<n ;i++)
        if (strcmp(ds[i].hoTen,hoTenCanTim)==0)
            return i;
    return -1;
}

SinhVien* themSinhVienSauTen (SinhVien* ds, int* n, char* hoTenCanTim)
{
    int index = timChiSoSinhVienTheoTen(ds,*n,hoTenCanTim);
    if (-1 == index)
    {
        printf("\tKhong tim thay sinh vien %s\n",hoTenCanTim);
        return ds;
    }
    else
    {
        ds = capPhatDanhSachKhiThem1SinhVien(n,ds);

        //Dịch các phần tử sau index đi 1 đơn vị
        for (int i = *n-1; i>index; i--)
            ds[i] = ds[i-1];

        //Thêm 1 sinh viên vào sau vị trí index
        ds[index+1] = nhapSinhVien();
        return ds;
    }
}

void suaSinhVienTheoTen (SinhVien* ds, int n, char* hoTenCanSua)
{
    int index = timChiSoSinhVienTheoTen(ds,n,hoTenCanSua);
    if (-1 == index)
    {
        printf("\tKhong tim thay sinh vien %s\n",hoTenCanSua);
    }
    else
    {
        ds[index] = nhapSinhVien();
    }
}

SinhVien* xoaSinhVienTheoTen (SinhVien* ds, int* n, char* hoTenCanXoa)
{
    int index = timChiSoSinhVienTheoTen(ds,*n,hoTenCanXoa);
    if (-1 == index)
    {
        printf("\tKhong tim thay sinh vien %s\n",hoTenCanXoa);
        return ds;
    }
    else
    {
        for (int i=index; i<(*n)-1; i++)
        {
            ds[i] = ds[i+1];
        }
        ds = capPhatDanhSachKhiXoa1SinhVien(n,ds);
        return ds;
    }
}

void menu()
{
    printf("\t\tMENU\n");
    printf("\t1. Tao danh sach sinh vien\n");
    printf("\t2. Hien thi danh sach sinh vien\n");
    printf("\t3. Chen them sinh vien sau ten\n");
    printf("\t4. Xoa sinh vien\n");
    printf("\t5. Sua sinh vien\n");
    printf("\t0. Exit\n");
    printf("\t\tVui long chon: ");
}

int main()
{
    int n = 0;
    SinhVien* ds = NULL;
    while (true)
    {
        menu();
        int chon;
        scanf("%d",&chon);
        system("cls");

        if (chon==1)
        {
            printf("\tBan da chon tao danh sach sinh vien\n");
            ds = taoDanhSachChuaBietSoSinhVien(&n);
            printf("\tBan da tao xong danh sach sinh vien\n");
        }
        else if (chon==2)
        {
            hienThiDanhSach(ds,n);
        }
        else if (chon==3)
        {
            printf("\tBan da chon them sinh vien sau ten\n");
            printf("\tNhap ten sinh vien dung truoc (da co): ");
            // char hoTen[30];
            // // scanf("%s",SinhVien.hoTen);
            // ds = themSinhVienSauTen(ds,&n,hoTen);
        }
        else if (chon==4)
        {
            printf("\tBan da chon xoa sinh vien theo ten\n");
            printf("\tNhap ten sinh vien can xoa: ");
            // char hoTen[30];
            // fflush(stdin);
            // gets(hoTen);
            // ds = xoaSinhVienTheoTen(ds,&n,hoTen);
        }
        else if (chon==5)
        {
            printf("\tBan da chon sua sinh vien theo ten\n");
            printf("\tNhap ten sinh vien can sua: ");
            // char hoTen[30];
            // fflush(stdin);
            // gets(hoTen);
            // suaSinhVienTheoTen(ds,n,hoTen);
        }
        else if (chon==0)
        {
            printf("\t\tBYE!!!\n");
            return 0;
        }
        else
        {
            printf("\tNhap tu 0-5\n");
        }
        printf("\tBam phim bat ky de ve menu\n");
        //getch();
        system("cls");
    }
}

