#include "cjstr.h"

int main()
{
    cjstr_t js_string = cjstr_create(L"Мама, привет!", 13);

    cjstr_destroy(js_string);

    return 0;
}