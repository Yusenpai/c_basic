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
	- [`union`](#union)
	- [`enum`](#enum)
	- [Từ khoá `typedef`](#từ-khoá-typedef)
	- [Bit field trong lập trình C](#bit-field-trong-lập-trình-c)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
		- [Câu hỏi](#câu-hỏi)
	- [Bài tập](#bài-tập)
	- [Bài tập thêm](#bài-tập-thêm)

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

## `union`

`union` tương tự như `struct`, nhưng khi khởi tạo, trình biên dịch sẽ chỉ cấp vùng nhớ cho thành phần chiếm nhiều bộ nhớ nhất.

```c++
union Number {
    int intValue;
    float floatValue;
    char charValue;
};

union Number numA;
numA.intValue = 100;

printf("Int Value: %d\n", numA.intValue);
printf("Float Value: %d\n", numA.floatValue);
printf("Char Value: %d\n", numA.charValue);
```

## `enum`

`enum` là một kiểu dữ liệu tự định nghĩa dùng để định nghĩa một tập hợp các hằng số nguyên có tên.

```c++
#include <stdio.h>

enum Weekday {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main() {
    enum Weekday today;
    today = WEDNESDAY;
    printf("Giá trị của today: %d\n", today); // In ra 3, vì WEDNESDAY có giá trị là 3
    printf("Giá trị của today: %d\n", WEDNESDAY); // Hoặc dùng thẳng WEDNESDAY

    return 0;
}
```

## Từ khoá `typedef`

`typedef` dùng để định nghĩa một tên kiểu mới cho một kiểu dữ liệu đã tồn tại.

Cú pháp:
```c++
typedef <kiểu_dữ_liệu> <tên_mới>;
```

Ví dụ:

```c++
typedef unsigned long int ulong;

ulong x = 1000000;
```

`typedef` thường được sử dụng kết hợp với `struct` và `union` để gọn cho việc khai báo biến cấu trúc:

```c++
typedef struct {
    int x;
    int y;
} Point;

Point p;	// Khai báo không cần từ khoá struct
```

## Bit field trong lập trình C

**Bit field** là một tính năng trong khai báo một `struct`, cho phép **cấp phát một số lượng bit nhất định** cho một thành phần của `struct`, thay vì cấp phát toàn bộ byte.

Ví dụ:

```c++
#include <stdio.h>

// Define a structure to represent the status of a device using bit fields
struct DeviceStatus {
    unsigned int power       : 1;  // 1 bit for power status (on/off)
    unsigned int mode        : 2;  // 2 bits for mode (0-3)
    unsigned int error       : 1;  // 1 bit for error status (no error/error)
};

int main() {
    struct DeviceStatus status;

    // Set initial values for the device status
    status.power = 1;   // Device is ON
    status.mode = 2;    // Mode set to 2
    status.error = 0;   // No error

    // Print initial values of the bit fields
    printf("Device Status:\n");
    printf("Power: %u\n", status.power);
    printf("Mode: %u\n", status.mode);
    printf("Error: %u\n", status.error);

    // Update some values in the device status
    status.power = 0;   // Turn OFF the device
    status.error = 1;   // Set error status

    // Print updated values of the bit fields
    printf("\nUpdated Device Status:\n");
    printf("Power: %u\n", status.power);
    printf("Mode: %u\n", status.mode);
    printf("Error: %u\n", status.error);

    return 0;
}
```

Kết hợp `struct`, `union` và `bitfield`:

```c++
#include <stdio.h>
#include <stdint.h>

typedef union
{
	struct
	{
		uint8_t red : 8;   // 8 bits for red
		uint8_t green : 8; // 8 bits for green
		uint8_t blue : 8;  // 8 bits for blue
	};

	struct
	{
		uint8_t r0 : 1, r1 : 1, r2 : 1, r3 : 1, r4 : 1, r5 : 1, r6 : 1, r7 : 1;
		uint8_t g0 : 1, g1 : 1, g2 : 1, g3 : 1, g4 : 1, g5 : 1, g6 : 1, g7 : 1;
		uint8_t b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
	};

	uint32_t rgb : 24; // 24 bits for combined RGB value
} RGBColor;

int main()
{
	RGBColor color;

	// Set color channels individually
	color.red = 255;	 // Red = 255 (0xFF)
	color.green = 127; // Green = 127 (0x7F)
	color.blue = 63;	 // Blue = 63 (0x3F)

	// Display the combined 24-bit RGB value
	printf("Combined RGB value: 0x%06X\n", color.rgb);
	for(int i = 0; i < 24; i++){
		printf("%d", color.rgb & (1 << (23-i)) ? 1 : 0);
		if((i + 1) % 8 == 0)
			printf(" ");
	}
	printf("\n");

	// Display individual color channel values
	printf("Red: %u, Green: %u, Blue: %u\n", color.red, color.green, color.blue);

	// Display individual bits of each channel
	printf("Red channel bits: %u%u%u%u%u%u%u%u\n",
		   color.r7, color.r6, color.r5, color.r4,
		   color.r3, color.r2, color.r1, color.r0);

	printf("Green channel bits: %u%u%u%u%u%u%u%u\n",
		   color.g7, color.g6, color.g5, color.g4,
		   color.g3, color.g2, color.g1, color.g0);

	printf("Blue channel bits: %u%u%u%u%u%u%u%u\n",
		   color.b7, color.b6, color.b5, color.b4,
		   color.b3, color.b2, color.b1, color.b0);

	return 0;
}
```

## Câu hỏi và bài tập

### Câu hỏi

1. Có mấy toán tử để truy cập tới các thành phần trong một cấu trúc?
2. Kích thước của các cấu trúc sau là bao nhiêu:

	```c++
	struct Example {
		int i;
		char c;
		double d;
		short s;
	};

	struct Person {
		char name[50];
		int age;    
		float height; 
	};

	struct Alien {
		char name[50];
		int age; 
		float height;
	} __attribute__((packed));

	union DataUnion {
		char type;       
		int id;          
		double value;  
	};
	```

3. Từ khoá `typedef` dùng để làm gì ?

## Bài tập

## Bài tập thêm

```c++
typedef struct
{
    __IO uint32_t CRL;   /*!< Port configuration register low,     Address offset: 0x00 */
    __IO uint32_t CRH;   /*!< Port configuration register high,    Address offset: 0x04 */
    __IO uint32_t IDR;   /*!< Port input data register,            Address offset: 0x08 */
    __IO uint32_t ODR;   /*!< Port output data register,           Address offset: 0x0C */
    __IO uint32_t BSRR;  /*!< Port bit set/reset register,         Address offset: 0x10 */
    __IO uint32_t BRR;   /*!< Port bit reset register,             Address offset: 0x14 */
    __IO uint32_t LCKR;  /*!< Port configuration lock register,    Address offset: 0x18 */
} GPIO_TypeDef;

#define GPIO_BASE 0x40010800
#define GPIOA ((GPIO_TypeDef *) GPIO_BASE)
```

