# Bài 3: Kiểu dữ liệu trong C

## Mục lục

- [Bài 3: Kiểu dữ liệu trong C](#bài-3-kiểu-dữ-liệu-trong-c)
	- [Mục lục](#mục-lục)
	- [Kiểu dữ liệu trong C](#kiểu-dữ-liệu-trong-c)
	- [Kiểu số nguyên](#kiểu-số-nguyên)
	- [Kiểu số thực](#kiểu-số-thực)
	- [Kiểu ký tự](#kiểu-ký-tự)
	- [Kiểu `bool`](#kiểu-bool)
	- [Kiểu `void`](#kiểu-void)
	- [Literal (hằng số)](#literal-hằng-số)
		- [Hằng số số nguyên](#hằng-số-số-nguyên)
		- [Hằng số số thực](#hằng-số-số-thực)
		- [Hằng số ký tự và chuỗi](#hằng-số-ký-tự-và-chuỗi)
	- [Ép kiểu trong C](#ép-kiểu-trong-c)
		- [Ép kiểu ngầm định](#ép-kiểu-ngầm-định)
		- [Ép kiểu tường minh](#ép-kiểu-tường-minh)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
	- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

## Kiểu dữ liệu trong C

**Kiểu dữ liệu** trong ngôn ngữ lập trình C xác định loại và kích thước của dữ liệu mà biến có thể lưu trữ.

Có ba loại kiểu dữ liệu chính:
- Kiểu dữ liệu cơ bản: gồm các kiểu số nguyên, số thực, ký tự.
- Kiểu dữ liệu dẫn xuất: gồm các kiểu mảng, con trỏ, hàm.
- Kiểu dữ liệu tự định nghĩa: là các kiểu dữ liệu người dùng tự định nghĩa.

Bài này chỉ nói tới các kiểu dữ liệu cơ bản.

## Kiểu số nguyên

Số nguyên gồm các số nguyên dương (1, 2, 3,...), các đối số(-1, -2, -3,...) và số 0. Có 5 loại kiểu dữ liệu dùng để lưu trữ các số nguyên:

- `char`: chiếm 1 byte bộ nhớ. Giá trị từ -2^7 đến 2^7-1
- `short`: chiếm 2 byte bộ nhớ. Giá trị từ -2^15 đến 2^15 - 1
- `int`: chiếm 4 byte bộ nhớ. Giá trị từ -2^31 đến 2^31-1
- `long`: chiếm 4 byte bộ nhớ. Tương tự `int`
- `long long`: chiếm 8 byte bộ nhớ. Giá trị từ -2^63 đến 2^63 - 1.

> Lưu ý: số lượng byte mỗi kiểu dữ liệu chiếm phụ thuộc vào trình biên dịch và kiến trúc CPU. Con số ở trên từ trình biên dịch C cho vi điều khiển STM32.

Thêm từ khoá `unsigned`, ta được kiểu dữ liệu **số nguyên không âm**:

- `unsigned char`: Giá trị từ 0 đến 255
- `unsigned short`: Giá trị từ 0 đến 65535
- `unsigned int`: Giá trị từ 0 đến 4,294,967,295
- `unsigned long`: Tương tự `int`
- `unsigned long long`: Giá trị từ 0 đến 2^64 - 1.

Để rút ngắn tên kiểu dữ liệu và tăng tính tương thích của code giữa các kiến trúc CPU, chuẩn C99 thêm vào các kiểu dữ liệu thay thế, định nghĩa trong thư viện chuẩn `stdint.h`:

- `int8_t`: tương tự với `char`
- `int16_t`: tương tự với `short`
- `int32_t`: tương tự với `int` và `long`
- `int64_t`: tương tự với `long long`

Với các số nguyên không âm:

- `uint8_t`: tương tự với `unsigned char`
- `uint16_t`: tương tự với `unsigned short`
- `uint32_t`: tương tự với `unsigned int` và `unsigned long`
- `uint64_t`: tương tự với `unsigned long long`

Ví dụ:

```c++
int8_t a = 100;
uint8_t b = 255U; // U hoặc u được dùng cho số không âm
int32_t c = -12314;
uint64_t d = 9999999L; // L hoặc L được dùng cho kiểu long int
```

## Kiểu số thực

Có hai kiểu số thực trong C:

- `float`: kiểu số thực dấu chấm động chiếm 4 byte. Từ 1.2E-38 đến 3.4E+38, độ chính xác khoảng 6-7 chữ số thập phân.
- `double`: kiểu số thực dấu chấm động chiếm 4 hoặc 8 byte. 
- `long double`: kiểu số thực dấu chấm động chiếm 8 hoặc 12 hoặc 16 byte. 

Kiểu `float` được hỗ trợ trên vi điều khiển. Kiểu `double` còn phụ thuộc vào phần cứng và trình biên dịch. Còn kiểu `long double` rất ít khi sử dụng và thường bị hạ xuống tương đương kiểu `double`.

Ví dụ:

```c++
float a = 1.35f;	// Chữ f được dùng số là kiểu float.
float a = 1.35;	// Chữ f được dùng số là kiểu float.
double b = 3.141592654;
double b = 3.141592654f;
```

## Kiểu ký tự

Kiểu kí tự là kiểu `char`.

Ví dụ:

```c++
char a = 'c'; // Lưu ký tự 'c' vào biến a
int8_t b = 'c'; // Tương tự
uint8_t d = 'c'; // Tương tự
```

## Kiểu `bool`

Kiểu `bool` là kiểu luận lý đúng sai. Kiểu này được thêm vào từ C99, được định nghĩa trong thư viện chuẩn `stdbool.h` và từ khoá `_Bool`. Kiểu này tương đương với kiểu `unsigned char` và `uint8_t`.

## Kiểu `void`

Kiểu `void` được hiểu là không có giá trị nào. Kiểu `void` thường được dùng làm kiểu trả về của hàm.

## Literal (hằng số)

**Literal** (tạm dịch: hằng số) là giá trị cụ thể được sử dụng trực tiếp trong code, không thay đổi trong suốt quá trình thực thi. Ví dụ:

### Hằng số số nguyên

- Số thập phân: 10, -5, 990uL
- Số thập lục phân: 0x0F23
- Số nhị phân: 0b0101010

### Hằng số số thực

- Số thực chấm động kiểu `float`: 3.4f, 10E4f
- Số thực chấm động kiểu `double`: 3.4, 10E4

### Hằng số ký tự và chuỗi

- Ký tự: 'A', 'b', 'c'
- Chuỗi: "acbasdas", "a", "Hello World\n"

## Ép kiểu trong C

Ép kiểu là việc chuyển dữ liệu của một biến từ kiểu dữ liệu này sang kiểu dữ liệu khác. Trong C có hai loại ép kiểu:

- Ép kiểu ngầm định: C tự động chuyển đổi kiểu dữ liệu khi cần thiết.

- Ép kiểu tường minh: người lập trình phải chỉ ra việc chuyển đổi một cách rõ ràng

### Ép kiểu ngầm định

Ép kiểu ngầm định được tự động thực hiện, thường là từ kiểu dữ liệu nhỏ hơn sang kiểu dữ liệu lớn hơn.

Ví dụ:
```c++
int a = 10;
float b = 5.5;
float result = a + b; // `a` tự động được chuyển sang kiểu `float` trước khi thực hiện phép cộng
```

### Ép kiểu tường minh

Người lập trình có thể ép kiểu tường minh bằng cú pháp:


`(<kiểu dữ liệu mới>) <biểu thức>;`

Ví dụ:

```c++
double x = 9.7;
int y = (int) x;  // Kết quả: y sẽ là 9

int num = 65;
char c = (char) num;  // Kết quả: c sẽ là ký tự 'A' (vì 65 là mã ASCII của 'A')
```

> Lưu ý: Ép kiểu có thể gây ra mất mát dữ liệu. Khi ép từ kiểu `float` sang `int`, phần thập phân bị mất. Hoặc khi khai báo `uint8_t a = 1000`, số `1000` được ép kiểu ngầm định để giữ lại 8 bit thấp và gán vào `a`. Giá trị của `a` là `232` (tại sao ?).

## Câu hỏi và bài tập

1. Liệt kê các kiểu dữ liệu cơ bản
2. Sự khác nhau giữa hằng số (biến khai báo bằng từ khoá `const`) và hằng (literal)
3. Có mấy loại ép kiểu ? Vì sao ép kiểu có thể gây ra mất mát dữ liệu ?
4. Tính giá trị của các biến khi thực hiện các phép gán sau:
```c++
int8_t a = 1000;
uint8_t b = -100;
uint16_t c = (uint16_t)1.256f;
```
## Tài liệu tham khảo