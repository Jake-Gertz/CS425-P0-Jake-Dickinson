#include <stdlib.h>
#include <stdio.h>
#include "harness/unity.h"
#include "../src/lab.h"


void setUp(void) {
  printf("Setting up tests...\n");
}

void tearDown(void) {
  printf("Tearing down tests...\n");
}

void test_get_greeting(void) {
  char *greeting = get_greeting("Alice");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", greeting);
  free(greeting); // Free the allocated memory for the greeting

  greeting = get_greeting(NULL);
  TEST_ASSERT_NULL(greeting);

  greeting = get_greeting("");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, !", greeting);
  free(greeting);
}

void test_product_calculation(void) {
  TEST_ASSERT_EQUAL_FLOAT(105.0, product_calculation(10.5, 10));
  TEST_ASSERT_EQUAL_FLOAT(1.0,product_calculation(1.0, 1.0));
  TEST_ASSERT_EQUAL_FLOAT(25.0,product_calculation(5, 5));  

  TEST_ASSERT_NOT_EQUAL_FLOAT(10, product_calculation(10,10));
}

void test_get_incorrect_sum(void) {
  TEST_ASSERT_NOT_EQUAL_FLOAT(10.0, get_incorrect_sum(100,90));
  TEST_ASSERT_NOT_EQUAL_FLOAT(0.0, get_incorrect_sum(0, 0));
  TEST_ASSERT_NOT_EQUAL_FLOAT(15, get_incorrect_sum(25.5, 10.5));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_greeting);
  RUN_TEST(test_product_calculation);
  RUN_TEST(test_get_incorrect_sum);
  return UNITY_END();
}
