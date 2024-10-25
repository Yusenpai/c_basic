# Bài 5.1: Sử dụng toán tử bitwise để thay đổi từng bit trong một số

## Mục lục

- [Bài 5.1: Sử dụng toán tử bitwise để thay đổi từng bit trong một số](#bài-51-sử-dụng-toán-tử-bitwise-để-thay-đổi-từng-bit-trong-một-số)
	- [Mục lục](#mục-lục)
	- [Vấn đề: Thay đổi 1 bit trong bộ nhớ mà không ảnh hưởng tới các bit khác.](#vấn-đề-thay-đổi-1-bit-trong-bộ-nhớ-mà-không-ảnh-hưởng-tới-các-bit-khác)
	- [Toán tử `|` (or) và toán tử `&` (and)](#toán-tử--or-và-toán-tử--and)
	- [Cú pháp thay đổi giá trị từng bit với mặt nạ bit](#cú-pháp-thay-đổi-giá-trị-từng-bit-với-mặt-nạ-bit)

## Vấn đề: Thay đổi 1 bit trong bộ nhớ mà không ảnh hưởng tới các bit khác.

Trong ngôn ngữ lập trình C, gần như không có toán tử nào hỗ trợ việc thay đổi 1 bit bất kỳ trong một vùng nhớ. Bởi bộ nhớ được thiết kế để truy cập và thao tác trên ít nhất là 8 bit (1 byte) một lần.

Tuy vậy, vẫn có cách để giải quyết bài toán trên sử dụng các toán tử bitwise.

## Toán tử `|` (or) và toán tử `&` (and)

Toán tử `|` thực hiện phép toán OR trên từng bit của hai số. Ví dụ:

```c++
uint8_t a = 0b00000101;		// 5 trong nhị phân là 0000 0101
uint8_t b = 0b00000011;		// 3 trong nhị phân là 0000 0011
uint8_t c = a | b; 			// Phép OR từng bit
printf("%d\n", c);  		// Kết quả là 0000 0111
```

Xét phép toán OR giữa hai bit A và B:

|A|B|A OR B|
|-|-|-	
|0|0|**0**
|1|0|**1**
|0|1|**1**
|1|1|**1**

Rút gọn:

| A   | B   | A OR B |
| --- | --- | ------ |
| A   | 0   | **A**  |
| X   | 1   | **1**  |

Ta thấy:
- Nếu B = 0, thì phép toán A OR B = A. Nói cách khác bit A được giữ nguyên. 
- Nếu B = 1 thì dù A bằng bao nhiêu thì A OR B = 1.

Sử dụng tính chất này, ta tạo ra một **mặt nạ bit** theo quy tắc sau:

- Bit nào của số `a` muốn giữ nguyên thì bit tương ứng của `b` là 0.
- Bit nào của số `a` muốn đổi thành 1 thì bit tương ứng của `b` là 1.

Giả sử ta có số `a`: `uint8_t a = 0b11110000;`
Ta muốn thay đổi bit 3 của số `a` thì số `b` sẽ như sau: `uint8_t b = 0b00001000;`. Số `b` được gọi là **mặt nạ bit (bit mask)**

```c++
uint8_t a = 0b11110000;	// Muốn thay đổi bit 3 của a thành 1
uint8_t b = 0b00001000;	// Bit 3 của b bằng 1, các bit khác là 0
uint8_t c = a | b;		// Kết quả sẽ là c = 0b11111000
a = c; // Gán lại vào a
```

Rút gọn:

```c++
uint8_t a = 0b11110000;	// Muốn thay đổi bit 3 của a thành 1
uint8_t b = (1 << 3);	// Tương đương với b = 0b00001000
uint8_t c = a | b;		// Kết quả sẽ là c = 0b11111000
a = c; // Gán lại vào a
```

hoặc:

```c++
uint8_t a = 0b11110000;	// Muốn thay đổi bit 3 của a thành 1
uint8_t a |= (1 << 3);
```

Phân tích tương tự với toán tử `&` (and), ta có cú pháp để chuyển một bit bất kỳ thành 0:

```c++
uint8_t a = 0b11111000;	// Muốn thay đổi bit 3 của a thành 0
uint8_t a &= ~(1 << 3);	// Bit mask lúc này là 0b11110111
```

## Cú pháp thay đổi giá trị từng bit với mặt nạ bit

- Đổi bit tại vị trí `n` thành 1:
```c++
a |= (1 << n);
```

- Đổi bit tại vị trí `n` thành 0:
```c++
a &= ~(1 << n);
```

Mặt nạ bit có thể ghép với nhau, cho phép ta đổi nhiều bit cùng lúc.

- Đổi bit tại vị trí `n1, n2, n3,...` thành 1:
```c++
a |= (1 << n1) | (1 << n2) | (1 << n3) | ...;
```

- Đổi bit tại vị trí `n1, n2, n3,...` thành 0:
```c++
a &= ~((1 << n1) | (1 << n2) | (1 << n3) | ...); // Chú ý dấu ngoặc tròn ngoài cùng
```