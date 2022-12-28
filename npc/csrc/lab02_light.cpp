#include <nvboard.h>
#include <Vlab02_light.h>

static TOP_NAME lab02_light;

void nvboard_bind_all_pins(Vlab02_light* lab02_light);
int main()
{

	nvboard_bind_all_pins(&lab02_light);
	nvboard_init();
	while(1)
	{
		lab02_light.eval();
		nvboard_update();
	}
	nvboard_quit();
}
