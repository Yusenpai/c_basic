# Bài 1: Giới thiệu về ngôn ngữ lập trình C

## Mục lục

- [Bài 1: Giới thiệu về ngôn ngữ lập trình C](#bài-1-giới-thiệu-về-ngôn-ngữ-lập-trình-c)
	- [Mục lục](#mục-lục)
	- [Ngôn ngữ lập trình C](#ngôn-ngữ-lập-trình-c)
	- [Cài đặt môi trường](#cài-đặt-môi-trường)
	- [Cấu trúc một chương trình C](#cấu-trúc-một-chương-trình-c)
	- [Ghi chú trong C](#ghi-chú-trong-c)
	- [Từ khoá trong C](#từ-khoá-trong-c)
	- [Các bước biên dịch một chương trình C](#các-bước-biên-dịch-một-chương-trình-c)
		- [Preprocessing (tiền xử lý)](#preprocessing-tiền-xử-lý)
		- [Compiling (biên dịch)](#compiling-biên-dịch)
		- [Assembling (hợp ngữ)](#assembling-hợp-ngữ)
		- [Linking (liên kết)](#linking-liên-kết)
	- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

## Ngôn ngữ lập trình C

**C** là một ngôn ngữ lập trình bậc trung, được phát triển vào những năm 1970 bởi Dennis Ritchie tại Bell Labs. C nổi tiếng với hiệu suất cao và khả năng làm việc gần với phần cứng, phù hợp để phát triển hệ điều hành, hệ thống nhúng và các ứng dụng cần tài nguyên hạn chế.

## Cài đặt môi trường

1. **Trình biên dịch C**: **GCC** (GNU Compiler Collection) là trình biên dịch phổ biến nhất cho C. Cài đặt GCC trên Windows sử dụng MinGW hoặc Cygwin. Link MinGW: https://sourceforge.net/projects/mingw/

2. **IDE hoặc Text Editor**: Visual Code, Sublime Text, Code::Block,...

## Cấu trúc một chương trình C

```c++
#include <stdio.h> // Thư viện chuẩn

int main() {
    // Khối lệnh chính
    printf("Hello, World!\n"); // In ra màn hình
    return 0; // Kết thúc chương trình
}
```

- `#include <stdio.h>`: Dòng này gọi thư viện chuẩn để sử dụng các hàm nhập/xuất.
- `int main()`: Hàm chính, nơi chương trình bắt đầu thực thi.
- `printf()`: Hàm xuất ra màn hình.
- `return 0`: Trả về giá trị 0, báo hiệu chương trình đã kết thúc thành công.

## Ghi chú trong C

```c++
// Đây là ghi chú một dòng

/* Đây là ghi chú
   nhiều dòng */

/* 
 * Đây cũng là
 * ghi chú nhiều dòng
 */
```

## Từ khoá trong C

Có 32 từ khoá trong C chuẩn ANSI (C89/90)

![](https://www.codingeek.com/wp-content/uploads/2016/11/keywords.png)

Chuẩn C99 có thêm 5 từ khoá:
1. `_Bool`
2. `_Complex`
3. `_Imaginary`
4. `inline`
5. `restrict`

## Các bước biên dịch một chương trình C

Biên dịch dùng lệnh:

```bash
gcc <danh sách các file .c> -o <tên chương trình>.exe
gcc main.c -o main.exe
```

Gồm 4 bước:

1. Preprocessing (tiền xử lý)
2. Compiling (biên dịch)
3. Assembling (hợp ngữ)
4. Linking (liên kết)

![](https://media.geeksforgeeks.org/wp-content/uploads/20230404112946/Compilation-Process-in-C.png)

### Preprocessing (tiền xử lý)

Đây là bước đầu tiên khi biên dịch một chương trình C. Nó thực hiện:

- Loại bỏ ghi chú
- Mở rộng Macros
- Mở rộng tệp được `include`
- Biên dịch có điều kiện

Dùng lệnh

```bash
gcc -E main.c -o preprocessed_main.i
```

### Compiling (biên dịch)

Bước tiếp theo là biên dịch file `preprocessed_main.i` thành hợp ngữ.

Dùng lệnh

```bash
gcc -S main.c -o asm_main.s
```

### Assembling (hợp ngữ)

Bước tiếp theo là biên dịch hợp ngữ trong `asm_main.s` thành mã máy ở dạng file `.o`. Có bao nhiêu file .c thì bấy nhiêu file `.o`.

Dùng lệnh

```bash
gcc main.c -o main.o
```

### Linking (liên kết)

Liên kết tất cả các file `.o` thành một chương trình `main.exe` hoàn chỉnh.

## Tài liệu tham khảo