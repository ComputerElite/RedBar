#include "RedBarViewController.hpp"

#include "UnityEngine/RectOffset.hpp"
#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/UI/Image.hpp"
#include "UnityEngine/UI/Toggle.hpp"
#include "UnityEngine/UI/Toggle_ToggleEvent.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/Events/UnityAction.hpp"
#include "UnityEngine/Events/UnityAction_1.hpp"
#include "HMUI/ScrollView.hpp"
#include "HMUI/ModalView.hpp"
#include "HMUI/Touchable.hpp"
#include "main.hpp"
#include "UnityEngine/Resources.hpp"
#include "GlobalNamespace/ColorPickerButtonController.hpp"
#include "GlobalNamespace/HSVPanelController.hpp"
#include "GlobalNamespace/ColorChangeUIEventType.hpp"
#include "System/Action_2.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/CustomTypes/Components/ExternalComponents.hpp"
#include "questui/shared/CustomTypes/Components/Backgroundable.hpp"
#include <stdlib.h>

using namespace QuestUI;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace UnityEngine::Events;
using namespace HMUI;
using namespace RedBar;

DEFINE_CLASS(RedBarViewController);

void onCalcClick(RedBarViewController* self)  {
    // Swap the current mode
    UnityEngine::Color color1;
    UnityEngine::Color color2;
    color1.r = getConfig().config["DiehpR"].GetFloat();
    color1.g = getConfig().config["DiehpG"].GetFloat();
    color1.b = getConfig().config["DiehpB"].GetFloat();

    color2.r = getConfig().config["HighhpR"].GetFloat();
    color2.g = getConfig().config["HighhpG"].GetFloat();
    color2.b = getConfig().config["HighhpB"].GetFloat();

    //0.5
    getConfig().config["LowhpR"].SetFloat(color1.r + (color2.r - color1.r)*0.5f);
    getConfig().config["LowhpG"].SetFloat(color1.g + (color2.g - color1.g)*0.5f);
    getConfig().config["LowhpB"].SetFloat(color1.b + (color2.b - color1.b)*0.5f);

    //0.7
    getConfig().config["DefpR"].SetFloat(color1.r + (color2.r - color1.r)*0.7f);
    getConfig().config["DefhpG"].SetFloat(color1.g + (color2.g - color1.g)*0.7f);
    getConfig().config["DefhpB"].SetFloat(color1.b + (color2.b - color1.b)*0.7f);
}

void onRainbowChange(RedBarViewController* self, bool newValue) {
        getConfig().config["Rainbow"].SetBool(newValue);
}

void onFadeChange(RedBarViewController* self, bool newValue) {
        getConfig().config["FullFade"].SetBool(newValue);
}

void onAlwaysRainbowChange(RedBarViewController* self, bool newValue) {
        getConfig().config["AlwaysRainbow"].SetBool(newValue);
}

void onFadeoutChange(RedBarViewController* self, bool newValue) {
        getConfig().config["Fadeout"].SetBool(newValue);
}

void onAlphaChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["Alpha"].SetFloat(newValue);
}

void onDieRChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["DiehpR"].SetFloat(newValue);
}
void onDieGChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["DiehpG"].SetFloat(newValue);
}
void onDieBChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["DiehpB"].SetFloat(newValue);
}

void onLowRChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["LowhpR"].SetFloat(newValue);
}
void onLowGChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["LowhpG"].SetFloat(newValue);
}
void onLowBChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["LowhpB"].SetFloat(newValue);
}

void onMidRChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["MidhpR"].SetFloat(newValue);
}
void onMidGChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["MidhpG"].SetFloat(newValue);
}
void onMidBChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["MidhpB"].SetFloat(newValue);
}

void onHeighRChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["HighhpR"].SetFloat(newValue);
}
void onHeighGChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["HighhpG"].SetFloat(newValue);
}
void onHeighBChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["HighhpB"].SetFloat(newValue);
}

void onDefRChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["DefhpR"].SetFloat(newValue);
}
void onDefGChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["DefhpG"].SetFloat(newValue);
}
void onDefBChange(RedBarViewController* self, float newValue)   {
    if(newValue < 0.0f) {
        newValue = 0.0f;
    }
    if(newValue > 1.0f) {
        newValue = 1.0f;
    }
    getConfig().config["DefhpB"].SetFloat(newValue);
}

void onDieChange(RedBarViewController* self, UnityEngine::Color* newValue, GlobalNamespace::ColorChangeUIEventType unused) {
    getConfig().config["DiehpR"].SetFloat(newValue->r);
    getConfig().config["DiehpG"].SetFloat(newValue->g);
    getConfig().config["DiehpB"].SetFloat(newValue->b);
}

