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

| In-Line Command                     | Description                                                                                         |
| ----------------------------------- | --------------------------------------------------------------------------------------------------- |
| `# Bar Config`                      |                                                                                                     |
| `-hidden`                           | Bars will initially be hidden                                                                       |
| `-no-hidden`                        | Bars will not initially be hidden                                                                   |
| `-bottom`                           | Bars will initially be drawn at the bottom                                                          |
| `-no-bottom`                        | Bars will initially be drawn at the top                                                             |
| `-hide-vacant-tags`                 | Do not display empty and inactive tags                                                              |
| `-no-hide-vacant-tags`              | Display empty and inactive tags                                                                     |
| `-status-commands`                  | Enable in-line commands in status text                                                              |
| `-no-status-commands`               | Disable in-line commands in status text                                                             |
| `-center-title`                     | Center title text on bar                                                                            |
| `-no-center-title`                  | Do not center title text on bar                                                                     |
| `-custom-title`                     | Do not display window title and treat the area as another status text element; see `-title` command |
| `-no-custom-title`                  | Display current window title as normal                                                              |
| `-active-color-title`               | Title colors will use active colors                                                                 |
| `-no-active-color-title`            | Title colors will use inactive colors                                                               |
| `-font [FONT]`                      | Specify a font                                                                                      |
| `-tags [NUMBER] [FIRST]...[LAST]`   | If IPC is disabled, specify custom tag names. If NUMBER is 0, then no tag names should be given     |
| `-vertical-padding [PIXELS]`        | Specify vertical pixel padding above and below text                                                 |
| `-active-fg-color [COLOR]`          | Specify text color of active tags or monitors                                                       |
| `-active-bg-color [COLOR]`          | Specify background color of active tags or monitors                                                 |
| `-occupied-fg-color [COLOR]`        | Specify text color of occupied tags                                                                 |
| `-occupied-bg-color [COLOR]`        | Specify background color of occupied tags                                                           |
| `-inactive-fg-color [COLOR]`        | Specify text color of inactive tags or monitors                                                     |
| `-inactive-bg-color [COLOR]`        | Specify background color of inactive tags or monitors                                               |
| `-urgent-fg-color [COLOR]`          | Specify text color of urgent tags                                                                   |
| `-urgent-bg-color [COLOR]`          | Specify background color of urgent tags                                                             |
| `-middle-bg-color [COLOR]`          | Specify background color of the middle of the bar                                                   |
| `-middle-bg-color-selected [COLOR]` | Specify background color of the middle of the bar when selected                                     |
| `-scale [BUFFER_SCALE]`             | Specify buffer scale value for integer scaling                                                      |



| Command                        | Description                                                                         |
| ------------------------------ | ----------------------------------------------------------------------------------- |
| `-target-socket [SOCKET-NAME]` | Set the socket to send command to. Sockets can be found in `$XDG_RUNTIME_DIR/dwlb/` |
| `-status [OUTPUT] [TEXT]`      | Set status text                                                                     |
| `-status-stdin [OUTPUT]`       | Set status text from stdin                                                          |
| `-title [OUTPUT] [TEXT]`       | Set title text, if `-custom-title` is enabled                                       |
| `-show [OUTPUT]`               | Show bar                                                                            |
| `-hide [OUTPUT]`               | Hide bar                                                                            |
| `-toggle-visibility [OUTPUT]`  | Toggle bar visibility                                                               |
| `-set-top [OUTPUT]`            | Draw bar at the top                                                                 |
| `-set-bottom [OUTPUT]`         | Draw bar at the bottom                                                              |
| `-toggle-location [OUTPUT]`    | Toggle bar location                                                                 |
| `-printfocused [OUTPUT]`       | Print the title of focused window                                                   |
| `-printtags [OUTPUT]`          | Print the decimal representation of occupied tags                                   |


| Option | Description             |
| ------ | ----------------------- |
| `-v`   | Get version information |

``` Example:
dwlb -printfocused eDP-1
```

## Someblocks
To use someblocks, or any program that outputs to stdout, with dwlb, use this one-liner:
```bash
someblocks -p | dwlb -status-stdin all
```

## Acknowledgements
* [dwlb](https://github.com/kolunmi/dwlb)
* [dtao](https://github.com/djpohly/dtao)
* [somebar](https://sr.ht/~raphi/somebar/)
