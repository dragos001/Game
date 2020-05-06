// add at the end
#ifdef __BATTLE_PASS__
ACMD(open_battlepass)
{
	if (ch->v_counts.empty())
		return;

	if (ch->missions_bp.empty())
		return;

	if (ch->IsOpenSafebox() || ch->IsDead() || ch->GetExchange() || ch->GetMyShop())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Nu poti face asta!");
		return;
	}

	time_t cur_Time = time(NULL);
	struct tm vKey = *localtime(&cur_Time);

	int month = vKey.tm_mon;
	
	if (month != ch->iMonthBattlePass)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Time Expire!");
		return;
	}

	for (int i=0; i<ch->missions_bp.size(); ++i)
	{
		ch->ChatPacket(CHAT_TYPE_COMMAND, "missions_bp %d %d %d %d", i, ch->missions_bp[i].type, ch->missions_bp[i].vnum, ch->missions_bp[i].count);
		ch->ChatPacket(CHAT_TYPE_COMMAND, "info_missions_bp %d %d %d %s", i, ch->v_counts[i].count, ch->v_counts[i].status, ch->rewards_bp[i].name);
		ch->ChatPacket(CHAT_TYPE_COMMAND, "rewards_missions_bp %d %d %d %d %d %d %d", i, ch->rewards_bp[i].vnum1, ch->rewards_bp[i].vnum2, ch->rewards_bp[i].vnum3, ch->rewards_bp[i].count1, ch->rewards_bp[i].count2 ,ch->rewards_bp[i].count3);
	}

	ch->ChatPacket(CHAT_TYPE_COMMAND, "size_missions_bp %d ", ch->missions_bp.size());
	ch->ChatPacket(CHAT_TYPE_COMMAND, "final_reward %d %d %d %d %d %d", ch->final_rewards[0].f_vnum1, ch->final_rewards[0].f_vnum2, ch->final_rewards[0].f_vnum3, ch->final_rewards[0].f_count1, ch->final_rewards[0].f_count2 ,ch->final_rewards[0].f_count3);

}

ACMD(final_reward_battlepass)
{
	if (ch->v_counts.empty())
		return;

	if (ch->missions_bp.empty())
		return;

	if (ch->v_counts[0].status == 2)
		return;

	if (ch->IsOpenSafebox() || ch->IsDead() || ch->GetExchange() || ch->GetMyShop())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Nu poti face asta!");
		return;
	}

	time_t cur_Time = time(NULL);
	struct tm vKey = *localtime(&cur_Time);

	int month = vKey.tm_mon;
	
	if (month != ch->iMonthBattlePass)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Time Expire!");
		return;
	}

	for (int i=0; i<ch->missions_bp.size(); ++i)
	{
		if (ch->missions_bp[i].count != ch->v_counts[i].count)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "Nu ai completat toate misiunile!");
			return;
		}
	}

	ch->FinalRewardBattlePass();
}
#endif
