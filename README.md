# cock_dialogs
Fastest dialog handler for SA-MP.

## Usage
Example script:
```pawn
#include <cock_dialogs>

forward DelayedKick(playerid);
public DelayedKick(playerid)
{
    Kick(playerid);
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "Hola, mundo!", "Hello, world!", "Accept", "bye");
	return 1;
}

CDiag:0(playerid, response, listitem, inputtext[])
{
	SendClientMessage(playerid, -1, "Replied!");
	return 1;
}

public OnPlayerCockSpoofing(playerid, dialogid)
{
    SendClientMessage(playerid, -1, "You have been kicked for attempting to Spoof a Dialog!");
    SetTimerEx("DelayedKick", 1000, false, "i", playerid);
    return 1;
}

```

## Installation
Use `sampctl p install leHeix/cock_dialogs` or download cock_dialogs.inc and paste it in `pawno/include`, then include in your script.
