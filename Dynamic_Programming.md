# Nhập môn Quy hoạch động

> ## QHĐ là gì ?
---

1. QHĐ là kĩ thuật được được dùng khi có một công thức và một (hoặc một vài) trạng thái bắt đầu. Một bài toán được tính bởi các bài toán nhỏ hơn đã tìm ra trước đó. QHĐ có độ phức tạp đa thức nên sẽ chạy nhanh hơn quay lui và duyệt trâu.

2. Quy hoạch động giúp giải quyết một cách hiệu quả một lớp vấn đề có các bài toán con chồng chéo và thuộc tính cấu trúc con tối ưu. Những bài toán như vậy liên quan đến việc tính toán nhiều lần giá trị của các bài toán con giống nhau để tìm ra giải pháp tối ưu.

- Các bài toán con chồng chéo: Bài toán con là các bài toán nhỏ hơn của bài toán ban đầu. Bất kỳ bài toán nào cũng có các bài toán con trùng nhau nếu việc tìm lời giải của nó liên quan đến việc giải cùng một bài toán con nhiều lần.
- Thuộc tính cấu trúc con tối ưu: Bất kỳ bài toán nào cũng có thuộc tính cấu trúc con tối ưu nếu giải pháp tối ưu tổng thể của nó có thể được xây dựng từ các giải pháp tối ưu của các bài toán con của nó.

3. Để hiểu rõ hơn hãy xem ví dụ sau:

> Cho N đồng xu và giá tiền của mỗi đồng (V0,V1,…,VN−1 ), và số S. Tìm số đồng xu nhỏ nhất để tổng giá trị của chúng bằng S (số lượng đồng xu không giới hạn).

-  *Đầu tiên, cần tìm một trạng thái của bài toán.*

> ## Trạng thái là gì ?
---

- Trạng thái là một trường hợp, một bài toán con của bài toán lớn.

- Ví dụ, trạng thái trong bài này là số lượng xu nhỏ nhất để tổng bằng i, với i≤S. Để tìm ra trạng thái i, cần phải tìm tất cả các trạng thái j mà (j<i). Một khi đã tìm ra trạng thái i, ta có thể dễ dàng tìm ra trạng thái của i+1.

> ## Quy hoạch động thường dùng một trong hai cách tiếp cận :
---

1. Top-down (Từ trên xuống): <br>
- Bài toán được chia thành các bài toán con, các bài toán con này được giải và lời giải được ghi nhớ để phòng trường hợp cần dùng lại chúng, và các bài toán con này tiếp tục gọi đến bài toán con của chúng đến khi đủ dữ kiện để lấy ra kết quả tính toán. <br>
- Đây là kỹ thuật đệ quy và lưu trữ được kết hợp với nhau, quy hoạch động giải quyết.

2. Bottom-up (Từ dưới lên): <br>
- Tất cả các bài toán con có thể cần đến đều được giải trước (từ bài toán cơ sở trở đi) , sau đó được dùng để xây dựng lời giải cho các bài toán lớn hơn. <br> 
- Điều này thường được thực hiện bằng cách điền vào một bảng với N chiều. Dựa trên kết quả trong bảng, giải pháp cho vấn đề ban đầu sẽ được tính toán. <br>
- ***Cách tiếp cận này tốt hơn về không gian bộ nhớ dùng cho ngăn xếp và số lời gọi hàm***. <br> 
- *Tuy nhiên, đôi khi việc xác định tất cả các bài toán con cần thiết cho việc giải quyết bài toán cho trước không được trực quan như Top-down*. (Dynamic programming)

## Vậy khi nào ta nên dùng QHĐ?

1. Quy hoạch động giúp giải quyết một cách hiệu quả một lớp vấn đề có các bài toán con chồng chéo và thuộc tính cấu trúc con tối ưu. Những bài toán như vậy liên quan đến việc tính toán nhiều lần giá trị của các bài toán con giống nhau để tìm ra giải pháp tối ưu.

- Các bài toán con chồng chéo: <br> 
    - Bài toán con là các   bài toán nhỏ hơn của bài toán ban đầu. Bất kỳ bài toán nào cũng có các bài toán con trùng nhau nếu việc tìm lời giải của nó liên quan đến việc giải cùng một bài toán con nhiều lần.
- Thuộc tính cấu trúc con tối ưu:<br> 
    - Bất kỳ bài toán nào cũng có thuộc tính cấu trúc con tối ưu nếu giải pháp tối ưu tổng thể của nó có thể được xây dựng từ các giải pháp tối ưu của các bài toán con của nó.

> ##  Phương pháp giải bài toán quy hoạch động :
---

1. Để giải quyết bài toán quy hoạch động ta chỉ cần xác định được hai vấn đề : <br>
- Thứ nhất là : Bài toán cơ sở.
- Thứ hai là : Công thức truy hồi.


2. Và để có được công thức truy hồi, ta phải xác định được bài toán với đủ dữ kiện để có thể xây dựng được công thức truy hồi đi đến bài toán lớn nhất. <br>
3. Do mỗi bài toán quy hoạch động đều có đặc thù riêng nên để hiểu rõ cách xác định bài toán và xây dựng bài toán cơ sở và công thức truy hồi, các bạn sẽ được xem ví dụ cụ thể cho một số bài toán quy hoạch động ở phần phía dưới

> Note: Giải một bài toán DP phụ thuộc rất nhiều vào cách bạn đặt tên cho mảng DP mà bạn dùng. (Mảng để lưu giá trị gì ?)

> ## Bài tập :

1. ### LIQ - Dãy con tăng dài nhất ( bản dễ )
---

```c++
    int main ()
    {
        int n;
        cin>>n;
        long arr[1003];
        long F[1003]; // F[i] là độ dài dãy tăng dài nhất kết thúc tại i;
        for (int i=1; i<=n; i++)
            cin>>arr[i];
        arr[0] = 0;
        F[0] = 0;
        for (int i=1; i<=n; i++)
        {
            F[i] = 1;

            // duyệt tìm dãy dài F[j] nhất sao cho a[j] < a[i];>

            for (int j=i-1; j>=1; j--)
            {
                if (arr[i]>arr[j])
                {
                    F[i]=max(F[i], F[j]+1);
                }
            }
        }
        
        // kết quả là F[i]_max;

        long dmax = 1;
        for (int i=1; i<=n; i++)
            if (F[i]>=dmax)
                dmax = F[i];
        cout<<dmax;
        return 0;
    } 
```

2. ### BCCAITUI - Cái Túi
---

```c++

/*
 Ý tưởng bài toán:
    - dp[i] : lưu giá trị lớn nhất có thể có khi mang i cân nặng;
    - Vì mỗi đồ vật chỉ được lấy một lần -> ta cần duyệt từ trên xuống theo giá trị của m để đảm bảo mỗi đồ vật thì các giá trị dp[i] đều được cặp nhập mà không bị lặp lại.
    VD : nếu duyệt từ a[i].fi -> m;
    với a[i] = 2;
    thì khi ta update giá trị dp[2];
    và sau đố ta update giá trị dp[4];
    thì đồ vật a[i] = 2 đã bị lặp lại 2 lần tại dp[2] và dp[4]; 
*/

void solve(){
    int n,m; cin >> n >> m;
    vector<pii> a(n);
    for (int i=0;i<n;i++) cin >> a[i].fi >> a[i].se;
    vector<int> dp(m+1,0);
    for (int i=0;i<n;i++){
        for (int j=m;j>=a[i].fi;j--){
            dp[j] = max(dp[j],dp[j-a[i].fi]+a[i].se);
        }
    }
    cout << dp[m];
}
```
