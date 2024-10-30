# Bài 9: Con trỏ trong C

## Mục lục

- [Bài 9: Con trỏ trong C](#bài-9-con-trỏ-trong-c)
	- [Mục lục](#mục-lục)
	- [Khái niệm về con trỏ](#khái-niệm-về-con-trỏ)
	- [Toán tử `*` và `&`](#toán-tử--và-)
	- [Các kiểu dữ liệu con trỏ](#các-kiểu-dữ-liệu-con-trỏ)
	- [Ép kiểu với con trỏ](#ép-kiểu-với-con-trỏ)
		- [Ép kiểu giữa các kiểu con trỏ](#ép-kiểu-giữa-các-kiểu-con-trỏ)
		- [Ép kiểu một con trỏ thành số nguyên và ngược lại](#ép-kiểu-một-con-trỏ-thành-số-nguyên-và-ngược-lại)
		- [Ép kiểu một số nguyên thành con trỏ hàm](#ép-kiểu-một-số-nguyên-thành-con-trỏ-hàm)
	- [Các phép toán với con trỏ](#các-phép-toán-với-con-trỏ)
		- [Các phép toán số học](#các-phép-toán-số-học)
	- [Con trỏ và hằng](#con-trỏ-và-hằng)
	- [Con trỏ tới con trỏ](#con-trỏ-tới-con-trỏ)
	- [Con trỏ và mảng](#con-trỏ-và-mảng)
	- [Con trỏ NULL](#con-trỏ-null)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
		- [Câu hỏi](#câu-hỏi)
		- [Bài tập](#bài-tập)


## Khái niệm về con trỏ

**Con trỏ** là một **biến** có thể lưu trữ địa chỉ của biến khác hoặc địa chỉ của một vùng nhớ.

Cú pháp khai báo một con trỏ:
```c++
<kiểu dữ liệu> * <tên biến>;
uint8_t *ptr;
char *ptr2;
```

Con trỏ lưu **giá trị địa chỉ**. Ví dụ:

```c++
#include <stdio.h>

int main()
{
	int a = 10;
	int *ptr = &a;
	printf("a's address is:%p\n", ptr);
	printf("sizeof(ptr) = %lu\n", sizeof(ptr));
	return 0;
}
```

```
➜  c_basic git:(main) ✗ ./main            
a's address is:0x16d427168
sizeof(ptr) = 8
```

Giá trị địa chỉ là **một số nguyên**. Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính. Đối với máy tính kiến trúc 64 bit, con trỏ thường có kích thước 8 byte (vì có 64 bit địa chỉ). Tương tự, máy tính 32 bit thì con trỏ chiếm 4 byte.

## Toán tử `*` và `&`

Toán tử `*` là toán tử **giải tham chiếu**. Toán tử này dùng để **truy cập tới vùng nhớ dữ liệu mà con trỏ tới**.

Toán tử `&` là toán tử **lấy địa chỉ của biến**. Toán tử trả về địa chỉ của biến.

Ví dụ:
```c++
int y = 5;
int *p = &y;	// &y trả về địa chỉ của y rồi gán vào p
*p = 15;  // Truy cập tới biến y qua con trỏ p
printf("Value of y after modification through pointer: %d\n", y);
```

> Lưu ý: Dấu `*` ở trong khai báo con trỏ và dấu `*` giải tham chiếu mang ý nghĩa khác nhau !

## Các kiểu dữ liệu con trỏ

Kiểu dữ liệu con trỏ được dẫn xuất **từ các kiểu dữ liệu cơ bản** và **các kiểu dữ liệu do người dùng tự định nghĩa**. 

Các kiểu dữ liệu được sử dụng khi **khai báo con trỏ** hoặc làm **kiểu trả về khi dùng toán tử `&`**.

- Con trỏ tới số nguyên:
  - `uint8_t *`
  - `uint16_t *`
  - `uint32_t *`
  - `uint64_t *`
- Con trỏ tới số thực:
  - `float *`
  - `double *`
- Con trỏ tới cấu trúc: Là con trỏ tới cấu trúc do người dùng tự định nghĩa. Học ở bài 10.

Ngoài ra còn các kiểu con trỏ đặc biệt khác:

- Con trỏ tới con trỏ: Là con trỏ lưu trữ địa chỉ của một con trỏ khác. Ví dụ:
  - `uint8_t **`: con trỏ tới con trỏ tới số nguyên 8 bit.
  - `char *****`

	> Lưu ý: Con trỏ a có thể trỏ tới con trỏ b, trong khi con trỏ b trỏ tới con trỏ a (?).

- Con trỏ tới kiểu `void`
  - `void *`: Đây là con trỏ trỏ tới vùng nhớ chưa biết trước kiểu dữ liệu.

- Con trỏ mảng: Là con trỏ trỏ tới một mảng. Ví dụ:
  
	```c++
	int (*pArr)[N]; // Khai báo con trỏ mảng pArr trỏ tới mảng có N phần tử.
	```

	> Lưu ý: **Con trỏ mảng** và **con trỏ tới phần tử đầu tiên của mảng** là khác nhau(?). Dùng toán tử `sizeof()` sẽ rõ!

- Con trỏ hàm: Là con trỏ trỏ tới một hàm, cho phép gọi hàm thông qua con trỏ này.
  
	Cú pháp: 

	```c++
	<kiểu trả về> (*tên con trỏ)(<danh sách kiểu tham số>);
	```

	Ví dụ:

	```c++

	int add(int a, int b) {
		return a + b;
	}

	// Khai báo con trỏ hàm funcPtr, với hai tham số kiểu int
	int (*funcPtr)(int, int); 

	int main(){
		// Gán địa chỉ của hàm add vào funcPtr
		funcPtr = add;

		// Gọi hàm add qua con trỏ funcPtr
		int result = funcPtr(10, 20);
		printf("Result: %d\n", result);  // Kết quả: 30
		return 0;
	}

	```

## Ép kiểu với con trỏ

### Ép kiểu giữa các kiểu con trỏ

Ép kiểu một con trỏ giữa các kiểu con trỏ bằng phương pháp ép kiểu tường minh. Ví dụ:

```c++
uint8_t a = 100;
uint16_t *ptrA = (uint16_t *) &a;	// Thiếu (uint16_t *) trình biên dịch cảnh cáo (hoặc không).

int32_t b = 13230;
int8_t *ptrB = (int8_t *) &b
```

Cần lưu ý khi ép kiểu con trỏ số nguyên và số thực:

```c++
#include <stdio.h>

int main(){
	int a = 1262;
	float *ptrA = (float *) &a;
	printf("Giá trị của a sau khi chuyển sang số thực: %f\n", *ptrA);

	float b = 1.34;
	int *ptrB = (int *)&b;
	printf("Giá trị của b sau khi chuyển sang số nguyên: %f\n", *ptrB);
}

// Thuật toán tính nghịch đảo căn bậc hai nhanh trong game Quake III Arena
float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;		   // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1); // wtf?
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y)); // 1st iteration
										 //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
	return y;
}
```

Con trỏ `void *` phải được ép kiểu trước khi sử dụng. Ví dụ:

```c++
void *p;
int a = 20;
p = &a;  // con trỏ void trỏ tới biến kiểu int

int *pInt = (int *)p;  // ép kiểu con trỏ void về int*
printf("Giá trị của a: %d\n", *pInt);  // Kết quả: 20
```

### Ép kiểu một con trỏ thành số nguyên và ngược lại

Khi con trỏ bị ép kiểu về một số nguyên, số nguyên đó sẽ lưu trữ giá trị là địa chỉ bộ nhớ mà con trỏ trỏ tới.

```c++
int a = 5;
int *p = &a;
long addr = (long)p;  // ép con trỏ thành số nguyên kiểu long
printf("Địa chỉ của a: %ld\n", addr);
```

> Lưu ý: Kiểu số nguyên phải đủ lớn để lưu trữ địa chỉ.

Tương tự, một số nguyên có thể bị ép kiểu thành một con trỏ.

```c++
int *p = (int *)0x7fff5fbffabc;  // Ép số nguyên thành con trỏ
// *p = 10; // có thể gây lỗi nếu địa chỉ không hợp lệ
```

> Lưu ý: Ép số nguyên thành con trỏ rồi truy cập tới vùng nhớ bằng con trỏ ***cực kì nguy hiểm***!!! Các hệ điều hành không cho phép và sẽ crash ứng dụng nếu cố tình.

### Ép kiểu một số nguyên thành con trỏ hàm

Tương tự, ta có thể ép kiểu một số nguyên thành một con trỏ hàm rồi gọi nó.

```c++
int (*funcPtr)(void) = int (*)(void)(0x12345678); // Ép số nguyên thành con trỏ hàm
funcPtr(); // Gọi hàm thông qua con trỏ hàm.
```

> Lưu ý: Nếu dữ liệu mà con trỏ hàm trỏ tới không phải là một hàm thì ?


## Các phép toán với con trỏ

Các phép toán với con trỏ gồm:

- Giải tham chiếu `*`
- Lấy địa chỉ của biến `&`
- Các phép toán số học
- Toán tử so sánh `==` `!=` `<` `>`  ...
- Toán tử truy cập mảng qua con trỏ `[]`

### Các phép toán số học

- Phép tăng `++`: Con trỏ sẽ trỏ tới vùng nhớ mới. Địa chỉ của con trỏ sẽ tăng lên ứng với kích thước dữ liệu mà con trỏ này trỏ tới.
- Phép giảm `--`: Con trỏ sẽ trỏ tới vùng nhớ mới. Địa chỉ của con trỏ sẽ giảm đi ứng với kích thước dữ liệu mà con trỏ này trỏ tới. 

	![](https://media.geeksforgeeks.org/wp-content/uploads/20230424100855/Pointer-Increment-Decrement.webp)
  
	```c++
	#include <stdio.h>
	int main()
	{
		int a = 22;
		int *p = &a;
		printf("p = %u\n", p);
		p++;
		printf("p++ = %u\n", p);
		p--;
		printf("p-- = %u\n", p);

		char c = 'a';
		char *r = &c;
		printf("r = %u\n", r);
		r++;
		printf("r++ = %u\n", r);
		r--;
		printf("r-- = %u\n", r); 
		return 0;
	}
	```

	Kết quả:
	```
	➜  c_basic git:(main) ✗ ./main            
	p   = 0x16d6a3168, 1835676008
	p++ = 0x16d6a316c, 1835676012
	p-- = 0x16d6a3168, 1835676008
	r   = 0x16d6a315f, 1835675999
	r++ = 0x16d6a3160, 1835676000
	r-- = 0x16d6a315f, 1835675999
	```

- Phép cộng/trừ con trỏ với một số: Đem số đó nhân với kích thước dữ liệu mà con trỏ trỏ tới, rồi cộng/trừ với địa chỉ của con trỏ.

	![](https://media.geeksforgeeks.org/wp-content/uploads/20230424100935/Pointer-Addition.webp)

> Lưu ý: các phép toán trên thường dùng để truy cập các phần tử trong mảng. Ví dụ:
>```c++
>	int arr[] = {10, 20, 30};
>	int *ptr = arr;
>	printf("%d\n", *(ptr + 1));  // Kết quả: 20
>```

- Phép cộng/trừ hai con trỏ cùng kiểu dữ liệu: Đem địa chỉ cộng/trừ nhau, rồi chia cho kích thước kiểu dữ liệu con trỏ trỏ tới.
- Phép so sánh giữa hai con trỏ: so sánh giá trị địa chỉ của hai con trỏ.
- Phép truy cập mảng bằng con trỏ: Coi con trỏ như mảng, rồi truy cập các phần tử y như mảng. Ví dụ:
	```c++
	int arr[] = {10, 20, 30};
	int *ptr = arr;
	printf("%d\n", ptr[1]);  // Kết quả: 20
	```

## Con trỏ và hằng

- Con trỏ tới hằng
- Con trỏ hằng (hằng con trỏ)
- Kết hợp hai loại trên

Con trỏ tới hằng là con trỏ trỏ tới một **hằng số**. Con trỏ này được dùng khi muốn truy cập tới một biến bằng con trỏ, nhưng không được phép thay đổi giá trị của biến đó. Ví dụ:

```c++
const int a = 10;
const int *p = &a;  // Con trỏ `p` trỏ tới hằng số `a`
```

Lưu ý: Con trỏ tới hằng khác với con trỏ hằng (hằng con trỏ). Con trỏ hằng là con trỏ có địa chỉ không thể thay đổi. Ví dụ:
```c++
int a = 10;
int *const p = &a;	// Khai báo một con trỏ hằng trỏ tới biến a. Con trỏ này không thể trỏ tới biến khác được nữa.
```
Kết hợp giữa của hai kiểu con trỏ trên ta được con trỏ không thể thay đổi địa chỉ cũng như không thể thay đổi giá trị mà nó trỏ tới.

```c++
const int a
const int *const p = &a;
```

## Con trỏ tới con trỏ

Ví dụ:
```c++
int a = 10;
int *p = &a;   // `p` trỏ tới `a`
int **pp = &p; // `pp` là con trỏ tới con trỏ `p`
```
Ứng dụng của con trỏ tới con trỏ:

- Dùng trong mảng động. Các hàm cấp phát động bộ nhớ sử dụng các con trỏ này
- Dùng để truy cập tới mảng của các chuỗi.
- Dùng trong mảng hai chiều

## Con trỏ và mảng

Con trỏ và mảng có mối liên hệ mật thiết với nhau:
- Tên của mảng chính là con trỏ trỏ tới phần tử đầu tiên của mảng. Ví dụ:
  
  ```c++
	int arr[3] = {10, 20, 30};
	int *ptr = arr;     // ptr trỏ tới phần tử đầu tiên của mảng
	printf("%d\n", *ptr);
  ```

  > Lưu ý: Tên của mảng `arr` trả về địa chỉ của phần tử đầu tiên trong mảng. Thế còn `&arr`? `&arr` trả về **con trỏ mảng**. Chúng có địa chỉ giống nhau, nhưng trỏ đến kiểu dữ liệu khác nhau (khác nhau thế nào?)

- Dùng con trỏ để truy cập mảng:

	```c++
	int arr[3] = {10, 20, 30};
	int *ptr = arr;

	printf("%d\n", *ptr);       // In ra 10
	printf("%d\n", *(ptr + 1)); // In ra 20
	printf("%d\n", *(ptr + 2)); // In ra 30
	```
- Dùng con trỏ để truyền một mảng vào hàm:

	Khi truyền một mảng vào một hàm, thực tế là bạn truyền địa chỉ của phần tử đầu tiên của mảng, nên hàm sẽ nhận một con trỏ.

	> Câu hỏi: Khi truyền một mảng vào hàm, thông tin nào về mảng đó mất đi?

## Con trỏ NULL

Con trỏ NULL là con trỏ trỏ tới một địa chỉ không hợp lệ, đó là 0. Con trỏ NULL được hiểu là không trỏ tới bất kì một vùng nhớ nào. Người ta hay kiểm tra tính hợp lệ của con trỏ bằng con trỏ NULL:

```c++
if (ptr != NULL) {
    // Sử dụng con trỏ `ptr`
} else {
    // Con trỏ chưa được khởi tạo hoặc không trỏ đến vùng nhớ nào
}
```

`NULL` được định nghĩa trong thư viện `<stddef.h>` hoặc `<stdio.h>`, mang giá trị là 0

## Câu hỏi và bài tập

### Câu hỏi

1. Toán tử `*` và `&` trong con trỏ dùng để làm gì?
2. Trong khai báo con trỏ 
   
	```c++
	int32_t *a;
	``` 
	
	và giải tham chiếu con trỏ 
	
	```c++
	*a = 10;
	```
	
	ý nghĩa của dấu `*` có giống nhau không?
3. Cú pháp ép kiểu một con trỏ thành kiểu con trỏ khác như thế nào?
4. Liệt kê các phép toán với con trỏ. Nêu ý nghĩa của chúng.
5. Có thể thay đổi giá trị một hằng số bằng con trỏ không?
6. Con trỏ tới con trỏ dùng khi nào?
7. Tên của một mảng có phải là con trỏ mảng không? Giải thích sự khác nhau giữa con trỏ mảng và con trỏ tới phần tử đầu tiên.
 
### Bài tập

1. Trên vi điều khiển STM32F103C8, thanh ghi `GPIOA->ODR` là thanh ghi 16 bit, điều khiển 16 chân PA0..15. Thanh ghi này có địa chỉ là `0x40010C0C`. Viết hàm điều khiển các chân PA0..15, với tham số là một số `uint16_t`, trả về kiểu `void`.

	```c++
	void GPIOA_Write(uint16_t data);
	```

2. Viết lại hàm `digitalWrite(pin, mode);` của thư viện Arduino, dùng để điều khiển các chân PA0..15 của STM32F103C8 như sau:
   
	```c++
	/// @brief Thay đổi giá trị ngõ ra của chân GPIO
	/// @param pin có giá trị từ 0..15, tương ứng với chân PA0..15
	/// @param mode giá trị ngõ ra. mode = 0 thì ngõ ra mức thấp, mode = 1 thì ngõ ra mức cao.
	void digitalWrite(uint8_t pin, uint8_t mode);
	```

3. Bạn có một mảng số `uint8_t nums[10];`. Viết một hàm in số lên màn hình theo quy tắc: mỗi số là một số 16 bit, được ghép từ phần tử `i` và `i+1` của `nums`, với `i` chẵn.
   
	```c++
	void print16bit(const uint8_t nums[]);
	```

