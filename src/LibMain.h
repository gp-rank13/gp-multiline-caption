// Multiline Caption extension for Gig Performer by @rank13

#pragma once

#include "gigperformer/sdk/GigPerformerAPI.h"
#include "Version.h"

class LibMain : public gigperformer::sdk::GigPerformerAPI
{
  protected:
    // These are for creating menu items
    int GetMenuCount() override;
    std::string GetMenuName(int index) override;
    void InvokeMenu(int itemIndex) override;

  public:
    explicit LibMain(LibraryHandle handle) : GigPerformerAPI(handle)
    {
    }

    ~LibMain() override
    {
    }

    void convertCaptionToMultiline();
    void updateWidgetCaptions(std::vector<std::string> widgets);
    std::string extractWidgetHandle(std::string widgetHandle);
    std::string GetProductDescription() override;
};
