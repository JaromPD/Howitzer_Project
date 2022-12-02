#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "test.h"
#include "testDirection.h";
#include "simulation.h";
using namespace std;

void callback(const Interface* pUI, void* p)
{
	Simulation* pSim = (Simulation*)p;
	
	// TAKE INPUTS
	pSim->input(pUI);

	// GAME LOGIC
	
	pSim->setInterval(0.5); // Advance time by half a second.
	pSim->advance();
	
	// Move projectile

	
	
	// DRAW EVERYTING
	pSim->display();
	
}

int main()
{
	Position ptUpperRight;
	ptUpperRight.setPixelsX(700.0);
	ptUpperRight.setPixelsY(500.0);
	Position().setZoom(40.0); /* 42 meters equals 1 pixel */
	Interface ui(0, NULL,
		"Artillery Simulator",   /* name on the window */
		ptUpperRight);
	Simulation sim(ptUpperRight);
	
	ui.run(callback, &sim);
	
	return 0;
}