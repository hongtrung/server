#include<stdio.h>
#include<string.h>

int main(void){
    char str1[100] = "hello";
    char dest[20];
    
    char str2[6] = "aorld";

    printf("Sizeof str = %d\n", sizeof(str1));
    printf("Sizeof str = %d\n", sizeof(str2));
    printf("Sizeof str = %d\n", strlen(str2));
    printf("str2 = %s\n", str2);
    strcpy(dest, str1);

    int result = strcmp(str1,str2);/*thuc hien so sanh 2 ky tu dau tien, neu bang nhau thi ss sang ben phai*/
    if (result==0)
    {
        printf ("chuoi 1 = chuoi 2\n");
    }
    else if (result>0)
    {
        printf("chuoi 1 > chuoi 2\n");
    }
    else
    {
        printf("chuoi 1 < chuoi 2\n");
    }
    strcat(str1,str2); // noi chuoi 2 vao chuoi 1
    printf("hello\n");
    printf("hello_2\n");
    return 0;
    
}