typedef System::Action_2<UnityEngine::Color, GlobalNamespace::ColorChangeUIEventType>* ColorChangeDelegate;
UnityEngine::GameObject* CreateColorPickerButton(UnityEngine::Transform* parent, std::string text, UnityEngine::Color defaultColor, ColorChangeDelegate onChange) {
    // use QuestUI toggle as starting point to make positioning and sizing easier
    auto fakeToggle = QuestUI::BeatSaberUI::CreateToggle(parent, text, nullptr);
    auto gameObject = fakeToggle->get_transform()->get_parent()->get_gameObject();
    UnityEngine::Object::Destroy(fakeToggle->get_gameObject());

    // create element that gets toggled to contain the actual picker
    auto pickerModalGO = UnityEngine::GameObject::New_ctor(il2cpp_utils::createcsstr("QountersMinusColorPickerModal"));
    auto pickerModalGORect = pickerModalGO->AddComponent<UnityEngine::RectTransform*>();
    pickerModalGORect->set_anchorMin(UnityEngine::Vector2(1.0f, 1.0f));
    pickerModalGORect->set_anchorMax(UnityEngine::Vector2(1.0f, 1.0f));
    pickerModalGORect->set_sizeDelta(UnityEngine::Vector2(40.0f, 40.0f));
    pickerModalGO->get_transform()->SetParent(parent, false);
    pickerModalGO->SetActive(false);

    // extra close button other than re-clicking the color button
    // auto closeButton = QuestUI::BeatSaberUI::CreateUIButton(gameObject->get_transform(), "Close", "PracticeButton", UnityEngine::Vector2(15.0f, -0.5f), il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction*>(
    //     classof(UnityEngine::Events::UnityAction*), pickerModalGO, +[](UnityEngine::GameObject* pickerModalGO) {
    //         pickerModalGO->SetActive(false);
    //     }
    // ));
    // closeButton->get_gameObject()->SetActive(false);

    // initialize the color button that toggles the picker open
    static auto colorPickerButtonControllers = UnityEngine::Resources::FindObjectsOfTypeAll<GlobalNamespace::ColorPickerButtonController*>();
    static auto buttonBase = colorPickerButtonControllers->values[0]->get_gameObject();
    auto buttonGO = UnityEngine::Object::Instantiate(buttonBase, gameObject->get_transform(), false);
    auto buttonRect = buttonGO->GetComponent<UnityEngine::RectTransform*>();
    buttonRect->set_anchorMin(UnityEngine::Vector2(1.0f, 0.5f));
    buttonRect->set_anchorMax(UnityEngine::Vector2(1.0f, 0.5f));
    buttonRect->set_anchoredPosition(UnityEngine::Vector2(-1.0f, -0.5f));
    buttonRect->set_pivot(UnityEngine::Vector2(1.0f, 0.5f));
    auto colorPickerButtonController = buttonGO->GetComponent<GlobalNamespace::ColorPickerButtonController*>();
    colorPickerButtonController->SetColor(defaultColor);

    // initialize the picker itself
    static auto hsvColorPickers = UnityEngine::Resources::FindObjectsOfTypeAll<GlobalNamespace::HSVPanelController*>();
    static auto pickerBase = hsvColorPickers->values[0]->get_gameObject();
    auto pickerGO = UnityEngine::Object::Instantiate(pickerBase, pickerModalGO->get_transform(), false);
    auto hsvPanelController = pickerGO->GetComponent<GlobalNamespace::HSVPanelController*>();
    UnityEngine::Object::Destroy(pickerGO->get_transform()->Find(il2cpp_utils::createcsstr("ColorPickerButtonPrimary"))->get_gameObject());
    auto pickerRect = pickerGO->GetComponent<UnityEngine::RectTransform*>();
    pickerRect->set_pivot(UnityEngine::Vector2(0.25f, 0.77f));
    pickerRect->set_localScale(UnityEngine::Vector3(0.75f, 0.75f, 0.75f));

    // event bindings
    hsvPanelController->add_colorDidChangeEvent(il2cpp_utils::MakeDelegate<ColorChangeDelegate>(
        classof(ColorChangeDelegate), colorPickerButtonController, +[](GlobalNamespace::ColorPickerButtonController* buttonController, UnityEngine::Color color, GlobalNamespace::ColorChangeUIEventType eventType) {
            buttonController->SetColor(color);
        })
    );
    hsvPanelController->add_colorDidChangeEvent(onChange);
    colorPickerButtonController->button->get_onClick()->AddListener(il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction*>(
        classof(UnityEngine::Events::UnityAction*), pickerModalGO, +[](UnityEngine::GameObject* pickerModalGO) {
            pickerModalGO->SetActive(!pickerModalGO->get_activeSelf());
        }
    ));

    return buttonGO;
}

void RedBarViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling){
    if(firstActivation) {
        get_gameObject()->AddComponent<Touchable*>();
        GameObject* container = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        // Rainbow
        auto RainbowChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
                   classof(UnityEngine::Events::UnityAction_1<bool>*), this, onRainbowChange);
        UnityEngine::UI::Toggle* Rain = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Rainbow Bar when full energy", getConfig().config["Rainbow"].GetBool(), RainbowChange);
        QuestUI::BeatSaberUI::AddHoverHint(Rain->get_gameObject(), "overrides Fadeout");

        // AlwaysRainbow
        auto AlwaysRainbowChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
                   classof(UnityEngine::Events::UnityAction_1<bool>*), this, onAlwaysRainbowChange);
        UnityEngine::UI::Toggle* Alw = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Always Rainbow Bar", getConfig().config["AlwaysRainbow"].GetBool(), AlwaysRainbowChange);
        QuestUI::BeatSaberUI::AddHoverHint(Alw->get_gameObject(), "overrides Fadeout, Fade red to green and Rainbow");

        // Fadeout
        auto FadeoutChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
                   classof(UnityEngine::Events::UnityAction_1<bool>*), this, onFadeoutChange);
        QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Fadeout", getConfig().config["Fadeout"].GetBool(), FadeoutChange);
        
        // Alpha
        auto AlphaChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onAlphaChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Alpha", 1, 0.1, getConfig().config["Alpha"].GetFloat(), 0.0f, 1.0f, AlphaChange);

        //QuestUI::BeatSaberUI::CreateText(container->get_transform(), "\n\n                                          Values under 0.0 will be 0.0");
        //QuestUI::BeatSaberUI::CreateText(container->get_transform(), "\n                                          Values over 1.0 will be 1.0");
        
        // FullFade
        auto FadeChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
                   classof(UnityEngine::Events::UnityAction_1<bool>*), this, onFadeChange);
        UnityEngine::UI::Toggle* FullFade = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Use fade between 15% and 95% colors", getConfig().config["FullFade"].GetBool(), FadeChange);
        QuestUI::BeatSaberUI::AddHoverHint(FullFade->get_gameObject(), "Fades between the 15% and 95% Color");


        auto DieChange = CreateColorPickerButton(container->get_transform(), "under 15% energy", UnityEngine::Color(getConfig().config["DiehpR"].GetFloat(), getConfig().config["DiehpG"].GetFloat(), getConfig().config["DiehpB"].GetFloat()), il2cpp_utils::MakeDelegate<ColorChangeDelegate>(
            classof(ColorChangeDelegate), container, +[](UnityEngine::GameObject* container, UnityEngine::Color newValue, GlobalNamespace::ColorChangeUIEventType eventType) {
                getConfig().config["DiehpR"].SetFloat(newValue.r);
                getConfig().config["DiehpG"].SetFloat(newValue.g);
                getConfig().config["DiehpB"].SetFloat(newValue.b);
            })
        );

        /*
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "\nunder 15% energy");
        // DieR
        auto DieRChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onDieRChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Red", 1, 0.1, getConfig().config["DiehpR"].GetFloat(), 0.0f, 1.0f, DieRChange);
        // DieG
        auto DieGChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onDieGChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Green", 1, 0.1, getConfig().config["DiehpG"].GetFloat(), 0.0f, 1.0f, DieGChange);
        // DieB
        auto DieBChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onDieBChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Blue", 1, 0.1, getConfig().config["DiehpB"].GetFloat(), 0.0f, 1.0f, DieBChange);
        
*/

        auto LowChange = CreateColorPickerButton(container->get_transform(), "under 50% energy", UnityEngine::Color(getConfig().config["LowhpR"].GetFloat(), getConfig().config["LowhpG"].GetFloat(), getConfig().config["LowhpB"].GetFloat()), il2cpp_utils::MakeDelegate<ColorChangeDelegate>(
            classof(ColorChangeDelegate), container, +[](UnityEngine::GameObject* container, UnityEngine::Color newValue, GlobalNamespace::ColorChangeUIEventType eventType) {
                getConfig().config["LowhpR"].SetFloat(newValue.r);
                getConfig().config["LowhpG"].SetFloat(newValue.g);
                getConfig().config["LowhpB"].SetFloat(newValue.b);
            })
        );

