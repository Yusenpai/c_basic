#include <stdio.h>

int main()
{
	int num;
	float real_num;
	char letter;

	// Nhập các giá trị
	printf("Nhập một số nguyên: ");
	scanf("%d", &num);

	printf("Nhập một số thực: ");
	scanf("%f", &real_num);

	printf("Nhập một ký tự: ");
	scanf(" %c", &letter); // Lưu ý có khoảng trắng trước %c để bỏ qua ký tự newline

	// Xuất các giá trị
	printf("Số nguyên: %d\n", num);
	printf("Số thực: %.2f\n", real_num); // %.2f để hiển thị 2 chữ số sau dấu thập phân
	printf("Ký tự: %c\n", letter);

	return 0;
}