all: test_quick_sort.cpp quick_sort.cpp 
	  g++ test_quick_sort.cpp quick_sort.cpp -I $GTEST_ROOT/include -L $GTEST_ROOT/lib -lgtest -lgtest_main -lpthread -o test_quick_sort
run:
	./test_quick_sort
