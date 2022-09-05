# Inheritance

> ##  Kế thừa là gì ?
---

- Kế thừa (**inheritance**) là một tính chất đặc trưng của lập trình hướng đối tượng. Nó có nghĩa là một class thừa hưởng lại tất cả các thuộc tính, phương thức của class mà nó kế thừa.

- Class kế thừa từ một class khác gọi là lớp con (**child class** hay **subclass**) hay lớp dẫn xuất (**derived class**). Class được lớp khác kế thừa được gọi là lớp cha (**parent class** hay **superclass**) hay lớp cơ sở (**base class**).

EX : 
```c++
    class Animal {
        // eat() function
        // sleep() function
    };

    class Dog : public Animal {
        // bark() function
    };
```

![](https://cdn.programiz.com/sites/tutorial2program/files/cpp-inheritance.png)

> ## Đơn kế thừa / Đa kế thừa ?

1. Đơn kế thừa là gì ?
---

- **Kế thừa đơn (single inheritance)** là một class con kế thừa duy nhất từ một class cha. Ví dụ như class sinh viên chỉ kế thừa duy nhất từ class con người, đó là một kế thừa đơn.

- Cú pháp khai báo một lớp kế thừa từ một lớp khác như sau:

```c++
class <Tên lớp dẫn xuất>: <Từ khóa dẫn xuất> <Tên lớp cơ sở> { 
    // Khai báo các thành phần lớp 
}; 
```

Trong đó: 

- **Tên lớp dẫn xuất**: là tên lớp được cho kế thừa từ lớp khác. Tên lớp này tuân thủ theo quy tắc đặt tên biến trong C++. 
- **Tên lớp cở sở**: là tên lớp đã được định nghĩa trước đó để cho lớp khác kế thừa. Tên lớp này cũng tuân thủ theo quy tắc đặt tên biến của C++. 
- **Từ khóa dẫn xuất**: là từ khóa quy định tính chất của sự kế thừa. Có ba từ khóa dẫn xuất là `private`, `protected` và `public`.

> Access Modes in C++ Inheritance :

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/table-class.png)


- `public`: Nếu kế thừa ở dạng này, sau khi kế thừa, tất cả các thành viên dạng `public` lớp cha sẽ `public` ở lớp con, dạng `protected` ở lớp cha vẫn sẽ là `protected` ở lớp con.
- `protected`: Nếu dùng `protected` thì sau khi kế thừa, tất cả các thành viên dạng `public` lớp cha sẽ trở thành `protected` tại lớp con.
- `private`: Trường hợp ta sử dụng `private`, thì sau khi kế thừa, tất cả các thành viên dạng `public` và `protected` ở lớp cha sẽ thành `private` tại lớp con.

EX:

```c++
class Base {
  public:
    int x;
  protected:
    int y;
  private:
    int z;
};

class PublicDerived: public Base {
  // x is public
  // y is protected
  // z is not accessible from PublicDerived
};

class ProtectedDerived: protected Base {
  // x is protected
  // y is protected
  // z is not accessible from ProtectedDerived
};

class PrivateDerived: private Base {
  // x is private
  // y is private
  // z is not accessible from PrivateDerived
};
```

> Constructor và Destructor trong inheritance :

Thứ tự được gọi sẽ bắt đầu từ hàm khởi tạo tương ứng của lớp cơ sở, sau đó đến hàm khởi tạo của lớp dẫn xuất. Do đó, thông thường, trong hàm khởi tạo của lớp dẫn xuất phải có hàm khởi tạo của lớp cơ sở.

Cú pháp khai báo hàm khởi tạo như sau:
```cpp
<Tên lớp dẫn xuất>([<Các tham số>]): <Tên lớp cơ sở>([<Các đối số>]) { 
    // Khởi tạo các thuộc tính mới bổ sung của lớp dẫn xuất 
};
```

Thứ tự gọi các hàm hủy bỏ ngược với thứ tự gọi hàm thiết lập: gọi hàm hủy bỏ của lớp dẫn xuất trước khi gọi hàm hủy bỏ của lớp cơ sở.

