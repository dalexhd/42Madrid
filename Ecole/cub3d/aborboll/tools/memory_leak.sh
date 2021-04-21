valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-leak-kinds=all --track-origins=yes --verbose ./${1} ${2} > valgrind_out  2>&1
rm -rf ${main_file}.dSYM tools/leak_tester/msg_out
