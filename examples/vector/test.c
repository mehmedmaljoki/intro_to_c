#include "test.h"
#include "vector.h"

#pragma FIXTURE_START

FIXTURE(Vector_fixture) {
    struct vector vec;
};

FIXTURE_SETUP(Vector_fixture) {
    T_ vec = vector_create(10, sizeof(short));
}

FIXTURE_TEARDOWN(Vector_fixture) {
    vector_destroy(&T_ vec);
}

#pragma FIXTURE_END

#pragma TEST_START

TEST(vector_create_works, Vector_fixture) {
    ASSERT_NON_NULL(T_ vec.con);
    ASSERT_EQ(T_ vec.capacity, 10, "%zu");
    ASSERT_EQ(T_ vec.size, 0, "%zu");
}

TEST(vector_destroy_deallocates, Vector_fixture) {
    vector_destroy(&T_ vec);
    ASSERT_NULL(T_ vec.con);
}

TEST(vector_add_single_element, Vector_fixture) {
    short value = 4;
    vector_add(&T_ vec, &value);
    ASSERT_EQ(T_ vec.size, 1, "%zu");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 0)), 4, "%d");
}

TEST(vector_add_multiple_elements, Vector_fixture) {
    short a = 4, b = 3, c = 7;
    vector_add(&T_ vec, &a);
    vector_add(&T_ vec, &b);
    vector_add(&T_ vec, &c);
    ASSERT_EQ(T_ vec.size, 3, "%zu");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 0)), 4, "%d");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 1)), 3, "%d");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 2)), 7, "%d");
}

TEST(vector_add_with_resize, Vector_fixture) {
    for (short i = 0; i < 11; i++) {
        vector_add(&T_ vec, &i);
    }
    ASSERT_EQ(T_ vec.size, 11, "%zu");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 10)), 10, "%d");
}

TEST(vector_insert_empty, Vector_fixture) {
    short value = 4;
    vector_insert(&T_ vec, 0, &value);
    ASSERT_EQ(T_ vec.size, 1, "%zu");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 0)), 4, "%d");
}

PTEST(vector_insert, Vector_fixture) {
    ASSERT_EQ(T_ vec.size, 3, "%zu");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 0)), 3, "%d");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 1)), 5, "%d");
    ASSERT_EQ(*((short *) vector_get(&T_ vec, 2)), 7, "%d");
}

PCASE(vector_insert, Vector_fixture) {
    // Insert at front
    short a = 3, b = 5, c = 7;
    vector_add(&T_ vec, &b);
    vector_add(&T_ vec, &c);
    vector_insert(&T_ vec, 0, &a);
}

PCASE(vector_insert, Vector_fixture) {
    // Insert at back
    short a = 3, b = 5, c = 7;
    vector_add(&T_ vec, &a);
    vector_add(&T_ vec, &b);
    vector_insert(&T_ vec, 2, &c);
}

PCASE(vector_insert, Vector_fixture) {
    // Insert in middle
    short a = 3, b = 5, c = 7;
    vector_add(&T_ vec, &a);
    vector_add(&T_ vec, &c);
    vector_insert(&T_ vec, 1, &b);
}

#pragma TEST_END

 // int main() {}