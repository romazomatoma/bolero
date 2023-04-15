#include "section_list.h"
#include <imgui.h>

namespace
{
    class ExampleSection : public bolero::section::ISection
    {
        const char *GetName() const final{
            return "ExampleSection";
        }
        void OnDraw() final {
            
        }
        void OnGUI() final {
        }
    };
} // anonymouse

namespace bolero
{
    namespace section
    {
        ISection *CreateExampleSection()
        {
            return new ExampleSection;
        }
    } // section
} // namespace bolero