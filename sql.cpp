#include <bits/stdc++.h>
using namespace std;

typedef struct Row {
    int a;
    int b;
} Row;

struct cmp {
    bool operator()(const Row* lhs, const Row* rhs) { return lhs->b > rhs->b; }
};

////////////////////////////////////////////////////////////////////////////////////////

/*!
 * Task 1.
 *
 * Find out all the rows that sastify below conditions:
 *
 * ((b >= 10 && b < 50) &&
 * (a == 1000 || a == 2000 || a == 3000))
 *
 * Print them to the terminal, one row per line, for example:
 *
 * 1000,20
 * 1000,23
 * 2000,16
 *
 * @param nrows     The total number of rows.
 * @param rows      The rows, for example rows[0] is the first row.
 */
void task1(const Row* rows, int nrows) {
    for (int i = 0; i < nrows; ++i) {
        if ((rows[i].a == 1000 || rows[i].a == 2000 || rows[i].a == 300) &&
            (rows[i].b > 10 && rows[i].b < 50)) {
            printf("%d,%d\n", rows[i].a, rows[i].b);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////

/*!
 *
 * Return the index of the left most element equal to key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key
 */
int binary_search_leftmost_by_a(const Row* rows, int nrows, int key) {
    int left = 0, right = nrows;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (rows[middle].a < key) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int binary_search_leftmost_by_b(const Row* rows, int nrows, int key) {
    int left = 0, right = nrows;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (rows[middle].b < key) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

/*!
 *
 * Return the index of the right most element equal to key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key
 *
 */
int binary_search_rightmost_by_a(const Row* rows, int nrows, int key) {
    int left = 0, right = nrows;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (rows[middle].a > key) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return right - 1;
}

int binary_search_rightmost_by_b(const Row* rows, int nrows, int key) {
    int left = 0, right = nrows;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (rows[middle].b > key) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return right - 1;
}

/*!
 *
 * Return the index of the first element greater than key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key
 * than it
 *
 */
int first_greater_than_key(const Row* rows, int nrows, int key) {
    return binary_search_rightmost_by_a(rows, nrows, key) + 1;
}

/*!
 *
 * Return the index of the last element less than key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key
 *
 */
int last_less_than_key(const Row* rows, int nrows, int key) {
    return binary_search_leftmost_by_a(rows, nrows, key) - 1;
}

/*!
 * Task 2.
 *
 * optimization of Task1 with the condition that
 * rows have been sorted by (a, b)
 *
 * Sample Input:
 * Row sorted_rows[] =
 * {
 * { 1000, 31 },
 * { 1000, 72 },
 * { 1500, 12 },
 * { 1500, 34 },
 * { 2000, 22 },
 * { 2000, 33 },
 * };
 *
 *
 * Sample Output:
 *
 * 1000,31
 * 2000,22
 * 2000,33
 *
 * @param nrows     The total number of rows.
 * @param rows      The rows, for example rows[0] is the first row.
 */
void task2(const Row* rows, int nrows) {
    int from = first_greater_than_key(rows, nrows, 5);
    int to = last_less_than_key(rows, nrows, 10);
    for (int i = from; i <= to; ++i) {
        if (rows[i].b == 1000 || rows[i].b == 2000 || rows[i].b == 300) {
            printf("%d,%d\n", rows[i].a, rows[i].b);
        }
    }
}

void task2_opt(const Row* rows, int nrows) {
    for (int i = first_greater_than_key(rows, nrows, 5);
         i <= last_less_than_key(rows, nrows, 10); ++i) {
        for (int j = binary_search_leftmost_by_b(rows, nrows, 1000);
             j <= binary_search_rightmost_by_b(rows, nrows, 1000); ++j) {
            printf("%d,%d\n", rows[j].a, rows[j].b);
        }

        for (int j = binary_search_leftmost_by_b(rows, nrows, 2000);
             j <= binary_search_rightmost_by_b(rows, nrows, 2000); ++j) {
            printf("%d,%d\n", rows[j].a, rows[j].b);
        }

        for (int j = binary_search_leftmost_by_b(rows, nrows, 3000);
             j <= binary_search_rightmost_by_b(rows, nrows, 3000); ++j) {
            printf("%d,%d\n", rows[j].a, rows[j].b);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////

/*!
 * Task 3.
 *
 * On the top of Task2, print the results sorted by b
 *
 *
 * Sample Ouput:
 *
 * 2000,22
 * 1000,31
 * 2000,33
 *
 * @param nrows     The total number of rows.
 * @param rows      The rows, for example rows[0] is the first row.
 */
void task3(const Row* rows, int nrows) {
    priority_queue<const Row*, vector<const Row*>, cmp> heap;

    for (int i = first_greater_than_key(rows, nrows, 5);
         i <= last_less_than_key(rows, nrows, 10); ++i) {
        for (int j = binary_search_leftmost_by_b(rows, nrows, 1000);
             j <= binary_search_rightmost_by_b(rows, nrows, 1000); ++j) {
            heap.push(&rows[j]);
        }

        for (int j = binary_search_leftmost_by_b(rows, nrows, 2000);
             j <= binary_search_rightmost_by_b(rows, nrows, 2000); ++j) {
            heap.push(&rows[j]);
        }

        for (int j = binary_search_leftmost_by_b(rows, nrows, 3000);
             j <= binary_search_rightmost_by_b(rows, nrows, 3000); ++j) {
            heap.push(&rows[j]);
        }
    }

    while(!heap.empty()) {
        printf("%d,%d\n", heap.top()->a, heap.top()->b);
        heap.pop();
    }
}
