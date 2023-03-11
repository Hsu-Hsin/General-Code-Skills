#include <vector>
#include <tuple>

struct Item {
	int a = 0;
	int b = 0;
	size_t idx_in_heap = 0;
};

struct cmp {
	bool operator()(const Item* lhs, const Item* rhs) {
		return (std::tie(lhs->a, rhs->b) < std::tie(rhs->a, rhs->b));
	}
};

template<class Type, class Compare = std::less<Type>>
class Heap {
public:
	size_t push(const Type& val) {
		vec.push_back(val);
		return heapifyUp(vec.size() - 1);
	}

	void pop() {
		if (vec.empty()) return;

		swap(0, vec.size() - 1);
		vec.pop_back();
		heapifyDown(0);
	}

	Type top() const { return vec[0]; }
	bool empty() const { return vec.empty(); }
	size_t size() const { return vec.size(); }

	void modify(const size_t pos, const Type& val) {
		if (!(pos > 0) || !(pos < vec.size())) return;

		vec[pos] = val;
		heapifyUp(pos);
		heapifyDown(pos);
	}

	void erase(const size_t pos) {
		if (!(pos > 0) || !(pos < vec.size())) return;

		swap(pos, vec.size() - 1);
		vec.pop_back();
		heapifyDown(pos);
	}
private:
	std::vector<Type> vec;

	size_t heapifyUp(size_t pos) {
		Compare cmp;
		for (; pos > 0 && cmp(vec[(pos - 1) >> 1], vec[pos]); pos = (pos - 1) >> 1) {
			swap((pos - 1) >> 1, pos);
		}
		return pos;
	}

	size_t heapifyDown(size_t pos) {
		Compare cmp;
		size_t sz = vec.size();

		for (size_t idx = pos; pos < sz; pos = idx) {
			size_t Lidx = (pos << 1) + 1, Ridx = (pos << 1) + 2;

			if (Lidx < sz && cmp(vec[idx], vec[Lidx])) {
				idx = Lidx;
			}

			if (Ridx < sz && cmp(vec[idx], vec[Ridx])) {
				idx = Ridx;
			}

			if (idx != pos) {
				swap(pos, idx);
			}
			else {
				break;
			}
		}

		return pos;
	}

	void swap(const size_t lhs, const size_t rhs) {
		Type tmp = vec[lhs];
		vec[lhs] = vec[rhs];
		vec[rhs] = vec[lhs];
	}
};

int main() {
	Heap<Item*, cmp> heap;
	return 0;
}
