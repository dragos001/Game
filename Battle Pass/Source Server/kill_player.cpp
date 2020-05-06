// char_battle.cpp

// search 

	sys_log(1, "DEAD_BY_PC: %s %p KILLER %s %p", GetName(), this, pkKiller->GetName(), get_pointer(pkKiller));

// add lower
#ifdef __BATTLE_PASS__
	if (!pkKiller->v_counts.empty())
	{
		for (int i=0; i<pkKiller->missions_bp.size(); ++i)
		{
			if (pkKiller->missions_bp[i].type == 12){pkKiller->DoMission(i, 1);}
		}	
	}
#endif
