Dialog:LoginInput(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext))
			return Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод логина", "{ffffff}Пожалуйста, введите ваш логин или почтовый адрес:", "Далее", "Отмена");	
	
		if (strlen(inputtext) > MAX_PLAYER_NAME)
			return Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод логина", "{ffffff}Пожалуйста, введите ваш логин или почтовый адрес:", "Далее", "Отмена");	
		
		if (!IsValidNickName(inputtext))
			return Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод логина", "{ffffff}Пожалуйста, введите ваш логин или почтовый адрес:", "Далее", "Отмена");	
		
		format(PlayerNickName[playerid], MAX_PLAYER_NAME, inputtext);
	}
	switch (PlayerInfo[playerid][pRegistration])
	{
		case false: Player_CreateLoginBox(playerid);
		case true: 
		{
			Player_CreateRegisterBox(playerid);
			PlayerInfo[playerid][pRegistration] = false;
		}
	}
	return true;
}

Dialog:PassInput(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext))
			return Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}Ввод пароля", "{ffffff}Пожалуйста, введите ваш пароль в поле ниже:", "Далее", "Отмена");	
		
		if (strlen(inputtext) > 32)
			return Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}Ввод пароля", "{ffffff}Пожалуйста, введите ваш пароль в поле ниже:", "Далее", "Отмена");	
		
		if (!IsValidNickName(inputtext))
			return Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}Ввод пароля", "{ffffff}Пожалуйста, введите ваш пароль в поле ниже:", "Далее", "Отмена");	
		
		format(PlayerPassword[playerid], 32, inputtext);
	}
	switch (PlayerInfo[playerid][pRegistration])
	{
		case false: Player_CreateLoginBox(playerid);
		case true: 
		{
			Player_CreateRegisterBox(playerid);
			PlayerInfo[playerid][pRegistration] = false;
		}
	}
	return true;
}

Dialog:MailInput(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext))
			return Dialog_Show(playerid, MailInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод электронной почты", "{ffffff}Пожалуйста, введите свой электронный ящик:", "Далее", "Отмена");	
		
		if (strlen(inputtext) > 64)
			return Dialog_Show(playerid, MailInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод электронной почты", "{ffffff}Пожалуйста, введите свой электронный ящик:", "Далее", "Отмена");	
		
		if (!IsValidEmail(inputtext))
			return Dialog_Show(playerid, MailInput, DIALOG_STYLE_INPUT, "{ffffff}Ввод электронной почты", "{ffffff}Пожалуйста, введите свой электронный ящик:", "Далее", "Отмена");	
		
		format(PlayerMail[playerid], 64, inputtext);
	}
	Player_CreateRegisterBox(playerid);
	
	return true;
}