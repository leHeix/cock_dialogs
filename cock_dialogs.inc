#if defined inc_cock_dialogs
	#endinput
#endif
#define _inc_cock_dialogs

#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define CDiag:%0(%1,%2,%3,%4) \
		forward cockd_%0_response(%1, %2, %3, %4); \
		public cockd_%0_response(%1, %2, %3, %4)

new cock_Player_Dialog[MAX_PLAYERS] = {-1,...};

forward OnPlayerCDiagSpoofing(playerid, dialogid);

public OnPlayerConnect(playerid)
{
    cock_Player_Dialog[playerid] = -1;
    #if defined CDiag_OnPlayerConnect
		return CDiag_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
public OnPlayerDisconnect(playerid, reason)
{
	cock_Player_Dialog[playerid] = -1;
	#if defined CDiag_OnPlayerDisconnect
		return CDiag_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(cock_Player_Dialog[playerid] == dialogid)
	{
		if(!isnull(inputtext))
		{
			for(new i; i < strlen(inputtext); i++)
			{
				if(inputtext[i] == '%') inputtext[i] = '#';
			}
		}

		new dialog_name[32];
		format(dialog_name, 32, "cockd_%d_response", dialogid);
		if(funcidx(dialog_name) != -1) CallLocalFunction(dialog_name, "ddds", playerid, response, listitem, inputtext);
	}
	else CallLocalFunction("OnPlayerCDiagSpoofing", "ii", playerid, dialogid);
	
	#if defined CDiag_OnDialogResponse
		return CDiag_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}

public OnPlayerCDiagSpoofing(playerid, dialogid)
{
    cock_Player_Dialog[playerid] = -1;
    #if defined CDiag_OnPlayerCDiagSpoofing
		return CDiag_OnPlayerCDiagSpoofing(playerid, dialogid);
	#else
		return 1;
	#endif
}

stock cdiag_ShowPlayerDialog(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[])
{
	cock_Player_Dialog[playerid] = dialogid;
	return ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
}

#if defined _ALS_ShowPlayerDialog
	#undef ShowPlayerDialog
#else
	#define _ALS_ShowPlayerDialog
#endif
#define ShowPlayerDialog cdiag_ShowPlayerDialog

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse COCK_OnDialogResponse
#if defined CDiag_OnDialogResponse
	forward CDiag_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect CDiag_OnPlayerDisconnect
#if defined CDiag_OnPlayerDisconnect
	forward CDiag_OnPlayerDisconnect(playerid, reason);
#endif

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect CDiag_OnPlayerConnect
#if defined CDiag_OnPlayerConnect
	forward CDiag_OnPlayerConnect(playerid);
#endif

#if defined _ALS_OnPlayerCDiagSpoofing
	#undef OnPlayerCDiagSpoofing
#else
	#define _ALS_OnPlayerCDiagSpoofing
#endif
#define OnPlayerCDiagSpoofing CDiag_OnPlayerCDiagSpoofing
#if defined CDiag_OnPlayerCDiagSpoofing
	forward CDiag_OnPlayerCDiagSpoofing(playerid, dialogid);
#endif
