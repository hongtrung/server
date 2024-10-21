#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    int yearOfBirth;
    int MSSV;
} Student;

typedef struct {
    Student* students;
    int sl_sv;
    int sl_SV_Max;
} StudentList;

void initStudentList(StudentList* list) 
{
    list->sl_sv = 0;
    list->sl_SV_Max = 1;
    list->students = (Student*)malloc(list->sl_SV_Max * sizeof(Student));
}

void addStudent(StudentList* list, char* name, int age, int yearOfBirth, int MSSV) 
{
    if (list->sl_sv == list->sl_SV_Max) {
        list->sl_SV_Max += 1;
        list->students = (Student*)realloc(list->students, list->sl_SV_Max * sizeof(Student));
    }

    strcpy(list->students[list->sl_sv].name, name);
    list->students[list->sl_sv].age = age;
    list->students[list->sl_sv].yearOfBirth = yearOfBirth;
    list->students[list->sl_sv].MSSV = MSSV;
    list->sl_sv++;
}

void removeStudent(StudentList* list, int MSSV) 
{
    int found = 0;
    for (int i = 0; i < list->sl_sv; i++) {
        if (list->students[i].MSSV == MSSV) 
        {
            found = 1;
            for (int j = i; j < list->sl_sv - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
            list->sl_sv--;
            printf("Da xoa sinh vien co MSSV la: %d\n", MSSV);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co MSSV la: %d\n", MSSV);
    }
}

void displayStudents(const StudentList* list) 
{
    if (list->sl_sv == 0) {
        printf("Chua co sinh vien nao.\n");
        return;
    }
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < list->sl_sv; i++) 
    {
        printf("Ten: %s, Tuoi: %d, Nam sinh: %d, MSSV: %d\n", list->students[i].name, list->students[i].age, list->students[i].yearOfBirth, list->students[i].MSSV);
    }
}

void display_1_Student(const StudentList* list, int MSSV) 
{
    int found = 0;
    for (int i = 0; i < list->sl_sv; i++) {
        if (list->students[i].MSSV == MSSV) {
            found = 1;
            printf("Thong tin sinh vien co MSSV: %d:\n", MSSV);
            printf("Ten: %s, Tuoi: %d, Nam sinh: %d, MSSV: %d\n", 
                   list->students[i].name, list->students[i].age, 
                   list->students[i].yearOfBirth, list->students[i].MSSV);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co MSSV: %d\n", MSSV);
    }
}

void edit_1_Student(StudentList* list, int MSSV) 
{
    int found = 0;
    for (int i = 0; i < list->sl_sv; i++) {
        if (list->students[i].MSSV == MSSV) {
            found = 1;
            printf("Chinh sua thong tin sinh vien co MSSV: %d:\n", MSSV);
            printf("Nhap ten moi: ");
            scanf("%s", list->students[i].name);
            printf("Nhap tuoi moi: ");
            scanf("%d", &list->students[i].age);
            printf("Nhap nam sinh moi: ");
            scanf("%d", &list->students[i].yearOfBirth);
            printf("Thong tin da duoc cap nhat.\n");
            break;
        }
    }
    if (!found) {
        printf("KKhong tim thay sinh vien co MSSV: %d\n", MSSV);
    }
}

void freeStudentList(StudentList* list) 
{
    free(list->students);
}

void menu()
{
    printf("\n0. Menu\n");
    printf("1. Them sinh vien vao danh sach\n");
    printf("2. Xoa sinh vien \n");
    printf("3. Hien thi danh sach sinh vien\n");
    printf("4. Hien thi thong tin sinh vien theo MSSV\n");
    printf("5. Chinh sua thong tin sinh vien\n");
    printf("6. Thoat\n");
}

int main() 
{
    StudentList list;
    initStudentList(&list);

    int choice;
    int MSSV, age, yearOfBirth;
    char name[30];

    menu();

    while (1) {
        
        printf("\nChon 1 tuy chon: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 0:
                menu();
                break;
            case 1:
                printf("Nhap ten sinh vien:");
                scanf("%s", name);
                printf("Tuoi: ");
                scanf("%d", &age);
                printf("Nam sinh: ");
                scanf("%d", &yearOfBirth);
                printf("MSSV: ");
                scanf("%d", &MSSV);
                addStudent(&list, name, age, yearOfBirth, MSSV);
                break;
            case 2:
                printf("Nhap MSSV can xoa: ");
                scanf("%d", &MSSV);
                removeStudent(&list, MSSV);
                break;
            case 3:
                displayStudents(&list);
                break;
            case 4:
                printf("Nhap MSSV can hien thong tin: ");
                scanf("%d", &MSSV);
                display_1_Student(&list, MSSV);
                break;
            case 5:
                printf("Nhap MSSV can sua thong tin: ");
                scanf("%d", &MSSV);
                edit_1_Student(&list, MSSV);
                break;
            case 6:
                freeStudentList(&list);
                printf("Ket thuc\n");
                return 0;
            default:
                printf("Moi chon tu 0-6.\n");
        }
    }
}
