#pragma once

#include <imgui.h>

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

    virtual const char* windowTitle() const = 0;
    virtual const char* mainTitle()  const = 0;
    virtual const char* subtitle()   const = 0;

    virtual const char* primaryButtonLabel()   const = 0;
    virtual void        onPrimaryButton()            = 0;

    virtual const char* secondaryButtonLabel() const = 0;
    virtual void        onSecondaryButton()          = 0;

    virtual const char* hint() const = 0;
};
