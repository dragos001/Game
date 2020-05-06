// caută 

	_send_bonus_info(ch);
	
// adaugă sub 
#ifdef __BATTLE_PASS__
	ch->ExternBattlePass();
	ch->Load_BattlePass();
#endif

