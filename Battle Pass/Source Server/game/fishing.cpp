// search 

			case 0:
				//ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("고기가 잡혔습니다! (%s)"), fish_info[info->fish_id].name);
				if (item_vnum)
				{
					FishingSuccess(ch);
					if(quest::CQuestManager::instance().GetEventFlag("enable_fish_event"))
					{
						if (ch->IsEquipUniqueItem(UNIQUE_ITEM_FISH_MIND))
						{
							int r = number(1, 100);
							if(r <= 10)
								ch->AutoGiveItem(ITEM_FISH_EVENT_BOX_SPECIAL, 1, -1, false);
							else
								ch->AutoGiveItem(ITEM_FISH_EVENT_BOX, 5, -1, false);
						}
						else
						{
							ch->AutoGiveItem(ITEM_FISH_EVENT_BOX, 5, -1, false);
						}
					}
					
// add lower
#ifdef __BATTLE_PASS__
					if (!ch->v_counts.empty())
					{
						for (int i=0; i<ch->missions_bp.size(); ++i)
						{
							if (ch->missions_bp[i].type == 6){	ch->DoMission(i, 1);}
						}
					}
#endif