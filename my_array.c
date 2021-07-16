#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct array {
    int *pBase;
    int len;  //最大长度
    int cnt;  //现在的个数
};

void init_arr(struct array *array, int len);

bool append_arr(struct array *array, int data);

bool insert_arr(struct array *array, int index, int data);

bool delete_arr(struct array *array, int index, int *delete_data);

int get(struct array *array, int index);

bool is_empty();

bool is_full();

void sort_arr();

void show_arr();

void inversion_arr();


int main(void) {
    struct array my_array;
    init_arr(&my_array, 6);
    append_arr(&my_array, 1);
    append_arr(&my_array, 2222);
    append_arr(&my_array, 3);
    append_arr(&my_array, 5);
    append_arr(&my_array, 4);
    append_arr(&my_array, -12);
    sort_arr(&my_array);
    inversion_arr(&my_array);
    show_arr(my_array);
    return 0;
}

bool insert_arr(struct array *array, int index, int data) {
    if (is_full(array)) {
        return false;
    } else {
        for (int i = array->cnt - 1; i >= index - 1; --i) {
            array->pBase[i + 1] = array->pBase[i];
        }
        array->pBase[index - 1] = data;
        return true;
    }
}


void init_arr(struct array *array, int len) {
    //those code modify the direction of the pointer
    (*array).pBase = (int *) malloc(sizeof(int) * len);
    if (NULL == array->pBase) {
        printf("sorry,There was an error in memory allocation ,please make sure your computer have enough memory  ");
    } else {
        array->cnt = 0;
        array->len = len;
    }
}

bool is_full(struct array *array) {
    if (array->cnt == array->len) {
        return true;
    } else {
        return false;
    }
}

bool append_arr(struct array *array, int data) {
    if (is_full(array)) {
        return false;
    }
    array->pBase[array->cnt] = data;
    array->cnt++;
    return true;
}

bool is_empty(struct array *array) {
    if (array->cnt == 0) {
        return true;
    } else {
        return false;
    }
}

void show_arr(struct array *array) {
    if (is_empty(array)) {
        printf("array is null");
        printf("\n");
    }
    for (int i = 0; i < array->cnt; ++i) {
        printf("%d", array->pBase[i]);
        printf("\n");
    }
}


bool delete_arr(struct array *array, int index, int *delete_data) {
    *delete_data = array->pBase[index - 1];
    for (int i = index; i < array->cnt; ++i) {
        array->pBase[i - 1] = array->pBase[i];
    }
    array->cnt--;
    return true;
}

int get(struct array *array, int index) {
    return array->pBase[index - 1];
}

void sort_arr(struct array *array) {
    int temp;
    for (int i = 0; i < array->len - 1; ++i) {
        for (int j = 0; j < array->len - 1 - i; ++j) {
            if (array->pBase[j] > array->pBase[j + 1]) {
                temp = array->pBase[j];
                array->pBase[j] = array->pBase[j + 1];
                array->pBase[j + 1] = temp;
            }
        }
    }
}

void inversion_arr(struct array *array) {
    int i = 0;
    int j = array->len-1;
    int temp;
    while (i < j) {
        temp = array->pBase[i];
        array->pBase[i] = array->pBase[j];
        array->pBase[j] = temp;
        ++i;
        --j;
    }

}