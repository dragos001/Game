#importă asta

import uibattlepass

## caută 

	def __MakeCubeResultWindow(self):
		self.wndCubeResult = uiCube.CubeResultWindow()
		self.wndCubeResult.LoadWindow()
		self.wndCubeResult.Hide()

## adaugă sub 

	def __BoardBpass(self):
		self.wndbpass = uibattlepass.Battlepass()
		self.wndbpass.LoadWindow()
		self.wndbpass.Hide()
		
## caută 

		self.__MakeCubeResultWindow()

## adaugă sub 

		self.__BoardBpass()

## caută 

		if self.wndChat:
			self.wndChat.Destroy()
			
## adaugă sub 

		if self.wndbpass:
			self.wndbpass.Destroy()
			
## caută 

		del self.inputDialog

## adaugă sub 

		del self.wndbpass
	
## caută 

	def OpenCubeWindow(self):
		self.wndCube.Open()
		if FALSE == self.wndInventory.IsShow():
			self.wndInventory.Show()
			self.wndExpandedMoney.Show()
			
## adaugă sub 

	def ShowBoardBpass(self):
		self.wndbpass.Show()
