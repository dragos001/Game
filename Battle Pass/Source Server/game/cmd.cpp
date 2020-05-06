// search 

ACMD(do_stun);

// add lower
#ifdef __BATTLE_PASS__
ACMD(final_reward_battlepass);
ACMD(open_battlepass);
#endif
// search 

	{ "stun",		do_stun,		0,			POS_DEAD,	GM_LOW_WIZARD	},

// add lower
#ifdef __BATTLE_PASS__
	{ "open_battlepass",		open_battlepass,		0,			POS_DEAD,	GM_PLAYER	},
	{ "final_reward_battlepass",		final_reward_battlepass,		0,			POS_DEAD,	GM_PLAYER	},
#endif