

#ifndef MENU_HPP_
#define MENU_HPP_

#include <Mini2D/Mini2D.hpp>				// Mini2D class
#include <Mini2D/Image.hpp>					// Image class
#include <Mini2D/Units.hpp>					// RectangleF, Vector2

// Textures
#include "bgimg_png.h"						// 
#include "cheat_png.h"						// 
#include "circle_error_dark_png.h"			// 
#include "circle_error_light_png.h"			// 
#include "circle_loading_bg_png.h"			// 
#include "circle_loading_seek_png.h"		// 
#include "edit_ico_add_png.h"				// 
#include "edit_ico_del_png.h"				// 
#include "edit_shadow_png.h"				// 
#include "footer_ico_circle_png.h"			// 
#include "footer_ico_cross_png.h"			// 
#include "footer_ico_lt_png.h"				// 
#include "footer_ico_rt_png.h"				// 
#include "footer_ico_square_png.h"			// 
#include "footer_ico_triangle_png.h"		// 
#include "header_dot_png.h"					// 
#include "header_ico_abt_png.h"				// 
#include "header_ico_cht_png.h"				// 
#include "header_ico_opt_png.h"				// 
#include "header_ico_xmb_png.h"				// 
#include "header_line_png.h"				// 
#include "help_png.h"						// 
#include "mark_arrow_png.h"					// 
#include "mark_line_png.h"					// 
#include "opt_off_png.h"					// 
#include "opt_on_png.h"						// 
#include "scroll_bg_png.h"					// 
#include "scroll_lock_png.h"				// 
#include "titlescr_ico_abt_png.h"			// 
#include "titlescr_ico_cht_png.h"			// 
#include "titlescr_ico_opt_png.h"			// 
#include "titlescr_ico_xmb_png.h"			// 
#include "titlescr_logo_png.h"				// 

namespace Menu {

	class IMenu
	{
	public:
		long State;								// Whether or not the menu is opening, closing, or idle

		virtual ~IMenu() { }

		// Draws the menu
		virtual void Draw(float deltaTime) = 0;

		// Process controller inputs
		virtual void Pad(int changed, int port, padData pData) = 0;

		// Returns the ID of this menu instance
		virtual long ID() = 0;

	protected:
		Mini2D * _mini;
		long  _id;
		long _prevId;
	};

	class Start : public IMenu {
	public:
		Start(Mini2D * mini, long id, long prevId);
		~Start();

		virtual void Draw(float deltaTime);
		virtual void Pad(int changed, int port, padData pData);
		virtual long ID();

	private:
	};
}

#endif /* MENU_HPP_ */