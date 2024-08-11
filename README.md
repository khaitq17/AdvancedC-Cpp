<details>
	<summary><strong>BÀI 3: POINTER</strong></summary>

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
Kích thước của con trỏ là **4 bytes** với hệ thống **32-bit** hoặc **8 bytes** với hệ thống **64-bit**. Và kích thước của con trỏ sẽ **KHÔNG** phụ thuộc vào kiểu dữ liệu mà nó trỏ đến.

Ví dụ:
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
Ví dụ:
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
Ví dụ:
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

Ví dụ:
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
        printf("Phep chia khong hop le vi mau so bang 0!");
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
Ví dụ:
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

Ví dụ:
```
#include<stdio.h>

int main(){
    int value = 5;
    int test = 10;
    int const* ptr = &value;

    printf("value: %d\n", *ptr);

    // ptr = &test; // Lỗi vì hằng con trỏ ptr đã trỏ tới biến value nên không thể trỏ tới biến test 
    return 0;
}
```

## 3.5 NULL Pointer
**Null Pointer** là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.

Sử dụng NULL Pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một NULL Pointer là quan trọng để tránh lỗi chương trình.

Ví dụ:
```
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
    
    return 0;
}
```
Khi khai báo và sử dụng xong con trỏ, không dùng nữa thì gán con trỏ đó thành con trỏ NULL.

Ví dụ:
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

Ví dụ:
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
Kết quả:
  
