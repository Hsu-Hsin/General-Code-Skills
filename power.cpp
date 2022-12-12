#include <iostream>

/*
 * figure out x ^ y
 * 0 <= x <= 9, 0 <= y <= 99
 * use linked list to simulate
*/

struct Node {
	int val;
	Node* pre;
	Node* next;
	Node() : val(0), pre(nullptr) ,next(nullptr) {}
	Node(int x) : val(x) , pre(nullptr), next(nullptr) {}
	Node(int x, Node* pre, Node* next) : val(x), pre(pre), next(next) {}
};

Node* mypower(int x, int y) {
	if (x == 0) {
		Node* node = new Node(0);
		return node;
	}
	else if (y == 0) {
		Node* node = new Node(1);
		return node;
	}
	else {
		Node* tial = new Node(x);
		Node* head = tial;
		for (int i = 1; i < y; ++i) {
			Node* cur = tial;
			int carry = 0;

			while (cur) {
				int tmp = cur->val * x;

				cur->val = (tmp < 10) ? (tmp + carry) % 10 : (tmp % 10 + carry) % 10;
				carry = tmp / 10 + (carry + tmp % 10) / 10;

				cur = cur->pre;
			}
			
			if (carry) {
				Node* node = new Node(carry);
				node->next = head;
				node->pre = nullptr;
				head->pre = node;
				head = node;	/*?????????????*/
			}
		}
		return head;
	}

	return nullptr;
}

int main() {
	int x = 9, y = 99;
	std::cout << pow(x, y) << std::endl;
	Node* p = mypower(x, y);
	while (p) {
		std::cout << p->val;
		p = p->next;
	}
	std::cout << std::endl;

	return 0;
}
