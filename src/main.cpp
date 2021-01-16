#include "main.hpp"
#include "GlobalNamespace/GameEnergyUIPanel.hpp"
#include "GlobalNamespace/GameEnergyCounter.hpp"

#include "beatsaber-hook/shared/config/config-utils.hpp"

#include "UnityEngine/UI/Image.hpp"

#include "RedBarViewController.hpp"

#include "questui/shared/QuestUI.hpp"
#include "custom-types/shared/register.hpp"

using namespace GlobalNamespace;
using namespace UnityEngine;
using namespace QuestUI;

static ModInfo modInfo;
Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));
    return *logger;
}

    UnityEngine::Material* energyBarMaterialStore = nullptr;
    UnityEngine::UI::Image* energyBarStore = nullptr;
    float energyy = 0.0;
    int pos = 0;


MAKE_HOOK_OFFSETLESS(GameEnergyUIPanel_HandleGameEnergyDidChange, void, GameEnergyUIPanel* self, float energy) {
    UnityEngine::Color color;

    color.a = getConfig().config["Alpha"].GetFloat();
    color.r = getConfig().config["DefhpR"].GetFloat();
    color.g = getConfig().config["DefhpG"].GetFloat();
    color.b = getConfig().config["DefhpB"].GetFloat();  
    
    UnityEngine::UI::Image* energyBar = self->energyBar;

    
    UnityEngine::Material* energyBarMaterial = energyBar->get_material();

    if (energyBarMaterialStore != energyBarMaterial || energyBarStore != energyBar) {
        energyBarMaterialStore = energyBarMaterial;
        energyBarStore = energyBar;
    }
    if (energy != energyy) {
        energyy = energy;
    }

    GameEnergyUIPanel_HandleGameEnergyDidChange(self, energy);

    if(getConfig().config["FullFade"].GetBool()) {
        double fraction = energy;
        color.r = getConfig().config["DiehpR"].GetFloat() + (getConfig().config["HighhpR"].GetFloat() - getConfig().config["DiehpR"].GetFloat()) * fraction;
        color.g = getConfig().config["DiehpG"].GetFloat() + (getConfig().config["HighhpG"].GetFloat() - getConfig().config["DiehpG"].GetFloat()) * fraction;
        color.b = getConfig().config["DiehpB"].GetFloat() + (getConfig().config["HighhpB"].GetFloat() - getConfig().config["DiehpB"].GetFloat()) * fraction;
    } else {
        if (energy < 0.15) {
            if (!getConfig().config["AlwaysRainbow"].GetBool()) {
                color.r = getConfig().config["DiehpR"].GetFloat();
                color.g = getConfig().config["DiehpG"].GetFloat();
                color.b = getConfig().config["DiehpB"].GetFloat();
            }
        } else if (energy < 0.5) {
            if (!getConfig().config["AlwaysRainbow"].GetBool()) {
                double fraction = (energy - 0.15f)*2.8571428f;
                color.r = getConfig().config["DiehpR"].GetFloat() + (getConfig().config["LowhpR"].GetFloat() - getConfig().config["DiehpR"].GetFloat()) * fraction;
                color.g = getConfig().config["DiehpG"].GetFloat() + (getConfig().config["LowhpG"].GetFloat() - getConfig().config["DiehpG"].GetFloat()) * fraction;
                color.b = getConfig().config["DiehpB"].GetFloat() + (getConfig().config["LowhpB"].GetFloat() - getConfig().config["DiehpB"].GetFloat()) * fraction;
            }
        } else if (energy > 0.5 && energy < 0.7) {
            if (!getConfig().config["AlwaysRainbow"].GetBool()) {
                double fraction = (energy - 0.5f)*5.0f;
                color.r = getConfig().config["LowhpR"].GetFloat() + (getConfig().config["DefhpR"].GetFloat() - getConfig().config["LowhpR"].GetFloat()) * fraction;
                color.g = getConfig().config["LowhpG"].GetFloat() + (getConfig().config["DefhpG"].GetFloat() - getConfig().config["LowhpG"].GetFloat()) * fraction;
                color.b = getConfig().config["LowhpB"].GetFloat() + (getConfig().config["DefhpB"].GetFloat() - getConfig().config["LowhpB"].GetFloat()) * fraction;
            }
        } else if (energy > 0.95) {
            if (!getConfig().config["Rainbow"].GetBool()) {
                double fraction = (energy - 0.95f)*20.0f;
                color.r = getConfig().config["MidhpR"].GetFloat() + (getConfig().config["HighhpR"].GetFloat() - getConfig().config["MidhpR"].GetFloat()) * fraction;
                color.g = getConfig().config["MidhpG"].GetFloat() + (getConfig().config["HighhpG"].GetFloat() - getConfig().config["MidhpG"].GetFloat()) * fraction;
                color.b = getConfig().config["MidhpB"].GetFloat() + (getConfig().config["HighhpB"].GetFloat() - getConfig().config["MidhpB"].GetFloat()) * fraction;
            }
        } else if (energy > 0.7) {
            if (!getConfig().config["AlwaysRainbow"].GetBool()) {
                double fraction = (energy - 0.7f)*3.3333333f;
                color.r = getConfig().config["DefhpR"].GetFloat() + (getConfig().config["MidhpR"].GetFloat() - getConfig().config["DefhpR"].GetFloat()) * fraction;
                color.g = getConfig().config["DefhpG"].GetFloat() + (getConfig().config["MidhpG"].GetFloat() - getConfig().config["DefhpG"].GetFloat()) * fraction;
                color.b = getConfig().config["DefhpB"].GetFloat() + (getConfig().config["MidhpB"].GetFloat() - getConfig().config["DefhpB"].GetFloat()) * fraction;
            }
        }
    }
    
    if (energy > 0.85 && getConfig().config["Fadeout"].GetBool()) {
        color.a = (6.667+(-6.667*energy))*getConfig().config["Alpha"].GetFloat();
    } else {
        color.a = getConfig().config["Alpha"].GetFloat();
    }
    
    energyBar->set_color(color);
}

