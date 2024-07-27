#include "cjstr.h"

int main()
{
    cjstr_t js_string = cjstr_create(L"Мама, привет!", 13);

    cjstr_t digit_js_string = cjstr_create(L"123", 3);

    printf("%d\n", cjstr_char_code_at(digit_js_string, 0));
    printf("%d\n", cjstr_char_code_at(digit_js_string, 1));
    printf("%d\n", cjstr_char_code_at(digit_js_string, 2));

    int16_t char_codes[] = {49, 50, 51};

    cjstr_t from_codes_js_string = cjstr_from_char_code(char_codes, sizeof(char_codes));

    printf("%d\n", cjstr_char_code_at(from_codes_js_string, 0));
    printf("%d\n", cjstr_char_code_at(from_codes_js_string, 1));
    printf("%d\n", cjstr_char_code_at(from_codes_js_string, 2));

    cjstr_destroy(js_string);
    cjstr_destroy(digit_js_string);
    cjstr_destroy(from_codes_js_string);

    cjstr_t mom = cjstr_create(L"Мама", 4);
    cjstr_t and = cjstr_create(L" и ", 3);
    cjstr_t dad = cjstr_create(L"Папа", 4);
    cjstr_t strs[] = {and, dad};

    cjstr_t mom_and_dad = cjstr_concat(mom, strs, 2);

    printf("%llu\n", cjstr_length(mom_and_dad));

    cjstr_destroy(mom);
    cjstr_destroy(and);
    cjstr_destroy(dad);
    cjstr_destroy(mom_and_dad);

    return 0;
}