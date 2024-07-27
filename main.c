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

    return 0;
}