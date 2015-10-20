stock SQL_CreateConnection()
{
	sql_handle = mysql_connect(SQL_HOSTNAME, SQL_USERNAME, SQL_DATABASE, SQL_PASSWORD);

	if (mysql_errno(sql_handle) != 0) {
		print(" ");
	    printf("[������] �� ������� ������������ � ������� SQL, ��������� ��������� ����������!\n\a");
	}
	return true;
}

public OnQueryFinished(playerid, threadid)
{
	if (!IsPlayerConnected(playerid)) return false;

	new 
		rows,
	    fields;
		
	switch (threadid)
	{
		case THREAD_LOGIN:
		{
			cache_get_data(rows, fields, sql_handle);
			
			if (!rows)
			{
				PlayerInfo[playerid][pLoginAttempts] ++;
				
				if (PlayerInfo[playerid][pLoginAttempts] >= MAX_LOGIN_ATTEMPTS) {
					SendClientMessage(playerid, COLOR_LIGHTRED, "[!] �� ���� �������, �� ��������� ��� ������� �����.");
    	            KickEx(playerid);
				}
				else {
					SendClientMessagef(playerid, COLOR_LIGHTRED, "[!] ������� ������ ������ (%d/%d �������).", PlayerInfo[playerid][pLoginAttempts], MAX_LOGIN_ATTEMPTS);
				}
			}
			else
			{
				SetSpawnInfo(playerid, 0, random(311), 1726.0510, -1851.8408, 13.7159, 0.0, 0, 0, 0, 0, 0, 0);
				TogglePlayerSpectating(playerid, false);
			}
		}
	}
	return true;
}

stock OnPlayerLoginAttemp(playerid, const login[], const password[])
{
	new query[256];
	
	if (strlen(login) < 1)
		return SendClientMessage(playerid, COLOR_LIGHTRED, "[!] �� ������ ������� ���� �����.");
	
	if (strlen(password) < 1)
		return SendClientMessage(playerid, COLOR_LIGHTRED, "[!] �� ������ ������� ���� ������.");
	
	format(query, sizeof(query), "SELECT `id` FROM `accounts` WHERE `username` = '%s' AND `password` = '%s' OR `email` = '%s' AND `password` = '%s'", login, password, login, password);
    mysql_tquery(sql_handle, query, "OnQueryFinished", "dd", playerid, THREAD_LOGIN);
	return true;
}

stock PlayerCreateAccount(playerid, const name[], const password[], const mail[])
{
	new query[256];
	
	if (strlen(name) < 1)
		return SendClientMessage(playerid, COLOR_LIGHTRED, "[!] �� ������ ������� ���� �����.");
	
	if (strlen(password) < 1)
		return SendClientMessage(playerid, COLOR_LIGHTRED, "[!] �� ������ ������� ���� ������.");
	
	format(query, sizeof(query), "INSERT INTO `accounts` (`username`, `email`, `password`) VALUES('%s', '%s', '%s')", name, mail, password);
	mysql_tquery(sql_handle, query);
	
	SendClientMessage(playerid, COLOR_DARKBLUE, "�� ������� ���������������� ���� �������.");
	
	SetSpawnInfo(playerid, 0, random(311), 1726.0510, -1851.8408, 13.7159, 0.0, 0, 0, 0, 0, 0, 0);
	TogglePlayerSpectating(playerid, false);
	return true;
}