Vì mỗi lớp chỉ có nhiều nhất là một hàm hủy bỏ, nên ta không cần phải chỉ ra hàm hủy bỏ nào của lớp cơ sở sẽ được gọi sau khi hủy bỏ lớp dẫn xuất. Do vậy, hàm hủy bỏ trong lớp dẫn xuất được khai báo và định nghĩa hoàn toàn giống với các lớp thông thường: 

```cpp
<Tên lớp>::~<Tên lớp>([<Các tham số>]){ 
    // giải phóng phần bộ nhớ cấp phát cho các thuộc tính bổ sung 
}
```

2. Đa kế thừ là gì?
---

**Đa kế thừa (multiple inheritance)** là một lớp có thể được dẫn xuất từ nhiều lớp cơ sở khác nhau, với những kiểu dẫn xuất khác nhau.

Đa kế thừa được khai báo theo cú pháp:

```cpp
class <Tên lớp dẫn xuất>: <Từ khoá dẫn xuất> <Tên lớp cơ sở 1>, 
                   <Từ khoá dẫn xuất> <Tên lớp cơ sở 2>, 
                   … 
                   <Từ khoá dẫn xuất> <Tên lớp cơ sở n> { 
        // Khai báo thêm các thành phần lớp dẫn xuất 
};
```

> Constructor và Destructor trong đa kế thừa

Hàm khởi tạo trong đa kế thừa được khai báo tương tự như trong đơn kế thừa, ngoại trừ việc phải sắp xếp thứ tự gọi tới hàm khởi tạo của các lớp cơ sở: thông thường, thứ tự gọi đến hàm khởi tạo của các lớp cơ sở nên tuân theo thứ tự dẫn xuất từ các lớp cơ sở trong đa kế thừa.

```cpp
class Car {
private:
	int  speed;
	string  mark;
	float price;     
public:
	Car();
	Car(int speed, string mark, float price);
};
Car::Car() {
	this->speed = 0;
	this->mark = "";
	this->price = 0;
}
Car::Car(int speed, string mark, float price) {
	this->speed = speed;
	this->mark = mark;
	this->price = price;
}
class PublicTransport {
	float ticket;
public: 
	PublicTransport();
	PublicTransport(float);
};
PublicTransport::PublicTransport() {	
	this->ticket = 0; 
}
PublicTransport::PublicTransport(float ticket) {
	this->ticket = ticket;
}
/* Định nghĩa lớp Bus kế thừa từ lớp Car và PublicTransport */
class Bus: public Car, public PublicTransport {  // Thứ tự khai báo  	 
	int label; 	
public: 
	Bus();
	Bus(int, string, float, float, int);
};
Bus::Bus(): Car(), PublicTransport() { 	// Theo thứ tự dẫn xuất
	label = 0; 
}
Bus::Bus(int speed, string mark, float price, float ticket, int label): Car(speed, mark, price), PublicTransport(ticket) { // Theo thứ tự dẫn xuất 
	this->label = label;
}
```

Vì hàm huỷ bỏ là duy nhất của mỗi lớp, hơn nữa hàm huỷ bỏ của lớp cơ sở sẽ được tự động gọi đến khi giải phóng đối tượng của lớp dẫn xuất. Cho nên hàm huỷ bỏ trong đa kế thừa hoàn toàn tương tự hàm huỷ bỏ trong đơn kế thừa.

> ## Hàm friend
---

- Nếu một hàm được định nghĩa là một **hàm friend** trong C ++ thì dữ liệu là `protected` và `private` của một lớp có thể được truy cập bằng hàm này.

Một hàm bạn của một lớp được khai báo bằng từ khóa friend khi khai báo khuôn mẫu hàm trong lớp tương ứng. 

```cpp
class <Tên lớp>{ 
    // Khai báo các thành phần lớp như thông thường 
    // Khai báo hàm bạn 
    friend <Kiểu trả về> <Tên hàm bạn>([<Các tham số>]);
};
``` 

