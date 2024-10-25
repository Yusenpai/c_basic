# Bài 6: Câu lệnh điều kiện và vòng lặp

## Mục lục

- [Bài 6: Câu lệnh điều kiện và vòng lặp](#bài-6-câu-lệnh-điều-kiện-và-vòng-lặp)
	- [Mục lục](#mục-lục)
	- [Câu lệnh điều kiện `if`...`else`](#câu-lệnh-điều-kiện-ifelse)
	- [Câu điều kiện `switch`...`case`](#câu-điều-kiện-switchcase)
	- [Vòng lặp `for`](#vòng-lặp-for)
	- [Vòng lặp `while` và `do`...`while`](#vòng-lặp-while-và-dowhile)
	- [Từ khóa `continue`, `break`, `goto`](#từ-khóa-continue-break-goto)
	- [Câu hỏi và bài tập](#câu-hỏi-và-bài-tập)

## Câu lệnh điều kiện `if`...`else`

Cú pháp:

```c++
if (điều kiện 1) {
    // Code thực thi nếu điều kiện 1 đúng
} else if (điều kiện 2) {
    // Code thực thi nếu điều kiện 1 sai và điều kiện 2 đúng
} else {
    // Code thực thi nếu tất cả các điều kiện đều sai
}
```

Ví dụ:

```c++
int a = 10, b = 20;
if (a > b) {
    printf("a lớn hơn b\n");
} else if (a < b) {
    printf("a nhỏ hơn b\n");
} else {
    printf("a bằng b\n");
}
```

## Câu điều kiện `switch`...`case`

Cú pháp:

```c++
switch (expression) {
    case value1:
        // Code thực thi nếu expression == value1
        break;
    case value2:
        // Code thực thi nếu expression == value2
        break;
    default:
        // Code thực thi nếu không khớp với bất kỳ giá trị nào
}
```

Một số biến thể của câu điều kiện switch:

```c++
switch (expression) {
    case value1: case value2: case value3:
        // Code thực thi nếu expression == value1 hoặc value2 hoặc value3
        break;
    case value4:
        // Code thực thi nếu expression == value2
        break;
    default:
        // Code thực thi nếu không khớp với bất kỳ giá trị nào
}

switch (expression) {
    case value1 ... value2:
        // Code thực thi nếu expression có giá trị từ value1 tới value2. Là tính năng chỉ hỗ trợ trên một số trình biên dịch
        break;
}

```

## Vòng lặp `for`

Vòng lặp for được sử dụng khi biết trước số lần lặp. Nó bao gồm 3 phần: khởi tạo, điều kiện, và cập nhật.

```c++
for (khởi tạo; điều kiện; cập nhật) {
    // Code thực thi trong vòng lặp
}
```

## Vòng lặp `while` và `do`...`while`

```c++
while (condition) {
    // Code thực thi trong vòng lặp
}
```
Vòng lặp `do`...`while` đảm bảo đoạn code chạy ít nhất một lần:

```c++
do {
    // Code thực thi trong vòng lặp
} while (condition);
```

>> Lưu ý: `while(1){}` và `for(;;){}` là tương đương nhau.

## Từ khóa `continue`, `break`, `goto`

- Từ khoá `break`: Dùng để kết thúc vòng lặp hoặc `switch` ngay lập tức.
Ví dụ:

```c++
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break; // Kết thúc vòng lặp khi i = 5
    }
    printf("i = %d\n", i);
}
```

- Từ khoá `continue`: Dùng để bỏ qua lần lặp hiện tại và chuyển sang lần lặp tiếp theo.

```c++
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        continue; // Bỏ qua giá trị i = 5
    }
    printf("i = %d\n", i);
}
```

- Từ khoá `goto`: Cho phép nhảy tới **một nhãn** (label) được định nghĩa trong code. Tuy nhiên, `goto` có thể làm code khó hiểu và khó bảo trì, nên chỉ dùng khi thực sự cần thiết.

Ví dụ:

```c++
int a = 1;
if (a == 1) {
    goto skip;
}
printf("Dòng này sẽ không được in\n");

skip:
    printf("Đã nhảy đến nhãn skip\n");
```

## Câu hỏi và bài tập

1. Xét đoạn code sau, kết quả in ra màn hình là gì? Giải thích?
```c++
uint8_t a = 10;
if(a)
	printf("OK\n");
else
	printf("NO\n");
```

2. Viết code kiểm tra bit 8 của số `a` rộng 16 bit. Nếu bit 8 của `a` là 1 thì in ra "OK", nếu là 0 thì in ra "NO".
3. Viết thuật toán thay đổi vị trí các bit trong một số 8 bit theo bảng sau:

| Vị trí ban đầu | Vị trí lúc sau
|-|-
|0|0|
|1|4|
|2|2|
|3|6|
|4|1|
|5|5|
|6|3|
|7|7|