![image](https://github.com/user-attachments/assets/12987b23-bf07-46b8-8515-8a86eed5ddf4)
</details>


<details>
	<summary><strong>BÀI 4: EXTERN - STATIC - VOLATILE - REGISTER</strong></summary>

# BÀI 4: EXTERN - STATIC - VOLATILE - REGISTER
## 4.1 Extern
- **Extern** được sử dụng để lấy 1 biến hoặc 1 hàm đã được khai báo trong 1 file nguồn khác vào chương trình hiện tại.
- Biến (hoặc hàm) đó là tham chiếu của một biến (hoặc hàm) cùng tên nào đó, đã được định nghĩa bên ngoài. Nó chỉ khai báo chứ không định nghĩa (cấp phát bộ nhớ cho biến).
- Biến (hoặc hàm) được tham chiếu phải được khai báo ở cấp độ cao nhất (toàn cục).
- Giúp quản lý liên kết giữa các file nguồn.
- Khi sử dụng `extern`, không được khai báo giá trị ban đầu cho biến.

Ví dụ:

File `test.c`:
```
#include<stdio.h>

int var = 5;

void tong(int a, int b){
    printf("Tong cua %d va %d la: %d", a, b, a+b);
}
```
File `main.c`:
```
#include<stdio.h>

extern int var;

extern void tong(int a, int b);

int main(){
    printf("var: %d\n", var);
    tong(3,7);

    return 0;
}
```
## 4.2 Static
### 4.2.1 Static local
- Biến **Static local** (Static cục bộ) được khai báo trong 1 hàm.
- Chỉ khởi tạo 1 lần duy nhất.
- Giữ giá trị của biến qua các lần gọi hàm.
- Được sử dụng hết vòng đời của chương trình.
Ví dụ:
```
#include<stdio.h>

void func(){
	static int count = 0; // Biến static giữ giá trị qua các lần gọi hàm
	count++;
	printf("Count: %d\n", count);
}

int main(){
	func(); // Count: 1
	func(); // Count: 2
	func(); // Count: 3

	return 0;
}
```
### 4.2.2 Static global
- Biến **Static global**(Static toàn cục) được khai báo bên ngoài hàm.
- Hạn chế phạm vi chỉ được sử dụng trong file nguồn hiện tại.
- Không thể gọi ra và sử dụng trong file khác, kể cả khi dùng `extern`.

## 4.3 Volatile
- **Volatile** có nghĩa là không dự đoán được.
- Từ khóa `volatile` được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. 
- Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.
- Trong thực tế, có 3 loại biến mà giá trị có thể bị thay đổi như vậy:
	- Memory-mapped peripheral registers (thanh ghi ngoại vi có ánh xạ đến ô nhớ).
	- Biến toàn cục được truy xuất từ các tiến trình con xử lý ngắt (interrupt service routine).
	- Biến toàn cục được truy xuất từ nhiều tác vụ trong một ứng dụng đa luồng.

## 4.4 Register
Từ khóa `register` để cho một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính thay vì được lưu vào trong bộ nhớ RAM, nhằm tăng tốc độ truy cập.

- Trong kiến trúc của vi xử lý thì ALU (Arithmetic Logic Unit) đóng vai trò xử lý các tính toán số học. Dữ liệu đưa vào làm việc với ALU phải chứa trong một vùng đặc biệt, gọi là các thanh ghi (register), và ALU chỉ làm việc với đống thanh ghi đó.

![image](https://github.com/user-attachments/assets/fc9a0e16-a1df-40a3-acc2-4de18e65e086)

- Khi các biến khai báo trong chương trình sẽ được đặt ở bộ nhớ ngoài (RAM, …). Do đó với khai báo biến thông thường, để thực hiện một phép tính thì cần có 3 bước:
	- Nạp giá trị từ vùng nhớ chứa biến vào register.
	- Yêu cầu ALU xử lý register vừa được nạp giá trị.
	- Đưa kết quả vừa xử lý của ALU ra ngoài vùng nhớ chứa biến.
 
Khi thêm từ khóa `register` để khai báo biến, thì tức là ta đã yêu cầu trình biên dịch ưu tiên đặc biệt dành luôn vùng register để chứa biến và giảm được các bước tính toán trên biến đó, giúp tăng tốc độ truy cập.

Ví dụ:
```
#include <stdio.h>
#include <time.h>

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();
    int i;

    // Đoạn mã của chương trình
    for (i = 0; i < 2000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}
```
Kết quả:
```
Thoi gian chay cua chuong trinh: 0.003000 giay
```
Nhưng khi sử dụng `register int i`:
```
Thoi gian chay cua chuong trinh: 0.001000 giay
```
</details>


<details>
	<summary><strong>BÀI 5: GOTO - SETJMP</strong></summary>

# BÀI 5: GOTO - SETJMP
## 5.1 Goto
- **goto** là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm. 
- Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng `goto` thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.
- Trong 1 chương trình sử dụng nhiều vòng lặp lồng vòng lặp thì việc sử dụng `goto` sẽ tránh phải dùng lệnh `break;` nhiều lần.
- Lệnh `goto` chỉ dùng cục bộ trong hàm.
Ví dụ:
```
#include<stdio.h>

int main(){
    int i = 0;

	// Đặt nhãn start
    start:
    if(i >= 5){
        goto end;	// i >= 5 sẽ di chuyển đến nhãn end
    }

    printf("%d\n", i);
    i++;
	goto start;		// Di chuyển đến nhãn start

	// Đặt nhãn end
    end:
    printf("Ket thuc!\n");

    return 0;
}
```
Kết quả:
```
0
1
2
3
4
Ket thuc!
```
## 5.2 Thư viện setjmp.h
**setjmp.h** là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là **setjmp()** và **longjmp()**. 

Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.

- **jmp_buf**: Kiểu dữ liệu được định nghĩa trong "setjmp.h"
```
jmp_buf buffer;	// Biến toàn cục
```
- **int set_jmp(BUF)**: Nếu macro này trả về một cách trực tiếp từ lời gọi macro, thì nó trả về 0; nhưng nếu nó trả về từ một lời gọi hàm **longjmp()**, thì một giá trị khác 0 được trả về.
Ví dụ:
```
#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY         if((exception_code = setjmp(buf)) == 0)
#define CATCH(x)    else if(exception_code == x)
#define THROW(x)    longjmp(buf, x)

double divide(int a, int b){
    if(b == 0){
        THROW(1);
    }
    return a/(double)b;
}

int main(){
    double result;

    TRY{
        result = divide(17, 0);
        printf("Result: %f\n", result);
    } CATCH(1){
        printf("Error: Divided by 0!\n");
    } CATCH(2){
        // Lỗi thứ 2
    } // Các lỗi khác

    return 0;
}
```
</details>


<details>
	<summary><strong>BÀI 6: BITMASK</strong></summary>

# BÀI 6: BITMASK
**Bitmask** là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).

**Bitmask** thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.
## 6.1 NOT bitwise
Dùng để thực hiện phép **NOT bitwise** trên từng bit của một số. Kết quả là bit đảo ngược của số đó.
```
int result = ~num;

~ 0 = 1
~ 1 = 0
```
## 6.2 AND bitwise
Dùng để thực hiện phép **AND bitwise** giữa từng cặp bit của hai số. Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.
```
int result = num1 & num2;

0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1
```
## 6.3 OR bitwise
Dùng để thực hiện phép **OR bitwise** giữa từng cặp bit của hai số. Kết quả là 1 nếu có hơn một bit tương ứng là 1.
```
int result = num1 | num2;

0 | 0 = 0
0 | 1 = 1				
1 | 0 = 1
1 | 1 = 1
```
## 6.4 XOR bitwise
Dùng để thực hiện phép **XOR bitwise** giữa từng cặp bit của hai số. Kết quả là 1 nếu chỉ có một bit tương ứng là 1.
```
int result = num1 ^ num2;

0 ^ 0 = 0
0 ^ 1 = 1			
1 ^ 0 = 1
1 ^ 1 = 0
```
## 6.5 Shift left bitwise 
Dùng để di chuyển bit sang trái, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
```
int resultLeftShift = num << shiftAmount;
```
## 6.6 Shift right bitwise
Dùng để di chuyển bit sang phải, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).
```
int resultRightShift = num >> shiftAmount;
```

