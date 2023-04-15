#pragma once
namespace bolero
{

	namespace section
	{
		class ISection
		{
		public:
		virtual ~ISection()=default;
			virtual const char *GetName() const = 0;
			virtual void OnDraw() = 0;
			virtual void OnGUI() = 0;
		};

		class ISectionManager
		{
		public:
		virtual ~ISectionManager()=default;
			virtual void OnDraw() = 0 ;
			virtual void OnGUI() = 0;
			static ISectionManager *GetInstance();
		};
	} // section

} // bolero