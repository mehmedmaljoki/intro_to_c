#include <stdlib.h>

#include "vector.h"
#include "test-framework/unity.h"

static struct vector vec;

void setUp(void) {
    vec = vector_create(10);  // Initialize vec in setUp
}

void tearDown(void) {
    vector_destroy(&vec);
}
// #pragma FIXTURE_START
// #pragma FIXTURE_END
//
// #pragma TEST_START
// #pragma TEST_END


static void test_vector_create_works(void) {
    TEST_ASSERT_NOT_NULL(vec.con);
    TEST_ASSERT(vec.capacity == 10);
    TEST_ASSERT(vec.size == 0);
}

static void test_vector_destroy_works(void) {
    vector_destroy(&vec);
    TEST_ASSERT_NULL(vec.con);
}

static void test_vector_add_single_element(void) {
    vector_add(&vec, 42);
    TEST_ASSERT_EQUAL_INT(42, vec.con[0]);
    TEST_ASSERT_EQUAL(vector_get(&vec, 0), 42);
    TEST_ASSERT_EQUAL_INT(1, vec.size);
}

static void test_add_multiple_elements(void) {
    vector_add(&vec, 42);
    vector_add(&vec, 43);
    vector_add(&vec, 44);
    TEST_ASSERT_EQUAL_INT(42, vec.con[0]);
    TEST_ASSERT_EQUAL(vector_get(&vec, 0), 42);
    TEST_ASSERT_EQUAL_INT(43, vec.con[1]);
    TEST_ASSERT_EQUAL(vector_get(&vec, 1), 43);
    TEST_ASSERT_EQUAL_INT(44, vec.con[2]);
    TEST_ASSERT_EQUAL(vector_get(&vec, 2), 44);
    TEST_ASSERT_EQUAL_INT(3, vec.size);
}

static void test_vector_add_with_resize(void) {
    for (int i = 0; i < 11; i++) {
        vector_add(&vec, i);
    }
    TEST_ASSERT_EQUAL_INT(11, vec.size);
    TEST_ASSERT_EQUAL(10, vec.con[10]);
    TEST_ASSERT_EQUAL(vector_get(&vec, 10), 10);

}


int main() {
    UnityBegin("test_vector.c");

    RUN_TEST(test_vector_create_works);
    RUN_TEST(test_vector_destroy_works);
    RUN_TEST(test_vector_add_single_element);
    RUN_TEST(test_add_multiple_elements);
    RUN_TEST(test_vector_add_with_resize);

    return UnityEnd();
}

