public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if (PlayerInterface[playerid][pShowConnectMenu])
	{
		if (playertextid == PlayerInterface[playerid][pTextDraws][5]) {
			Player_DestroyConnectedMenu(playerid);
			Player_CreateRegisterBox(playerid);
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][6]) {
			Player_DestroyConnectedMenu(playerid);
			Player_CreateLoginBox(playerid);
		}
	}
	else if (PlayerInterface[playerid][pShowLoginBox])
	{
		if (playertextid == PlayerInterface[playerid][pTextDraws][12]) {
			Player_DestroyLoginBox(playerid);
			Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод логина", "{ffffff}Пожалуйста, введите ваш логин или почтовый адрес:", "Далее", "Отмена");	
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][13]) {
			Player_DestroyLoginBox(playerid);
			Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}Ввод пароля", "{ffffff}Пожалуйста, введите ваш пароль в поле ниже:", "Далее", "Отмена");	
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][16]) {
			Player_DestroyLoginBox(playerid);
			Player_CreateConnectedMenu(playerid);
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][17]) {
			OnPlayerLoginAttemp(playerid, PlayerNickName[playerid], PlayerPassword[playerid]);
		}
	}
	else if (PlayerInterface[playerid][pShowRegisterBox])
	{
		if (playertextid == PlayerInterface[playerid][pTextDraws][23]) 
		{
			Player_DestroyRegisterBox(playerid);
			
			PlayerInfo[playerid][pRegistration] = true;
			Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод логина", "{ffffff}Пожалуйста, введите ваш логин или почтовый адрес:", "Далее", "Отмена");	
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][24]) {
			Player_DestroyRegisterBox(playerid);
			Dialog_Show(playerid, MailInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод электронной почты", "{ffffff}Пожалуйста, введите свой электронный ящик:", "Далее", "Отмена");	
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][27]) {
			Player_DestroyRegisterBox(playerid);
			Player_CreateConnectedMenu(playerid);
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][28]) {
			PlayerCreateAccount(playerid, PlayerNickName[playerid], PlayerPassword[playerid], PlayerMail[playerid]);
		}
		else if (playertextid == PlayerInterface[playerid][pTextDraws][32]) 
		{
			Player_DestroyRegisterBox(playerid);
			
			PlayerInfo[playerid][pRegistration] = true;
			Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}Ввод пароля", "{ffffff}Пожалуйста, введите ваш пароль в поле ниже:", "Далее", "Отмена");	
		}
	}
    return true;
}

Player_CreateLogotype(playerid)
{
	new string[64];
	
	if (PlayerInterface[playerid][pShowLogotype]) return false;
	
	format(string, sizeof(string), "ONLINE: ~r~%d/%d", GetPlayersOnline(), MAX_PLAYERS);
	
	PlayerInterface[playerid][pTextDraws][0] = CreatePlayerTextDraw(playerid, 139.925109, 368.500091, "death~n~match");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][0], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][0], true);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][0], -1523963137);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][0], false);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][0], true);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][0], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][0], 3);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][0], false);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][0], false);
	
	PlayerInterface[playerid][pTextDraws][1] = CreatePlayerTextDraw(playerid, 160.556367, 396.950225, string);
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][1], 0.201249, 0.730832);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][1], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][1], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][1], true);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][1], false);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][1], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][1], true);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][1], true);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][1], true);
	
	PlayerTextDrawShow(playerid, PlayerInterface[playerid][pTextDraws][0]);
	PlayerTextDrawShow(playerid, PlayerInterface[playerid][pTextDraws][1]);
	PlayerInterface[playerid][pShowLogotype] = true;
	return true;
}

Player_DestroyLogotype(playerid)
{
	if (!PlayerInterface[playerid][pShowLogotype]) return false;
	
	PlayerTextDrawHide(playerid, PlayerInterface[playerid][pTextDraws][0]);
	PlayerTextDrawHide(playerid, PlayerInterface[playerid][pTextDraws][1]);
	
	PlayerTextDrawDestroy(playerid, PlayerInterface[playerid][pTextDraws][0]);
	PlayerTextDrawDestroy(playerid, PlayerInterface[playerid][pTextDraws][1]);
	
	PlayerInterface[playerid][pShowLogotype] = false;
	return true;
}

