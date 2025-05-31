/* Bai 4.1 Đảo ngược một danh sách liên kết đơn
Hãy hoàn thiện các hàm thao tác trên một danh sách liên kết:
Thêm một phần tử vào đầu danh sách liên kết.
In danh sách
Đảo ngược danh sách liên kết 
(yêu cầu độ phức tạp thời gian O(N) và chi phí bộ nhớ dùng thêm O(1))
Ho Minh Dung - 20235050 - 750829 - Tuan 38*/
#include <iostream> 
using namespace std;
struct Node { 
	int data; 
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

// push a new element to the beginning of the list
Node* prepend(Node* head_50, int data_50) {
	/*****************
	# YOUR CODE HERE #
	*****************/
	Node *newNode_50 = new Node(data_50);
	newNode_50->next = head_50;
	head_50 = newNode_50;
	return head_50;
}

// print the list content on a line
void print(Node* head_50) {
	/*****************
	# YOUR CODE HERE #
	*****************/
	while (head_50 != NULL){
		cout << head_50->data << " ";
		head_50 = head_50->next;
	}
	cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head_50) {
	/*****************
	# YOUR CODE HERE #
	*****************/
	if (head_50->next == NULL) return head_50;
	Node *cur_50 = head_50->next;
	Node *prev_50 = head_50;
	head_50->next = NULL;
	while (cur_50->next != NULL){
		Node *tmp_50 = cur_50->next;
		cur_50->next = prev_50;
		prev_50 = cur_50;
		cur_50 = tmp_50;
	}
	cur_50->next = prev_50;
	return cur_50;
}

/*Ho Minh Dung - 20235050 - 750829 - Tuan 38*/
int main() {
	cout << "Ho Minh Dung - 5050\n";
	int n_50, u_50;
	cin >> n_50;
	Node* head_50 = NULL;
	for (int i_50 = 0; i_50 < n_50; ++i_50){
		cin >> u_50;
		head_50 = prepend(head_50, u_50);
	} 
	
	cout << "Original list: ";
	print(head_50);

	head_50 = reverse(head_50);
	
	cout << "Reversed list: ";
	print(head_50);

	return 0; 
}