<div align="center">
<h1>dwlb</h1>

A fast, feature-complete bar for [dwl](https://github.com/djpohly/dwl).

![screenshot 1](/screenshot1.png "screenshot 1")
![screenshot 2](/screenshot2.png "screenshot 2")
</div>

## Dependencies
* libwayland-client
* pixman
* fcft

## Installation
This branch is a stripped down fork from https://github.com/kolunmi/dwlb focused on performance, simplicity and usability.
```bash
git clone --branch stripped https://github.com/desgua/dwlb.git
cd dwlb
make
make install
```

## Usage
Pass `dwlb_wrapper.sh` as an argument to dwl's `-s` flag. This will populate each connected output with a bar. For example:
```bash
dwl -s 'dwlb_wrapper.sh'
```

This fork is focused on performance, simplicity and usability. The main changes from original kolunmi code are:
- no ipc: for simplicity and I don't want to ever use the cursor. Ever.
- optimizations on Makefile, including -O3 and -march=native
- set the dpi in config.h
- new commands that print useful information like the ocuppied tags and the currently focused window.


## Commands
Command options send instructions to existing instances of dwlb. All commands take at least one argument to specify a bar on which to operate. This may be zxdg_output_v1 name, "all" to affect all outputs, or "selected" for the current output.

### Status Text
The `-status` and `-title` commands are used to write status text. The text may contain in-line commands in the following format: `^cmd(argument)`.

| In-Line Command     | Description                                                                 |
|---------------------|-----------------------------------------------------------------------------|
| `^fg(HEXCOLOR)`     | Sets foreground color to `HEXCOLOR`.                                        |
| `^bg(HEXCOLOR)`     | Sets background color to `HEXCOLOR`.                                        |


A color command with no argument reverts to the default value. `^^` represents a single `^` character. Status commands can be disabled with `-no-status-commands`.

## Scaling
If you use scaling in Wayland, you can specify `buffer_scale` through config file or by passing it as an option (only integer values):
```bash
dwlb -scale 2
```
This will render both surface and a cursor with 2x detail. If your monitor is set to 1.25 or 1.5 scaling, setting scale to 2 will also work as compositor will downscale the buffer properly.

## Other Options
usage: dwlb [OPTIONS]
Bar Config
	-hidden				bars will initially be hidden
	-no-hidden			bars will not initially be hidden
	-bottom				bars will initially be drawn at the bottom
	-no-bottom			bars will initially be drawn at the top
	-hide-vacant-tags		do not display empty and inactive tags
	-no-hide-vacant-tags		display empty and inactive tags
	-status-commands		enable in-line commands in status text
	-no-status-commands		disable in-line commands in status text
	-center-title			center title text on bar
	-no-center-title		do not center title text on bar
	-custom-title			do not display window title and treat the area as another status text element; see -title command
	-no-custom-title		display current window title as normal
	-active-color-title		title colors will use active colors
	-no-active-color-title		title colors will use inactive colors
	-font [FONT]			specify a font
	-tags [NUMBER] [FIRST]...[LAST]	if ipc is disabled, specify custom tag names. If NUMBER is 0, then no tag names should be given 
	-vertical-padding [PIXELS]	specify vertical pixel padding above and below text
	-active-fg-color [COLOR]	specify text color of active tags or monitors
	-active-bg-color [COLOR]	specify background color of active tags or monitors
	-occupied-fg-color [COLOR]	specify text color of occupied tags
	-occupied-bg-color [COLOR]	specify background color of occupied tags
	-inactive-fg-color [COLOR]	specify text color of inactive tags or monitors
	-inactive-bg-color [COLOR]	specify background color of inactive tags or monitors
	-urgent-fg-color [COLOR]	specify text color of urgent tags
	-urgent-bg-color [COLOR]	specify background color of urgent tags
	-middle-bg-color [COLOR]	specify background color of the color in the middle of the bar
	-middle-bg-color-selected [COLOR]	specify background color of the color in the middle of the bar, when selected
	-scale [BUFFER_SCALE]		specify buffer scale value for integer scaling
Commands
	-target-socket [SOCKET-NAME]	set the socket to send command to. Sockets can be found in `$XDG_RUNTIME_DIR/dwlb/`
	-status	[OUTPUT] [TEXT]		set status text
	-status-stdin	[OUTPUT]		set status text from stdin
	-title	[OUTPUT] [TEXT]		set title text, if -custom-title is enabled
	-show [OUTPUT]			show bar
	-hide [OUTPUT]			hide bar
	-toggle-visibility [OUTPUT]	toggle bar visibility
	-set-top [OUTPUT]		draw bar at the top
	-set-bottom [OUTPUT]		draw bar at the bottom
	-toggle-location [OUTPUT]	toggle bar location
	-printfocused [OUTPUT]		print the title of focused window
	-printtags [OUTPUT]		print the decimal representation of occupied tags
Other
	-v				get version information

## Someblocks
To use someblocks, or any program that outputs to stdout, with dwlb, use this one-liner:
```bash
someblocks -p | dwlb -status-stdin all
```

## Acknowledgements
* [dwlb](https://github.com/kolunmi/dwlb)
* [dtao](https://github.com/djpohly/dtao)
* [somebar](https://sr.ht/~raphi/somebar/)