Player_CreateConnectedMenu(playerid)
{
	if (PlayerInterface[playerid][pShowConnectMenu]) return false;
	
	PlayerInterface[playerid][pTextDraws][2] = CreatePlayerTextDraw(playerid, 246.875000, 180.682907, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][2], 0.000000, 8.375000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][2], 392.500000, 0.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][2], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][2], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][2], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][2], 76);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][2], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][2], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][2], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][2], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][2], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][2], 0);

	PlayerInterface[playerid][pTextDraws][3] = CreatePlayerTextDraw(playerid, 249.974884, 235.500000, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][3], 0.000000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][3], 388.149932, 20.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][3], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][3], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][3], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][3], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][3], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][3], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][3], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][3], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][3], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][3], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][3], true);

	PlayerInterface[playerid][pTextDraws][4] = CreatePlayerTextDraw(playerid, 321.875000, 240.750000, "About Server");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][4], 0.320624, 0.899999);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][4], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][4], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][4], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][4], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][4], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][4], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][4], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][4], 0);

	PlayerInterface[playerid][pTextDraws][5] = CreatePlayerTextDraw(playerid, 247.224945, 207.165130, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][5], 143.494796, 22.499971);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][5], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][5], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][5], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][5], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][5], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][5], 4);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][5], 0);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][5], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][5], true);

	PlayerInterface[playerid][pTextDraws][6] = CreatePlayerTextDraw(playerid, 247.224945, 181.765518, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][6], 143.494796, 22.499971);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][6], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][6], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][6], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][6], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][6], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][6], 4);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][6], 0);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][6], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][6], true);

	PlayerInterface[playerid][pTextDraws][7] = CreatePlayerTextDraw(playerid, 321.875000, 188.550796, "authorization");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][7], 0.320624, 0.899999);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][7], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][7], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][7], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][7], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][7], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][7], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][7], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][7], 0);

	PlayerInterface[playerid][pTextDraws][8] = CreatePlayerTextDraw(playerid, 321.875000, 213.950408, "registration");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][8], 0.320624, 0.899999);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][8], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][8], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][8], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][8], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][8], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][8], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][8], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][8], 0);
	
	for (new i = 2; i < 9; i++) {
		PlayerTextDrawShow(playerid, PlayerInterface[playerid][pTextDraws][i]);
	}
	
	SelectTextDraw(playerid, 0xB92228FF);
	PlayerInterface[playerid][pShowConnectMenu] = true;
	
	return true;
}

Player_DestroyConnectedMenu(playerid)
{
	if (!PlayerInterface[playerid][pShowConnectMenu]) return false;
	
	for (new i = 2; i < 9; i++) {
		PlayerTextDrawHide(playerid, PlayerInterface[playerid][pTextDraws][i]);
		PlayerTextDrawDestroy(playerid, PlayerInterface[playerid][pTextDraws][i]);
	}
	
	CancelSelectTextDraw(playerid);
	PlayerInterface[playerid][pShowConnectMenu] = false;
	
	return true;
}

