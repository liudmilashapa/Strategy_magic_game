#ifndef _IMP_MAGIC_UNIT_HPP_
#define _IMP_MAGIC_UNIT_HPP_

#include < list >
#include < memory >

#include "API_Magic_Unit.hpp"
#include "IMP_Unit.hpp"
#include "spell.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {
	
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	typedef
	std::list<  Spell * >
	spellContainer;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class MagicUnit : public GameModel::MagicUnit, GameModel::Implementation::Unit
	{
		
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	public:

		MagicUnit(
			  const double & _maxHP
			, const double & _attackRate
			, const double & _defenseRate
			, const double & _maxMPU
			, const spellContainer & _spells)
			:	 GameModel::Implementation::Unit (
					  _maxHP
					, _attackRate
					, _defenseRate)
				, m_maxMPU ( _maxMPU )
				, m_spells ( _spells )
		{}

		MagicUnit(const MagicUnit & _other) = delete;
		MagicUnit & operator = (const MagicUnit & _other) = delete;

		virtual double getCurentMPU () const override;
		void setCurentMPU ( double _curentMPU );
		
		virtual double getMaxMPU () const override;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	private:
	
		double m_curentMPU;
		double m_maxMPU;
		spellContainer m_spells;

	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif // !_IMP_MAGIC_UNIT_HPP_
