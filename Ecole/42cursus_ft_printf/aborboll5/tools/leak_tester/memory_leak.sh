main_file=$1
rm tools/leak_tester/valgrind_out
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --dsymutil=yes ./${main_file} > tools/leak_tester/valgrind_out  2>&1
byts=$(cat tools/leak_tester/valgrind_out | grep "definitely lost:" | cut -d : -f 2 | cut -d b  -f 1 | tr -d " " | tr -d ",")
rm -rf ${main_file}.dSYM
rm -rf tools/leak_tester/msg.c tools/leak_tester/msg_out
