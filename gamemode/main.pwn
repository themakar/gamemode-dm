#include <a_samp>

#include plugins/YSF
#include plugins/foreach
#include plugins/streamer // Last Version: https://github.com/samp-incognito/samp-streamer-plugin/releases (Streamer Plugin v2.7.8)
#include plugins/a_mysql // Last Version: https://github.com/pBlueG/SA-MP-MySQL/releases (R39-3)
#include plugins/a_dialogs

#include main.h
#include main_systems.h

#include sources/players/player.h
#include sources/server/server.h
#include sources/teams/team.h

public OnGameModeInit()
{
	OnServerSetup();
	SQL_CreateConnection();
	
	if (mysql_errno(sql_handle) != 0) return false;
		
	LoadServerMap();	
	return true;
}

public OnGameModeExit()
{
	return true;
}

public OnPlayerRequestClass(playerid, classid)
{
	if (IsPlayerNPC(playerid)) return true;
	if (PlayerInfo[playerid][pKicked]) return false;
	
	Player_CreateConnectedMenu(playerid);
	SetPlayerColor(playerid, COLOUR_WHITE);
	TogglePlayerSpectating(playerid, true);
	return true;
}

public OnPlayerConnect(playerid)
{
	RemoveBuildsForPlayer(playerid);
	return true;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if (PlayerInterface[playerid][pShowRegisterBox])
		Player_DestroyRegisterBox(playerid);
	
	if (PlayerInterface[playerid][pShowLoginBox])
		Player_DestroyLoginBox(playerid);
	
	Player_CreateLogotype(playerid);
	return true;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/mycommand", cmdtext, true, 10) == 0)
	{
		// Do something here
		return 1;
	}
	return 0;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return true;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}
