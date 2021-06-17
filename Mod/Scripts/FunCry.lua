--
-- FunCry
-- 
-- FunCry is licensed under the FunCry license
--

Input:BindCommandToKey( "#Game:FunCry_IncrementSlot( )"       , "Up"    , 1 );
Input:BindCommandToKey( "#Game:FunCry_StartEffectManually( )" , "Right" , 1 );
Input:BindCommandToKey( "#Game:FunCry_DecrementSlot( )"       , "Down"  , 1 );
Input:BindCommandToKey( "#Game:FunCry_ToggleSlot( )"          , "Left"  , 1 );

FunCry = {
  Crosshair = 1,
  FOWS = { },
};

function FunCry:SetFOV( val )
  Game:FunCry_Log( "LUA | SetFOV( " .. tostring( val ) .. " )" );
	Game:SetCameraFov( val );
	if ZoomView and ZoomView.NoZoom ~= nil then
		ZoomView.NoZoom = val;
	end
end

function FunCry:DoCrosshair( val )
  Game:FunCry_Log( "LUA | DoCrosshair( " .. tostring( val ) .. " )" );
	FunCry.Crosshair = val;
end

function FunCry:FOWSBackup( ) -- perhaps calling this early before the Hud has initialized fully results in the bug?
  Game:FunCry_Log( "LUA | FOWSBackup(  )" );
  FunCry.FOWS.leftx      = Hud.FarOut.leftx;
  FunCry.FOWS.lefty      = Hud.FarOut.lefty;
  FunCry.FOWS.scalewidth = Hud.FarOut.scalewidth;
  FunCry.FOWS.scalex     = Hud.FarOut.scalex;
  FunCry.FOWS.rightoffl  = Hud.FarOut.rightoffl;
  FunCry.FOWS.rightoffr  = Hud.FarOut.rightoffr;
  FunCry.FOWS.rightx     = Hud.FarOut.rightx;
  FunCry.FOWS.righty     = Hud.FarOut.righty;
end

function FunCry:FOWSRestore( )
  Game:FunCry_Log( "LUA | FOWSRestore(  )" );
  Hud.FarOut.leftx      = FunCry.FOWS.leftx;
  Hud.FarOut.lefty      = FunCry.FOWS.lefty;
  Hud.FarOut.scalewidth = FunCry.FOWS.scalewidth;
  Hud.FarOut.scalex     = FunCry.FOWS.scalex;
  Hud.FarOut.rightoffl  = FunCry.FOWS.rightoffl;
  Hud.FarOut.rightoffr  = FunCry.FOWS.rightoffr;
  Hud.FarOut.rightx     = FunCry.FOWS.rightx;
  Hud.FarOut.righty     = FunCry.FOWS.righty;
end

function FunCry:DoFOWS( val )
  Game:FunCry_Log( "LUA | DoFOWS( " .. tostring( val ) .. " )" );
	if val == 0 then
    FunCry:FOWSBackup( );
    Hud.FarOut.leftx      = 0;
    Hud.FarOut.lefty      = 0;
    Hud.FarOut.scalewidth = 1;
    Hud.FarOut.scalex     = 0;
    Hud.FarOut.rightoffl  = 0;
    Hud.FarOut.rightoffr  = 0;
    Hud.FarOut.rightx     = 0;
    Hud.FarOut.righty     = 0;
  elseif val == 1 then
    FunCry:FOWSRestore( );
  end
end

function FunCry:AltHUD( Lx , Ly , Rx , Ry , Sx , Sw )
  Game:FunCry_Log( "LUA | AltHUD( " .. tostring( Lx ) .. " , " .. tostring( Ly ) .. " , " .. tostring( Rx ) .. " , " .. tostring( Ry ) .. " , " .. tostring( Sx ) .. " , " .. tostring( Sw ) .. " )" );
  Hud.FarOut.leftx  = Lx;
  Hud.FarOut.lefty  = Ly;
  Hud.FarOut.rightx = Rx;
  Hud.FarOut.righty = Ry;
  if Sx ~= nil then
    if type( Sx ) == "number" and Sx >= 0 then
      Hud.FarOut.scalex = Sx;
    end
  end
  if Sw ~= nil then
    if type( Sw ) == "number" and Sw >= 0 then
      Hud.FarOut.scalewidth = Sw;
    end
  end
end

function FunCry:CIAWork( val )
  Game:FunCry_Log( "LUA | CIAWork( " .. tostring( val ) .. " )" );
  if val == 0 then
    Hud.DrawRadar = FunCry.DrawRadarOLD;
  elseif val == 1 then
    FunCry.DrawRadarOLD = Hud.DrawRadar;
    Hud.DrawRadar = FunCry.DrawRadar;
  end
end

