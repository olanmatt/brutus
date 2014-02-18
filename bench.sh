make
valgrind --tool=callgrind --dump-instr=yes ./brutus abcd 1 5 > /dev/null
kcachegrind
wait $!
rm callgrind.out.*
