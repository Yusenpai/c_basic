# Bài 5: Toán tử trong C

## Mục lục

- [Bài 5: Toán tử trong C](#bài-5-toán-tử-trong-c)
	- [Mục lục](#mục-lục)
- [Các loại toán tử trong C](#các-loại-toán-tử-trong-c)
	- [Toán tử số học (Arithmetic Operators)](#toán-tử-số-học-arithmetic-operators)
	- [Toán tử một ngôi](#toán-tử-một-ngôi)
	- [Toán tử so sánh](#toán-tử-so-sánh)
	- [Toán tử logic](#toán-tử-logic)
	- [Toán tử bitwise](#toán-tử-bitwise)
	- [Toán tử gán (Assignment Operators)](#toán-tử-gán-assignment-operators)
	- [Các toán tử khác](#các-toán-tử-khác)
		- [`sizeof()`](#sizeof)
		- [Toán tử điều kiện ba ngôi](#toán-tử-điều-kiện-ba-ngôi)
		- [Truy cập phần tử trong `struct`](#truy-cập-phần-tử-trong-struct)
		- [Con trỏ](#con-trỏ)
	- [Thứ tự thực hiện phép toán (Operator Precedence)](#thứ-tự-thực-hiện-phép-toán-operator-precedence)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
	- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

# Các loại toán tử trong C

Toán tử trong C là các ký hiệu dùng để thực hiện các phép toán trên các toán hạng. Trong C có các loại toán tử:

- **Toán tử số học** (Arithmetic Operators)
- **Toán tử so sánh** (Relational Operators)
- **Toán tử logic** (Logical Operators)
- **Toán tử bitwise** (Bitwise Operators)
- **Toán tử gán** (Assignment Operators)
- **Toán tử khác**

## Toán tử số học (Arithmetic Operators)
Toán tử số học dùng để thực hiện các phép tính cơ bản như cộng, trừ, nhân, chia và lấy phần dư,...
|Toán tử|	Mô tả	|Ví dụ|
|-|-|-|
|+		|Cộng		|a + b|
|-		|Trừ		|a - b|
|*		|Nhân		|a * b|
|/		|Chia		|a / b|
|%		|Chia lấy dư|a % b (chỉ dùng cho số nguyên)|
|++			|Tăng giá trị lên 1				|++a, a++|
|--			|Giảm giá trị xuống 1			|--a, a--|
|+			|Giá trị dương (positive)		|+a		|
|-			|Lấy nghịch đảo		|-a		|

## Toán tử một ngôi

|Toán tử	|Mô tả							|Ví dụ	|
|-|-|-|
|!			|Phủ định (logical NOT)			|!a		|
|~			|Phủ định bitwise (bitwise NOT)	|~a		|
|*			|Giải tham chiếu				|*ptr	|
|&			|Lấy địa chỉ của biến			|&a		|
|sizeof()	|Kích thước vùng nhớ của biến	|sizeof(a)|

## Toán tử so sánh
Toán tử so sánh và toán tử logic giúp thực hiện các phép so sánh và kiểm tra điều kiện.

|Toán tử	|Mô tả				|Ví dụ|
|-|-|-|
|==|	Bằng nhau			|a == b|
|!=|	Khác nhau			|a != b|
|>|		Lớn hơn				|a > b|
|<|		Nhỏ hơn				|a < b|
|>=|	Lớn hơn hoặc bằng	|a >= b|
|<=|	Nhỏ hơn hoặc bằng	|a <= b|

## Toán tử logic

|Toán tử	|Mô tả		|Ví dụ
|-|-|-|
|&&			|AND logic	|a && b
|&#124;&#124;|OR logic	|a &#124;&#124; b
|!			|NOT logic	|!a

## Toán tử bitwise
Toán tử bitwise thực hiện phép toán trên từng bit của toán hạng.

|Toán tử	|Mô tả			|Ví dụ
|-|-|-|
|&			|AND bitwise		|a & b
|&#124;		|OR bitwise	|	a &#124; b
|^			|XOR bitwise		|a ^ b
|~			|NOT bitwise	|	~a
|<<			|Dịch bit trái	|a << 1
|>>			|Dịch bit phải	|a >> 1

## Toán tử gán (Assignment Operators)

Toán tử gán dùng để gán giá trị cho biến. Các toán tử gán mở rộng cho phép thực hiện phép toán kết hợp với việc gán.

|Toán tử	|Mô tả					|Ví dụ
|-|-|-|
|=			|Gán					|	a = b
|+=			|Cộng rồi gán			|a += b
|-=			|Trừ rồi gán			|	a -= b
|*=			|Nhân rồi gán			|a *= b
|/=			|Chia rồi gán			|a /= b
|%=			|Chia lấy dư rồi gán	|	a %= b
|&=			|AND rồi gán			|	a &= b
|&#124;=	|OR rồi gán| a &#124;= b
|^=			|XOR rồi gán			|	a ^= b
|<<=		|Dịch trái rồi gán		|a <<= b
|>>=		|Dịch phải rồi gán		|a >>= b

## Các toán tử khác

### `sizeof()`

Toán tử `sizeof()` trả về kích thước (số byte) của một kiểu dữ liệu hoặc biến.

```c++
int x;
printf("Kích thước của int: %zu bytes\n", sizeof(int));
printf("Kích thước của biến x: %zu bytes\n", sizeof(x));
```

### Toán tử điều kiện ba ngôi

Toán tử ba ngôi `(? :)` là một cách ngắn gọn để viết câu lệnh if-else. Cú pháp:

```c++
<điều kiện> ? <biểu thức nếu đúng> : <biểu thức nếu sai>;
```

Ví dụ:

```c++
int a = 10, b = 20;
int max = (a > b) ? a : b;  // max sẽ là 20
```

### Truy cập phần tử trong `struct`

|Toán tử| Mô tả| Ví dụ
|-|-|-
|.|Truy cập trực tiếp tới thành phần trong `struct`|s1.age = 21
|->|Truy cập thành phần của `struct` khi có con trỏ tới `struct`| ptr->age = 21

### Con trỏ

| Toán tử | Mô tả                                                        | Ví dụ         |
| ------- | ------------------------------------------------------------ | ------------- |
| *       | Giải tham chiếu. Truy cập giá trị mà con trỏ trỏ tới.          |   int y = *p; |
| &      | Trả về địa chỉ của biến | int *p = &x;  |

## Thứ tự thực hiện phép toán (Operator Precedence)

Thứ tự thực hiện phép toán xác định trình tự thực hiện các phép toán khi có nhiều toán tử xuất hiện trong cùng một biểu thức, theo thứ tự:

1.	Dấu ngoặc ( ) luôn được ưu tiên trước.
2.	Toán tử 1 ngôi: `++` `--` `!` `~` v.v.
3.	Toán tử số học. Các toán tử `*` `/` `%` có ưu tiên cao hơn toán tử `+` `-`
4.	Toán tử so sánh: `==` `!=` `>` `<` `>=` `<=`
5.	Toán tử gán: `=` `+=` `-=` v.v.

## Câu hỏi và bài tập

1. Viết code kiểm tra một số chẵn dùng toán tử điều kiện ba ngôi
2. Cho một biến `a`: `uint8_t a = 0b11110000`. Viết code để thay đổi bit 3 của `a` thành 1, mà không làm thay đổi các bit khác.
3. Cũng biến `a`, viết code để thay đổi bit 6 và bit 7 của số `a` thành 0, mà không làm thay đổi các bit khác.
4. Viết đoạn chương trình in số `a` dài 8 bit lên màn hình, dưới dạng số nhị phân.

## Tài liệu tham khảo