function FunCry:DrawRadar( x , y , w , h )
	if hud_disableradar == "1" then
		return
	end

	local LocalPlayer = _localplayer;
	local LocalPlayerPos = LocalPlayer:GetPos();
	local FrameTime = _frametime;

	-- indoor/outdoor ?
	if System:IsPointIndoors( LocalPlayerPos ) then
		Hud:SetRadarRange( tonumber( g_RadarRangeIndoor ) );
	else
		Hud:SetRadarRange( tonumber( g_RadarRangeOutdoor ) );
	end

	-- adjust range
	if ( Hud.DestinationRadarRange and ( tonumber( Hud.DestinationRadarRange ) ~= tonumber( g_RadarRange ) ) and ( FrameTime < 1 ) and ( tonumber( g_RadarRangeChangeSpeed ) > 0 ) ) then
		g_RadarRange = tonumber( g_RadarRange ) + ( tonumber( Hud.DestinationRadarRange ) - tonumber( g_RadarRange ) ) * FrameTime * tonumber( g_RadarRangeChangeSpeed );
		g_SuspenseRange = g_RadarRange;
	end

	-- Make Sure Players table is empty.
	for i, Player in Hud.tblPlayers do
		Hud.tblPlayers[ i ] = nil;
	end

	-- enemy data..
	Game:GetPlayerEntitiesInRadius( LocalPlayerPos , 240 , Hud.tblPlayers , 1 );

	-- Used for setting moods in DynamicMusic.
	Hud.EnemyInSuspense = 0;
	Hud.EnemyInNearSuspense = 0;
	Hud.EnemyAlerted = 0;
	local SuspenseRange2 = tonumber( g_SuspenseRange ) * tonumber( g_SuspenseRange );
	local NearSuspenseRange2 = SuspenseRange2 * tonumber( g_NearSuspenseRangeFactor ) * tonumber( g_NearSuspenseRangeFactor );

	-- radar fade in/out
	local alpha_step = 0.5;
	Hud.radar_transparency = Hud.radar_transparency - alpha_step * FrameTime;
	if Hud.radar_transparency < 0 then
		Hud.radar_transparency = 0;
	end

	if ( Hud.tblPlayers and type( Hud.tblPlayers ) == "table" ) then
		for i, Player in Hud.tblPlayers do
			if Player.pEntity == LocalPlayer then -- is player ?
				Hud:SetPlayerColor( Player , 0 , 0.9 , 0.8 , Hud.radar_transparency );
			elseif Player.pEntity.Properties.species == LocalPlayer.Properties.species then	--is enemy of friend ?
				-- radar fade in
		    local alpha_step = 1.0;
		    Hud.radar_transparency = Hud.radar_transparency + alpha_step * _frametime;
		    if Hud.radar_transparency > 1.0 then
		    	Hud.radar_transparency = 1.0;
		    end

				-- check if in mp mode..
				if Game:IsMultiplayer( ) then
				else
					Hud:SetPlayerColor( Player , 1.0 , 0.8 , 1.0 , Hud.radar_transparency );
				end
			else
				if Player.fDistance2 < SuspenseRange2 then
					Hud.EnemyInSuspense = 1;
				end
				if Player.fDistance2 < NearSuspenseRange2 then
					Hud.EnemyInNearSuspense = 1;
				end

			  -- radar fade in
			  local alpha_step = 1.0;
			  Hud.radar_transparency = Hud.radar_transparency + alpha_step * FrameTime;
			  if Hud.radar_transparency > 1.0 then
		      	Hud.radar_transparency = 1.0;
			  end

				-- if saw player, then always in combat mode
				if Player.pEntity.bEnemyInCombat == 1 then
				else
					local Target = AI:GetAttentionTargetOf( Player.pEntity.id );
					local TargetType = type( Target );
					Player.pEntity.bEnemyInCombat = 0;	-- set default
					
					if TargetType == "table" and Target == LocalPlayer then
						Hud.EnemyAlerted = 1;
						Player.pEntity.bEnemyInCombat = 1;
					elseif TargetType == "number" then
					 	if Target == AIOBJECT_DUMMY then
					 		if Player.pEntity.Behaviour.JOB == nil then
								Hud.EnemyAlerted = 1;
						  end
						end
					end
				end
			end
		end

    -- get/set radar objective
		local RadarPosition = "NoObjective";

		-- update objective blinking
		if Hud.bBlinkObjective >= 1 then
			Hud.fBlinkObjectiveUpdate = Hud.fBlinkObjectiveUpdate + 5 * _frametime;
			if Hud.fBlinkObjectiveUpdate > 1 then
				Hud.fBlinkObjectiveUpdate = 0;
				Hud.bBlinkObjective = Hud.bBlinkObjective + 1;
				if Hud.bBlinkObjective > 6 * 3 then
					Hud.bBlinkObjective = 0;
				end
			end
		else
			Hud.fBlinkObjectiveUpdate = 0;
		end

		if Hud.radarObjective ~= nil and ( Hud.bBlinkObjective == 0 or Hud.fBlinkObjectiveUpdate > 0.5 ) then
		  RadarPosition= format( "%g %g %g" , Hud.radarObjective.x , Hud.radarObjective.y , Hud.radarObjective.z );
		end

		Game:DrawRadar( x , y , w , h , tonumber( g_RadarRange ) , Hud.Radar , Hud.RadarMask , Hud.RadarPlayerIcon , Hud.RadarEnemyInRangeIcon , Hud.RadarEnemyOutRangeIcon , Hud.RadarSoundIcon , Hud.RadarObjectiveIcon , Hud.tblPlayers , RadarPosition );
	end
end

function FunCry:CHECK_SW( )
  if ( Hud ~= nil ) and ( Hud.FarOut ~= nil ) and (Hud.FarOut.scalewidth ~= nil) then
    Game:FunCry_Log( "** SW == " .. tostring( Hud.FarOut.scalewidth ) );

    if Hud.FarOut.scalewidth == 0 then
      Hud.FarOut.scalewidth = ( 4 / 3 ) / ( getglobal( "r_Width" ) / getglobal( "r_Height" ) );
      Game:FunCry_Log( "** SW has been reset" );
    end

  else
    Game:FunCry_Log( "** SW is not available" );
  end
end