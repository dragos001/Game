// search 

		if (iGold != 0)
		{
			iTotalGold += iGold; // Total gold

			for (int i = 0; i < iSplitCount; ++i)
			{
				if (isAutoLoot)
				{
					pkAttacker->GiveGold(iGold / iSplitCount);
				}
				else if ((item = ITEM_MANAGER::instance().CreateItem(1, iGold / iSplitCount)))
				{
					pos.x = GetX() + (number(-7, 7) * 20);
					pos.y = GetY() + (number(-7, 7) * 20);

					item->AddToGround(GetMapIndex(), pos);
					item->StartDestroyEvent();
				}
			}
		}
	}
	
// replace with 

		if (iGold != 0)
		{
			iTotalGold += iGold; // Total gold

			for (int i = 0; i < iSplitCount; ++i)
			{
#ifdef __BATTLE_PASS__
				if (!pkAttacker->v_counts.empty())
				{
					for (int i=0; i<pkAttacker->missions_bp.size(); ++i)
					{
						if (pkAttacker->missions_bp[i].type == 9){	pkAttacker->DoMission(i, iGold / iSplitCount);}
					}
				}
#endif
				if (isAutoLoot)
				{
					pkAttacker->GiveGold(iGold / iSplitCount);
				}
				else if ((item = ITEM_MANAGER::instance().CreateItem(1, iGold / iSplitCount)))
				{
					pos.x = GetX() + (number(-7, 7) * 20);
					pos.y = GetY() + (number(-7, 7) * 20);

					item->AddToGround(GetMapIndex(), pos);
					item->StartDestroyEvent();
				}
			}
		}
	}
	
// search 

	if (true == IsMonster() && 2493 == GetMobTable().dwVnum)
	{
		if (NULL != pkKiller && NULL != pkKiller->GetGuild())
		{
			CDragonLairManager::instance().OnDragonDead( this, pkKiller->GetGuild()->GetID() );
		}
		else
		{
			sys_err("DragonLair: Dragon killed by nobody");
		}
	}
	
// add lower
#ifdef __BATTLE_PASS__
	if (pkKiller && GetRaceNum() > 100)
	{
		if (!pkKiller->v_counts.empty())
		{
			for (int i=0; i<pkKiller->missions_bp.size(); ++i)
			{
				if (GetRaceNum() == pkKiller->missions_bp[i].vnum && pkKiller->missions_bp[i].type == 2)
				{
					pkKiller->DoMission(i, 1);
				}
			}
		
		}
	}
#endif

// search 

		//최종 데미지 보정
		float damMul = this->GetDamMul();
		float tempDam = dam;
		dam = tempDam * damMul + 0.5f;
		
// add lower
#ifdef __BATTLE_PASS__
		if (!pAttacker->v_counts.empty() && pAttacker->IsPC())
		{
			for (int i=0; i<pAttacker->missions_bp.size(); ++i)
			{
				if (pAttacker->missions_bp[i].type == 7 && !this->IsPC()){	pAttacker->DoMission(i, dam);}
				if (pAttacker->missions_bp[i].type == 8 && this->IsPC()){	pAttacker->DoMission(i, dam);}
				if (pAttacker->missions_bp[i].type == 11 && this->IsPC() && dam >= pAttacker->missions_bp[i].count){	pAttacker->DoMission(i, dam);}
			}
		}
#endif
