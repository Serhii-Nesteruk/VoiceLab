#pragma once

class IView
{
public:
    virtual ~IView() = default;
    virtual void render() = 0;
};
