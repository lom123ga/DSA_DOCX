#  Object-oriented programming 

***created by Trieu Ngoc Tam*** <br>
language: Vietnamese <br>
Programming Language : C++

## OOP ( viết tắt của Object-oriented programming) 
- lập trình hướng đối tượng là một phương pháp lập trình về lớp và đối tượng. OOP tập trung vào các đối tượng thao tác hơn là logic để thao tác chúng, giúp code dễ quản lý, tái sử dụng được và dễ bảo trì.

<br>

> Đầu tiên ta cùng tìm hiểu Object (đối tượng) và Class (lớp) là gì ?

![](https://images.viblo.asia/full/cca858a7-0231-43b3-ae11-408cf7a25c19.png)

## I. Object :

Object gồm 2 thành phần chính :
- Attribute (thuộc tính) : là những thông tin, đặc điểm, của đối tượng.
- Method (phương thức) : là những hành vi mà đối tượng có thể thực hiện.

Để dễ hình dung ta có một ví dụ thực tế về Object là con người (bạn Tâm chẳng hạn), đối tượng này có :
- Attribute : màu tóc, chiều cao, cân nặng, đẹp trai, ...
- Method : ăn cơm, đi bộ, lăn, bò, trườn, ...

## II. Class :

Class là sự trừu tượng hoá của đối tượng. Những đối tượng có những đặc tính đặc tính tương tự nhau sẽ được tập trung thành một class. Class cũng sẽ bao gồm 2 thông tin là attribute và method.

Một object có thể xem là một thực thể của class.

Ví dụ về class con người , có 2 thành phần :
- Attribute : màu tóc, chiều cao, cân nặng, ...
- Method : ăn cơm, đi bộ, lăn, bò, trườn, ...

và các Object của nó là : giáo viên, anh thợ sửa ống nước, bác hàng xóm, cô lao công, ...

> Vậy class là một khuôn mẫu của object và object là một sự thể hiện của class.

VD : 

```c++
    // Create a Car class with some attributes
    class Car {
        public:
            string brand;   
            string model;
            int year;
    };

    int main() {
        // Create an object of Car
        Car carObj1;
        carObj1.brand = "BMW";
        carObj1.model = "X5";
        carObj1.year = 1999;

        // Create another object of Car
        Car carObj2;
        carObj2.brand = "Ford";
        carObj2.model = "Mustang";
        carObj2.year = 1969;

        // Print attribute values
        cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
        cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
        return 0;
    }
```

## III. Con trỏ this :

> **this->** là một con trỏ đặc biệt ẩn dấu bên trong hàm thành viên của class, có tác dụng trỏ đến địa chỉ của đối tượng hiện tại. Như vậy để truy cập đến các attribute, method của đối tượng hiện tại thì ta sẽ sử dụng con trỏ **this**.

VD : trong contructor của class Persion có attribute là name và age:
```c++
    //(attribute) :
    int age;
    string name;
    // Contructor :
    Persion(string name, int age){
        this->name = name;
        this->age = age;
    }

```

- ta thấy Contructor của Class Persion có vào 2 tham số là name và age và ta có thể dùng con trỏ this để gán giá trị của attribute của đối tượng hiện tại.

## IV. tính chất của OOP :
---

![](https://media.geeksforgeeks.org/wp-content/uploads/OOPs-Concepts.jpg)

> OOP có 4 tính chất quan trọng là :
- Abstraction (Tính trừu tượng)
- Encapsulation (Tính đóng gói)
- Polymorphism (Tính đa hình)
- Inheritance (Tính kế thừa)

### Trong bài này ta sẽ tập trung tìm hiểu về Encapsulation và Abstraction :

1. **Encapsulation** :
---

![](https://images.viblo.asia/e9bf3532-2291-4c0b-8873-d17852e9d173.png)

Trong OOP , *Encapsulation* có nghĩa là liên kết các dữ liệu và các chức năng vận dụng của chúng với nhau.

ý nghĩa của *Encapsulation* là ẩn những dữ liệu quan trọng khỏi người dùng và khi muồn truy cập vào dữ liệu ấy cần thông qua các method liên quan tới chúng.

*Encapsulation* giúp đảm bảo kiểm soát dữ liệu tốt hơn khi mà bạn có thể sửa một đoạn code và không lo ảnh hưởng đến những đoạn khác. Và nó cũng tăng độ bảo mật dữ liệu của bạn.

> Encapsulation cũng dẫn đến việc trừu tượng hoá hoặc ẩn dữ liệu.

2. **Abstraction** :
---

*Abstraction* là một trong những tính năng quan trọng và cần thiết nhất trong OOP. Nó có nghĩ là chỉ hiện những thông tin cần thiết và ẩn những chi tiết khác đi.

Trừu tượng hoá dữ liệu đề cập đến việc chỉ cung cấp những thôn tin cần thiết về dữ liệu và che dấu những thôn tin cơ bản về dữ liệu hoăc triển khai chúng.

VD về việc một người lái ô tô : khi anh ta nhấn ga để tăng tốc độ hoặc phanh để giảm tốc độ. Anh ta chỉ biết là bấm ga là tăng tốc, nhấn phanh là giảm tốc chứ không biết tốc độ thực sự sẽ thay đổ như nào, không biết về viêch thực hiện nhấn ga thì các cơ quan trong ô tô thay đổi như nào. Đó là tính trừu tượng.

Abstraction trong C++ :

- Abstraction using Classes: Class giúp ta gộp những dữ liệu và các hàm thành viên bằng cách sử dụng các **access specifiers** (nhãn phạm vi). Một Class có thể quyết định rằng dữ liệu nào sẽ hiển thị với bên ngoài và dữ liệu  nào không.

- Abstraction in Header files: Một loại trừu tượng trong C++ là các *header files*. Ví dụ với hàm **pow()** trong header files "math.h".
Mỗi khi chúng ta cần tính luỹ thừa thì ta chỉ cần gọi hàm pow thuộc thư viện "math.h" và truyền vào các đối số mà không cần biết thuật toán thực sự hàm đang chạy để tính luỹ thừa.

## V. Access Modifier 
---

Access modifier được dùng để triển khai một khía cạnh quan trọng trong OOP đó là **data hiding**.

Access modifier trong 1 Class gán khả năng truy cập cho các thành viên trong lớp. Tức là nó đặt một số hạn chế đối với các thành viên trong Class để bên ngoài không thể truy cập trực tiếp vào được.

Có 3 kiểu access modifier trong C++ :

- Public
- Private
- Protected

> Note : Nếu ta không chỉ đinh bất kỳ nhã phạm vi nào cho các thành viên trong Class thì mặc định access modifier sẽ là **Private**.

1. Public : Tất cả các thành viên trong Class được công khai và có thể truy cập với các hàm và lớp khác. Các hành viên trong 1 lớp có thể truy cập từ bất kỳ đâu trong chương trình bằng toán tử (.) với đối tượng của lớp đó.

Ex : 
```c++
    #include<iostream>
    using namespace std;
 
    class Circle
    {
        public:
            double radius;
            
            double  compute_area()
            {
                return 3.14*radius*radius;
            }
        
    };

    int main()
    {
        Circle obj;

        obj.radius = 5.5;
        
        cout << "Radius is: " << obj.radius << "\n";
        cout << "Area is: " << obj.compute_area();
        return 0;
    }
```


2. Private:  Các thành viên trong Class được khai báo là Private chỉ có thể được truy cập bới các hàm thành viên trong Class. Các Object và hàm ngoài không thể truy cập trực tiếp vào chúng ngoại trừ các **friend_function** được phép truy cập dữ liệu private của Class.

Ex :
```c++
    #include<iostream>
    using namespace std;
    
    class Circle
    { 
        private:
            double radius;
    
        public:   
            double  compute_area()
            {   
                return 3.14*radius*radius;
            }
        
    };
 
    int main()
    {  
        Circle obj;
    
        obj.radius = 1.5;
        
        cout << "Area is:" << obj.compute_area();
        return 0;
    }
```

> Output: 
```text
 In function 'int main()':
11:16: error: 'double Circle::radius' is private
         double radius;
                ^
31:9: error: within this context
     obj.radius = 1.5;
         ^
```

3. Protected: Nó cũng giống như Private, ngoại trừ việc có thể truy cập bới Friend Class. Các thành viên của lớp được khai báo là Protected có thể được truy cập bới bất kỳ subclass (lớp con) nào của Class đó.

Ex :

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    class Parent
    {  
        protected:
        int id_protected;
        
    };
    
    class Child : public Parent
    {
        public:
        void setId(int id)
        {

            id_protected = id;
            
        }
        
        void displayId()
        {
            cout << "id_protected is: " << id_protected << endl;
        }
    };
    
    int main() {
        
        Child obj1;
        
        obj1.setId(81);
        obj1.displayId();
        return 0;
    }
```
>Output:
```text
    id_protected is: 81
```

## VI. Constructor(Hàm khởi tạo), Destructor(Hàm hủy)
---

Cũng giống như struct, Class cũng có Constructor và Destructor.

1. Constructor :

- Constructor là một phương thức đặc biệt được gọi tự động tại thời điểm đối tượng được tạo ra.

- Mục đích của hàm xây dựng dùng để khởi tạo dữ liệu cho dữ liệu thành viên.

- Constructor phải trùng tên với tên lớp và không có kiểu trả về kể cả kiểu void.

- Constructor có thể có đối số hoặc không có đối số.

- Trong một lớp có thể có nhiều Constructor (cùng tên nhưng khác đối số).

- Vì mục đích để khởi tạo dữ liệu lên phải được khai báo với phạm vi là Public. Nếu contructor được khai báo là Private thì chỉ có thể được truy cập trong chính lớp được khai báo đó.

Ex:
```c++
    //Hàm khởi tạo không có tham số
    Circle(){
		this->r = 0;
	}
	//Hàm khởi tạo có tham số
	Circle(float r){
		this->r = r;
	}
```

2. Destructor :

- Destructor sẽ tự động được gọi trước khi giải phóng một đối tượng để giải phóng vùng nhớ trước khi đối tượng được hủy bỏ.

- Mỗi lớp chỉ có một Destructor.

- Destructor không có kiểu, không có giá trị trả về và không có đối số.

-  Tên Destructor cùng tên với tên lớp và có một dấu ngã (~) ngay trước tên.

Ex:

```c++
    ~Circle(){
		cout<<"Radius of circle has destroyed."<<endl;
	}
```

## VII. Getter, Setter 
---

Trong C++, Encapsulation là quá trình trong đó thông tin quan trọng được dữ kín. Điều này làm cho không thể thay đổi giá trị dữ liệu từ bên ngoài Class. Vì vậy chúng ta cần một hàm đặc biệt đễ truy xuất những dữ liệu đó và đặt giá trị.

OOP cung cấp các hàm getter và setter để đáp ứng các yêu cầu đó. Các hàm getter và setter cho phép truy cập vào dữ liệu ở chế độ an toàn.

Ex :
``` C++
    class GetSet {
 
        // Member variable of this class
        private:
            String name;
    
        public:
            // Method 1 - Getter
            String getName() { return name; }
    
            // Method 2 - Setter
            void setName(String N)
            {
        
                // This keyword refers to current instance itself
                this.name = N;
            }
    }
```

## VIII. Biến Static trong C++
---

1. Biến static trong Hàm:

 - Khi một biến được khai báo với từ khóa static, vùng nhớ cho nó tồn tại theo vòng đời của chương trình.
 - Ngay cả khi hàm được gọi nhiều lần, vùng nhớ cho biến static chỉ được cấp nhát một lần và giá trị của biến trong những lần gọi trước đó được lưu lại và được sử dụng để thực hiện thông qua các lượt gọi hàm tiếp theo.

2. Các biến static trong class:

 - Vì các biến được khai báo là static chỉ được khởi tạo một lần khi chúng được cấp phát một địa chỉ trong bộ lưu trữ tĩnh riêng biệt, do đó, các biến static trong một lớp được chia sẻ bởi các đối tượng.
 - Chúng ta không tạo ra các bản sao cho cùng một biến tĩnh của các đối tượng khác nhau.
 - Cũng vì lý do này mà các biến tĩnh không thể được khởi tạo bằng cách sử dụng các hàm khởi tạo (hàm constructor()).

 ```c++
    #include<iostream> 
    using namespace std; 
    
    class GfG 
    { 
    public: 
        static int i; 
        
        GfG() {  }; 
    }; 
    
    int main() 
    { 
    GfG obj1; 
    GfG obj2; 
    obj1.i =2; 
    obj2.i = 3; 
        
    cout << obj1.i<<" "<<obj2.i;
    } 
 ```
```text
    ---> chương trình lỗi, không chạy được.
```

>  mình thử tạo ra nhiều bản sao của biến static i của các đối tượng. Nhưng việc này là không thể.

Vì vậy, một biến static bên trong một class nên được khởi tạo bằng cách sử dụng toán tử tên và toán tử phân giải phạm vi bên ngoài class như dưới đây:

```c++
    class GfG 
    { 
    public: 
        static int i; 
        
        GfG() {}; 
    }; 
    
    int GfG::i = 1; 
    
    int main() 
    { 
        GfG obj; 
        cout << obj.i;  
    } 
```

3. Thành viên static của class :

Các đối tượng của class là static: Cũng giống như các biến, các đối tượng khi được khai báo là static có thời gian tồn tại bằng với thời gian tồn tại của chương trình

> hàm thường

```c++
    #include<iostream> 
    using namespace std; 
    
    class GfG 
    { 
        int i = 0; 
        
        public: 
        GfG() 
        { 
            i = 0; 
            cout << "Inside Constructor\n"; 
        } 
        
        ~GfG() 
        { 
            cout << "Inside Destructor\n"; 
        } 
    }; 
    
    int main() 
    { 
        int x = 0; 
        if (x==0) 
        { 
            GfG obj; 
        } 
        cout << "End of main\n"; 
    } 
```
```text
    Inside Constructor
    Inside Destructor
    End of main
```
> hàm static

```c++
    #include<iostream> 
    using namespace std; 
    
    class GfG 
    { 
        int i = 0; 
        
        public: 
        GfG() 
        { 
            i = 0; 
            cout << "Inside Constructor\n"; 
        } 
        
        ~GfG() 
        { 
            cout << "Inside Destructor\n"; 
        } 
    }; 
    
    int main() 
    { 
        int x = 0; 
        if (x==0) 
        { 
            static GfG obj; 
        } 
        cout << "End of main\n"; 
    } 
```
```text
    Inside Constructor
    End of main
    Inside Destructor
```

> Các hàm static trong class: Giống như các thành viên kiểu static hoặc các biến static bên trong class, các hàm static cũng không phụ thuộc vào đối tượng của class.

```c++
    #include<iostream> 
    using namespace std; 
    
    class GfG 
    { 
    public: 
        
        // static member function 
        static void printMsg() 
        { 
            cout<<"Welcome to GfG!"; 
        } 
    }; 
    
    // main function 
    int main() 
    { 
        // invoking a static member function 
        GfG::printMsg(); 
    } 
```
```text
    Welcome to GfG!
```

## IX. Kỹ thuật chia tách file (file.h và file.cpp)
---

Việc tách code C++ cũng như tách code ở các ngôn ngữ khác sẽ giúp:

- Dễ quản lí, bảo trì source code.
- Giúp code dễ đọc, dễ hiểu và dễ sử dụng.
- Tái sử dụng các hàm đã viết.

### Kỹ thuật tách file :

> CODE_MẪU :

```c++
    #include <iostream>
    #include <string>
    #include <cmath>
    
    using namespace std;
    
    // Các hàm tính toán - Math
    int UCLN(int a, int b){
        if(a == b)
            return a;
        else if(a > b)
            return UCLN(a - b, b);
        else
            return UCLN(a, b - a);
    }
    
    int BCNN(int a, int b){
        int uc = UCLN(a, b);
        return a * b / uc;
    }
    
    bool laSoNguyenTo(int n){
        if(n < 2)
            return false;
        else if(n == 2)
            return true;
        else{
            int num = sqrt(n);
            for(int i = 2; i <= num; i++){
                if(n % i == 0)
                    return false;
            }
            return true;
        }
    }
    
    // Các hàm về chuỗi - string
    
    string inHoa(string xau){
        for(int i = 0; i < xau.size(); i++){
            if(xau[i] >= 'a' && xau[i] <= 'z')
                xau[i] = xau[i] - 'a' + 'A';
        }
        return xau;
    }
    
    string inThuong(string xau){
        for(int i = 0; i < xau.size(); i++){
            if(xau[i] >= 'A' && xau[i] <= 'Z')
                xau[i] = xau[i] - 'A' + 'a';
        }
        return xau;
    }
    
    int main(){
        cout << UCLN(18, 27) << endl;
        cout << inHoa("Lap Trinh Khong Kho") <<  endl;
        return 0;
    }
```

Có thể thấy: Chương trình được viết vào một file main.cpp duy nhất. Và các hàm (function) của mình có 2 loại. “Loại 1: Các hàm về tính toán” và “Loại 2: Các hàm về xâu chuỗi”. Mình sẽ tách chương trình trên thành các file sau:

- Header.h – Các thư viện dùng chung như “iostream”,…
- Math_Fn.h và Math_Fn.cpp – Các hàm về tính toán
- String_Fn.h và String_Fn.cpp – Các hàm về xâu, chuỗi
- main.cpp – Hàm main, chạy code
- file .h dùng để khai báo hàm và file .cpp dùng để viết hàm.

> Mã code các file :

1. File: Header.h <br>
Đối với mình, đây sẽ là file include các thư viện mà tất cả các file khác đều phải có.

```c++
    #pragma once
    #include <iostream>
    using namespace std;
```

> tại sao lại cần **#pragma once** ở đầu file .h

Khi bạn include một file header (.h) thì tức là bạn đã include “toàn bộ những gì mà file header đó include”. Hãy nhìn hình dưới đây:

![](https://blog.luyencode.net/wp-content/uploads/2022/01/Minh-hoa-1024x734.png)

Như vậy ở file main.cpp, ta đã include iostream 2 lần. Điều này sẽ gây ra xung đột và có thể khiến chương trình không thể chạy được. Và thêm “#pragma once” ở đầu giúp chúng ta khắc phục điều đó, nó mang ý nghĩa include thư viện một lần, tránh sự trùng lặp.

> File: Math_Fn.h
```c++ 
#pragma once
#include "Header.h"
#include <cmath>
 
// Các hàm về tính toán - Math
int UCLN(int a, int b);
int BCNN(int a, int b);
bool laSoNguyenTo(int n);
```

> File: Math_Fn.cpp

```c++
#include "Math_Fn.h"
 
int UCLN(int a, int b) {
    if (a == b)
        return a;
    else if (a > b)
        return UCLN(a - b, b);
    else
        return UCLN(a, b - a);
}
 
int BCNN(int a, int b) {
    int uc = UCLN(a, b);
    return a * b / uc;
}
 
bool laSoNguyenTo(int n) {
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else {
        int num = sqrt(n);
        for (int i = 2; i <= num; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
```

> File: String_Fn.h

```c++
    #pragma once
    #include "Header.h"
    #include <string>
    
    // Các hàm về chuỗi - string
    string inHoa(string xau);
    string inThuong(string xau);
```

> File: String_Fn.cpp

```c++
    #include "String_Fn.h"
 
    // Các hàm về chuỗi - string
    
    string inHoa(string xau) {
        for (int i = 0; i < xau.size(); i++) {
            if (xau[i] >= 'a' && xau[i] <= 'z')
                xau[i] = xau[i] - 'a' + 'A';
        }
        return xau;
    }
    
    string inThuong(string xau) {
        for (int i = 0; i < xau.size(); i++) {
            if (xau[i] >= 'A' && xau[i] <= 'Z')
                xau[i] = xau[i] - 'A' + 'a';
        }
        return xau;
    }
```

> File: main.cpp

``` c++
    #include "Header.h"
    #include "Math_Fn.h"
    #include "String_Fn.h"
    
    int main() {
        cout << UCLN(18, 27) << endl;
        cout << inHoa("Lap Trinh Khong Kho") << endl;
        return 0;
    }
```

## X. Quy tắc đặt tên biến trong OOP C++
---

###  Dùng tiếng Anh

Luôn sử dụng tiếng Anh để đặt tên hàm và biến.

Ví dụ:

```cpp
/* Bad */
const hoTen = "Trạng Tí"
const banBe = ["Sửu Ẹo", "Dần Béo", "Cả Mẹo"]
/* Good */
const fullName = "Trạng Tí"
const friends = ["Sửu Ẹo", "Dần Béo", "Cả Mẹo"]
```

###  Quy ước đặt tên

Nếu team của bạn chọn quy ước đặt tên là `camelCase`, hãy sử dụng `camelCase` cho toàn bộ dự án, nếu bạn qua một team khác chuộng `snake_case` hơn, hãy tuân thủ nghiêm ngặt. Cho dù là quy ước nào thì điều quan trọng nhất chính là **tính nhất quán**.

```cpp
/* Bad */
const page_count = 5
const isUser = true
/* Good */
const pageCount = 5
const isUser = true
/* Good as well */
const page_count = 5
const is_user = true
```

###  Nguyên tắc S-I-D

- **Short (ngắn gọn)**: tên không được dài, không phải mất thời gian để gõ và nhớ.
- **Intuitive (tự nhiên)**: tên khi đọc lên phải cho cảm giác xuôi tai, gần gũi với văn nói.
- **Descriptive (súc tích)**: tên phải mô tả được ý nghĩa, tác dụng của nó, bằng cách hiệu quả nhất.

```cpp
/* Bad */
const totalNumberOfPublishedArticles = 10 // tên quá dài
const a = 5 // "a" không mô tả được số 5 để làm gì
const isDisplayable = a > 5 // "isDisplayable" nghe không tự nhiên lắm
/* Good */
const totalArticles = 10
const postCount = 5
const shouldDisplay = postCount > 5
```