Khi đó, định nghĩa chi tiết hàm bạn được thực hiện như định nghĩa một hàm tự do thông thường:

```cpp
<Kiểu trả về> <Tên hàm bạn>([<Các tham số>]) { 
    // Có thể truy nhập trực tiếp các thành phần private  
    // của lớp đã khai báo 
}
```

**Lưu ý:**

- Mặc dù hàm bạn được khai báo *khuôn mẫu hàm* trong phạm vi lớp, nhưng hàm bạn tự do lại **không phải** là một phương thức của lớp. Nó là **hàm tự do**, việc định nghĩa và sử dụng hàm này hoàn toàn tương tự như các hàm tự do khác. 
- Việc khai báo *khuôn mẫu hàm* bạn trong phạm vi lớp ở vị trí nào cũng được: hàm bạn không bị ảnh hưởng bởi các từ khóa `private`, `protected` hay `public` trong lớp. 
- Trong hàm bạn, có thể truy nhập trực tiếp đến các thành phần `private` và `protected` của đối tượng có kiểu lớp mà nó làm bạn (truy nhập thông qua đối tượng cụ thể).

Trong C++, một phương thức của lớp này cũng có thể làm bạn của một lớp kia. Để khai báo một phương thức `f()` của lớp B là bạn của lớp A và `f()` nhận một tham số có kiểu lớp A, ta phải khai báo tuần tự như sau:

1. Khai báo khuôn mẫu lớp A, để làm tham số cho hàm f của lớp B: 
```cpp
class A; 
```

2. Khai báo lớp B với hàm f như khai báo các lớp thông thường:
```cpp
class B { 
    // Khai báo các thành phần khác của lớp B 
    void f(A); 
};
```
3. Khai báo chi tiết lớp A với hàm f của lớp B là bạn
```cpp
class A{ 
    // Khai báo các thành phần khác của lớp A     
    friend void B::f(A); 
};
```
4. Định nghĩa chi tiết hàm f của lớp B:
```cpp
void B::f(A) { 
    // Định nghĩa chi tiết hàm f 
}
```
**Lưu ý:**
- Trong trường hợp này, **hàm f** chỉ được định nghĩa chi tiết một khi lớp A đã được định nghĩa chi tiết. Do vậy, chỉ có thể định nghĩa chi tiết **hàm f** ngay trong lớp A *(ở bước 3)* hoặc sau khi định nghĩa lớp A *(ở bước 4)*, mà không thể định nghĩa chi tiết **hàm f** ngay trong lớp B *(ở bước 2)*. 
- **Hàm f** có thể truy nhập đến các thành phần `private` và `protected` của cả hai lớp A và B. Tuy nhiên, muốn **f** truy nhập đến các thành phần của lớp A thì phải thông qua một đối tượng cụ thể có kiểu lớp A. 

> ## Function Overloading & Operator Overloading
---

- Nạp chồng - Overloading :

Trong một lớp, ta có thể tạo ra nhiều hàm với cùng một tên gọi nhưng khác nhau các dữ liệu đầu vào hoặc tham số, đó gọi là **nạp chồng**.

1. Function Overloading:

Trong một lớp, ta có thể tạo ra nhiều hàm với **cùng một tên gọi** nhưng khác nhau **các dữ liệu đầu vào hoặc tham số**, đó gọi là **nạp chồng phương thức**.
Lới ích của việc nạp chồng phương thức là chúng ta có thể khai báo cùng một tên phương thức trong cùng chương trình, không cần phải khai báo tên khác cho cùng một hành đông.

EX:

```cpp
#include <iostream>  
using namespace std;
class Cal {
public:
	static int add(int a, int b) {
		return a + b;
	}
	static int add(int a, int b, int c) {
		return a + b + c;
	}
};
int main(void) {
	Cal C;
	cout << C.add(10, 20) << endl;
	cout << C.add(12, 20, 23) << endl;
}
```

OUTPUT: 

```
30
55
```

2. Operator Overloading:

