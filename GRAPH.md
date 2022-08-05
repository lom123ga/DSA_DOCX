# Cấu trúc dữ liệu đồ thị (Graph)


## 1\. Khái niệm <br>
- *Cấu trúc dữ liệu đồ thị* là một tập hợp các nút có **dữ liệu** và **được kết nối** với các nút khác.<br>

 - Ta sẽ hiểu điều này thông qua một ví dụ. Trên một trang mạng xã hội A, mọi thứ đều là một nút. Bao gồm người dùng, ảnh, album, sự kiện, nhóm, trang, bình luận, câu chuyện, video… bất cứ thứ gì có dữ liệu là một nút. Mọi mối quan hệ là một cạnh từ nút này sang nút khác. Cho dù bạn đăng ảnh, tham gia nhóm, thích một trang,…, một cạnh mới sẽ được tạo ra cho mối quan hệ đó.

<img src="https://tek4.vn/public_files/00628c0e-b774-4e38-af5d-c077c6f4c88b">

Tất cả của mạng xã hội này sau đó là một tập hợp các nút và các cạnh. Điều này là do A sử dụng cấu trúc dữ liệu đồ thị để lưu trữ dữ liệu của nó.

Chính xác hơn, đồ thị là một cấu trúc dữ liệu (V, E) bao gồm:

- Tập hợp các đỉnh V.
- Tập hợp các cạnh E, được biểu diễn dưới dạng các cặp đỉnh có thứ tự (u, v).

<img src="https://tek4.vn/public_files/2dd17e0f-e455-44ca-b209-425b3ffb82d7">

Trong đồ thị trên, ta có:

- V = {0, 1, 2, 3}
- E = {(2,1), (2,0), (2,3), (1,0)}
- G = {V, E}

## 2\. Thuật ngữ trong cấu trúc dữ liệu đồ thị
- **Đỉnh kề**: Một đỉnh được cho là kề với một đỉnh khác nếu có một cạnh nối giữa chúng. Các đỉnh 0 và 3 không liền nhau vì không có cạnh giữa chúng.<br>

- **Đường dẫn**: Một dãy các cạnh cho phép ta đi từ đỉnh A đến đỉnh B được gọi là đường dẫn. 0-1, 1-2 và 0-2 là các đường đi từ đỉnh 0 đến đỉnh 2.<br>

- **Đơn đồ thị**: là đồ thị mà không có khuyên và không có cạnh song song.

- **Đa đồ thị là đồ**: thị mà không thỏa mãn đơn đồ thị.

- **Đa đồ thị có hướng**: là một đồ thị có hướng, trong đó, nếu x và y là hai đỉnh thì đồ thị được phép có cả hai cung (x, y) và (y, x).

- **Đơn đồ thị có hướng**: (hoặc Đa đồ thị có hướng) là một đồ thị có hướng, trong đó, nếu x và y là hai đỉnh thì đồ thị chỉ được phép có tối đa một trong hai cung (x, y) hoặc (y, x).<br>

- *Một khuyên* (loop) là một cạnh (vô hướng hoặc có hướng) nối từ một đỉnh về chính nó; Kiểu cạnh này có được chấp nhận hay không là tùy ở ứng dụng. Trong ngữ cảnh này, một cạnh nối hai đỉnh phân biệt được gọi là một liên kết. <br>

- Với một đinh u thuộc đồ thị, định nghĩa bậc (degree), ký hiệu deg(u) là số cạnh liên thuộc với u. <br>

- Trên đơn đồ thị, số cạnh liên thuộc với uu cũng chính là số đỉnh kề với uu. <br> 

## 3\. Biểu diễn đồ thị

*Đồ thị thường được biểu diễn theo hai cách:*

### <ul> 3.1. Ma trận liền kề hay ma trận kề : </ul>

<ul> Ma trận kề là một mảng 2 chiều gồm các đỉnh VxV. Mỗi hàng và cột đại diện cho một đỉnh. <br>
Nếu giá trị của bất kỳ phần tử nào a[i][j] là 1, nó biểu thị rằng có một cạnh nối đỉnh i và đỉnh j. <br>
Ma trận kề cho biểu đồ chúng ta đã tạo ở trên như sau.</ul>

<img src="https://tek4.vn/public_files/fbb4fe7a-d822-4170-ac61-8d401a80b388" > <br>

<ul>
Vì là đồ thị vô hướng nên đối với cạnh (0,2), chúng ta cũng cần đánh dấu cạnh (2,0), làm cho ma trận kề đối xứng qua đường chéo.

Việc tìm kiếm cạnh (kiểm tra xem có tồn tại cạnh nối giữa đỉnh A và đỉnh B hay không) cực kỳ nhanh chóng trong biểu diễn ma trận kề nhưng chúng ta phải dành không gian cho mọi liên kết có thể có giữa tất cả các đỉnh (VxV), vì vậy nó đòi hỏi nhiều không gian hơn.
</ul>

