# Bài 9: Con trỏ trong C

## Khái niệm về con trỏ

Khái niệm:

Khai báo:

## Toán tử `*` và `&`

[//]: # (Các toán tử dùng để làm gì? Mỗi cái một ví dụ)

## Các kiểu dữ liệu con trỏ

[//]: # (Một số kiểu dữ liệu con trỏ? Cho ví dụ?)

[//]: # (Ép kiểu giữa các kiểu con trỏ thế nào? Ép kiểu từ số nguyên thành con trỏ thế nào? Ép kiểu từ con trỏ thành số nguyên thế nào?)

## Các phép toán với con trỏ

[//]: # (Có bao nhiêu phép toán, gồm các phép nào? Mỗi cái một ví dụ. Cái nào hay dùng để truy cập phần tử trong mảng ?)

[//]: # (Với hai con trỏ có kiểu con trỏ khác nhau, ví dụ uint8_t* và uint16_t*, các phép toán con trỏ có gì thay đổi không?)

## Con trỏ hằng

[//]: # (Con trỏ hằng là gì? Cú pháp khai báo? Dùng để làm gì ?)

## Con trỏ tới con trỏ

[//]: # (Con trỏ tới con trỏ là gì? Cú pháp khai báo? Dùng để làm gì?)

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
 
### Bài tập

1. Trên vi điều khiển STM32F103C8, thanh ghi `GPIOA->ODR` là thanh ghi 16 bit, điều khiển 16 chân PA0..15. Thanh ghi này có địa chỉ là `0x40010C0C`. Viết hàm điều khiển các chân PA0..15, với tham số là một số `uint16_t`, trả về kiểu `void`.
	```c++
	void GPIOA_Write(uint16_t data);
	```
2. Bạn có một mảng số `uint8_t nums[10];`. Viết một hàm in số lên màn hình theo quy tắc: mỗi số là một số 16 bit, được ghép từ phần tử `i` và `i+1` của `nums`, với `i` chẵn.
	```c++
	void print16bit(const uint8_t nums[]);
	```


