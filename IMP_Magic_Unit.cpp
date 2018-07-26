#include "API_Unit.hpp"
#include "IMP_Unit.hpp"
#include "API_Magic_Unit.hpp"
#include "IMP_Magic_Unit.hpp"


namespace Game_Model
{
	namespace Implementation
	{
		double Magic_Unit::getCurentMPU () const 
		{
			return m_curentMPU;
		}

		double Magic_Unit::getMaxMPU () const 
		{
			return m_maxMPU;
		}
	}
}
