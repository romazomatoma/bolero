#include "section_manager.h"
#include "section_list.h"

#include <vector>
#include <memory>

#include <imgui.h>

namespace bolero
{

    namespace section
    {
        class SectionManagerImpl : public ISectionManager
        {
        public:
            SectionManagerImpl()
            {
                m_sections.push_back(std::shared_ptr<ISection>(CreateExampleSection()));
            }

            void OnDraw() final
            {
                auto s = GetCurrentSection();
                s->OnDraw();
            }

            void OnGUI() final
            {
                auto s = GetCurrentSection();
                if (ImGui::Begin(s->GetName()))
                {
                    s->OnGUI();
                }
                ImGui::End();
            }

            ISection *GetCurrentSection()
            {
                return m_sections.at(0).get();
            }
            std::vector<std::shared_ptr<ISection>> m_sections;
        };

        ISectionManager *ISectionManager::GetInstance()
        {
            static SectionManagerImpl instance;
            return &instance;
        }
    } // section

} // bolero