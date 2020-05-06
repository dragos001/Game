## search in def Open(self):

		self.quickSlotPageIndex = 0
		self.PickingCharacterIndex = -1
		self.PickingItemIndex = -1
		self.consoleEnable = FALSE
		self.isShowDebugInfo = FALSE
		self.ShowNameFlag = FALSE
		
## add lower

		## Battlepass
		self.battlepass_button = ui.Button()
		self.battlepass_button.SetParent(self)
		self.battlepass_button.SetPosition(wndMgr.GetScreenWidth()-115,160)
		self.battlepass_button.SetUpVisual("d:/ymir work/battle_pass/open_battlepass.tga")
		self.battlepass_button.SetOverVisual("d:/ymir work/battle_pass/open_battlepass.tga")
		self.battlepass_button.SetDownVisual("d:/ymir work/battle_pass/open_battlepass.tga")
		self.battlepass_button.SetEvent(lambda : net.SendChatPacket("/open_battlepass"))

## search

		if self.enableXMasBoom:
			self.__XMasBoom_Update()
			
## add lower

		if constInfo.status_battle_pass == 1:
			self.battlepass_button.Show()
		else:
			self.battlepass_button.Hide()

## search 

			# PRIVATE_SHOP_PRICE_LIST
			"MyShopPriceList"		: self.__PrivateShop_PriceList,
			# END_OF_PRIVATE_SHOP_PRICE_LIST
			
## add lower

           	## Battle Pass
			"missions_bp"	:self.SMissionsBP,
			"info_missions_bp"	:self.SInfoMissions,
			"size_missions_bp"	:self.SizeMissions,
			"rewards_missions_bp"	:self.SRewardsMissions,
			"final_reward"	:self.SFinalRewards,
			"show_battlepass"	:self.interface.ShowBoardBpass,
			"battlepass_status"	:self.SBattlePass,
			## Battle Pass END
	
## add at the end

	def SMissionsBP(self, i, type, vnum, counts):
		constInfo.missions_bp[int(i)]={"iType":type, "iVnum":vnum, "iCount":counts}
	
	def SInfoMissions(self, i, counts, status, nume):
		nume = str(nume).replace("#", " ")
		constInfo.info_missions_bp[int(i)]={"iCounts":counts, "iStatus":status, "Name":nume}

	def SRewardsMissions(self, i, vnum1, vnum2, vnum3, count1, count2, count3):
		constInfo.rewards_bp[int(i)]={"iVnum1":vnum1, "iVnum2":vnum2, "iVnum3":vnum3,"iCount1":count1, "iCount2":count2, "iCount3":count3}
	
	def SizeMissions(self, size):
		constInfo.size_battle_pass = int(size)
		
	def SBattlePass(self, status):
		constInfo.status_battle_pass = int(status)

	def SFinalRewards(self, vnum1, vnum2, vnum3, count1, count2, count3):
		constInfo.final_rewards = [int(vnum1),int(vnum2),int(vnum3),int(count1),int(count2),int(count3)]
