#undef MAX_PLAYERS
#define MAX_PLAYERS (100)

#undef MAX_PLAYER_TEXT_DRAWS
#define MAX_PLAYER_TEXT_DRAWS (34)

#define MODE_NAME 	"TDM"
#define MODE_VER 	"0.1.12"
#define MODE_DATA	"19.10.2015"
#define MODE_AUTHOR "themakar"

#define SQL_HOSTNAME "localhost"
#define SQL_USERNAME "root"
#define SQL_DATABASE "mode"
#define SQL_PASSWORD ""

#define COLOUR_WHITE		(0xFFFFFFFF)
#define COLOR_RED			(0xFF0000FF)
#define COLOR_LIGHTRED		(0xFF6347FF)
#define COLOR_DARKBLUE    	(0x1394BFFF)

#define THREAD_LOGIN (0)

#define MAX_LOGIN_ATTEMPTS (3)

#define SERVER_NAME "[0.3.7] War of San Andreas by themakar"
#define GAMEMODE_NAME #MODE_NAME " " #MODE_VER

enum e_playerInterface {
	PlayerText:pTextDraws[MAX_PLAYER_TEXT_DRAWS],
	pShowLogotype,
	pShowConnectMenu,
	pShowLoginBox,
	pShowRegisterBox
};

enum e_playerInfo {
	pID,
	pKicked,
	pLoginAttempts,
	pRegistration,
};

new sql_handle;

new PlayerInfo[MAX_PLAYERS][e_playerInfo];
new PlayerInterface[MAX_PLAYERS][e_playerInterface];

/* Register and Login Var */
new PlayerMail[MAX_PLAYERS][64];
new PlayerPassword[MAX_PLAYERS][32];
new PlayerNickName[MAX_PLAYERS][MAX_PLAYER_NAME];

main() 
{
	if (mysql_errno(sql_handle) == 0)
	{
		print("\n\n\n");
		print("| Игровой режим "GAMEMODE_NAME".");
		print("| Успешно загружен. Автор: "MODE_AUTHOR".");
		print("| Последнее обновление: "MODE_DATA".");
		print("\n\n\n");
	}
}

forward KickTimer(playerid);
forward OnQueryFinished(playerid, threadid);