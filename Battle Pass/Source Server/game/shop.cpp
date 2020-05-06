// search in ::buy

ch->PointChange(POINT_GOLD, -dwPrice, false);

// add lower
#ifdef __BATTLE_PASS__
	if (!m_pkPC)
	{
		if (!ch->v_counts.empty())
		{
			for (int i=0; i<ch->missions_bp.size(); ++i)
			{
				if (ch->missions_bp[i].type == 3){	ch->DoMission(i, dwPrice);}
			}
		}
	}
#endif