float * Wheel(int WheelPos) {
  static int c[3];
  static float epic[3];
 
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  epic[0] = (float) c[0] / 255.0;
  epic[1] = (float) c[1] / 255.0;
  epic[2] = (float) c[2] / 255.0;
 
  return epic;
}


MAKE_HOOK_OFFSETLESS(GameEnergyCounter_LateUpdate, void, GameEnergyCounter* self) {
    GameEnergyCounter_LateUpdate(self);
    if ((energyBarMaterialStore != nullptr && energyy == 1.0 && getConfig().config["Rainbow"].GetBool()) || (energyBarMaterialStore != nullptr && getConfig().config["AlwaysRainbow"].GetBool())) {
        float* Heck = Wheel(pos);
        UnityEngine::Color color;
        color.a = 1.0;
        color.r = Heck[0];
        color.g = Heck[1];
        color.b = Heck[2];
        energyBarStore->set_color(color);
        pos++;
        if (pos > 255) {
            pos = 0;
        }
    }

}

    

void createDefaultConfig()  {
    
    if(getConfig().config.HasMember("Rainbow") && !getConfig().config.HasMember("FullFade")) {
        rapidjson::Document::AllocatorType& allocator = getConfig().config.GetAllocator();
        getConfig().config.AddMember("FullFade", rapidjson::Value().SetBool(false), allocator);
    }
    if(getConfig().config.HasMember("Rainbow")) {return;}

    // Add all the default options
    getConfig().config.RemoveAllMembers(); // Empty the config - it should already be empty but just to be sure
    getConfig().config.SetObject(); // Set the base of the config to a value that can contain keys

    // Get what is used to allocate memory in the config file
    rapidjson::Document::AllocatorType& allocator = getConfig().config.GetAllocator();

    // Add a member to the config, using the allocator

    getConfig().config.AddMember("Rainbow", rapidjson::Value().SetBool(true), allocator);
    getConfig().config.AddMember("AlwaysRainbow", rapidjson::Value().SetBool(false), allocator);
    getConfig().config.AddMember("Fadeout", rapidjson::Value().SetBool(false), allocator);
    getConfig().config.AddMember("FullFade", rapidjson::Value().SetBool(false), allocator);
    getConfig().config.AddMember("Alpha", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("DiehpR", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("DiehpG", rapidjson::Value().SetFloat(0.0), allocator);
    getConfig().config.AddMember("DiehpB", rapidjson::Value().SetFloat(0.0), allocator);
    getConfig().config.AddMember("LowhpR", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("LowhpG", rapidjson::Value().SetFloat(0.0), allocator);
    getConfig().config.AddMember("LowhpB", rapidjson::Value().SetFloat(0.0), allocator);
    getConfig().config.AddMember("MidhpR", rapidjson::Value().SetFloat(0.0), allocator);
    getConfig().config.AddMember("MidhpG", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("MidhpB", rapidjson::Value().SetFloat(0.0), allocator);
    getConfig().config.AddMember("HighhpR", rapidjson::Value().SetFloat(0.0), allocator);
    getConfig().config.AddMember("HighhpG", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("HighhpB", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("DefhpR", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("DefhpG", rapidjson::Value().SetFloat(1.0), allocator);
    getConfig().config.AddMember("DefhpB", rapidjson::Value().SetFloat(1.0), allocator);

    getConfig().Write(); // Write the config back to disk
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load(); // Load the config file
    createDefaultConfig();
    getLogger().info("Completed setup!");
}

extern "C" void load() {
    getLogger().info("Installing hooks...");
    il2cpp_functions::Init();
    QuestUI::Init();

    LoggerContextObject logger = getLogger().WithContext("load");
    custom_types::Register::RegisterType<RedBar::RedBarViewController>();
    // Register our mod settings menu
    QuestUI::Register::RegisterModSettingsViewController<RedBar::RedBarViewController*>(modInfo);
    // Install our hooks
    INSTALL_HOOK_OFFSETLESS(logger, GameEnergyUIPanel_HandleGameEnergyDidChange, il2cpp_utils::FindMethodUnsafe("", "GameEnergyUIPanel", "HandleGameEnergyDidChange", 1));
    INSTALL_HOOK_OFFSETLESS(logger, GameEnergyCounter_LateUpdate, il2cpp_utils::FindMethodUnsafe("", "GameEnergyCounter", "LateUpdate", 0));
    getLogger().info("Installed all hooks!");
}