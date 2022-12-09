#pragma once
#include "UnityEngine/Color.hpp"
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,

    CONFIG_VALUE(Rainbow, bool, "Rainbow Bar when full energy", true);
    CONFIG_VALUE(AlwaysRainbow, bool, "Always Rainbow Bar", false);
    CONFIG_VALUE(Fadeout, bool, "Fadeout", false);
    CONFIG_VALUE(FullFade, bool, "Use fade between 15% and 95% colors", false);
    CONFIG_VALUE(Alpha, float, "Alpha", 1.0);
    CONFIG_VALUE(Diehp, UnityEngine::Color, "under 15% energy", ConfigUtils::Color(1.0f, 0.0f, 0.0f, 0.0f));
    CONFIG_VALUE(Lowhp, UnityEngine::Color, "under 50% energy", ConfigUtils::Color(1.0f, 0.0f, 0.0f, 0.0f));
    CONFIG_VALUE(Midhp, UnityEngine::Color, "over 70% energy", ConfigUtils::Color(0.0f, 1.0f, 0.0f, 0.0f));
    CONFIG_VALUE(Highhp, UnityEngine::Color, "over 95% energy", ConfigUtils::Color(0.0f, 1.0f, 1.0f, 0.0f));
    CONFIG_VALUE(Defhp, UnityEngine::Color, "over 50% energy", ConfigUtils::Color(1.0f, 1.0f, 1.0f, 0.0f));
)