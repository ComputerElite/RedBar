#pragma once
#include "UnityEngine/Color.hpp"
#include "extern/config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,

    DECLARE_VALUE(Rainbow, bool, "Rainbow Bar when full energy", true);
    DECLARE_VALUE(AlwaysRainbow, bool, "Always Rainbow Bar", false);
    DECLARE_VALUE(Fadeout, bool, "Fadeout", false);
    DECLARE_VALUE(FullFade, bool, "Use fade between 15% and 95% colors", false);
    DECLARE_VALUE(Alpha, float, "Alpha", 1.0);
    DECLARE_VALUE(Diehp, UnityEngine::Color, "under 15% energy", UnityEngine::Color(1.0f, 0.0f, 0.0f, 0.0f));
    DECLARE_VALUE(Lowhp, UnityEngine::Color, "under 50% energy", UnityEngine::Color(1.0f, 0.0f, 0.0f, 0.0f));
    DECLARE_VALUE(Midhp, UnityEngine::Color, "over 70% energy", UnityEngine::Color(0.0f, 1.0f, 0.0f, 0.0f));
    DECLARE_VALUE(Highhp, UnityEngine::Color, "over 95% energy", UnityEngine::Color(0.0f, 1.0f, 1.0f, 0.0f));
    DECLARE_VALUE(Defhp, UnityEngine::Color, "over 50% energy", UnityEngine::Color(1.0f, 1.0f, 1.0f, 0.0f));

    INIT_FUNCTION(
        INIT_VALUE(Rainbow);
        INIT_VALUE(AlwaysRainbow);
        INIT_VALUE(Fadeout);
        INIT_VALUE(FullFade);
        INIT_VALUE(Alpha);
        INIT_VALUE(Diehp);
        INIT_VALUE(Lowhp);
        INIT_VALUE(Midhp);
        INIT_VALUE(Highhp);
        INIT_VALUE(Defhp);
    )
)