### <ul> 3.2. Danh sách kề </ul>
<ul>
Danh sách kề biểu thị một biểu đồ dưới dạng một mảng các danh sách được liên kết.

Chỉ số của mảng đại diện cho một đỉnh và mỗi phần tử trong danh sách liên kết của nó đại diện cho các đỉnh khác tạo thành một cạnh với đỉnh.

Danh sách kề cho biểu đồ mà chúng ta đã tạo trong ví dụ đầu tiên như sau:
</ul>

<img src = "https://tek4.vn/public_files/7d5843e5-6373-49d0-b011-26ac04559563"> <br>

<ul>
Danh sách kề có tính hiệu quả về mặt lưu trữ vì chúng ta chỉ cần lưu trữ các giá trị cho các cạnh. Đối với một biểu đồ có hàng triệu đỉnh, điều này có nghĩa là rất nhiều không gian được tiết kiệm.
</ul>

### 4\. Các thuật toán trên đồ thị : 

#### 1. Khái niệm :

 - Một **đường đi P** độ dài k từ đỉnh $v_0$ tới đỉnh $v_k$ là tập đỉnh { $v_0$, $v_1$, $v_2$,..., $v_k$} sao cho ( $v_{i−1}$ , $v_i$ )∈E,∀i:1≤i≤k. Khi đó ta nói đường đi này bao gồm các đỉnh \{ $v_0$, $v_1$, $v_2$,..., $v_k$\} và các cạnh \{( $v_0$, $v_1$), ( $v_1$, $v_2$), ..., ( $v_{k - 1}$, $v_k$)\}; và $v_0$ đến được $v_k$ thông qua đường đi P. <br>
 - Đường đi được gọi là **đường đi đơn giản (simple path)** nếu tất cả các đỉnh trên đường đi đó đều phân biệt. Đường đi được gọi là **đường đi đơn** nếu như không có cạnh nào trên đường đi đó đi qua hơn một lần. <br>
- Một **đường đi con (subpath)** P' của P là một đoạn liên tục các đỉnh và cạnh dọc theo đường đi P.<br>
- Đường đi P gọi là **chu trình (circuit)** nếu như $v_0$= $v_k$​. Chu trình P gọi là **chu trình đơn giản (simple circuit)* nếu như \{ $v_1$, $v_2$,..., $v_k$\} đôi một khác nhau. Chu trình mà trong đó không có cạnh nào đi qua hơn một lần được gọi là **chu trình đơn**. <br>

#### 2. Tìm kiếm theo chiều sâu (DFS) :

- Trong quá trình *DFS*, với mỗi đỉnh u ta có đỉnh ***par[u]*** là số hiệu của đỉnh mà từ đỉnh đó thủ tục DFS gọi đệ quy đến u. Xây dựng đồ thị con với các cạnh là (par[u],u) ta có được một cây. Cây này được gọi là **cây DFS**.

- Các cạnh thuộc cây DFS được gọi là các “*cạnh nét liền*”.

- Các cạnh còn lại không thuộc cây DFS được gọi là các “*cạnh nét đứt*".

<img src = "https://vnoi.info/wiki/uploads/Depth-First-Search-Tree_img1.png">

- Trong đồ thị có hướng, xét các cung được thăm và không được thăm bởi DFS, ta có 4 loại cung sau:

    - Cung của cây DFS (Tree edge): là các cung thuộc cây DFS được định hướng theo chiều từ cha đến con. (ví dụ cạnh (u,v) thuộc cây DFS mà u được thăm trước v hay u là cha của v thì ta có cung u→v là cung của cây DFS). < Các cung của cây DFS được đánh dấu là các cạnh màu đen trong hình bên dưới >
    - Cung xuôi (Forward edge): là các cung không thuộc cây DFS và có dạng u→v trong đó u là tổ tiên của v trong cây DFS. < Các cung xuôi được đánh dấu là các cạnh màu xanh lá trong hình bên dưới >
    - Cung ngược (Back edge): là các cung không thuộc cây DFS và có dạng v→u trong đó u là tổ tiên của v trong cây DFS. < Các cung ngược được đánh dấu là các cạnh màu đỏ trong hình bên dưới >
    - Cung chéo (Cross edge): là các cung không thuộc cây DFS có dạng u→v trong đó u và v thuộc hai nhánh khác nhau của cùng một cây DFS. < Các cung chéo được đánh dấu là các cạnh màu xanh dương trong hình bên dưới >

