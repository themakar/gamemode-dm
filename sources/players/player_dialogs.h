Dialog:LoginInput(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext))
			return Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}���� ������", "{ffffff}����������, ������� ��� ����� ��� �������� �����:", "�����", "������");	
	
		if (strlen(inputtext) > MAX_PLAYER_NAME)
			return Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}���� ������", "{ffffff}����������, ������� ��� ����� ��� �������� �����:", "�����", "������");	
		
		if (!IsValidNickName(inputtext))
			return Dialog_Show(playerid, LoginInput, DIALOG_STYLE_INPUT, "{ffffff}���� ������", "{ffffff}����������, ������� ��� ����� ��� �������� �����:", "�����", "������");	
		
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
			return Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}���� ������", "{ffffff}����������, ������� ��� ������ � ���� ����:", "�����", "������");	
		
		if (strlen(inputtext) > 32)
			return Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}���� ������", "{ffffff}����������, ������� ��� ������ � ���� ����:", "�����", "������");	
		
		if (!IsValidNickName(inputtext))
			return Dialog_Show(playerid, PassInput, DIALOG_STYLE_PASSWORD, "{ffffff}���� ������", "{ffffff}����������, ������� ��� ������ � ���� ����:", "�����", "������");	
		
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
			return Dialog_Show(playerid, MailInput, DIALOG_STYLE_INPUT, "{ffffff}���� ����������� �����", "{ffffff}����������, ������� ���� ����������� ����:", "�����", "������");	
		
		if (strlen(inputtext) > 64)
			return Dialog_Show(playerid, MailInput, DIALOG_STYLE_INPUT, "{ffffff}���� ����������� �����", "{ffffff}����������, ������� ���� ����������� ����:", "�����", "������");	
		
		if (!IsValidEmail(inputtext))
			return Dialog_Show(playerid, MailInput, DIALOG_STYLE_INPUT, "{ffffff}���� ����������� �����", "{ffffff}����������, ������� ���� ����������� ����:", "�����", "������");	
		
		format(PlayerMail[playerid], 64, inputtext);
	}
	Player_CreateRegisterBox(playerid);
	
	return true;
}