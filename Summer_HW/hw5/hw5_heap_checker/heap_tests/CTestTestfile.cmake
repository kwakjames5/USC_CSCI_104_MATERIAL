# CMake generated Testfile for 
# Source directory: /home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests
# Build directory: /home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(HeapTest.ConstructionDestruction "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.ConstructionDestruction")
add_test(HeapTest.InitiallyEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.InitiallyEmpty")
add_test(HeapTest.EmptyTopException "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.EmptyTopException")
add_test(HeapTest.EmptyPopException "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.EmptyPopException")
add_test(HeapTest.SingleItemNonempty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.SingleItemNonempty")
add_test(HeapTest.SingleItemPush "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.SingleItemPush")
add_test(HeapTest.SingleItemPushPop "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.SingleItemPushPop")
add_test(HeapTest.TwoElementPush_LowPriFirst "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.TwoElementPush_LowPriFirst")
add_test(HeapTest.TwoElementPush_HighPriFirst "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.TwoElementPush_HighPriFirst")
add_test(HeapTest.Duplicates "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.Duplicates")
add_test(HeapTest.NegativeElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.NegativeElements")
add_test(HeapTest.ThreeElementPush_0_5_10 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.ThreeElementPush_0_5_10")
add_test(HeapTest.ThreeElementPush_0_10_5 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.ThreeElementPush_0_10_5")
add_test(HeapTest.ThreeElementPush_5_0_10 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.ThreeElementPush_5_0_10")
add_test(HeapTest.ThreeElementPush_5_10_0 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.ThreeElementPush_5_10_0")
add_test(HeapTest.ThreeElementPush_10_0_5 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.ThreeElementPush_10_0_5")
add_test(HeapTest.ThreeElementPush_10_5_0 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.ThreeElementPush_10_5_0")
add_test(HeapTest.GreaterComparator "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.GreaterComparator")
add_test(HeapTest.StringStorage "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.StringStorage")
add_test(HeapTest.FiveElementPush_TrinaryHeap "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapTest.FiveElementPush_TrinaryHeap")
add_test(HeapStress.50x50RandomElements_QuaternaryHeap "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw5/hw5_heap_checker/heap_tests/heap_tests" "--gtest_filter=HeapStress.50x50RandomElements_QuaternaryHeap")