Player_CreateLoginBox(playerid)
{
	if (PlayerInterface[playerid][pShowLoginBox]) return false;
		
	PlayerInterface[playerid][pTextDraws][9] = CreatePlayerTextDraw(playerid, 246.875000, 180.682907, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][9], 0.000000, 11.003049);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][9], 391.250000, 0.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][9], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][9], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][9], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][9], 76);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][9], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][9], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][9], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][9], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][9], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][9], 0);

	PlayerInterface[playerid][pTextDraws][10] = CreatePlayerTextDraw(playerid, 250.000000, 182.416687, "LOGIN");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][10], 0.336875, 0.993333);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][10], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][10], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][10], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][10], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][10], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][10], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][10], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][10], 0);

	PlayerInterface[playerid][pTextDraws][11] = CreatePlayerTextDraw(playerid, 250.625000, 218.418884, "PASSWORD");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][11], 0.336875, 0.993333);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][11], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][11], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][11], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][11], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][11], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][11], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][11], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][11], 0);

	PlayerInterface[playerid][pTextDraws][12] = CreatePlayerTextDraw(playerid, 250.625000, 196.233322, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][12], 0.000000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][12], 388.750000, 20.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][12], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][12], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][12], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][12], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][12], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][12], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][12], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][12], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][12], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][12], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][12], true);

	PlayerInterface[playerid][pTextDraws][13] = CreatePlayerTextDraw(playerid, 250.625000, 232.633209, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][13], 0.000000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][13], 388.750000, 20.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][13], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][13], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][13], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][13], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][13], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][13], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][13], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][13], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][13], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][13], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][13], true);

	PlayerInterface[playerid][pTextDraws][14] = CreatePlayerTextDraw(playerid, 316.550000, 201.683319, (!PlayerNickName[playerid][0]) ? ("Your Login") : (PlayerNickName[playerid]));
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][14], 0.306874, 0.759999);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][14], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][14], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][14], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][14], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][14], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][14], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][14], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][14], 0);

	PlayerInterface[playerid][pTextDraws][15] = CreatePlayerTextDraw(playerid, 316.550000, 238.283691, (!PlayerPassword[playerid][0]) ? ("Your Password") : (HidePassword(PlayerPassword[playerid])));
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][15], 0.306874, 0.759999);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][15], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][15], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][15], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][15], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][15], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][15], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][15], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][15], 0);
	
	PlayerInterface[playerid][pTextDraws][16] = CreatePlayerTextDraw(playerid, 248.125000, 258.250030, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][16], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][16], 70.659980, 20.000007);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][16], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][16], 55);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][16], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][16], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][16], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][16], 4);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][16], 0);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][16], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][16], true);

	PlayerInterface[playerid][pTextDraws][17] = CreatePlayerTextDraw(playerid, 320.528808, 258.250030, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][17], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][17], 70.659980, 20.000007);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][17], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][17], 55);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][17], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][17], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][17], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][17], 4);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][17], 0);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][17], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][17], true);

	PlayerInterface[playerid][pTextDraws][18] = CreatePlayerTextDraw(playerid, 281.101135, 263.516693, "<BACK");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][18], 0.340624, 0.987500);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][18], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][18], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][18], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][18], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][18], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][18], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][18], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][18], 0);

	PlayerInterface[playerid][pTextDraws][19] = CreatePlayerTextDraw(playerid, 356.905761, 263.516693, "NEXT>");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][19], 0.340624, 0.987500);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][19], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][19], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][19], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][19], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][19], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][19], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][19], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][19], 0);

	for (new i = 9; i < 20; i++) {
		PlayerTextDrawShow(playerid, PlayerInterface[playerid][pTextDraws][i]);
	}
	SelectTextDraw(playerid, 0xB92228FF);
	
	PlayerInterface[playerid][pShowLoginBox] = true;
	return true;
}

Player_DestroyLoginBox(playerid)
{
	if (!PlayerInterface[playerid][pShowLoginBox]) return false;
	
	for (new i = 9; i < 20; i++)
	{
		PlayerTextDrawHide(playerid, PlayerInterface[playerid][pTextDraws][i]);
		PlayerTextDrawDestroy(playerid, PlayerInterface[playerid][pTextDraws][i]);
	}
	CancelSelectTextDraw(playerid);
	
	PlayerInterface[playerid][pShowLoginBox] = false;
	return true;
}

