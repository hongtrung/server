#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    int id;
} Student;

typedef struct {
    Student* students;
    int size;
    int capacity;
} StudentList;

// Hàm khởi tạo danh sách sinh viên
void initStudentList(StudentList* list) {
    list->size = 0;
    list->capacity = 2;
    list->students = (Student*)malloc(list->capacity * sizeof(Student));
}

// Hàm thêm sinh viên vào danh sách
void addStudent(StudentList* list, const char* name, int id) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->students = (Student*)realloc(list->students, list->capacity * sizeof(Student));
    }

    strcpy(list->students[list->size].name, name);
    list->students[list->size].id = id;
    list->size++;
}

// Hàm xóa sinh viên khỏi danh sách theo ID
void removeStudent(StudentList* list, int id) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            found = 1;
            for (int j = i; j < list->size - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
            list->size--;
            printf("Đã xóa sinh viên có ID %d\n", id);
            break;
        }
    }
    if (!found) {
        printf("Không tìm thấy sinh viên có ID %d\n", id);
    }
}

// Hàm hiển thị danh sách sinh viên
void displayStudents(const StudentList* list) {
    if (list->size == 0) {
        printf("Danh sách sinh viên trống.\n");
        return;
    }
    printf("Danh sách sinh viên:\n");
    for (int i = 0; i < list->size; i++) {
        printf("Tên: %s, ID: %d\n", list->students[i].name, list->students[i].id);
    }
}

// Hàm hiển thị thông tin một sinh viên theo ID
void displayStudentByID(const StudentList* list, int id) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            found = 1;
            printf("Thông tin sinh viên có ID %d:\n", id);
            printf("Tên: %s, ID: %d\n", list->students[i].name, list->students[i].id);
            break;
        }
    }
    if (!found) {
        printf("Không tìm thấy sinh viên có ID %d\n", id);
    }
}

// Hàm chỉnh sửa thông tin sinh viên theo ID
void editStudent(StudentList* list, int id) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            found = 1;
            printf("Nhập tên mới cho sinh viên có ID %d: ", id);
            scanf("%s", list->students[i].name);
            printf("Đã cập nhật thông tin sinh viên có ID %d\n", id);
            break;
        }
    }
    if (!found) {
        printf("Không tìm thấy sinh viên có ID %d\n", id);
    }
}

// Hàm giải phóng bộ nhớ của danh sách sinh viên
void freeStudentList(StudentList* list) {
    free(list->students);
}

void menu()
{
    printf("\nMenu:\n");
    printf("1. Them sinh vien vao danh sach\n");
    printf("2. Xoa sinh vien \n");
    printf("3. Hien thi danh sach sinh vien\n");
    printf("4. Hien thi thong tin sinh vien theo ten\n");
    printf("5. Chinh sua thong tin sinh vien\n");
    printf("6. Thoat\n");
}
int main() {
    StudentList list;
    initStudentList(&list);

    int choice, id;
    char name[MAX_NAME];
    menu();
    while (1) {
        
        printf("Chon 1 tuy chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập tên sinh viên: ");
                scanf("%s", name);
                printf("Nhập ID sinh viên: ");
                scanf("%d", &id);
                addStudent(&list, name, id);
                break;
            case 2:
                printf("Nhập ID sinh viên cần xóa: ");
                scanf("%d", &id);
                removeStudent(&list, id);
                break;
            case 3:
                displayStudents(&list);
                break;
            case 4:
                printf("Nhập ID sinh viên cần hiển thị: ");
                scanf("%d", &id);
                displayStudentByID(&list, id);
                break;
            case 5:
                printf("Nhập ID sinh viên cần chỉnh sửa: ");
                scanf("%d", &id);
                editStudent(&list, id);
                break;
            case 6:
                freeStudentList(&list);
                printf("Thoát chương trình.\n");
                return 0;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    }
}
