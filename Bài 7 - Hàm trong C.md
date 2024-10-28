# Bài 7: Hàm trong C

## Mục lục

- [Bài 7: Hàm trong C](#bài-7-hàm-trong-c)
	- [Mục lục](#mục-lục)
	- [Khai báo, định nghĩa hàm](#khai-báo-định-nghĩa-hàm)
		- [Khai báo hàm](#khai-báo-hàm)
		- [Định nghĩa hàm](#định-nghĩa-hàm)
	- [Tham số và trả về](#tham-số-và-trả-về)
	- [Các kỹ thuật truyền tham số: truyền bằng giá trị và truyền bằng tham chiếu.](#các-kỹ-thuật-truyền-tham-số-truyền-bằng-giá-trị-và-truyền-bằng-tham-chiếu)
		- [Truyền giá trị](#truyền-giá-trị)
		- [Truyền tham chiếu](#truyền-tham-chiếu)
	- [Hàm main()](#hàm-main)
	- [Con trỏ hàm và hàm Callback](#con-trỏ-hàm-và-hàm-callback)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)
		- [Câu hỏi](#câu-hỏi)
		- [Bài tập](#bài-tập)
	- [Bài tập thêm](#bài-tập-thêm)


## Khai báo, định nghĩa hàm

### Khai báo hàm

Khai báo hàm là:

Cú pháp khai báo hàm:
```c++

```

Khai báo hàm với kiểu trả về là `void`:
```c++

```

Khai báo hàm với kiểu trả về là `uint32_t` với 3 tham số kiểu `uint8_t`, `char[]` và `I2C_HandleTypedef *`:
```c++

```

### Định nghĩa hàm

Định nghĩa hàm là:

## Tham số và trả về

Tham số của hàm là: 

Từ khoá `return` mang ý nghĩa:

## Các kỹ thuật truyền tham số: truyền bằng giá trị và truyền bằng tham chiếu.

### Truyền giá trị

Truyền giá trị là:

Ví dụ:

```c++

```

### Truyền tham chiếu

Truyền tham chiếu là:

Ví dụ:

```c++

```

## Hàm main()

Hàm `main()` là:

Khai báo hàm `main()` trả về kiểu int với tham số:

```c++

```

Khai báo hàm `main()` trả về kiểu int không có tham số:

```c++

```

Khai báo hàm `main()` trả về kiểu void không có tham số:

```c++

```

Ý nghĩa giá trị trả về của hàm `main()`:

`return 0`:

`return 1`:

## Con trỏ hàm và hàm Callback

Con trỏ hàm là:

Cú pháp khai báo con trỏ hàm:

```c++

```

Hàm callback là:

Ví dụ sử dụng con trỏ hàm và hàm callback:

```c++

```

## Câu hỏi và bài tập

### Câu hỏi

1. Khai báo hàm khác gì với định nghĩa hàm ?
2. Dự đoán và giải thích kết quả của đoạn code sau:

	```c++
	#include <stdio.h>

	void printHello(){
		printf("hello");
		return;
		printf(" world\n");
	}

	int main(){
		printHello();
		return 0;
	}
	```

3. Dự đoán và giải thích kết quả của đoạn code sau:

	```c++
	#include <stdio.h>

	void funcA(int a){
	a = a + 1;
	}

	void funcB(int *a){
	*a = *a + 1;
	}

	int main(){
	int a = 10;

	funcA(a);
	printf("%d\n", a);

	funcB(&a);
	printf("%d\n", a);

	return 0;
	}
	```
### Bài tập

1. Viết hàm nhận hai tham số, giá trị trả về là kết quả tổng hai số.
2. Viết hàm hoán đổi hai số `a` và `b`. Dùng con trỏ để thay đổi giá trị của `a` và `b`. Trả về `void`.
## Bài tập thêm

1. Khi nào thì nên truyền giá trị, khi nào thì truyền tham chiếu?
2. Khi nào thì dùng hàm callback và con trỏ hàm ?