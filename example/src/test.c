
#ifdef TEST

#include "unity.h"
#include "board.h"

enum {LED_RED, LED_GREEN, LED_BLUE};
uint8_t testTable[] = { 2 , 2, 2, 2, 2};

// test functions
void testAverage(){
	TEST_ASSERT_EQUAL(2, averageTemp(testTable, 5));
}

void testTempFalling(){
	lastTemps(testTable, 3, 5, 3);
	TEST_ASSERT_TRUE(Board_LED_Test(LED_BLUE));
	TEST_ASSERT_FALSE(Board_LED_Test(LED_RED));
	TEST_ASSERT_FALSE(Board_LED_Test(LED_GREEN));
}

void testTempRising(){
	lastTemps(testTable, 1, 5, 3);
	TEST_ASSERT_FALSE(Board_LED_Test(LED_BLUE));
	TEST_ASSERT_FALSE(Board_LED_Test(LED_GREEN));
	TEST_ASSERT_TRUE(Board_LED_Test(LED_RED));
}

void testTempStable(){
	lastTemps(testTable, 2, 5, 3);
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
	RUN_TEST(testAverage);

	return UNITY_END();
}


#endif
