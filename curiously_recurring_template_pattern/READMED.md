# Curiously Recurring Template Pattern (CRTP)

## What?
Curiously Recurring Template Pattern (CRTP) trong C++ là một kỹ thuật lập trình cho phép một lớp kế thừa từ một lớp template, trong đó lớp con đóng vai trò là tham số template cho lớp cơ sở.

CRTP cho phép lớp con điều khiển hành vi của nó thông qua việc định nghĩa các phương thức cụ thể, trong khi vẫn kế thừa các thuộc tính và phương thức từ lớp cơ sở. Kỹ thuật này được gọi là "curiously recurring" vì sự kỳ lạ của việc lớp con tự tham gia vào quá trình kế thừa của mình thông qua lớp template.


- Để hiểu CRTP, hãy xem xét một ví dụ đơn giản. Giả sử chúng ta muốn tạo ra một lớp cơ sở gọi là Base, và chúng ta muốn kế thừa từ Base để tạo ra một lớp dẫn xuất gọi là Derived. Tuy nhiên, chúng ta muốn lớp Derived có thể truy cập vào các thành viên của Base mà không cần thông qua một con trỏ hay tham chiếu đến Base.


Để hiểu CRTP, hãy xem xét ví dụ đơn giản sau:
```
template <typename Derived>
class Base {
public:
    void foo() {
        static_cast<Derived*>(this)->bar();
    }
};

class Derived : public Base<Derived> {
public:
    void bar() {
        // Đoạn mã cụ thể cho lớp Derived
    }
};
```
Trong ví dụ này, lớp Base là một lớp template và có một phương thức foo(). Trong phương thức foo(), ta sử dụng static_cast để ép kiểu con trỏ this sang kiểu Derived* và gọi phương thức bar() của lớp con.

Lớp Derived kế thừa từ lớp Base và truyền chính nó làm tham số template. Khi gọi phương thức foo() trên một đối tượng của lớp Derived, nó sẽ thực thi phương thức bar() cụ thể cho lớp Derived.

CRTP được sử dụng để cung cấp một cách để mở rộng và tùy chỉnh hành vi của các lớp con trong quá trình kế thừa. Kỹ thuật này cho phép lớp con kiểm soát một phần hành vi của nó thông qua việc định nghĩa các phương thức cụ thể, trong khi vẫn chia sẻ và tái sử dụng mã chung từ lớp cơ sở.

## When?
Curiously Recurring Template Pattern (CRTP) trong C++ được sử dụng trong các tình huống khi bạn muốn áp dụng một mô hình kế thừa có tính linh hoạt và tùy chỉnh hơn. Dưới đây là một số tình huống thường gặp mà CRTP có thể hữu ích:

Tạo ra sự tương thích tại thời điểm biên dịch: CRTP cho phép tạo ra các lớp con có sự tương thích tại thời điểm biên dịch với lớp cơ sở. Điều này có thể giúp tối ưu hóa hiệu suất và tránh trễ đến thời điểm chạy.

Triển khai tĩnh đa hình: CRTP cho phép triển khai tĩnh đa hình (static polymorphism), cung cấp các phương thức ảo tại thời điểm biên dịch. Điều này có thể tạo ra mã máy hiệu quả hơn và giảm độ trễ tại thời điểm chạy so với đa hình động (dynamic polymorphism).

Tùy chỉnh hành vi: CRTP cho phép lớp con điều khiển hành vi của nó thông qua việc định nghĩa các phương thức cụ thể. Điều này giúp tăng tính linh hoạt và khả năng tùy chỉnh của lớp con.

Mẫu thiết kế: CRTP thường được sử dụng trong việc triển khai các mẫu thiết kế như "Curiously Recurring Template Method" và "Static Polymorphism". Ví dụ, CRTP có thể được sử dụng để triển khai mẫu CRTP Method để cung cấp các phương thức cụ thể cho lớp con.

Tóm lại, bạn có thể sử dụng CRTP khi muốn có sự tương thích tại thời điểm biên dịch, triển khai tĩnh đa hình, tùy chỉnh hành vi và áp dụng các mẫu thiết kế trong C++. Tuy nhiên, hãy chắc chắn rằng CRTP là lựa chọn phù hợp cho vấn đề cụ thể mà bạn đang giải quyết, và hãy hiểu rõ các quy tắc và giới hạn của nó trước khi sử dụng.

## Why?
Curiously Recurring Template Pattern (CRTP) được sử dụng trong C++ vì nó cung cấp một số lợi ích và tính linh hoạt cho việc thiết kế và triển khai các lớp con. Dưới đây là một số lý do phổ biến để sử dụng CRTP:

Tối ưu hiệu suất: CRTP cho phép tối ưu hóa hiệu suất bằng cách thực hiện một phần của hành vi tại thời điểm biên dịch. Khi lớp con tham gia vào quá trình kế thừa thông qua lớp template, mã máy được tạo ra có thể hiệu quả hơn và tránh các trễ tại thời điểm chạy.

Đa hình tĩnh: CRTP cung cấp đa hình tĩnh (static polymorphism), cho phép lớp con triển khai các phương thức cụ thể của nó. Điều này giúp tăng tính linh hoạt và hiệu suất so với việc sử dụng đa hình động (dynamic polymorphism) thông qua các phương thức ảo.

Tùy chỉnh hành vi: CRTP cho phép lớp con kiểm soát hành vi của mình thông qua việc định nghĩa các phương thức cụ thể. Điều này giúp đảm bảo rằng các phương thức cụ thể được gọi trong lớp cơ sở được triển khai theo cách tùy chỉnh bởi lớp con.

Mẫu thiết kế: CRTP là một công cụ hữu ích để triển khai một số mẫu thiết kế trong C++. Ví dụ, nó có thể được sử dụng để triển khai mẫu CRTP Method để cung cấp các phương thức cụ thể cho lớp con hoặc để triển khai mẫu Static Polymorphism để có hiệu suất tốt hơn và mã máy gọn hơn.

Tuy nhiên, việc sử dụng CRTP cần được cân nhắc kỹ lưỡng và phải hiểu rõ các quy tắc và giới hạn của nó. Việc sử dụng CRTP có thể làm tăng độ phức tạp của mã và yêu cầu kiến thức vững vàng về ngôn ngữ C++. Do đó, cần xem xét cẩn thận trước khi sử dụng CRTP và đảm bảo rằng nó giải quyết vấn đề cụ thể của bạn một cách tốt nhất.
