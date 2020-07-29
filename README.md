# cock_dialogs
Fastest dialog handler for SA-MP.

## Usage
Example script:
```pawn
#include <cock_dialogs>

public OnPlayerRequestClass(playerid, classid)
{
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "Hello there!", "Hello, world!", "Accept", "bye");
	return 1;
}

CDiag:0(playerid, response, listitem, inputtext[])
{
	if(!response) return 0;
	ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "responses!", "Replied!!!", "Accept", "bye");
	return 1;
}

```
## Installation
Use `sampctl p install leHeix/cock_dialogs` or download cock_dialogs.inc and paste it in `pawno/include`, then include in your script.
