// Multiline Caption extension for Gig Performer by @rank13

#include "LibMain.h"

#include <regex>

// This is a dummy function to suppress compiler warnings about unused parameters
template <typename T> void Ignore(T const &) noexcept
{
}

const std::string XMLProductDescription =
    "<Library>"
    "<Product Name=\"" + PROJECT_TITLE + "\" Version=\"" + PROJECT_VERSION + "\" BuildDate=\"" + PROJECT_BUILD_DATE + "\"></Product>"
    "<Description>" + PROJECT_DESCRIPTION + "</Description>"
    "<ImagePath></ImagePath>"
    "</Library>";

// List of menu items
std::vector<std::string> menuNames = {
    "Convert Captions to Multiline"
};

int LibMain::GetMenuCount()
{
    return static_cast<int>(menuNames.size());
}

std::string LibMain::GetMenuName(int index)
{
    std::string text;
    if (index >= 0 && static_cast<std::size_t>(index) < menuNames.size())
    {
        text = menuNames[index];
    }
    return text;
}

void LibMain::InvokeMenu(int index)
{
    if (index >= 0 && static_cast<std::size_t>(index) < menuNames.size())
    {
        switch (index)
        {
        case 0:
            convertCaptionToMultiline();
            break;
        default:
            break;
        }
    }
}

void LibMain::convertCaptionToMultiline()
{
    // Local widgets
    std::vector<std::string> localWidgets;
    getWidgetList(localWidgets, false);
    updateWidgetCaptions(localWidgets);

    // Global widgets
    std::vector<std::string> globalWidgets;
    getWidgetList(globalWidgets, true);
    updateWidgetCaptions(globalWidgets);
}

// Identify widget handles starting with MULTILINE and convert caption semicolons to line breaks
void LibMain::updateWidgetCaptions(std::vector<std::string> widgets)
{
    for (int i = 0; i < widgets.size(); i++) {
        std::string widgetHandle = extractWidgetHandle(widgets[i]);
        if (std::regex_match (widgetHandle, std::regex("^MULTILINE(.*)") )) {
            std::string caption = getWidgetCaption(widgetHandle);
            std::string newCaption = std::regex_replace(caption, std::regex(";"), "\n"); 
            setWidgetCaption(widgetHandle, newCaption);
        }
    }
}

// Extract the widget name from the end of the combined "Type:Handle" format
std::string LibMain::extractWidgetHandle(std::string widgetHandle)
{
   if (widgetHandle.find(":"))
      widgetHandle = widgetHandle.substr(widgetHandle.find(":") + 1);

   return widgetHandle;
}

std::string LibMain::GetProductDescription()
{
    return XMLProductDescription;
}


namespace gigperformer
{
namespace sdk
{

GigPerformerAPI *CreateGPExtension(LibraryHandle handle)
{
    return new LibMain(handle);
}

} // namespace sdk
} // namespace gigperformer
