#include "main.hpp"
#include "ModConfig.hpp"
#include "GlobalNamespace/GameEnergyUIPanel.hpp"
#include "GlobalNamespace/GameEnergyCounter.hpp"
#include "GlobalNamespace/IDifficultyBeatmap.hpp"
#include "GlobalNamespace/OverrideEnvironmentSettings.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
#include "GlobalNamespace/PracticeSettings.hpp"
#include "GlobalNamespace/StandardLevelScenesTransitionSetupDataSO.hpp"
#include "GlobalNamespace/MultiplayerLevelScenesTransitionSetupDataSO.hpp"
#include "GlobalNamespace/IPreviewBeatmapLevel.hpp"
#include "GlobalNamespace/BeatmapDifficulty.hpp"
#include "GlobalNamespace/BeatmapCharacteristicSO.hpp"

#include "beatsaber-hook/shared/config/config-utils.hpp"

#include "UnityEngine/UI/Image.hpp"
#include "UnityEngine/SceneManagement/Scene.hpp"

#include "RedBarViewController.hpp"

#include "questui/shared/QuestUI.hpp"
#include "custom-types/shared/register.hpp"

using namespace GlobalNamespace;
using namespace UnityEngine;
using namespace QuestUI;

static ModInfo modInfo;
DEFINE_CONFIG(ModConfig);

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));
    return *logger;
}

    UnityEngine::Material* energyBarMaterialStore = nullptr;
    UnityEngine::UI::Image* energyBarStore = nullptr;
    float energyy = 0.0;
    int pos = 0;


