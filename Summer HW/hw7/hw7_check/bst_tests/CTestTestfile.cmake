# CMake generated Testfile for 
# Source directory: /home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests
# Build directory: /home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(BST.ConstructionDestruction "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BST.ConstructionDestruction")
add_test(BSTInsert.JustRoot "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.JustRoot")
add_test(BSTInsert.DoubleInsertLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.DoubleInsertLeft")
add_test(BSTInsert.DoubleInsertRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.DoubleInsertRight")
add_test(BSTInsert.InsertZigZigLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.InsertZigZigLeft")
add_test(BSTInsert.InsertZigZigRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.InsertZigZigRight")
add_test(BSTInsert.InsertZigZagLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.InsertZigZagLeft")
add_test(BSTInsert.InsertZigZagRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.InsertZigZagRight")
add_test(BSTInsert.7Elements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.7Elements")
add_test(BSTClear.Clear "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTClear.Clear")
add_test(BSTFind.InvalidFind "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTFind.InvalidFind")
add_test(BSTInsert.Duplicates "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.Duplicates")
add_test(BSTInsert.BasicRandom "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.BasicRandom")
add_test(BSTInsert.Random50x30ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.Random50x30ele")
add_test(BSTInsert.Random3x5000ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTInsert.Random3x5000ele")
add_test(BSTRemove.EmptyTree "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.EmptyTree")
add_test(BSTRemove.NodeMismatch "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.NodeMismatch")
add_test(BSTRemove.SingleRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.SingleRemove")
add_test(BSTRemove.RightChildRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.RightChildRemove")
add_test(BSTRemove.LeftChildRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.LeftChildRemove")
add_test(BSTRemove.TwoChildrenRemove_3Node "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.TwoChildrenRemove_3Node")
add_test(BSTRemove.TwoChildrenRemove_4Node "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.TwoChildrenRemove_4Node")
add_test(BSTRemove.Random50x30ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTRemove.Random50x30ele")
add_test(BSTStress.InsertRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTStress.InsertRemove")
add_test(BSTStress.Remove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTStress.Remove")
add_test(BSTBalance.EmptyTree "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTBalance.EmptyTree")
add_test(BSTBalance.OneNode "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTBalance.OneNode")
add_test(BSTBalance.3Nodes_Unbalanced "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTBalance.3Nodes_Unbalanced")
add_test(BSTBalance.3Nodes_Balanced "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTBalance.3Nodes_Balanced")
add_test(BSTBalance.UnbalancedSubtree "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTBalance.UnbalancedSubtree")
add_test(BSTBalance.Random50x30ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/cs104/Repositories/hw-kwakjame/hw7/hw7_check/bst_tests/bst_tests" "--gtest_filter=BSTBalance.Random50x30ele")
