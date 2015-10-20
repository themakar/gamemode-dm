stock GetPlayersOnline()
{
	new count;
	
	foreach (new i : Player) if (IsPlayerConnected(i)) {
		count ++;
	}
	return count;
}

stock ReturnPlayerName(playerid)
{
	new name[MAX_PLAYER_NAME];
	
	GetPlayerName(playerid, name, sizeof(name));
	
	return name;
}

stock HidePassword(const password[])
{
	new str[32];
	
	for (new i; i < strlen(password); i++)
	{
		strcat(str, "]");
	}
	return str;
}

stock KickEx(playerid)
{
	if (PlayerInfo[playerid][pKicked]) return false;

	PlayerInfo[playerid][pKicked] = 1;
	SetTimerEx("KickTimer", 500, false, "d", playerid);
	return true;
}

stock IsValidEmail(const mail[])
{
    new 
		count[2], 
		len = strlen(mail);
		
    if (6 < len > 64) return false;
	
    for (new i; i != len; i++)
    {
        if(mail[i] == '@')
        {
            count[0]++;
            if (count[0] != 1 || i == len - 1 || i == 0) return false;
        }
        else if (count[0] == 1 && mail[i] == '.' && count[1] == 0 && i != len - 1) count[1] = 1;
        else if (!(('0' <= mail[i] <= '9') ^ ('a' <= mail[i] <= 'z') ^ ('A' <= mail[i] <= 'Z') ^ (mail[i] == '_' || mail[i] == '-'))) return false;
    }
    return (count[1] == 0) ? (false) : (true);
} 