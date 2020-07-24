#include <cock_dialogs>

public OnPlayerConnect(playerid)
{
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "Hola, mundo!", "Hello, world!", "Ok, "Fuck you");
	return 1;
}

forward 0_Response(playerid, response, listitem, inputtext[]);
public 0_Response(playerid, response, listitem, inputtext[])
{
	SendClientMesssage(playerid, -1, "pawno");
	return 1;
}
