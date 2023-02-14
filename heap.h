/*
 * store pointer of Node in Heap
 * -------------------------------------------------
 * Interface    Fuction
 * -------------------------------------------------
 * push()         push Node*
 * pop()          pop top of Heap
 * modify()       modify item in the middle of Heap
 * erase()        erase item in the middle of Heap
 * clear()        reset Heap
 * top()          catch top of Heap
 * empty()        juege if Heap is empty
 * size()         get size of Heap
 * -------------------------------------------------
 */
#define HEAP_SIZE 20000

struct Node {
    int priority = 0;
    int idx_heap = 0;
    /* another way is use hash_map to map node_idx to heap_array_idx */
};

class Heap {
   private:
    Node* arr[HEAP_SIZE] = {nullptr};
    int sz = 0;

    void heapifyUp(int pos) {
        while (pos > 0 && compare((pos - 1) >> 1, pos)) {
            exchange((pos - 1) >> 1, pos);
            pos = (pos - 1) >> 1;
        }
    }
    void heapifyDown(int pos) {
        while (pos < sz) {
            int Lc = (pos << 1) + 1, Rc = (pos << 1) + 2;
            int idx = pos;
            if (Lc < sz && compare(idx, Lc)) {
                idx = Lc;
            }
            if (Rc < sz && compare(idx, Rc)) {
                idx = Rc;
            }
            if (idx != pos) {
                exchange(pos, idx);
                pos = idx;
            } else {
                break;
            }
        }
    }
    void exchange(int parent, int child) {
        // exchange content but keep idx
        Node* tmp = arr[parent];
        int pidx = arr[parent]->idx_heap, cidx = arr[child]->idx_heap;

        arr[parent] = arr[child];
        arr[child] = tmp;

        arr[parent]->idx_heap = pidx;
        arr[child]->idx_heap = cidx;
    }
    bool compare(int parent, int child) const {
        return arr[parent]->priority > arr[child]->priority;
    }

   public:
    void push(Node* val) {
        val->idx_heap = sz;
        arr[sz] = val;
        heapifyUp(sz);
        ++sz;
    }
    void pop() {
        exchange(0, sz - 1);
        --sz;
        heapifyDown(0);
    }
    void modify(int pos) {
        heapifyUp(pos);
        heapifyDown(pos);
    }
    void erase(int pos) {
        exchange(pos, sz - 1);
        --sz;
        heapifyUp(pos);
        heapifyDown(pos);
    }
    void clear() { sz = 0; }

    Node* top() const { return arr[0]; }
    bool empty() const { return sz == 0; }
    bool size() const { return sz; }
};