Ví dụ:
```
#include <stdio.h>
#include <stdint.h>

#define ENABLE 1
#define DISABLE 0

typedef struct {
    uint8_t LED1 : 1;	// LED1 sử dụng 1 bit
    uint8_t LED2 : 1;	// LED2 sử dụng 1 bit
    uint8_t LED3 : 1;	// LED3 sử dụng 1 bit
    uint8_t LED4 : 1;	// LED4 sử dụng 1 bit
    uint8_t LED5 : 1;	// LED5 sử dụng 1 bit
    uint8_t LED6 : 1;	// LED6 sử dụng 1 bit
    uint8_t LED7 : 1;	// LED7 sử dụng 1 bit
    uint8_t LED8 : 1;	// LED8 sử dụng 1 bit
} LEDStatus;
void displayAllStatusLed(LEDStatus status) {
 	uint8_t* statusPtr = (uint8_t*)&status;
		for (int j = 0; j < 8; j++) {
		printf("LED%d: %d\n", j+1, (*statusPtr >> j) & 1);
}

}


int main() {
    LEDStatus ledStatus = {.LED7 = ENABLE};

    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;
    displayAllStatusLed(ledStatus);
	
    return 0;
}
```
</details>


<details>
	<summary><strong>BÀI 7: STRUCT - UNION</strong></summary>

# BÀI 7: STRUCT - UNION 
## 7.1 Struct
**Struct** trong C là một kiểu dữ liệu tùy chỉnh, được sử dụng để lưu trữ các biến có kiểu dữ liệu khác nhau ở một đối tượng duy nhất. 
- Một struct được định nghĩa bằng cách liệt kê tất cả các biến thành viên (member) bên trong nó, và mỗi biến thành viên có thể có một kiểu dữ liệu khác nhau.
- Khai báo:
```
struct{
	kieuDuLieu1 thanhVien1;
	kieuDuLieu2 thanhVien2;
	// ...
} TenStruct;
```
Ví dụ: Định nghĩa kiểu dữ liệu tên là SinhVien gồm các thành phần như họ tên (kiểu char), ID (kiểu int), điểm trung bình (kiểu float), ….
```
struct{
	char ten[20];
	int ID;
	float diemTB;
} SinhVien; 
```
- Xác định kích thước của Struct:
Kích thước của Struct sẽ bằng tổng kích thước của các thành viên (members) của nó và kích thước của bộ nhớ đệm (padding) (nếu có)

