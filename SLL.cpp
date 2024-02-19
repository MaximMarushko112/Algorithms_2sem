#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "SLL.h"

SLL Create_SLL() {
    SLL list = (SLL) calloc(ELEM_NUM, sizeof(Elem_of_SLL));

    assert(list != NULL);

    return list;
}

SLL SLL_New_Elem(SLL list) {
    assert(list != NULL);

    SLL new_elem = (SLL) calloc(ELEM_NUM, sizeof(Elem_of_SLL));
    assert(new_elem != NULL);

    new_elem->next = list;

    return new_elem;
}

SLL SLL_Delete_Last(SLL list) {
    assert(list != NULL);

    SLL temp = list->next;
    free(list);
    return temp;
}

void Clear_SLL(SLL list) {
    assert(list != NULL);

    SLL temp = NULL;

    while (list != NULL) {
        temp = list->next;
        free(list);
        list = temp;
    }
}
