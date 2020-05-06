// search 

	int pc_has_master_skill(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		bool bHasMasterSkill = false;
		for (int i=0; i< SKILL_MAX_NUM; i++)
			if (ch->GetSkillMasterType(i) >= SKILL_MASTER && ch->GetSkillLevel(i) >= 21)
			{
				bHasMasterSkill = true;
				break;
			}

		lua_pushboolean(L, bHasMasterSkill);
		return 1;
	}
	
// add lower
#ifdef __BATTLE_PASS__
	int pc_do_battle_pass(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		if (!ch)
			return 0;
		
		if (ch->v_counts.empty())
			return 0;
		
		if (!ch->v_counts.empty())
		{
			for (int i=0; i<ch->missions_bp.size(); ++i)
			{
				if (ch->missions_bp[i].type == (int)lua_tonumber(L, 1)){	ch->DoMission(i, (DWORD)lua_tonumber(L, 2));}
			}
		}
		return 1;
	}
#endif
// search 

{ "has_master_skill",	pc_has_master_skill	},

// add lower

#ifdef __BATTLE_PASS__
{ "do_mission",	pc_do_battle_pass	},
#endif
