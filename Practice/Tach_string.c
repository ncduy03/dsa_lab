#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // khai báo một chuỗi để lưu chuỗi nhập từ bàn phím
    printf("Nhap chuoi (nhan Enter de dung):\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // xóa ký tự '\n' ở cuối chuỗi
        input[strcspn(input, "\n")] = '\0';

        char *token = strtok(input, "/"); // tách chuỗi bằng ký tự "/"

        while (token != NULL) {
            printf("%s\n", token); // in ra từng phần tử con của chuỗi
            token = strtok(NULL, "/"); // tách tiếp phần tử tiếp theo
        }
    }

    return 0;
}
