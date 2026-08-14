//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//
#include "cbase.h"
#include "gamevars_shared.h"

#if defined( TF_CLIENT_DLL ) || defined( TF_DLL )
#include "tf_gamerules.h"
#endif

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#ifdef GAME_DLL
void MPForceCameraCallback( IConVar *var, const char *pOldString, float flOldValue )
{
	if ( mp_forcecamera.GetInt() < OBS_ALLOW_ALL || mp_forcecamera.GetInt() >= OBS_ALLOW_NUM_MODES )
	{
		mp_forcecamera.SetValue( OBS_ALLOW_TEAM );
	}
}
#endif 

// some shared cvars used by game rules
ConVar mp_forcecamera( 
	"mp_forcecamera", 
#ifdef CSTRIKE
	"0", 
#else
	"1",
#endif
	FCVAR_REPLICATED,
	"Restricts spectator modes for dead players"
#ifdef GAME_DLL
	, MPForceCameraCallback 
#endif
	);
	
ConVar mp_allowspectators(
	"mp_allowspectators", 
	"1.0", 
	FCVAR_REPLICATED,
	"toggles whether the server allows spectator mode or not" );

ConVar friendlyfire(
	"mp_friendlyfire",
	"0",
	FCVAR_REPLICATED | FCVAR_NOTIFY,
	"Allows team members to injure other members of their team"
	);

#if defined( TF_CLIENT_DLL ) || defined( TF_DLL )
ConVar tf_round_end_friendlyfire(
	"tf_round_end_friendlyfire",
	"0",
	FCVAR_REPLICATED | FCVAR_NOTIFY,
	"Allows team members to injure other members of their team after a win.\n"
	"  0 = FF Off (Normal TF2 functionality)\n"
	"  1 = FF On (Post-round Friendly Fire is fully enabled. Kill 'em all!)\n"
	"  2 = FF On (Same as 1, but friendly player collisions also gets enabled)"
	);

//-----------------------------------------------------------------------------
// Purpose: Teammates should be able to murder each other once the round is over,
//			because it's fucking hilarious. - Saint
//-----------------------------------------------------------------------------
bool CTFGameRules::ShouldForceFriendlyFire( void )
{
	return tf_round_end_friendlyfire.GetBool() && RoundHasBeenWon();
}

//-----------------------------------------------------------------------------
// Purpose: Narrower than ShouldForceFriendlyFire() above - only true at cvar
//			value 2. Gates teammate-vs-teammate movement collision specifically
//			separately from damage/effects. This is done so that if a server
//			operator chooses to enable such things as shield collisions,
//			setting the value to 2 will do so for that scenario. 
//			However, it can make players get stuck inside one another when
//			the round ends, so keep that in mind - Saint
//-----------------------------------------------------------------------------
bool CTFGameRules::ShouldForceFriendlyFireCollision( void )
{
	return tf_round_end_friendlyfire.GetInt() >= 2 && RoundHasBeenWon();
}
#endif

ConVar mp_fadetoblack( 
	"mp_fadetoblack", 
	"0", 
	FCVAR_REPLICATED | FCVAR_NOTIFY, 
	"fade a player's screen to black when he dies" );


ConVar sv_hudhint_sound( "sv_hudhint_sound", "1", FCVAR_REPLICATED );
