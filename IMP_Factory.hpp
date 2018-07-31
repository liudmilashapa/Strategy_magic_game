#ifndef _IMP_FACTORY_HPP_
#define _IMP_FACTORY_HPP_

#include < memory >

#include "IMP_Fight.hpp"
#include "IMP_Magic_Unit.hpp"
#include "Spell.hpp"

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Unit;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class AbilityUnit;
	class Fight;
	class MagicUnit;
	class Spell;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class GameFactory
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	public:

		GameFactory() {}

		GameFactory(const GameFactory & _other) = delete;
		GameFactory & operator = (const GameFactory & _other) = delete;

		std::unique_ptr < GameModel::Unit > createUnit (
			  const double & _maxHP
			, const double & _attackRate
			, const double & _defenseRate
		) const;

		std::unique_ptr < GameModel::MagicUnit > createMagicUnit (
			  const double & _maxHP
			, const double & _attackRate
			, const double & _defenseRate
			, const double & _maxMPU
			, const spellContainer & _spells
		) const;

		std::unique_ptr < GameModel::AbilityUnit > createAbilityUnit (
			  const double & _maxHP
			, const double & _attackRate
			, const double & _defenseRate
		) const;

		std::unique_ptr < GameModel::Fight > createFight (
			  fightContainer & _army1
			, fightContainer & _army2
		) const;

		std::unique_ptr < GameModel::Spell > createSpell (
			const double & _cost
		) const;
	

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	private:
	
	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif // !_IMP_FACTORY_HPP_



