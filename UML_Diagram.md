# UML Class Diagram

> UML Class Diagram là một ký hiệu đồ hoạ dùng để xây dựng và trực quan hoá các hệ thống hướng đối tượng.   Một Class Diagram trong UML ( Unified Modeling Language ) là một loại biểu đồ cấu trúc tĩnh mô tả cấu trúc của hệ thống bằng cách hiển thị :
- Classes
- Attributes
- Operations (or methods)
- Và các quan hệ giữa các đối tượng

## UML Class Notation
---

Một Class đại diện cho một khái niệm bao gồm state(attributes) và behavior(operations). Mỗi attribute  và method có một kiểu dữ liệu. Riêng tên Class là thông tin bắt buộc duy nhất.

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/02-class-notation.png)

*Class Name* :
- Tên của Class xuất hiện trong phân vùng đầu tiên

*Class Attributes* :
- Attributes được hiển thị trong phân vùng thứ 2
- Atribute type được hiển thị sau dấu " : "
- Atributes tương ứng với các biến thành viên trong code

*Class Operations (Methods)* :
- Operations được hiển thị trong phân vùng thứ 3. Chúng là những method mà Class cung cấp
- Kiểu trả về của mối method được hiển thị sau dấu " : "
- Kiểu trả về của các tham số được hiển thị sau dấu " : " theo sau tên tham số

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/03-class-notation-with-examples.png)

### Access Modifier
---

Các ký hiệu **+** , **-** , **#** đứng trước tên Atributes và operations biểu thị cho phạm vi hoạt động của attribute và operation đó.

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/04-class-attributes-with-different-visibility.png)

- " + " : Public
- " - " : Private
- " # " : Protected

### Tham số truyền vào 
---

Mõi tham số trong một operation(method) có thể được ký hiệu là in , out hoặc inout chỉ sự đính hướng của nó đối với người gọi và được hiển thị trước tên tham số.

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/05-parameter-directionality.png)

## Relationship trong class diagram
---

UML không phải chỉ là những hình ảnh đẹp. Nếu được sử dụng một cách chính xác, UML truyền tải chính xác cách thức code được triển khai từ các sơ đồ. Nếu được giải thích chính xác, code được triển khai sẽ phản ánh chính xác ý định của người thiết kế.

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/07-relationships-between-classes.png)

Ta tìm hiểu sâu về  Composition, Agregation và Cardinality.

> Aggregation

- ClassA và ClassB có quan hệ Association với nhau
- Object của ClassA có chứa object của ClassB
- Object của ClassA và Object của ClassB có vòng đời riêng biệt. Nghĩa là A bị hủy thì B sẽ không bị hủy theo.
- Còn gọi là : Whole A – Part B . Nghĩa là A được tạo từ nhiều B kết hợp lại , và B có thể tạo ra độc lập , không cần phải tạo ra A , B có thể cùng thuộc 1 whole khác A.

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/12-aggregation.png)

> Composition

- ClassA và ClassB có quan hệ Association với nhau
- Còn gọi là Whole A – Part B . Nghĩa là A được tạo từ nhiều B kết hợp lại , nhưng B không thể đứng 1 mình được , B chỉ là thuộc A mà thôi không thể cùng thuộc Whole khác được.
- Object của Class A có chứa object của ClassB. Nếu A bị hủy thì B sẽ không tồn tại. ngược lại, B bị hủy thì se không ảnh hưởng đến A

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/13-composition.png)

> Dependency

Một đối tượng của một lớp có thể sử dụng một đối tượng của một lớp khác trong mã của một phương thức. Nếu đối tượng không được lưu trữ trong bất kỳ trường nào, thì điều này được mô hình hóa như một mối quan hệ phụ thuộc.

- Tồn tại giữa hai lớp nếu những thay đổi đối với định nghĩa của một lớp có thể gây ra thay đổi cho lớp kia (nhưng không phải ngược lại).

Hình dưới đây cho thấy một ví dụ về sự phụ thuộc. Mối quan hệ được hiển thị dưới dạng đường đứt nét với mũi tên mở.

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/14-dependency.png)

Hình dưới đây cho thấy một ví dụ khác về sự phụ thuộc. Lớp Person có thể có phương thức hasRead với tham số Book trả về true nếu người đó đã đọc sách (có lẽ bằng cách kiểm tra một số cơ sở dữ liệu).

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/15-dependency-example.png)

> Realization

Hiện thực hóa là mối quan hệ giữa lớp blueprint và đối tượng chứa các chi tiết cấp độ triển khai tương ứng của nó. Đối tượng này được cho là hiện thực hóa lớp bản thiết kế. Nói cách khác, bạn có thể hiểu đây là mối quan hệ giữa giao diện và lớp triển khai.

Ví dụ: giao diện Chủ sở hữu có thể chỉ định các phương pháp để có được tài sản và xử lý tài sản. Các lớp Person và Corporation cần thực hiện các phương pháp này, có thể theo những cách rất khác nhau.

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/16-realization.png)


> Cardinality

Cardinality được thể hiện dưới dạng :

- one to one
- one to many
- many to many

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/11-associations-with-different-multiplicies.png)

> multiplicity :
- thể hiện sự quan hệ giữa các Class với nhau
