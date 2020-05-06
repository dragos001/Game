// search 

							case ITEM_ELK_VNUM: // 돈꾸러미
								{
									int iGold = item->GetSocket(0);
									ITEM_MANAGER::instance().RemoveItem(item);
									ChatPacket(CHAT_TYPE_INFO, LC_TEXT("돈 %d 냥을 획득했습니다."), iGold);
									PointChange(POINT_GOLD, iGold);
								}
								break;
								
// add lower
#ifdef __BATTLE_PASS__
							case ITEM_BATTLE_PASS: 
								{
									if (!v_counts.empty())
									{
										ChatPacket(CHAT_TYPE_INFO, "You have already one active!");
										return false;
									}
									
									FILE 	*fileID;
									char file_name[256+1];

									snprintf(file_name, sizeof(file_name), "%s/battlepass_players/%s.txt", LocaleService_GetBasePath().c_str(),GetName());
									fileID = fopen(file_name, "w");
									
									if (NULL == fileID)
										return false;

									for (int i=0; i<missions_bp.size(); ++i)
									{
										fprintf(fileID,"MISSION	%d	%d\n", 0, 0);
									}
									
									fclose(fileID);

									Load_BattlePass();
									ChatPacket(CHAT_TYPE_INFO, "You activate battle pass for this month!");
									item->SetCount(item->GetCount() - 1);
								}
								break;
#endif
