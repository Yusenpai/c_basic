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
		- [5. Tên mảng trùng với con trỏ tới phần tử đầu tiên](#5-tên-mảng-trùng-với-con-trỏ-tới-phần-tử-đầu-tiên)
		- [6. Không kiểm tra nếu truy cập tới chỉ số nằm ngoài mảng](#6-không-kiểm-tra-nếu-truy-cập-tới-chỉ-số-nằm-ngoài-mảng)
		- [7. Mảng tiêu giảm thành con trỏ](#7-mảng-tiêu-giảm-thành-con-trỏ)
	- [Truyền tham số là một mảng vào hàm](#truyền-tham-số-là-một-mảng-vào-hàm)
	- [Chuỗi ký tự](#chuỗi-ký-tự)
	- [Các thao tác với mảng và chuỗi ký tự trong thư viện `string.h`](#các-thao-tác-với-mảng-và-chuỗi-ký-tự-trong-thư-viện-stringh)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
		- [Câu hỏi](#câu-hỏi)
		- [Bài tập](#bài-tập)
		- [Bài tập thêm](#bài-tập-thêm)


## Mảng một chiều trong C

Mảng là:

Các phần tử trong mảng sắp xếp ... trong bộ nhớ.

Hình minh hoạ sự sắp xếp các phần tử trong mảng:

![]()

Cú pháp khai báo mảng một chiều:

```c++

```

Ví dụ:

```c++

```

## Các tính chất của mảng một chiều

### 1. Kích thước cố định

Kích thước của mảng phải được chỉ rõ khi khai báo. Ví dụ:

```c++

```

Dùng `sizeof()` để đếm số phần tử trong mảng:

```c++

```

### 2. Đồng nhất về kiểu dữ liệu

Các phần tử trong mảng có:

### 3. Các phần tử nằm cạnh nhau trong bộ nhớ

Các phần tử...

### 4. Truy cập ngẫu nhiên (truy cập tới bất kỳ phần tử nào)

Có hai cách truy cập tới mảng: Dùng `[]` hoặc con trỏ.

Ví dụ:

```c++

```

### 5. Tên mảng trùng với con trỏ tới phần tử đầu tiên

Ví dụ:

```c++

```

### 6. Không kiểm tra nếu truy cập tới chỉ số nằm ngoài mảng

Ví dụ:

```c++

```

### 7. Mảng tiêu giảm thành con trỏ

Ví dụ:

```c++

```

## Truyền tham số là một mảng vào hàm

Ví dụ:

```c++

```

## Chuỗi ký tự

Chuỗi ký tự là:

Chuỗi ký tự kết thúc bằng ký tự:

Khai báo và khởi tạo một chuỗi ký tự:

```c++

```

## Các thao tác với mảng và chuỗi ký tự trong thư viện `string.h`

- `memcpy`

	```c++

	```

- `memmove`

	```c++
	
	```

- `strcpy`

	```c++
	
	```

- `memset`

	```c++
	
	```

- `strlen`

	```c++
	
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