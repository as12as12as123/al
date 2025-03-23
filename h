local OrionLib = loadstring(game:HttpGet('https://pastebin.com/raw/w1S27M3Y'))()
local Window = OrionLib:MakeWindow({Name = "هاك سعودي 🇸🇦", HidePremium = false, SaveConfig = true, ConfigFolder = "OrionTest"})

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
	Name = "الصفحة الرئيسية",
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
    [1] = "CharacterSizeUp",
    [2] = 1.5
}

game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Clothe1s"):FireServer(unpack(args))

  	end    
})
Tab:AddButton({
	Name = "حجم كبير جدا",
	Callback = function()
      	 local args = {
    [1] = "CharacterSizeUp",
    [2] = 1
}

game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Clothe1s"):FireServer(unpack(args))
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
  	end    
})
local Section = Tab:AddSection({
	Name = "الاسم"
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "اسم ملون",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start the loop when the toggle is activated
			while isActive do
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
local Section = Tab:AddSection({
	Name = "رجل مخفيه وراس مخفي"
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
	Name = "راس مخفي",
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
 local Tab = Window:MakeTab({
	Name = "السيارات",
	Icon = "rbxassetid://18944378972",
	PremiumOnly = false
})
local Section = Tab:AddSection({
	Name = "متعة السيارات"
})
Tab:AddTextbox({
    Name = "  حط كود الصوت",
    Default = "",
    TextDisappear = true,
    Callback = function(input)
        local args = {
            [1] = "PickingCarMusicText",
            [2] = input
        }
        game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
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
local Section = Tab:AddSection({
	Name = "سيارة ملونه وتكرارات"
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "سياره ملونه",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start the loop when the toggle is activated
			spawn(function()
				while isActive do
					-- Generate random car color
					local args = {
						[1] = "PickingCarColor",
						[2] = Color3.new(math.random(), math.random(), math.random()) -- Random color
					}
					
					-- Fire the remote event
					game:GetService("ReplicatedStorage").RE:FindFirstChild("1Player1sCa1r"):FireServer(unpack(args))
					
					wait(1.2) -- Adjust the wait time as needed
				end
			end)
		end
	end
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = " تكرار بوري السياره 1",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start spamming the event
			spawn(function()
				while isActive do
					local args = {
						[1] = "Duke1"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
					wait(0.8) -- Spam every 0.8 seconds
				end
			end)
		end
	end
})local isActive = false -- حالة التفعيل

Tab:AddToggle({
	Name = "تشغيل الحريق تكرار",
	Default = false, -- التفعيل الافتراضي
	Callback = function(value)
		isActive = value -- تحديث حالة التفعيل
		if isActive then
			-- تشغيل الحريق بشكل مستمر
			spawn(function()
				while isActive do
					local args = {
						[1] = "Fire"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
					wait(1) -- التحكم في مدة الانتظار بين كل عملية
				end
			end)
		else
			-- تشغيل السكربت مرة واحدة فقط عند الإطفاء
			local args = {
				[1] = "StopFire"
			}
			game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
			print("تم إطفاء الحريق.")
		end
	end
})local isActive = false -- حالة التفعيل

Tab:AddToggle({
	Name = "تكرار تشغيل الدخان",
	Default = false, -- التفعيل الافتراضي
	Callback = function(value)
		isActive = value -- تحديث حالة التفعيل
		if isActive then
			-- تشغيل الدخان بشكل مستمر
			spawn(function()
				while isActive do
					local args = {
						[1] = "Smoke"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
					wait(1) -- التحكم في مدة الانتظار بين كل عملية
				end
			end)
		else
			-- تشغيل السكربت مرة واحدة فقط عند الإطفاء
			local args = {
				[1] = "StopSmoke" -- اسم الحدث لإيقاف الدخان (تأكد من أنه موجود)
			}
			game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
			print("تم إطفاء الدخان.")
		end
	end
})local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "تكرار بوري 2",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start spamming the event when toggle is activated
			spawn(function()
				while isActive do
					local args = {
						[1] = "Duke"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
					wait(0.9) -- Spam every 0.9 seconds
				end
			end)
		end
	end
})local isActive = false -- Toggle state

Tab:AddToggle({
	Name = " تكرار تغير كفر السيارة",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start spamming the event when toggle is activated
			spawn(function()
				while isActive do
					local args = {
						[1] = "WheelNumber"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args))
					wait(0.8) -- Spam every 0.8 seconds
				end
			end)
		end
	end
})local isActive = false -- Toggle state

Tab:AddToggle({
	Name = " تكرار تغير طول السيارة",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start alternating between the two scripts
			spawn(function()
				while isActive do
					-- First script
					local args1 = {
						[1] = "VehicleHeight",
						[2] = 1
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args1))
					
					wait(0.8) -- Wait before switching

					if not isActive then break end -- Stop if toggle is off

					-- Second script
					local args2 = {
						[1] = "VehicleHeight",
						[2] = 4
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sCa1r"):FireServer(unpack(args2))
					
					wait(0.8) -- Wait before switching back
				end
			end)
		end
	end
})
--[[
Name = <string> - The name of the section.
]]
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
	Name = "بيت ملون وتكرارات وازالة الباند وكود صوت"
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "بيت ملون",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start the loop when the toggle is activated
			spawn(function()
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
				
				while isActive do
					for _, color in pairs(colors) do
						if not isActive then break end -- Stop loop if toggle is off
						local args = {
							[1] = "ColorPickHouse",
							[2] = color
						}
						event:FireServer(unpack(args))
						wait(1) -- Adjust this to control the speed of the color change
					end
				end
			end)
		end
	end
})
local isBannedLotsRemoved = false -- Tracks the state of the folder

Tab:AddToggle({
	Name = "ازالة الباند من كل البيوت",
	Default = false,
	Callback = function(value)
		local ReplicatedStorage = game:GetService("ReplicatedStorage")
		local folderName = "BannedLots"

		-- When the toggle is switched on or off
		if value then
			if not isBannedLotsRemoved then
				-- Delete the folder if it exists
				local folder = ReplicatedStorage:FindFirstChild(folderName)
				if folder then
					folder:Destroy()
					print("BannedLots folder has been deleted.")
				else
					print("BannedLots folder not found to delete.")
				end
				isBannedLotsRemoved = true -- Update state to 'deleted'
			else
				-- Restore the folder
				local newFolder = Instance.new("Folder")
				newFolder.Name = folderName
				newFolder.Parent = ReplicatedStorage
				print("BannedLots folder has been restored.")
				isBannedLotsRemoved = false -- Update state to 'restored'
			end
		end
	end
})
Tab:AddTextbox({
    Name = "دخل كود الصوت",
    Default = "",
    TextDisappear = true,
    Callback = function(input)
        local args = {
            [1] = "PickHouseMusicText",
            [2] = input -- Use the user's input here
        }
        game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sHous1e"):FireServer(unpack(args))
    end
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "تكرار اضهار وعدم اضهار المسبح",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start spamming the event
			spawn(function()
				while isActive do
					local args = {
						[1] = "PoolOnOff"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sHous1e"):FireServer(unpack(args))
					wait(0.7) -- Spam every 0.7 seconds
				end
			end)
		end
	end
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "تكرار فتح وقفل الكراج",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start spamming the event
			spawn(function()
				while isActive do
					local args = {
						[1] = "GarageDoor"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sHous1e"):FireServer(unpack(args))
					wait(0.8) -- Spam every 0.8 seconds
				end
			end)
		end
	end
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "تكرار فتح وقفل الشباك",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start spamming the event
			spawn(function()
				while isActive do
					local args = {
						[1] = "Curtains"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sHous1e"):FireServer(unpack(args))
					wait(0.7) -- Spam every 0.7 seconds
				end
			end)
		end
	end
})
local isActive = false -- Toggle state

Tab:AddToggle({
	Name = "تكرار فتح وقفل الباب",
	Default = false, -- Toggle starts off
	Callback = function(value)
		isActive = value -- Update toggle state
		if isActive then
			-- Start spamming the event
			spawn(function()
				while isActive do
					local args = {
						[1] = "LockDoors"
					}
					game:GetService("ReplicatedStorage"):WaitForChild("RE"):WaitForChild("1Player1sHous1e"):FireServer(unpack(args))
					wait(0.7) -- Spam every 0.7 seconds
				end
			end)
		end
	end
})
local Tab = Window:MakeTab({
	Name = "المتعة",
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
local Section = Tab:AddSection({
	Name = "مودات المسدسات"
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
Tab:AddButton({
	Name = "مسدس قراني",
	Callback = function()
      		local args = {
    [1] = "RequestingGunSkins",
    [2] = "11528005848"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1Clea1rTool1s"):FireServer(unpack(args))
 
  	end    
})
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
	Name = "رسم في الشات",
	Callback = function()
      		loadstring(game:HttpGet("https://pastebin.com/raw/Q5zhT6Mv"))()
  	end    
})
local Section = Tab:AddSection({
	Name = "مشي في الجدران واختفاء"
})
Tab:AddButton({
	Name = "اختفاء",
	Callback = function()
      		loadstring(game:HttpGet('https://pastebin.com/raw/3Rnd9rHf'))()
  	end    
})
Tab:AddButton({
	Name = "مشي في الجدران",
	Callback = function()
      		loadstring(game:HttpGet("https://pastebin.com/raw/zXk4Rq2r"))()
  	end    
})
local Section = Tab:AddSection({
	Name = "تجسس"
})
Tab:AddButton({
	Name = "كاميرا تشيلها",
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
    [2] = "7236490488"
}
 
game:GetService("ReplicatedStorage").RE:FindFirstChild("1NoMoto1rVehicle1s"):FireServer(unpack(args))
  	end    
})
local Tab = Window:MakeTab({
	Name = "اوامر وادمن",
	Icon = "rbxassetid://13902942537",
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
Name = <string> - The name of the tab.
Icon = <string> - The icon of the tab.
PremiumOnly = <bool> - Makes the tab accessible to Sirus Premium users only.
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
