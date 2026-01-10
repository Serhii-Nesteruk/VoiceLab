#pragma once

#include <imgui.h>
#include <string>

#include "IView.h"
#include "UiActionBus.h"
#include "styles/UiComponentsBuilder.h"

class VoiceScreenViewBase : public IView
{
public:
    explicit VoiceScreenViewBase(UiActionBus& actionBus)
        : _actionBus(actionBus)
    {}

    void render() override;

protected:
    UiActionBus& _actionBus;

    [[nodiscard]] virtual const char* windowTitle() const = 0;
    [[nodiscard]] virtual const char* mainTitle()  const = 0;
    [[nodiscard]] virtual std::string subtitle()   const = 0;

    [[nodiscard]] virtual const char* primaryButtonLabel()   const = 0;
    virtual void        onPrimaryButton()            = 0;

    [[nodiscard]] virtual const char* secondaryButtonLabel() const = 0;
    virtual void        onSecondaryButton()          = 0;

    [[nodiscard]] virtual const char* thirdButtonLabel() const = 0;
    virtual void        onThirdButton()          = 0;
};
