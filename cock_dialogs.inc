#if defined inc_cock_dialogs
	#endinput
#endif
#define _inc_cock_dialogs

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new dialog_name[32];
	format(dialog_name, 32, "%d_Response", dialogid);
	if(funcidx(dialog_name) != -1) CallLocalFunction(dialog_name, "ddds", playerid, response, listitem, inputtext);
	
	#if defined COCK_OnDialogResponse
		return COCK_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse COCK_OnDialogResponse
#if defined COCK_OnDialogResponse
	forward COCK_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
