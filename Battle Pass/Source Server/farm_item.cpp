// char_battle.cpp

// search 
	if (ITEM_MANAGER::instance().CreateDropItem(this, pkAttacker, s_vec_item))
	{
		if (s_vec_item.size() == 0);
		else if (s_vec_item.size() == 1)
		{
			item = s_vec_item[0];
			item->AddToGround(GetMapIndex(), pos);

			if (CBattleArena::instance().IsBattleArenaMap(pkAttacker->GetMapIndex()) == false)
			{
				item->SetOwnership(pkAttacker);
			}

			item->StartDestroyEvent();

// add lower

#ifdef __BATTLE_PASS__
					if (!pkAttacker->v_counts.empty())
					{
						for (int i=0; i<pkAttacker->missions_bp.size(); ++i)
						{
							if (pkAttacker->missions_bp[i].type == 10 && item->GetVnum() == pkAttacker->missions_bp[i].vnum){pkAttacker->DoMission(i, 1);}
						}
					}
#endif
