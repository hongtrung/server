#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#pragma pack(1) 
typedef struct 
{
    //int MSSV;
    int namSinh;
    char hoTen[50];
    int tuoi;
}Student;

Student* capphat_1_Sv()
{
    return (Student*) malloc (sizeof(Student));
}

Student* capphatDSSV(int n)
{
    return (Student*) malloc (n*sizeof(Student));
}



void inputSV(Student arr_student)
{
    printf("Ho va ten: ");
    scanf("%s", arr_student.hoTen);
    // fgets(arr_student->hoTen, sizeof(arr_student->hoTen), stdin);
    
    printf("Nam sinh: ");
    scanf("%d", &arr_student.namSinh);

    printf("Tuoi: ");
    scanf("%d", &arr_student.tuoi);
    return arr_student;
}

void outputSV (Student arr_student)
{
    printf("Ho va ten:%s Nam sinh: %d tuoi: %d\n.",arr_student.hoTen,&arr_student.namSinh,&arr_student.tuoi);
}

void hienthids(Student* ds, int n)
{
    printf("DSSV\n");
    int stt = 1;
    for (int i = 0; i<n; i++)
    {
        printf ("%d", stt++);
        outputSV(ds[i]);
    }
}

void menu()
{
    printf("0. MENU\n");
    printf("1. Nhap thong tin sinh vien\n");
    printf("2. Hien thi thong tin sinh vien\n");
    printf("3. Them sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Hien thi danh sach sinh vien\n");
    printf("6. Ket thuc\n");
}

Student* add_sv(int* n, Student* danhsach)
{

}

int main(void)
{   
    int n=1000;
    menu();

    Student* arr_student = NULL;
    Student* ds = NULL;

    while (0==0)
    {
        int i;
        int chon;
        printf ("Lua chon: ");
        scanf("%d",&chon);

        if (chon == 1)
        {
            printf("Ban da chon \"Nhap thong tin sinh vien\"\n");
            printf("Chon sinh vien: ");
            scanf("%d", &i);
            inputSV(arr_student[i]);
        }
        else if (chon == 2)
        {
            printf("Ban da chon \"Hien thi thong tin sinh vien\"\n");
            printf("Chon sinh vien: ");
            scanf("%d", &i);
            outputSV(arr_student[i]);
        }
        else if (chon == 3)
        {
            printf("\nKet thuc\n");
            return 0;
        }
        else if (chon == 0)
        {
            menu();
        }
        else if (chon==4)
        {
            hienthids(&arr_student,n);
        }
        
        else
        {
            printf("Nhap tu 0-3\n");
        }
    }
    free(arr_student);
    return 0;
}