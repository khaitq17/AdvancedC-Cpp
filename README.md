# BÀI 3: POINTER
Con trỏ (Pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn.

- Khai báo:
```
int *ptr;  // Con trỏ trỏ đến kiểu int 
char *ptr;  // Con trỏ trỏ đến kiểu char  
float *ptr;  // Con trỏ trỏ đến kiểu float
```
- Lấy địa chỉ của một biến và truy cập giá trị
```
int a = 5;
int *ptr = &a;  // Con trỏ ptr chứa địa chỉ của a
int b = *ptr;  // b bằng giá trị mà ptr trỏ đến
```
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch.
```
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));
    return 0;
}
```
Kích thước của con trỏ là **4 bytes** với hệ thống **32-bit** hoặc **8 bytes** với hệ thống **64-bit**.
Và kích thước của con trỏ sẽ KHÔNG phụ thuộc vào kiểu dữ liệu mà nó trỏ đến.

- Ví dụ:
```
#include <stdio.h>
void swap(int *a, int *b)  
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);	//value a is: 20
   printf("value b is: %d\n", b);	//value b is: 10

    return 0;
}
```
- Ví dụ:
```
#include <stdio.h>
int main(){
	int var = 5;

	printf("Dia chi cua var la: %p\n", &var);
	printf("Gia tri cua var la: %d\n", *(&var));
	
	int array[] = {1, 3, 5, 7, 9};
	int *ptr = array;
	
	printf("Dia chi array: %p\n", array);
	printf("Dia chi array: %p\n", ptr);
    printf("Dia chi array: %p\n", &array[0]);	// Giá trị của array cũng chính là địa chỉ của phần tử đầu tiên trong mảng

    for(int i = 0; i<5; i++){
        printf("Gia tri cua phan tu thu %d la: %d\n", i+1, *(ptr+i));
    }
    return 0;
}
```
## 3.1 Void Pointer
**Void Pointer** thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.

- Khai báo:
```
void *ptr;
```
- Ví dụ:
```
include <stdio.h>
#include <stdlib.h>

int main() {
   
    char array[] = "Hello";
    int value = 10;
    double test = 17.5;
    char letter = 'K';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    return 0;
}
```

## 3.2 Function Pointer
**Function Pointer** (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
Trong ngôn ngữ lập trình C, con trỏ hàm cho phép truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.

- Ví dụ:
```
#include <stdio.h>

void addition(int a, int b){
	printf("Tong cua %d va %d la: %d\n", a, b, a+b);
}

void subtraction(int a, int b){
	printf("Hieu cua %d va %d la: %d\n", a, b, a-b);
}

void multiplication(int a, int b){
	printf("Tich cua %d va %d la: %d\n", a, b, a*b);
}

void division(int a, int b){
    if(b == 0){
        printf("Phep chia khong hop le vi mau so bang 0");
    }
    else{printf("Thuong cua %d va %d la: %.2f\n", a, b, a/(double)b);}
}

void calculation(void (*ptr)(int, int), int a, int b){
    printf("Chuong trinh tinh toan:\n");
    ptr(a,b);
}

int main(){
    void (*ptr)(int, int) = &multiplication;

    ptr(3,6); // Tich cua 3 va 6 la: 18

    void (*array[])(int, int) = {&addition, &subtraction, &multiplication, &division}; 

    for(int i = 0; i < 4; i++){ 
        array[i](17,5);
    }

    /*
    Tong cua 17 va 5 la: 22
    Hieu cua 17 va 5 la: 12
    Tich cua 17 va 5 la: 85
    Thuong cua 17 va 5 la: 3.40
    */

    calculation(&addition, 17, 5); // Tong cua 17 va 5 la: 22
    return 0;
}
```

## 3.3 Pointer to Constant
**Pointer to Constant** (Con trỏ hằng) là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

- Khai báo:
```
int const *ptr;
const int *ptr;
```
- Ví dụ:
```
#include<stdio.h>

int main(){
    int var = 3;
    int const *ptr;	// Khai báo con trỏ hằng
    ptr = &var;

    // *ptr = 5; // Lỗi vì không thể thay đổi giá trị mà con trỏ trỏ đến

    printf("value: %d\n", *ptr);	// value: 3

    var = 10;
    printf("value: %d\n", *ptr);	// value: 10

    return 0;
}
```

## 3.4 Constant Pointer
**Constant Pointer** (Hằng con trỏ) định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ) không thể thay đổi, tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.

- Khai báo:
```
int *const ptr = &value;
```

- Ví dụ:
```
#include<stdio.h>

int main(){
    int value = 5;
    int test = 10;
    int const* ptr = &value;

    printf("value: %d\n", *ptr);

    // ptr = &test; // Lỗi vì hằng con trỏ ptr đã trỏ tới biến value nên không thẻ trỏ tới biến test 
    return 0;
}
```

## 3.5 NULL Pointer
**Null Pointer** là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.

Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.

Khi khai báo và sử dụng xong con trỏ, không dùng nữa thì gán con trỏ đó thành con trỏ NULL.

```
#include<stdio.h>

int main(){
    int *ptr = NULL;

    printf("Dia chi: %p\n", ptr);	// 0x00

    ptr = NULL;

    return 0;
}
```
## 3.6 Pointer to Pointer
**Pointer to Pointer** (Con trỏ đến con trỏ) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. 

Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi làm việc với các hàm cần thay đổi giá trị của con trỏ.
- Ví dụ:
```
#include<stdio.h>

int main(){
    int var = 3;        
    printf("Gia tri var: %d\n", var);
    printf("Dia chi var: %p\n", &var);

    printf("\n");

    int *ptr = &var;
    printf("Gia tri ptr: %p\n", ptr);
    printf("Dia chi ptr: %p\n", &ptr);

    printf("\n");

    int **ptp = &ptr;
    printf("Gia tri ptp: %p\n", ptp);

	return 0;
}
```
- Kết quả:
  
![image](https://github.com/user-attachments/assets/12987b23-bf07-46b8-8515-8a86eed5ddf4)





































