/*
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "\nunder 50% energy");
        // LowR
        auto LowRChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onLowRChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Red", 1, 0.1, getConfig().config["LowhpR"].GetFloat(), 0.0f, 1.0f, LowRChange);
        // LowG
        auto LowGChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onLowGChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Green", 1, 0.1, getConfig().config["LowhpG"].GetFloat(), 0.0f, 1.0f, LowGChange);
        // LowB
        auto LowBChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onLowBChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Blue", 1, 0.1, getConfig().config["LowhpB"].GetFloat(), 0.0f, 1.0f, LowBChange);
*/

        auto DefChange = CreateColorPickerButton(container->get_transform(), "over 50% energy", UnityEngine::Color(getConfig().config["DefhpR"].GetFloat(), getConfig().config["DefhpG"].GetFloat(), getConfig().config["DefhpB"].GetFloat()), il2cpp_utils::MakeDelegate<ColorChangeDelegate>(
            classof(ColorChangeDelegate), container, +[](UnityEngine::GameObject* container, UnityEngine::Color newValue, GlobalNamespace::ColorChangeUIEventType eventType) {
                getConfig().config["DefhpR"].SetFloat(newValue.r);
                getConfig().config["DefhpG"].SetFloat(newValue.g);
                getConfig().config["DefhpB"].SetFloat(newValue.b);
            })
        );

        /*
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "\nover 50% energy");
        // DefR
        auto DefRChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onDefRChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Red", 1, 0.1, getConfig().config["DefhpR"].GetFloat(), 0.0f, 1.0f, DefRChange);
        // DefG
        auto DefGChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onDefGChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Green", 1, 0.1, getConfig().config["DefhpG"].GetFloat(), 0.0f, 1.0f, DefGChange);
        // DefB
        auto DefBChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onDefBChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Blue", 1, 0.1, getConfig().config["DefhpB"].GetFloat(), 0.0f, 1.0f, DefBChange);
        */

       auto MidChange = CreateColorPickerButton(container->get_transform(), "over 70% energy", UnityEngine::Color(getConfig().config["MidhpR"].GetFloat(), getConfig().config["MidhpG"].GetFloat(), getConfig().config["MidhpB"].GetFloat()), il2cpp_utils::MakeDelegate<ColorChangeDelegate>(
            classof(ColorChangeDelegate), container, +[](UnityEngine::GameObject* container, UnityEngine::Color newValue, GlobalNamespace::ColorChangeUIEventType eventType) {
                getConfig().config["MidhpR"].SetFloat(newValue.r);
                getConfig().config["MidhpG"].SetFloat(newValue.g);
                getConfig().config["MidhpB"].SetFloat(newValue.b);
            })
        );

        /*
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "\nover 70% energy");
        // MidR
        auto MidRChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onMidRChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Red", 1, 0.1, getConfig().config["MidhpR"].GetFloat(), 0.0f, 1.0f, MidRChange);
        // MidG
        auto MidGChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onMidGChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Green", 1, 0.1, getConfig().config["MidhpG"].GetFloat(), 0.0f, 1.0f, MidGChange);
        // MidB
        auto MidBChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onMidBChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Blue", 1, 0.1, getConfig().config["MidhpB"].GetFloat(), 0.0f, 1.0f, MidBChange);
        */

       auto HeighChange = CreateColorPickerButton(container->get_transform(), "over 95% energy", UnityEngine::Color(getConfig().config["HeighhpR"].GetFloat(), getConfig().config["HeighhpG"].GetFloat(), getConfig().config["HeighhpB"].GetFloat()), il2cpp_utils::MakeDelegate<ColorChangeDelegate>(
            classof(ColorChangeDelegate), container, +[](UnityEngine::GameObject* container, UnityEngine::Color newValue, GlobalNamespace::ColorChangeUIEventType eventType) {
                getConfig().config["HeighhpR"].SetFloat(newValue.r);
                getConfig().config["HeighhpG"].SetFloat(newValue.g);
                getConfig().config["HeighhpB"].SetFloat(newValue.b);
            })
        );

        /*
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "\n100% energy");
        // HeighR
        auto HeighRChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onHeighRChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Red", 1, 0.1, getConfig().config["HighhpR"].GetFloat(), 0.0f, 1.0f, HeighRChange);
        // HeighG
        auto HeighGChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onHeighGChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Green", 1, 0.1, getConfig().config["HighhpG"].GetFloat(), 0.0f, 1.0f, HeighGChange);
        // HeighB
        auto HeighBChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, onHeighBChange);
        QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "   Blue", 1, 0.1, getConfig().config["HighhpB"].GetFloat(), 0.0f, 1.0f, HeighBChange);
        */
    }
}

void RedBarViewController::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling) {
    getConfig().Write();
}