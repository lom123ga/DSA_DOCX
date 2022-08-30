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

> Cardinality

Cardinality được thể hiện dưới dạng :

- one to one
- one to many
- many to many

![](https://cdn-images.visual-paradigm.com/guide/uml/uml-class-diagram-tutorial/11-associations-with-different-multiplicies.png)

> multiplicity :
- thể hiện sự quan hệ giữa các Class với nhau
