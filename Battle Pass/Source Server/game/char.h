// search 

};

ESex GET_SEX(LPCHARACTER ch);

// add before :

#ifdef __BATTLE_PASS__
	public:
		int iMonthBattlePass;
		struct Struct_BattlePass{DWORD	count;	DWORD	status;};
		void	Load_BattlePass();
		void	ExternBattlePass();
		void	DoMission(int index, long long count);
		void	SendInfosBattlePass(int index);
		void	FinalRewardBattlePass();
		struct Infos_BattlePass{DWORD	vnum1;	DWORD	count1;	DWORD	vnum2;
								DWORD	count2;	DWORD	vnum3;	DWORD	count3;
		char	name[4096];};
		struct Infos_MissionsBP{DWORD	type;	DWORD	vnum;	DWORD	count;};
		struct Infos_FinalBP{DWORD	f_vnum1;	DWORD	f_count1;	DWORD	f_vnum2;
							 DWORD	f_count2;	DWORD	f_vnum3;	DWORD	f_count3;};
		std::vector<Struct_BattlePass> v_counts;
		std::vector<Infos_BattlePass> rewards_bp;
		std::vector<Infos_MissionsBP> missions_bp;
		std::vector<Infos_FinalBP> final_rewards;
#endif
