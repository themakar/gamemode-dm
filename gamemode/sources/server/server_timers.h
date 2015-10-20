public KickTimer(playerid)
{
	if (PlayerInfo[playerid][pKicked])
	{
		return Kick(playerid);
	}
	return true;
}