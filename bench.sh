make
valgrind --tool=callgrind --dump-instr=yes ./brutus > /dev/null
kcachegrind
wait $!
rm callgrind.out.*