Player_CreateRegisterBox(playerid)
{
	if (PlayerInterface[playerid][pShowRegisterBox]) return false;
	
	PlayerInterface[playerid][pTextDraws][20] = CreatePlayerTextDraw(playerid, 246.875000, 180.682907, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][20], 0.000000, 15.455028);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][20], 391.250000, 0.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][20], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][20], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][20], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][20], 76);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][20], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][20], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][20], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][20], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][20], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][20], 0);

	PlayerInterface[playerid][pTextDraws][21] = CreatePlayerTextDraw(playerid, 250.000000, 182.416687, "LOGIN");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][21], 0.336874, 0.993332);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][21], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][21], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][21], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][21], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][21], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][21], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][21], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][21], 0);

	PlayerInterface[playerid][pTextDraws][22] = CreatePlayerTextDraw(playerid, 250.625000, 218.418884, "E-MAIL");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][22], 0.336874, 0.993332);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][22], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][22], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][22], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][22], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][22], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][22], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][22], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][22], 0);

	PlayerInterface[playerid][pTextDraws][23] = CreatePlayerTextDraw(playerid, 250.625000, 196.233322, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][23], 0.000000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][23], 388.750000, 20.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][23], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][23], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][23], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][23], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][23], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][23], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][23], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][23], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][23], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][23], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][23], true);

	PlayerInterface[playerid][pTextDraws][24] = CreatePlayerTextDraw(playerid, 250.625000, 232.633209, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][24], 0.000000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][24], 388.750000, 20.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][24], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][24], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][24], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][24], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][24], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][24], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][24], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][24], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][24], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][24], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][24], true);

	PlayerInterface[playerid][pTextDraws][25] = CreatePlayerTextDraw(playerid, 320.449829, 201.683319, (!PlayerNickName[playerid][0]) ? ("Your Login") : (PlayerNickName[playerid]));
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][25], 0.306874, 0.759998);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][25], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][25], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][25], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][25], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][25], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][25], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][25], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][25], 0);

	PlayerInterface[playerid][pTextDraws][26] = CreatePlayerTextDraw(playerid, 320.449829, 238.283691, (!PlayerMail[playerid][0]) ? ("Your E-MAIL") : (PlayerMail[playerid]));
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][26], 0.306874, 0.759998);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][26], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][26], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][26], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][26], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][26], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][26], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][26], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][26], 0);

	PlayerInterface[playerid][pTextDraws][27] = CreatePlayerTextDraw(playerid, 248.750000, 295.131896, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][27], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][27], 70.659980, 20.000007);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][27], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][27], 55);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][27], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][27], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][27], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][27], 4);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][27], 0);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][27], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][27], true);

	PlayerInterface[playerid][pTextDraws][28] = CreatePlayerTextDraw(playerid, 321.153808, 295.148529, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][28], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][28], 70.659980, 20.000007);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][28], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][28], 55);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][28], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][28], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][28], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][28], 4);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][28], 0);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][28], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][28], true);

	PlayerInterface[playerid][pTextDraws][29] = CreatePlayerTextDraw(playerid, 281.101135, 301.015167, "<BACK");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][29], 0.340624, 0.987500);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][29], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][29], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][29], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][29], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][29], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][29], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][29], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][29], 0);

	PlayerInterface[playerid][pTextDraws][30] = CreatePlayerTextDraw(playerid, 356.905761, 300.415191, "NEXT>");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][30], 0.340624, 0.987500);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][30], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][30], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][30], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][30], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][30], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][30], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][30], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][30], 0);

	PlayerInterface[playerid][pTextDraws][31] = CreatePlayerTextDraw(playerid, 250.625000, 255.319259, "PASSWORD");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][31], 0.336874, 0.993332);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][31], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][31], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][31], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][31], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][31], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][31], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][31], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][31], 0);

	PlayerInterface[playerid][pTextDraws][32] = CreatePlayerTextDraw(playerid, 250.625000, 269.532897, "box");
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][32], 0.000000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerInterface[playerid][pTextDraws][32], 388.750000, 20.000000);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][32], 1);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][32], -1);
	PlayerTextDrawUseBox(playerid, PlayerInterface[playerid][pTextDraws][32], 1);
	PlayerTextDrawBoxColor(playerid, PlayerInterface[playerid][pTextDraws][32], 127);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][32], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][32], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][32], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][32], 1);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][32], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][32], 0);
	PlayerTextDrawSetSelectable(playerid, PlayerInterface[playerid][pTextDraws][32], true);

	PlayerInterface[playerid][pTextDraws][33] = CreatePlayerTextDraw(playerid, 320.449829, 274.883117, (!PlayerPassword[playerid][0]) ? ("Your Password") : (PlayerPassword[playerid]));
	PlayerTextDrawLetterSize(playerid, PlayerInterface[playerid][pTextDraws][33], 0.306874, 0.759998);
	PlayerTextDrawAlignment(playerid, PlayerInterface[playerid][pTextDraws][33], 2);
	PlayerTextDrawColor(playerid, PlayerInterface[playerid][pTextDraws][33], -1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][33], 0);
	PlayerTextDrawSetOutline(playerid, PlayerInterface[playerid][pTextDraws][33], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerInterface[playerid][pTextDraws][33], 255);
	PlayerTextDrawFont(playerid, PlayerInterface[playerid][pTextDraws][33], 2);
	PlayerTextDrawSetProportional(playerid, PlayerInterface[playerid][pTextDraws][33], 1);
	PlayerTextDrawSetShadow(playerid, PlayerInterface[playerid][pTextDraws][33], 0);
	
	for (new i = 20; i < 34; i++) {
		PlayerTextDrawShow(playerid, PlayerInterface[playerid][pTextDraws][i]);
	}
	SelectTextDraw(playerid, 0xB92228FF);
	
	PlayerInterface[playerid][pShowRegisterBox] = true;
	return true;
}

Player_DestroyRegisterBox(playerid)
{
	if (!PlayerInterface[playerid][pShowRegisterBox]) return false;
	
	for (new i = 20; i < 34; i++)
	{
		PlayerTextDrawHide(playerid, PlayerInterface[playerid][pTextDraws][i]);
		PlayerTextDrawDestroy(playerid, PlayerInterface[playerid][pTextDraws][i]);
	}
	CancelSelectTextDraw(playerid);
	
	PlayerInterface[playerid][pShowRegisterBox] = false;
	return true;
}