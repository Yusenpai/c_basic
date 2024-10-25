# Bài 4.1: Sử dụng `printf()` và `scanf()` trên vi điều khiển

## Mục lục

- [Bài 4.1: Sử dụng `printf()` và `scanf()` trên vi điều khiển](#bài-41-sử-dụng-printf-và-scanf-trên-vi-điều-khiển)
	- [Mục lục](#mục-lục)
	- [`printf()`](#printf)
	- [`scanf()`](#scanf)


## `printf()`

Khi bạn gọi `printf()`, thực tế là bạn đang gọi một chuỗi các hàm bên trong thư viện chuẩn C. Hàm `printf()` thực hiện hai bước:

- Bước 1: Xử lý chuỗi bạn đưa vào
- Bước 2: Gọi hàm `_write()` là một hàm thấp hơn trong chuỗi thư viện, dùng để gửi chuỗi của bạn tới `stdout`.

Trên vi điều khiển, `stdout` là một bộ đệm, không có công dụng gì ngoài lưu trữ. Để dùng `printf()` trên vi điều khiển, ta phải định nghĩa lại hàm `_write()`:

```c++
// Định nghĩa lại hàm _write(), dùng USART1 để gửi chuỗi lên máy tính.
int _write(int file, char *data, int len) {
    HAL_UART_Transmit(&huart1, (uint8_t *)data, len, HAL_MAX_DELAY);
    return len;
}
```

Sau đó sử dụng hàm `printf()` như bình thường, vi điều khiển sẽ gửi chuỗi qua UART1.

## `scanf()`

Tương tự với `printf()`, `scanf()` sử dụng hàm thấp hơn là `_read()`. Hàm `_read()` đọc dữ liệu từ `stdin`. Ta cần định nghĩa lại hàm này để nó đọc dữ liệu từ UART1:

```c++
// Định nghĩa lại hàm _read để scanf() có thể đọc dữ liệu từ UART1
int _read(int file, char *data, int len) {
    // Nhận dữ liệu từ UART và lưu vào bộ đệm `data`
    HAL_UART_Receive(&huart1, (uint8_t *)data, len, HAL_MAX_DELAY);
    return len;
}
```