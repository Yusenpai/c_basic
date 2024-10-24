# Bài 2: Biến và hằng số trong C

## Mục lục

- [Bài 2: Biến và hằng số trong C](#bài-2-biến-và-hằng-số-trong-c)
	- [Mục lục](#mục-lục)
	- [Biến và Hằng số](#biến-và-hằng-số)
	- [Khai báo, định nghĩa và khởi tạo biến](#khai-báo-định-nghĩa-và-khởi-tạo-biến)
		- [Khai báo biến](#khai-báo-biến)
		- [Định nghĩa biến](#định-nghĩa-biến)
		- [Khởi tạo biến](#khởi-tạo-biến)
	- [Sử dụng biến](#sử-dụng-biến)
	- [Khai báo hằng số](#khai-báo-hằng-số)
	- [Phạm vi (Scope) của biến](#phạm-vi-scope-của-biến)
	- [Liên kết nội (Internal Linkage) và liên kết ngoại (External Linkage) trong C](#liên-kết-nội-internal-linkage-và-liên-kết-ngoại-external-linkage-trong-c)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
	- [Tài liệu tham khảo](#tài-liệu-tham-khảo)


## Biến và Hằng số

**Biến** là một vùng nhớ lưu trữ dữ liệu và giá trị có thể ***bị thay đổi*** trong quá trình chạy của chương trình.

**Hằng số** là biến có giá trị cố định ***không thể thay đổi*** trong suốt thời gian chạy của chương trình.

## Khai báo, định nghĩa và khởi tạo biến

Khi khai báo một biến trong C, có thể hiểu ở ba khía cạnh:

1. **Khai báo biến**
2. **Định nghĩa biến**
3. **Khởi tạo biến**

### Khai báo biến

**Khai báo biến** là thông báo sự tồn tại của biến với trình biên dịch. Biến này chưa được cấp phát vùng nhớ.

### Định nghĩa biến

**Định nghĩa biến** là khi trình biên dịch cấp phát một vùng nhớ cho biến đó. Giá trị nằm trong vùng nhớ có thể là giá trị rác.

Trình biên dịch C hiện đại cho phép khai báo và định nghĩa biến trong một bước với cú pháp: 

`<kiểu dữ liệu> <tên biến>;`

Ví dụ:
```c++
int a;
float b;
uint16_t number;
```

### Khởi tạo biến

**Khởi tạo biến** là gán giá trị ban đầu cho biến. Khởi tạo biến dùng toán tử `=`. Cú pháp:

`<tên biến> = <giá trị>;`

Ví dụ:
```c++
a = 10;
b = 3.14f;
number = 0x08;
```

Có thể khai báo, định nghĩa và khởi tạo một biến trong một dòng lệnh:

```c++
int a = 10;
float b = 3.14f;
uint16_t number = 0x08;
```
> Lưu ý khi đặt tên biến: 
> - Tên có phân biệt chữ cái hoa với thường. biến A khác với biến a.
> - Tên biến chỉ có thể chứa chữ cái, số và dấu gạch chân
> - Không có khoảng trắng
> - Không trùng với từ khoá

## Sử dụng biến

```c++
#include "stdio.h"

int main(){
	int a = 10;
	printf("Number a is: %d\n", a);
	return 0;
}
```

## Khai báo hằng số

Khai báo hằng số tương tự với khai báo biến và thêm từ khoá `const`. Khác với biến, khai báo hằng số bắt buộc phải có giá trị khởi tạo.

Cú pháp:

`const <kiểu dữ liệu> <tên biến> = <giá trị>;`

```c++
const int a = 10;
```

## Phạm vi (Scope) của biến

**Phạm vi của biến** là một khối hoặc một vùng trong chương trình C, mà biến được khai báo, định nghĩa và sử dụng. Bên ngoài vùng này **không thể truy xuất tới biến**.

Có hai loại phạm vi:

- **Phạm vi toàn cục (global scope)**: Là khu vực bên ngoài tất cả các khối, các hàm. Một biến nằm trong phạm vi toàn cục có thể được truy xuất từ mọi nơi. Biến này được gọi là **Biến toàn cục**

- **Phạm vi cục bộ (local scope)**: Là khu vực bên trong các khối và các hàm (nằm bên trong hai dấu `{}`). Các biến trong khu vực này chỉ có thể được truy cập trong cùng phạm vi hoặc trong **phạm vi bé hơn nó**.

Xét đoạn code sau:

```c++
#include "stdio.h"

int main(){
	int a = 10;
	printf("Number a is: %d\n", a);
	return 0;
}

/* Hàm foo đang cố gắng truy xuất tới biến a bên trong hàm main */
void foo(){
	printf("Number a is: %d\n", a);
}
```
Ngõ ra:
```
main.c:13:30: error: use of undeclared identifier 'a'
   13 |         printf("Number a is: %d\n", a);
      |                                     ^
1 error generated.
```

Trình biên dịch báo lỗi vì sử dụng biến `a`, mặc dù chưa được khai báo trong hàm `foo()`. Ta thấy rằng biến `a` bên trong hàm `main()` không thể truy xuất ra bên ngoài hàm `main()` được. 

Ta nói phạm vi của biến `a` là hàm `main()`, là một **phạm vi cục bộ**. Biến `a` là **biến cục bộ**.

Nếu ta sửa đoạn code một chút, khai báo `a` bên ngoài hàm `main()`:

```c++
#include "stdio.h"
int a = 10; // Khai báo biến a
int main(){
	printf("Number a is: %d\n", a);
	return 0;
}

void foo(){
	printf("Number a is: %d\n", a);
}
```

Lúc này cả hàm `foo()` và `main()` có thể truy cập tới biến `a`. Ta nói biến `a` là **biến toàn cục** và có **phạm vi toàn cục**.

## Liên kết nội (Internal Linkage) và liên kết ngoại (External Linkage) trong C

Một biến được khai báo với phạm vi toàn cục có thể truy cập từ mọi nơi trong chương trình. Nếu biến đó được truy xuất từ một file khác thì nó có **liên kết ngoại**. Nếu biến đó bị hạn chế truy cập trong cùng một file thì nó có **liên kết nội**.

Xét đoạn code sau:

Trong file `file1.c`:
```c++
#include <stdio.h>

// Khai báo biến a có phạm vi toàn cục
int a;

// Một hàm sử dụng biến a
void myfun()
{
    printf("%d\n", a);
}
```

Trong file `main.c`:
```c++
#include <stdio.h>

// Khai báo biến a với từ khoá extern, cho biết a được định nghĩa ở một nơi khác
extern int a;

int main(void)
{
    // Khởi tạo biến a
    a = 2;

	printf("%d\n", a);

    return 0;
}
```
Biến `a` được khai báo và định nghĩa trong file `file1.c` với phạm vi toàn cục. Ta sử dụng từ khoá `extern` với cú pháp:

`extern <kiểu dữ liệu> <tên biến>;`

để khai báo biến `a` trong file `main.c`. Cú pháp này thông báo cho trình biên dịch rằng biến `a` được định nghĩa ở nơi khác, bên ngoài file `main.c`. Lúc này ta nói biến `a` có **liên kết ngoại**.

Ngược lại, ta có thể hạn chế một biến, mà biến đó chỉ có thể truy cập trong cùng một file với từ khoá `static`.
Trong file `file1.c`:
```c++
#include <stdio.h>

// Khai báo biến a có phạm vi toàn cục
int a;

// Khai báo biến b có phạm vi toàn cục, nhưng có liên kết nội
static int b;

// Một hàm sử dụng biến a
void myfun()
{
    printf("%d\n", a);
}
```

Trong file `main.c`:
```c++
#include <stdio.h>

// Khai báo biến a với từ khoá extern, cho biết a được định nghĩa ở một nơi khác
extern int a;

// Sử dụng extern để khai báo biến b
extern int b;

int main(void)
{
    // Khởi tạo biến a và b
    a = 2;
	b = 3;

	printf("%d\n", a);
	printf("%d\n", b);

    return 0;
}
```

Lỗi khi biên dịch:

```bash
➜  c_basic git:(main) ✗ gcc main.c file1.c -o main
Undefined symbols for architecture arm64:
  "_b", referenced from:
      _main in main-6063be.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

Đây là lỗi trong bước **linking (liên kết)**, khi trình biên dịch không tìm ra biến `b`. Biến `b` được khai báo trong file `file1.c` với cú pháp:

`static <kiểu dữ liệu> <tên biến>;`

Biến `b` tuy có phạm vi toàn cục nhưng không thể truy cập từ bên ngoài file chứa nó. Ta nói biến `b` có **liên kết nội**.

## Câu hỏi và bài tập

1. Có mấy loại phạm vi của biến? Biến cục bộ và biến toàn cục là gì?
2. Ý nghĩa của từ khoá `extern` và `static` khi nói tới liên kết nội và liên kết ngoại ?
3. (Khó) Giá trị của một hằng số có thể bị thay đổi không ?

## Tài liệu tham khảo