#include <math.h>

#include "Menu.hpp"
#include "Globals.hpp"

namespace Menu
{
	Start::Start(Mini2D * mini, long id, long prevId) {
		if (!mini)
			return;

		_mini = mini;
		_id = id;
		_prevId = prevId;
	}

	Start::~Start() {
		
	}

	void Start::Draw(float deltaTime) {
		if (!tex_bgimg)
			return;

		tex_bgimg->Draw(0xF0F0F0FF);
		tex_titlescr_logo->Draw(0xF0F0F0FF);
	}

	void Start::Pad(int changed, int port, padData pData) {

	}

	long Start::ID() {
		return _id;
	}
}
