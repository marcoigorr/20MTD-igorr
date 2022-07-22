#include "pch.h"
#include "MyMenu.h"

#include "Options.h"

#include "info.h"

void MyMenu::SetStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();

    // Colors
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);

    style.Colors[ImGuiCol_Border] = ImVec4(1.000f, 0.000f, 0.647f, 1.000f);
    style.Colors[ImGuiCol_Separator] = ImVec4(1.000f, 0.000f, 0.647f, 1.000f);

    style.Colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 1.000f, 1.000f, 0.875f);

    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.718f, 0.325f, 1.000f, 0.541f); // purple
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.655f, 0.314f, 1.000f, 0.204f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.671f, 0.314f, 1.000f, 0.745f);

    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.745f, 0.494f, 1.000f, 0.722f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.706f, 0.439f, 1.000f, 1.000f);

    style.Colors[ImGuiCol_Button] = ImVec4(0.702f, 0.416f, 1.000f, 0.439f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.639f, 0.404f, 1.000f, 0.831f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.694f, 0.529f, 0.980f, 1.000f);

    style.Colors[ImGuiCol_Tab] = ImVec4(1.000f, 0.000f, 0.608f, 0.694f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(1.000f, 0.000f, 0.714f, 1.000f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(1.000f, 0.000f, 0.714f, 1.000f);

    style.Colors[ImGuiCol_Header] = ImVec4(1.000f, 0.000f, 0.569f, 0.141f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.816f, 0.000f, 0.773f, 0.800f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(1.000f, 0.000f, 0.490f, 1.000f);

    // other
    style.WindowMinSize = ImVec2(Menu->WIDTH, Menu->HEIGHT);
    style.WindowTitleAlign = ImVec2(0.50f, 0.50f); // Title
    style.WindowPadding = ImVec2(20.0f, 20.0f);
    style.WindowRounding = 9.0f;

    style.FrameRounding = 12.0f;
    style.FramePadding = ImVec2(17.0f, 4.0f);

    style.TabRounding = 9.0f;
    
    style.GrabRounding = 12.0f;
    style.GrabMinSize = 15.0f;

    style.ScrollbarSize = 17.0f;   

    style.ItemSpacing = ImVec2(13.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(10.0f, 8.0f);

}

void AddCheckBox(const char* title, bool* var)
{
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 10, ImGui::GetCursorPos().y + 20));
    ImGui::Checkbox(title, var);
}

ImVec4 Red = ImVec4(1.0f, 0, 0, 1.0f);
ImVec4 Green = ImVec4(0, 1.0f, 0, 1.0f);
void AddStatus(bool b)
{
    ImGui::SetCursorPos(ImVec2((ImGui::GetWindowContentRegionWidth() / 2.0) - (ImGui::CalcTextSize("Status: AVAILABLE").x / 2.0), ImGui::GetCursorPosY() + 10));
    
    ImGui::Text("Status: ");
    ImGui::SameLine();
    ImGui::TextColored((b) ? Green : Red, (b) ? "AVAILABLE" : "UNAVAILABLE");
}

void AddSlider()
{

}

void  MyMenu::Draw()
{
	// If menu is active
	if (options->bMenu)
	{	
		ImGui::SetNextWindowSize({ Menu->WIDTH,  Menu->HEIGHT });

        ImGui::Begin("marcoigorr v2.0.1", &options->bMenu, 0);
        {
            if (ImGui::BeginTabBar("tabs"))
            {
                if (ImGui::BeginTabItem("Health"))
                {
                    AddStatus(info::sHealth);
                    
                    AddCheckBox("Is Invincible", &options->bHealth);

                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Ammo"))
                {
                    AddStatus(info::sAmmo);

                    AddCheckBox("Infinite Ammo", &options->bAmmo);

                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Speed"))
                {
                    AddStatus(info::sSpeedHack);

                    AddCheckBox("Speed Hack", &options->bSpeedHack);

                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("XP"))
                {
                    AddStatus(info::sDoubleXP);

                    AddCheckBox("Double XP", &options->bDoubleXP);

                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar();
            }
        }
        ImGui::End();
	}

}

MyMenu* Menu = new MyMenu();

ImVec4* colors = ImGui::GetStyle().Colors;

