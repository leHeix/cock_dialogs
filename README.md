# cock_dialogs
Fastest dialog handler for SA-MP.

## Usage
Example script:
```pawn
#include <cock_dialogs>
new SpoofAttempts[MAX_PLAYERS];
forward DelayedKick(playerid);
public DelayedKick(playerid)
{
    Kick(playerid);
    return 1;
}

public OnPlayerConnect(playerid)
{
	SpoofAttempts[playerid] = 0;
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

public OnPlayerCDiagSpoofing(playerid, dialogid)
{
	if(SpoofAttempts[playerid] != 3)
	{
		SendClientMessage(playerid, -1, "You have attempted to Spoof a Dialog, repeated attempts will get you kicked!");
		SpoofAttempts[playerid] ++;
		return 1;
	}
	else
	{
		SendClientMessage(playerid, -1, "You have been kicked for attempting to Spoof a Dialog!");
		SetTimerEx("DelayedKick", 1000, false, "i", playerid);
		return 1;
	}
    return 1;
}

```
## Installation
Use `sampctl p install leHeix/cock_dialogs` or download cock_dialogs.inc and paste it in `pawno/include`, then include in your script.
