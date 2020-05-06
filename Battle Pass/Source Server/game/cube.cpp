// search

	// 제조시 필요한 골드 차감
	if (0 < cube_proto->gold)
		ch->PointChange(POINT_GOLD, -(cube_proto->gold), false);
	
// add lower
#ifdef __BATTLE_PASS__
	if (!ch->v_counts.empty())
	{
		for (int i=0; i<ch->missions_bp.size(); ++i)
		{
			if (ch->missions_bp[i].type == 5)
			{
				ch->DoMission(i, 1);
			}
		}
	}
#endif