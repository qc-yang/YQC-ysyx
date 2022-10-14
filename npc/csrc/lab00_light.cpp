#include <nvboard.h>
#include <Vlab00_light.h>

static TOP_NAME lab00_light;

void single_cycle() {
	lab00_light.clk = 0; lab00_light.eval();
	lab00_light.clk = 1; lab00_light.eval();
}

void reset(int n) {
	lab00_light.rst = 1;
	while (n -- > 0) single_cycle();
	lab00_light.rst = 0;
}
void nvboard_bind_all_pins(Vlab00_light* lab00_light);
int main()
{

	nvboard_bind_all_pins(&lab00_light);
	nvboard_init();
	reset(10);
	while (1)
	{
		single_cycle();
		nvboard_update();
	}
	nvboard_quit();
}