**Nạp chồng toán tử (overload operator)** là bạn định nghĩa lại toán tử đã có trên kiểu dữ liệu người dùng tự định nghĩa để dể dàng thể hiện các câu lệnh trong chương trình.
Ví dụ như bạn định nghĩa phép cộng cho kiểu dữ liệu phân số thì sẽ thực hiện cộng hai phân số rồi trả về một phân số mới. So với việc thực hiện gọi hàm, việc overload toán tử sẽ làm cho câu lệnh ngắn gọn, dễ hiểu hơn.
```cpp
PhanSo ps1(1, 2);
PhanSo ps2(2, 3);
PhanSo ketQua;
// Dùng hàm
ketQua = ps1.cong(ps2);
// Dùng Overload operator
ketQua = ps1 + ps2;  // 7/6
```

Như đã giới thiệu, bản chất việc dùng toán tử là lời gọi hàm, do đó chúng ta overload toán tử cũng giống overload hàm, vậy chúng ta sẽ overload hàm nào? Chúng ta sẽ overload hàm có tên là `operator @`, với `@` là toán tử cần overload (+, -, *, /…), kiểu trả về của hàm chính là lớp đó.
Có hai loại là **hàm cục bộ (dùng phương thức của lớp)** và **hàm toàn cục (dùng hàm bạn)**.

> Overload toán tử nhập :

```cpp
class PhanSo {
    friend istream &operator >> (istream &in, PhanSo &ps);
}
istream &operator >> (istream &in, PhanSo &ps) {
    cout << "Tu: ";
    in >> ps.tu;
    cout << "Mau: ";
    in >> ps.mau;
    return in;
}
```

> Overload toán tử xuất :

```cpp
class PhanSo {
    friend ostream &operator << (ostream &out, PhanSo ps);
}
ostream &operator << (ostream &out, PhanSo ps) {
    if (ps.tu == 0) out << 0;
    else if (ps.mau == 1) out << ps.tu;
    else out << ps.tu << '/' << ps.mau;
    return out;
}
```

> ## Function Overriding
---

Như chúng ta đã biết, kế thừa là một tính năng của OOP cho phép chúng ta tạo các lớp dẫn xuất từ một lớp cơ sở. Các lớp dẫn xuất kế thừa các tính năng của lớp cơ sở.

Giả sử, cùng một hàm được định nghĩa trong cả lớp dẫn xuất và lớp dựa trên. Bây giờ nếu chúng ta gọi hàm này bằng cách sử dụng đối tượng của lớp dẫn xuất, hàm của lớp dẫn xuất được thực thi.

Điều này được gọi là chức năng ghi đè trong C++. Hàm trong lớp dẫn xuất ghi đè hàm trong lớp cơ sở.

EX:

```c++
#include <iostream>
using namespace std;

class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1;
    derived1.print();
    return 0;
}
```

OUTPUT:

```
Derived Function
```

![](https://cdn.programiz.com/sites/tutorial2program/files/cpp-function-overriding.png)

- Để truy cập hàm overridden của lớp cơ sở, chúng ta sử dụng toán tử độ phân giải phạm vi : :

- Chúng ta cũng có thể truy cập hàm ghi đè bằng cách sử dụng một con trỏ của lớp cơ sở để trỏ đến một đối tượng của lớp dẫn xuất và sau đó gọi hàm từ con trỏ đó.

```c++
class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1, derived2;
    derived1.print();

    // access print() function of the Base class
    derived2.Base::print();

    return 0;
}
```

OUTPUT:

```
Derived Function
Base Function
```

![](https://cdn.programiz.com/sites/tutorial2program/files/cpp-access-overridden-function-using-object.png)

Hoặc :

```c++
class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;
        Base::print();
    }
};
```

![](https://cdn.programiz.com/sites/tutorial2program/files/cpp-access-overridden-function-inside-derived-class.png)

- Dùng con trỏ :

```c++
class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1;

    // pointer of Base type that points to derived1
    Base* ptr = &derived1;

    // call function of Base class using ptr
    ptr->print();

    return 0;
}
```

OUTPUT:

```
Base Function
```
