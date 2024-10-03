## Xây dựng thư viện Linked List chứa các hàm:
- node *createNode(int value); // Tạo 1 node mới

- void push_back(node** array, int value);    // Thêm 1 node vào phía sau

- void push_front(node **array, int value);    // Thêm 1 node vào phía trước

- void pop_back(node **array);    // Xóa node cuối cùng

- void pop_front(node **array);    // Xóa node đầu tiên

- int front(node *array);    // Lấy giá trị của node đầu tiên

- int back(node *array);    // Lấy giá trị của node cuối cùng

- void insert(node **array, int value, int pos);    // Thêm 1 node vào vị trí bất kỳ

- void erase(node **array, int pos, int num);    // Xóa 1 hoặc nhiều node bắt đầu tại 1 vị trí bất kỳ

- int size(node **array); // Lấy kích thước của list

- int get(node **array, int pos);    // Lấy giá trị của node bất kỳ

- bool empty(node **array); // Kiểm tra list có rỗng hay không
