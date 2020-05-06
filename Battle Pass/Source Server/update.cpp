// search in cmd_general.cpp

	ch->ChatPacket(CHAT_TYPE_COMMAND, "final_reward %d %d %d %d %d %d", ch->final_rewards[0].f_vnum1, ch->final_rewards[0].f_vnum2, ch->final_rewards[0].f_vnum3, ch->final_rewards[0].f_count1, ch->final_rewards[0].f_count2 ,ch->final_rewards[0].f_count3);

// add lower

	ch->ChatPacket(CHAT_TYPE_COMMAND, "show_battlepass");

// go in System_Battlepass.cpp and add at the end of this function: void CHARACTER::Load_BattlePass()

	ChatPacket(CHAT_TYPE_COMMAND, "battlepass_status %d", 1);
	
// go in char_item.cpp

// search in CHARACTER::UseItemEx

	if (-1 != iLimitRealtimeStartFirstUseFlagIndex)
	{
		if (0 == item->GetSocket(1))
		{
			long duration = (0 != item->GetSocket(0)) ? item->GetSocket(0) : item->GetProto()->aLimits[iLimitRealtimeStartFirstUseFlagIndex].lValue;

			if (0 == duration)
				duration = 60 * 60 * 24 * 7;

			item->SetSocket(0, time(0) + duration);
			item->StartRealTimeExpireEvent();
		}	

		if (false == item->IsEquipped())
			item->SetSocket(1, item->GetSocket(1) + 1);
	}
	
// add lower

#ifdef __BATTLE_PASS__
	if (!v_counts.empty())
	{
		for (int i=0; i<missions_bp.size(); ++i)
		{
			if (missions_bp[i].type == 1 && item->GetVnum() == missions_bp[i].vnum)
			{
				DoMission(i, 1);
			}
		}
	}
#endif
