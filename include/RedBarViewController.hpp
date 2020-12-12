#include "main.hpp"

#include "custom-types/shared/macros.hpp"

#include "questui/shared/CustomTypes/Components/Settings/IncrementSetting.hpp"

#include "UnityEngine/UI/Button.hpp"
#include "HMUI/ViewController.hpp"

// ViewController for the settings UI
DECLARE_CLASS_CODEGEN(RedBar, RedBarViewController, HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, modeSelectButton);
    DECLARE_INSTANCE_FIELD(QuestUI::IncrementSetting*, thresholdSetting);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, DidDeactivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidDeactivate", 2), bool removedFromHierarchy, bool systemScreenDisabling);

    REGISTER_FUNCTION(RedBarViewController,
        //REGISTER_FIELD(modeSelectButton);
        //REGISTER_FIELD(thresholdSetting);

        REGISTER_METHOD(DidActivate);
        REGISTER_METHOD(DidDeactivate);
    )
)