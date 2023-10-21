#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* linear_search_product(char** product_list, int size, char* target_product, int* result_size) {
    int* indices = NULL;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (strcmp(product_list[i], target_product) == 0) {
            ++count;
            indices = realloc(indices, count * sizeof(int));
            if (indices == NULL) {
                fprintf(stderr, "Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
            indices[count - 1] = i;
        }
    }

    *result_size = count;
    return indices;
}

int main() {
    char* products[] = {"apple", "banana", "orange", "banana", "apple", "kiwi", "banana"};
    int size = sizeof(products) / sizeof(products[0]);
    char* target_product = "banana";
    int result_size;
    int* result = linear_search_product(products, size, target_product, &result_size);

    if (result_size > 0) {
        printf("The product '%s' is found at indices: ", target_product);
        for (int i = 0; i < result_size; ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    } else {
        printf("The product '%s' is not found in the list.\n", target_product);
    }

    return 0;
}
