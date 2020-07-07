#include "util.h"

test(puts)
{
    int ret;

    ret = puts("");
    ok(ret, "got %d, expected zero\n", ret);

    ret = puts("Hello, world\n");
    ok(ret, "got %d, expected zero\n", ret);
}

int main(void)
{
    test_init();
    add_test(puts);
    test_end();
}
