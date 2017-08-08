#include <stdio.h>
#include <io/pad.h>

#include <Mini2D/Mini2D.hpp>
#include <Mini2D/Image.hpp>

#include "alphatest_png.h"

int drawUpdate(float deltaTime, unsigned long frame);
void padUpdate(int changed, int port, padData pData);
void exit();

Mini2D * mini = NULL;

int doExit = 0;

int main(s32 argc, const char* argv[]) {

	// Initialize Mini2D
	mini = new Mini2D((Mini2D::PadCallback_f)&padUpdate, (Mini2D::DrawCallback_f)&drawUpdate, (Mini2D::ExitCallback_f)&exit);

	mini->SetAnalogDeadzone(15);
	mini->SetClearColor(0x23B2D7FF);
	mini->SetAlphaState(1);
	mini->BeginDrawLoop();

	return 0;
}

int drawUpdate(float deltaTime, unsigned long frame) {
	return doExit;
}

void padUpdate(int changed, int port, padData pData) {
	if (pData.BTN_L3 && pData.BTN_R3 && (changed & Mini2D::BTN_CHANGED_L3 || changed & Mini2D::BTN_CHANGED_R3))
		doExit = -1;
}

void exit() {
	printf("exiting\n");
	
	if (mini) {
		delete mini;
		mini = NULL;
	}
}
