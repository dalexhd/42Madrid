echo "" > tools/makefile_target/makefile_targets
grep -B1 -E "^[a-zA-Z0-9_-]+\:" ./Makefile | grep -v -- -- | tr -s '\t' ' ' | tr -s ' ' ' ' | sed 'N;s/\n/###/' | sed -n 's/^# \(.*\)###\(.*\):.*/\\033[33;36m\2:\\033[33;0m###     \1\\n/p' | tr -d '"' | column -t  -s '###' >> tools/makefile_target/makefile_targets