![](https://vnoi.info/wiki/uploads/Depth-First-Search-Tree_img2.png)

- Độ phức tạp của thuật toán 

    - Độ phức tạp về thời gian của thuật toán DFS được biểu diễn dưới dạng O(V+E), trong đó V là số nút và E là số cạnh.
    - Độ phức tạp về không gian của thuật toán là O(V).

- Cài đặt thuật toán :
    - Dùng stack :
    ```c++
            void DFS(int x){
                visited[x] = true;
                stack<int> st;
                st.push(x);
                while (st.size()){
                    int u = st.top();   // lấy đỉnh
                    st.pop();
                    visited[u] = true;
                    for (int v : a[u]){
                        if (!visited[v]){
                            st.push(v);
                            trace[v] = u; // từ đỉnh u đi đến được đỉnh v
                        }
                    }
                }
            }
    ```
    - Dùng đệ quy :
    ```c++
            void DFS(int x){
                // thăm đỉnh x
                visited[x] = true;
                for (int v : a[x]){
                    if (!visited[v]){
                        DFS[v];
                    }
                }
            }
    ```

#### 3. Tìm kiếm theo chiều rộng (BFS) :

- Thuật toán duyệt đồ thị ưu tiên chiều rộng (Breadth-first search - BFS) là một trong những thuật toán tìm kiếm cơ bản và thiết yếu trên đồ thị. Mà trong đó, những đỉnh nào gần đỉnh xuất phát hơn sẽ được duyệt trước.

- Ứng dụng của BFS có thể giúp ta giải quyết tốt một số bài toán trong thời gian và không gian tối thiểu. Đặc biệt là bài toán tìm kiếm đường đi ngắn nhất từ một đỉnh gốc tới tất cả các đỉnh khác. Trong đồ thị không có trọng số hoặc tất cả trọng số bằng nhau, thuật toán sẽ luôn trả ra đường đi ngắn nhất có thể. Ngoài ra, thuật toán này còn được dùng để tìm các thành phần liên thông của đồ thị, hoặc kiểm tra đồ thị hai phía, …

![](https://vnoi.info/wiki/uploads/breadth-first-search_img1.png)

##### Ý tưởng
--- <br>

- Với đồ thị không trọng số và đỉnh nguồn s. Đồ thị này có thể là đồ thị có hướng hoặc vô hướng, điều đó không quan trọng đối với thuật toán.

-   Có thể hiểu thuật toán như một ngọn lửa lan rộng trên đồ thị:

    - Ở bước thứ 0, chỉ có đỉnh nguồn s đang cháy.
    - Ở mỗi bước tiếp theo, ngọn lửa đang cháy ở mỗi đỉnh lại lan sang tất cả các đỉnh kề với nó.

- Trong mỗi lần lặp của thuật toán, "vòng lửa" lại lan rộng ra theo chiều rộng. Những đỉnh nào gần s hơn sẽ bùng cháy trước.

![](https://vnoi.info/wiki/uploads/breadth-first-search_img2.png)

#### Thuật toán loang : 

- **Thuật toán loang (thuật toán vết dầu loang)** là một kĩ thuật sử dụng BFS để tìm tất cả các điểm có thể đi tới. Điểm khác biệt giữa **Loang** so với đa số những bài **BFS** là ta không phải tìm chi phí nhỏ nhất.

- Gọi là thuật toán loang vì nguyên lí của thuật toán này rất giống với hiện tượng loang của chất lỏng. Khi ta nhỏ dầu xuống một mặt phẳng, vết dầu có thể loang ra những khu vực xung quanh. Tương tự, thuật toán loang trên ma trận cũng vậy, ta sẽ duyệt một ô trên ma trận và sau đó duyệt các điểm xung quanh nó và loang dần ra để giải quyết bài toán.

#### Cài đặt BFS bằng queue 
---
```c++
        int n; // Số lượng đỉnh của đồ thị
        int d[maxN], par[maxN];
        bool visit[maxN];
        vector <int> g[maxN];

        void bfs(int s) { // Với s là đỉnh xuất phát (đỉnh nguồn)
            fill_n(d, n + 1, 0);
            fill_n(par, n + 1, -1);
            fill_n(visit, n + 1, false);

            queue <int> q;
            q.push(s);
            visit[s] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto v : g[u]) {
                    if (!visit[v]) {
                        d[v]     = d[u] + 1;
                        par[v]   = u;
                        visit[v] = true;
                        q.push(v);
                    }
                }
            }
        }
```

#### Độ phức tạp thời gian

- độ phức tạp thời gian của thuật toán này là O(|V|+|E|) với **danh sách kề**.

- thuật toán sẽ mất độ phức tạp O( $|V|^2$ ) với **ma trận kề**.

### Tính liên thông của đồ thị 
---

- Đồ thị vô hướng được coi là liên thông nếu luôn tìm được đường đi giữa hai đỉnh bất 
kỳ của nó.

- Trong trường hợp đồ thị G không liên thông, ta có thể phân ra G thành một số đồ thị
con liên thông mà chúng đôi một không có đỉnh chung. Mỗi đồ thị con như vậy là một 
thành phần liên thông của G. Như vậy, đồ thị liên thông khi và chỉ khi số thành phần 
liên thông của nó là 1.

- Đối với đồ thị vô hướng, đường đi từ đỉnh u đến đỉnh v cũng giống như đỉnh đường đi từ đỉnh v đến đỉnh u. Chính vì vậy, nếu tồn tại u sao cho u có đường đi đến tất cả các đỉnh còn lại của đồ thị thì ta kết luận được đồ thị là liên thông.

- **Đỉnh khớp** (cut vertex/ articulation point): của một đồ thị vô hướng là đỉnh mà nếu xóa đỉnh này khỏi đồ thị và các cạnh nối đến nó thì số thành phần liên thông của đồ thị sẽ tăng thêm.

- **Cạnh cầu** (bridge): của một đồ thị vô hướng là cạnh mà nếu xóa đi khỏi đồ thị thì số thành phần liên thông của đồ thị sẽ tăng thêm. <br>
![](https://upload.wikimedia.org/wikipedia/commons/9/99/DTSongLThong1.png)

- **Liên thông mạnh (strongly connected)**: Đồ thị có hướng gọi là liên thông mạnh nếu có đường đi từ a tới b và từ b tới a với mọi cặp đỉnh a và b của đồ thị.

- **Liên thông yếu (weakly connected)**: Đồ thị có hướng gọi là liên thông yếu nếu có đường đi giữa 2 đỉnh bất kỳ của đồ thị vô hướng tương ứng với đồ thị đã cho. Tức là hủy bỏ các hướng của các cạnh trong đồ thị.<br>
![](https://upload.wikimedia.org/wikipedia/commons/0/0e/DTLThongCH1.png)

#### Đếm thành phần liên thông bằng BFS

- Trong phép duyệt đồ thị, số thành phần liên thông của nó bằng số lần gọi tới thủ tục BFS.

![](https://vnoi.info/wiki/uploads/breadth-first-search_gif2.gif)

```c++
            const int maxN  = 1e5 + 7;

            int n, m, components = 0;
            bool visit[maxN];
            vector <int> g[maxN];

            void bfs(int s) {
                ++components;
                queue <int> q;
                q.push(s);
                visit[s] = true;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (auto v : g[u]) {
                        if (!visit[v]) {
                            visit[v] = true;
                            q.push(v);
                        }
                    }
                }
            }

            int main() {
                cin >> n >> m;
                while (m--) {
                    int u, v;
                    cin >> u >> v;
                    g[u].push_back(v);
                    g[v].push_back(u);
                }

                fill_n(visit, n + 1, false);
                for (int i = 1; i <= n; ++i)
                    if (!visit[i]) bfs(i);
                cout << components;
            }
```


###  BÀI TẬP CF :

> H\. [ProPTIT-Algorithm-Graph] DFS trên đồ thị vô hướng

```c++
        int visited[1005];
        vector<int> a[1005];
        
        
        void DFS(int u){
            cout << u << " ";
            visited[u] = 1;
            for (int v : a[u]){
                if (!visited[v]){
                    DFS(v);
                }
            }
        }
        
        
        void solve(){
            int V,E,st;
            cin >> V >> E >> st;
            for (int i=0;i<1005;i++) a[i].clear();
            memset(visited,0,sizeof(visited));
            for (int i=0;i<E;i++){
                int u,v;
                cin >> u >> v;
                a[u].push_back(v);
                a[v].push_back(u);
            }
            for (int i=1;i<=V;i++){
                if (a[i].size()) sort(all(a[i]));
            }
            DFS(st);
            cout << endl;
        }
```

> I\. [ProPTIT-Algorithm-Graph] BFS trên đồ thị có hướng

```c++
            int visited[1005];
            vector<int> a[1005];
            
            
            void BFS(int x){
                queue<int> q;
                q.push(x);
                visited[x] = 1;
                while (q.size()){
                    int u = q.front();
                    q.pop();
                    cout << u << " ";
                    for (int v : a[u]){
                        if (!visited[v]) {
                            q.push(v);
                            visited[v] = 1;
                        }
                    }
                }
            }
            
            
            void solve(){
                int V,E,st;
                cin >> V >> E >> st;
                for (int i=0;i<1005;i++) a[i].clear();
                memset(visited,0,sizeof(visited));
                for (int i=0;i<E;i++){
                    int u,v;
                    cin >> u >> v;
                    a[u].push_back(v);
                }
                for (int i=1;i<=V;i++){
                    if (a[i].size()) sort(all(a[i]));
                }
                BFS(st);
                cout << endl;
            }
```
