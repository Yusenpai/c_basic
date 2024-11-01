# Bài 10: Kiểu dữ liệu tự định nghĩa

## Mục lục

- [Bài 10: Kiểu dữ liệu tự định nghĩa](#bài-10-kiểu-dữ-liệu-tự-định-nghĩa)
	- [Mục lục](#mục-lục)
	- [Kiểu cấu trúc `struct`](#kiểu-cấu-trúc-struct)
		- [Cú pháp](#cú-pháp)
		- [Khởi tạo một cấu trúc](#khởi-tạo-một-cấu-trúc)
	- [Toán tử `.` và `->`](#toán-tử--và--)
	- [Căn chỉnh và đệm trong một cấu trúc](#căn-chỉnh-và-đệm-trong-một-cấu-trúc)
	- [Nén cấu trúc](#nén-cấu-trúc)

## Kiểu cấu trúc `struct`

**Kiểu cấu trúc** là kiểu dữ liệu cho phép bạn nhóm nhiều kiểu dữ liệu khác nhau lại với nhau.

### Cú pháp

```c++

// Định nghĩa một cấu trúc
struct <tên cấu trúc> {
    <kiểu dữ liệu> <tên thành phần 1>;
    <kiểu dữ liệu> <tên thành phần 2>;
    // ...
};

// Khai báo và định nghĩa một biến có kiểu cấu trúc
struct <tên cấu trúc> <tên biến>;
```

Ví dụ:

```c++
struct Point {
    int x;
    int y;
};

struct Point p1;

p1.x = 10;
p1.y = 20;
```

### Khởi tạo một cấu trúc

Có hai cách để khởi tạo giá trị các thành phần trong một cấu trúc:

- Khởi tạo ngay khi khai báo:

	```c++
	struct Point {
		int x;
		int y;
	};

	struct Point p1 = {10, 20};	// Khởi tạo phải đúng thứ tự

	struct Point p2 = {
		.x = 12,
		.y = 20
	} // Khởi tạo không cần nhớ thứ tự
	```

- Khởi tạo sau khi đã khai báo, dùng toán tử `.`:

	```c++
	struct Point p3;
	p3.x = 10;       // Khởi tạo thành phần x
	p3.y = 20;       // Khởi tạo thành phần y
	```

## Toán tử `.` và `->`

- Toán tử `.` dùng để truy cập tới các thành phần của một biến cấu trúc:

	```c++
	struct Point {
		int x;
		int y;
	};

	struct Point p1;
	p1.x = 10;
	p1.y = 20;

	printf("Toạ độ: (%d, %d)\n", p1.x, p1.y);
	```

- Toán tử `->` được sử dụng để truy cập các thành viên của một con trỏ đến cấu trúc:

	```c++
	#include <stdio.h>
	#include <stdlib.h>

	struct Point {
		int x;
		int y;
	};

	int main() {
		struct Point p1;
		struct Point *p2 = &p1;
		p2->x = 30;
		p2->y = 40;
		printf("Toạ độ: (%d, %d)\n", p1.x, p1.y);
		printf("Toạ độ: (%d, %d)\n", p2->x, p2->y);
	}
	```

## Căn chỉnh và đệm trong một cấu trúc

```c++
struct Point
{
	char x;
	int y;
};
```

![alt text](<images/Screenshot 2024-11-01 at 18.43.14.png>)

Thực tế:

![alt text](<images/Screenshot 2024-11-01 at 18.44.01.png>)

Phần màu xám là **phần đệm cấu trúc**. Phần này không dùng để lưu dữ liệu, trình biên dịch C tự đệm để căn chỉnh cho đúng kích thước yêu cầu bởi CPU.

CPU yêu cầu kiểu dữ liệu phải được **căn chỉnh** trên đúng hàng địa chỉ như sau:

- Kiểu 8bit: Không yêu cầu
- Kiểu 16bit: Nằm trên địa chỉ chẵn
- Kiểu 32bit: Nằm trên địa chỉ chia hết cho 4
- Kiểu 64bit: Nằm trên địa chỉ chia hết cho 8

Nếu có mảng trong một cấu trúc, mảng đó cũng được căn chỉnh dựa trên kiểu dữ liệu của các phần tử trong mảng.

## Nén cấu trúc

Đôi khi không được phép đệm cấu trúc. Ví dụ: khi đọc file ảnh, file ELF,... Trong C, ta có cú pháp:

```c++
#pragma pack(1)	// áp dụng cho toàn bộ các cấu trúc sau dòng này, cho tới khi dùng #pragma pack() để đặt lại.
```

hoặc 

```c++

struct <tên cấu trúc> {
    ...
}__attribute__((packed));	// Chỉ áp dụng cho cấu trúc hiện tại

```