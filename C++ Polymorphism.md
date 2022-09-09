# C++ Polymorphism

![https://codelearn.io/Upload/Blog/tinh-da-hinh-trong-oop-63730380096.806.jpg](https://codelearn.io/Upload/Blog/tinh-da-hinh-trong-oop-63730380096.806.jpg)

# Đặt vấn  đề khi cần sử dụng Đa hình ?

---

Sự kế thừa trong C++ cho phép có sự tương ứng giữa lớp cơ sở và các lớp dẫn xuất trong sơ đồ thừa kế:

- Một con trỏ có kiểu lớp cơ sở luôn có thể trỏ đến địa chỉ của một đối tượng của lớp dẫn xuất.
- Tuy nhiên, khi thực hiện lời gọi một phương thức của lớp, trình biên dịch sẽ quan tâm đến kiểu của con trỏ chứ không phải đối tượng mà con trỏ đang trỏ tới: phương thức của lớp mà con trỏ có kiểu được gọi chứ không phải phương thức của đối tượng mà con trỏ đang trỏ tới được gọi.

**Ví dụ:** Lớp mayAcer kế thừa từ lớp `Mayvitinh`, cả hai lớp này đều định nghĩa phương thức `show()`

```cpp
class Mayvitinh{  
	public: 	 	 	
	void show(){
	    cout << "mayvitinh" << endl;
	}
}; 
class mayAcer: public Mayvitinh{  	
    public: 	 	 	
    void show(){
        cout << "mayAcer" << endl;
    }
};
```

khi đó, nếu ta khai báo một con trỏ lớp `Mayvitinh`, nhưng lại trỏ vào địa chỉ của một đối tượng lớp  `mayAcer` :

```cpp
mayAcer may1; 
Mayvitinh *tenmay = &may1;
tenmay->show();
```

thì chương trình sẽ gọi đến phương thức `show()` của lớp `Mayvitinh`, mà không gọi tới phương thức `show()` của lớp `mayAcer`.

Để giải quyết vấn đề này, chúng ta cần sử dụng đến **tính đa hình (Polymorphism)**  trong Lập trình hướng đối tượng. Mình sẽ giải thích chi tiết hơn ở bên dưới.

**Đa hình (polymorphism)** nghĩa là có nhiều hình thái khác nhau. Tiêu biểu là, **đa hình** xuất hiện khi có một cấu trúc cấp bậc của các lớp và chúng liên quan với nhau bởi tính kế thừa.

Mình lấy một ví dụ thực thế nhé: Một người cùng một lúc có thể có đặc điểm khác nhau. Giống như một người học sinh đồng thời là một người con trai, một người bạn, một người anh. Vì vậy, cùng một người sở hữu những hành vi khác nhau trong các tình huống khác nhau. Điều này được gọi là **đa hình**.

**Đa hình** được coi là một trong những tính năng quan trọng của OOP .

![https://dotnettutorials.net/wp-content/uploads/2022/06/word-image-26906-1.png](https://dotnettutorials.net/wp-content/uploads/2022/06/word-image-26906-1.png)

# ****Types of Polymorphism in C++:****

---

- **Tính đa hình** chủ yếu được chia thành hai loại:
1. **Compile-time Polymorphism** (**Example:** **[Function Overloading](https://dotnettutorials.net/lesson/function-overloading-in-cpp/)**, and **[Operator Overloading](https://dotnettutorials.net/lesson/operator-overloading-in-cpp/)**)
2. **Runtime Polymorphism** (Example: **[Function Overriding](https://dotnettutorials.net/lesson/function-overriding-in-cpp/)** and **[Virtual Functions](https://dotnettutorials.net/lesson/virtual-functions-in-cpp/)**)

![https://dotnettutorials.net/wp-content/uploads/2022/06/word-image-26906-2.png](https://dotnettutorials.net/wp-content/uploads/2022/06/word-image-26906-2.png)

## I. Compile-time Polymorphism:

---

- **Tính đa hình** này được sử dụng bằng cách nạp chồng hàm hoặc nạp chồng toán tử.
- Các hàm nạp chồng được gọi bằng cách khớp kiểu và số lượng đối số. Thông tin hiện diện trong thời gian biên dịch. Điều này có nghĩa là trình biên dịch C ++ sẽ chọn đúng chức năng tại thời điểm biên dịch. Tính đa hình thời gian biên dịch đạt được thông qua quá trình nạp chồng hàm và nạp chồng toán tử, còn được gọi là liên kết tĩnh hoặc liên kết sớm.

## II. Runtime Polymorphism:

---

- Runtime polymorphism đạt được khi phương thức của đối tượng được gọi vào thời gian chạy thay vì thời gian biên dịch. Nó đạt được bằng cách ghi đè phương pháp (function overriding) còn được gọi là liên kết động hoặc liên kết muộn.
- việc ghi đè hàm xảy ra khi một lớp dẫn xuất có định nghĩa cho một trong các hàm thành viên của lớp cơ sở. Hàm cơ sở đó được cho là bị ghi đè. Ghi đè hàm xảy ra khi một hàm của lớp cơ sở được đưa ra một định nghĩa mới trong một lớp dẫn xuất. Tại thời điểm đó, chúng ta có thể nói hàm cơ sở đã bị ghi đè. (VD : ở phần inheritance đã có rồi)
- Virtual function là một cách khác để triển khai tính đa hình thời gian chạy trong C ++. Nó là một hàm đặc biệt được định nghĩa trong một lớp cơ sở và được định nghĩa lại trong lớp dẫn xuất. Để khai báo một hàm ảo, bạn nên sử dụng từ khóa *virtual*. Từ khóa phải đứng trước phần khai báo của hàm trong lớp cơ sở. Nếu một lớp hàm ảo được kế thừa, lớp ảo sẽ xác định lại hàm ảo cho phù hợp với nhu cầu của nó.

Ta dùng luôn ví dụ đầu tiên ở trên :

```cpp
#include <iostream>
using namespace std;

class Mayvitinh{  
	public: 	 	 	
	void show(){
	    cout << "mayvitinh" << endl;
	}
}; 
class mayAcer: public Mayvitinh{  	
    public: 	 	 	
    void show(){
        cout << "mayAcer" << endl;
    }
}; 

int main(){
    mayAcer may1; 
    Mayvitinh *tenmay = &may1;
    tenmay->show(); 
}
```

Có thể thấy chương trình sau khi chạy sẽ gọi đến phương thức `show()` của lớp `Mayvitinh`, mà không gọi tới phương thức `show()` của lớp `mayAcer`.

Vậy để chương trình gọi tới phương thức `show()` của lớp `mayAcer` ta sử dụng hàm ảo `virtual` như sau:

```cpp
#include <iostream>
using namespace std;

class Mayvitinh{  
	public: 	 	 	
	virtual void show(){
	    cout << "mayvitinh" << endl;
	}
}; 
class mayAcer: public Mayvitinh{  	
    public: 	 	 	
    void show(){
        cout << "mayAcer" << endl;
    }
}; 

int main(){
    mayAcer may1; 
    Mayvitinh *tenmay = &may1;
    tenmay->show(); 
}
```

OUTPUT:

```cpp
mayAce
```

- Trong ví dụ trên mình đã thêm từ khóa `virtual` vào hàm `show()` trong lớp cơ sở `Mayvitinh`.
- Từ khóa `virtual` này dùng để khai báo một hàm là hàm ảo.

Khi khai báo hàm ảo với từ khóa `virtual` nghĩa là hàm này sẽ được gọi theo loại đối tượng được trỏ (hoặc tham chiếu), chứ không phải theo loại của con trỏ (hoặc tham chiếu). Và điều này dẫn đến kết quả khác nhau:

- Nếu không khai báo hàm ảo `virtual` trình biên dịch sẽ gọi hàm tại lớp cở sở
- Nếu dùng hàm ảo `virtual` trình biên dịch sẽ gọi hàm tại lớp dẫn xuất

Khi nhận thấy có khai báo **virtual** trong lớp cơ sở, trình biên dịch sẽ thêm vào mỗi đối tượng của lớp cơ sở và các lớp dẫn xuất của nó một con trỏ chỉ đến bảng phương thức ảo (virtual function table). Con trỏ đó có tên là vptr (virtual pointer). Bảng phương thức ảo là nơi chứa các con trỏ chỉ đến đoạn chương trình đã biên dịch ứng với các phương thức ảo. Mỗi lớp có một bảng phương thức ảo. Trình biên dịch chỉ lập bảng phương thức ảo khi bắt đầu có việc tạo đối tượng của lớp. Đến khi chương trình chạy, phương thức ảo của đối tượng mới được nối kết và thi hành thông qua con trỏ vptr. ( Tức là tạo ra một con trỏ vptr trong lớp cha chỉ đến hàm ảo gần nhất với class đó )

Cộng dụng : Các hàm ảo cho phép chúng ta tạo một danh sách các con trỏ lớp cơ sở và phương thức gọi của bất kỳ lớp dẫn xuất nào mà không cần biết loại đối tượng lớp dẫn xuất.

![https://media.geeksforgeeks.org/wp-content/uploads/VirtualFunction.png](https://media.geeksforgeeks.org/wp-content/uploads/VirtualFunction.png)

Phương thức thuần ảo là 1 phương thức ảo (virtual) nhưng không có nội dung (không có thân hàm) và được khai báo bằng cách gán giá trị 0 như sau:

```cpp
class Hinh {
    	public:
    	virtual void Ve() = 0;
    };
```

---

**Lưu ý:** chỉ có hàm ảo (có từ khóa virtual) mới được phép gán giá trị 0.

Chúng ta có hàm Ve (nó là vẽ đó các bạn) để vẽ được hình chữ nhật, hình vuông, tam giác,… nhưng ở lớp hình chúng ta không có gì để vẽ ra cả -> phương thức vẽ nên là phương thưc thuần ảo.

Khi sử dụng phương thức thuần ảo cần phải biết:

- Nếu 1 lớp có 1 hoặc nhiều phương thức thuần ảo thì lớp đó được gọi là lớp cơ sở trừu tượng (abstract base class).
- Không thể khởi tạo 1 đối tượng thuộc lớp cơ sở trừu tượng.
- Nếu lớp con kế thừa từ lớp cha (với lớp cha là 1 lớp cơ sở trừu tượng) thì lớp con bắt buộc phải định nghĩa thân hàm cho hàm thuần ảo -> Nếu không làm (hoặc thiếu xót) lớp con đó sẽ được xem như là 1 lớp cơ sở trừu tượng.

Xem kỹ hơn :

```cpp
		#include <iostream>
    #include <string>
    using namespace std;
     
    class Hinh {
    	protected:
    	string Ten;
    	public:
    	virtual void Ve() = 0;
    };
     
    class HinhChuNhat : public Hinh {
    	public:
    	HinhChuNhat() {
    		Ten = "hinh chu nhat";
    	}
    	void Ve() {
    		cout << "dang ve " << Ten << endl;
    	}
    };
     
    class TamGiac : public Hinh {
    	public:
    	TamGiac() {
    		Ten = "hinh chu nhat";
    	}
    	/*
    	*Lớp tam giác không định nghĩa thân hàm Ve nên được
    	*xem như là 1 lớp cơ sở trừu tượng.
    	*/
    };
     
    int main() {
    	// your code goes here
    	Hinh *hinh; //hợp lệ
     
    	HinhChuNhat hcn; //hợp lệ
     
    	TamGiac tamgiac; //không hợp lệ do TamGiac là lớp
    					 //cơ sở trừu tượng nên ko tạo đối tượng được.
    	return 0;
    }
```

## Virtual destructor

---

```cpp
#include <iostream>
    using namespace std;
     
    class Base {
    	public:
    	~Base() {
    		cout << "Base destructor..." << endl;
    	}
    };
     
    class Derived : public Base {
    	int *arr;
    	int length;
    	public:
    	Derived(int l) {
    		arr = new int[l];
    	}
    	~Derived() {
    		if(arr) {
    			delete arr;
    			arr = nullptr;
    		}
    		cout << "Derived destructor..." << endl;
    	}
    };
     
    int main() {
    	// your code goes here
    	Base* ptr = new Derived(5);
    	delete ptr; // chú ý: chúng ta phải tự delete
    				// do C++ không tự hủy con trỏ.
    	return 0;
    }
```

OUTPUT:

```cpp
Base destructor...
```

Sủ dụng virtual cho destructtor:

```cpp
#include <iostream>
    using namespace std;
     
    class Base {
    	public:
    	virtual ~Base() {
    		cout << "Base destructor..." << endl;
    	}
    };
     
    class Derived : public Base {
    	int *arr;
    	int length;
    	public:
    	Derived(int l) {
    		arr = new int[l];
    	}
    	virtual ~Derived() {
    		if(arr) {
    			delete arr;
    			arr = nullptr;
    		}
    		cout << "Derived destructor..." << endl;
    	}
    };
     
    int main() {
    	// your code goes here
    	Base* ptr = new Derived(5);
    	delete ptr; // chú ý: chúng ta phải tự delete
    				// do C++ không tự hủy con trỏ.
    	return 0;
    }
```

OUTPUT:

```cpp
Derived destructor...
Base destructor...
```