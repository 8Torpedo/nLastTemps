
#ifdef TEST

#include "unity.h"
#include "board.h"

enum {LED_RED, LED_GREEN, LED_BLUE};
// test functions

void testTempFalling(){
	showTempChange(2, 1);
	TEST_ASSERT_TRUE(Board_LED_Test(LED_BLUE));
	TEST_ASSERT_FALSE(Board_LED_Test(LED_RED));
	TEST_ASSERT_FALSE(Board_LED_Test(LED_GREEN));
}

void testTempRising(){
	showTempChange(1, 2);
	TEST_ASSERT_FALSE(Board_LED_Test(LED_BLUE));
	TEST_ASSERT_FALSE(Board_LED_Test(LED_GREEN));
	TEST_ASSERT_TRUE(Board_LED_Test(LED_RED));
}

void testTempStable(){
	showTempChange(0, 0);
	TEST_ASSERT_FALSE(Board_LED_Test(LED_RED));
	TEST_ASSERT_TRUE(Board_LED_Test(LED_GREEN));
	TEST_ASSERT_FALSE(Board_LED_Test(LED_BLUE));
}


int main(){

	Board_Init();
	// ...unity code
	UNITY_BEGIN();

	RUN_TEST(testTempFalling);
	RUN_TEST(testTempRising);
	RUN_TEST(testTempStable);

	return UNITY_END();
}


#endif
