#define HEX_COLOR(hex)				\
	{ .red   = ((hex >> 24) & 0xff) * 257,	\
	  .green = ((hex >> 16) & 0xff) * 257,	\
	  .blue  = ((hex >> 8) & 0xff) * 257,	\
	  .alpha = (hex & 0xff) * 257 }

// initially hide all bars
static bool hidden = false;
// initially draw all bars at the bottom
static bool bottom = false;
// hide vacant tags
static bool hide_vacant = true;
// vertical pixel padding above and below text
static uint32_t vertical_padding = 0;
// horizontal pixel padding by desgua
static uint32_t horizontal_padding = 0;
// allow in-line color commands in status text
static bool status_commands = true;
// center title text
static bool center_title = false;
// use title space as status text element
static bool custom_title = false;
// title color use active colors
static bool active_color_title = false;
// scale
static uint32_t buffer_scale = 1;
// set dpi by desgua
static uint32_t dpi_set = 143;
// font
//static char *fontstr = "URW Gothic:size=20, 3270 Nerd Font:size=14";
//static char *fontstr = "3270 Nerd Font:size=20";
static char *fontstr = "JetBrains Mono:Thin:size=14";
// tag names
static char *tags_names[] = { " ", "2", "3", "4", "  ", " ", " ", " ", " ", " ", "󱓧 ", " ", " ", " ", " ", "󱁸 ", " " };

// set 16-bit colors for bar
// use either pixman_color_t struct or HEX_COLOR macro for 8-bit colors
// fg: 82dcff
static pixman_color_t active_fg_color = HEX_COLOR(0x93edffff);
static pixman_color_t active_bg_color = HEX_COLOR(0x111111ff);
static pixman_color_t occupied_fg_color = HEX_COLOR(0x009DDBff);
static pixman_color_t occupied_bg_color = HEX_COLOR(0x111111ff);
// inactive changes also the [M] info
static pixman_color_t inactive_fg_color = HEX_COLOR(0x009DDBff);
static pixman_color_t inactive_bg_color = HEX_COLOR(0x111111ff);
static pixman_color_t urgent_fg_color = HEX_COLOR(0xffff00ff);
static pixman_color_t urgent_bg_color = HEX_COLOR(0x111111ff);
static pixman_color_t middle_bg_color = HEX_COLOR(0x111111ff);
static pixman_color_t middle_bg_color_selected = HEX_COLOR(0x111111ff);
