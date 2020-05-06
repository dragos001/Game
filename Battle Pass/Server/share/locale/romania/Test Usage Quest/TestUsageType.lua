quest test_battle_pass begin
	state start begin
		when login begin
			pc.do_mission(13, 2) -- Type Mission and Counts Receive
		end
	end
end