MAKE_HOOK_OFFSETLESS(GameEnergyUIPanel_HandleGameEnergyDidChange, void, GameEnergyUIPanel* self, float energy) {
    
    //getLogger().info("Energy change RedBar");
    GameEnergyUIPanel_HandleGameEnergyDidChange(self, energy);
    UnityEngine::Color color;

    color = getModConfig().Defhp.GetValue();
    color.a = getModConfig().Alpha.GetValue();
    
    UnityEngine::UI::Image* energyBar = self->energyBar;

    
    UnityEngine::Material* energyBarMaterial = energyBar->get_material();

    if (energyBarMaterialStore != energyBarMaterial || energyBarStore != energyBar) {
        energyBarMaterialStore = energyBarMaterial;
        energyBarStore = energyBar;
    }
    if (energy != energyy) {
        energyy = energy;
    }

    if(getModConfig().FullFade.GetValue()) {
        double fraction = energy;
        color.r = getModConfig().Diehp.GetValue().r + (getModConfig().Highhp.GetValue().r - getModConfig().Diehp.GetValue().r) * fraction;
        color.g = getModConfig().Diehp.GetValue().g + (getModConfig().Highhp.GetValue().g - getModConfig().Diehp.GetValue().g) * fraction;
        color.b = getModConfig().Diehp.GetValue().b + (getModConfig().Highhp.GetValue().b - getModConfig().Diehp.GetValue().b) * fraction;
    } else {
        if (energy < 0.15) {
            if (!getModConfig().AlwaysRainbow.GetValue()) {
                color.r = getModConfig().Diehp.GetValue().r;
                color.g = getModConfig().Diehp.GetValue().g;
                color.b = getModConfig().Diehp.GetValue().b;
            }
        } else if (energy < 0.5) {
            if (!getModConfig().AlwaysRainbow.GetValue()) {
                double fraction = (energy - 0.15f)*2.8571428f;
                color.r = getModConfig().Diehp.GetValue().r + (getModConfig().Lowhp.GetValue().r - getModConfig().Diehp.GetValue().r) * fraction;
                color.g = getModConfig().Diehp.GetValue().g + (getModConfig().Lowhp.GetValue().g - getModConfig().Diehp.GetValue().g) * fraction;
                color.b = getModConfig().Diehp.GetValue().b + (getModConfig().Lowhp.GetValue().b - getModConfig().Diehp.GetValue().b) * fraction;
            }
        } else if (energy > 0.5 && energy < 0.7) {
            if (!getModConfig().AlwaysRainbow.GetValue()) {
                double fraction = (energy - 0.5f)*5.0f;
                color.r = getModConfig().Lowhp.GetValue().r + (getModConfig().Defhp.GetValue().r - getModConfig().Lowhp.GetValue().r) * fraction;
                color.g = getModConfig().Lowhp.GetValue().g + (getModConfig().Defhp.GetValue().g - getModConfig().Lowhp.GetValue().g) * fraction;
                color.b = getModConfig().Lowhp.GetValue().b + (getModConfig().Defhp.GetValue().b - getModConfig().Lowhp.GetValue().b) * fraction;
            }
        } else if (energy > 0.95) {
            if (!getModConfig().Rainbow.GetValue()) {
                double fraction = (energy - 0.95f)*20.0f;
                color.r = getModConfig().Midhp.GetValue().r + (getModConfig().Highhp.GetValue().r - getModConfig().Midhp.GetValue().r) * fraction;
                color.g = getModConfig().Midhp.GetValue().g + (getModConfig().Highhp.GetValue().g - getModConfig().Midhp.GetValue().g) * fraction;
                color.b = getModConfig().Midhp.GetValue().b + (getModConfig().Highhp.GetValue().b - getModConfig().Midhp.GetValue().b) * fraction;
            }
        } else if (energy > 0.7) {
            if (!getModConfig().AlwaysRainbow.GetValue()) {
                double fraction = (energy - 0.7f)*3.3333333f;
                color.r = getModConfig().Defhp.GetValue().r + (getModConfig().Midhp.GetValue().r - getModConfig().Defhp.GetValue().r) * fraction;
                color.g = getModConfig().Defhp.GetValue().g + (getModConfig().Midhp.GetValue().g - getModConfig().Defhp.GetValue().g) * fraction;
                color.b = getModConfig().Defhp.GetValue().b + (getModConfig().Midhp.GetValue().b - getModConfig().Defhp.GetValue().b) * fraction;
            }
        }
    }
    
    if (energy > 0.85 && getModConfig().Fadeout.GetValue()) {
        color.a = (6.667+(-6.667*energy))*getModConfig().Alpha.GetValue();
    } else {
        color.a = getModConfig().Alpha.GetValue();
    }
    //getLogger().info("r: " + std::to_string(color.r) + " g: " + std::to_string(color.g) + " b: " + std::to_string(color.g) + " a: " + std::to_string(color.a));
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
    //getLogger().info("LateUpdate RedBar");
    GameEnergyCounter_LateUpdate(self);
    if ((energyBarMaterialStore != nullptr && energyBarStore != nullptr && energyy == 1.0 && getModConfig().Rainbow.GetValue()) || (energyBarMaterialStore != nullptr && energyBarStore != nullptr && getModConfig().AlwaysRainbow.GetValue())) {
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

MAKE_HOOK_OFFSETLESS(SceneManager_ActiveSceneChanged, void, UnityEngine::SceneManagement::Scene previousActiveScene, UnityEngine::SceneManagement::Scene nextActiveScene) {
    SceneManager_ActiveSceneChanged(previousActiveScene, nextActiveScene);
    energyBarStore = nullptr;
    energyBarMaterialStore = nullptr;
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getLogger().info("Completed setup!");
}

extern "C" void load() {
    getLogger().info("Installing hooks...");
    il2cpp_functions::Init();
    getModConfig().Init(modInfo);
    QuestUI::Init();

    LoggerContextObject logger = getLogger().WithContext("load");
    custom_types::Register::RegisterType<RedBar::RedBarViewController>();
    // Register our mod settings menu
    QuestUI::Register::RegisterModSettingsViewController<RedBar::RedBarViewController*>(modInfo);
    // Install our hooks
    INSTALL_HOOK_OFFSETLESS(logger, GameEnergyUIPanel_HandleGameEnergyDidChange, il2cpp_utils::FindMethodUnsafe("", "GameEnergyUIPanel", "HandleGameEnergyDidChange", 1));
    INSTALL_HOOK_OFFSETLESS(logger, GameEnergyCounter_LateUpdate, il2cpp_utils::FindMethodUnsafe("", "GameEnergyCounter", "LateUpdate", 0));
    INSTALL_HOOK_OFFSETLESS(logger, SceneManager_ActiveSceneChanged, il2cpp_utils::FindMethodUnsafe("UnityEngine.SceneManagement", "SceneManager", "Internal_ActiveSceneChanged", 2));
    getLogger().info("Installed all hooks!");
}