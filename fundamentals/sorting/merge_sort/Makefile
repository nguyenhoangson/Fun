all: test_merge_sort.cpp merge_sort.cpp
	  g++ test_merge_sort.cpp merge_sort.cpp -I $GTEST_ROOT/include -L $GTEST_ROOT/lib -lgtest -lgtest_main -lpthread -o test_merge_sort
run:
	./test_merge_sort
