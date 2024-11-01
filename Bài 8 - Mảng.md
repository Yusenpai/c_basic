# Bài 8: Mảng trong C

## Mục lục

- [Bài 8: Mảng trong C](#bài-8-mảng-trong-c)
	- [Mục lục](#mục-lục)
	- [Mảng một chiều trong C](#mảng-một-chiều-trong-c)
	- [Các tính chất của mảng một chiều](#các-tính-chất-của-mảng-một-chiều)
		- [1. Kích thước cố định](#1-kích-thước-cố-định)
		- [2. Đồng nhất về kiểu dữ liệu](#2-đồng-nhất-về-kiểu-dữ-liệu)
		- [3. Các phần tử nằm cạnh nhau trong bộ nhớ](#3-các-phần-tử-nằm-cạnh-nhau-trong-bộ-nhớ)
		- [4. Truy cập ngẫu nhiên (truy cập tới bất kỳ phần tử nào)](#4-truy-cập-ngẫu-nhiên-truy-cập-tới-bất-kỳ-phần-tử-nào)
		- [5. Tên mảng là con trỏ tới phần tử đầu tiên](#5-tên-mảng-là-con-trỏ-tới-phần-tử-đầu-tiên)
		- [6. Không kiểm tra nếu truy cập tới chỉ số nằm ngoài mảng](#6-không-kiểm-tra-nếu-truy-cập-tới-chỉ-số-nằm-ngoài-mảng)
		- [7. Mảng tiêu giảm thành con trỏ](#7-mảng-tiêu-giảm-thành-con-trỏ)
	- [Chuỗi ký tự](#chuỗi-ký-tự)
	- [Các thao tác với mảng và chuỗi ký tự trong thư viện `string.h`](#các-thao-tác-với-mảng-và-chuỗi-ký-tự-trong-thư-viện-stringh)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
		- [Câu hỏi](#câu-hỏi)
		- [Bài tập](#bài-tập)
		- [Bài tập thêm](#bài-tập-thêm)


## Mảng một chiều trong C

Mảng là một tập hợp các phần tử có ***cùng kiểu dữ liệu***, được ***xếp cạnh nhau trong bộ nhớ***.

![](https://media.geeksforgeeks.org/wp-content/uploads/20230302091959/Arrays-in-C.png)

Cú pháp khai báo mảng một chiều:

```c++
<kiểu dữ liệu> <tên mảng>[<số phần tử>];
```

Ví dụ:

```c++

int array1[10];

uint8_t array2[] = {1, 2, 3};

struct Vector2D {
    float x;
    float y;
};

struct Vector2D array3[1000];

```

## Các tính chất của mảng một chiều

### 1. Kích thước cố định

Kích thước của mảng phải được chỉ rõ khi khai báo. Ví dụ:

```c++
int array1[10];
uint8_t array2[] = {1, 2, 3};

int array3[]; // Lỗi

```

Dùng `sizeof()` để đếm số phần tử trong mảng:

```c++
uint8_t array2[] = {1, 2, 3};

int n = sizeof(array2) / sizeof(uint8_t);

printf("Số phần tử của mảng: %d\n", n);

```

### 2. Đồng nhất về kiểu dữ liệu

Các phần tử trong mảng có chung một kiểu dữ liệu.

### 3. Các phần tử nằm cạnh nhau trong bộ nhớ

Các phần tử được đặt cạnh nhau trong bộ nhớ. Do đó có thể dùng con trỏ để truy cập tới từng phần tử trong mảng. Ví dụ:

```c++
int array[] = {10, 20, 30, 40, 50};   // Khai báo một mảng gồm 5 phần tử
int *ptr = array;                     // Con trỏ trỏ tới phần tử đầu tiên của mảng

int size = sizeof(array) / sizeof(array[0]);   // Tính số phần tử của mảng

printf("Các phần tử của mảng là:\n");
for (int i = 0; i < size; i++) {
	printf("Phần tử %d: %d\n", i, *(ptr + i)); // Truy cập phần tử thông qua con trỏ
}
```

### 4. Truy cập ngẫu nhiên (truy cập tới bất kỳ phần tử nào)

Có hai cách truy cập tới mảng: Dùng `[]` hoặc con trỏ.

### 5. Tên mảng là con trỏ tới phần tử đầu tiên

Ví dụ:

```c++
int array[] = {10, 20, 30, 40, 50};   // Khai báo một mảng gồm 5 phần tử
printf("%d\n", *array);
```

### 6. Không kiểm tra nếu truy cập tới chỉ số nằm ngoài mảng

Ví dụ:

```c++
int array[5] = {10, 20, 30, 40, 50};
// In các giá trị hợp lệ
for (int i = 0; i < 5; i++)
{
	printf("array[%d] = %d\n", i, array[i]);
}
// Truy cập chỉ số nằm ngoài mảng
for (int i = 5; i < 7; i++)
{
	printf("array[%d] = %d\n", i, array[i]); // Chỉ số 5 và 6 nằm ngoài mảng
}
```

### 7. Mảng tiêu giảm thành con trỏ

Tên mảng bị tiêu giảm thành con trỏ trong hai trường hợp:

- Gán tên mảng cho một con trỏ: `int *ptr = array;`
- Truyền mảng vào một hàm

Ví dụ:

```c++
#include <stdio.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    printArray(array, 5); // array tiêu giảm thành con trỏ
    return 0;
}
```

## Chuỗi ký tự

Chuỗi ký tự là mảng của các ký tự, kết thúc bằng ký tự `'\0'`, ứng với số `0`.

Khai báo và khởi tạo một chuỗi ký tự:

```c++

char str1[] = "hello"; // Chuỗi "hello" đã tự động thêm \0 vào đuôi.

char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Cần thêm '\0' để đánh dấu kết thúc.

```

Câu hỏi: mảng `str1[]` có bao nhiêu phần tử ?

## Các thao tác với mảng và chuỗi ký tự trong thư viện `string.h`

- `memcpy`: Sao chép một vùng nhớ từ vị trí này sang vị trí khác.

	```c++
	void *memcpy(void *dest, const void *src, size_t n);
	```

- `strcpy`

	```c++
	char *strcpy(char *dest, const char *src);
	```

- `memset`

	```c++
	void *memset(void *s, int c, size_t n);
	```

- `strlen`

	```c++
	size_t strlen(const char *s);
	```

Tham khảo thêm ở <https://cplusplus.com/reference/cstring/>
## Câu hỏi và bài tập

### Câu hỏi

1. Làm sao để đếm số phần tử trong mảng dùng toán tử `sizeof()`?
2. Cú pháp dùng con trỏ truy cập tới phần tử thứ `i` trong mảng?
3. Một mảng là tham số của một hàm. Bên trong hàm, có thể dùng toán tử `sizeof()` để đếm số phần tử của mảng không? Viết code chứng minh câu trả lời của bạn.
4. Làm sao để biết chuỗi ký tự kết thúc?
5. Mảng `a` được khai báo như sau:
   
   ```c++
   uint8_t a[] = "hello";
   ```

   Mảng `a` có bao nhiều phần tử ?

### Bài tập

1. Viết hàm trả về vị trí của số `a` trong mảng. Nếu không tìm thấy thì trả về -1.
2. Viết chương trình sắp xếp theo thứ tự tăng dần một mảng số nguyên `n` phần tử.
3. Viết chương trình để tách một chuỗi thành các từ dựa trên khoảng trắng. In ra các từ này.

### Bài tập thêm

1. Viết hàm ghép hai chuỗi `word1` và `word2` và lưu vào `word3`. Trả về `void`.