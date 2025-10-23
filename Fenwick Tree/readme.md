Ủng hộ GSPVH tại: https://wescan.vn/GSPVHCUTE (hướng dẫn: Cả nhà ơi mua trà sữa ủng hộ GSPVH nè)
Bài toán gốc
Cho một dãy số a[1] a[2] ... a[n], ta cần thực hiện hai thao tác sau:
update(x, v): a[x] += v (tăng a[x] thêm v đơn vị)
get(x): tính a[1] + a[2] + ... + a[x] (tổng x số đầu tiên)
Cách giải bằng BIT
int bit[MAX], n; // mảng bit độ dài n

void update(int x, int v) {
	for (; x <= n; x += x & -x) bit[x] += v;
}
int get(int x) {
	int res = 0;
	for (; x >= 1; x &= x - 1) res += bit[x];
	return res;
}

get(x) trả về tổng giá trị v trong các lần gọi hàm update với vị trí <= x
Sau khi gọi hàm update(x, v); giá trị trả về của các gọi hàm get(x), get(x + 1), get(x + 2), ..., get(n) tăng thêm v đơn vị.

Demo Fenwick Tree: https://ideone.com/KSJ6v8

Giải thích bẩn chát của BIT
BIT là một cấu trúc có dạng cây, gồm n nút. Các nút được đánh số từ 1 đến n. Nút thứ i có cha là nút i + (i & -i)

i & -i kết quả trả về luôn là luỹ thừa của 2, cụ thể, i & -i = luỹ thừa của 2 lớn nhất mà là ước số của i
i & -i = 2^k lớn nhất sao cho i chia hết cho 2^k

Ví dụ, với mọi i lẻ, i chia hết cho 2^0 nhưng không chia hết cho 2^1 -> i & -i = 1 với mọi i lẻ

i = 24, i chia hết cho 2^3 nhưng không chia hết cho 2^4 -> i & -i = 8
i = 16, i chia hết cho 2^4 nhưng không chia hết cho 2^5 -> i & -i = 16

2^k lớn nhất để i chia hết cho 2^k chính là số bit 0 ngoài cùng bên phải trong biểu diễn nhị phân của số i



Vòng for trong hàm update:
	for (; x <= n; x += x & -x): Lệnh gán x <- x + (x & -x) (chính là đỉnh cha của đỉnh x)
	Do đó, vòng for này có ý nghĩa: lần lượt di chuyển từ nút hiện tại lên cha của nó 
Từ đây, ta thấy rằng, bản chất vòng for trong hàm update(x, v) chính là: xét lần lượt các nút: x -> cha của x -> ông nội của x -> cụ nội của x -> kị nội của x -> ... Mỗi nút là tổ tiên của x sẽ được tăng thêm v đơn vị,

Do trong hàm update(x, v); ta tăng thêm v ở tất cả các nút x và tổ tiên của x; nên giá trị bit[x] bản chất là tổng giá trị của các nút trong cây con gốc x

Nói cách khác, bit[x] là tổng giá trị v của các lần gọi hàm update mà vị trí update nằm trong cây con gốc x.

Ví dụ: cây con gốc 8 gồm các nút 1 2 3 4 5 6 7 8
-> bit[8] là tổng giá trị v của các lần update ở các vị trí 1 2 3 4 5 6 7 8

cây con gốc 28 gồm các nút 25 26 27 28
-> bit[28] = tổng các lần update vào các vị trí 25 26 27 28

Tiếp theo, ta tìm hiểu bên trong cây con gốc x có gì?
Với x lẻ, nút x là nút lá, cây con gốc x chỉ có đúng nút x
Với x có 1 bit 0 ở ngoài cùng bên phải (chia hết cho 2 nhưng không chia hết cho 4): 
	Cây con gốc x có hai nút là x và x - 1
Với x có 2 bit 0 ở ngoài cùng bên phải (chia hết cho 4 nhưng không chia hết cho 8):
	Cây con gốc x có bốn nút là x - 3 -> x

Quy luật chung:
	Nếu x có k bit 0 ở ngoài cùng bên phải trong biểu diễn nhị phân (nói cách khác, x chia hết cho 2^k nhưng không chia hết cho 2^(k + 1)):
		Cây con gốc gồm 2^k nút là các nút có chỉ số từ x - 2^k + 1 -> x
		Mọi cây con gốc x đều có các nút là các số nguyên liên tiếp với số lớn nhất là x

Cây con gốc 12 gồm 4 nút 9 -> 12 với biểu diễn nhị phân
	 9 = 01001
	10 = 01010
	11 = 01011
	12 = 01100

Cây con gốc 8 gồm 8 nút 1 -> 8 với biểu diễn nhị phân
	1 = 00001
	2 = 00010
	3 = 00011
	4 = 00100
	5 = 00101
	6 = 00110
	7 = 00111
	8 = 01000

Cây con gốc 20 gồm 4 nút 17 -> 20 với biểu diễn nhị phân
	17 = 10001
	18 = 10010
	19 = 10011
	20 = 10100

Hàm get có lệnh x &= x - 1
x &= x - 1 là xoá đi bit 1 phải nhất trong biểu diễn nhị phân của x (chuyển bit 1 phải nhất thành 0) và giữ nguyên các bit còn lại
         x  = 10101001
     x - 1  = 10101000
x & (x - 1) = 10101000

         x  = 1011000
     x - 1  = 1010111
x & (x - 1) = 1010000

Ví dụ: get(22) 22 biểu diễn nhị phân x = 10110

x = 10110 = 22 -> res += bit[22] (cây con gốc 22 gồm 21 -> 22)    10101 -> 10110
x = 10100 = 20 -> res += bit[20] (cây con gốc 20 gồm 17 -> 20)    10001 -> 10100
x = 10000 = 16 -> res += bit[16] (cây con gốc 16 gồm  1 -> 16)    00001 -> 10000  
x = 0 -> kết thúc
Kết luận, res = bit[22] + bit[20] + bit[16] = (21 -> 22) + (17 -> 20) + (1 -> 16) đẩy đủ đoạn 1 -> 22

get(9): 9 biểu diễn nhị phân 9 = 01001
x = 01001 = 9 -> res += bit[9] (cây con gốc 9 gồm      9)       01001 -> 01001
x = 01000 = 8 -> res += bit[8] (cây con gốc 8 gồm 1 -> 8)       00001 -> 01000
x = 0 -> kết thúc
Kết luận, res = bit[9] + bit[8] = (9 -> 9) + (1 -> 8)

get(29): 29 = 11101
x = 11101 = 29 -> res += bit[29] (29 -> 29)
x = 11100 = 28 -> res += bit[28] (25 -> 28)
x = 11000 = 24 -> res += bit[24] (17 -> 24)
x = 10000 = 16 -> res += bit[16] ( 1 -> 16)

Độ phức tạp
Cả hai hàm update và get đều có độ phức tạp là O(log(n)). Cụ thể hơn:
	hàm update số lần chạy nhỏ hơn log(n)
	hàm get, sau mỗi lần gán x &= x - 1, số bit 1 của x giảm 1 -> số lần chạy của hàm get là số bit 1 trong biểu diễn nhị phân của x

hằng số của BIT nhỏ hơn tất cả các CTDL khác (segment tree)
	cả hàm update và get của BIT đều có hằng số nhỏ hơn 1 (~ 1 / 2)
	segment tree walk (thao tác trên 1 phần tử): log(n) hằng số = 1
	segment tree đệ quy truy vấn trên đoạn / lazy update: số nút đi qua = 2 * log(n), chi phí rất lớn cho đệ quy