Ví dụ: 
```
#include<stdio.h>
#include<stdint.h>

struct{
	uint8_t var1;	// 1 byte	
	uint32_t var2;	// 4 byte
	uint16_t var3;	// 2 byte
} example;

int main(){
	printf("Size: %d byte", sizeof(example));

	return 0;
}
```
Kích thước của Struct phụ thuộc vào kích thước của kiểu dữ liệu lớn nhất của nó.

![image](https://github.com/user-attachments/assets/ff85a52d-378f-4179-abb6-0792fc68d174)

Kết quả:
```
Size: 12 byte
```
Khi sắp xếp lại thứ tự các biến trong Struct:
```
#include<stdio.h>
#include<stdint.h>

struct{
	uint8_t var1;	// 1 byte	
	uint16_t var3;	// 2 byte
	uint32_t var2;	// 4 byte
} example;

int main(){
	printf("Size: %d byte", sizeof(example));

	return 0;
}
```

![image](https://github.com/user-attachments/assets/9f9719cd-d7fa-4eb1-a3e0-76d0b6ce8a06)

Kết quả:
```
Size: 8 byte
```
Vì vậy, trong 1 struct ta có thể sắp xếp thứ tự các biến thành viên một cách hợp lí để tối ưu bộ nhớ.

Ví dụ:
```
#include<stdio.h>
#include<stdint.h>

struct{
	uint8_t arr1[5];		
	uint16_t arr2[4];	
	uint32_t arr3[2];	
} example;

int main(){
	printf("Size: %d byte", sizeof(example));

	return 0;
}
```
Với struct gồm các thành viên là các mảng thì thực chất có thể được hiểu như sau:
```
struct{
	// uint8_t arr1[5];
	uint8_t arr1_1;
	uint8_t arr1_2;
	uint8_t arr1_3;
	uint8_t arr1_4;
	uint8_t arr1_5;

	// uint16_t arr2[4];
	uint16_t arr2_1;
	uint16_t arr2_2;
	uint16_t arr2_3;
	uint16_t arr2_4;

	// uint32_t arr3[2];
	uint32_t arr3_1;
	uint32_t arr3_2;	
} example;
```
![image](https://github.com/user-attachments/assets/7111ee2f-7965-41e6-a7be-1f69688b321e)

Kết quả:
```
Size: 24 byte
```

## 7.2 Union
**Union** cũng là kiểu dữ liệu mà người dùng tự định nghĩa tương tự như struct, Union cũng có các thành phần dữ liệu để mô tả thông tin của đối tượng muốn lưu trữ.
- Nếu với Struct thì các thành phần của nó có thể lưu trữ giá trị đồng thời tại cùng một thời điểm còn Union thì tại mỗi thời điểm chỉ có một thành viên của Union có thể được sử dụng.
- Tất cả các thành phần của Union sẽ chia sẻ chung 1 vùng nhớ.
- Khai báo:
```
union{
	kieuDuLieu1 thanhVien1;
	kieuDuLieu2 thanhVien2;
	// ...
} TenUnion;
```

Ví dụ:
```
#include<stdio.h>
#include<stdint.h>

union{
	uint8_t var1;
	uint16_t var2;
	uint32_t var3;
} Data;

int main(){
	printf("Size: %d byte", sizeof(example));

	return 0;
}
```
Kích thước của Union chính là kích thước của thành viên có kích thước lớn nhất của nó.
Kết quả:
```
Size: 4 byte
```
Vì các thành viên của Union chia sẻ chung 1 vùng nhớ nên khi gọi 1 thành viên thì vùng nhớ sẽ như sau:

![image](https://github.com/user-attachments/assets/d2fffe3f-a2ef-423c-9cc5-d9633e9659ef)

Ví dụ:
```
#include<stdio.h>
#include<stdint.h>

union{
	uint8_t arr1[5];	// 5 byte
	uint16_t arr2[9];	// 18 byte
	uint32_t arr3[3];	// 12 byte
} Data;

int main(){
	printf("Size: %d byte", sizeof(example));

	return 0;
}
```
Tương tự Struct thì kích thước của Union cũng phụ thuộc vào kích thước của kiểu dữ liệu lớn nhất trong nó. 

Trong ví dụ này khi quét nó sẽ quét 4 byte một lần. Và member `arr2[9]` có kích thước lớn nhất với 18 byte kích thước của nó và 2 byte padding.

Vì vậy, kích thước của Union sẽ là 20 byte.
Kết quả:
```
Size: 20 byte
```

## 7.3 Ứng dụng kết hợp của Struct và Union
```
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;

int main()
{
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

	Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
	
    return 0;
}
```
</details>


<details>
	<summary><strong>BÀI 8: MEMORY LAYOUT</strong></summary>

# BÀI 8: MEMORY LAYOUT
Chương trình main.exe (trên window), main.hex (nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên Window (cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.
![image](https://github.com/user-attachments/assets/e84b6278-6b83-4f30-9d88-9a7878eead10)

## 8.1 Text Segment
- Chứa tập hợp các lệnh thực thi.
- Quyền truy cập: Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. 
- Lưu hằng số, con trỏ kiểu char.
- Tất cả các biến lưu ở phân vùng Text đều không thể thay đổi giá trị mà chỉ được đọc.

![image](https://github.com/user-attachments/assets/3e570e02-9bb4-4273-8523-8699b5e40531)

Ví dụ:
```
#include<stdio.h>
#include<string.h>

const int a = 5;	// Phân vùng Text

char *ptr = "Hello World!";		// Phân vùng Text

int main(){
	a = 10; 	// Lỗi không thể thay đổi được hằng số
	printf("a = %d\n", a);	

	*ptr = 'K';		// Lỗi không thể thay đổi con trỏ kiểu char
	printf("%s\n", ptr);	

	return 0;
}
```
## 8.2 Data Segment
**Initialized Data Segment** (Dữ liệu đã khởi tạo):
- Chứa các biến toàn cục được khởi tạo với giá trị khác 0.
- Chứa các biến static được khởi tạo với giá trị khác 0.
- Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến.
- Tất cả các biến sẽ được thu hồi **sau khi chương trình kết thúc**.

![image](https://github.com/user-attachments/assets/43b01e88-f724-4e13-bdf7-7e9875fde4e0)

Ví dụ:
```
#include<stdio.h>
/*
Các biến phân vùng Data

int a = 5; 	// Biến toàn cục được khởi tạo khác 0       

static int b = 10; 	// Biến static toàn cục được khởi tạo khác 0

void test(){
    static int x = 3;	// Biến static cục bộ được khởi tạo khác 0
}
*/

int main(){

    return 0;
}
// Sau khi kết thúc chương trình các biến phân vùng Data sẽ được thu hồi 
```
## 8.3 BSS Segment
**Uninitialized Data Segment** (Dữ liệu Chưa Khởi Tạo):
- Chứa các biến toàn cục khởi tạo với giá trị bằng 0 hoặc không gán giá trị.
- Chứa các biến static với giá trị khởi tạo bằng 0 hoặc không gán giá trị.
- Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến.
- Tất cả các biến sẽ được thu hồi **sau khi chương trình kết thúc**.

![image](https://github.com/user-attachments/assets/5d1eb88e-fba4-4129-913f-52d8323d3bb6)

Ví dụ:
```
#include<stdio.h>
/*
Các biến phân vùng BSS

int a = 0;	// Biến toàn cục khởi tạo với giá trị bằng 0  

static int b;	// Biến static không khởi tạo giá trị ban đầu
*/

int main(){
	a = 10; // Khi gán giá trị a = 10 thì biến a vẫn nằm trong phân vùng BSS chứ không chuyển sang phân vùng Data.

    return 0;
}
```
## 8.4 Stack
- Chứa các biến cục bộ, tham số truyền vào.
- Quyền truy cập: đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.
- Các biến sẽ được thu hồi vùng nhớ **sau khi ra khỏi hàm**.

![image](https://github.com/user-attachments/assets/23e16469-2639-4ffc-86bd-386b75a47584)

Ví dụ:
```
#include<stdio.h>

int tong(int a, int b){
	const int x = 10;	// Biến cục bộ là hằng số nhưng vẫn được lưu ở phân vùng Stack và chỉ có quyền đọc.
	int c;		// Các biến cục bộ a, b, c được lưu ở phân vùng Stack 
	c = a + b;
	return c;
}

int main(){
    tong(3, 5);
	// Sau khi kết thúc hàm thì các biến phân vùng Stack sẽ bị thu hồi vùng nhớ.

    return 0;
}
```
## 8.5 Heap
Cấp phát động:
- **Heap** được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
- Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
- Các hàm như `malloc()`, `calloc()`, `realloc()`, và `free()` được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.

![image](https://github.com/user-attachments/assets/ddcb9a31-2ad6-4743-afbb-dfd686b066ce)

Ví dụ:
```
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>


int main(){
    uint16_t *ptr = NULL;
    ptr = (uint16_t*)malloc(sizeof(uint16_t) * 6);  // Dùng malloc() cấp phát động 1 mảng có kích thước 2 * 6 = 12 byte

    for (int i = 0; i < 6; i++)
    {
        ptr[i] = i + 1;
    }
    
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", ptr[i]);
    }

    ptr = (uint16_t*)realloc(ptr, sizeof(uint16_t) * 10);  // Dùng realloc() cấp phát động lại mảng với kích thước mới 2 * 10 = 20 byte

    ptr[10] = 17;	// Ô nhớ chưa được cấp phát động nên biến a có thể truy cập đến và sử dụng
    int a;	// Các ô nhớ được cấp phát động thì biến a không thể truy cập đến

    for (int i = 0; i < 10; i++)
    {
        ptr[i] = i + 1;
    }
    
    for (int i = 0; i < 11; i++)
    {
        printf("%d\n", ptr[i]);
    }

    free(ptr);	// Thu hồi vùng nhớ để tránh tràn bộ nhớ

    return 0;
}
```
## 8.6 Hàm malloc() và calloc()
### 8.6.1 Hàm malloc()
Hàm **malloc()** là viết tắt của từ **memory allocation** tức là cấp phát động vùng nhớ, hàm này được sử dụng để xin cấp phát khối bộ nhớ theo kích thước byte mong muốn. 

Giá trị trả về của hàm là một con trỏ kiểu `void`, nên ép kiểu sang kiểu dữ liệu cần dùng. 

Các giá trị trong các ô nhớ được cấp phát là giá trị rác.

Cú pháp: `ptr = (cast_type*)malloc(byte_size)`

Trong đó : 

- `ptr` là con trỏ lưu trữ ô nhớ đầu tiên của vùng nhớ được cấp phát
- `cast_type*` là kiểu con trỏ muốn ép kiểu sang
- `byte_size` là kích thước theo byte muốn cấp phát
### 8.6.2 Hàm calloc()
Hàm **calloc()** viết tắt của **contiguous allocation**, tương tự như **malloc()** sử dụng để cấp phát vùng nhớ động nhưng các giá trị của các vùng nhớ được cấp phát sẽ có giá trị mặc định là 0.

Cú pháp : `ptr = (cast_type*) calloc(n, element_size)`

Trong đó : 

- `ptr` là con trỏ lưu trữ ô nhớ đầu tiên của vùng nhớ được cấp phát
- `cast_type*` là kiểu con trỏ muốn ép kiểu sang
- `n` là số lượng phần tử muốn cấp phát
- `element_size` là kích thước theo byte của 1 phần tử
### 8.6.3 So sánh malloc() và calloc()
|**malloc**|**calloc()**|
|:---------|:-----------|
|Tạo một khối bộ nhớ có kích thước do người dùng chỉ định.|Có thể gán nhiều khối bộ nhớ cho một biến.|
|Chứa giá trị rác.|Khối bộ nhớ được cấp phát luôn được khởi tạo bằng 0.|
|Số lượng input là 1.|Số lượng input là 2.|
|Nhanh hơn calloc().|Chậm hơn malloc().|
|Không an toàn so với calloc().|An toàn để sử dụng so với malloc().|
|Hiệu quả về thời gian cao hơn calloc().|Hiệu quả về thời gian thấp hơn malloc().|
|Chỉ trả về địa chỉ bắt đầu và không biến nó thành 0.|Trả về địa chỉ bắt đầu và biến nó thành 0 trước khi cấp phát địa chỉ.|
|Không thực hiện khởi tạo bộ nhớ.|Thực hiện khởi tạo bộ nhớ.|

- Trường hợp nên sử dụng **malloc()**:
	- Khi phải cấp phát bộ nhớ khi chạy.
	- Khi phải phân bổ các đối tượng phải tồn tại ngoài việc thực thi khối bộ nhớ hiện tại.
	- Nếu cần phân bổ bộ nhớ lớn hơn kích thước của ngăn xếp đó.
- Trường hợp nên sử dụng **calloc()**:
	- Khi phải đặt bộ nhớ được phân bổ về 0.
	- Khi cần khởi tạo các phần tử về 0 để trả về một con trỏ vào bộ nhớ.
	- Để tránh tràn có thể xảy ra với malloc().
## 8.7 Stack và Heap
|	| **Stack**   | **Heap**   | 
|:-:|:------------|:-----------|
|Đặc điểm|- Dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.<br>- Được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.|- Dùng để lưu trữ vùng nhớ cho những biến được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).<br>- Được quản lý bởi lập trình viên, dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, vì vậy phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.| 
|Kích thước vùng nhớ|Cố định, tùy thuộc vào hệ điều hành|Không cố định, có thể tăng giảm để đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.|
|Lỗi xảy ra đối với vùng nhớ|Nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...|- Nếu liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow).<br>- Nếu khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.|

Sử dụng **Stack** nếu biết chính xác lượng dữ liệu phân bổ trước khi biên dịch và dữ liệu không quá lớn. Ngược lại, nên sử dụng **Heap**.
</details>


<details>
	<summary><strong>BÀI 9: JSON</strong></summary>

# BÀI 9: JSON
- **JSON** là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.

- **JSON** được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp **key** - **value**, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

Ví dụ: 
1 Object JSON:
```
{
    "name" : "Nguyen Van A",	// value là 1 string
    "age" : 18,	// value là 1 number
    "address" : null,	// value là null
    "isStudent": true,	// value là boolean
    "score" : [9, 10, 7],	// value là 1 array
    "contact" : {	// value là 1 object
        "email" : "nva@gmail.com",
        "phoneNumber" : "123456789"
    }
}
```
Trong đó:
- `"name" : "Nguyen Van A"` là 1 member
- `"name"` là 1 key
- `"Nguyen Van A"` là 1 value

1 Object JSON mở đầu bằng "{" kết thúc bằng "}".

Trong đó: 
- *key* phải là 1 **string**, ngăn cách với *value* bởi dấu `:`
- *value* có thể là:
	- Null: Đại diện cho 1 giá trị không tồn tại hoặc không xác định
 	- Boolean: `true` hoặc `false`
	- Number: Có thể là số nguyên (int) hoặc số thực (float, double),...
	- String: Chuỗi ký tự 
	- Array: Mảng có thể bao gồm nhiều kiểu dữ liệu
	- Object: Đối tượng thuộc 1 *key* có cấu trúc như ví dụ trên
- Mỗi member trong object ngăn cách nhau bằng dấu `,`
```
typedef enum{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;
```
</details>


<details>
	<summary><strong>BÀI 10: LINKED LIST</strong></summary>

# BÀI 10: LINKED LIST
**Linked list** hay **danh sách liên kết** (DSLK) là một cấu trúc dữ liệu được sử dụng để tổ chức và lưu trữ dữ liệu. 

- Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.
- Cấu trúc 1 node:
```
typedef struct node{
    int value;	// Dữ liệu kiểu int
    struct node* next;	// Con trỏ trỏ đến nút tiếp theo
} node;
```

![image](https://github.com/user-attachments/assets/fedc69d4-9da0-497e-bba9-795e00b2b824)

- Tạo 1 node mới:
```
node *createNode(int value){
    node *ptr = (node*)malloc(sizeof(node));

    ptr->value = value;
    ptr->next = NULL;

    return ptr;
}
```

- Tính chất:
	- Phần tử cuối cùng trong DSLK trỏ đến NULL (con trỏ NULL).
	- Mỗi node trong DSLK đều được cấp phát động và số lượng phần tử trong DSLK phụ thuộc vào bộ nhớ Heap.
	- Có thể thay đổi kích thước qua việc thêm, xóa phần tử.
	- Truy cập phần tử trong DSLK cần truy cập tuần tự, **KHÔNG** thể truy cập qua chỉ số.
 	- Mỗi node trong DSLK thực chất là một con trỏ, nó là địa chỉ một ô nhớ mà ô nhớ đó được sử dụng để lưu trữ thông tin về một node.
</details>

<details>
	<summary><strong>BÀI 11: STACK - QUEUE</strong></summary>

# BÀI 11: STACK - QUEUE
## 11.1 Stack
**Stack** (ngăn xếp) là một cấu trúc dữ liệu tuân theo nguyên tắc **"Last In, First Out"** (LIFO), nghĩa là phần tử cuối cùng được thêm vào Stack sẽ là phần tử đầu tiên được lấy ra.

![image](https://github.com/user-attachments/assets/0d3e8537-9c59-4ac1-9c76-bc41506de6e3)

Định nghĩa 1 Stack:
```
typedef struct {
    int* items; // Mảng chứa các giá trị trong ngăn xếp
    int size;   // Kích thước của mảng 
    int top;   // Chỉ số của phần tử trên cùng
} Stack;
```

Các thao tác cơ bản trên Stack bao gồm:
- **initialize**: Khởi tạo ngăn xếp rỗng.
```
void initialize(Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}
```
- **is_empty**: Kiểm tra xem ngăn xếp có rỗng không.
```
int is_empty(Stack stack) {
    return stack.top == -1;
}
```  
- **is_full**: Kiểm tra xem ngăn xếp có bị đầy (tràn) hay không.
```
int is_full(Stack stack) {
    return stack.top == stack.size - 1;
}
```
- **push**: Thêm một phần tử vào ngăn xếp.
```
void push(Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}
```
- **pop**: Lấy ra phần tử ở đỉnh ngăn xếp.
```
int pop(Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}
```
- **top**: Trả về phần tử ở đỉnh ngăn xếp.
```
int top(Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}
```

## 11.2 Queue
**Queue** (hàng đợi) là một cấu trúc dữ liệu tuân theo nguyên tắc **"First In, First Out"** (FIFO), nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra. 

![image](https://github.com/user-attachments/assets/a3ee63b2-079c-45ad-81c3-6460c96bb085)

**Queue** trong lập trình nhúng: Hoạt động kiểu Circular Queue

![image](https://github.com/user-attachments/assets/a7628eb3-8f15-42a7-ac0d-94d34342252d)

Định nghĩa 1 Queue:
```
typedef struct {
    int* items;	// Mảng chứa các giá trị trong ngăn xếp
    int size;	// Kích thước của mảng
    int front, rear;	// Chỉ số của phần tử đầu và cuối
} Queue;
```

Các thao tác cơ bản trên hàng đợi bao gồm:
- **initialize**: Khởi tạo một hàng đợi rỗng.
```
void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}
```
- **is_empty**: Kiểm tra hàng đợi có rỗng hay không.
```
int is_empty(Queue queue) {
    return queue.front == -1;
}
```
- **is_full**: Kiểm tra hàng đợi đã bị đầy chưa.
```
int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}
```
- **front**: Trả về giá trị của phần tử ở đầu hàng đợi.
```
int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}
```
- **enqueue**: Đẩy một phần tử vào cuối hàng đợi.
```
void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
    } else {
        printf("Queue overflow\n");
    }
}
```
- **dequeue**: Loại bỏ một phần tử ở đầu hàng đợi và trả về phần tử đó.
```
int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}
```
</details>













 






































