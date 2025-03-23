local OrionLib = loadstring(game:HttpGet('https://pastebin.com/raw/XRNU6dHc'))()
local Window = OrionLib:MakeWindow({Name = "gold hub       [النسخه VIP]  ", HidePremium = false, SaveConfig = true, ConfigFolder = "OrionTest"})

--[[
Name = <string> - The name of the UI.
HidePremium = <bool> - Whether or not the user details shows Premium status or not.
SaveConfig = <bool> - Toggles the config saving in the UI.
ConfigFolder = <string> - The name of the folder where the configs are saved.
IntroEnabled = <bool> - Whether or not to show the intro animation.
IntroText = <string> - Text to show in the intro animation.
IntroIcon = <string> - URL to the image you want to use in the intro animation.
Icon = <string> - URL to the image you want displayed on the window.
CloseCallback = <function> - Function to execute when the window is closed.
]]
local Tab = Window:MakeTab({
	Name = "الصفحه الرئيسية",
	Icon = "rbxassetid://93059210162475",
	PremiumOnly = false
})
local Players = game:GetService("Players")
local player = Players.LocalPlayer

Tab:AddButton({
    Name = "هلا " .. player.Name,
    Callback = function()
        print("button pressed by " .. player.Name)
    end
})
Tab:AddButton({
	Name = "الصانع almaher11",
	Callback = function()
      		print("gold hub vip:)")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Section = Tab:AddSection({
	Name = "ادمن"
})
Tab:AddButton({
    Name = "طرد الكل",
    Callback = function() 
        tools = "FireX"
        shutdownserver = true
        if game.Players.LocalPlayer.Character.Humanoid.Sit == true then
            task.wait()
            game.Players.LocalPlayer.Character.Humanoid.Sit = false
        end
        if game:GetService("Workspace"):FindFirstChild("Camera") then
            game:GetService("Workspace"):FindFirstChild("Camera"):Destroy()
        end
        wait(0.1)
        if game:GetService("Workspace"):FindFirstChild("Camera") then
            game:GetService("Workspace"):FindFirstChild("Camera"):Destroy()
        end
        game:GetService("Players").LocalPlayer.Character.HumanoidRootPart.CFrame = game:GetService("Workspace").WorkspaceCom["001_GiveTools"].FireX.CFrame + Vector3.new(0, -15, 0)
        task.wait(0.2)
        game.Players.LocalPlayer.Character.HumanoidRootPart.Anchored = true
        ddos = true
        for i = 1, 1350 do
            task.wait()
            if ddos == false then
                local args = {
                    [1] = "ClearAllTools"
                }

                cleartoolremote:FireServer(unpack(args))
                game.Players.LocalPlayer.Character.HumanoidRootPart.Anchored = false
                game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(9999, -475, 9999)
                return
            end
            if game:GetService("Workspace"):FindFirstChild("Camera") then
                game:GetService("Workspace"):FindFirstChild("Camera"):Destroy()
            end
            if game:GetService("Players").LocalPlayer.Character:FindFirstChild(tools) then
                game:GetService("Players").LocalPlayer.Character:FindFirstChild(tools):Destroy()
            end
            if ddos == false then return end
            fireclickdetector(game:GetService("Workspace").WorkspaceCom["001_GiveTools"].FireX.ClickDetector, 0)
        end
        game.Players.LocalPlayer.Character.HumanoidRootPart.Anchored = false
        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(0, -475, 0)
    end    
})
Tab:AddButton({
	Name = "اسحب كل القطع الي تتحرك",
	Callback = function()
      		-- Services:

local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local Workspace = game:GetService("Workspace")

-- Variables:

local LocalPlayer = Players.LocalPlayer
local character
local humanoidRootPart
local blackHoleActive = false
local DescendantAddedConnection

-- Folder and Part Setup:

local Folder = Instance.new("Folder", Workspace)
local Part = Instance.new("Part", Folder)
local Attachment1 = Instance.new("Attachment", Part)
Part.Anchored = true
Part.CanCollide = false
Part.Transparency = 1

-- Global Network Setup:

if not getgenv().Network then
    getgenv().Network = {
        BaseParts = {},
        Velocity = Vector3.new(14.46262424, 14.46262424, 14.46262424)
    }

    Network.RetainPart = function(Part)
        if Part:IsA("BasePart") and Part:IsDescendantOf(Workspace) then
            table.insert(Network.BaseParts, Part)
            Part.CustomPhysicalProperties = PhysicalProperties.new(0, 0, 0, 0, 0)
            Part.CanCollide = false
        end
    end

    local function EnablePartControl()
        LocalPlayer.ReplicationFocus = Workspace
        RunService.Heartbeat:Connect(function()
            sethiddenproperty(LocalPlayer, "SimulationRadius", math.huge)
            for _, Part in pairs(Network.BaseParts) do
                if Part:IsDescendantOf(Workspace) then
                    Part.Velocity = Network.Velocity
                end
            end
        end)
    end

    EnablePartControl()
end

-- Function to Handle Parts:

local function ForcePart(v)
    if v:IsA("BasePart") and not v.Anchored and not v.Parent:FindFirstChildOfClass("Humanoid") and not v.Parent:FindFirstChild("Head") and v.Name ~= "Handle" then
        for _, x in ipairs(v:GetChildren()) do
            if x:IsA("BodyMover") or x:IsA("RocketPropulsion") then
                x:Destroy()
            end
        end
        if v:FindFirstChild("Attachment") then
            v:FindFirstChild("Attachment"):Destroy()
        end
        if v:FindFirstChild("AlignPosition") then
            v:FindFirstChild("AlignPosition"):Destroy()
        end
        if v:FindFirstChild("Torque") then
            v:FindFirstChild("Torque"):Destroy()
        end
        v.CanCollide = false
        local Torque = Instance.new("Torque", v)
        Torque.Torque = Vector3.new(100000, 100000, 100000)
        local AlignPosition = Instance.new("AlignPosition", v)
        local Attachment2 = Instance.new("Attachment", v)
        Torque.Attachment0 = Attachment2
        AlignPosition.MaxForce = math.huge
        AlignPosition.MaxVelocity = math.huge
        AlignPosition.Responsiveness = 200
        AlignPosition.Attachment0 = Attachment2
        AlignPosition.Attachment1 = Attachment1
    end
end

-- Toggle Function:

local function toggleBlackHole()
    blackHoleActive = not blackHoleActive
    if blackHoleActive then
        for _, v in ipairs(Workspace:GetDescendants()) do
            ForcePart(v)
        end

        DescendantAddedConnection = Workspace.DescendantAdded:Connect(function(v)
            if blackHoleActive then
                ForcePart(v)
            end
        end)

        spawn(function()
            while blackHoleActive and RunService.RenderStepped:Wait() do
                if humanoidRootPart then
                    Attachment1.WorldCFrame = humanoidRootPart.CFrame
                end
            end
        end)
    else
        if DescendantAddedConnection then
            DescendantAddedConnection:Disconnect()
        end
    end
end

-- Use LocalPlayer:

character = LocalPlayer.Character or LocalPlayer.CharacterAdded:Wait()
humanoidRootPart = character:WaitForChild("HumanoidRootPart")
toggleBlackHole()  -- This activates the black hole on the local player
  	end    
})

Tab:AddButton({
	Name = "صوت جوال اندرويد عالي ومزعج جدا",
	Callback = function()
      		local args = {
    [1] = "SkateBoard"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
local args = {
    [1] = "PickingScooterMusicText",
    [2] = "7288899492"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]                                 
--[[
Name = <string> - The name of the section.
]]

--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
local Tab = Window:MakeTab({
	Name = "الشخصية",
	Icon = "rbxassetid://17824305386",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "الحجم"
})
Tab:AddButton({
	Name = "حجم نمله",
	Callback = function()
      		local args = {
    [1] = "CharacterSizeDown",
    [2] = 2.4
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "حجم كبير جدا",
	Callback = function()
              local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 94995961629302,
        [2] = 100558822187663,
        [3] = 110711743190640,
        [4] = 91059998815242,
        [5] = 132096480597445,
        [6] = 0
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
local args = {
    [1] = "CharacterSizeDown",
    [2] = 1
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))
  	end   
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Section = Tab:AddSection({
	Name = "الاسم"
})
Tab:AddButton({
	Name = "اسم ملون",
	Callback = function()
      		while true do
    -- Generate random RGB values between 0 and 1
    local randomColor = Color3.new(math.random(), math.random(), math.random())

    -- Set up the arguments with the random color
    local args = {
        [1] = "PickingRPNameColor",
        [2] = randomColor
    }

    -- Fire the remote event with the new color
    game:GetService("ReplicatedStorage").RE:FindFirstChild("1RPNam1eColo1r"):FireServer(unpack(args))

    -- Wait for a short duration before changing the color again
    wait(0.5) -- Adjust the wait time as needed
end
  	end    
})
Tab:AddButton({
	Name = "قلب",
	Callback = function()
      		local args = {
    [1] = "RolePlayName",
    [2] = "\226\153\161"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1RPNam1eTex1t"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "اسم M طويل",
	Callback = function() 
local args = {
    [1] = "RolePlayName",
    [2] = "M\204\181\204\191\204\129\204\142\204\139\204\134\204\149\204\136\204\136\205\155\204\145\205\160\204\130\205\139\205\131\205\129\204\139\205\138\205\146\204\130\205\157\204\139\204\131\204\145\205\128\204\135\205\129\204\132\204\129\204\146\204\141\204\154\204\140\205\144\205\130\204\132\205\146\205\144\205\146\204\132\204\128\205\157\204\146\205\132\204\143\205\151\204\154\205\140\204\144\204\167\204\168\204\166\204\175\204\156\205\136\205\142\204\169\205\150\205\147\204\173\205\136\204\188\204\156\205\153\204\165\204\169\204\172\204\165\204\177\204\152\204\162\205\149\204\168\204\178\205\150\205\137\204\161\204\161\204\187\204\177\204\159\205\153\204\173\205\141\204\159\204\151\205\136\204\170\204\156\205\153"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1RPNam1eTex1t"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "اسم هكر كبير",
	Callback = function() 
local args = {
    [1] = "RolePlayName",
    [2] = "\202\156\204\180\205\132\204\141\205\145\204\157\204\164\204\173\205\135\225\180\128\204\181\204\155\204\154\204\136\204\156\204\164\205\136\204\164\204\176\205\137\204\163\225\180\132\204\181\205\132\204\144\204\139\204\144\204\189\204\142\205\135\205\149\205\148\204\159\205\148\225\180\139\204\183\204\131\205\146\205\155\204\148\204\134\205\130\204\145\204\136\205\133\204\151\204\186\204\164\205\135\204\156\225\180\135\204\180\204\135\205\145\204\128\205\130\204\145\204\166\204\186\205\142\204\158\202\128\204\184\204\134\204\143\204\128\205\155\205\130\204\148\205\131\204\176\205\156\204\176\204\166\204\176"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1RPNam1eTex1t"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "اسم ادمن كبير",
	Callback = function()
      		local args = {
    [1] = "RolePlayName",
    [2] = "A\204\182\204\155\205\130\204\140\204\149\204\128\204\138\204\146\204\140\204\168\204\176\204\172\205\135\204\175D\204\182\204\155\204\190\204\149\204\148\205\132\205\128\204\157\204\162\205\149\204\151\204\172\204\158M\204\181\205\134\205\133\205\153\204\152I\204\183\204\142\205\130\204\139\204\144\204\189\205\160\205\156N\204\181\204\131\204\140\205\157\205\144\205\132\205\132\205\157\205\132\204\189\205\136\204\163\204\174\204\170\205\135\205\148\204\179\204\166"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1RPNam1eTex1t"):FireServer(unpack(args))

  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
local Section = Tab:AddSection({
	Name = "الرجل المخفيه والهيدليس"
})
Tab:AddButton({
	Name = "رجل مخفيه",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 139607718,
        [2] = 139607718,
        [3] = 139607718,
        [4] = 139607718,
        [5] = 139607718,
        [6] = 0
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "هيدليس",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 1,
        [2] = 1,
        [3] = 1,
        [4] = 1,
        [5] = 1,
        [6] = 134082579
    },
    [3] = "Roblox20"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})
local Section = Tab:AddSection({
	Name = "قبابيع تطلع اصوات"
})
Tab:AddButton({
	Name = "قبوع يطلع صوت شرب",
	Callback = function()
      		local args = {
    [1] = "AskIfIdAvailable",
    [2] = "24114402"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "قبوع يطلع صوت دجاج",
	Callback = function()
      		local args = {
    [1] = "AskIfIdAvailable",
    [2] = "24112667"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))
 
  	end    
})
Tab:AddButton({
	Name = "قبوع يطلع صوت ضحكه",
	Callback = function()
      		local args = {
    [1] = "AskIfIdAvailable",
    [2] = "305888394"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "قبوع يطلع صوت اغنيه",
	Callback = function()
      		local args = {
    [1] = "AskIfIdAvailable",
    [2] = "33070696"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))
  	end    
})
local Section = Tab:AddSection({
	Name = "الطاقات الخارقه"
})
Tab:AddButton({
	Name = "ايد ناريه",
	Callback = function()
      		-- Get the player's character and initial position
local player = game.Players.LocalPlayer
local character = player.Character or player.CharacterAdded:Wait()
local initialPosition = character.HumanoidRootPart.Position
 
-- Define the destination position
local destination = Vector3.new(-347.7337646484375, 2.397120475769043, 98.97232818603516)
 
-- Teleport the character to the destination
character.HumanoidRootPart.CFrame = CFrame.new(destination)
 
wait(1)
 
 
fireclickdetector(Workspace.WorkspaceCom["001_Hospital"].PoolClick.ClickDetector)
 
wait(1)
 
-- Teleport the character back to the initial position
character.HumanoidRootPart.CFrame = CFrame.new(initialPosition)
  	end    
})
Tab:AddButton({
	Name = "طاقه زرقاء في الراس",
	Callback = function()
      		local args = {
    [1] = "wear",
    [2] = 183468963
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
local Tab = Window:MakeTab({
	Name = "الادوات",
	Icon = "rbxassetid://18284799027",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "ادوات ادمن"
})
Tab:AddButton({
	Name = "ادوات ادمن",
	Callback = function()
      		loadstring(game:HttpGet(('https://pastefy.app/VYIAk3o1/raw'),true))()
  	end    
})
local Tab = Window:MakeTab({
	Name = "متعه",
	Icon = "rbxassetid://5873794859",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "السيرفر"
})
Tab:AddButton({
	Name = "وقف السيرفر",
	Callback = function()
      		tools = "FireX"
		lagserver = true
		if game.Players.LocalPlayer.Character.Humanoid.Sit == true then
			task.wait()
			game.Players.LocalPlayer.Character.Humanoid.Sit = false
		end
		if game:GetService("Workspace"):FindFirstChild("Camera") then
			game:GetService("Workspace"):FindFirstChild("Camera"):Destroy() end
			wait(0.1)
		if game:GetService("Workspace"):FindFirstChild("Camera") then
		game:GetService("Workspace"):FindFirstChild("Camera"):Destroy() end
		game:GetService("Players").LocalPlayer.Character.HumanoidRootPart.CFrame = game:GetService("Workspace").WorkspaceCom["001_GiveTools"].FireX.CFrame + Vector3.new(0,-15,0)
task.wait(0.2)
game.Players.LocalPlayer.Character.HumanoidRootPart.Anchored = true
ddos = true
		for i=1, 425 do task.wait()
			if ddos == false then
				local args = {
					[1] = "ClearAllTools"
				}
				
				cleartoolremote:FireServer(unpack(args))
				 game.Players.LocalPlayer.Character.HumanoidRootPart.Anchored = false
				 game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(9999,-475,9999)
				 return
			end
			if game:GetService("Workspace"):FindFirstChild("Camera") then
				game:GetService("Workspace"):FindFirstChild("Camera"):Destroy() end
				if game:GetService("Players").LocalPlayer.Character:FindFirstChild(tools) then
					game:GetService("Players").LocalPlayer.Character:FindFirstChild(tools):Destroy() end
					if ddos == false then return end
			fireclickdetector(game:GetService("Workspace").WorkspaceCom["001_GiveTools"].FireX.ClickDetector,0)
			end
			game.Players.LocalPlayer.Character.HumanoidRootPart.Anchored = false
			game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(0,-475,0)
			wait(15)
			lagserver = false
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
local Section = Tab:AddSection({
	Name = "الشات"
})
Tab:AddButton({
	Name = "شات كذبي",
	Callback = function()
      		loadstring(game:HttpGet("https://raw.githubusercontent.com/game-hax/uca/main/release/uca.min.lua"))()
  	end    
})
Tab:AddButton({
	Name = "رسم في الشات تم التصليح (:",
	Callback = function()
     loadstring(game:HttpGet("https://pastebin.com/raw/Q5zhT6Mv"))()
  	end    
})
local Section = Tab:AddSection({
	Name = " سحب ومشي في الجدران و اختفاء"
})
Tab:AddButton({
	Name = "سحب",
	Callback = function()
      		wait(0.1) do
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-82.6174087524414, 19.262874603271484, -130.01634216308594)
end
wait(0.1) do
loadstring(game:HttpGet("https://rawscripts.net/raw/Universal-Script-Fling-gui-troll-17597"))()
end
  	end    
})
Tab:AddButton({
	Name = "مشي في الجدران",
	Callback = function()
      		loadstring(game:HttpGet("https://pastebin.com/raw/zXk4Rq2r"))()
  	end    
})
Tab:AddButton({
	Name = "اختفاء",
	Callback = function()
      		loadstring(game:HttpGet('https://pastebin.com/raw/3Rnd9rHf'))()
  	end    
})

local Section = Tab:AddSection({
	Name = " و نسخ سكنات وتطير بلكنب وتحريك الأشياء من بعيد"
})
Tab:AddButton({
	Name = "نسخ سكنات ",
	Callback = function()
      		--[[
	WARNING: Heads up! This script has not been verified by ScriptBlox. Use at your own risk!
]]
loadstring(game:HttpGet("https://raw.githubusercontent.com/REDzHUB/REDzHUB/main/REDzHUB"))()
  	end    
})
Tab:AddButton({
	Name = "تطير بلكنب",
	Callback = function()
      		loadstring(game:HttpGet("https://raw.githubusercontent.com/0Ben1/fe./main/Fling%20GUI"))()
  	end    
})
Tab:AddButton({
	Name = "تحريك من بعيد",
	Callback = function()
      		loadstring(game:HttpGet(('https://raw.githubusercontent.com/SAZXHUB/Control-update/main/README.md'),true))()
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Section = Tab:AddSection({
	Name = "كاميرات"
})
Tab:AddButton({
	Name = "كاميرا تحطها في اي مكان",
	Callback = function()
      		loadstring(game:HttpGet('https://raw.githubusercontent.com/GhostPlayer352/Test4/main/CCTV%20Camera'))()
  	end    
})
Tab:AddButton({
	Name = "كاميرا تشوف كل الناس",
	Callback = function()
      		loadstring(game:HttpGet('https://pastebin.com/raw/wyvdb7gr'))()
  	end    
})
local Section = Tab:AddSection({
	Name = "متعة البيوت"
})
Tab:AddButton({
	Name = "دائرات برتقاليه نارية كبيررهههه في البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Solar"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "تسونامي في البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Flood"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "ذبان في كل البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Bugs"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "زومبي في شبابيك وابواب البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Zombie"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "زلزال في البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Quake"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "ضلام في البيت كله",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Lights"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "جنيه تخوف البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Ghost"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "صواعق في البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Lightning"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "تفجيرات وطلق نار واصوات",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Explosives"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "فضائي يدور حول البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Alien"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "تسرب غاز يغطي البيت كله",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Gas"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "اوراق شجر تدور حول البيت",
	Callback = function()
      		local args = {
    [1] = "DisasterClientRequsting",
    [2] = "Wind"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Flyin1g"):FireServer(unpack(args))

  	end    
})
local Section = Tab:AddSection({
	Name = "المسدسات"
})
Tab:AddButton({
	Name = "مسدس يتلون",
	Callback = function()
      		while wait(0.1) do
wait(0.1) do
local args = {
    [1] = "RequestingGunSkins",
    [2] = "46152172"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))

end
wait(0.2) do
local args = {
    [1] = "RequestingGunSkins",
    [2] = "12144955212"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))

end
wait(0.1) do
local args = {
    [1] = "RequestingGunSkins",
    [2] = "10528731255"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))

end
wait(0.1) do
local args = {
    [1] = "RequestingGunSkins",
    [2] = "7020150509"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))

end
wait(0.1) do
local args = {
    [1] = "RequestingGunSkins",
    [2] = "1302869033"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))

end
wait(0.1) do
local args = {
    [1] = "RequestingGunSkins",
    [2] = "91010744044936"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))

end
end
  	end    
})
Tab:AddButton({
	Name = "مسدس يخوف",
	Callback = function()
      		local args = {
    [1] = "RequestingGunSkins",
    [2] = "668614178"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))

  	end    
})
local Section = Tab:AddSection({
	Name = "الفجعات"
})
Tab:AddButton({
	Name = "فجعة وجه بنت يخوف",
	Callback = function()
      		local args = {
    [1] = "SkateBoard"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
local args = {
    [1] = "wear",
    [2] = 18535682226
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
local args = {
    [1] = "PickingScooterMusicText",
    [2] = "5567523008"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Section = Tab:AddSection({
	Name = " اصوات تخوف وتضحك وعاليه"
})
Tab:AddButton({
	Name = "صوت ضحكه عالي",
	Callback = function()
      		local args = {
    [1] = "SkateBoard"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
local args = {
    [1] = "PickingScooterMusicText",
    [2] = "8449305114"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "صوت صراخ قرد",
	Callback = function()
      		local args = {
    [1] = "SkateBoard"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
local args = {
    [1] = "PickingScooterMusicText",
    [2] = "2473639958"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "صوت مكالمه مزعج",
	Callback = function()
      		local args = {
    [1] = "SkateBoard"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
local args = {
    [1] = "PickingScooterMusicText",
    [2] = "5686707484"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "صوت ضحك رجل عالي",
	Callback = function()
      		local args = {
    [1] = "SkateBoard"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
local args = {
    [1] = "PickingScooterMusicText",
    [2] = "374106817"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
  	end   
})
Tab:AddButton({
	Name = "صوت نباح",
	Callback = function()
      		local args = {
    [1] = "SkateBoard"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
local args = {
    [1] = "PickingScooterMusicText",
    [2] = "6831408050"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
local Tab = Window:MakeTab({
	Name = "تحولات",
	Icon = "rbxassetid://4483345998",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "اخفاء اجزاء الجسم"
})
Tab:AddButton({
	Name = "تبعيد الراس عن الجسم شوي بشكل يضحك",
	Callback = function()
      	local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 16367059899,
        [2] = 16367059899,
        [3] = 16367059899,
        [4] = 16367059899,
        [5] = 16367059899,
        [6] = 0
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "اخفاء اليد",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 18637111456,
        [2] = 18637111879,
        [3] = 18637113685,
        [4] = 18637113993,
        [5] = 18637111141,
        [6] = 0
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "اذرع كبيره",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 0,
        [2] = 14776227941,
        [3] = 14776227816,
        [4] = 0,
        [5] = 0,
        [6] = 0
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "صدر كبير",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 14776593226,
        [2] = 0,
        [3] = 0,
        [4] = 0,
        [5] = 0,
        [6] = 0
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Section = Tab:AddSection({
	Name = "تحولات"
})
Tab:AddButton({
	Name = "تحول هيروبراين",
	Callback = function()
      		wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 12346875906
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 4773930099
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 14976595538,
        [2] = 14976595831,
        [3] = 14976595559,
        [4] = 14976595617,
        [5] = 14976595675,
        [6] = 134082579
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 18758840211
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
wait(0.6) do
local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 1,
        [2] = 1,
        [3] = 1,
        [4] = 1,
        [5] = 1,
        [6] = 134082579
    },
    [3] = "Roblox20"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
end
wait(0.7) do
local args = {
    [1] = "wear",
    [2] = 18908349386
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

end
wait(0.9) do
local character = game.Players.LocalPlayer.Character 


local animationTrack = character.Animate.run.RunAnim
animationTrack.AnimationId = "rbxassetid://10921244891"
character.Animate.walk.WalkAnim.AnimationId = "rbxassetid://10921244891"
character.Animate.jump.JumpAnim.AnimationId = "rbxassetid://10921242013"
character.Animate.fall.FallAnim.AnimationId = "rbxassetid://"
character.Animate.idle.Animation1.AnimationId = "rbxassetid://10921230744"
character.Animate.idle.Animation2.AnimationId = "rbxassetid://10921232093"
character.Animate.climb.ClimbAnim.AnimationId = "rbxassetid://"
character.Animate.swim.Swim.AnimationId = "rbxassetid://"
character.Animate.swimidle.SwimIdle.AnimationId = "rbxassetid://"
end
  	end    
})
Tab:AddButton({
	Name = "تحول ستيف",
	Callback = function()
      		wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 12346875906
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 4773930099
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 14976595538,
        [2] = 14976595831,
        [3] = 14976595559,
        [4] = 14976595617,
        [5] = 14976595675,
        [6] = 134082579
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 18758858043
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 1,
        [2] = 1,
        [3] = 1,
        [4] = 1,
        [5] = 1,
        [6] = 134082579
    },
    [3] = "Roblox20"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
wait(0.8) do
local args = {
    [1] = "wear",
    [2] = 12346875906
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 1,
        [2] = 1,
        [3] = 1,
        [4] = 1,
        [5] = 1,
        [6] = 134082579
    },
    [3] = "Roblox20"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
end
  	end    
})
Tab:AddButton({
	Name = "تحول عنكبوت",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 17047437188,
        [2] = 17047437378,
        [3] = 17047437442,
        [4] = 17047437366,
        [5] = 17047437217,
        [6] = 17047437225
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
local args = {
    [1] = "wear",
    [2] = 16571270062
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "تحول ديانصور",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 3210533212,
        [2] = 3203439803,
        [3] = 3203438798,
        [4] = 3203440611,
        [5] = 3203443647,
        [6] = 3203436750
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
local args = {
    [1] = "wear",
    [2] = 3203444687
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "تحول بيبي",
	Callback = function()
      		local args = {
    [1] = "PickingTools",
    [2] = "BabyBoy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Too1l"):InvokeServer(unpack(args))
local args = {
    [1] = "CharacterSizeDown",
    [2] = 5
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))
local player = game.Players.LocalPlayer
 
-- Function to equip all tools
local function equipAllTools()
    local backpack = player.Backpack
    for _, item in pairs(backpack:GetChildren()) do
        if item:IsA("Tool") then
            item.Parent = player.Character
        end
    end
end
 
-- Call the function when needed, e.g., on a button click or game event
equipAllTools()
 

  	end    
})
Tab:AddButton({
	Name = "تحول ميني الي هو جسم صغير",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 14579958702,
        [2] = 14583777042,
        [3] = 14583777007,
        [4] = 14583776823,
        [5] = 14583776741,
        [6] = 14583776643
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "تحول قروي",
	Callback = function()
      		wait(0.1) do
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 74148072333019,
        [2] = 105051845347092,
        [3] = 103317093565994,
        [4] = 123546781151669,
        [5] = 110417909019083,
        [6] = 140062839549195
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 101261485943722
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

end
    end
})
Tab:AddButton({
	Name = "تحول فريدي",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 16178047998,
        [2] = 16178059844,
        [3] = 16178051545,
        [4] = 16178051497,
        [5] = 16178051469,
        [6] = 16178048180
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 15568938922
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
 
end
  	end    
})
Tab:AddButton({
	Name = "تحول زرافة",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 16766192865,
        [2] = 17449272553,
        [3] = 17449272421,
        [4] = 17449274174,
        [5] = 17449272828,
        [6] = 134082579
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
wait(0.2) do
local args = {
    [1] = "wear",
    [2] = 430064625
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
wait(0.1) do
local args = {
    [1] = "wear",
    [2] = 9304931059
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
 
end
  	end    
})
Tab:AddButton({
	Name = "تحول سمين",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 108716627329168,
        [2] = 71354838009971,
        [3] = 136839017348018,
        [4] = 79036034268250,
        [5] = 127317284094477,
        [6] = 0
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
  	end    
})
Tab:AddButton({
	Name = "تحول بسه",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 16766192865,
        [2] = 16766190802,
        [3] = 16766190790,
        [4] = 16766190782,
        [5] = 16766190791,
        [6] = 134082579
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
wait(0.2) do
local args = {
    [1] = "wear",
    [2] = 6202818787
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

end
wait(0.3) do
local args = {
    [1] = "CharacterSizeDown",
    [2] = 0.5
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))

end
wait(0.4) do
local args = {
    [1] = "wear",
    [2] = 7337878491
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

end
wait(0.5) do
local args = {
    [1] = "wear",
    [2] = 7337879396
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

end
wait(0.6) do
local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 1,
        [2] = 1,
        [3] = 1,
        [4] = 1,
        [5] = 1,
        [6] = 134082579
    },
    [3] = "Roblox20"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
end
  	end    
})
Tab:AddButton({
	Name = "تحول كرسي",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 16872133248,
        [2] = 16872133982,
        [3] = 16872133723,
        [4] = 16872133730,
        [5] = 16872133733,
        [6] = 134082579
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
wait(0.2) do
local args = {
    [1] = "wear",
    [2] = 10342507026
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

end
wait(0.4) do
local args = {
    [1] = "wear",
    [2] = 12270733718
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

end
  	end    
})
Tab:AddButton({
	Name = "تحول روبوت كبير",
	Callback = function()
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 14776593226,
        [2] = 14776227941,
        [3] = 14776227816,
        [4] = 102149844389538,
        [5] = 102624006545764,
        [6] = 74920391713702
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
wait(0.2) do
local args = {
    [1] = "wear",
    [2] = 16179349
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
wait(0.4) do
local args = {
    [1] = "wear",
    [2] = 7385915523
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))
end
  	end    
})
Tab:AddButton({
	Name = "تحول هالك",
	Callback = function()
      		wait(0.1) do
      		local args = {
    [1] = "CharacterChange",
    [2] = {
        [1] = 105938035513300,
        [2] = 120682289281525,
        [3] = 78459091342559,
        [4] = 119167161940457,
        [5] = 78171925423915,
        [6] = 92193892051712
    },
    [3] = "Boy"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Avata1rOrigina1l"):FireServer(unpack(args))
end
    end
})
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Tab = Window:MakeTab({
	Name = "البناء",
	Icon = "rbxassetid://743367508",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "متعة البناء"
})
Tab:AddButton({
	Name = "رسم بل ادوات",
	Callback = function()
      		local tooldraw = Instance.new("ScreenGui")
local canvas = Instance.new("Frame")
local undo = Instance.new("TextButton")
local UICorner = Instance.new("UICorner")
local partCount = Instance.new("TextLabel")
local UICorner_2 = Instance.new("UICorner")
local heading = Instance.new("TextLabel")
local X = Instance.new("TextButton")

-- Properties:

tooldraw.Name = "tooldraw"
tooldraw.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")
tooldraw.ResetOnSpawn = false

canvas.Name = "canvas"
canvas.Parent = tooldraw
canvas.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
canvas.BorderColor3 = Color3.fromRGB(0, 0, 0)
canvas.BorderSizePixel = 3
canvas.Position = UDim2.new(0.107591286, 0, 0.34321183, 0)
canvas.Size = UDim2.new(0, 614, 0, 286)

undo.Name = "undo"
undo.Parent = canvas
undo.BackgroundColor3 = Color3.fromRGB(21, 21, 21)
undo.BackgroundTransparency = 0.400
undo.BorderColor3 = Color3.fromRGB(0, 0, 0)
undo.BorderSizePixel = 0
undo.Position = UDim2.new(0.863454342, 0, 0.867436349, 0)
undo.Size = UDim2.new(0, 65, 0, 31)
undo.Font = Enum.Font.SourceSans
undo.Text = "احذف الرسمة"
undo.TextColor3 = Color3.fromRGB(0, 0, 0)
undo.TextSize = 21.000
undo.TextWrapped = true

UICorner.CornerRadius = UDim.new(0.200000003, 8)
UICorner.Parent = undo

partCount.Name = "partCount"
partCount.Parent = canvas
partCount.BackgroundColor3 = Color3.fromRGB(57, 57, 57)
partCount.BorderColor3 = Color3.fromRGB(0, 0, 0)
partCount.BorderSizePixel = 0
partCount.Position = UDim2.new(-0.00112408074, 0, 1.03302538, 0)
partCount.Size = UDim2.new(0, 265, 0, 36)
partCount.Font = Enum.Font.SourceSansBold
partCount.Text = "PARTS: 0/0"
partCount.TextColor3 = Color3.fromRGB(0, 255, 0)
partCount.TextScaled = true
partCount.TextSize = 14.000
partCount.TextWrapped = true

UICorner_2.CornerRadius = UDim.new(0.200000003, 8)
UICorner_2.Parent = partCount

heading.Name = "heading"
heading.Parent = tooldraw
heading.BackgroundColor3 = Color3.fromRGB(40, 40, 40)
heading.BorderColor3 = Color3.fromRGB(67, 67, 67)
heading.BorderSizePixel = 3
heading.Position = UDim2.new(0.107591286, 0, 0.30526374, 0)
heading.Size = UDim2.new(0, 614, 0, 26)
heading.Font = Enum.Font.Unknown
heading.Text = "Affexter Utilities: ToolEditor"
heading.TextColor3 = Color3.fromRGB(47, 255, 0)
heading.TextSize = 14.000

X.Name = "X"
X.Parent = heading
X.BackgroundColor3 = Color3.fromRGB(0, 255, 42)
X.BorderColor3 = Color3.fromRGB(0, 0, 0)
X.BorderSizePixel = 0
X.Position = UDim2.new(0.943230331, 0, 0.140418425, 0)
X.Size = UDim2.new(0, 33, 0, 17)
X.Font = Enum.Font.SourceSansBold
X.Text = "X"
X.TextColor3 = Color3.fromRGB(0, 0, 0)
X.TextScaled = true
X.TextSize = 14.000
X.TextWrapped = true

local player = game:GetService('Players').LocalPlayer
local RunService = game:GetService("RunService")

local used = 0
 
local function UTG()
    local backpack = player.Backpack:GetChildren()
    local total = #backpack
    for _, tool in ipairs(player.Character:GetChildren()) do
        if tool:IsA("Tool") then
            total = total + 1
        end
    end
    partCount.Text = "PARTS: " .. used .. "/" .. total

    if used >= total then
        partCount.TextColor3 = Color3.fromRGB(255, 0, 0)
    else
        partCount.TextColor3 = Color3.fromRGB(0, 255, 42)
    end
end

RunService.RenderStepped:Connect(UTG)

-- Scripts:
local function XQFJOB_fake_script()
    local script = Instance.new('LocalScript', canvas)

    local frame = script.Parent
    local isDrawing = false
    
    local toolGripOffset = Vector3.new(-27, -20, 0)

    local function toolLogic(pos)
        local backpack = player.Backpack:GetChildren()
        local canvasSize = frame.Size
        local canvasWidth = canvasSize.X.Offset
        local canvasHeight = canvasSize.Y.Offset
    
        local gripPosition = Vector3.new(
            ((pos.X - frame.AbsolutePosition.X) / canvasWidth) * 60 - 1,
            ((pos.Y - frame.AbsolutePosition.Y) / canvasHeight) * 25 - 1,
            0
        ) + toolGripOffset
    
        local tool = backpack[1]
        if tool then
            if tool:FindFirstChild('LocalScript') then
                tool.LocalScript:Destroy()
            end
        
            tool.Grip = CFrame.new(gripPosition)
            tool.Parent = player.Character
            used = used + 1
            UTG()
        end
    end

    local function createDot(position)
        local dot = Instance.new("Frame")
        dot.Size = UDim2.new(0, 5, 0, 5)
        dot.Position = UDim2.new(0, position.X - frame.AbsolutePosition.X, 0, position.Y - frame.AbsolutePosition.Y)
        dot.BackgroundColor3 = Color3.new(0, 0, 0)
        dot.BorderSizePixel = 0
        dot.Parent = frame
        toolLogic(position)
    end
    
    local function handleInput(input)
        if input.UserInputType == Enum.UserInputType.MouseButton1 or 
           input.UserInputType == Enum.UserInputType.Touch then
            local backpack = player.Backpack:GetChildren()
            if #backpack > 0 then
                isDrawing = true
                createDot(input.Position)
            end
        end
    end
    
    frame.InputBegan:Connect(handleInput)
    
    frame.InputEnded:Connect(function(input)
        if input.UserInputType == Enum.UserInputType.MouseButton1 or 
           input.UserInputType == Enum.UserInputType.Touch then
            isDrawing = false
        end
    end)
    
    frame.InputChanged:Connect(function(input)
        if isDrawing and (input.UserInputType == Enum.UserInputType.MouseMovement or 
                          input.UserInputType == Enum.UserInputType.Touch) then
            createDot(input.Position)
        end
    end)
end

coroutine.wrap(XQFJOB_fake_script)()


local function QYOUZ_fake_script()
    local script = Instance.new('LocalScript', undo)
    local button = script.Parent
    local canvas = button.Parent
    
    local function reset()
        for _, line in ipairs(canvas:GetChildren()) do
            if line:IsA("Frame") then
                line:Destroy()
            end
        end
        for _, tool in ipairs(player.Character:GetChildren()) do
            if tool:IsA("Tool") then
                tool.Parent = player.Backpack
            end
        end
        used = 0
        UTG()
    end
    
    button.Activated:Connect(reset)
end
coroutine.wrap(QYOUZ_fake_script)()

local function XMLK_fake_script()
    local script = Instance.new('LocalScript', heading)

    local UserInputService = game:GetService("UserInputService")
    
    local header = script.Parent
    local canvas = script.Parent.Parent.canvas
    
    local dragging = false
    local dragStart, startPos
    
    local function updatePosition(input)
        local delta = input.Position - dragStart
        header.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
        canvas.Position = UDim2.new(canvasStartPos.X.Scale, canvasStartPos.X.Offset + delta.X, canvasStartPos.Y.Scale, canvasStartPos.Y.Offset + delta.Y)
    end
    
    local function onInputBegan(input, gameProcessed)
        if gameProcessed then return end
        
        local inputPosition = input.Position
        local headerPosition = header.AbsolutePosition
        local headerSize = header.AbsoluteSize
        
        if (input.UserInputType == Enum.UserInputType.MouseButton1 or input.UserInputType == Enum.UserInputType.Touch) and
           inputPosition.X >= headerPosition.X and inputPosition.X <= headerPosition.X + headerSize.X and
           inputPosition.Y >= headerPosition.Y and inputPosition.Y <= headerPosition.Y + headerSize.Y then
            dragging = true
            dragStart = inputPosition
            startPos = header.Position
            canvasStartPos = canvas.Position
            
            input.Changed:Connect(function()
                if input.UserInputState == Enum.UserInputState.End then
                    dragging = false
                end
            end)
        end
    end
    
    local function onInputChanged(input, gameProcessed)
        if gameProcessed then return end
        
        if dragging and 
           (input.UserInputType == Enum.UserInputType.MouseMovement or 
            input.UserInputType == Enum.UserInputType.Touch) then
            updatePosition(input)
        end
    end
    
    UserInputService.InputBegan:Connect(onInputBegan)
    UserInputService.InputChanged:Connect(onInputChanged)
end
coroutine.wrap(XMLK_fake_script)()

local function FKUSJ_fake_script()
    local script = Instance.new('LocalScript', X)

    local button = script.Parent
    local gui = button.Parent.Parent
    
    local function closeGUI()
        gui:Destroy()
    end
    
    button.Activated:Connect(closeGUI)
end
coroutine.wrap(FKUSJ_fake_script)()
  	end    
})
local Section = Tab:AddSection({
	Name = "تكرارات الاشياء"
})
Tab:AddButton({
	Name = "تكرار كيس النار",
	Callback = function()
      		game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-2.7239348888397217, 3.5075316429138184, -121.8108139038086)
wait(0.1) do
local totalTime = 5 -- Total duration in seconds
local interval = 0.0 -- Time between each repetition in seconds
local elapsedTime = 0 -- Time elapsed

-- Function to execute the repeated action
local function repeatAction()
    fireclickdetector(workspace.WorkspaceCom["001_GroceryRobbery"].StoreRobbery.Tool.PaperbagFire.ClickDetector) 
end

-- Start the loop
while elapsedTime < totalTime do
    repeatAction()
    wait(interval) -- Wait for the specified interval
    elapsedTime = elapsedTime + interval -- Update elapsed time
end

print("Completed repeating the action.")
end
  	end    
})

--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
local Tab = Window:MakeTab({
	Name = "البيوت",
	Icon = "rbxassetid://18786871535",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "تحكم"
})
local playerName = "fgijvcdeool"  -- Default player name
local numberValue = 11  -- Default number value

-- First Textbox for Player Name
Tab:AddTextbox({
	Name = "اسم الاعب",
	Default = "دخل اسم الاعب او اسمك كامل",
	TextDisappear = true,
	Callback = function(Value)
		playerName = Value  -- Update the playerName variable with the textbox input
		print("Entered player name: " .. playerName)
	end
})

-- Second Textbox for Number Value
Tab:AddTextbox({
	Name = "رقم البيت",
	Default = "دخل رقم البيت",
	TextDisappear = true,
	Callback = function(Value)
		numberValue = tonumber(Value) or 11  -- Update the numberValue variable with the input, default to 11 if invalid
		print("Entered number value: " .. tostring(numberValue))
	end
})

-- Button to fire the event using the input values
Tab:AddButton({
	Name = "تحكم",
	Callback = function()
		-- Find the player based on the input name
		local player = game:GetService("Players"):FindFirstChild(playerName)

		if player then
			local args = {
				[1] = "GivePermissionLoopToServer",
				[2] = player,  -- Replace fgijvcdeool with the entered player name
				[3] = numberValue  -- Replace 11 with the entered number value
			}

			-- Fire the event with the updated args
			game:GetService("ReplicatedStorage").RE:FindFirstChild("1Playe1rTrigge1rEven1t"):FireServer(unpack(args))
			
			print("Event fired for player: " .. playerName .. " with value: " .. tostring(numberValue))
		else
			print("Player not found.")
		end
	end
})
local Section = Tab:AddSection({
	Name = "بيت ملون وتكرارات"
})
Tab:AddButton({
	Name = "بيت ملون",
	Callback = function()
      		local ReplicatedStorage = game:GetService("ReplicatedStorage")
local event = ReplicatedStorage.RE:FindFirstChild("1Player1sHous1e")

local colors = { 
    Color3.fromRGB(255, 0, 0),   -- Red
    Color3.fromRGB(0, 255, 0),   -- Green
    Color3.fromRGB(0, 0, 255),   -- Blue
    Color3.fromRGB(255, 255, 0), -- Yellow
    Color3.fromRGB(255, 165, 0), -- Orange
    Color3.fromRGB(75, 0, 130),  -- Indigo
    Color3.fromRGB(238, 130, 238), -- Violet
    Color3.fromRGB(128, 0, 128)  -- Purple
}

while true do
    for _, color in pairs(colors) do
        local args = {
            [1] = "ColorPickHouse",
            [2] = color
        }
        event:FireServer(unpack(args))
        wait(1)  -- Adjust this to control the speed of the color change
    end
end
  	end    
})
Tab:AddButton({
	Name = "ازالة الباند من كل البيوت",
	Callback = function()
      	   -- Define the path to the folder
local folder = game.ReplicatedStorage:FindFirstChild("BannedLots")

-- Check if the folder exists
if folder then
    folder:Destroy() -- Deletes the folder
    print("BannedLots folder has been deleted.")
else
    print("BannedLots folder not found.")
end
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
local Tab = Window:MakeTab({
	Name = "السيارات",
	Icon = "rbxassetid://18944378972",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "متعة السيارات"
})
Tab:AddButton({
	Name = "سحب كل السيارات",
	Callback = function()
      		--[[
	WARNING: Heads up! This script has not been verified by ScriptBlox. Use at your own risk!
]]
--gold hub:) 
loadstring(game:HttpGet('https://pastefy.app/vaXK1Kgy/raw'))()
  	end    
})
Tab:AddButton({
	Name = "سيارة بوقاتي زرقاء سريه",
	Callback = function()
      		local args = {
    [1] = "wear",
    [2] = 15371260910
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Updat1eAvata1r"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "اسم m كبير وطويل جدا ومقلتش للسيارات",
	Callback = function()
      		local args = {
    [1] = "ReturningSemiName",
    [2] = "M\204\183\205\131\204\149\205\140\204\141\205\134\204\133\204\131\204\137\204\148\204\145\205\145\205\151\205\157\205\132\204\154\205\134\205\155\204\132\204\132\204\191\204\144\204\147\204\188\205\149\205\153\204\174\205\147\205\153\204\167\205\149\205\135\204\152\205\154\204\167\204\157\204\169\204\158\204\186\204\151\204\162\204\156\205\142\204\166\205\153\204\178\204\150\204\166\205\147\204\178\205\135\205\147\204\161\204\159\204\187\204\185\204\186\204\163\204\163\204\160\205\150\205\135\204\163"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Cemeter1y"):FireServer(unpack(args))
wait(0.2) do
local args = {
    [1] = "ReturningNascarPremiumName",
    [2] = "M\204\183\205\131\204\149\205\140\204\141\205\134\204\133\204\131\204\137\204\148\204\145\205\145\205\151\205\157\205\132\204\154\205\134\205\155\204\132\204\132\204\191\204\144\204\147\204\188\205\149\205\153\204\174\205\147\205\153\204\167\205\149\205\135\204\152\205\154\204\167\204\157\204\169\204\158\204\186\204\151\204\162\204\156\205\142\204\166\205\153\204\178\204\150\204\166\205\147\204\178\205\135\205\147\204\161\204\159\204\187\204\185\204\186\204\163\204\163\204\160\205\150\205\135\204\163"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Cemeter1y"):FireServer(unpack(args))

end
wait(0.3) do
local args = {
    [1] = "ReturningStudentDriverName",
    [2] = "M\204\183\205\131\204\149\205\140\204\141\205\134\204\133\204\131\204\137\204\148\204\145\205\145\205\151\205\157\205\132\204\154\205\134\205\155\204\132\204\132\204\191\204\144\204\147\204\188\205\149\205\153\204\174\205\147\205\153\204\167\205\149\205\135\204\152\205\154\204\167\204\157\204\169\204\158\204\186\204\151\204\162\204\156\205\142\204\166\205\153\204\178\204\150\204\166\205\147\204\178\205\135\205\147\204\161\204\159\204\187\204\185\204\186\204\163\204\163\204\160\205\150\205\135\204\163"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Cemeter1y"):FireServer(unpack(args))

end
wait(0.4) do
local args = {
    [1] = "ReturningFoodTruckName",
    [2] = "M\204\183\205\131\204\149\205\140\204\141\205\134\204\133\204\131\204\137\204\148\204\145\205\145\205\151\205\157\205\132\204\154\205\134\205\155\204\132\204\132\204\191\204\144\204\147\204\188\205\149\205\153\204\174\205\147\205\153\204\167\205\149\205\135\204\152\205\154\204\167\204\157\204\169\204\158\204\186\204\151\204\162\204\156\205\142\204\166\205\153\204\178\204\150\204\166\205\147\204\178\205\135\205\147\204\161\204\159\204\187\204\185\204\186\204\163\204\163\204\160\205\150\205\135\204\163"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Cemeter1y"):FireServer(unpack(args))

end
wait(0.5) do
local args = {
    [1] = "ReturningNascarTruckName",
    [2] = "M\204\183\205\131\204\149\205\140\204\141\205\134\204\133\204\131\204\137\204\148\204\145\205\145\205\151\205\157\205\132\204\154\205\134\205\155\204\132\204\132\204\191\204\144\204\147\204\188\205\149\205\153\204\174\205\147\205\153\204\167\205\149\205\135\204\152\205\154\204\167\204\157\204\169\204\158\204\186\204\151\204\162\204\156\205\142\204\166\205\153\204\178\204\150\204\166\205\147\204\178\205\135\205\147\204\161\204\159\204\187\204\185\204\186\204\163\204\163\204\160\205\150\205\135\204\163"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Cemeter1y"):FireServer(unpack(args))

end
wait(0.6) do
local args = {
    [1] = "ReturningRVName",
    [2] = "M\204\183\205\131\204\149\205\140\204\141\205\134\204\133\204\131\204\137\204\148\204\145\205\145\205\151\205\157\205\132\204\154\205\134\205\155\204\132\204\132\204\191\204\144\204\147\204\188\205\149\205\153\204\174\205\147\205\153\204\167\205\149\205\135\204\152\205\154\204\167\204\157\204\169\204\158\204\186\204\151\204\162\204\156\205\142\204\166\205\153\204\178\204\150\204\166\205\147\204\178\205\135\205\147\204\161\204\159\204\187\204\185\204\186\204\163\204\163\204\160\205\150\205\135\204\163"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Cemeter1y"):FireServer(unpack(args))

end
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Section = Tab:AddSection({
	Name = "تكرارات و سياره ملونه"
})
Tab:AddButton({
	Name = "سياره ملونه",
	Callback = function()
      		while true do  -- Infinite loop
    local args = {
        [1] = "PickingCarColor",
        [2] = Color3.new(math.random(), math.random(), math.random())  -- Random color
    }

    game:GetService("ReplicatedStorage").RE:FindFirstChild("1Player1sCa1r"):FireServer(unpack(args))

    wait(1.2)  -- Wait for 1 second before changing color again
end
  	end    
})
local Section = Tab:AddSection({
	Name = "متعه الاحصنه"
})
Tab:AddButton({
	Name = "سحب كل الاحصنه",
	Callback = function()
      		local players = game:GetService("Players")

for _, player in pairs(players:GetPlayers()) do
    local args = {
        [1] = player
    }

    game:GetService("ReplicatedStorage").RE:FindFirstChild("1Hors1eRemot1e"):FireServer(unpack(args))
end
  	end    
})
Tab:AddButton({
	Name = "قطع الحصان ",
	Callback = function()
      		local args = {
    [1] = "PickingCar",
    [2] = "Horse"
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Ca1r"):FireServer(unpack(args))
wait(0.5) do
local args = {
    [1] = game:GetService("Players").LocalPlayer
}

game:GetService("ReplicatedStorage").RE:FindFirstChild("1Hors1eRemot1e"):FireServer(unpack(args))
end
wait(0.9) do
-- Reference the player
local player = game.Players.LocalPlayer

-- Check if the character already exists
if player.Character then
    player.Character:BreakJoints() -- Reset the character immediately
end

-- Listen for future character spawns and reset
player.CharacterAdded:Connect(function(character)
    character:BreakJoints() -- Reset the character whenever it spawns
end)
end
  	end    
})
Tab:AddButton({
	Name = "قطع الحصان ملونه قريبا",
	Callback = function()
      		
  	end    
})
local Tab = Window:MakeTab({
	Name = "اوامر وادمن",
	Icon = "rbxassetid://4483345998",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "اوامر"
}) 
-- Function to get all player names
local function getPlayerNames()
    local playerNames = {}
    for _, player in ipairs(game.Players:GetPlayers()) do
        table.insert(playerNames, player.Name)
    end
    return playerNames
end

-- Store selected player for later use
local selectedPlayer = nil
local followHead = false
local connection = nil

-- Function to spectate the selected player
local function spectatePlayer(enable)
    local player = game.Players.LocalPlayer
    local camera = workspace.CurrentCamera

    if selectedPlayer then
        local targetPlayer = game.Players:FindFirstChild(selectedPlayer)
        if targetPlayer and targetPlayer.Character and targetPlayer.Character:FindFirstChild("HumanoidRootPart") then
            if enable then
                -- Set camera to follow the selected player
                camera.CameraSubject = targetPlayer.Character.Humanoid
            else
                -- Reset camera to default (back to the local player)
                camera.CameraSubject = player.Character.Humanoid
            end
        else
            print("Selected player not available or out of game.")
        end
    else
        print("No player selected!")
    end
end

-- Function to float just above the selected player's head without falling
local function floatAbovePlayerHead()
    local player = game.Players.LocalPlayer
    local character = player.Character or player.CharacterAdded:Wait()

    if character and character:FindFirstChild("HumanoidRootPart") then
        local humanoidRootPart = character.HumanoidRootPart

        if selectedPlayer then
            local targetPlayer = game.Players:FindFirstChild(selectedPlayer)

            if targetPlayer and targetPlayer.Character and targetPlayer.Character:FindFirstChild("Head") then
                local targetHead = targetPlayer.Character.Head

                -- Position above the selected player's head
                humanoidRootPart.CFrame = targetHead.CFrame * CFrame.new(0, 3, 0)

                -- Keep updating the position every frame
                connection = game:GetService("RunService").Heartbeat:Connect(function()
                    if followHead and targetPlayer and targetPlayer.Character and targetPlayer.Character:FindFirstChild("Head") then
                        -- Update to stay above the player's head
                        humanoidRootPart.CFrame = targetPlayer.Character.Head.CFrame * CFrame.new(0, 3, 0)
                    else
                        connection:Disconnect() -- Disconnect if the toggle is off
                    end
                end)
            else
                print("Target player not found or not in the game.")
            end
        else
            print("No player selected!")
        end
    end
end

-- Function to trigger the secondary script
local function triggerCharacterSizeDown()
    local args = {
        [1] = "CharacterSizeDown",
        [2] = 2.4
    }
    game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clothe1s"):FireServer(unpack(args))
end

-- Function to teleport behind the selected player and return after 1.5 seconds
local function moveBehindAndReturn()
    local player = game.Players.LocalPlayer
    local character = player.Character or player.CharacterAdded:Wait()
    local humanoidRootPart = character:FindFirstChild("HumanoidRootPart")

    if humanoidRootPart and selectedPlayer then
        local targetPlayer = game.Players:FindFirstChild(selectedPlayer)
        if targetPlayer and targetPlayer.Character and targetPlayer.Character:FindFirstChild("HumanoidRootPart") then
            local targetHumanoidRootPart = targetPlayer.Character.HumanoidRootPart

            -- Store the original position
            local originalPosition = humanoidRootPart.CFrame

            -- Move behind the selected player
            humanoidRootPart.CFrame = targetHumanoidRootPart.CFrame * CFrame.new(0, 0, 3)

            -- Wait for 1.5 seconds before returning
            wait(1.5)

            -- Return to original position
            humanoidRootPart.CFrame = originalPosition
        else
            print("Selected player not found or not in the game.")
        end
    else
        print("No player or HumanoidRootPart found!")
    end
end

-- Create the dropdown with player names
Tab:AddDropdown({
    Name = "اختار الاعب",
    Default = "",
    Options = getPlayerNames(),
    Callback = function(value)
        selectedPlayer = value
        print("Player selected: " .. value)
    end    
})

-- Add a toggle that allows the player to spectate the selected player
Tab:AddToggle({
    Name = "شوف الاعب",
    Default = false,
    Callback = function(value)
        spectatePlayer(value)
    end    
})

-- Add a second toggle to start floating above the selected player's head
Tab:AddToggle({
    Name = "تحكم في شات الاعب",
    Default = false,
    Callback = function(value)
        followHead = value
        if followHead then
            -- Teleport to player's head first
            floatAbovePlayerHead()
            -- Trigger the secondary script
            triggerCharacterSizeDown()
        else
            if connection then
                connection:Disconnect() -- Disconnect the heartbeat listener when not following
                connection = nil
            end
        end
    end    
})

-- Add a button to teleport to the selected player
Tab:AddButton({
    Name = "روح عند الاعب",
    Callback = function()
        floatAbovePlayerHead()
    end    
})

-- Add a button to move behind the selected player and return after 1.5 seconds
Tab:AddButton({
    Name = "اسحب الاعب",
    Callback = function()
        moveBehindAndReturn()
    end    
})
-- Function to teleport behind the selected player and then move to a fixed position
local function moveBehindThenTeleportToFixedPosition()
    local player = game.Players.LocalPlayer
    local character = player.Character or player.CharacterAdded:Wait()
    local humanoidRootPart = character:FindFirstChild("HumanoidRootPart")
    local teleportPosition = Vector3.new(0.9995850324630737, -489.0882873535156, 1.0034377574920654)

    if humanoidRootPart and selectedPlayer then
        local targetPlayer = game.Players:FindFirstChild(selectedPlayer)
        if targetPlayer and targetPlayer.Character and targetPlayer.Character:FindFirstChild("HumanoidRootPart") then
            local targetHumanoidRootPart = targetPlayer.Character.HumanoidRootPart

            -- Move behind the selected player
            humanoidRootPart.CFrame = targetHumanoidRootPart.CFrame * CFrame.new(0, 0, 3)

            -- Wait for 1.1 seconds before teleporting to the fixed position
            wait(1.1)

            -- Teleport to the fixed position
            humanoidRootPart.CFrame = CFrame.new(teleportPosition)
        else
            print("Selected player not found or not in the game.")
        end
    else
        print("No player or HumanoidRootPart found!")
    end
end

-- Add a new button to move behind the selected player and then teleport to a fixed position
Tab:AddButton({
    Name = "اقتل الاعب",
    Callback = function()
        moveBehindThenTeleportToFixedPosition()
    end    
})
local Section = Tab:AddSection({
	Name = "ادمن"
})
Tab:AddTextbox({
    Name = "حط كود الصوت",
    Default = "default box input",
    TextDisappear = true,
    Callback = function(Value)
        -- Updating the value in the args
        local args1 = {
            [1] = "CharacterSizeDown",
            [2] = 1
        }
        game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Clothe1s"):FireServer(unpack(args1))

        local args2 = {
            [1] = "SkateBoard"
        }
        game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1NoMoto1rVehicle1s"):FireServer(unpack(args2))

        -- Replacing the static value with the input from the textbox
        local args3 = {
            [1] = "PickingScooterMusicText",
            [2] = Value -- Here, we use the textbox value to replace 35935204
        }
        game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1NoMoto1rVehicle1s"):FireServer(unpack(args3))

        local args4 = {
            [1] = "CharacterSizeUp",
            [2] = 1
        }
        game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Clothe1s"):FireServer(unpack(args4))
    end    
})

--[[
Name = <string> - The name of the textbox.
Default = <string> - The default value of the textbox.
TextDisappear = <bool> - Makes the text disappear in the textbox after losing focus.
Callback = <function> - The function of the textbox.
]]
Tab:AddButton({
	Name = "اداة حذف القطع الي تتحرك",
	Callback = function()
      		local tool = Instance.new("Tool")
tool.Name = "يحمل"
tool.RequiresHandle = false

-- Create a local variable to store the mouse
local mouse = nil

-- Function to check if a part is unanchored
local function isUnanchored(part)
    return not part:IsDescendantOf(workspace) or not part:IsDescendantOf(game:GetService("Players").LocalPlayer.Character) or not part.Anchored
end

-- Function to handle part selection
local function handlePart(part)
    if isUnanchored(part) then
        -- Apply a force to fling the part
        local flingForce = Instance.new("BodyVelocity")
        flingForce.Velocity = Vector3.new(9999, 9999, 9999) -- Change the velocity as per your requirement. Change it to this ( 0, 10000, 0) to make it stronger 
        flingForce.P = math.huge
        flingForce.MaxForce = Vector3.new(math.huge, math.huge, math.huge)
        flingForce.Parent = part

        -- Create a fire effect
        local fire = Instance.new("Fire")
        fire.Size = 20 -- Change the size of the fire as per your requirement
        fire.Heat = 20 -- Change the heat of the fire as per your requirement
        fire.Parent = part

        -- Remove the fire effect and force after a short delay
        wait(0.5) -- Change the delay as per your requirement
        fire:Destroy()
        flingForce:Destroy()
    end
end

-- Function to handle tool equipped event
local function onEquipped()
    -- Get the local player's mouse
    mouse = game:GetService("Players").LocalPlayer:GetMouse()

    -- Connect the mouse button press event
    mouse.Button1Down:Connect(function()
        -- Check if the mouse target is a part
        if mouse.Target and mouse.Target:IsA("BasePart") then
            handlePart(mouse.Target)
        end
    end)
end

-- Function to handle tool unequipped event
local function onUnequipped()
    -- Disconnect the mouse button press event
    if mouse then
        mouse.Button1Down:Disconnect()
        mouse = nil
    end
end

-- Connect the tool equipped and unequipped events
tool.Equipped:Connect(onEquipped)
tool.Unequipped:Connect(onUnequipped)

-- Add the tool to the player's backpack
game:GetService("Players").LocalPlayer.Backpack:ClearAllChildren()
tool.Parent = game:GetService("Players").LocalPlayer.Backpack



local players = game:GetService("Players")
local player = players.LocalPlayer
local backpack = player.Backpack

for _, tool in ipairs(backpack:GetChildren()) do
    if tool:IsA("Tool") then
        tool.Parent = player.Character
    end
end

wait(1)
game.Players.LocalPlayer.Character.Humanoid.Health = 0

wait(1)

local args = {
    [1] = "PickingTools",
    [2] = "Hammer"
}

game:GetService("ReplicatedStorage").RE["1Too1l"]:InvokeServer(unpack(args))

  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the dropdown (to select a player).
Default = <string> - The default value of the dropdown.
Options = <table> - The list of player names.
Callback = <function> - The function that triggers when a player is selected.

Name = <string> - The name of the first toggle (to spectate the player).
Default = <bool> - The default value of the toggle.
Callback = <function> - The function that triggers when the toggle is clicked.

Name = <string> - The name of the second toggle (to float above the player's head and trigger the FireServer).
Default = <bool> - The default value of the toggle.
Callback = <function> - The function that triggers when the toggle is clicked.

Name = <string> - The name of the first button (to teleport to the selected player).
Callback = <function> - The function that triggers when the button is clicked.

Name = <string> - The name of the second button (to move behind the selected player and return to the original position after 1.5 seconds).
Callback = <function> - The function that triggers when the button is clicked.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
local Tab = Window:MakeTab({
	Name = "المابات المدعومة للسكربت",
	Icon = "rbxassetid://4483345998",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "المابات المدعومة للسكربت قائمة وتشغيلها"
})
Tab:AddButton({
	Name = "MM2",
	Callback = function()
      		loadstring(game:HttpGet("https://pastebin.com/raw/nrfbPyqD"))()
  	end    
})
Tab:AddButton({
	Name = "سكربت حذف السلم او الشي الي كل ما تمشي عليه يختفي لللباركورات",
	Callback = function()
      		loadstring(game:HttpGet("https://raw.githubusercontent.com/hellohellohell012321/obby-ruiner/main/obby-ruiner.lua",true))()
  	end    
})
Tab:AddButton({
	Name = "اخذ فلوس بوقت سريع ماب المطعم",
	Callback = function()
      		loadstring(game:HttpGet("https://rawscripts.net/raw/My-Restaurant!-Fast-Autofarm-4610"))()
  	end    
})
Tab:AddButton({
	Name = "داندي ورلد Dandy",
	Callback = function()
      		loadstring(game:HttpGet("https://pastebin.com/raw/D8yHCstP"))() 
  	end    
})
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
local Section = Tab:AddSection({
	Name = "قريبا"
})
local Tab = Window:MakeTab({
	Name = "الاعدادات",
	Icon = "rbxassetid://4483345998",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "الشاشة"
})
Tab:AddButton({
	Name = "قفل في الشاشه",
	Callback = function()
      		loadstring(game:HttpGet("https://rawscripts.net/raw/Universal-Script-FE-Mobile-Shiftlock-Official-19126"))()
  	end    
})
local Section = Tab:AddSection({
	Name = "الاعب"
})
Tab:AddTextbox({
    Name = "اكتب السرعه الي تبغاها",
    Default = "16",  -- القيمة الافتراضية
    TextDisappear = true,
    Callback = function(Value)
        local player = game.Players.LocalPlayer
        local speedValue = tonumber(Value)  -- تحويل النص إلى رقم
        if player and player.Character and player.Character:FindFirstChild("Humanoid") then
            if speedValue then
                player.Character.Humanoid.WalkSpeed = speedValue  -- تغيير سرعة المشي
            else
                print("Invalid input!")
            end
        end
    end    
})
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
--[[
Name = <string> - The name of the section.
]]
--[[
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
]]
