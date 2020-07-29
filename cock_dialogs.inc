#if defined inc_cock_dialogs
	#endinput
#endif
#define _inc_cock_dialogs

#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#if defined SAMP_CONST_CORRECT
	#define CDIAG_CONST const
#else
	#define CDIAG_CONST
#endif

#define CDiag:%0(%1,%2,%3,%4) \
		forward cockd_%0_response(%1, %2, %3, %4); \
		public cockd_%0_response(%1, %2, %3, %4)

#if !defined _easyDialog_included
	#define Dialog CDiag
#endif

new cock_Player_Dialog[MAX_PLAYERS] = {-1,...};

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
		CallLocalFunction(dialog_name, "ddds", playerid, response, listitem, inputtext);
	}
	
	cock_Player_Dialog[playerid] = -1;
	
	#if defined CDiag_OnDialogResponse
		return CDiag_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}

stock cdiag_ShowPlayerDialog(playerid, dialogid, style, CDIAG_CONST caption[], CDIAG_CONST info[], CDIAG_CONST button1[], CDIAG_CONST button2[])
{
	cock_Player_Dialog[playerid] = dialogid;
	return ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
}

/* 			Hooks				*/
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
