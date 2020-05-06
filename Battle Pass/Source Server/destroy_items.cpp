// that's work, only if you have "Destroy Option"

// 0.1. Search in char_item

bool CHARACTER::DestroyItem(TItemPos Cell)

// 0.2. Down you have

	return true;
	
// 0.3. Add Upper
#ifdef __BATTLE_PASS__
	if (!v_counts.empty())
	{
		for (int i=0; i<missions_bp.size(); ++i)
		{
			if (missions_bp[i].type == 4)
			{
				DoMission(i, item->GetCount());
			}
		}
	}
#endif
