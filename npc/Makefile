all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."

verilator -Wall -trace --cc --exe --build ./csrc/sim_main.cpp ./vsrc/top.v
./obj_dir/Vtop
gtkwave wave.vcd
clean:
	rm -rf obj_dir
	rm wave.vcd
include ../Makefile
