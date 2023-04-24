#include <iostream>
typedef struct Row {
    int a;
    int b;
} Row;

/* !
 *
 * Return the index of the first element which is large than key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key which need to find the first element large than it
 *
 */
void task1(const Row* rows, int nrows) {
    for (int i = 0; i < nrows; ++i) {
        if ((rows[i].a == 1000 || rows[i].a == 2000 || rows[i].a == 300) &&
            (rows[i].b > 10 && rows[i].b < 50)) {
            std::cout << rows[i].a << "," << rows[i].b << std::endl;
        }
    }
}

/* !
 *
 * Return the index of the left most element equal to key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key
 * than it
 *
 */
int binary_search_leftmost(const Row* rows, int nrows, int key) {
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

/* !
 *
 * Return the index of the right most element equal to key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key
 *
 */
int binary_search_rightmost(const Row* rows, int nrows, int key) {
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

/* !
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
    return binary_search_rightmost(rows, nrows, key) + 1;
}

/* !
 *
 * Return the index of the last element less than key.
 *
 * @param rows      The pointer of first row
 * @param nrows     The total number of rows
 * @param key       The key
 *
 */
int last_less_than_key(const Row* rows, int nrows, int key) {
    return binary_search_leftmost(rows, nrows, key) - 1;
}

void task1_opt1(const Row* rows, int nrows) {
    int from = first_greater_than_key(rows, nrows, 5);
    int to = last_less_than_key(rows, nrows, 10);
    for (int i = from; i <= to; ++i) {
        if (rows[i].b == 1000 || rows[i].b == 2000 || rows[i].b == 300) {
            std::cout << rows[i].a << "," << rows[i].b << std::endl;
        }
    }
}

void task1_opt2(const Row* rows, int nrows) {
    for (int i = first_greater_than_key(rows, nrows, 5);
         i <= last_less_than_key(rows, nrows, 10); ++i) {

        // change a to b
        for (int j = binary_search_leftmost(rows, nrows, 1000);
             j <= binary_search_rightmost(rows, nrows, 1000); ++j) {
            std::cout << rows[j].a << "," << rows[j].b << std::endl;
        }

        for (int j = binary_search_leftmost(rows, nrows, 2000);
             j <= binary_search_rightmost(rows, nrows, 2000); ++j) {
            std::cout << rows[j].a << "," << rows[j].b << std::endl;
        }

        for (int j = binary_search_leftmost(rows, nrows, 3000);
             j <= binary_search_rightmost(rows, nrows, 3000); ++j) {
            std::cout << rows[j].a << "," << rows[j].b << std::endl;
        }
    }
}

void task1_opt_print(const Row* rows, int nrows) {}
