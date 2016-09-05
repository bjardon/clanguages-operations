
#include "language.h"


void dummy(Lang * lang) {
    int i;
    string helper;

    str(&helper);

    for (i = 65; i <= 90; ++i) {
        sprintf(helper, "%c%c", i, i);
        lang_add(lang, helper);
    }
}

int main(int argc, const char * argv[]) {
    Lang * sigma;
    sigma = (Lang *)malloc(sizeof(Lang));
    dummy(sigma);
    lang_print(sigma);
    lang_add(sigma, "AA");
    lang_add(sigma, "Ab");
    lang_print(sigma);

}