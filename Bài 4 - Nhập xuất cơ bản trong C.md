# Bài 4: Nhập xuất cơ bản trong C

## Mục lục

- [Bài 4: Nhập xuất cơ bản trong C](#bài-4-nhập-xuất-cơ-bản-trong-c)
  - [Mục lục](#mục-lục)
  - [`stdin` và `stdout`](#stdin-và-stdout)
  - [`printf()`](#printf)
  - [`scanf()`](#scanf)
  - [Các ký tự định dạng (Format Specifier)](#các-ký-tự-định-dạng-format-specifier)
  - [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
  - [Tài liệu tham khảo](#tài-liệu-tham-khảo)

## `stdin` và `stdout`

- `stdin` (Standard Input): Đây là nơi chương trình lấy dữ liệu đầu vào. Trong phần lớn trường hợp, `stdin` là bàn phím, nhưng nó cũng có thể được thay thế bởi tệp hoặc luồng nhập khác.

- `stdout` (Standard Output): Đây là nơi chương trình ghi dữ liệu đầu ra. Mặc định là màn hình, nhưng cũng có thể được chuyển hướng tới tệp hoặc luồng khác.

Các hàm đọc và ghi lên `stdin` và `stdout` được cung cấp trong thư viện `stdio.h`, trong đó dùng nhiều nhất là `printf()` và `scanf()`.

```c++
#include <stdio.h>

int main() {
    char name[30];
    printf("Nhập tên của bạn: ");  // Ghi ra stdout (màn hình)
    scanf("%s", name);              // Nhận dữ liệu từ stdin (bàn phím)
    printf("Xin chào, %s!\n", name); // Ghi ra stdout
    return 0;
}
```

## `printf()`

Hàm `printf()` là một hàm trong thư viện chuẩn của C để in ra `stdout`. Cú pháp:

```c++
printf("Chuỗi định dạng", <danh sách tham số>);
```

- **Chuỗi định dạng**: Là chuỗi chứa văn bản và các **ký tự định dạng** (format specifier) để biểu diễn các giá trị của biến.
- **Danh sách tham số**: Là các biến hoặc giá trị tương ứng với các ký tự định dạng trong chuỗi.

Ví dụ:
```c++
int age = 20;
printf("Tôi %d tuổi.\n", age);

uint32_t address = 0xFF10;
printf("Địa chỉ là: 0x%06X\n", address);
```

Kết quả:

```
Tôi 20 tuổi.
Địa chỉ là: 0x00FF10
```

## `scanf()`

`scanf()` được dùng để nhập dữ liệu từ `stdin`. Hàm này đọc dữ liệu từ dòng nhập theo chuỗi định dạng và lưu vào các biến tương ứng. Cú pháp:

```c++
scanf("Chuỗi định dạng", <danh sách địa chỉ biến>);
```

- **Chuỗi định dạng**: Là chuỗi chứa các ký tự định dạng, xác định kiểu dữ liệu đầu vào mà người dùng nhập vào.

- **Danh sách địa chỉ biến**: Là các địa chỉ của biến (vì sao?) (sử dụng ký tự &) để lưu dữ liệu nhập vào.

Ví dụ:

```c++
int age;
printf("Nhập tuổi của bạn: ");
scanf("%d", &age);
printf("Tuổi của bạn là: %d\n", age);
```

## Các ký tự định dạng (Format Specifier)

Khi sử dụng `printf()` hoặc `scanf()`, ta cần dùng các ký tự định dạng để chỉ ra kiểu dữ liệu nào sẽ được in hoặc nhập.

Một số ký tự định dạng phổ biến:

|Ký tự định dạng (specifier)| Ý nghĩa	| Ví dụ sử dụng với printf|
|---------------|------|------|
|%d	|Số nguyên	|printf("%d", 123);
|%f	|Số thực (kiểu float)	|printf("%f", 3.14);
|%c	|Ký tự	|printf("%c", 'A');
|%s	|Chuỗi ký tự	|printf("%s", "Hello");
|%x	|Số nguyên ở hệ thập lục phân (hex)	|printf("%x", 255);
|%p	|Địa chỉ bộ nhớ (con trỏ)	|printf("%p", ptr);

Tham khảo thêm tại: https://cplusplus.com/reference/cstdio/printf/

Ví dụ:

```c++
#include <stdio.h>

int main() {
    int num;
    float real_num;
    char letter;
    
    // Nhập các giá trị
    printf("Nhập một số nguyên: ");
    scanf("%d", &num);
    
    printf("Nhập một số thực: ");
    scanf("%f", &real_num);
    
    printf("Nhập một ký tự: ");
    scanf(" %c", &letter); // Lưu ý có khoảng trắng trước %c để bỏ qua ký tự newline
    
    // Xuất các giá trị
    printf("Số nguyên: %d\n", num);
    printf("Số thực: %.2f\n", real_num); // %.2f để hiển thị 2 chữ số sau dấu thập phân
    printf("Ký tự: %c\n", letter);

    return 0;
}
```

## Câu hỏi và bài tập

1. Stdin và Stdout là gì? Nêu sự khác nhau giữa chúng.
2. Kể tên ít nhất 5 ký tự định dạng và giải thích ý nghĩa của chúng.
3. Tại sao khi dùng `scanf()` để nhập ký tự (sử dụng %c), đôi khi ta phải thêm một khoảng trắng trước %c?
4. (Khó) Vì sao phải truyền địa chỉ của biến vào hàm `scanf()`?
5. (Khó) Khi lập trình vi điều khiển, có thể dùng hàm `printf()` và `scanf()` không?

## Tài liệu tham khảo